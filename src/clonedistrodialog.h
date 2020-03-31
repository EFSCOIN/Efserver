#ifndef CLONEDISTRODIALOG_H
#define CLONEDISTRODIALOG_H

#include <gtkmm.h>
#include <string>

class EfServer;
class Distribution;

class CloneDistroDialog
{
public:
    CloneDistroDialog(EfServer *ps, Distribution *olddistro, Gtk::Window *parent);
    virtual ~CloneDistroDialog();
    bool exec();

protected:
    EfServer *_ps;
    Distribution *_olddistro;
    Gtk::Dialog *_dialog, *_progressDialog;
    Gtk::Button *_okButton;
    Gtk::Entry *_nameEntry;
    GPid _pid;

    bool isNameValid(const std::string &name);
    void setOkSensitive();
    void onCopyFinished(GPid pid, int status);
};

#endif // CLONEDISTRODIALOG_H
