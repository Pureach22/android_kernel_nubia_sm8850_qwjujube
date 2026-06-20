__int64 __fastcall duration_show(__int64 a1, __int64 a2, __int64 a3, __int64 *a4, __int64 a5, __int64 a6, __int64 a7)
{
  __int64 result; // x0
  __int64 v8; // x9
  __int64 v9; // x22
  int v13; // w0
  char s[8]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v15; // [xsp+10h] [xbp-20h]
  _WORD v16[7]; // [xsp+18h] [xbp-18h] BYREF
  __int64 v17; // [xsp+28h] [xbp-8h]

  result = 0;
  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *a4;
  v9 = g_aw86320;
  v15 = 0;
  memset(v16, 0, sizeof(v16));
  *(_QWORD *)s = 0;
  if ( !v8 )
  {
    printk(&unk_9E14, "aw86320", 871, "duration_show", *(unsigned int *)(g_aw86320 + 12), a6, a7);
    v13 = snprintf(s, 0x1Eu, "%u\n", *(_DWORD *)(v9 + 12));
    result = simple_read_from_buffer(a2, a3, a4, s, v13);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
