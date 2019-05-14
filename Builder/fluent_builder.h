#include <vector>
#include <string>
#include <memory>
#include <sstream>
using namespace std;

class HtmlBuilder;

class HtmlElement
{
	friend class HtmlBuilder;
	friend unique_ptr<HtmlElement> make_unique<HtmlElement>(const string &);
	friend unique_ptr<HtmlElement> make_unique<HtmlElement>(const string &,const string &);
	string tag,text;
	const size_t indent_size = 2;
	vector<HtmlElement> children;
	HtmlElement() {}
	HtmlElement(const string &tag) : tag(tag) {}
	HtmlElement(const string &tag, const string &text) : tag(tag), text(text) {}
public:
	string str(int indent) const;
	static HtmlBuilder create(string root_tag);
};

class HtmlBuilder
{
	unique_ptr<HtmlElement> root;
public:
	HtmlBuilder() {}
	HtmlBuilder(const string &str) : root(make_unique<HtmlElement>(str)) {}
	HtmlBuilder(const string &tag, const string &txt) : root(make_unique<HtmlElement>(tag,txt)) {}

	HtmlBuilder& add_child(string child_name, string child_text);

	string str() const;
	operator unique_ptr<HtmlElement>() { return move(root); }
};