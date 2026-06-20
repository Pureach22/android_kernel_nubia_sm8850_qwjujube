__int64 __fastcall csr_set_ht2040_mode(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  char *v16; // x0
  char v17; // w23
  char *v18; // x20
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7

  if ( a2 <= 5 && *(_QWORD *)(a1 + 17296) + 96LL * a2 )
  {
    v16 = (char *)_qdf_mem_malloc(0xEu, "csr_set_ht2040_mode", 6152);
    if ( v16 )
    {
      v17 = a4 & 1;
      v18 = v16;
      qdf_mem_set(v16, 0xEu, 0);
      *(_DWORD *)v18 = 922720;
      wlan_mlme_get_mac_vdev_id(*(_QWORD *)(a1 + 21632), a2, v18 + 6);
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: CSR Attempting to set HT20/40 mode for Bssid= %02x:%02x:%02x:**:**:%02x",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "csr_set_ht2040_mode",
        (unsigned __int8)v18[6],
        (unsigned __int8)v18[7],
        (unsigned __int8)v18[8],
        (unsigned __int8)v18[11]);
      v18[12] = a2;
      qdf_trace_msg(
        0x34u,
        8u,
        "%s:   session %d HT20/40 mode %d",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "csr_set_ht2040_mode",
        a2,
        a3);
      v18[4] = a3;
      v18[5] = v17;
      return umac_send_mb_message_to_mac(v18);
    }
    else
    {
      return 2;
    }
  }
  else
  {
    qdf_trace_msg(0x34u, 2u, "%s: session %d not found", a5, a6, a7, a8, a9, a10, a11, a12, "csr_set_ht2040_mode", a2);
    return 16;
  }
}
