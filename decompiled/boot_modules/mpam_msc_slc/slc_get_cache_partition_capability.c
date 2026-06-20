__int64 __fastcall slc_get_cache_partition_capability(__int64 a1, __int64 *a2, _QWORD *a3)
{
  __int64 v3; // x9
  __int64 v4; // x10
  __int64 result; // x0
  __int64 v6; // x10
  __int64 v7; // x10
  __int64 v9; // x0
  __int64 v10; // x8
  __int64 (__fastcall *v11)(__int64, __int64 *, __int64, __int64, __int64, __int64); // x8
  __int64 v12; // x9
  const char *v13; // x1
  __int64 v14; // [xsp+8h] [xbp-48h] BYREF
  __int64 v15; // [xsp+10h] [xbp-40h]
  __int64 v16; // [xsp+18h] [xbp-38h]
  __int64 v17; // [xsp+20h] [xbp-30h]
  __int64 v18; // [xsp+28h] [xbp-28h]
  __int64 v19; // [xsp+30h] [xbp-20h]
  __int64 v20; // [xsp+38h] [xbp-18h]
  __int64 v21; // [xsp+40h] [xbp-10h]
  __int64 v22; // [xsp+48h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 152);
  if ( !v3 )
    goto LABEL_4;
  v4 = *(_QWORD *)(v3 + 16);
  if ( !v4 || (*(_BYTE *)(v3 + 88) & 2) == 0 )
    goto LABEL_4;
  if ( *(_DWORD *)v4 <= (unsigned int)*((unsigned __int16 *)a2 + 3) )
  {
    v13 = "Invalid Client ID %d\n";
LABEL_16:
    dev_err(a1, v13);
LABEL_4:
    result = 4294967274LL;
    goto LABEL_5;
  }
  v6 = *(_QWORD *)(v4 + 4) + 21LL * *((unsigned __int16 *)a2 + 3);
  if ( !*(_BYTE *)(v6 + 12) )
  {
    v13 = "Client not enabled for configuration %d\n";
    goto LABEL_16;
  }
  if ( *((unsigned __int16 *)a2 + 2) >= (unsigned int)*(unsigned __int16 *)(v6 + 2) )
  {
    v13 = "Invalid PART id %d\n";
    goto LABEL_16;
  }
  v20 = 0;
  v21 = 0;
  v7 = *a2;
  v18 = 0;
  v19 = 0;
  v10 = *(_QWORD *)(v3 + 40);
  v9 = *(_QWORD *)(v3 + 48);
  v16 = 0;
  v17 = 0;
  v14 = v7;
  v15 = 0;
  v11 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64, __int64, __int64, __int64))(v10 + 8);
  if ( *((_DWORD *)v11 - 1) != 1134762728 )
    __break(0x8228u);
  result = v11(v9, &v14, 0x534C434D50414DLL, 2, 8, 16);
  if ( !(_DWORD)result )
  {
    v12 = v15;
    *a3 = v14;
    a3[1] = v12;
  }
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
