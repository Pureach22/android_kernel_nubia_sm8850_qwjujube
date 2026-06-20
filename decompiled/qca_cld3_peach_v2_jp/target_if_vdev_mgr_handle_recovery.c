__int64 __fastcall target_if_vdev_mgr_handle_recovery(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned __int16 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x29
  __int64 v13; // x30
  unsigned __int8 v14; // w19
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7

  if ( a4 >= 8u )
  {
    __break(1u);
    return target_if_vdev_mgr_mac_addr_rsp_timeout(a1, a2, a3);
  }
  else
  {
    v14 = a2;
    qdf_trace_msg(
      0x68u,
      2u,
      "PSOC_%d VDEV_%d: %s rsp timeout",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      *(unsigned __int8 *)(a1 + 48),
      (unsigned __int8)a2,
      string_from_rsp_bit_strings[a4],
      v12,
      v13);
    if ( (qdf_is_recovering() & 1) != 0 || (qdf_is_fw_down(v16, v17, v18, v19, v20, v21, v22, v23) & 1) != 0 )
      return qdf_trace_msg(
               0x68u,
               8u,
               "PSOC_%d VDEV_%d: Panic not allowed",
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               v23,
               *(unsigned __int8 *)(a1 + 48),
               v14);
    else
      return _qdf_trigger_self_recovery();
  }
}
