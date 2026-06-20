__int64 __fastcall csr_send_set_ie(
        __int64 result,
        char a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  if ( (unsigned __int8)result == 2 || (unsigned __int8)result == 1 && a2 == 1 )
  {
    qdf_trace_msg(0x34u, 8u, "%s: vdev %d type %d sub_type %d", a4, a5, a6, a7, a8, a9, a10, a11, "csr_send_set_ie", a3);
    result = _qdf_mem_malloc(6u, "csr_send_set_ie", 6383);
    if ( result )
    {
      *(_BYTE *)(result + 4) = a3;
      *(_DWORD *)result = 398454;
      result = umac_send_mb_message_to_mac(result);
      if ( (_DWORD)result )
        return qdf_trace_msg(
                 0x34u,
                 8u,
                 "%s: Failed to send set IE req for vdev_%d",
                 v12,
                 v13,
                 v14,
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 "csr_send_set_ie",
                 a3);
    }
  }
  return result;
}
