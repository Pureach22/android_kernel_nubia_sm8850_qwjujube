__int64 sub_1249D4()
{
  void *v0; // x11
  __int64 v1; // x29

  __arm_mte_set_tag((void *)(v1 - 768), v0);
  __arm_mte_set_tag((void *)(v1 - 752), v0);
  return cam_common_evt_inject_parse_node_evt_params();
}
