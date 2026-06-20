__int64 __fastcall slc_get_cache_partition(__int64 a1, __int64 a2, _DWORD *a3)
{
  __int64 v3; // x9
  __int64 v4; // x10
  __int64 result; // x0
  __int64 v6; // x10
  __int64 v8; // x0
  __int64 v9; // x8
  _DWORD *v10; // x8
  const char *v11; // x1
  _QWORD v12[9]; // [xsp+8h] [xbp-48h] BYREF

  v12[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 152);
  if ( !v3 )
    goto LABEL_4;
  v4 = *(_QWORD *)(v3 + 16);
  if ( !v4 || (*(_BYTE *)(v3 + 88) & 2) == 0 )
    goto LABEL_4;
  if ( *(_DWORD *)v4 <= (unsigned int)*(unsigned __int16 *)(a2 + 6) )
  {
    v11 = "Invalid Client ID %d\n";
LABEL_16:
    dev_err(a1, v11);
LABEL_4:
    result = 4294967274LL;
    goto LABEL_5;
  }
  v6 = *(_QWORD *)(v4 + 4) + 21LL * *(unsigned __int16 *)(a2 + 6);
  if ( !*(_BYTE *)(v6 + 12) )
  {
    v11 = "Client not enabled for configuration %d\n";
    goto LABEL_16;
  }
  if ( *(unsigned __int16 *)(a2 + 4) >= (unsigned int)*(unsigned __int16 *)(v6 + 2) )
  {
    v11 = "Invalid PART id %d\n";
    goto LABEL_16;
  }
  v9 = *(_QWORD *)(v3 + 40);
  v8 = *(_QWORD *)(v3 + 48);
  v12[0] = *(_QWORD *)a2;
  memset(&v12[1], 0, 56);
  v10 = *(_DWORD **)(v9 + 8);
  if ( *(v10 - 1) != 1134762728 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, _QWORD *, __int64, __int64, __int64, __int64))v10)(
             v8,
             v12,
             0x534C434D50414DLL,
             3,
             8,
             4);
  if ( !(_DWORD)result )
    *a3 = v12[0];
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
