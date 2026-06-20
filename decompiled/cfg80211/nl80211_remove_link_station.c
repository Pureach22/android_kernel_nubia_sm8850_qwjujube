__int64 __fastcall nl80211_remove_link_station(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x19
  __int64 v3; // x9
  __int64 v4; // x8
  __int64 v5; // x9
  __int64 v6; // x1
  __int64 (__fastcall *v7)(__int64, __int64, __int64 *); // x8
  __int64 result; // x0
  __int64 v9; // [xsp+8h] [xbp-18h] BYREF
  __int64 v10; // [xsp+10h] [xbp-10h]
  __int64 v11; // [xsp+18h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a2[6];
  v10 = 0;
  if ( *(_QWORD *)(*(_QWORD *)v2 + 976LL) )
  {
    v3 = a2[4];
    v4 = *(_QWORD *)(v3 + 2512);
    if ( v4 && (v5 = *(_QWORD *)(v3 + 2504)) != 0 )
    {
      v6 = a2[7];
      v9 = v4 + 4;
      LODWORD(v10) = *(unsigned __int8 *)(v5 + 4);
      v7 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *))(*(_QWORD *)v2 + 976LL);
      if ( v7 )
      {
        if ( *((_DWORD *)v7 - 1) != -568064893 )
          __break(0x8228u);
        result = v7(v2 + 992, v6, &v9);
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
