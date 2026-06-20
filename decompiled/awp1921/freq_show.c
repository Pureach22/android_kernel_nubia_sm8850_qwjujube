__int64 __fastcall freq_show(__int64 a1, __int64 a2, __int64 a3, __int64 *a4)
{
  __int64 result; // x0
  __int64 v5; // x9
  __int64 v6; // x22
  int v10; // w0
  char s[8]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v12; // [xsp+10h] [xbp-20h]
  _WORD v13[7]; // [xsp+18h] [xbp-18h] BYREF
  __int64 v14; // [xsp+28h] [xbp-8h]

  result = 0;
  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *a4;
  v6 = mAWP1921;
  v12 = 0;
  memset(v13, 0, sizeof(v13));
  *(_QWORD *)s = 0;
  if ( !v5 )
  {
    printk(&unk_87FC, "freq_show", 488);
    v10 = snprintf(s, 0x1Eu, "%u\n", *(unsigned __int16 *)(v6 + 2092));
    result = simple_read_from_buffer(a2, a3, a4, s, v10);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
