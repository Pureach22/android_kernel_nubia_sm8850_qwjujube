__int64 __fastcall sme_set_ese_beacon_request(
        __int64 a1,
        unsigned __int8 a2,
        char *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x21
  __int64 bssid_vdev_id; // x0
  __int64 v26; // x1
  __int64 v27; // x2
  __int64 v28; // x3
  __int64 v29; // x4
  char v30; // v23.b[8]
  char v31; // w9
  unsigned int v32; // w20

  if ( (*(_BYTE *)(a1 + 17948) & 1) != 0 )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: A Beacon Report Req is already in progress",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "sme_set_ese_beacon_request");
    return 1;
  }
  else
  {
    qdf_mem_copy((void *)(a1 + 17848), a3, 0x64u);
    v15 = _qdf_mem_malloc(0x84u, "sme_set_ese_beacon_request", 1678);
    if ( v15 )
    {
      v24 = v15;
      *(_BYTE *)(a1 + 17948) = 1;
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: Sending Beacon Report Req to SME",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "sme_set_ese_beacon_request");
      *(_DWORD *)v24 = 8655917;
      bssid_vdev_id = wlan_mlme_get_bssid_vdev_id(*(_QWORD *)(a1 + 21560), a2, (void *)(v24 + 5));
      *(_BYTE *)(v24 + 33) = -1;
      v31 = *a3;
      *(_DWORD *)(v24 + 128) = 3;
      *(_BYTE *)(v24 + 4) = 0;
      *(_BYTE *)(v24 + 92) = v31;
      if ( !*a3 )
        goto LABEL_13;
      *(_BYTE *)(v24 + 46) = a3[12];
      *(_WORD *)(v24 + 12) = (68719477 * (unsigned __int64)(*((unsigned __int16 *)a3 + 7) << 10)) >> 36;
      *(_DWORD *)(v24 + 96) = *((_DWORD *)a3 + 2);
      if ( (unsigned __int8)*a3 < 2u )
        goto LABEL_13;
      *(_BYTE *)(v24 + 47) = a3[24];
      *(_WORD *)(v24 + 14) = (68719477 * (unsigned __int64)(*((unsigned __int16 *)a3 + 13) << 10)) >> 36;
      *(_DWORD *)(v24 + 100) = *((_DWORD *)a3 + 5);
      if ( (unsigned __int8)*a3 < 3u )
        goto LABEL_13;
      *(_BYTE *)(v24 + 48) = a3[36];
      *(_WORD *)(v24 + 16) = (68719477 * (unsigned __int64)(*((unsigned __int16 *)a3 + 19) << 10)) >> 36;
      *(_DWORD *)(v24 + 104) = *((_DWORD *)a3 + 8);
      if ( (unsigned __int8)*a3 < 4u )
        goto LABEL_13;
      *(_BYTE *)(v24 + 49) = a3[48];
      *(_WORD *)(v24 + 18) = (68719477 * (unsigned __int64)(*((unsigned __int16 *)a3 + 25) << 10)) >> 36;
      *(_DWORD *)(v24 + 108) = *((_DWORD *)a3 + 11);
      if ( (unsigned __int8)*a3 < 5u )
        goto LABEL_13;
      *(_BYTE *)(v24 + 50) = a3[60];
      *(_WORD *)(v24 + 20) = (68719477 * (unsigned __int64)(*((unsigned __int16 *)a3 + 31) << 10)) >> 36;
      *(_DWORD *)(v24 + 112) = *((_DWORD *)a3 + 14);
      if ( (unsigned __int8)*a3 < 6u )
        goto LABEL_13;
      *(_BYTE *)(v24 + 51) = a3[72];
      *(_WORD *)(v24 + 22) = (68719477 * (unsigned __int64)(*((unsigned __int16 *)a3 + 37) << 10)) >> 36;
      *(_DWORD *)(v24 + 116) = *((_DWORD *)a3 + 17);
      if ( (unsigned __int8)*a3 < 7u )
        goto LABEL_13;
      *(_BYTE *)(v24 + 52) = a3[84];
      *(_WORD *)(v24 + 24) = (68719477 * (unsigned __int64)(*((unsigned __int16 *)a3 + 43) << 10)) >> 36;
      *(_DWORD *)(v24 + 120) = *((_DWORD *)a3 + 20);
      if ( (unsigned __int8)*a3 >= 8u
        && (*(_BYTE *)(v24 + 53) = a3[96],
            *(_WORD *)(v24 + 26) = (68719477 * (unsigned __int64)(*((unsigned __int16 *)a3 + 49) << 10)) >> 36,
            *(_DWORD *)(v24 + 124) = *((_DWORD *)a3 + 23),
            (unsigned __int8)*a3 > 8u) )
      {
        __break(0x5512u);
        *(_BYTE *)v24 = v30;
        return sme_get_tsm_stats(bssid_vdev_id, v26, v27, v28, v29);
      }
      else
      {
LABEL_13:
        v32 = sme_rrm_process_beacon_report_req_ind(a1, v24);
        if ( v32 )
          *(_BYTE *)(a1 + 17948) = 0;
        _qdf_mem_free(v24);
        return v32;
      }
    }
    else
    {
      return 2;
    }
  }
}
