__int64 __fastcall _lim_process_qos_map_configure_frame(__int64 a1, unsigned int *a2, __int64 a3)
{
  unsigned __int8 *v4; // x19
  unsigned int v5; // w21
  unsigned int v7; // w0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7

  v4 = *((unsigned __int8 **)a2 + 2);
  v5 = a2[10];
  v7 = sir_convert_qos_map_configure_frame2_struct(a1, *((_QWORD *)a2 + 3), v5, a3 + 7365);
  if ( v7 )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: QosMapConfigure frame parsing fail %d",
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             "__lim_process_qos_map_configure_frame",
             v7);
  else
    return lim_send_sme_mgmt_frame_ind(a1, *v4 >> 4, v4, v5 + 24, 0, *a2, a2[2], 0);
}
