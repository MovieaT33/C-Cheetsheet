void original() {}

void alias_func() __attribute__((alias("original")));
