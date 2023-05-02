cc_library(
    name = "wordcount",
    srcs = ["wordcount.cc"],
    hdrs = ["wordcount.h"],
)

cc_test(
    name = "wordcount_test",
    srcs = ["wordcount_test.cc"],
    deps = [
        ":wordcount",
        "@catch2//:catch2_main",
    ],
)
