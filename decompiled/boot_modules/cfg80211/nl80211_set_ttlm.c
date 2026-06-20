__int64 __fastcall nl80211_set_ttlm(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x19
  __int64 v3; // x8
  int v4; // w9
  __int64 v6; // x9
  __int64 v7; // x8
  __int64 v8; // x20
  _DWORD *v10; // x8
  __int64 result; // x0
  _QWORD v12[2]; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v13[3]; // [xsp+18h] [xbp-18h] BYREF

  v13[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a2[7];
  v13[0] = 0;
  v13[1] = 0;
  v12[0] = 0;
  v12[1] = 0;
  v3 = *(_QWORD *)(v2 + 992);
  v4 = *(_DWORD *)(v3 + 8);
  if ( v4 == 8 || v4 == 2 )
  {
    if ( (*(_BYTE *)(v3 + 164) & 1) != 0 )
    {
      v6 = a2[4];
      v7 = *(_QWORD *)(v6 + 2624);
      if ( v7 && *(_QWORD *)(v6 + 2632) )
      {
        v8 = a2[6];
        nla_memcpy(v12, v7, 16);
        nla_memcpy(v13, *(_QWORD *)(a2[4] + 2632LL), 16);
        v10 = *(_DWORD **)(*(_QWORD *)v8 + 992LL);
        if ( v10 )
        {
          if ( *(v10 - 1) != 1376863258 )
            __break(0x8228u);
          result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *))v10)(v8 + 992, v2, v12);
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
    else
    {
      result = 4294967229LL;
    }
  }
  else
  {
    result = 4294967201LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
