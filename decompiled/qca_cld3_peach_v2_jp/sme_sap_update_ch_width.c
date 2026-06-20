__int64 __fastcall sme_sap_update_ch_width(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned __int8 a10,
        int a11,
        int a12,
        unsigned __int8 a13,
        int a14)
{
  _QWORD *context; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  _QWORD *v28; // x19
  __int64 result; // x0
  _DWORD *command_buffer; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  _DWORD *v39; // x22

  context = _cds_get_context(52, (__int64)"sme_get_mac_context", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( context )
  {
    v28 = context;
    result = qdf_mutex_acquire((__int64)(context + 1597));
    if ( !(_DWORD)result )
    {
      command_buffer = (_DWORD *)csr_get_command_buffer(v28);
      if ( command_buffer )
      {
        command_buffer[10] = a12;
        command_buffer[6] = a10;
        command_buffer[4] = 262151;
        command_buffer[8] = a11;
        command_buffer[9] = a10;
        command_buffer[11] = a13;
        command_buffer[12] = a14;
        v39 = command_buffer;
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: vdev %d ch_width: %d reason: %d",
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          "sme_sap_update_ch_width");
        csr_queue_sme_command(v28, v39, 0);
        qdf_mutex_release((__int64)(v28 + 1597));
        return 0;
      }
      else
      {
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: Get command buffer failed",
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          "sme_sap_update_ch_width");
        qdf_mutex_release((__int64)(v28 + 1597));
        return 29;
      }
    }
  }
  else
  {
    qdf_trace_msg(0x34u, 2u, "%s: mac is null", v20, v21, v22, v23, v24, v25, v26, v27, "sme_sap_update_ch_width");
    return 16;
  }
  return result;
}
