__int64 __fastcall nl80211_del_station(__int64 a1, _QWORD *a2)
{
  _QWORD *v2; // x11
  __int64 v3; // x9
  __int64 v4; // x10
  int v5; // w9
  _BYTE *v6; // x19
  unsigned int v7; // w8
  __int64 result; // x0
  __int64 v9; // x8
  int v10; // w8
  __int64 v11; // x8
  unsigned __int64 v12; // x8
  __int64 (__fastcall *v13)(_QWORD); // x8

  _ReadStatusReg(SP_EL0);
  v2 = (_QWORD *)a2[4];
  v3 = v2[313];
  v4 = *(_QWORD *)(a2[7] + 992LL);
  if ( v3 )
    v5 = *(unsigned __int8 *)(v3 + 4);
  else
    v5 = -1;
  v6 = (_BYTE *)a2[6];
  v7 = *(_DWORD *)(v4 + 8);
  result = 4294967274LL;
  if ( v7 > 9 || ((1 << v7) & 0x298) == 0 && (v7 != 1 || (v6[1109] & 0x10) == 0) )
    goto LABEL_27;
  if ( !*(_QWORD *)(*(_QWORD *)v6 + 144LL) )
  {
    result = 4294967201LL;
    goto LABEL_27;
  }
  v9 = v2[41];
  if ( v9 )
  {
    v10 = *(unsigned __int8 *)(v9 + 4);
    if ( v10 != 10 && v10 != 12 )
      goto LABEL_27;
    v11 = v2[54];
    if ( v11 )
    {
LABEL_11:
      if ( !*(_WORD *)(v11 + 4) )
        goto LABEL_27;
      v12 = *(unsigned __int16 *)(v4 + 1472);
      if ( *(_WORD *)(v4 + 1472) )
        goto LABEL_21;
      goto LABEL_20;
    }
  }
  else
  {
    v11 = v2[54];
    if ( v11 )
      goto LABEL_11;
  }
  v12 = *(unsigned __int16 *)(v4 + 1472);
  if ( !*(_WORD *)(v4 + 1472) )
  {
LABEL_20:
    if ( v5 != -1 )
      goto LABEL_27;
  }
LABEL_21:
  if ( !(_DWORD)v12 || v5 < 0 || ((v12 >> v5) & 1) != 0 )
  {
    v13 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)v6 + 144LL);
    if ( *((_DWORD *)v13 - 1) != 516895074 )
      __break(0x8228u);
    result = v13(v6 + 992);
  }
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
