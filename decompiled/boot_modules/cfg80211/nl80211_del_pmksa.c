__int64 __fastcall nl80211_del_pmksa(__int64 a1, _QWORD *a2)
{
  _QWORD *v2; // x9
  __int64 v3; // x1
  _BYTE *v4; // x19
  __int64 result; // x0
  int v6; // w9
  __int64 (__fastcall *v7)(_QWORD); // x8

  _ReadStatusReg(SP_EL0);
  v2 = (_QWORD *)a2[4];
  v4 = (_BYTE *)a2[6];
  v3 = a2[7];
  if ( !v2[6] && (!v2[52] || (!v2[253] || !v2[254]) && (v4[1108] & 0x40) == 0 && (v4[1112] & 2) == 0) )
  {
    result = 4294967274LL;
    goto LABEL_19;
  }
  result = 4294967201LL;
  v6 = *(_DWORD *)(*(_QWORD *)(v3 + 992) + 8LL);
  if ( v6 > 7 )
  {
    if ( v6 != 8 )
    {
      if ( v6 != 9 )
        goto LABEL_19;
      goto LABEL_14;
    }
  }
  else if ( v6 != 2 )
  {
    if ( v6 != 3 )
      goto LABEL_19;
LABEL_14:
    if ( (v4[1108] & 4) == 0 )
      goto LABEL_19;
  }
  if ( *(_QWORD *)(*(_QWORD *)v4 + 488LL) )
  {
    v7 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)v4 + 488LL);
    if ( *((_DWORD *)v7 - 1) != 814151817 )
      __break(0x8228u);
    result = v7(v4 + 992);
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
