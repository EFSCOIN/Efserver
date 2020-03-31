#include <iostream>
#include <fstream>
#include <gtkmm.h>
#include "mainwindow.h"
#include "installwizard.h"
#include "efserver.h"

using namespace std;

int main(int argc, char *argv[])
{
    EfServer ps;

	setlocale (LC_ALL, "");
	bindtextdomain ("piserver", "/usr/share/locale");
	bind_textdomain_codeset ("efserver", "UTF-8");
	textdomain ("efserver");

    if (argc == 2 && strcmp(argv[1], "--update-ip") == 0 )
    {
        ps.updateIP();
        return 0;
    }

    auto app = Gtk::Application::create(argc, argv, "org.efscoin.efserver");

    if (::getuid() != 0)
    {
        Gtk::MessageDialog d(_("This program must be run as root. Try starting it with sudo."));
        d.run();
        return 1;
    }

    if (::access(EFSERVER_DATADIR, R_OK | W_OK | X_OK) == -1
            || ::access(EFSERVER_TFTPROOT, R_OK | W_OK | X_OK) == -1
            || ::access(EFSERVER_DISTROROOT, R_OK | W_OK | X_OK) == -1)
    {
        Gtk::MessageDialog d(_("Sanity check failed. Data directories do not exist or have "
                               "incorrect permissions. Please reinstall the 'efserver' package."));
        d.run();
        return 1;
    }

    if (!ps.getSetting("installed", false))
    {
        /* Warn if using overlayfs, as Debian currently uses Linux 4.9.x
         * that does not support exporting overlayfs through NFS
         * Do not make warning fatal, as this may change in the future
         */
        std::ifstream i("/proc/mounts", ios_base::in);
        std::stringstream buf;
        buf << i.rdbuf();

        if (buf.str().find("overlay / ") != string::npos)
        {
                Gtk::MessageDialog d(_("Warning: you seem to be running Debian with persistence enabled, "
                                       "which does not work properly with efserver. Please 'install' Debian to "
                                       "hard disk first."));
                d.run();
        }

        InstallWizard w(app, &ps);
        w.exec();
        /* For some reason gtk doesn't allow the main loop to be run a second time.
           create fresh Application object for use by MainWindow */
        app = Gtk::Application::create(argc, argv, "org.efscoin.efserver");
    }

    if (ps.getSetting("installed", false))
    {
        MainWindow win(app, &ps);
        win.exec();
    }

    return 0;
}

