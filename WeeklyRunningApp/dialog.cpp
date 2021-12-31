#include "dialog.h"
#include "./ui_dialog.h"
#include <stdlib.h>


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->runnerType->addItem("Distance");
    ui->runnerType->addItem("Sprinting");
    ui->runnerType->setCurrentIndex(0);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_runnerType_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    runnerTypeString = ui->runnerType->currentText();
}

void Dialog::on_update_clicked()
{
    int rows =  sizeof mileagePercents / sizeof mileagePercents[0];
    int indexSelected = rand() % rows;
    mondayMileage = (int) (mileagePercents[indexSelected][0] * weeklyMileageNum);
    tuesdayMileage = (int)  (mileagePercents[indexSelected][1] * weeklyMileageNum);
    wednesdayMileage = (int) (mileagePercents[indexSelected][2] * weeklyMileageNum);
    thursdayMileage = (int)  (mileagePercents[indexSelected][3] * weeklyMileageNum);
    fridayMileage =  (int) (mileagePercents[indexSelected][4] * weeklyMileageNum);
    saturdayMileage = (int)  (mileagePercents[indexSelected][5] * weeklyMileageNum);
    sundayMileage = (int)  (mileagePercents[indexSelected][6] * weeklyMileageNum);

    ui->mon->setText(QString::number(mondayMileage));
    ui->tue->setText(QString::number(tuesdayMileage));
    ui->wed->setText(QString::number(wednesdayMileage));
    ui->thur->setText(QString::number(thursdayMileage));
    ui->fri->setText(QString::number(fridayMileage));
    ui->sat->setText(QString::number(saturdayMileage));
    ui->sun->setText(QString::number(sundayMileage));

    if(runnerTypeString=="Distance"){
        int lenDis = sizeof(distanceWorkouts)/sizeof(distanceWorkouts[0]);
        int firstWorkoutDisIndex = rand() % lenDis;
        int secondWorkoutDisIndex = rand() % lenDis;
        ui->wk1->setText(distanceWorkouts[firstWorkoutDisIndex]);
        ui->wk2->setText(distanceWorkouts[secondWorkoutDisIndex]);
    }
    if(runnerTypeString=="Sprinting"){
        int lenSprints = sizeof(sprintWorkouts)/sizeof(sprintWorkouts[0]);
        int firstWorkoutSprintIndex = rand() % lenSprints;
        int secondWorkoutSprintIndex = rand() % lenSprints;
        ui->wk1->setText(distanceWorkouts[firstWorkoutSprintIndex]);
        ui->wk2->setText(distanceWorkouts[secondWorkoutSprintIndex]);
    }


}

void Dialog::on_weeklyMileage_editingFinished()
{
    bool numberEntered = false;
    weeklyMileageNum = ui->weeklyMileage->text().toInt(&numberEntered);
}

