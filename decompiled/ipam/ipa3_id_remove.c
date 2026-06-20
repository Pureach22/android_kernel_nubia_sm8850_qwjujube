__int64 __fastcall ipa3_id_remove(unsigned int a1)
{
  raw_spin_lock(ipa3_ctx + 34232);
  idr_remove(ipa3_ctx + 34184, a1);
  return raw_spin_unlock(ipa3_ctx + 34232);
}
