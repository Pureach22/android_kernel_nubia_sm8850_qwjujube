__int64 __fastcall firmware_name_show(__int64 a1, __int64 a2, __int64 a3)
{
  const char *v3; // x3

  if ( a1 && a2 && a3 )
  {
    if ( firmware_name )
      v3 = (const char *)firmware_name;
    else
      v3 = "unknown";
    return (int)scnprintf(a3, 4096, "%s\n", v3);
  }
  else
  {
    printk(&unk_8619, "firmware_name_show");
    return -22;
  }
}
