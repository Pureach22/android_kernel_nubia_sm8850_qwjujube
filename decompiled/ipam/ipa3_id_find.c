__int64 __fastcall ipa3_id_find(unsigned int a1)
{
  __int64 v2; // x19

  raw_spin_lock(ipa3_ctx + 34232);
  v2 = idr_find(ipa3_ctx + 34184, a1);
  raw_spin_unlock(ipa3_ctx + 34232);
  return v2;
}
