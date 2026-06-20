void __fastcall __noreturn bt_kernel_panic(int a1)
{
  char *v2; // x20
  size_t v3; // x21
  size_t v4; // x0
  unsigned __int64 v5; // x2
  size_t v6; // x0
  unsigned __int64 v7; // x2

  printk(&unk_13584, "bt_kernel_panic");
  if ( inline_copy_from_user((int)&CrashInfo, a1, 0x96u) )
  {
    printk(&unk_126AA, "bt_kernel_panic");
    CrashInfo = 0;
    qword_13B9A = 0;
    v2 = default_crash_reason;
    qword_13BA2 = 0;
    qword_13BAA = 0;
    qword_13BB2 = 0;
    qword_13BBA = 0;
    qword_13BC2 = 0;
    qword_13BCA = 0;
    qword_13BD2 = 0;
    qword_13BDA = 0;
    qword_13BE2 = 0;
    qword_13BEA = 0;
    qword_13BF2 = 0;
    qword_13BFA = 0;
    qword_13C02 = 0;
    qword_13C0A = 0;
    qword_13C12 = 0;
    qword_13C1A = 0;
    *(__int64 *)((char *)&qword_13C1A + 6) = 0;
    v3 = strlen(default_crash_reason);
    v4 = strnlen(default_crash_reason, v3);
    if ( v4 != -1 || v3 == -1 )
      goto LABEL_5;
    do
    {
      v4 = _fortify_panic(2, -1, 0);
LABEL_5:
      if ( v4 == v3 )
        v5 = v3;
      else
        v5 = v4 + 1;
      if ( v5 >= 0x33 )
        _fortify_panic(7, 50, v5);
      sized_strscpy(&CrashInfo, v2);
      v2 = default_crash_reason;
      v3 = strlen(default_crash_reason);
      v6 = strnlen(default_crash_reason, v3);
    }
    while ( v6 == -1 && v3 != -1 );
    if ( v6 == v3 )
      v7 = v3;
    else
      v7 = v6 + 1;
    if ( v7 >= 0x65 )
      _fortify_panic(7, 100, v7);
    sized_strscpy((char *)&qword_13BC2 + 2, v2);
  }
  BYTE1(qword_13BC2) = 0;
  byte_13C27 = 0;
  printk(&unk_126DF, "bt_kernel_panic");
  panic(
    "%s: BT kernel panic Primary reason = %s, Secondary reason = %s\n",
    "bt_kernel_panic",
    (const char *)&CrashInfo,
    (const char *)&qword_13BC2 + 2);
}
