__int64 __fastcall wcd938x_version_read(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v6; // x9
  __int64 v7; // x9
  __int64 result; // x0
  __int64 v9; // [xsp+0h] [xbp-30h] BYREF
  _QWORD v10[5]; // [xsp+8h] [xbp-28h] BYREF

  v10[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 64);
  v9 = a6;
  memset(v10, 0, 32);
  if ( v6 )
  {
    if ( *(_DWORD *)(v6 + 3152) == 1 )
    {
      strcpy((char *)v10, "WCD938X_1_0\n");
      v7 = 12;
    }
    else
    {
      strcpy((char *)v10, "VER_UNDEFINED\n");
      v7 = 14;
    }
    result = simple_read_from_buffer(a4, a5, &v9, v10, v7);
  }
  else
  {
    if ( (unsigned int)__ratelimit(&wcd938x_version_read__rs, "wcd938x_version_read") )
      printk(&unk_132FC, "wcd938x_version_read");
    result = -22;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
