__int64 __fastcall nl80211_parse_key_new(__int64 a1, __int16 *a2, __int64 a3)
{
  __int16 v5; // t1
  __int64 v6; // x6
  __int64 result; // x0
  __int64 v8; // x8
  __int64 v9; // x10
  __int64 v10; // x9
  _WORD *v11; // x8
  _WORD *v12; // x8
  __int64 v13; // x6
  __int64 v14; // x9
  __int64 v15; // [xsp+8h] [xbp-78h] BYREF
  __int64 v16; // [xsp+10h] [xbp-70h]
  __int64 v17; // [xsp+18h] [xbp-68h]
  __int64 v18; // [xsp+20h] [xbp-60h] BYREF
  _WORD *v19; // [xsp+28h] [xbp-58h]
  __int64 v20; // [xsp+30h] [xbp-50h]
  __int64 v21; // [xsp+38h] [xbp-48h]
  _WORD *v22; // [xsp+40h] [xbp-40h]
  __int64 v23; // [xsp+48h] [xbp-38h]
  __int64 v24; // [xsp+50h] [xbp-30h]
  __int64 v25; // [xsp+58h] [xbp-28h]
  _WORD *v26; // [xsp+60h] [xbp-20h]
  __int64 v27; // [xsp+68h] [xbp-18h]
  __int64 v28; // [xsp+70h] [xbp-10h]
  __int64 v29; // [xsp+78h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *a2;
  v6 = *(_QWORD *)(a1 + 64);
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = nullptr;
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = nullptr;
  v19 = nullptr;
  v20 = 0;
  v18 = 0;
  result = _nla_parse(&v18, 10, a2 + 2, (unsigned __int16)(v5 - 4), &nl80211_key_policy, 0, v6);
  if ( !(_DWORD)result )
  {
    v9 = v23;
    v8 = v24;
    v10 = v28;
    *(_BYTE *)(a3 + 48) = v23 != 0;
    *(_BYTE *)(a3 + 49) = v8 != 0;
    *(_BYTE *)(a3 + 50) = v10 != 0;
    if ( v9 )
      *(_WORD *)(a3 + 51) = 257;
    if ( v8 | v10 )
      *(_BYTE *)(a3 + 52) = 1;
    if ( v20 )
      *(_DWORD *)(a3 + 40) = *(unsigned __int8 *)(v20 + 4);
    v11 = v19;
    if ( v19 )
    {
      *(_QWORD *)a3 = v19 + 2;
      *(_DWORD *)(a3 + 16) = (unsigned __int16)(*v11 - 4);
    }
    v12 = v22;
    if ( v22 )
    {
      *(_QWORD *)(a3 + 8) = v22 + 2;
      *(_DWORD *)(a3 + 20) = (unsigned __int16)(*v12 - 4);
    }
    if ( v21 )
      *(_DWORD *)(a3 + 28) = *(_DWORD *)(v21 + 4);
    if ( v25 )
      *(_DWORD *)(a3 + 44) = *(_DWORD *)(v25 + 4);
    if ( v26 )
    {
      v16 = 0;
      v17 = 0;
      v13 = *(_QWORD *)(a1 + 64);
      v15 = 0;
      result = _nla_parse(&v15, 2, v26 + 2, (unsigned __int16)(*v26 - 4), &nl80211_key_default_policy, 0, v13);
      if ( (_DWORD)result )
        goto LABEL_2;
      v14 = v17;
      *(_BYTE *)(a3 + 51) = v16 != 0;
      *(_BYTE *)(a3 + 52) = v14 != 0;
    }
    result = 0;
    if ( v27 )
      *(_DWORD *)(a3 + 32) = *(unsigned __int8 *)(v27 + 4);
  }
LABEL_2:
  _ReadStatusReg(SP_EL0);
  return result;
}
