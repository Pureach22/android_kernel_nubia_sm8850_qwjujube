__int64 __fastcall sub_449770(void *a1, __int64 a2)
{
  __int64 v2; // x28

  __arm_mte_set_tag((void *)(v2 + 2208), a1);
  __arm_mte_set_tag((void *)(v2 + 2224), a1);
  return csr_roam_check_for_link_status_change(a1, a2);
}
