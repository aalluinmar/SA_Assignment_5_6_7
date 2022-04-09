

#include "JournalExports.h"
#include <string>
#include <vector>
#include "JournalingTypes.h"

class GuidObject;

/// <summary>
/// Function to set the journaling langauge.  This value cannot be changed
/// once we start journaling, and exception will be thrown if this happens
/// </summary>
/// <param name="jnlLang"></param>

class JournalCallParamDataInt : public JournalCallParamData
{
public:


	JournalCallParamDataInt(std::string paramName,
		ParameterMetaType paramType, std::int64_t value);

	void Journal() override;

private:
	JournalCallParamDataInt() = delete;
	JournalCallParamDataInt(const JournalCallParamDataInt&) = delete;
	JournalCallParamDataInt& operator=(const JournalCallParamDataInt&) = delete;
	std::int64_t m_value;
};

class JournalCallParamDataBoolean : public JournalCallParamData
{
public:


	JournalCallParamDataBoolean(std::string paramName,
		ParameterMetaType paramType, bool value);

	void Journal() override;

private:
	JournalCallParamDataBoolean() = delete;
	JournalCallParamDataBoolean(const JournalCallParamDataBoolean&) = delete;
	JournalCallParamDataBoolean& operator=(const JournalCallParamDataBoolean&) = delete;
	bool m_value;
};




extern JOURNALING_API void SetJournalingLangauge(JournalingLanguage jnlLang);
/// <summary>
/// Returns the journal language. If we are recording this is the active language
/// we are journaling in
/// </summary>
/// <returns></returns>
extern JOURNALING_API JournalingLanguage GetJournalingLangauge();

/// <summary>
/// Starts journal file, language is based upon value returned by GetJournalingLangauge
/// </summary>
/// <param name="jnlFile"></param>
extern JOURNALING_API void StartJournaling(std::string jnlFile);

/// <summary>
/// This ends journal file and write outs the file.
/// </summary>
extern JOURNALING_API void EndJournaling();
/// <summary>
/// Are we journaling a journal file.
/// </summary>
/// <returns></returns>
extern JOURNALING_API bool IsJournaling();




