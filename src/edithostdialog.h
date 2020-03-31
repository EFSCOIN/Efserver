#ifndef EDITHOSTDIALOG_H
#define EDITHOSTDIALOG_H

#include "efserver.h"
#include <string>
#include <gtkmm.h>

class EditHostDialog
{
public:
    EditHostDialog(EfServer *ps, const std::string &mac, Gtk::Window *parent = NULL);
    virtual ~EditHostDialog();
    bool exec();

protected:
    EfServer *_ps;
    std::string _mac;
    Gtk::Dialog *_dialog;
    Gtk::Label *_maclabel;
    Gtk::ComboBox *_oscombo;
    Gtk::Entry *_descriptionentry;
    Glib::RefPtr<Gtk::ListStore> _distrostore;

};

#endif // EDITHOSTDIALOG_H
