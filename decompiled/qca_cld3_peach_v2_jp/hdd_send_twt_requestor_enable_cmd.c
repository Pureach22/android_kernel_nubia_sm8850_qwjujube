__int64 __fastcall hdd_send_twt_requestor_enable_cmd(__int64 *a1, unsigned __int8 a2)
{
  unsigned int macid_by_vdev_id; // w0

  macid_by_vdev_id = policy_mgr_mode_get_macid_by_vdev_id(*a1, a2);
  osif_twt_send_requestor_enable_cmd(*a1, macid_by_vdev_id);
  return 0;
}
