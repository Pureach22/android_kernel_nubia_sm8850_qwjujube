__int64 __fastcall hdd_send_twt_responder_disable_cmd(__int64 *a1, unsigned int a2, unsigned __int8 a3)
{
  unsigned int macid_by_vdev_id; // w0

  macid_by_vdev_id = policy_mgr_mode_get_macid_by_vdev_id(*a1, a3);
  osif_twt_send_responder_disable_cmd(*a1, macid_by_vdev_id, a2);
  return 0;
}
