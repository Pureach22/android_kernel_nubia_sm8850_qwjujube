__int64 __fastcall nan_ndp_responder_req_tlv(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int v11; // w22
  int v13; // w28
  int v14; // w26
  int v15; // w25
  unsigned __int16 v16; // w23
  __int64 v17; // x0
  _DWORD *v18; // x24
  size_t v19; // x2
  int *v20; // x22
  int *v21; // x22
  size_t v22; // x2
  int *v23; // x22
  size_t v24; // x2
  int *v25; // x22
  char *v26; // x22
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  char *v35; // x19
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  unsigned int v52; // w19
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 v62; // [xsp+0h] [xbp-40h]
  __int64 v63; // [xsp+10h] [xbp-30h]
  __int64 v64; // [xsp+18h] [xbp-28h]
  __int64 v65; // [xsp+20h] [xbp-20h]
  int v66; // [xsp+28h] [xbp-18h]
  int v67; // [xsp+34h] [xbp-Ch]

  v11 = *(unsigned __int8 *)(*(_QWORD *)a2 + 168LL);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: vdev_id: %d, transaction_id: %d, ndp_rsp %d, ndp_instance_id: %d, ndp_app_info_len: %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "nan_ndp_responder_req_tlv",
    *(unsigned __int8 *)(*(_QWORD *)a2 + 168LL),
    *(unsigned int *)(a2 + 8),
    *(unsigned int *)(a2 + 16),
    *(unsigned int *)(a2 + 12),
    *(_DWORD *)(a2 + 280));
  v13 = *(_DWORD *)(a2 + 20) + 3;
  v14 = *(_DWORD *)(a2 + 280) + 3;
  v15 = *(_DWORD *)(a2 + 540) + 3;
  v66 = *(_DWORD *)(a2 + 580) + 3;
  v67 = *(_DWORD *)(a2 + 648) + 3;
  v65 = v67 & 0xFFFFFFFC;
  v16 = (v13 & 0xFFFC) + (v14 & 0xFFFC) + (v15 & 0xFFFC) + (v66 & 0xFFFC) + (v67 & 0xFFFC) + 72;
  if ( (*(_BYTE *)(a2 + 908) & 1) != 0 || (*(_BYTE *)(a2 + 925) & 1) != 0 || *(_BYTE *)(a2 + 928) == 1 )
    v16 = (v13 & 0xFFFC) + (v14 & 0xFFFC) + (v15 & 0xFFFC) + (v66 & 0xFFFC) + (v67 & 0xFFFC) + 112;
  v17 = wmi_buf_alloc_fl(a1, v16, "nan_ndp_responder_req_tlv", 0x25Eu);
  if ( v17 )
  {
    v63 = v17;
    v64 = a1;
    v18 = *(_DWORD **)(v17 + 224);
    *v18 = 33030192;
    v18[1] = v11;
    v18[2] = *(_DWORD *)(a2 + 8);
    v18[3] = *(_DWORD *)(a2 + 12);
    v18[4] = *(_DWORD *)(a2 + 16);
    v19 = *(unsigned int *)(a2 + 20);
    v18[5] = v19;
    v18[6] = *(_DWORD *)(a2 + 280);
    v18[8] = *(_DWORD *)(a2 + 540);
    v18[7] = *(_DWORD *)(a2 + 576);
    v18[9] = *(_DWORD *)(a2 + 580);
    v18[10] = *(_DWORD *)(a2 + 648);
    v18[11] = *(_DWORD *)(a2 + 932);
    v18[12] = *(_DWORD *)(a2 + 936);
    v18[13] = v13 & 0xFFFC | 0x110000;
    qdf_mem_copy(v18 + 14, (const void *)(a2 + 24), v19);
    v20 = (_DWORD *)((char *)v18 + (v13 & 0xFFFFFFFC) + 56);
    *v20++ = v14 & 0xFFFC | 0x110000;
    qdf_mem_copy(v20, (const void *)(a2 + 284), *(unsigned int *)(a2 + 280));
    v21 = (int *)((char *)v20 + (v14 & 0xFFFFFFFC));
    v22 = (unsigned int)v18[8];
    *v21++ = v15 & 0xFFFC | 0x110000;
    qdf_mem_copy(v21, (const void *)(a2 + 544), v22);
    v23 = (int *)((char *)v21 + (v15 & 0xFFFFFFFC));
    v24 = (unsigned int)v18[9];
    *v23++ = v66 & 0xFFFC | 0x110000;
    qdf_mem_copy(v23, (const void *)(a2 + 584), v24);
    v25 = (int *)((char *)v23 + (v66 & 0xFFFFFFFC));
    *v25 = v67 & 0xFFFC | 0x110000;
    v26 = (char *)(v25 + 1);
    qdf_mem_copy(v26, (const void *)(a2 + 652), (unsigned int)v18[10]);
    if ( (*(_BYTE *)(a2 + 908) & 1) != 0 || (*(_BYTE *)(a2 + 925) & 1) != 0 || *(_BYTE *)(a2 + 928) == 1 )
    {
      v35 = &v26[v65];
      *(_DWORD *)v35 = 49152036;
      *((_DWORD *)v35 + 1) = *(unsigned __int8 *)(a2 + 908);
      qdf_mem_copy(&v26[v65 + 16], (const void *)(a2 + 909), 0x10u);
      *((_DWORD *)v35 + 2) = *(unsigned __int8 *)(a2 + 925);
      *((_DWORD *)v35 + 8) = *(unsigned __int16 *)(a2 + 926);
      *((_DWORD *)v35 + 3) = *(unsigned __int8 *)(a2 + 928);
      *((_DWORD *)v35 + 9) = *(unsigned __int8 *)(a2 + 929);
    }
    LODWORD(v62) = v18[10];
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: ndp_config len: %d ndp_app_info len: %d pmk len: %d pass phrase len: %d service name len: %d",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "nan_ndp_responder_req_tlv",
      *(unsigned int *)(a2 + 20),
      *(unsigned int *)(a2 + 280),
      (unsigned int)v18[8],
      (unsigned int)v18[9],
      v62);
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: ndp_csid_cap %d, ndp_gtk_required %d",
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      "nan_ndp_responder_req_tlv",
      (unsigned int)v18[11],
      (unsigned int)v18[12]);
    wmi_mtrace(0x38003u, v18[1], 0);
    v52 = wmi_unified_cmd_send_fl(
            v64,
            v63,
            v16,
            0x38003u,
            "nan_ndp_responder_req_tlv",
            0x2AEu,
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51);
    if ( v52 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: WMI_NDP_RESPONDER_REQ_CMDID failed, ret: %d",
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        "nan_ndp_responder_req_tlv",
        v52);
      wmi_buf_free();
    }
  }
  else
  {
    return 2;
  }
  return v52;
}
