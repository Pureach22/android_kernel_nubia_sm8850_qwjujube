__int64 __fastcall extract_ndp_sch_update_tlv(
        __int64 a1,
        __int64 *a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  char v14; // w0
  __int64 v15; // x26
  char v16; // w22
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int v33; // w4
  const char *v34; // x2
  __int64 v36; // x0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  unsigned int v45; // w8
  unsigned int *v46; // x8
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // x0
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  unsigned int v64; // w8
  __int64 v65; // x27
  _BYTE *v66; // x28
  __int64 v67; // x23
  __int64 v68; // x25
  unsigned int v69; // w1
  unsigned int ch_width_from_phy_mode; // w0
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  __int64 v79; // x4
  __int64 v80; // x6
  __int64 v81; // x7
  __int64 v82; // x4
  int v83; // w22

  v14 = wmi_service_enabled(a1, 0xA7u, a4, a5, a6, a7, a8, a9, a10, a11);
  v15 = *a2;
  v16 = v14;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: flags: %d, num_ch: %d, num_ndp_instances: %d",
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    "extract_ndp_sch_update_tlv",
    *(unsigned int *)(*a2 + 16),
    *(unsigned int *)(*a2 + 20),
    *(unsigned int *)(*a2 + 24));
  v33 = *(_DWORD *)(v15 + 20);
  if ( v33 > *((_DWORD *)a2 + 10) || v33 > *((_DWORD *)a2 + 14) )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Channel count %d greater than NDP Ch list TLV len(%d) or NSS list TLV len(%d)",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "extract_ndp_sch_update_tlv");
    return 4;
  }
  if ( (v16 & 1) != 0 && v33 > *((_DWORD *)a2 + 18) )
  {
    v34 = "%s: Channel count %d greater than NDP Ch info(%d)";
LABEL_9:
    qdf_trace_msg(0x31u, 2u, v34, v25, v26, v27, v28, v29, v30, v31, v32, "extract_ndp_sch_update_tlv");
    return 4;
  }
  if ( *(_DWORD *)(v15 + 24) > *((_DWORD *)a2 + 6) )
  {
    v34 = "%s: NDP Instance count %d greater than NDP Instancei TLV len %d";
    goto LABEL_9;
  }
  v36 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
          **(_QWORD **)(a1 + 760),
          *(unsigned int *)(v15 + 4),
          20);
  *(_QWORD *)a3 = v36;
  if ( !v36 )
  {
    qdf_trace_msg(0x31u, 2u, "%s: vdev is null", v37, v38, v39, v40, v41, v42, v43, v44, "extract_ndp_sch_update_tlv");
    return 4;
  }
  *(_DWORD *)(a3 + 16) = *(_DWORD *)(v15 + 16);
  *(_DWORD *)(a3 + 20) = *(_DWORD *)(v15 + 20);
  v45 = *(_DWORD *)(v15 + 24);
  *(_DWORD *)(a3 + 24) = v45;
  *(_WORD *)(a3 + 8) = *(_DWORD *)(v15 + 8);
  *(_BYTE *)(a3 + 10) = *(_WORD *)(v15 + 10);
  *(_BYTE *)(a3 + 11) = *(_BYTE *)(v15 + 11);
  *(_WORD *)(a3 + 12) = *(_DWORD *)(v15 + 12);
  if ( v45 > 0xFF )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: uint32 overflow",
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      "extract_ndp_sch_update_tlv");
    wlan_objmgr_vdev_release_ref(*(_QWORD *)a3, 0x14u, v46, v47, v48, v49, v50, v51, v52, v53, v54);
    return 4;
  }
  v55 = (__int64)qdf_mem_copy((void *)(a3 + 108), (const void *)a2[2], 4 * v45);
  v64 = *(_DWORD *)(a3 + 20);
  if ( v64 < 5 )
  {
    if ( !v64 )
    {
LABEL_25:
      if ( *(_DWORD *)(v15 + 24) )
      {
        v82 = 0;
        v83 = 0;
        do
        {
          qdf_trace_msg(
            0x31u,
            8u,
            "%s: instance_id[%d]: %d",
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            v62,
            v63,
            "extract_ndp_sch_update_tlv",
            v82,
            *(unsigned int *)(a2[2] + 4LL * (unsigned __int8)v83++));
          v82 = (unsigned __int8)v83;
        }
        while ( *(_DWORD *)(v15 + 24) > (unsigned int)(unsigned __int8)v83 );
      }
      return 0;
    }
  }
  else
  {
    v55 = qdf_trace_msg(
            0x31u,
            2u,
            "%s: too many channels",
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            v62,
            v63,
            "extract_ndp_sch_update_tlv");
    *(_DWORD *)(a3 + 20) = 4;
  }
  v65 = 0;
  v66 = (_BYTE *)(a3 + 44);
  v67 = 16;
  v68 = 4;
  while ( v67 != 128 )
  {
    *((_DWORD *)v66 - 3) = *(_DWORD *)(a2[4] + v67 - 12);
    *((_DWORD *)v66 - 1) = *(_DWORD *)(a2[6] + 4 * v65);
    v69 = *(_DWORD *)(a2[4] + v67) & 0x3F;
    *((_DWORD *)v66 - 4) = v69;
    ch_width_from_phy_mode = wmi_get_ch_width_from_phy_mode(a1, v69);
    *((_DWORD *)v66 - 2) = ch_width_from_phy_mode;
    if ( (v16 & 1) != 0 )
    {
      v79 = *((unsigned int *)v66 - 3);
      v80 = *((unsigned int *)v66 - 1);
      v81 = (unsigned __int8)*(_DWORD *)(a2[8] + v68);
      *v66 = *(_DWORD *)(a2[8] + v68);
      v55 = qdf_trace_msg(
              0x31u,
              8u,
              "%s: Freq: %d, ch_mode: %d, nss: %d mac_id: %d",
              v71,
              v72,
              v73,
              v74,
              v75,
              v76,
              v77,
              v78,
              "extract_ndp_sch_update_tlv",
              v79,
              ch_width_from_phy_mode,
              v80,
              v81);
    }
    else
    {
      v55 = qdf_trace_msg(
              0x31u,
              8u,
              "%s: Freq: %d, ch_mode: %d, nss: %d",
              v71,
              v72,
              v73,
              v74,
              v75,
              v76,
              v77,
              v78,
              "extract_ndp_sch_update_tlv",
              *((unsigned int *)v66 - 3),
              ch_width_from_phy_mode,
              *((unsigned int *)v66 - 1));
    }
    ++v65;
    v67 += 28;
    v66 += 20;
    v68 += 8;
    if ( *(_DWORD *)(a3 + 20) <= (unsigned int)v65 )
      goto LABEL_25;
  }
  __break(0x5512u);
  return extract_ndp_host_event_tlv(v55);
}
