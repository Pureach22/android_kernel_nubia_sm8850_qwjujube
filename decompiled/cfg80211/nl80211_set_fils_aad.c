__int64 __fastcall nl80211_set_fils_aad(__int64 a1, _QWORD *a2)
{
  _QWORD *v2; // x8
  __int64 v3; // x1
  __int64 v4; // x19
  __int64 v5; // x9
  char *v6; // x10
  __int64 v7; // x8
  char v8; // t1
  _DWORD *v9; // x8
  __int64 result; // x0
  _QWORD v11[2]; // [xsp+10h] [xbp-30h] BYREF
  __int64 v12; // [xsp+20h] [xbp-20h]
  __int64 v13; // [xsp+28h] [xbp-18h]
  __int64 v14; // [xsp+30h] [xbp-10h]
  __int64 v15; // [xsp+38h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = (_QWORD *)a2[4];
  v12 = 0;
  v4 = a2[6];
  v3 = a2[7];
  v5 = v2[6];
  if ( v5 && (v6 = (char *)v2[242]) != nullptr && (v7 = v2[243]) != 0 )
  {
    v11[0] = v5 + 4;
    v8 = *v6;
    v11[1] = v6 + 4;
    v13 = v7 + 4;
    v14 = v7 + 20;
    LOBYTE(v12) = v8 - 4;
    v9 = *(_DWORD **)(*(_QWORD *)v4 + 944LL);
    if ( v9 )
    {
      if ( *(v9 - 1) != 109276629 )
        __break(0x8228u);
      result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *))v9)(v4 + 992, v3, v11);
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
  _ReadStatusReg(SP_EL0);
  return result;
}
