__int64 __fastcall extract_mgmt_rx_ml_cu_params_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 *a10,
        _WORD *a11)
{
  __int64 v11; // x8
  unsigned int v12; // w19
  const char *v13; // x2
  unsigned int v14; // w1

  if ( !a10 )
  {
    v13 = "%s:  MGMT RX param_tlvs is NULL";
    v14 = 2;
LABEL_10:
    qdf_trace_msg(0x31u, v14, v13, a1, a2, a3, a4, a5, a6, a7, a8, "extract_mgmt_rx_ml_cu_params_tlv");
    return 4;
  }
  if ( !a11 )
  {
    v13 = "%s: MGMT Rx CU params is NULL";
LABEL_9:
    v14 = 8;
    goto LABEL_10;
  }
  v11 = *a10;
  if ( !*a10 )
  {
    v13 = "%s: mgmt_ml_info TLV is not sent by FW";
    goto LABEL_9;
  }
  *a11 = *(_DWORD *)(v11 + 4);
  a11[1] = *(_WORD *)(v11 + 6);
  a11[2] = *(_DWORD *)(v11 + 8);
  a11[3] = *(_WORD *)(v11 + 10);
  a11[4] = *(_DWORD *)(v11 + 12);
  a11[5] = *(_WORD *)(v11 + 14);
  v12 = *((_DWORD *)a10 + 6);
  if ( v12 < 0x61 )
  {
    qdf_mem_copy(a11 + 6, (const void *)a10[2], v12);
    ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(49, 8, a10[2], v12);
    return 0;
  }
  qdf_trace_msg(
    0x31u,
    2u,
    "%s: Invalid num_bpcc_bufp:%u",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "extract_mgmt_rx_ml_cu_params_tlv",
    v12);
  return 4;
}
