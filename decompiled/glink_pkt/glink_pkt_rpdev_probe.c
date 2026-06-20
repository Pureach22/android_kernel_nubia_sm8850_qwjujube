__int64 __fastcall glink_pkt_rpdev_probe(_QWORD *a1)
{
  __int64 v1; // x21

  v1 = a1[17];
  mutex_lock(v1 - 232);
  *(_QWORD *)(v1 - 144) = a1;
  *(_BYTE *)(v1 - 136) = qcom_glink_rx_done_supported(a1[121]) & 1;
  qcom_glink_register_signals_cb(a1[121], glink_pkt_rpdev_sigs);
  mutex_unlock(v1 - 232);
  a1[19] = v1 - 1280;
  complete_all(v1 - 184);
  return 0;
}
