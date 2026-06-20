__int64 __fastcall target_if_dcs_register_tx_ops(
        _QWORD *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x29
  __int64 v10; // x30

  if ( a1 )
  {
    a1[43] = target_if_dcs_register_event_handler;
    a1[44] = target_if_dcs_unregister_event_handler;
    a1[45] = target_if_dcs_cmd_send;
    a1[46] = target_if_send_dcs_cmd_for_vdev;
    a1[47] = target_if_vdev_level_dcs_is_supported;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: lmac tx ops is NULL!",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "target_if_dcs_register_tx_ops",
      v9,
      v10);
    return 4;
  }
}
