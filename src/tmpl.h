#include <nlohmann/json.hpp>
#include <string>
#include <iostream>
#include <regex>

namespace azure_tts_extension {

using json = nlohmann::json;

class MsttsTemplate {
 public:
  MsttsTemplate() = default;
  ~MsttsTemplate() = default;

  std::string replace(const json& params) const {
    std::string result = templateStr_;
    if (params.contains("prosody")) {
      auto value = params["prosody"].get<std::string>();
      if (!value.empty()) {
        result = templateProsodyStr_;
      }
    }
    replacePlaceholder(result, "lang", params, "xml:lang=\"{lang}\"");
    replacePlaceholder(result, "voice", params, "name=\"{voice}\"");
    replacePlaceholder(result, "style", params, "style=\"{style}\"");
    replacePlaceholder(result, "role", params, "role=\"{role}\"");
    replacePlaceholder(result, "prosody", params, "{prosody}");
    replacePlaceholder(result, "text", params, "{text}");
    return result;
  }

 private:
  std::string templateProsodyStr_ = R"(
    <speak version="1.0" xmlns="http://www.w3.org/2001/10/synthesis" xmlns:mstts="https://www.w3.org/2001/mstts" {lang}>
        <voice {voice}>
            <mstts:express-as {role} {style} >
            <prosody {prosody}>
                {text}
            </prosody>
            </mstts:express-as>
        </voice>
    </speak>
    )";

  std::string templateStr_ = R"(
    <speak version="1.0" xmlns="http://www.w3.org/2001/10/synthesis" xmlns:mstts="https://www.w3.org/2001/mstts" {lang}>
        <voice {voice}>
            <mstts:express-as {role} {style} >
                {text}
            </mstts:express-as>
        </voice>
    </speak>
    )";
  
  void replacePlaceholder(std::string& result, const std::string& placeholder, const json& params, const std::string& templateStr) const {
    std::string value = "";
    if (params.contains(placeholder)) {
      value = params[placeholder].get<std::string>();
    }
    std::string tempStr = templateStr;
    if (value.empty()) {
      result = std::regex_replace(result, std::regex("\\{" + placeholder + "\\}"), "");
    } else {
      tempStr = std::regex_replace(tempStr, std::regex("\\{" + placeholder + "\\}"), value);
      result = std::regex_replace(result, std::regex("\\{" + placeholder + "\\}"), tempStr);
    }
  }
};

}  // namespace azure_tts_extension