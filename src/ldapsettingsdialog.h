#ifndef LDAPSETTINGSDIALOG_H
#define LDAPSETTINGSDIALOG_H

#include <gtkmm.h>
#include <string>

class EfServer;

class LdapSettingsDialog
{
public:
    LdapSettingsDialog(PiServer *ps, Gtk::Window *parent);
    virtual ~LdapSettingsDialog();
    bool exec();

protected:
    EfServer *_ps;
    Gtk::Dialog *_dialog;
    Gtk::TreeView *_dntree, *_grouptree;
    Glib::RefPtr<Gtk::ListStore> _dnstore, _groupstore;
};

#endif // LDAPSETTINGSDIALOG_H
