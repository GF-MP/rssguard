// This file is part of RSS Guard.
//
// Copyright (C) 2011-2016 by Martin Rotter <rotter.martinos@gmail.com>
//
// RSS Guard is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// RSS Guard is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with RSS Guard. If not, see <http://www.gnu.org/licenses/>.

#ifndef FORMSETTINGS_H
#define FORMSETTINGS_H

#include <QDialog>

#include "ui_formsettings.h"


class Settings;
class SettingsPanel;

class FormSettings : public QDialog {
    Q_OBJECT

  public:
    // Constructors and destructors.
    explicit FormSettings(QWidget *parent = 0);
    virtual ~FormSettings();

  private slots:
    // Displays "restart" dialog if some critical settings changed.
    void promptForRestart();

    // Saves settings into global configuration.
    void saveSettings();
    
  private:
    void addSettingsPanel(SettingsPanel *panel);

    QList<SettingsPanel*> m_panels;
    QScopedPointer<Ui::FormSettings> m_ui;
    QPushButton *m_btnApply;
    Settings *m_settings;
};

#endif // FORMSETTINGS_H
