__int64 __fastcall nan_ndp_initiator_req_tlv(__int64 a1, __int64 a2)
{
  int v3; // w28
  int v4; // w22
  int v5; // w25
  int v6; // w23
  __int16 v7; // w8
  unsigned __int16 v8; // w27
  __int64 v10; // x0
  _DWORD *v11; // x24
  size_t v12; // x2
  int *v13; // x22
  size_t v14; // x2
  int *v15; // x22
  size_t v16; // x2
  int *v17; // x22
  size_t v18; // x2
  int *v19; // x22
  char *v20; // x22
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x4
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  unsigned int v62; // w19
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  __int64 v72; // [xsp+0h] [xbp-50h]
  __int64 v73; // [xsp+28h] [xbp-28h]
  __int64 v74; // [xsp+30h] [xbp-20h]
  __int64 v75; // [xsp+38h] [xbp-18h]
  int v76; // [xsp+40h] [xbp-10h]

  v3 = *(_DWORD *)(a2 + 596) + 3;
  v4 = *(_DWORD *)(a2 + 40) + 3;
  v5 = *(_DWORD *)(a2 + 300) + 3;
  v6 = *(_DWORD *)(a2 + 560) + 3;
  v76 = *(_DWORD *)(a2 + 664) + 3;
  if ( *(_BYTE *)(a2 + 924) )
    v7 = 148;
  else
    v7 = 108;
  v8 = (v4 & 0xFFFC) + (v5 & 0xFFFC) + (v6 & 0xFFFC) + (v3 & 0xFFFC) + (v76 & 0xFFFC) + v7;
  v75 = v76 & 0xFFFFFFFC;
  v10 = wmi_buf_alloc_fl(a1, v8, "nan_ndp_initiator_req_tlv", 0x1D9u);
  if ( v10 )
  {
    v74 = a1;
    v11 = *(_DWORD **)(v10 + 224);
    *v11 = 32964664;
    v73 = v10;
    v11[1] = *(unsigned __int8 *)(*(_QWORD *)a2 + 168LL);
    v11[2] = *(_DWORD *)(a2 + 8);
    v11[3] = *(_DWORD *)(a2 + 20);
    v11[4] = *(_DWORD *)(a2 + 28);
    v11[5] = *(unsigned __int16 *)(a2 + 32);
    v12 = *(unsigned int *)(a2 + 40);
    v11[6] = v12;
    v11[7] = *(_DWORD *)(a2 + 300);
    v11[8] = *(_DWORD *)(a2 + 16);
    v11[10] = *(_DWORD *)(a2 + 560);
    v11[9] = *(_DWORD *)(a2 + 24);
    v11[11] = *(_DWORD *)(a2 + 596);
    v11[12] = *(_DWORD *)(a2 + 664);
    v11[13] = *(_DWORD *)(a2 + 944);
    v11[14] = *(_DWORD *)(a2 + 948);
    v11[15] = 5242904;
    v11[16] = *(_DWORD *)(a2 + 12);
    v11[22] = v4 & 0xFFFC | 0x110000;
    qdf_mem_copy(v11 + 23, (const void *)(a2 + 44), v12);
    v13 = (_DWORD *)((char *)v11 + (v4 & 0xFFFFFFFC) + 92);
    v14 = (unsigned int)v11[7];
    *v13++ = v5 & 0xFFFC | 0x110000;
    qdf_mem_copy(v13, (const void *)(a2 + 304), v14);
    v15 = (int *)((char *)v13 + (v5 & 0xFFFFFFFC));
    v16 = (unsigned int)v11[10];
    *v15++ = v6 & 0xFFFC | 0x110000;
    qdf_mem_copy(v15, (const void *)(a2 + 564), v16);
    v17 = (int *)((char *)v15 + (v6 & 0xFFFFFFFC));
    v18 = (unsigned int)v11[11];
    *v17++ = v3 & 0xFFFC | 0x110000;
    qdf_mem_copy(v17, (const void *)(a2 + 600), v18);
    v19 = (int *)((char *)v17 + (v3 & 0xFFFFFFFC));
    *v19 = v76 & 0xFFFC | 0x110000;
    v20 = (char *)(v19 + 1);
    qdf_mem_copy(v20, (const void *)(a2 + 668), (unsigned int)v11[12]);
    v29 = *(unsigned __int8 *)(a2 + 924);
    if ( (_DWORD)v29 == 1 )
    {
      *(_QWORD *)&v20[v75] = 0x102EE0024LL;
      qdf_mem_copy(&v20[v75 + 16], (const void *)(a2 + 925), 0x10u);
      v29 = *(unsigned __int8 *)(a2 + 924);
    }
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: IPv6 addr present: %d, addr: %pI6",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "nan_ndp_initiator_req_tlv",
      v29,
      a2 + 925);
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: vdev_id = %d, transaction_id: %d, service_instance_id: %d, ch: %d, ch_cfg: %d, csid: %d peer mac addr: mac_add"
      "r31to0: 0x%x, mac_addr47to32: 0x%x",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "nan_ndp_initiator_req_tlv",
      (unsigned int)v11[1],
      (unsigned int)v11[2],
      (unsigned int)v11[3],
      (unsigned int)v11[16],
      v11[8],
      v11[9],
      v11[4],
      v11[5]);
    LODWORD(v72) = v11[12];
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: ndp_config len: %d ndp_app_info len: %d pmk len: %d pass phrase len: %d service name len: %d",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "nan_ndp_initiator_req_tlv",
      (unsigned int)v11[6],
      (unsigned int)v11[7],
      (unsigned int)v11[10],
      (unsigned int)v11[11],
      v72);
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: ndp_csid_cap %d, ndp_gtk_required %d",
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      "nan_ndp_initiator_req_tlv",
      (unsigned int)v11[13],
      (unsigned int)v11[14]);
    wmi_mtrace(0x38002u, v11[1], 0);
    v62 = wmi_unified_cmd_send_fl(
            v74,
            v73,
            v8,
            0x38002u,
            "nan_ndp_initiator_req_tlv",
            0x22Fu,
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            v61);
    if ( v62 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: WMI_NDP_INITIATOR_REQ_CMDID failed, ret: %d",
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        "nan_ndp_initiator_req_tlv",
        v62);
      wmi_buf_free();
    }
  }
  else
  {
    return 2;
  }
  return v62;
}
