__int64 __fastcall icnss_stats_write(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  __int64 v4; // x8
  __int64 v5; // x20
  int v6; // w0
  int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v3 = a3;
  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 32);
  v8 = 0;
  v5 = *(_QWORD *)(v4 + 128);
  v6 = kstrtouint_from_user(a2, a3, 0, &v8);
  if ( v6 )
    v3 = v6;
  else
    memset((void *)(v5 + 2156), 0, 0x240u);
  _ReadStatusReg(SP_EL0);
  return v3;
}
