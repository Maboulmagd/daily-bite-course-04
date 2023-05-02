cc_library(
    name = "bepositive",
    srcs = ["bepositive.cc"],
    hdrs = ["bepositive.h"],
)

cc_test(
    name = "bepositive_test",
    srcs = ["bepositive_test.cc"],
    deps = [
        ":bepositive",
        "@catch2//:catch2_main",
    ],
)
