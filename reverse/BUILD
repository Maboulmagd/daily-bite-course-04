cc_library(
    name = "reverse",
    srcs = ["reverse.cc"],
    hdrs = ["reverse.h"],
)

cc_test(
    name = "reverse_test",
    srcs = ["reverse_test.cc"],
    deps = [
        ":reverse",
        "@catch2//:catch2_main",
    ],
)
