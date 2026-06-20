__int64 sub_48BEFC()
{
  __int64 v0; // x16
  void *v1; // x28

  __arm_mte_set_tag((void *)(v0 + 1200), v1);
  __arm_mte_set_tag((void *)(v0 + 1216), v1);
  return wma_process_update_membership();
}
