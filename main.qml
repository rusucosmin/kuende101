import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.4
import QtGraphicalEffects 1.0
import com.kuende.cosmin.kuende101 1.0
import QtQuick.Window 2.2
import QtQuick.Layouts 1.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Kuende Challenge!")

    MainForm {
        id: mainForm
        anchors.fill: parent


        TabView {
            id: tabView
            anchors.fill: parent
            tabPosition: Qt.BottomEdge

            Tab {
                id: redditPostTab;
                title: "List"
                anchors.fill: parent;
                anchors.margins: 10
                ListView {
                    id: redditPostListView
                    model: RedditPostModel {}
                    delegate: Rectangle {
                        width: parent.width;
                        height: width / 4 + upvotes.height + 20
                        property real imgheight: width / 4
                        anchors.margins: 10
                        Image {
                            id: img
                            height: parent.imgheight
                            width: parent.imgheight
                            anchors.left: parent.left;
                            anchors.top: parent.top
                            anchors.margins: 10
                            fillMode: Image.PreserveAspectCrop
                            source: model.imageUrl
                            onStatusChanged:
                                if (img.status == Image.Ready)
                                    loadingImg.visible = false;
                            Image {
                                id: loadingImg
                                anchors.fill: parent;
                                source: 'img/loading.gif'
                            }
                        }
                        Text {
                            id: upvotes
                            text: model.upvotes
                            anchors.margins: 10
                            anchors.top: img.bottom
                            anchors.left: parent.left
                        }
                        Text {
                            anchors.top: parent.top;
                            anchors.left: img.right
                            anchors.margins: 10
                            clip: true
                            wrapMode: Text.Wrap
                            width: parent.width - img.width
                            height: img.height
                            id: title
                            text: model.title;
                            font.pointSize: 20
                        }
                        Text {
                            anchors.top: title.bottom
                            anchors.right: parent.right;
                            clip: true
                            wrapMode: Text.Wrap
                            anchors.margins: 10
                            text: "By " + model.author + " on r/" + model.subreddit
                        }

                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            redditPostListView.currentIndex = index;
                        }
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
                    model: RandomStringModel {
                        id: randomStringModel;
                    }

                    delegate: Rectangle {
                        id: wrapper
                        border.width: 2
                        border.color: 'grey'
                        color: randomStringListView.currentIndex == index ? '#4283f4' : 'white'
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
                            }
                        }
                        width: parent.width
                        height: random_text.height;
                    }
                    highlightMoveDuration: 20
                    focus: false;
                    currentIndex: -1
                }
            }
            Tab {
                id: moveTab;
                title: "Move"

                DropArea {
                    /*  RadialGradient {
                        width: 500
                        height: 500
                        clip: true
                        source: Image {
                            source: "img/circle.png"
                        }
                        horizontalOffset: 0
                        verticalOffset: 0
                        horizontalRadius: 250
                        verticalRadius: 250
                        angle: 0
                    }
                    */

                    Rectangle {
                        id: control
                        x: Math.random() * (parent.width - 400)
                        y: Math.random() * (parent.height - 400)
                        width: 400
                        height: 400
                        radius: 0.5*control.width

                        Drag.active: dragArea.drag.active
                        Drag.hotSpot.x: 10
                        Drag.hotSpot.y: 10


                        RadialGradient {
                            anchors.fill: parent;

                            source: Image {
                                source: "img/circle.png"
                            }

                            gradient: Gradient {
                                GradientStop {
                                    position: 0.000
                                    color: Qt.rgba(1, 0, 0, 1)
                                }
                                GradientStop {
                                    position: 0.167
                                    color: Qt.rgba(1, 1, 0, 1)
                                }
                                GradientStop {
                                    position: 0.333
                                    color: Qt.rgba(0, 1, 0, 1)
                                }
                                GradientStop {
                                    position: 0.500
                                    color: Qt.rgba(0, 1, 1, 1)
                                }
                                GradientStop {
                                    position: 0.667
                                    color: Qt.rgba(0, 0, 1, 1)
                                }
                                GradientStop {
                                    position: 0.833
                                    color: Qt.rgba(1, 0, 1, 1)
                                }
                                GradientStop {
                                    position: 1.000
                                    color: Qt.rgba(1, 0, 0, 1)
                                }
                            }
                        }
                    }
                    MouseArea {
                        id: dragArea
                        anchors.fill: parent
                        drag.target: parent
                    }
                }
            }
            Tab {
                id: animationTab
                title: "Animation"
                Rectangle {
                    Rectangle {
                        id: square
                        x: 250
                        y: 250
                        width: 400
                        height: 400
                        color: "yellow"
                        border.width: 10
                        border.color: 'red'
                        Behavior on width {
                            NumberAnimation {
                                duration: 500
                            }
                        }
                        Behavior on height {
                            NumberAnimation {
                                duration: 500
                            }
                        }
                        Behavior on x {
                            NumberAnimation {
                                duration: 500
                            }
                        }
                        Behavior on y {
                            NumberAnimation {
                                duration: 500
                            }
                        }
                        Behavior on color {
                            ColorAnimation {
                                duration: 500
                            }
                        }
                    }
                    Row {
                        anchors.bottom: parent.bottom;
                        anchors.horizontalCenter: parent
                        Button {
                            id: moveButton
                            focus: false
                            text: "Move"
                            onClicked: moveSquare()
                        }
                        Button {
                            id: colorBtn
                            focus: false
                            text: "Color"
                            onClicked: colorSquare()
                        }
                        Button {
                            id: sizeBtn
                            focus: false
                            text: "Size"
                            onClicked: sizeSquare()
                        }
                        Button {
                            id: resetBtn
                            focus: false
                            text: "Reset"
                            onClicked: resetSquare()
                        }
                    }

                    function moveSquare() {
                        square.x = Math.random() * (square.parent.width - square.width);
                        square.y = Math.random() * (square.parent.height- square.height);
                    }
                    function colorSquare() {
                        /// TODO: indeed check if the chosen color does not equal the current color :)
                        var colArr = ['red', 'yellow', 'blue', 'black', '#123456', 'green']
                        var aux = Math.floor(Math.random() * colArr.length)
                        console.log(colArr);
                        console.log(colArr[aux])
                        console.log(aux)
                        square.color = colArr[aux]
                    }
                    function sizeSquare() {
                        square.width += 50
                        square.height += 50
                    }

                    function resetSquare() {
                        square.x = 250;
                        square.y = 250;
                        square.width = 400;
                        square.height = 400;
                        square.color = "yellow"
                    }
                }
            }
        }
    }
}
