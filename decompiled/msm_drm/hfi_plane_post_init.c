__int64 __fastcall hfi_plane_post_init(
        __int64 a1,
        long double a2,
        long double a3,
        long double a4,
        long double a5,
        long double a6,
        long double a7,
        long double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 v11; // x8
  unsigned int v12; // w10
  unsigned int v13; // w2

  if ( a1
    && *(_QWORD *)a1
    && (v9 = *(_QWORD *)(*(_QWORD *)a1 + 56LL)) != 0
    && (v10 = *(_QWORD *)(v9 + 8)) != 0
    && (v11 = *(_QWORD *)(v10 + 6440)) != 0
    && ((v12 = *(_DWORD *)(a1 + 1928), v13 = v12 - 1, v12 - 1 < 8) || (v13 = v12 - 9, v12 - 9 <= 5)) )
  {
    return hfi_kms_get_plane_indices(
             v11,
             v12 < 9,
             v13,
             *(unsigned __int8 *)(a1 + 2388),
             (_DWORD *)(*(_QWORD *)(a1 + 4272) + 8LL),
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9);
  }
  else
  {
    return 4294967274LL;
  }
}
