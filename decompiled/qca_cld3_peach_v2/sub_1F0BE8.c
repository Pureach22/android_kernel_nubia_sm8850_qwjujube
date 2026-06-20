__int64 sub_1F0BE8()
{
  void *v0; // x16
  __int64 v1; // x20

  __arm_mte_set_tag((void *)(v1 - 320), v0);
  __arm_mte_set_tag((void *)(v1 - 304), v0);
  return tgt_vdev_mgr_set_neighbour_rx_cmd_send();
}
