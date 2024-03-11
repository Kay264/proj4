#include <gtest/gtest.h>
#include "StringUtils.h"

//You want your tests to fail first
TEST(StringUtilsTest, SliceTest){
    std::string Base = "Hello";

    EXPECT_EQ(StringUtils::Slice(Base,0),"Hello");
    EXPECT_EQ(StringUtils::Slice(Base,1),"ello");
}  

TEST(StringUtilsTest, Capitalize){
    std::string Base = "hello";

    EXPECT_EQ(StringUtils::Capitalize(Base),"Hello");
    EXPECT_EQ(StringUtils::Capitalize(std::string()),"");
    EXPECT_EQ(StringUtils::Capitalize(" hello")," hello");
    EXPECT_EQ(StringUtils::Capitalize("HELLO"),"Hello"); 
}

TEST(StringUtilsTest, Upper){
    std::string Base = "hello";

    EXPECT_EQ(StringUtils::Upper(Base),"HELLO");
    EXPECT_EQ(StringUtils::Upper(std::string()),"");
    EXPECT_EQ(StringUtils::Upper(" hello")," HELLO");
    EXPECT_EQ(StringUtils::Upper("HELLO"),"HELLO"); 
}

TEST(StringUtilsTest, Lower){
    std::string Base = "hello";

    EXPECT_EQ(StringUtils::Lower(Base),"hello");
    EXPECT_EQ(StringUtils::Lower(std::string()),"");
    EXPECT_EQ(StringUtils::Lower(" hello")," hello");
    EXPECT_EQ(StringUtils::Lower("HELLO"),"hello");
}

TEST(StringUtilsTest, LStrip){
    std::string Base = "hello";

    EXPECT_EQ(StringUtils::LStrip(Base),"hello");
    EXPECT_EQ(StringUtils::LStrip(std::string()),"");
    EXPECT_EQ(StringUtils::LStrip(" hello"),"hello");
    EXPECT_EQ(StringUtils::LStrip("      hello"),"hello");
    EXPECT_EQ(StringUtils::LStrip("      hello    "),"hello    ");
    EXPECT_EQ(StringUtils::LStrip("      hel   lo    "),"hel   lo    ");
    EXPECT_EQ(StringUtils::LStrip("      hel   lo    lo      "),"hel   lo    lo      ");
    EXPECT_EQ(StringUtils::LStrip("    "),"");
}

TEST(StringUtilsTest, RStrip){
    std::string Base = "hello";

    EXPECT_EQ(StringUtils::RStrip(Base),"hello");
    EXPECT_EQ(StringUtils::RStrip(std::string()),"");
    EXPECT_EQ(StringUtils::RStrip(" hello")," hello");
    EXPECT_EQ(StringUtils::RStrip("      hello"),"      hello");
    EXPECT_EQ(StringUtils::RStrip("      hello    "),"      hello");
    EXPECT_EQ(StringUtils::RStrip("      hel   lo    "),"      hel   lo");
    EXPECT_EQ(StringUtils::RStrip("      hel   lo    lo      "),"      hel   lo    lo");
    EXPECT_EQ(StringUtils::RStrip("    "),"");
}

TEST(StringUtilsTest, Strip){
    std::string Base = "hello";

    EXPECT_EQ(StringUtils::Strip(Base),"hello");
    EXPECT_EQ(StringUtils::Strip(std::string()),"");
    EXPECT_EQ(StringUtils::Strip(" hello"),"hello");
    EXPECT_EQ(StringUtils::Strip("      hello"),"hello");
    EXPECT_EQ(StringUtils::Strip("      hello    "),"hello");
    EXPECT_EQ(StringUtils::Strip("      hel   lo    "),"hel   lo");
    EXPECT_EQ(StringUtils::Strip("      hel   lo    lo      "),"hel   lo    lo");
    EXPECT_EQ(StringUtils::Strip("    "),"");
}

// Returns the center/left/right justified strings
TEST(StringUtilsTest, Center){
    std::string Base = "hello";

    EXPECT_EQ(StringUtils::Center(Base, 6, ' '), "   hello   ");
    EXPECT_EQ(StringUtils::Center(Base, 7, ' '), "   hello    ");
}

TEST(StringUtilsTest, LJust){
    std::string Base = "hello";

    EXPECT_EQ(StringUtils::LJust(Base, 6, ' '), "hello      ");
    EXPECT_EQ(StringUtils::LJust(Base, 7, ' '), "hello       ");    
}

TEST(StringUtilsTest, RJust){
    std::string Base = "hello";

    EXPECT_EQ(StringUtils::RJust(Base, 6, ' '), "      hello");
    EXPECT_EQ(StringUtils::RJust(Base, 7, ' '), "       hello");    
}

// Returns the string str with all instances of old replaced with rep
TEST(StringUtilsTest, Replace){
    std::string Base = "a";
    EXPECT_EQ(StringUtils::Replace(Base, "a", "b"), "b");
    EXPECT_EQ(StringUtils::Replace("aa", "aa", "b"), "b");
    EXPECT_EQ(StringUtils::Replace("aaa", "a", "b"), "bbb");
    EXPECT_EQ(StringUtils::Replace(" aaa", " ", "b"), "baaa");
    EXPECT_EQ(StringUtils::Replace(" a  a a", "a  a", "b"), " b a");
}

// Splits the string up into a vector of strings based on splt parameter, if
// splt parameter is empty string, then split on white space
TEST(StringUtilsTest, Split){
    std::string Base = "bab";
    EXPECT_EQ(StringUtils::Split(Base, "a"), (std::vector<std::string>{"b", "b"}));
    EXPECT_EQ(StringUtils::Split("a a", " "), (std::vector<std::string>{"a", "a"}));
    EXPECT_EQ(StringUtils::Split("a a a", " "), (std::vector<std::string>{"a", "a", "a"}));
    EXPECT_EQ(StringUtils::Split("bb a a", " "), (std::vector<std::string>{"bb", "a", "a"}));
}

TEST(StringUtilsTest, Join){
    std::string Base = "a";
    EXPECT_EQ(StringUtils::Join(" ", (std::vector<std::string>{"b", "b"})), "b b");
    EXPECT_EQ(StringUtils::Join(" ", (std::vector<std::string>{"bb", "a", "a"})), "bb a a");
    EXPECT_EQ(StringUtils::Join(" ", (std::vector<std::string>{"a", "a", "a"})), "a a a");
    EXPECT_EQ(StringUtils::Join(" ", (std::vector<std::string>{"a", "a"})), "a a");
}

TEST(StringUtilsTest, ExpandTabs){
    std::string Base = "a";
    EXPECT_EQ(StringUtils::ExpandTabs("\ta", 3), "   a");
    EXPECT_EQ(StringUtils::ExpandTabs("\taaa", 3), "   aaa");
    EXPECT_EQ(StringUtils::ExpandTabs("\ta", 4), "    a");
    EXPECT_EQ(StringUtils::ExpandTabs("\ta\t", 3), "   a   ");
    EXPECT_EQ(StringUtils::ExpandTabs("\ta\t ", 3), "   a    ");
}

TEST(StringUtilsTest, EditDistance){
    std::string Base = "a";
    EXPECT_EQ(StringUtils::EditDistance("a", "b", true), 1);
    EXPECT_EQ(StringUtils::EditDistance("aaa", "bbb", false), 3);
    EXPECT_EQ(StringUtils::EditDistance("bb", "cccd", false), 4);
    EXPECT_EQ(StringUtils::EditDistance("pets", "cats", true), 2);
    EXPECT_EQ(StringUtils::EditDistance("bb", "Bccd", false), 4);
    EXPECT_EQ(StringUtils::EditDistance("bb", "Bccd", true), 3);
}

// #include <gtest/gtest.h>
// #include "StringUtils.h"

// TEST(StringUtilsTest, SliceTest){
//     EXPECT_EQ(StringUtils::Slice("Hello World!",1), "ello World!");
//     EXPECT_EQ(StringUtils::Slice("Hello World!",0,5), "Hello");
//     EXPECT_EQ(StringUtils::Slice("Hello World!",0,-1), "Hello World");
//     EXPECT_EQ(StringUtils::Slice("Hello World!",3,-2), "lo Worl");
//     EXPECT_EQ(StringUtils::Slice("Hello World!",-5,-2), "orl");
//     EXPECT_EQ(StringUtils::Slice("Hello World!",14), "");
// }

// TEST(StringUtilsTest, Capitalize){
//     EXPECT_EQ(StringUtils::Capitalize("hello world!"), "Hello world!");
//     EXPECT_EQ(StringUtils::Capitalize("HELLO WORLD!"), "Hello world!");
//     EXPECT_EQ(StringUtils::Capitalize(" HELLO WORLD!"), " hello world!");
// }

// TEST(StringUtilsTest, Upper){
//     EXPECT_EQ(StringUtils::Upper("hello world!"), "HELLO WORLD!");
//     EXPECT_EQ(StringUtils::Upper("Hello World!"), "HELLO WORLD!");
//     EXPECT_EQ(StringUtils::Upper("HELLO WORLD!"), "HELLO WORLD!");
//     EXPECT_EQ(StringUtils::Upper(" HELLO WORLD!"), " HELLO WORLD!");
// }

// TEST(StringUtilsTest, Lower){
//     EXPECT_EQ(StringUtils::Lower("hello world!"), "hello world!");
//     EXPECT_EQ(StringUtils::Lower("Hello World!"), "hello world!");
//     EXPECT_EQ(StringUtils::Lower("HELLO WORLD!"), "hello world!");
//     EXPECT_EQ(StringUtils::Lower(" HELLO WORLD!"), " hello world!");
// }

// TEST(StringUtilsTest, LStrip){
//     std::string Str1 = "    Test String    ";
//     std::string Str2 = " \t \r\n Test String";
//     std::string Str3 = "Test String \t \r\n ";
//     EXPECT_EQ(StringUtils::LStrip(Str1), "Test String    ");
//     EXPECT_EQ(StringUtils::LStrip(Str2), "Test String");
//     EXPECT_EQ(StringUtils::LStrip(Str3), Str3);
// }

// TEST(StringUtilsTest, RStrip){
//     std::string Str1 = "    Test String    ";
//     std::string Str2 = " \t \r\n Test String";
//     std::string Str3 = "Test String \t \r\n ";
//     EXPECT_EQ(StringUtils::RStrip(Str1), "    Test String");
//     EXPECT_EQ(StringUtils::RStrip(Str2),Str2);
//     EXPECT_EQ(StringUtils::RStrip(Str3), "Test String");
// }

// TEST(StringUtilsTest, Strip){
//     std::string Str1 = "    Test String    ";
//     std::string Str2 = " \t \r\n Test String";
//     std::string Str3 = "Test String \t \r\n ";
//     EXPECT_EQ(StringUtils::Strip(Str1), "Test String");
//     EXPECT_EQ(StringUtils::Strip(Str2), "Test String");
//     EXPECT_EQ(StringUtils::Strip(Str3), "Test String");
//     EXPECT_EQ(StringUtils::Strip(Str1),StringUtils::RStrip(StringUtils::LStrip(Str1)));
//     EXPECT_EQ(StringUtils::Strip(Str2),StringUtils::RStrip(StringUtils::LStrip(Str2)));
//     EXPECT_EQ(StringUtils::Strip(Str3),StringUtils::RStrip(StringUtils::LStrip(Str3)));
// }

// TEST(StringUtilsTest, Center){
//     EXPECT_EQ(StringUtils::Center("Test String",19), "    Test String    ");
//     EXPECT_EQ(StringUtils::Center("Test String",16,'-'), "--Test String---");
//     EXPECT_EQ(StringUtils::Center("Test String",5,'-'), "Test String");
// }

// TEST(StringUtilsTest, LJust){
//     EXPECT_EQ(StringUtils::LJust("Test String",19), "Test String        ");
//     EXPECT_EQ(StringUtils::LJust("Test String",5), "Test String");
// }

// TEST(StringUtilsTest, RJust){
//     EXPECT_EQ(StringUtils::RJust("Test String",19), "        Test String");
//     EXPECT_EQ(StringUtils::RJust("Test String",5), "Test String");
// }

// TEST(StringUtilsTest, Replace){
//     EXPECT_EQ(StringUtils::Replace("\\Path\\To\\A\\Directory","\\","/"), "/Path/To/A/Directory");
//     EXPECT_EQ(StringUtils::Replace("a = b + c * b + d","b","e"), "a = e + c * e + d");
//     EXPECT_EQ(StringUtils::Replace("aabbccaaabbbcccaaaa","aa","ee"), "eebbcceeabbbccceeee");
// }

// TEST(StringUtilsTest, Split){
//     auto PathComponents = StringUtils::Split("/Path/To/A/Directory","/");
//     ASSERT_EQ(PathComponents.size(), 5);
//     EXPECT_EQ(PathComponents[0], "");
//     EXPECT_EQ(PathComponents[1], "Path");
//     EXPECT_EQ(PathComponents[2], "To");
//     EXPECT_EQ(PathComponents[3], "A");
//     EXPECT_EQ(PathComponents[4], "Directory");
    
//     auto SentenceComponents = StringUtils::Split("A  tougher\ttest\nto   pass!");
//     ASSERT_EQ(SentenceComponents.size(), 5);
//     EXPECT_EQ(SentenceComponents[0], "A");
//     EXPECT_EQ(SentenceComponents[1], "tougher");
//     EXPECT_EQ(SentenceComponents[2], "test");
//     EXPECT_EQ(SentenceComponents[3], "to");
//     EXPECT_EQ(SentenceComponents[4], "pass!");
// }

// TEST(StringUtilsTest, Join){
//     std::vector<std::string> PathComponents = {"", "Path", "To", "A", "Directory"};
//     EXPECT_EQ(StringUtils::Join("/",PathComponents), "/Path/To/A/Directory");
    
//     std::vector<std::string>  SentenceComponents = {"A","tougher","test","to","pass!"};
//     EXPECT_EQ(StringUtils::Join(" ",SentenceComponents), "A tougher test to pass!");
// }

// TEST(StringUtilsTest, ExpandTabs){
//     EXPECT_EQ(StringUtils::ExpandTabs("1\t2\t3\t4"), "1   2   3   4");
//     EXPECT_EQ(StringUtils::ExpandTabs("1\t12\t123\t1234"), "1   12  123 1234");
//     EXPECT_EQ(StringUtils::ExpandTabs("1234\t123\t12\t1"), "1234    123 12  1");
//     EXPECT_EQ(StringUtils::ExpandTabs("1234\t123\t12\t1",3), "1234  123   12 1");
//     EXPECT_EQ(StringUtils::ExpandTabs("1234\t123\t12\t1",0), "1234123121");
// }

// TEST(StringUtilsTest, EditDistance){
//     EXPECT_EQ(StringUtils::EditDistance("1234","1234"), 0);
//     EXPECT_EQ(StringUtils::EditDistance("Test","test"), 1);
//     EXPECT_EQ(StringUtils::EditDistance("Test","test",true), 0);
//     EXPECT_EQ(StringUtils::EditDistance("12345","52341"), 2);
//     EXPECT_EQ(StringUtils::EditDistance("This is an example","This is a sample"), 3);
//     EXPECT_EQ(StringUtils::EditDistance("int Var = Other + 3.4;","int x = y + 3.4;"), 8);
// }
