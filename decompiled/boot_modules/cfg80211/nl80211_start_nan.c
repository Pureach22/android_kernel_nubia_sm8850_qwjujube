__int64 __fastcall nl80211_start_nan(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x19
  __int64 v3; // x20
  __int64 v4; // x8
  __int64 result; // x0
  __int64 v7; // x8
  __int64 v8; // x9
  __int64 v9; // x8
  int v10; // w8
  __int64 (__fastcall *v11)(__int64, __int64, __int16 *); // x8
  __int16 v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a2[6];
  v2 = a2[7];
  v12 = 0;
  if ( *(_DWORD *)(v2 + 8) != 12 )
    goto LABEL_11;
  v4 = *(_QWORD *)(v2 + 32);
  if ( v4 )
  {
    if ( (*(_QWORD *)(v4 + 168) & 1) == 0 )
      goto LABEL_4;
LABEL_7:
    result = 4294967279LL;
    goto LABEL_12;
  }
  if ( (*(_BYTE *)(v2 + 66) & 1) != 0 )
    goto LABEL_7;
LABEL_4:
  if ( (rfkill_blocked(*(_QWORD *)(v3 + 2472)) & 1) != 0 )
  {
    result = 4294967164LL;
    goto LABEL_12;
  }
  v7 = a2[4];
  v8 = *(_QWORD *)(v7 + 1904);
  if ( !v8 )
    goto LABEL_15;
  v9 = *(_QWORD *)(v7 + 1912);
  LOBYTE(v12) = *(_BYTE *)(v8 + 4);
  if ( v9 )
  {
    v10 = *(_DWORD *)(v9 + 4);
    if ( (v10 & ~*(unsigned __int8 *)(*(_QWORD *)v2 + 1400LL)) != 0 )
    {
LABEL_11:
      result = 4294967201LL;
      goto LABEL_12;
    }
    if ( v10 && (v10 & 1) == 0 )
    {
LABEL_15:
      result = 4294967274LL;
      goto LABEL_12;
    }
    HIBYTE(v12) = v10;
  }
  v11 = *(__int64 (__fastcall **)(__int64, __int64, __int16 *))(*(_QWORD *)v3 + 784LL);
  if ( *((_DWORD *)v11 - 1) != -1251694623 )
    __break(0x8228u);
  result = v11(v3 + 992, v2, &v12);
  if ( !(_DWORD)result )
  {
    *(_BYTE *)(v2 + 66) = 1;
    ++*(_DWORD *)(v3 + 112);
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
