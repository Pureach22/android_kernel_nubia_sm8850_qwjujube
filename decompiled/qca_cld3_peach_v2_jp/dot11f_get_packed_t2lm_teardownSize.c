__int64 __fastcall dot11f_get_packed_t2lm_teardownSize(__int64 a1, __int64 a2, int *a3)
{
  *a3 = 2;
  return get_packed_size_core(a1, a2, a3, IES_t2lm_teardown);
}
