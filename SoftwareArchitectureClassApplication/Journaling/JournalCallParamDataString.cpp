#include "JournalCallParamDataString.h"
#include "JournalingInternal.h"
#include "JournalFile.h"

using namespace Journal;

JournalCallParamDataString::JournalCallParamDataString(std::string paramName,
    ParameterMetaType paramType, std::string value) :
    JournalCallParamData(paramName, paramType,
        JournalCallParamData::ParameterBasicType::STRING), m_value(value)
{

}

void JournalCallParamDataString::Journal()
{
    if (this->m_paramType == JournalCallParamData::ParameterMetaType::INPUT)
    {
        //There is a bug here, all \ in the string need to be replaced with \\
        // i.e. if d:\dir\some.prt  we need to actualy change this to 
        //         d:\\dir\\some.prt
        
        std::string jnlString = "\\" + m_value + "\\";
        GetActiveJournalFile()->WriteToFile(jnlString);
    }
    else if (this->m_paramType == JournalCallParamData::ParameterMetaType::OUTPUT)
    {
        throw std::exception("NIY ");
    }
    else // RETURN
    {
        throw std::exception("NIY");
    }


}

void JournalCallParamDataBoolean::Journal()
{
    if (this->m_paramType == JournalCallParamData::ParameterMetaType::INPUT)
    {
        /*
         * Approach 1 where we explicitly assigned 1 to true and 0 to false
         *
         * string s;
         * if (m_value == 1)
         *   s = "true";
         * else
         *   s = "false"; 
         * 
         * journalContents <<  s << ",";
         */

        // Approach 2 using std::boolalpha which converts 1 to true and 0 to false
           journalContents << std::boolalpha << m_value << ",";
    }
    else if (this->m_paramType == JournalCallParamData::ParameterMetaType::OUTPUT)
    {
        throw new std::exception("NIY ");
    }
    else // RETURN
    {
        throw new std::exception("NIY");
    }
}

void JournalCallParamDataInt::Journal()
{
    if (this->m_paramType == JournalCallParamData::ParameterMetaType::INPUT)
    {

        journalContents << m_value ;
    }
    else if (this->m_paramType == JournalCallParamData::ParameterMetaType::OUTPUT)
    {
        throw new std::exception("NIY ");
    }
    else // RETURN
    {
        throw new std::exception("NIY");
    }
}
