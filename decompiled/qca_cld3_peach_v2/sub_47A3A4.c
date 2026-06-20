__int64 __fastcall sub_47A3A4(__int64 a1, __int64 a2)
{
  __int64 v2; // x15

  __arm_mte_increment_tag((void *)(v2 + 528), 0xAu);
  return sap_is_peer_mac_allowed(a1, a2);
}
