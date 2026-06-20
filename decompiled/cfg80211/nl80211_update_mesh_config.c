__int64 __fastcall nl80211_update_mesh_config(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x20
  __int64 v4; // x21
  int v5; // w8
  __int64 result; // x0
  __int64 v7; // x2
  _DWORD *v8; // x8
  unsigned int v9; // [xsp+Ch] [xbp-64h] BYREF
  _QWORD v10[12]; // [xsp+10h] [xbp-60h] BYREF

  v10[11] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a2 + 48);
  v2 = *(_QWORD *)(a2 + 56);
  v4 = *(_QWORD *)(v2 + 992);
  v5 = *(_DWORD *)(v4 + 8);
  memset(v10, 0, 88);
  if ( v5 == 7 && *(_QWORD *)(*(_QWORD *)v3 + 240LL) )
  {
    v9 = 0;
    result = nl80211_parse_mesh_config(a2, v10, &v9);
    if ( !(_DWORD)result )
    {
      if ( *(_BYTE *)(v4 + 384) )
      {
        v7 = v9;
        v8 = *(_DWORD **)(*(_QWORD *)v3 + 240LL);
        if ( *(v8 - 1) != 2050856026 )
          __break(0x8228u);
        result = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD *))v8)(v3 + 992, v2, v7, v10);
      }
      else
      {
        result = 4294967229LL;
      }
    }
  }
  else
  {
    result = 4294967201LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
