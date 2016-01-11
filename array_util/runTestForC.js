var fs = require('fs');
var testfile = process.argv[2];
var option = process.argv[3];
var child_process = require('child_process');

function printUsage() {
    var usage = [
        'Usage :',
        'node runTestForC.js exampleTest.c ==> runs all tests',
        'node runTestForC.js exampleTest.c -list ==> lists all tests',
        'node runTestForC.js exampleTest.c -stop ==> stops on first failure',
        'node runTestForC.js exampleTest.c -only namePart ==> runs all tests that match the namePart'
    ];
    console.log(usage.join('\t\n'));
}


function readFile(fileName) {
    console.log(fileName)
    try {
        return fs.readFileSync('./'+fileName, 'utf-8');
    } catch (e) {
        throw e.message;
    }
};

function extractTests(fileContent) {
    var tests = fileContent.match(/(\btest_\w+)/g);
    return tests.map(function(test) {
        return test + "\(\);";
    });
};

function printFormattedErr(err) {
    process.stderr.write(err);
}

function printResult(test, allTests, summary) {
    return function(err, stdout, stderr) {
        printTestName(test);
        if (stdout) console.log(stdout);
        if (err || stderr) summary.failed++, printFormattedErr(stderr);
        console.log('--------------');
        runAllTests(allTests, summary);
    }
}

function createFile(test) {
    var sample = ["#include <stdio.h>",
        "#include \"" + testfile + "\"",
        "int main(void) {"
    ];
    return sample.join('\n') + test + 'return 0;}';
}

function printTestName(test) {
    console.log('===>', test.substr(0, test.length - 3));
}

function listTestNames(tests) {
    tests.forEach(printTestName)
}

function printTestCounts(summary) {
    console.log('failed/total :\t', summary.failed + '/' + summary.totalTest);
};

function runAllTests(tests, summary) {
    if (tests.length == 0) {
        printTestCounts(summary);
        return;
    }
    var test = tests.shift();
    var mainFile = createFile(test);
    fs.writeFileSync('test_main.c', mainFile);
    child_process.execSync('gcc test_main.c array_util.c -o arrayUtilTest');
    fs.unlink('./test_main.c');
    child_process.exec('./arrayUtilTest', printResult(test, tests, summary));
};

function main() {
    if (testfile) {
        var fileContent = readFile(testfile);
        var tests = extractTests(fileContent);
        var summary = {
            failed: 0,
            totalTest: tests.length
        }
        console.log("loading tests from " + testfile + "\n--------------");
        if (option)
            listTestNames(tests);
        runAllTests(tests, summary);
    } else
        printUsage();

};
main();