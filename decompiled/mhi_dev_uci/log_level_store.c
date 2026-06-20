__int64 __fastcall log_level_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x20
  unsigned int v6; // w8
  __int64 v7; // x0
  unsigned int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v9 = 0;
  if ( (kstrtouint(a3, 0, &v9) & 0x80000000) != 0 )
  {
    a4 = -22;
  }
  else if ( v5 )
  {
    v6 = v9;
    v7 = *(_QWORD *)(v5 + 352);
    *(_DWORD *)(v5 + 360) = v9;
    if ( v7 && v6 <= 1 )
      ipc_log_string();
  }
  else
  {
    a4 = -5;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
