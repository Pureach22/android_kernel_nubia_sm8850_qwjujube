__int64 __fastcall sub_110E40(__int64 a1, __int64 a2, __int64 a3, __int64 a4, atomic_ullong *a5)
{
  unsigned __int64 v5; // x21

  atomic_fetch_or(a5, v5);
  return sde_kms_display_early_wakeup();
}
