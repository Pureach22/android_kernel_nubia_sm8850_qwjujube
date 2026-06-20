__int64 __fastcall sme_nss_update_request(
        unsigned int a1,
        unsigned __int8 a2,
        unsigned __int8 a3,
        __int64 a4,
        char a5,
        __int64 a6,
        int a7,
        unsigned int a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16,
        int a17)
{
  _QWORD *context; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  _QWORD *v34; // x19
  __int64 result; // x0
  __int64 command_buffer; // x0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x23

  context = _cds_get_context(52, (__int64)"sme_get_mac_context", a9, a10, a11, a12, a13, a14, a15, a16);
  if ( context )
  {
    v34 = context;
    result = qdf_mutex_acquire((__int64)(context + 1606));
    if ( !(_DWORD)result )
    {
      command_buffer = csr_get_command_buffer(v34);
      if ( command_buffer )
      {
        *(_DWORD *)(command_buffer + 24) = a1;
        *(_DWORD *)(command_buffer + 16) = 262148;
        *(_DWORD *)(command_buffer + 32) = a2;
        *(_DWORD *)(command_buffer + 36) = a3;
        *(_DWORD *)(command_buffer + 40) = a1;
        *(_QWORD *)(command_buffer + 48) = a4;
        *(_QWORD *)(command_buffer + 56) = a6;
        *(_BYTE *)(command_buffer + 64) = a5;
        v45 = command_buffer;
        *(_DWORD *)(command_buffer + 68) = a7;
        *(_DWORD *)(command_buffer + 72) = a8;
        *(_DWORD *)(command_buffer + 76) = a17;
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: Queuing e_sme_command_nss_update to CSR:vdev (%d %d) ss %d r %d req id %x",
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          "sme_nss_update_request",
          a1,
          a8,
          a17);
        csr_queue_sme_command(v34, v45, 0);
        qdf_mutex_release((__int64)(v34 + 1606));
        return 0;
      }
      else
      {
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: Get command buffer failed",
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          "sme_nss_update_request");
        qdf_mutex_release((__int64)(v34 + 1606));
        return 29;
      }
    }
  }
  else
  {
    qdf_trace_msg(0x34u, 2u, "%s: mac is null", v26, v27, v28, v29, v30, v31, v32, v33, "sme_nss_update_request");
    return 16;
  }
  return result;
}
