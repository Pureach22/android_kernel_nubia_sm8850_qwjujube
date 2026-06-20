__int64 __fastcall sub_73D778(void *a1, int a2, int a3)
{
  __int64 v3; // x29

  __arm_mte_set_tag((void *)(v3 - 2816), a1);
  return extract_vdev_tdls_ev_param_tlv((int)a1, a2, a3);
}
