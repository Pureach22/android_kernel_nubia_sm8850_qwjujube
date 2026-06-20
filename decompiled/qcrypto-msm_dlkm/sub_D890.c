__int64 __fastcall sub_D890(
        long double a1,
        long double a2,
        long double a3,
        long double a4,
        long double a5,
        long double a6)
{
  return qcrypto_ahash_cra_exit(a1, a2, a3, a4, a5, a6, COERCE_DOUBLE(vshrd_n_u64(*(unsigned __int64 *)&a4, 0x20u)));
}
