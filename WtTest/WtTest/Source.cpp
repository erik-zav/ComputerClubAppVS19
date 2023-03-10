/*
 * Copyright (C) 2008 Emweb bv, Herent, Belgium.
 *
 * See the LICENSE file for terms of use.
 */
#pragma once
#include <Wt/WApplication.h>
#include <Wt/WWidget.h>
#include <Wt/WBreak.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include <Wt/WImage.h>
#include <Wt/WBreak.h>
#include <Wt/WBorderLayout.h>
#include <Wt/WLayout.h>
#include <Wt/WMenu.h>
#include <Wt/WStackedWidget.h>
#include <Wt/WTextArea.h>
#include <Wt/WAnimation.h>
#include <Wt/WPanel.h>



 /*
  * A simple hello world application class which demonstrates how to react
  * to events, read input, and give feed-back.
  */
class ComputerClubApplication : public Wt::WApplication
{
public:
    ComputerClubApplication(const Wt::WEnvironment& env);

private:
    Wt::WLineEdit* nameEdit_;
    Wt::WText* greeting_;

    
};

/*
 * The env argument contains information about the new session, and
 * the initial request. It must be passed to the WApplication
 * constructor so it is typically also an argument for your custom
 * application constructor.
*/
ComputerClubApplication::ComputerClubApplication(const Wt::WEnvironment& env)
    : WApplication(env)
{
    setTitle("Kent Stark Computer Club");                            // application title
    useStyleSheet("main.css");
   
    //container and layout set
    auto container = std::make_unique<Wt::WContainerWidget>();
    container->addStyleClass("main-container");
    auto layout = container->setLayout(std::make_unique<Wt::WBorderLayout>());

    //items for layout
    //top item with image
    auto pic_1 = std::make_unique<Wt::WImage>("https://www.nicepng.com/png/detail/859-8593064_cartoon-computer-clipart-pc.png", "some text");
    pic_1->setStyleClass("pic_1");
    auto frame_1 = std::make_unique<Wt::WContainerWidget>();
    frame_1->addWidget(std::move(pic_1));
    frame_1->setStyleClass("top-box");
    
   //container with middle body of text
    auto text_main = std::make_unique<Wt::WText>("lorem ipsum I forget the shortcut for blocks of latin gibberish so im gonna copy and paste this\nlorem ipsum I forget the shortcut for blocks of latin gibberish so im gonna copy and paste this\nlorem ipsum I forget the shortcut for blocks of latin gibberish so im gonna copy and paste this\nlorem ipsum I forget the shortcut for blocks of latin gibberish so im gonna copy and paste this\nlorem ipsum I forget the shortcut for blocks of latin gibberish so im gonna copy and paste this\nlorem ipsum I forget the shortcut for blocks of latin gibberish so im gonna copy and paste this\nlorem ipsum I forget the shortcut for blocks of latin gibberish so im gonna copy and paste this\n");
    text_main->addStyleClass("text-main");
    auto textbox_1 = std::make_unique<Wt::WContainerWidget>();
    textbox_1->addWidget(std::move(text_main));

    textbox_1->setStyleClass("middle-box");

    auto panel = std::make_unique<Wt::WPanel>();

    panel->setTitle("Collapsible panel");
    panel->addStyleClass("centered-example");
    panel->setCollapsible(true);

    Wt::WAnimation animation(Wt::AnimationEffect::SlideInFromTop,
                                    Wt::TimingFunction::EaseOut,
                                                            100);

    panel->setAnimation(animation);
    panel->setCentralWidget(std::make_unique<Wt::WText>("This panel can be collapsed."));
    textbox_1->addWidget(std::move(panel));
    
    //footer with simple text
    auto text_bottom = std::make_unique<Wt::WText>("Hello This is the bottom of the page, I hope!");
    text_bottom->setStyleClass("bottom-box");




    //side menu
    auto container_menu = std::make_unique<Wt::WContainerWidget>();
    auto contents = std::make_unique<Wt::WStackedWidget>();

    Wt::WMenu *menu = container_menu->addNew<Wt::WMenu>(contents.get());
    menu->setStyleClass("side-menu");
    


    // Add menu items using the default lazy loading policy.
    menu->addItem("Internal paths", std::make_unique<Wt::WTextArea>("Internal paths contents"));
    menu->addItem("Anchor", std::make_unique<Wt::WTextArea>("Anchor contents"));
    menu->addItem("Stacked widget", std::make_unique<Wt::WTextArea>("Stacked widget contents"));
    menu->addItem("Tab widget", std::make_unique<Wt::WTextArea>("Tab widget contents"));
    menu->addItem("Menu", std::make_unique<Wt::WTextArea>("Menu contents"));
    container_menu->addWidget(std::move(contents));
  

    auto placeholder = std::make_unique<Wt::WText>("Hello");
    placeholder->addStyleClass("placeholder");

    //adds each item to the layout and declares position (north, south, east, west, center)
    layout->addWidget(std::move(container_menu), Wt::LayoutPosition::West);
    layout->addWidget(std::move(placeholder), Wt::LayoutPosition::East);
    layout->addWidget(std::move(frame_1), Wt::LayoutPosition::North);
    layout->addWidget(std::move(text_bottom), Wt::LayoutPosition::South);
    layout->addWidget(std::move(textbox_1), Wt::LayoutPosition::Center);

    root()->addWidget(std::move(container));



    
    

}
//sample of button with event handling
/*

#include <Wt/WPushButton.h>

auto okPtr = std::make_unique<Wt::WPushButton>("Send");
auto ok = okPtr.get();

ok->clicked().connect(ok, &Wt::WPushButton::disable);
ok->clicked().connect([=] {
    ok->setText("Thank you");
});

*/




//sample of layout class working IN container
/*
#include <Wt/WContainerWidget.h>
#include <Wt/WBorderLayout.h>
#include <Wt/WText.h>


auto container = std::make_unique<Wt::WContainerWidget>();
container->setHeight(400);
container->setStyleClass("yellow-box");

auto layout = container->setLayout(std::make_unique<Wt::WBorderLayout>());

const char* cell = "{1} item";

auto item = std::make_unique<Wt::WText>(Wt::WString(cell).arg("North"));
item->setStyleClass("green-box");
layout->addWidget(std::move(item), Wt::LayoutPosition::North);

item = std::make_unique<Wt::WText>(Wt::WString(cell).arg("West"));
item->setStyleClass("green-box");
layout->addWidget(std::move(item), Wt::LayoutPosition::West);

item = std::make_unique<Wt::WText>(Wt::WString(cell).arg("East"));
item->setStyleClass("green-box");
layout->addWidget(std::move(item), Wt::LayoutPosition::East);

item = std::make_unique<Wt::WText>(Wt::WString(cell).arg("South"));
item->setStyleClass("green-box");
layout->addWidget(std::move(item), Wt::LayoutPosition::South);

item = std::make_unique<Wt::WText>(Wt::WString(cell).arg("Center"));
item->setStyleClass("green-box");
layout->addWidget(std::move(item), Wt::LayoutPosition::Center);

*/



int main(int argc, char** argv)
{
    /*
     * Your main method may set up some shared resources, but should then
     * start the server application (FastCGI or httpd) that starts listening
     * for requests, and handles all of the application life cycles.
     *
     * The last argument to WRun specifies the function that will instantiate
     * new application objects. That function is executed when a new user surfs
     * to the Wt application, and after the library has negotiated browser
     * support. The function should return a newly instantiated application
     * object.
     */
    return Wt::WRun(argc, argv, [](const Wt::WEnvironment& env) {
        /*
         * You could read information from the environment to decide whether
         * the user has permission to start a new application
         */
        return std::make_unique<ComputerClubApplication>(env);
        });
}
