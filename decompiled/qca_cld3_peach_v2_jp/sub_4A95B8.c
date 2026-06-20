__int64 __fastcall sub_4A95B8(__int64 a1, __int64 a2)
{
  unsigned __int64 v2; // x23
  __int64 v3; // x24
  atomic_ullong *v4; // x25

  atomic_compare_exchange_strong_explicit(v4, (unsigned __int64 *)&v3, v2, memory_order_release, memory_order_relaxed);
  return dp_tx_get_bank_profile(a1, a2);
}
