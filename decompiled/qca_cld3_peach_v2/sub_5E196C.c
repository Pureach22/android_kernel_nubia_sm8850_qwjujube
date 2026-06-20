__int64 __fastcall sub_5E196C(unsigned __int64 *a1)
{
  atomic_load(a1);
  return ipa_update_tx_stats();
}
