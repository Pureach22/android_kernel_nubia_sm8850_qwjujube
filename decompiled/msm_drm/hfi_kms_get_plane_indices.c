__int64 __fastcall hfi_kms_get_plane_indices(
        __int64 a1,
        int a2,
        unsigned int a3,
        int a4,
        _DWORD *a5,
        long double a6,
        long double a7,
        long double a8,
        long double a9,
        long double a10,
        long double a11,
        long double a12,
        double a13)
{
  __int64 v13; // d17
  __int64 v14; // x8
  _DWORD *v15; // x8
  __int64 v16; // x8
  __int64 v17; // x8
  __int64 v19; // x8

  if ( ((a2 ^ 1) & 1) == 0 && (a4 & 1) == 0 )
  {
    v14 = *(_QWORD *)(a1 + 184);
    if ( *(_DWORD *)(v14 + 12) >= a3 )
    {
      if ( a3 < 0x10 )
      {
        v15 = (_DWORD *)(v14 + 4LL * a3 + 16);
LABEL_15:
        *a5 = *v15;
        return 0;
      }
      goto LABEL_21;
    }
LABEL_18:
    *a5 = 0xFFFFFF;
    return 4294967274LL;
  }
  if ( ((a2 ^ 1 | a4 ^ 1) & 1) != 0 )
  {
    if ( (a2 & 1) == 0 && (a4 & 1) == 0 )
    {
      v16 = *(_QWORD *)(a1 + 184);
      if ( *(_DWORD *)(v16 + 148) >= a3 )
      {
        if ( a3 <= 0xF )
        {
          v15 = (_DWORD *)(v16 + 4LL * a3 + 152);
          goto LABEL_15;
        }
        goto LABEL_21;
      }
      goto LABEL_18;
    }
    if ( ((a4 ^ 1 | a2) & 1) != 0 )
      goto LABEL_18;
    v19 = *(_QWORD *)(a1 + 184);
    if ( *(_DWORD *)(v19 + 216) < a3 )
      goto LABEL_18;
    if ( a3 <= 0xF )
    {
      v15 = (_DWORD *)(v19 + 4LL * a3 + 220);
      goto LABEL_15;
    }
  }
  else
  {
    v17 = *(_QWORD *)(a1 + 184);
    if ( *(_DWORD *)(v17 + 80) < a3 )
      goto LABEL_18;
    if ( a3 <= 0xF )
    {
      v15 = (_DWORD *)(v17 + 4LL * a3 + 84);
      goto LABEL_15;
    }
  }
LABEL_21:
  __break(0x5512u);
  return hfi_kms_get_catalog_data(
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           COERCE_DOUBLE(vmls_s64(*(__int64 *)&a13, *(__int64 *)&a11, v13)));
}
