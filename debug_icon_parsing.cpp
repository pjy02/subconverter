// 调试图标解析逻辑
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 模拟 split 函数
vector<string> split(const string& str, const string& delimiter) {
    vector<string> result;
    size_t start = 0;
    size_t end = str.find(delimiter);
    
    while (end != string::npos) {
        result.push_back(str.substr(start, end - start));
        start = end + delimiter.length();
        end = str.find(delimiter, start);
    }
    result.push_back(str.substr(start));
    return result;
}

int main() {
    // 测试配置字符串
    string testConfig = "延迟最低|https://cdn.jsdelivr.net/gh/GitMetaio/Surfing@rm/Home/icon/UrlTest.svg`url-test`.*`http://www.gstatic.com/generate_204`300`50";
    
    cout << "原始配置: " << testConfig << endl;
    
    // 按 ` 分割
    vector<string> vArray = split(testConfig, "`");
    cout << "分割后数组大小: " << vArray.size() << endl;
    
    for (size_t i = 0; i < vArray.size(); i++) {
        cout << "vArray[" << i << "]: " << vArray[i] << endl;
    }
    
    // 检查第一个元素是否包含 |
    if (vArray[0].find('|') != string::npos) {
        cout << "发现图标分隔符 |" << endl;
        
        vector<string> nameArray = split(vArray[0], "|");
        cout << "名称数组大小: " << nameArray.size() << endl;
        
        for (size_t i = 0; i < nameArray.size(); i++) {
            cout << "nameArray[" << i << "]: " << nameArray[i] << endl;
        }
        
        if (nameArray.size() >= 2) {
            cout << "解析结果:" << endl;
            cout << "Name: " << nameArray[0] << endl;
            cout << "Icon: " << nameArray[1] << endl;
        }
    }
    
    return 0;
}