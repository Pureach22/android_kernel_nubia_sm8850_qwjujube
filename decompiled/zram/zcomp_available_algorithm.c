bool __fastcall zcomp_available_algorithm(__int64 a1)
{
  return (unsigned int)crypto_has_alg(a1, 2, 15) == 1;
}
