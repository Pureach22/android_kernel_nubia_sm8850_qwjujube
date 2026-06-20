__int64 __fastcall sub_6B507C(__int64 a1, __int64 a2)
{
  unsigned __int64 *v2; // x13

  atomic_load(v2);
  return wlan_mlo_is_csa_allow(a1, a2);
}
