__int64 __fastcall slc_reset_cache_partition(__int64 a1, __int64 *a2, int *a3)
{
  __int64 v3; // x8
  __int64 v4; // x9
  __int64 result; // x0
  __int64 v6; // x9
  int v7; // w10
  __int64 v8; // x0
  __int64 (__fastcall **v9)(__int64, __int64 *, __int64, __int64, __int64); // x9
  __int64 (__fastcall *v10)(__int64, __int64 *, __int64, __int64, __int64); // x8
  const char *v11; // x1
  __int64 v12; // [xsp+8h] [xbp-18h] BYREF
  int v13; // [xsp+10h] [xbp-10h]
  __int64 v14; // [xsp+18h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 152);
  if ( !v3 || (v4 = *(_QWORD *)(v3 + 16)) == 0 || (*(_BYTE *)(v3 + 88) & 2) == 0 )
  {
    result = 4294967274LL;
    goto LABEL_5;
  }
  if ( !*(_DWORD *)v4 )
  {
    v11 = "Invalid Client ID %d\n";
LABEL_15:
    dev_err(a1, v11);
    result = 4294967274LL;
    goto LABEL_5;
  }
  v6 = *(_QWORD *)(v4 + 4);
  if ( !*(_BYTE *)(v6 + 12) )
  {
    v11 = "Client not enabled for configuration %d\n";
    goto LABEL_15;
  }
  if ( !*(_WORD *)(v6 + 2) )
  {
    v11 = "Invalid PART id %d\n";
    goto LABEL_15;
  }
  v7 = *a3;
  v12 = *a2;
  v9 = *(__int64 (__fastcall ***)(__int64, __int64 *, __int64, __int64, __int64))(v3 + 40);
  v8 = *(_QWORD *)(v3 + 48);
  v13 = v7;
  v10 = *v9;
  if ( *((_DWORD *)*v9 - 1) != 1737159351 )
    __break(0x8228u);
  result = v10(v8, &v12, 0x534C434D50414DLL, 2, 12);
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
