__int64 __fastcall test_fuse_state_show(__int64 a1, __int64 a2, __int64 a3)
{
  const char *v3; // x3

  if ( a1 && a2 && a3 )
  {
    if ( firmware_type == 116 )
    {
      v3 = "test";
      return (int)scnprintf(a3, 4096, "%s", v3);
    }
    if ( firmware_type == 112 )
    {
      v3 = "prod";
      return (int)scnprintf(a3, 4096, "%s", v3);
    }
  }
  else
  {
    printk(&unk_8619, "test_fuse_state_show");
  }
  return -22;
}
