#ifndef ABSTRACTADDUSER_H
#define ABSTRACTADDUSER_H

#include <gtkmm.h>

class EfServer;

class AbstractAddUser
{
protected:
    AbstractAddUser(EfServer *ps);
    void setupAddUserFields(Glib::RefPtr<Gtk::Builder> builder);
    virtual ~AbstractAddUser();
    virtual void setAddUserOkButton() = 0;
    bool addUserFieldsOk();
    void on_showPassToggled();
    bool checkUserAvailability(bool useLDAP);
    void addUsers();

    Gtk::CheckButton *_forcePassChangeCheck, *_showPassCheck;
    std::vector<Gtk::Entry *> _userEntry;
    std::vector<Gtk::Entry *> _passEntry;

private:
    EfServer *_ps;
};

#endif // ABSTRACTADDUSER_H
