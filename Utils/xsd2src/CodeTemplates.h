/*
 * CodeTemplates.h: Definition of the class CodeComposer This class
 * implements source code composition.
 *
 * Copyright (c) 1999-2017, Parallels International GmbH
 * Copyright (c) 2017-2023 Virtuozzo International GmbH. All rights reserved.
 *
 * This file is part of Virtuozzo SDK. Virtuozzo SDK is free
 * software; you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License,
 * or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see
 * <http://www.gnu.org/licenses/> or write to Free Software Foundation,
 * 51 Franklin Street, Fifth Floor Boston, MA 02110, USA.
 *
 * Our contact details: Virtuozzo International GmbH, Vordergasse 59, 8200
 * Schaffhausen, Switzerland.
 */


#ifndef CODE_TEMPLATES_H
#define CODE_TEMPLATES_H

// Project include template defines

#define PRI_CAPTION \
	"#///////////////////////////////////////////////////////////////////////////////\n" \
	"#//\n" \
	"#// %1.pri\n" \
	"#//\n" \
	"#// ***DO NOT EDIT THIS FILE***\n" \
	"#// ***IT IS GENERATED AUTOMATICALLY BY xsd2src UTILITY***\n" \
	"#//\n" \
	"#///////////////////////////////////////////////////////////////////////////////\n\n"

#define PRI_GEN_DIR_HEADERS \
	"GEN_DIR_HEADERS = \\\n"
#define PRI_GEN_HEADERS \
	"\nGEN_HEADERS += $${GEN_DIR_HEADERS}\n"
#define PRI_GEN_SOURCES \
	"GEN_SOURCES += \\\n"
#define PRI_FILE \
	"\t\t$$PWD/%1 \\\n"
#define PRI_GEN_PRIFILES \
	"GEN_PRIFILES += $$PWD/%1.pri\n"

#define PRI_GEN_INSTALL_HEADERS \
	"headers_%1.files = $${GEN_DIR_HEADERS}\n" \
	"headers_%1.path = $${PREFIX}/include/prlxmlmodel/%1\n" \
	"INSTALLS += headers_%1\n"

// Header template defines

#define HDR_CAPTION \
	"////////////////////////////////////////////////////////////////////////////////\n" \
	"///\n" \
	"/// %1.h\n" \
	"///\n" \
	"/// ***DO NOT EDIT THIS FILE***\n" \
	"/// ***IT IS GENERATED AUTOMATICALLY BY xsd2src UTILITY***\n" \
	"///\n" \
	"////////////////////////////////////////////////////////////////////////////////\n\n"

#define HDR_PRAGMA \
	"#ifndef %1_H\n" \
	"#define %2_H\n" \
	"\n\n"

#define HDR_INCLUDES \
	"#include <prlcommon/PrlObjects/CBaseNode.h>\n"

#define HDR_INCLUDE \
	"#include \"%1.h\"\n"
#define HDR_INCLUDE_EXTERN \
	"#include \"%1\"\n"
#define HDR_INCLUDE_ADDITIONAL \
	"#include %1\n"

#define HDR_CLASS \
	"\n\nclass %1 :"

#define DEFAULT_BASE_CLASS \
	"CBaseNode"

#define DEFAULT_SIGNALS_BASE_CLASS \
	"CBaseNodeSignals"

#define HDR_DEFAULT_BASE_CLASS \
	" public " DEFAULT_BASE_CLASS "\n"

#define HDR_DEFAULT_SIGNALS_BASE_CLASS \
	" public " DEFAULT_SIGNALS_BASE_CLASS "\n"

#define HDR_BASE_CLASS_IDENT \
	"\t\t\t\t,"
#define HDR_BASE_CLASS \
	HDR_BASE_CLASS_IDENT" public %1\n"

#define HDR_CLASS_PUBLIC \
	"{\n" \
	"\npublic:\n\n"
#define HDR_Q_OBJECT_CLASS_PUBLIC \
	"{\n" \
	"\tQ_OBJECT\n" \
	"\npublic:\n\n"

#define HDR_CONSTRUCTORS \
	"\t%1();\n" \
	"\t%2(const %3& rObject);\n" \
	"\t%4(const %5* pObject);\n" \
	"\t%6(QFile* pFile);\n"

#define HDR_ASSIGN_OPERATOR \
	"\t%1& operator=(const %2& rObject);\n"

#define HDR_VIRTUAL_DESTRUCTOR \
	"\tvirtual ~%1();\n\n"

#define HDR_LIST_MEMBER \
	"\tQList<%1* >\t\tm_lst%2;\n"
#define HDR_GET_SINGLE_LIST_MEMBER \
	"\t%1%2* get%3() const;\n"
#define HDR_SET_SINGLE_LIST_MEMBER \
	"\t%1void set%2(%3* p%4);\n"

#define HDR_IS_METHOD \
	"\n\t%1bool is%2() const;\n"
#define HDR_GET_METHOD \
	"\n\t%1%2 get%3() const;\n"
#define HDR_SET_METHOD \
	"\t%1void set%2(%3 value = %4);\n"
#define HDR_GET_METHOD_ID \
	"\tQString get%1_id() const;\n"

#define HDR_METHOD_PRIVATE_BEGIN \
	"private:"
#define HDR_METHOD_PRIVATE_END \
	"public:\n"

#define HDR_XML \
	"\n\tvirtual QDomElement getXml(QDomDocument* Document, bool no_save_option = false) const;\n" \
	"\tvirtual int readXml(QDomElement* RootElement, QString ext_tag_name = QString(), bool unite_with_loaded = false);\n" \
	"\tvirtual void syncItemIds();\n"

#define HDR_DEFAULTS \
	"\n\tvirtual void setDefaults(QDomElement* RootElement = 0);\n"

#define HDR_PROPERTY \
	"\n\tvirtual QVariant getPropertyValue(QString path) const;\n" \
	"\tvirtual bool setPropertyValue(QString path, QVariant value, bool* pbValueChanged = 0);\n"
#define HDR_LIST_IFACE \
	"\n\tint addListItem(QString path);\n" \
	"\tbool deleteListItem(QString path);\n"

#define HDR_MERGE \
	"\n\tbool merge(%1* pCur, %1* pPrev, MergeOptions nOptions);\n"

#define HDR_DIFF \
	"\n\tvoid diff(const %1* pOld, QStringList& lstDiffFullItemIds) const;\n"

#define HDR_CLASS_PROTECTED \
	"\nprotected:\n\n"

#define HDR_SIMPLE_MEMBER \
	"\t%1\t\tm_%2%3;\n"

#define HDR_COPY \
	"\tvoid Copy(const %1& rObject);\n"

#define HDR_INIT_LISTS \
	"\n\tvirtual void InitLists();\n"

#define HDR_CLEAR_LISTS \
	"\tvirtual void ClearLists();\n"

#define HDR_CLEAR_LISTS_IN_READ_XML \
	"\tvirtual void ClearListsInReadXml(bool unite_with_loaded = false, const QStringList& dyn_lists = QStringList(), bool bSupportDynList = true);\n"

#define HDR_CLASS_SIGNALS \
	"\nsignals:\n\n"
#define HDR_SIGNAL \
	"\tvoid signal%1Changed(%2 value, QString object_id = QString());\n"
#define HDR_CLASS_SLOTS \
	"\nprivate slots:\n\n"
#define HDR_SLOT \
	"\tvoid slotChange%1(%2 value);\n"

#define HDR_END_CLASS \
	"\n};\n\n"

#define HDR_DECLARE_METATYPE \
	"#ifndef DM_%1\n" \
	"#define DM_%1\n" \
	"Q_DECLARE_METATYPE(%2)\n" \
	"#endif\n"

#define HDR_END \
	"\n\n#endif\n"

// Unit template defines

#define UNIT_CAPTION \
	"////////////////////////////////////////////////////////////////////////////////\n" \
	"///\n" \
	"/// %1.cpp\n" \
	"///\n" \
	"/// ***DO NOT EDIT THIS FILE***\n" \
	"/// ***IT IS GENERATED AUTOMATICALLY BY xsd2src UTILITY***\n" \
	"///\n" \
	"////////////////////////////////////////////////////////////////////////////////\n\n"

#define UNIT_INCLUDE \
	"#include \"%1.h\"\n\n\n"

#define UNIT_DEFAULT_CONSTRUCTOR \
	"%1::%2()\n" \
	"{\n" \
	"\tInitLists();\n" \
	"\tsetDefaults();\n" \
	"}\n\n"

#define UNIT_COPY_CONSTRUCTOR \
	"%1::%2(const %3& rObject)\n" \
	": %4\n" \
	"{\n" \
	"\tCopy(rObject);\n" \
	"}\n\n"

#define UNIT_POINTER_CONSTRUCTOR \
	"%1::%2(const %3* pObject)\n" \
	"{\n" \
	"\tif (pObject)\n" \
	"\t{\n" \
	"\t\tCopy(*pObject);\n" \
	"\t}\n" \
	"\telse\n" \
	"\t{\n" \
	"\t\tInitLists();\n" \
	"\t\tsetDefaults();\n" \
	"\t}\n" \
	"}\n\n"
/*
#define UNIT_INITIALIZE_CONSTRUCTOR \
	"%1::%2(QString source_string)\n" \
	"{\n" \
	"\tfromString(source_string);\n" \
	"}\n\n"
*/

#define UNIT_FILE_CONSTRUCTOR \
	"%1::%2(QFile* pFile)\n" \
	"{\n" \
	"\tInitLists();\n" \
	"\tloadFromFile(pFile);\n" \
	"}\n\n"

#define UNIT_ASSIGN_OPERATOR \
	"%1& %2::operator=(const %3& rObject)\n" \
	"{\n" \
	"\tCopy(rObject);\n" \
	"\treturn *this;\n" \
	"}\n\n"

#define UNIT_VIRTUAL_DESTRUCTOR \
	"%1::~%2()\n" \
	"{\n" \
	"\tClearLists();\n" \
	"}\n\n"

#define UNIT_GET_SINGLE_LIST_MEMBERS \
	"%1* %2::get%3() const\n" \
	"{\n" \
	"\tif (!m_lst%4.isEmpty())\n" \
	"\t{\n" \
	"\t\treturn m_lst%5[0];\n" \
	"\t}\n" \
	"\treturn 0;\n" \
	"}\n\n"
#define UNIT_SET_SINGLE_LIST_MEMBERS \
	"void %1::set%2(%3* p%4)\n" \
	"{\n" \
	"\tClearList<%5>(m_lst%6);\n" \
	"\tif (p%7)\n" \
	"\t{\n" \
	"\t\tm_lst%8 += p%9;\n" \
	"\t}\n" \
	"}\n\n"

#define UNIT_IS_METHOD \
	"bool %1::is%2() const\n" \
	"{\n" \
	"\treturn m_b%3;\n" \
	"}\n\n"
#define UNIT_GET_METHOD \
	"%1 %2::get%3() const\n" \
	"{\n" \
	"\treturn m_%4%5;\n" \
	"}\n\n"
#define UNIT_SET_METHOD \
	"void %1::set%2(%3 value)\n" \
	"{\n" \
	"%6" \
	"\tm_%4%5 = value;\n" \
	"}\n\n"
#define UNIT_SET_METHOD_WITH_SIGNAL \
	"void %1::set%2(%3 value)\n" \
	"{\n" \
	"%8" \
	"\tbool bValueChanged = (m_%4%5 != value);\n" \
	"\tm_%4%5 = value;\n" \
	"\tif (isSignalsEnabled() && bValueChanged)\n" \
	"\t{\n" \
	"\t\temit signal%6Changed(value%7);\n" \
	"\t}\n" \
	"}\n\n"
#define UNIT_SLOT_METHOD \
	"void %1::slotChange%2(%3 value)\n" \
	"{\n" \
	"\tset%4(value);\n" \
	"}\n\n"
#define UNIT_GET_METHOD_ID \
	"QString %1::get%2_id() const\n" \
	"{\n" \
	"\treturn getFullItemId().isEmpty() ? \"%3\" : getFullItemId() + \".%3\";\n" \
	"}\n"

#define UNIT_SET_DEFAULTS \
	"void %1::setDefaults(QDomElement* RootElement)\n" \
	"{\n" \
	"\tQ_UNUSED(RootElement);\n\n" \
	"\tQStringList dyn_lists;\n" \
	"\tif (RootElement)\n" \
	"\t\tdyn_lists = RootElement->attribute(\"dyn_lists\").split(\" \");\n\n"
#define UNIT_CALL_SET_METHOD \
	"\tif ( ! RootElement || ! RootElement->firstChildElement(\"%1\").isNull() )\n" \
	"\t\t%2(%3);\n"
#define UNIT_CALL_SET_METHOD_LIST \
	"\tif ( ! RootElement || dyn_lists.contains(\"%1\") )\n" \
	"\t\t%2(%3);\n"
#define UNIT_ONCE_CONDITION \
	"\n" \
	"\tstatic bool first_time = true;\n" \
	"\tif ( first_time )\n" \
	"\t{\n"
#define UNIT_REGISTER_METATYPE \
	"\t\tqRegisterMetaType< %1 >(\"%2\");\n"
#define UNIT_END_ONCE_CONDITION \
	"\t\tfirst_time = false;\n" \
	"\t}\n\n"

#define UNIT_GET_PROPERTY \
	"QVariant %1::getPropertyValue(QString path) const\n" \
	"{\n" \
	"\tQVariant value;\n" \
	"\tQString list_tag;\n" \
	"\tbool bOk = false;\n" \
	"\tQ_UNUSED(path);\n" \
	"\tQ_UNUSED(value);\n" \
	"\tQ_UNUSED(list_tag);\n" \
	"\tQ_UNUSED(bOk);\n\n"
#define UNIT_GET_PROPERTY_ITEM_ID \
	"\tif (path == \"itemId\")\n" \
	"\t\tvalue.setValue(getItemId());\n\n"
#define UNIT_GET_PROPERTY_PATCH_STAMP \
	"\tif (path == \"%1.patch_stamp\")\n" \
	"\t\tvalue.setValue(getFieldPatchedValue(\"%1\"));\n\n"
#define UNIT_GET_PROPERTY_MEMBER \
	"\tif (path == \"%1\")\n" \
	"\t\tvalue.setValue(%3%2());\n\n"
#define UNIT_GET_PROPERTY_ENUM_MEMBER \
	"\tif (path == \"%1\")\n" \
	"\t\tvalue.setValue((qlonglong )%3%2());\n\n"
#define UNIT_GET_PROPERTY_LIST_MEMBER \
	"\tlist_tag = \"%1.\";\n" \
	"\tif (path.startsWith(list_tag) && ! %2.isEmpty() && %2.first())\n" \
	"\t\treturn %2.first()->getPropertyValue(path.mid(list_tag.size()));\n\n"
#define UNIT_GET_PROPERTY_DYN_LIST_MEMBER \
	"\tlist_tag = \"%1[\";\n" \
	"\tif (path.startsWith(list_tag))\n" \
	"\t{\n" \
	"\t\tint idx = path.indexOf(\"].\");\n" \
	"\t\tif (idx == -1) return value;\n" \
	"\t\tQString qsItemId = path.mid(list_tag.size(), idx - list_tag.size());\n" \
	"\t\tint nItemId = qsItemId.toInt(&bOk);\n" \
	"\t\tif ( ! bOk ) return value;\n"
#define UNIT_GET_PROPERTY_DYN_LIST_MEMBER_IMPL \
	"\t\tfor(int i = 0; i < %1.size(); ++i)\n" \
	"\t\t\tif (%1[i] && nItemId == %1[i]->getItemId())\n" \
	"\t\t\t\treturn %1[i]->getPropertyValue(path.mid(idx + 2));\n"
#define UNIT_GET_PROPERTY_DYN_LIST_MEMBER_MAX_ITEM_ID \
	"\t}\n" \
	"\telse if (path.startsWith(\"%1.maxItemId\"))\n" \
	"\t{\n" \
	"\t\tint nMaxId = -1;\n" \
	"\t\tfor(int i = 0; i < %2.size(); ++i)\n" \
	"\t\t\tif (%2[i] && nMaxId < %2[i]->getItemId())\n" \
	"\t\t\t\tnMaxId = %2[i]->getItemId();\n" \
	"\t\tvalue.setValue(nMaxId);\n"
#define UNIT_GET_PROPERTY_DYN_LIST_MEMBER_LIST_ITEM_IDS \
	"\t}\n" \
	"\telse if (path.startsWith(\"%1.listItemIds\"))\n" \
	"\t{\n" \
	"\t\tQList<int > lstIds;\n" \
	"\t\tfor(int i = 0; i < %2.size(); ++i)\n" \
	"\t\t\tif (%2[i]) lstIds += %2[i]->getItemId();\n" \
	"\t\tvalue.setValue(lstIds);\n"

#define UNIT_GET_PROPERTY_DYN_LIST_MEMBER_SF_IMPL \
	"\t\tif (nItemId >= 0 && nItemId < %1.size() && %1[nItemId])\n" \
	"\t\t\treturn %1[nItemId]->getPropertyValue(path.mid(idx + 2));\n"
#define UNIT_GET_PROPERTY_DYN_LIST_MEMBER_END \
	"\t}\n\n"
#define UNIT_RETURN_GET_PROPERTY \
	"\treturn value;\n" \
	"}\n\n"

#define UNIT_SET_PROPERTY \
	"bool %1::setPropertyValue(QString path, QVariant value, bool* pbValueChanged)\n" \
	"{\n" \
	"\tQString list_tag;\n" \
	"\tbool bOk = false;\n" \
	"\tQ_UNUSED(path);\n" \
	"\tQ_UNUSED(value);\n" \
	"\tQ_UNUSED(pbValueChanged);\n" \
	"\tQ_UNUSED(list_tag);\n" \
	"\tQ_UNUSED(bOk);\n\n"
#define UNIT_SET_PROPERTY_PATCH_STAMP \
	"\tif (path == \"%1.patch_stamp\")\n" \
	"\t{\n" \
	"\t\tmarkPatchedField(\"%1\", value.toString());\n" \
	"\t\treturn true;\n" \
	"\t}\n\n"
#define UNIT_SET_PROPERTY_MEMBER \
	"\tif (path == \"%1\")\n" \
	"\t{\n" \
	"\t\tif (pbValueChanged)\n" \
	"\t\t\t*pbValueChanged = (%5%2() != value.value< %3 >());\n" \
	"\t\t%5%4(value.value< %3 >());\n" \
	"\t\treturn true;\n" \
	"\t}\n\n"
#define UNIT_SET_PROPERTY_ENUM_MEMBER \
	"\tif (path == \"%1\")\n" \
	"\t{\n" \
	"\t\tif (pbValueChanged)\n" \
	"\t\t\t*pbValueChanged = (%5%2() != (%3 )value.value< qlonglong >());\n" \
	"\t\t%5%4((%3 )value.value< qlonglong >());\n" \
	"\t\treturn true;\n" \
	"\t}\n\n"
#define UNIT_SET_PROPERTY_LIST_MEMBER \
	"\tlist_tag = \"%1.\";\n" \
	"\tif (path.startsWith(list_tag) && ! %2.isEmpty() && %2.first())\n" \
	"\t\treturn %2.first()->setPropertyValue(path.mid(list_tag.size()), value, pbValueChanged);\n\n"
#define UNIT_SET_PROPERTY_DYN_LIST_MEMBER \
	"\tlist_tag = \"%1[\";\n" \
	"\tif (path.startsWith(list_tag))\n" \
	"\t{\n" \
	"\t\tint idx = path.indexOf(\"].\");\n" \
	"\t\tif (idx == -1) return false;\n" \
	"\t\tQString qsItemId = path.mid(list_tag.size(), idx - list_tag.size());\n" \
	"\t\tint nItemId = qsItemId.toInt(&bOk);\n" \
	"\t\tif ( ! bOk ) return false;\n"
#define UNIT_SET_PROPERTY_DYN_LIST_MEMBER_IMPL \
	"\t\tfor(int i = 0; i < %1.size(); ++i)\n" \
	"\t\t\tif (%1[i] && nItemId == %1[i]->getItemId())\n" \
	"\t\t\t\treturn %1[i]->setPropertyValue(path.mid(idx + 2), value, pbValueChanged);\n"
#define UNIT_SET_PROPERTY_DYN_LIST_MEMBER_SF_IMPL \
	"\t\tif (nItemId >= 0 && nItemId < %1.size() && %1[nItemId])\n" \
	"\t\t\treturn %1[nItemId]->setPropertyValue(path.mid(idx + 2), value, pbValueChanged);\n"
#define UNIT_SET_PROPERTY_DYN_LIST_MEMBER_END \
	"\t}\n\n"
#define UNIT_RETURN_SET_PROPERTY \
	"\treturn false;\n" \
	"}\n\n"

#define UNIT_ADD_LIST_ITEM \
	"int %1::addListItem(QString path)\n" \
	"{\n" \
	"\tint nNewItemId = -1;\n" \
	"\tQString list_tag;\n" \
	"\tbool bOk = false;\n" \
	"\tQ_UNUSED(path);\n" \
	"\tQ_UNUSED(nNewItemId);\n" \
	"\tQ_UNUSED(list_tag);\n" \
	"\tQ_UNUSED(bOk);\n\n"
#define UNIT_ADD_LIST_ITEM_IMPL \
	"\tif (path == \"%1\")\n" \
	"\t{\n" \
	"\t\t%2 += new %3;\n" \
	"\t\tnNewItemId = getMaxItemId<%3>(%2, \"%1\");\n" \
	"\t\t%2.last()->setItemId(nNewItemId);\n" \
	"\t\tsyncMaxItemId(nNewItemId + 1, \"%1\");\n" \
	"\t}\n\n"
#define UNIT_ADD_LIST_ITEM_SF \
	"\tlist_tag = \"%1.\";\n" \
	"\tif (path.startsWith(list_tag) && ! %2.isEmpty() && %2.first())\n" \
	"\t\treturn %2.first()->addListItem(path.mid(list_tag.size()));\n\n"
#define UNIT_ADD_LIST_ITEM_DYN_LIST \
	"\tlist_tag = \"%1[\";\n" \
	"\tif (path.startsWith(list_tag))\n" \
	"\t{\n" \
	"\t\tint idx = path.indexOf(\"].\");\n" \
	"\t\tif (idx == -1) return -1;\n" \
	"\t\tQString qsItemId = path.mid(list_tag.size(), idx - list_tag.size());\n" \
	"\t\tint nItemId = qsItemId.toInt(&bOk);\n" \
	"\t\tif ( ! bOk ) return -1;\n"
#define UNIT_ADD_LIST_ITEM_DYN_LIST_IMPL \
	"\t\tfor(int i = 0; i < %1.size(); ++i)\n" \
	"\t\t\tif (%1[i] && nItemId == %1[i]->getItemId())\n" \
	"\t\t\t\treturn %1[i]->addListItem(path.mid(idx + 2));\n"
#define UNIT_ADD_LIST_ITEM_DYN_LIST_SF_IMPL \
	"\t\tif (nItemId >= 0 && nItemId < %1.size() && %1[nItemId])\n" \
	"\t\t\treturn %1[nItemId]->addListItem(path.mid(idx + 2));\n"
#define UNIT_ADD_LIST_ITEM_DYN_LIST_END \
	"\t}\n\n"
#define UNIT_RETURN_ADD_LIST_ITEM \
	"\treturn nNewItemId;\n" \
	"}\n\n"

#define UNIT_DELETE_LIST_ITEM \
	"bool %1::deleteListItem(QString path)\n" \
	"{\n" \
	"\tQString list_tag;\n" \
	"\tbool bOk = false;\n" \
	"\tQ_UNUSED(path);\n" \
	"\tQ_UNUSED(list_tag);\n" \
	"\tQ_UNUSED(bOk);\n\n"
#define UNIT_DELETE_LIST_ITEM_SF \
	"\tlist_tag = \"%1.\";\n" \
	"\tif (path.startsWith(list_tag) && ! %2.isEmpty() && %2.first())\n" \
	"\t\treturn %2.first()->deleteListItem(path.mid(list_tag.size()));\n\n"
#define UNIT_DELETE_LIST_ITEM_DYN_LIST \
	"\tlist_tag = \"%1[\";\n" \
	"\tif (path.startsWith(list_tag))\n" \
	"\t{\n" \
	"\t\tbool bDel = false;\n" \
	"\t\tint idx = path.indexOf(\"].\");\n" \
	"\t\tif (idx == -1 && (idx = path.indexOf(\"]\")) != -1) bDel = true;\n" \
	"\t\tif (idx == -1) return false;\n" \
	"\t\tQString qsItemId = path.mid(list_tag.size(), idx - list_tag.size());\n" \
	"\t\tint nItemId = qsItemId.toInt(&bOk);\n" \
	"\t\tif ( ! bOk ) return false;\n"
#define UNIT_DELETE_LIST_ITEM_DYN_LIST_IMPL \
	"\t\tfor(int i = 0; i < %1.size(); ++i)\n" \
	"\t\t\tif (%1[i] && nItemId == %1[i]->getItemId())\n" \
	"\t\t\t{\n" \
	"\t\t\t\tif ( ! bDel )\n" \
	"\t\t\t\t\treturn %1[i]->deleteListItem(path.mid(idx + 2));\n" \
	"\t\t\t\tdelete %1.takeAt(i);\n" \
	"\t\t\t\treturn true;\n" \
	"\t\t\t}\n"
#define UNIT_DELETE_LIST_ITEM_DYN_LIST_SF_IMPL \
	"\t\tif (nItemId >= 0 && nItemId < %1.size() && %1[nItemId])\n" \
	"\t\t\treturn %1[nItemId]->deleteListItem(path.mid(idx + 2));\n"
#define UNIT_DELETE_LIST_ITEM_DYN_LIST_END \
	"\t}\n\n"
#define UNIT_RETURN_DELETE_LIST_ITEM \
	"\treturn false;\n" \
	"}\n\n"

#define UNIT_GET_XML \
	"QDomElement %1::getXml(QDomDocument* Document, bool no_save_option) const\n" \
	"{\n" \
	"\tQ_UNUSED(no_save_option);\n" \
	"\tint i = -1;\n" \
	"\tQ_UNUSED(i);\n" \
	"\tint nMaxItemId = -1;\n" \
	"\tQ_UNUSED(nMaxItemId);\n" \
	"\tint nElemIdx = 0;\n" \
	"\tQ_UNUSED(nElemIdx);\n" \
	"\tQDomElement element;\n" \
	"\tQDomText text_element;\n" \
	"\tQDomCDATASection cdata_element;\n" \
	"\tQStringList dyn_lists;\n" \
	"\tQSet<int > setItemIds;\n" \
	"\tQMap<QString , int > mapMaxDynListIds = m_mapMaxDynListIds;\n\n" \
	"\tQDomElement root_element = Document->createElement(" \
	"m_qsExtRootTagName.isEmpty() ? QString(\"%2\") : m_qsExtRootTagName);\n\n"
#define UNIT_MEMBER_TO_DOM_ELEMENT \
	"\tcheckAndInsertExtDocElement(root_element, nElemIdx);\n" \
	"\telement = Document->createElement(\"%1\");\n" \
	"\ttext_element = Document->createTextNode( QString(\"#\").arg(%2()%3) );\n" \
	"\troot_element.appendChild(element);\n" \
	"\telement.appendChild(text_element);\n\n"
#define UNIT_MEMBER_TO_DOM_ELEMENT_LIST \
	"\tfor(i = 0; i < m_lst%1.size(); ++i)\n" \
	"\t{\n" \
	"\t\tcheckAndInsertExtDocElement(root_element, nElemIdx);\n" \
	"\t\telement = Document->createElement(\"%2\");\n" \
	"\t\ttext_element = Document->createTextNode( QString(\"#\").arg(m_lst%3[i]%4) );\n" \
	"\t\troot_element.appendChild(element);\n" \
	"\t\telement.appendChild(text_element);\n" \
	"\t}\n\n"
#define UNIT_PATCH_TO_DOM_ELEMENT_ATTRIBUTE \
	"\tif ( m_mapPatchedFields.contains(element.tagName()) )\n" \
	"\t{\n" \
	"\t\troot_element.setAttribute( element.tagName() + \"_patch\", m_mapPatchedFields.value(element.tagName()) );\n" \
	"\t}\n\n"
#define UNIT_TO_DYN_LISTS_ATTR \
	"\tdyn_lists += \"%1\";\n"
#define UNIT_MAX_ITEM_ID \
	"\tnMaxItemId = getMaxItemId<%1>(%2, \"%3\", mapMaxDynListIds);\n" \
	"\tsetItemIds.clear();\n"
#define UNIT_SET_ITEM_ID \
	"\t\tint nItemId = object->getItemId();\n" \
	"\t\tdo {\n" \
	"\t\t\tnItemId = nItemId == -1 ? nMaxItemId++ : nItemId;\n" \
	"\t\t\tif ( ! setItemIds.contains(nItemId) ) break;\n" \
	"\t\t\tnItemId = -1;\n" \
	"\t\t} while(1);\n" \
	"\t\tsetItemIds.insert(nItemId);\n"
#define UNIT_SET_ITEM_ID_ATTR \
	"\t\telement.setAttribute(\"id\", QString::number(nItemId));\n"
#define UNIT_LIST_MEMBER_TO_DOM_ELEMENT \
	"\tfor(i = 0; i < %1.size() && (%2); ++i)\n" \
	"\t{\n" \
	"\t\tcheckAndInsertExtDocElement(root_element, nElemIdx);\n" \
	"\t\tconst %3* object = %1[i];\n" \
	"\t\tif ( ! object ) continue;\n" \
	"%4" \
	"\t\telement = object->getXml(Document, no_save_option);\n" \
	"%5" \
	"\t\troot_element.appendChild(element);\n" \
	"\t}\n"
#define UNIT_SYNC_MAX_ITEM_ID \
	"\tdyn_lists += QString::number(syncMaxItemId(nMaxItemId, \"%1\", mapMaxDynListIds));\n\n"
#define UNIT_GET_XML_RETURN \
	"\tcheckAndInsertExtDocElement(root_element, nElemIdx);\n\n" \
	"\troot_element.setAttribute(\"dyn_lists\", dyn_lists.join(\" \"));\n\n" \
	"\treturn root_element;\n"

#define UNIT_CONDITION \
	"\tif (%1)\n" \
	"\t{\n" \
	"%2" \
	"\t}\n\n"

#define UNIT_READ_XML \
	"int %1::readXml(QDomElement* RootElement, QString ext_tag_name, bool unite_with_loaded)\n" \
	"{\n" \
	"\tQDomDocument temp_doc;\n" \
	"\tQString tag_name;\n" \
	"\tQString attribute;\n" \
	"\tQDomText text_element;\n" \
	"\tQDomCDATASection cdata_element;\n\n" \
	"\ttag_name = RootElement->tagName();\n" \
	"\tm_qsTagName = tag_name;\n" \
	"\tm_qsExtRootTagName = ext_tag_name;\n" \
	"\tif (!eqName(tag_name, (ext_tag_name.isEmpty() ? QString(\"%2\") : ext_tag_name), true))\n" \
	"\t{\n" \
	"\t\tm_qsErrorMessage = \"Error in class '%3': wrong root element with tag name '\" + tag_name + \"'\";\n" \
	"\t\treturn PRL_ERR_PARSE_VM_CONFIG;\n" \
	"\t}\n\n" \
	"\tbool bSupportDynList = RootElement->hasAttribute(\"dyn_lists\");\n" \
	"\tQStringList dyn_lists = RootElement->attribute(\"dyn_lists\").split(\" \");\n" \
	"\tinitMaxItemIds(dyn_lists);\n" \
	"\tQDomElement element = RootElement->firstChildElement();\n\n"
#define UNIT_READ_XML_MAP_ITEM_ID \
	"\tint nMaxItemId_%1 = getMaxItemId2(element, \"%1\");\n" \
	"\tQMap<int , QString > map%1;\n" \
	"\tif (unite_with_loaded)\n" \
	"\t\tfillItemIdMap<%2>(%3, map%1);\n"
#define UNIT_READ_XML_CLEAR \
	"\tm_qsErrorMessage.clear();\n" \
	"\tm_lstWarningList.clear();\n" \
	"\tClearListsInReadXml(unite_with_loaded, dyn_lists, bSupportDynList);\n" \
	"\tsetDefaults(unite_with_loaded ? RootElement : 0);\n" \
	"\tm_mapPatchedFields.clear();\n\n"

#define UNIT_TAG_MIN_OCCURS_COUNTER \
	"\tint %1_count = %2;\n"
#define UNIT_PATCH_STAMP \
	"\tQString %1_patch_stamp = RootElement->attribute(\"%1_patch\");\n" \
	"\tif (unite_with_loaded && RootElement->firstChildElement(\"%1\").isNull())\n" \
	"\t\t%1_patch_stamp = getFieldPatchedValue(\"%1\");\n"
#define UNIT_READ_XML_LOOP \
	"\tint nElemIdx = 0;\n" \
	"\tm_mapExtDoc.clear();\n" \
	"\tm_doc = QDomDocument();\n" \
	"\twhile(!element.isNull())\n" \
	"\t{\n" \
	"\t\ttag_name = element.tagName();\n\n" \
	"\t\tbool unused_tag = true;\n\n"
#define UNIT_READ_XML_LOOP_INIT \
	"\t\tQDomElement* pElement = 0;\n" \
	"\t\tQ_UNUSED(pElement);\n" \
	"\t\tbool is_set = false;\n" \
	"\t\tQ_UNUSED(is_set);\n\n"
#define UNIT_DOM_ELEMENT_TO_MEMBER \
	"\t\tpElement = 0;\n" \
	"\t\tis_set = false;\n" \
	"\t\tattribute = \"%1\";\n" \
	"\t\tif (RootElement->hasAttribute(attribute))\n" \
	"\t\t{\n" \
	"\t\t\tpElement = RootElement;\n" \
	"\t\t}\n" \
	"\t\telse if (element.hasAttribute(attribute))\n" \
	"\t\t{\n" \
	"\t\t\tpElement = &element;\n" \
	"\t\t}\n\n" \
	"\t\tif (pElement && (%2_count - %3) == 0)\n" \
	"\t\t{\n" \
	"\t\t\ttext_element = temp_doc.createTextNode( pElement->attribute(attribute) );\n" \
	"\t\t\tis_set = true;\n" \
	"\t\t}\n" \
	"\t\telse if (eqName(tag_name, \"%4\"))\n" \
	"\t\t{\n" \
	"\t\t\tis_set = true;\n" \
	"\t\t\ttext_element = element.firstChild().toText();\n" \
	"\t\t}\n\n" \
	"\t\tif (is_set)\n" \
	"\t\t{\n" \
	"\t\t\tunused_tag = false;\n" \
	"\t\t\t%5(%6);\n" \
	"\t\t\t--%7_count;\n" \
	"\t\t}\n\n\n"
#define UNIT_DOM_ELEMENT_TO_MEMBER_LIST \
	"\t\tif (eqName(tag_name, \"%1\"))\n" \
	"\t\t{\n" \
	"\t\t\tunused_tag = false;\n" \
	"\t\t\ttext_element = element.firstChild().toText();\n" \
	"\t\t\tm_lst%2 += %3;\n" \
	"\t\t\t--%4_count;\n" \
	"\t\t}\n"
#define UNIT_MAKE_FULL_ITEM_ID_2 \
	"\t\t\tobject->makeFullItemId(getFullItemId(), \"%1\"%2);\n"
#define UNIT_LIST_DOM_ELEMENT_TO_MEMBER \
	"\t\tif (eqName(tag_name, \"%1\"))\n" \
	"\t\t{\n" \
	"\t\t\tunused_tag = false;\n" \
	"\t\t\tint nItemId = element.attribute(\"id\", \"-1\").toInt();\n" \
	"\t\t\tnItemId = nItemId == -1 ? nMaxItemId_%1++ : nItemId;\n" \
	"\t\t\t%2* object = new %2();\n" \
	"\t\t\tobject->setItemId(nItemId);\n" \
	"%5" \
	"\t\t\tif (unite_with_loaded && map%1.contains(nItemId))\n" \
	"\t\t\t\tobject->fromString(map%1.value(nItemId));\n" \
	"\t\t\tif (object->readXml(&element, tag_name, unite_with_loaded))\n" \
	"\t\t\t{\n" \
	"\t\t\t\tm_qsErrorMessage = object->GetErrorMessage();\n" \
	"\t\t\t\tdelete object;\n" \
	"\t\t\t\treturn PRL_ERR_PARSE_VM_CONFIG;\n" \
	"\t\t\t}\n" \
	"\t\t\t%3 += object;\n" \
	"\t\t\t--%4_count;\n" \
	"\t\t\tm_lstWarningList += object->GetWarningList();\n" \
	"\t\t}\n\n"
#define UNIT_LIST_DOM_ELEMENT_TO_MEMBER_SINGLE_FIXED \
	"\t\tif (eqName(tag_name, \"%1\") && %2_count > 0)\n" \
	"\t\t{\n" \
	"\t\t\tunused_tag = false;\n" \
	"\t\t\t%3* object = %4[%5 - %2_count];\n" \
	"%6" \
	"\t\t\tif (object->readXml(&element, tag_name, unite_with_loaded))\n" \
	"\t\t\t{\n" \
	"\t\t\t\tm_qsErrorMessage = object->GetErrorMessage();\n" \
	"\t\t\t\treturn PRL_ERR_PARSE_VM_CONFIG;\n" \
	"\t\t\t}\n" \
	"\t\t\t--%2_count;\n" \
	"\t\t\tobject->setSectionFakeFlag(false);\n" \
	"\t\t\tm_lstWarningList += object->GetWarningList();\n" \
	"\t\t}\n\n"
#define UNIT_READ_XML_END \
	"\t\tif ( unused_tag )\n" \
	"\t\t\tm_mapExtDoc.insert(nElemIdx, m_doc.importNode(element, true).toElement());\n" \
	"\t\tnElemIdx++;\n" \
	"\t\telement = element.nextSiblingElement();\n" \
	"\t}\n\n"
#define UNIT_CHECK_MIN_OCCURS_ERROR \
	"\tif (%1_count > 0)\n" \
	"\t{\n" \
	"\t\tm_qsErrorMessage = \"Error in class '%2': tag '%3' does not satisfy 'minOccurs = %4' condition\";\n" \
	"\t\treturn PRL_ERR_PARSE_VM_CONFIG;\n" \
	"\t}\n\n"
#define UNIT_CHECK_MIN_OCCURS_WARNING \
	"\tif (%1_count >= 0)\n" \
	"\t{\n" \
	"\t\tm_lstWarningList += \"Warning in class '%2': tag '%3' is absent\";\n" \
	"\t}\n\n"
#define UNIT_SYNC_MAX_ITEM_ID_2 \
	"\tsyncMaxItemId(nMaxItemId_%1, \"%1\");\n"
#define UNIT_PATCH_MEMBER \
	"%1\n" \
	"\tm_mapPatchedFields.insert(\"%2\", %3_patch_stamp);\n\n"
#define UNIT_READ_XML_RETURN \
	"\treturn 0;\n"

#define UNIT_SYNC_ITEM_IDS \
	"void %1::syncItemIds()\n" \
	"{\n" \
	"\tint i = -1;\n" \
	"\tQ_UNUSED(i);\n" \
	"\tint nMaxItemId = -1;\n" \
	"\tQ_UNUSED(nMaxItemId);\n" \
	"\tQSet<int > setItemIds;\n\n"
#define UNIT_MAX_ITEM_ID_2 \
	"\tnMaxItemId = getMaxItemId<%1>(%2, \"%3\");\n" \
	"\tsetItemIds.clear();\n"
#define UNIT_SET_ITEM_ID_EX \
	UNIT_SET_ITEM_ID \
	"\t\tobject->setItemId(nItemId);\n"
#define UNIT_MAKE_FULL_ITEM_ID \
	"\t\tobject->makeFullItemId(getFullItemId(), \"%1\"%2);\n"
#define UNIT_SYNC_MAX_ITEM_ID_3 \
	"\tsyncMaxItemId(nMaxItemId, \"%1\");\n\n"
#define UNIT_LIST_MEMBER_SYNC_ITEM_IDS \
	"\tfor(i = 0; i < %1.size(); ++i)\n" \
	"\t{\n" \
	"\t\t%2* object = %1[i];\n" \
	"\t\tif ( ! object ) continue;\n" \
	"%3" \
	"\t\tobject->syncItemIds();\n" \
	"\t}\n"

#define UNIT_MERGE \
	"bool %1::merge(%1* pCur, %1* pPrev, MergeOptions nOptions)\n" \
	"{\n" \
	"\tint i = -1;\n" \
	"\tQ_UNUSED(i);\n" \
	"\tQ_UNUSED(pCur);\n" \
	"\tQ_UNUSED(pPrev);\n" \
	"\tQ_UNUSED(nOptions);\n\n" \
	"\tm_qsErrorMessage = \"%2\";\n\n"
#define UNIT_MERGE_RESTRICT \
	"\tif (nOptions & moEnableRestrictSections)\n" \
	"\t{\n" \
	"\t\tif (toString() != pCur->toString() && toString() == pPrev->toString())\n" \
	"\t\t\tfromString(pCur->toString());\n" \
	"\t\telse if (toString() != pCur->toString() && toString() != pPrev->toString() && pCur->toString() != pPrev->toString())\n" \
	"\t\t\treturn false;\n" \
	"\t\treturn true;\n" \
	"\t}\n\n"
#define UNIT_MERGE_FIXED_FIELD \
	"\tif (nOptions & moEnableFixedFields)\n" \
	"\t\t%2(pPrev->%1());\n"
#define UNIT_MERGE_MEMBER_COPY \
	"\tif (%1() != pCur->%1() && %1() == pPrev->%1())\n" \
	"\t\t%2(pCur->%1());\n"
#define UNIT_MERGE_MEMBER_CONFLICT \
	"\telse if (%1() != pCur->%1() && %1() != pPrev->%1() && pCur->%1() != pPrev->%1())\n" \
	"\t{\n" \
	"\t\tm_qsErrorMessage += \".%2\";\n" \
	"\t\treturn false;\n" \
	"\t}\n\n"

#define UNIT_MERGE_MEMBER_LIST_SINGLE_FIXED \
	"\tfor(i = 0; i < %1.size(); i++)\n" \
	"\t{\n" \
	"\t\tif ( %1[i]->merge(pCur->%1[i], pPrev->%1[i], nOptions) ) continue;\n" \
	"\t\tQString qsIdx = (%1.size() > 1 ? (\"[\" + QString::number(i) + \"]\") : QString());\n" \
	"\t\tm_qsErrorMessage += \".\" + qsIdx + %1[i]->GetErrorMessage();\n" \
	"\t\treturn false;\n" \
	"\t}\n\n"
#define UNIT_MERGE_MEMBER_LIST \
	"\tif ( ! mergeList<%1>(%2, pCur->%2, pPrev->%2, \"%3\", nOptions) )\n" \
	"\t\treturn false;\n\n"

#define UNIT_MERGE_RETURN \
	"\treturn true;\n"

#define UNIT_DIFF \
	"void %1::diff(const %1* pOld, QStringList& lstDiffFullItemIds) const\n" \
	"{\n" \
	"\tint i = -1;\n" \
	"\tQ_UNUSED(i);\n" \
	"\tQ_UNUSED(pOld);\n" \
	"\tQ_UNUSED(lstDiffFullItemIds);\n\n"
#define UNIT_DIFF_MEMBER \
	"\tif (%1() != pOld->%1())\n" \
	"\t\tlstDiffFullItemIds += get%2_id();\n\n"
#define UNIT_DIFF_LIST_MEMBER_SF \
	"\tfor(i = 0; i < %1.size(); ++i)\n" \
	"\t\t%1[i]->diff(pOld->%1[i], lstDiffFullItemIds);\n\n"
#define UNIT_DIFF_LIST_MEMBER_DYN \
	"\tdiffList<%1>(%2, pOld->%2, lstDiffFullItemIds);\n\n"

#define UNIT_COPY \
	"void %1::Copy(const %2& rObject)\n" \
	"{\n" \
	"\tif (this == &rObject)\n" \
	"\t\treturn;\n\n" \
	"\tint i = -1;\n" \
	"\tQ_UNUSED(i);\n\n" \
	"\tCopyBase(&rObject);\n\n"
#define UNIT_COPY_MEMBER \
	"\t%1(rObject.%2);\n"
#define UNIT_COPY_LIST_MEMBER \
	"\tClearList<%1 >(%2);\n" \
	"\tfor(i = 0; i < rObject.%2.size(); i++)\n" \
	"\t\t%2 += new %1(rObject.%2[i]);\n\n"
#define UNIT_COPY_CUSTOM_CALL \
	"\tCustomCopy(&rObject);\n\n"

#define UNIT_INIT_LISTS \
	"void %1::InitLists()\n" \
	"{\n"
#define UNIT_CALL_INIT_LIST \
	"\tInitList<%1>(%2, %3);\n"
#define UNIT_CUSTOM_INIT \
	"\tCustomInit();\n"

#define UNIT_CLEAR_LISTS \
	"void %1::ClearLists()\n" \
	"{\n"
#define UNIT_CLEAR_LISTS_IN_READ_XML \
	"void %1::ClearListsInReadXml(bool unite_with_loaded, const QStringList& dyn_lists, bool bSupportDynList)\n" \
	"{\n" \
	"\tQ_UNUSED(unite_with_loaded);\n" \
	"\tQ_UNUSED(dyn_lists);\n" \
	"\tQ_UNUSED(bSupportDynList);\n" \
	"\tQDomElement element;\n" \
	"\tint i = -1;\n" \
	"\tQ_UNUSED(i);\n"
#define UNIT_CHECK_KNOWN_LIST \
	"\tif ( ! unite_with_loaded || ! bSupportDynList || dyn_lists.contains(\"%1\") )\n\t"
#define UNIT_CALL_CLEAR_LIST \
	"\tClearList<%1>(%2);\n"
#define UNIT_CALL_LIST_SET_DEFAULT \
	"\tfor(i = 0; i < %1.size() && ! unite_with_loaded; i++)\n" \
	"\t{\n" \
	"\t\t%1[i]->ClearListsInReadXml();\n" \
	"\t\t%1[i]->setDefaults();\n" \
	"\t\t%1[i]->setSectionFakeFlag(true);\n" \
	"\t}\n"

#define UNIT_CLOSE_BRACE \
	"}\n\n"

// Templates for xs:any
#define UNIT_STORE_NODE_NAME	"m_AnyNodeCopy"
#define UNIT_STORE_NODE_DECL	"\tQDomNode " UNIT_STORE_NODE_NAME ";\n"

#define UNIT_STORE_NODE_CODE	\
	"\t" UNIT_STORE_NODE_NAME " = RootElement->cloneNode(true);\n"

#define UNIT_SAVE_NODE_CODE	\
	"\troot_element.appendChild(" UNIT_STORE_NODE_NAME ");\n" \

#define HEADER_GET_NODE_CODE	\
	"\tQDomNode* getAnyNode() { return &" UNIT_STORE_NODE_NAME "; };\n"

#endif
