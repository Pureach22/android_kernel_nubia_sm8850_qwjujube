__int64 __fastcall nl80211_nan_del_func(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x19
  __int64 v3; // x8
  __int64 v4; // x20
  __int64 result; // x0
  __int64 v6; // x1
  __int64 v7; // x2
  void (__fastcall *v8)(__int64, __int64, __int64); // x8
  _QWORD v9[2]; // [xsp+10h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a2[7];
  if ( *(_DWORD *)(v2 + 8) != 12 )
  {
    result = 4294967201LL;
    goto LABEL_12;
  }
  v3 = *(_QWORD *)(v2 + 32);
  v4 = a2[6];
  if ( v3 )
  {
    if ( (*(_QWORD *)(v3 + 168) & 1) == 0 )
    {
LABEL_4:
      result = 4294967189LL;
      goto LABEL_12;
    }
  }
  else if ( *(_BYTE *)(v2 + 66) != 1 )
  {
    goto LABEL_4;
  }
  v6 = *(_QWORD *)(a2[4] + 704LL);
  if ( v6 )
  {
    v9[0] = 0;
    nla_memcpy(v9, v6, 8);
    v7 = v9[0];
    v8 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)v4 + 808LL);
    if ( *((_DWORD *)v8 - 1) != 242895373 )
      __break(0x8228u);
    v8(v4 + 992, v2, v7);
    result = 0;
  }
  else
  {
    result = 4294967274LL;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
