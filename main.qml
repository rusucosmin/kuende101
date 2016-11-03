import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.4
import com.kuende.cosmin.kuende101 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Kuende Challenge!")

    MainForm {
        id: mainForm
        anchors.fill: parent

        RandomStringModel {
            id: randomStringModel;
        }

        TabView {
            id: tabView
            anchors.fill: parent
            anchors.margins: 10
            tabPosition: Qt.BottomEdge

            Tab {
                id: redditPostTab;
                title: "List"
                anchors.fill: parent;
                ListView {
                    id: redditPostListView
                    model: ListModel {
                        ListElement { text: "element0" }
                        ListElement { text: "element1" }
                        ListElement { text: "element2" }
                        ListElement { text: "element3" }
                        ListElement { text: "element4" }
                        ListElement { text: "element5" }
                        ListElement { text: "element6" }
                        ListElement { text: "element7" }
                        ListElement { text: "element8" }
                        ListElement { text: "element9" }
                        ListElement { text: "element10" }
                        ListElement { text: "element11" }
                        ListElement { text: "element12" }
                        ListElement { text: "element13" }
                    }
                    delegate: Item {
                        Text {
                            id: text
                            text: model.text
                            font.pointSize: 50
                            anchors.centerIn: parent
                            anchors.margins: 10
                        }
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                redditPostListView.currentIndex = index;
                                console.log("tocmai ai atins: " + index);
                            }
                        }
                        width: parent.width
                        height: text.height;
                    }
                    highlight: Rectangle {
                        color: "lightsteelblue"
                    }
                    highlightMoveDuration: 20
                    focus: false
                }
            }
            Tab {
                id: randomListTab
                title: "C++ List"
                ListView {
                    id: randomStringListView
                    model: randomStringModel
                    delegate: Rectangle {
                        id: wrapper
                        border.width: 1
                        border.color: 'grey'
                        color: randomStringListView.currentIndex == index ? 'lightsteelblue' : 'white'
                        Text {
                            id: random_text
                            font.pointSize: 20
                            width: parent.width
                            wrapMode: Text.Wrap
                            text: model.display
                            clip: true
                        }
                        MouseArea {
                            anchors.fill:parent
                            onClicked: {
                                randomStringListView.currentIndex = index
                                console.log("you just clicked " + index);
                            }
                        }
                        width: parent.width
                        height: random_text.height;
                    }
                    highlight: Rectangle {
                        anchors.fill: parent;
                        color: "lightsteelblue"
                    }
                    highlightMoveDuration: 20
                    focus: false;
                }
            }
            Tab {
                id: moveTab;
                title: "Move"
                Rectangle {
                    color: "blue"
                }
            }
            Tab {
                id: animationTab;
                title: "Animation"
                Rectangle {
                    color: "red"
                }
            }
        }
    }
}
