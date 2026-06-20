bool __fastcall _dp_assert_always_internal(char a1)
{
  char v2; // w19
  __int64 v3; // x0

  if ( (a1 & 1) == 0 )
  {
    v2 = a1;
    v3 = printk(
           &unk_9BB309,
           "expr",
           "__dp_assert_always_internal",
           "/proc/self/cwd/vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_internal.h");
    dump_stack(v3);
    a1 = v2;
  }
  return (a1 & 1) == 0;
}
