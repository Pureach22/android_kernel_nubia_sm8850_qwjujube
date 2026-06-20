__int64 __fastcall sub_2829C(__int64 a1, __int64 a2, __int64 a3, unsigned __int8 a4, atomic_uchar *a5)
{
  atomic_fetch_or_explicit(a5, a4, memory_order_release);
  return syna_tcm_enable_predict_reading(a1, a2);
}
