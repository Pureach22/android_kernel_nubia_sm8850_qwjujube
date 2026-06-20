__int64 __fastcall sme_soc_set_dual_mac_config(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  _QWORD *v19; // x19
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 command_buffer; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  int v38; // w8
  __int64 v39; // x20

  context = _cds_get_context(52, (__int64)"sme_get_mac_context", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context )
  {
    v19 = context;
    if ( (unsigned int)qdf_mutex_acquire((__int64)(context + 1606)) )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Failed to acquire lock",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "sme_soc_set_dual_mac_config");
      return 1;
    }
    else
    {
      command_buffer = csr_get_command_buffer(v19);
      if ( command_buffer )
      {
        *(_DWORD *)(command_buffer + 16) = 262149;
        *(_DWORD *)(command_buffer + 32) = *(_DWORD *)a1;
        *(_DWORD *)(command_buffer + 36) = *(_DWORD *)(a1 + 4);
        *(_QWORD *)(command_buffer + 40) = *(_QWORD *)(a1 + 8);
        v38 = *(unsigned __int8 *)(a1 + 16);
        v39 = command_buffer;
        *(_DWORD *)(command_buffer + 24) = v38;
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: set_dual_mac_config scan_config: %x fw_mode_config: %x",
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          "sme_soc_set_dual_mac_config");
        LODWORD(v39) = csr_queue_sme_command(v19, v39, 0);
        qdf_mutex_release((__int64)(v19 + 1606));
        return (unsigned int)v39;
      }
      else
      {
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: Get command buffer failed",
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          "sme_soc_set_dual_mac_config");
        qdf_mutex_release((__int64)(v19 + 1606));
        return 29;
      }
    }
  }
  else
  {
    qdf_trace_msg(0x34u, 2u, "%s: mac is null", v11, v12, v13, v14, v15, v16, v17, v18, "sme_soc_set_dual_mac_config");
    return 16;
  }
}
