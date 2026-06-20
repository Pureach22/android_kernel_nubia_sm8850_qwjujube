__int64 __fastcall nl80211_update_owe_info(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x20
  __int64 v3; // x8
  __int64 v4; // x9
  __int64 v5; // x8
  __int64 v6; // x19
  __int64 v8; // x8
  __int64 v9; // x9
  __int64 (__fastcall *v10)(__int64, __int64, __int64 *); // x8
  __int64 result; // x0
  __int64 v12; // [xsp+0h] [xbp-30h] BYREF
  __int64 v13; // [xsp+8h] [xbp-28h]
  __int64 v14; // [xsp+10h] [xbp-20h]
  __int64 v15; // [xsp+18h] [xbp-18h]
  __int64 v16; // [xsp+20h] [xbp-10h]
  __int64 v17; // [xsp+28h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a2[6];
  if ( *(_QWORD *)(*(_QWORD *)v2 + 896LL) )
  {
    v3 = a2[4];
    v4 = *(_QWORD *)(v3 + 576);
    if ( v4 && (v5 = *(_QWORD *)(v3 + 48)) != 0 )
    {
      v15 = 0;
      v16 = 0;
      v6 = a2[7];
      v13 = 0;
      v14 = 0;
      v12 = 0;
      HIWORD(v12) = *(_WORD *)(v4 + 4);
      nla_memcpy(&v12, v5, 6);
      v8 = a2[4];
      v9 = *(_QWORD *)(v8 + 336);
      if ( v9 )
      {
        v13 = v9 + 4;
        v14 = (unsigned __int16)(**(_WORD **)(v8 + 336) - 4);
      }
      v10 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *))(*(_QWORD *)v2 + 896LL);
      if ( v10 )
      {
        if ( *((_DWORD *)v10 - 1) != 1880879276 )
          __break(0x8228u);
        result = v10(v2 + 992, v6, &v12);
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
    result = 4294967201LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
