__int64 __fastcall sub_683D6C(void *a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x29

  __arm_mte_set_tag((void *)(v3 - 2816), a1);
  return wmi_extract_vdev_tdls_ev_param(a1, a2, a3);
}
