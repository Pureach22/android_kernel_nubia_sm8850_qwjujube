__int64 __fastcall log_level_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x20
  __int64 v6; // x21
  __int64 v7; // x8
  __int64 v8; // x9
  const char *v9; // x3
  unsigned int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 - 24);
  v11 = 0;
  v6 = *(_QWORD *)(*(_QWORD *)(v5 + 16) + 192LL);
  if ( (kstrtouint(a3, 0, &v11) & 0x80000000) != 0 )
  {
    a4 = -22;
  }
  else if ( v6 )
  {
    v7 = v11;
    *(_DWORD *)(v6 + 24) = v11;
    v8 = *(_QWORD *)(*(_QWORD *)(v5 + 16) + 192LL);
    if ( v8 && *(_DWORD *)(v8 + 24) <= 1u )
    {
      if ( (unsigned int)v7 <= 4 )
        v9 = mhi_log_level_str[v7];
      else
        v9 = "Mask all";
      ipc_log_string(*(_QWORD *)(v8 + 32), "[I][%s] IPC log level changed to: %s\n", "log_level_store", v9);
    }
  }
  else
  {
    a4 = -5;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
