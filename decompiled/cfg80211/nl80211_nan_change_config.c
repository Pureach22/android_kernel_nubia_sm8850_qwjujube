__int64 __fastcall nl80211_nan_change_config(__int64 a1, _QWORD *a2)
{
  __int64 v3; // x1
  __int64 v4; // x19
  __int64 v5; // x9
  __int64 result; // x0
  __int64 v7; // x8
  __int64 v8; // x9
  int v9; // w9
  __int64 v10; // x8
  __int64 v11; // x3
  int v12; // w8
  __int64 (__fastcall *v13)(__int64, __int64, __int16 *, __int64); // x8
  __int16 v14; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+18h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a2[7];
  v4 = a2[6];
  v14 = 0;
  if ( *(_DWORD *)(v3 + 8) != 12 )
    goto LABEL_13;
  v5 = *(_QWORD *)(v3 + 32);
  if ( v5 )
  {
    if ( (*(_QWORD *)(v5 + 168) & 1) == 0 )
    {
LABEL_4:
      result = 4294967189LL;
      goto LABEL_14;
    }
  }
  else if ( *(_BYTE *)(v3 + 66) != 1 )
  {
    goto LABEL_4;
  }
  v7 = a2[4];
  v8 = *(_QWORD *)(v7 + 1904);
  if ( v8 )
  {
    v9 = *(unsigned __int8 *)(v8 + 4);
    LOBYTE(v14) = v9;
    if ( (unsigned int)(v9 - 255) < 0xFFFFFF03 )
      goto LABEL_17;
    v10 = *(_QWORD *)(v7 + 1912);
    if ( !v10 )
    {
      v11 = 1;
      goto LABEL_20;
    }
    v11 = 3;
  }
  else
  {
    v10 = *(_QWORD *)(v7 + 1912);
    if ( !v10 )
      goto LABEL_17;
    v11 = 2;
  }
  v12 = *(_DWORD *)(v10 + 4);
  if ( (v12 & ~*(unsigned __int8 *)(*(_QWORD *)v3 + 1400LL)) != 0 )
  {
LABEL_13:
    result = 4294967201LL;
    goto LABEL_14;
  }
  if ( v12 && (v12 & 1) == 0 )
  {
LABEL_17:
    result = 4294967274LL;
    goto LABEL_14;
  }
  HIBYTE(v14) = v12;
LABEL_20:
  v13 = *(__int64 (__fastcall **)(__int64, __int64, __int16 *, __int64))(*(_QWORD *)v4 + 816LL);
  if ( v13 )
  {
    if ( *((_DWORD *)v13 - 1) != -1372393199 )
      __break(0x8228u);
    result = v13(v4 + 992, v3, &v14, v11);
  }
  else
  {
    result = 4294967201LL;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
