__int64 __fastcall sub_4AD0B0(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        double a9,
        double a10,
        double a11,
        double a12,
        long double a13)
{
  __int128 v13; // q19

  *(_OWORD *)(a8 + 960) = v13;
  *(long double *)(a8 + 976) = a13;
  return csr_fill_auth_type(a1, a2, a3, a4, a5, a6, a7, a8 + 960);
}
