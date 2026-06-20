__int64 __fastcall sub_5E4988(unsigned __int64 *a1, __int64 a2, __int64 a3)
{
  atomic_load(a1);
  return ucfg_ipa_update_tx_stats(a1, a2, a3);
}
