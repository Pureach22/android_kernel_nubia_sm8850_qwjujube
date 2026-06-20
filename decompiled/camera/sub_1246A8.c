__int64 __fastcall sub_1246A8(int a1, int a2, char *a3)
{
  void *v3; // x11
  __int64 v4; // x29

  __arm_mte_set_tag((void *)(v4 - 768), v3);
  __arm_mte_set_tag((void *)(v4 - 752), v3);
  return cam_common_evt_inject_parse_common_params(a1, a2, a3);
}
