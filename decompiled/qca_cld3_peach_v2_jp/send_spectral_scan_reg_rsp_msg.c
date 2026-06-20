__int64 __fastcall send_spectral_scan_reg_rsp_msg(__int64 a1)
{
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x22
  __int64 v12; // x20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 result; // x0
  const char *v22; // x2

  v2 = _alloc_skb(32, 3264, 0, 0xFFFFFFFFLL);
  if ( v2 )
  {
    v11 = *(_QWORD *)(v2 + 224);
    v12 = v2;
    *(_QWORD *)(v11 + 12) = 0x100000000LL;
    *(_QWORD *)(v11 + 4) = 29;
    *(_DWORD *)(v11 + 20) = *(_DWORD *)(a1 + 3492);
    ucfg_spectral_get_version(*(_QWORD *)(a1 + 8), v11 + 24, v11 + 28);
    *(_DWORD *)v11 = 32;
    skb_put(v12, 32);
    qdf_trace_msg(
      0x33u,
      4u,
      "%s: sending App Reg Response to process pid %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "send_spectral_scan_reg_rsp_msg",
      *(unsigned int *)(a1 + 3492));
    result = nl_srv_ucast(v12, *(_DWORD *)(a1 + 3492), 64, 0x1Du, 6u);
    if ( (result & 0x80000000) == 0 )
      return result;
    v22 = "%s: SPECTRAL: failed to send to spectral scan reg response";
  }
  else
  {
    v22 = "%s: Skb allocation failed";
  }
  return qdf_trace_msg(0x33u, 2u, v22, v3, v4, v5, v6, v7, v8, v9, v10, "send_spectral_scan_reg_rsp_msg");
}
