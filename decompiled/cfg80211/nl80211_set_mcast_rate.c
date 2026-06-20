__int64 __fastcall nl80211_set_mcast_rate(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x20
  unsigned int v3; // w8
  bool v4; // cc
  int v5; // w8
  bool v6; // zf
  __int64 v7; // x19
  __int64 v8; // x8
  __int64 v9; // x8
  _DWORD *v10; // x8
  __int64 result; // x0
  _QWORD v12[4]; // [xsp+0h] [xbp-20h] BYREF

  v12[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a2[7];
  v3 = *(_DWORD *)(*(_QWORD *)(v2 + 992) + 8LL);
  v4 = v3 > 0xB;
  v5 = (1 << v3) & 0x882;
  v6 = v4 || v5 == 0;
  if ( v6 || (v7 = a2[6], !*(_QWORD *)(*(_QWORD *)v7 + 408LL)) )
  {
    result = 4294967201LL;
  }
  else
  {
    v8 = a2[4];
    memset(v12, 0, 24);
    v9 = *(_QWORD *)(v8 + 856);
    if ( v9 && (nl80211_parse_mcast_rate(v7, v12, *(unsigned int *)(v9 + 4)) & 1) != 0 )
    {
      v10 = *(_DWORD **)(*(_QWORD *)v7 + 408LL);
      if ( v10 )
      {
        if ( *(v10 - 1) != -1331118544 )
          __break(0x8228u);
        result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *))v10)(v7 + 992, v2, v12);
      }
      else
      {
        result = 4294967201LL;
      }
    }
    else
    {
      result = 4294967274LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
