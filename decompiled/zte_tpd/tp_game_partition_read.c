__int64 __fastcall tp_game_partition_read(__int64 a1, __int64 a2, __int64 a3, _QWORD *a4)
{
  __int64 result; // x0
  __int64 v8; // x22
  int v9; // w0
  char s[1024]; // [xsp+8h] [xbp-408h] BYREF
  __int64 v11; // [xsp+408h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  if ( *a4 )
  {
    result = 0;
  }
  else
  {
    v8 = tpd_cdev;
    printk(&unk_3B699, "tp_game_partition_read", tpd_cdev + 65);
    v9 = snprintf(s, 0x400u, "%s\n", (const char *)(v8 + 65));
    result = simple_read_from_buffer(a2, a3, a4, s, v9);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
