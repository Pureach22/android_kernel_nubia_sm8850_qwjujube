__int64 __fastcall twm_enable_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x21
  __int64 v6; // x20
  bool v7; // w9
  bool v8; // w10
  const char *v9; // x4
  int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v11 = 0;
  v6 = *(_QWORD *)(v5 + 2760);
  if ( (unsigned int)kstrtoint(a3, 10, &v11) )
  {
    printk(&unk_274204, "twm_enable_store");
    a4 = -22;
  }
  else
  {
    v7 = v11 != 0;
    v8 = v11 == 0;
    *(_BYTE *)(v5 + 4518) = v11 != 0;
    *(_BYTE *)(v6 + 1221) = v7;
    *(_BYTE *)(v5 + 4540) = v8;
    if ( (_drm_debug & 4) != 0 )
    {
      if ( *(_BYTE *)(v5 + 4518) )
        v9 = "ENABLED";
      else
        v9 = "DISABLED";
      _drm_dev_dbg(0, 0, 0, "TWM: %s\n", v9);
    }
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
