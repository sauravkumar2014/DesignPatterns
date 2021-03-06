#include <iostream>
#include <sstream>
#include "basic_builder.h"
using namespace std;

string HtmlElement::str(int indent = 0) const
{
	ostringstream oss;
	string i(indent_size * indent, ' ');
	oss << i << "<" << tag << ">" << endl;
	if(text.size() > 0)
		oss << string(indent_size * (indent + 1), ' ') << text << endl;

	for(const auto &e : children)
		oss << e.str(indent + 1);

	oss << i << "</" << tag << ">" << endl;
	return oss.str();
}

HtmlBuilder HtmlElement::create(string root_tag)
{
	return {root_tag};
}

void HtmlBuilder::add_child(string child_name, string child_text)
{
	HtmlElement e(child_name, child_text);
	(*root).children.emplace_back(e);
}

string HtmlBuilder::str() const { return (*root).str(); }

int main(int argc, char const *argv[])
{
	HtmlBuilder builder{"ul"};
	builder.add_child("li","hello");
	builder.add_child("li","world");

	cout<<builder.str()<<endl;
	return 0;
}