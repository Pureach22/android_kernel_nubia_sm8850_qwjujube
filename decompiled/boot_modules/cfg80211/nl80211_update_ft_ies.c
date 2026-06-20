__int64 __fastcall nl80211_update_ft_ies(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x19
  __int64 v3; // x8
  __int64 v4; // x9
  _WORD *v5; // x8
  __int64 v6; // x1
  __int16 v7; // w9
  _DWORD *v8; // x8
  __int64 result; // x0
  _QWORD v10[4]; // [xsp+10h] [xbp-20h] BYREF

  v10[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a2[6];
  if ( *(_QWORD *)(*(_QWORD *)v2 + 696LL) )
  {
    v3 = a2[4];
    v4 = *(_QWORD *)(v3 + 1416);
    if ( v4 && (v5 = *(_WORD **)(v3 + 336)) != nullptr )
    {
      v10[0] = 0;
      v6 = a2[7];
      v7 = *(_WORD *)(v4 + 4);
      v10[1] = v5 + 2;
      LOWORD(v10[0]) = v7;
      v10[2] = (unsigned __int16)(*v5 - 4);
      v8 = *(_DWORD **)(*(_QWORD *)v2 + 696LL);
      if ( *(v8 - 1) != 3465862 )
        __break(0x8228u);
      result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *))v8)(v2 + 992, v6, v10);
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
