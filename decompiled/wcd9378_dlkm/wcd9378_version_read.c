__int64 __fastcall wcd9378_version_read(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v6; // x8
  const char *v8; // x2
  int v10; // w0
  __int64 result; // x0
  __int64 v12; // [xsp+0h] [xbp-30h] BYREF
  _QWORD v13[5]; // [xsp+8h] [xbp-28h] BYREF

  v13[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 64);
  v12 = a6;
  memset(v13, 0, 32);
  if ( v6 )
  {
    if ( *(_DWORD *)(v6 + 3256) == 1 )
      v8 = "WCD9378_1_0\n";
    else
      v8 = "VER_UNDEFINED\n";
    v10 = scnprintf(v13, 32, v8);
    result = simple_read_from_buffer(a4, a5, &v12, v13, v10);
  }
  else
  {
    printk(&unk_14807, "wcd9378_version_read");
    result = -22;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
