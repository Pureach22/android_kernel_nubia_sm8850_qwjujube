__int64 __fastcall csr_send_chng_mcc_beacon_interval(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x8
  __int64 v12; // x8
  _BYTE *v13; // x8
  int v14; // t1
  _DWORD *v16; // x0
  __int64 v17; // x23
  __int64 v18; // x8
  _DWORD *v19; // x20
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x22
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7

  if ( a2 <= 5 && (v11 = *(_QWORD *)(a1 + 17296), v11 + 96LL * a2) )
  {
    v12 = v11 + 96LL * a2;
    v14 = *(unsigned __int8 *)(v12 + 50);
    v13 = (_BYTE *)(v12 + 50);
    if ( v14 == 1 )
    {
      *v13 = 0;
      v16 = (_DWORD *)_qdf_mem_malloc(0xEu, "csr_send_chng_mcc_beacon_interval", 6115);
      if ( v16 )
      {
        v17 = a1;
        *v16 = 922664;
        v18 = *(_QWORD *)(a1 + 21632);
        v19 = v16;
        wlan_mlme_get_mac_vdev_id(v18, a2, (char *)v16 + 6);
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: CSR Attempting to change BI for Bssid= %02x:%02x:%02x:**:**:%02x",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "csr_send_chng_mcc_beacon_interval",
          *((unsigned __int8 *)v19 + 6),
          *((unsigned __int8 *)v19 + 7),
          *((unsigned __int8 *)v19 + 8),
          *((unsigned __int8 *)v19 + 11));
        *((_BYTE *)v19 + 12) = a2;
        v28 = 96LL * a2;
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: session %d BeaconInterval %d",
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          "csr_send_chng_mcc_beacon_interval",
          a2,
          *(unsigned __int16 *)(*(_QWORD *)(v17 + 17296) + v28 + 48));
        *((_WORD *)v19 + 2) = *(_WORD *)(*(_QWORD *)(v17 + 17296) + v28 + 48);
        return umac_send_mb_message_to_mac(v19);
      }
      else
      {
        return 2;
      }
    }
    else
    {
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: session %d not found",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "csr_send_chng_mcc_beacon_interval",
      a2);
    return 16;
  }
}
