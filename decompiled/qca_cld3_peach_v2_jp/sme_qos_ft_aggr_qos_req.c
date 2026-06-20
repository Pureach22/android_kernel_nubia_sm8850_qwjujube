__int64 __fastcall sme_qos_ft_aggr_qos_req(
        unsigned __int8 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x20
  __int64 v11; // x22
  __int64 result; // x0
  __int64 v13; // x25
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w21
  _BYTE *v23; // x27
  __int64 v24; // x20
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  char v33; // w24
  __int64 v34; // x4
  char v35; // w8
  int v36; // w9
  unsigned int v37; // w9
  __int64 v38; // x10
  __int64 v39; // x12
  __int64 v40; // x13
  __int64 v41; // x8
  __int64 v42; // x11
  __int64 v43; // x26
  unsigned __int16 *v44; // x24
  int v45; // w22
  _QWORD *v46; // x23
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  int v55; // w6
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  char v64; // w24
  __int64 v65; // x4
  char v66; // w8
  int v67; // w9
  unsigned int v68; // w9
  __int64 v69; // x10
  __int64 v70; // x12
  __int64 v71; // x13
  __int64 v72; // x8
  __int64 v73; // x11
  int v74; // w6
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  __int64 v83; // [xsp+8h] [xbp-8h]

  qdf_trace_msg(0x34u, 8u, "%s: invoked on session %d", a2, a3, a4, a5, a6, a7, a8, a9, "sme_qos_ft_aggr_qos_req", a1);
  v10 = qword_856120;
  v11 = _qdf_mem_malloc(0x2A0u, "sme_qos_ft_aggr_qos_req", 3224);
  result = 2;
  if ( v11 )
  {
    v13 = v10 + 3040LL * a1;
    *(_BYTE *)(v11 + 4) = a1;
    *(_DWORD *)v11 = 44045364;
    *(_DWORD *)(v11 + 12) = 0;
    *(_BYTE *)(v11 + 16) = 1;
    qdf_mem_copy((void *)(v11 + 5), (const void *)(*(_QWORD *)(v13 + 2920) + 2LL), 6u);
    v22 = 0;
    v23 = (_BYTE *)(v11 + 182);
    v24 = -2912;
    v83 = v11;
    do
    {
      v43 = v13 + v24;
      v44 = (unsigned __int16 *)(v13 + v24 + 3269);
      v45 = 1 << v22;
      v46 = v23 - 161;
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: ac=%d, tspec_mask_status=%x, tspec_index=%d direction = %d",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "sme_qos_ft_aggr_qos_req",
        v22,
        *(unsigned __int8 *)(v13 + v24 + 3233),
        0,
        (*v44 >> 5) & 3);
      if ( (*(_BYTE *)(v13 + v24 + 3233) & 1) != 0 )
      {
        v55 = (*v44 >> 5) & 3;
        if ( v55 == 3 || !v55 )
        {
          qdf_trace_msg(
            0x34u,
            8u,
            "%s: Found tspec entry AC=%d, flow=%d, direction = %d",
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            "sme_qos_fill_aggr_info",
            v22,
            0);
          v64 = byte_85618C;
          v65 = (unsigned __int8)byte_85618C;
          if ( (((unsigned __int8)byte_85618C + 1) & 0x100) != 0 )
            v66 = 1;
          else
            v66 = byte_85618C + 1;
          byte_85618C = v66;
          qdf_trace_msg(
            0x34u,
            8u,
            "%s: token %d",
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            v62,
            v63,
            "sme_qos_assign_dialog_token",
            v65);
          *(v23 - 162) = v64;
          *v23 = *v23 & 0xF7 | *(_BYTE *)(v13 + v24 + 3438) & 8;
          *(v23 - 103) = *(_BYTE *)(v13 + v24 + 3324);
          qdf_mem_copy(v23 - 102, (const void *)(v13 + v24 + 3325), 2u);
          v67 = (unsigned __int8)*v23;
          *(v23 - 10) = *(_BYTE *)(v13 + v24 + 3417);
          v68 = v67 & 0xFFFFFFEF | (16 * ((*(unsigned __int8 *)(v13 + v24 + 3438) >> 4) & 1));
          *v23 = v68;
          v69 = *(_QWORD *)(v13 + v24 + 3290);
          v70 = *(_QWORD *)(v13 + v24 + 3266);
          v71 = *(_QWORD *)(v13 + v24 + 3274);
          *(_QWORD *)(v23 - 145) = *(_QWORD *)(v13 + v24 + 3282);
          *(_QWORD *)(v23 - 137) = v69;
          *v46 = v70;
          *(_QWORD *)(v23 - 153) = v71;
          v72 = *(_QWORD *)(v13 + v24 + 3306);
          v73 = *(_QWORD *)(v13 + v24 + 3314);
          LOWORD(v69) = *(_WORD *)(v13 + v24 + 3322);
          *(_QWORD *)(v23 - 129) = *(_QWORD *)(v13 + v24 + 3298);
          *(_WORD *)(v23 - 105) = v69;
          *(_QWORD *)(v23 - 121) = v72;
          *(_QWORD *)(v23 - 113) = v73;
          LOBYTE(v68) = v68 & 0xFD | (2 * ((*(_BYTE *)(v13 + v24 + 3438) & 2) != 0));
          *v23 = v68;
          *v23 = v68 & 0xFB | *(_BYTE *)(v13 + v24 + 3438) & 4;
          *(_WORD *)(v83 + 18) |= v45;
          *(_BYTE *)(v43 + 3234) = 1;
        }
      }
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: ac=%d, tspec_mask_status=%x, tspec_index=%d direction = %d",
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        "sme_qos_ft_aggr_qos_req",
        v22,
        *(unsigned __int8 *)(v43 + 3233),
        1,
        (*(unsigned __int16 *)(v43 + 3469) >> 5) & 3);
      if ( (*(_BYTE *)(v43 + 3233) & 2) != 0 )
      {
        v74 = (*(unsigned __int16 *)(v43 + 3469) >> 5) & 3;
        if ( v74 == 3 || !v74 )
        {
          qdf_trace_msg(
            0x34u,
            8u,
            "%s: Found tspec entry AC=%d, flow=%d, direction = %d",
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            "sme_qos_fill_aggr_info",
            v22,
            1);
          v33 = byte_85618C;
          v34 = (unsigned __int8)byte_85618C;
          if ( (((unsigned __int8)byte_85618C + 1) & 0x100) != 0 )
            v35 = 1;
          else
            v35 = byte_85618C + 1;
          byte_85618C = v35;
          qdf_trace_msg(
            0x34u,
            8u,
            "%s: token %d",
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            "sme_qos_assign_dialog_token",
            v34);
          *(v23 - 162) = v33;
          *v23 = *v23 & 0xF7 | *(_BYTE *)(v13 + v24 + 3638) & 8;
          *(v23 - 103) = *(_BYTE *)(v13 + v24 + 3524);
          qdf_mem_copy(v23 - 102, (const void *)(v13 + v24 + 3525), 2u);
          v36 = (unsigned __int8)*v23;
          *(v23 - 10) = *(_BYTE *)(v13 + v24 + 3617);
          v37 = v36 & 0xFFFFFFEF | (16 * ((*(unsigned __int8 *)(v13 + v24 + 3638) >> 4) & 1));
          *v23 = v37;
          v38 = *(_QWORD *)(v13 + v24 + 3490);
          v39 = *(_QWORD *)(v13 + v24 + 3466);
          v40 = *(_QWORD *)(v13 + v24 + 3474);
          *(_QWORD *)(v23 - 145) = *(_QWORD *)(v13 + v24 + 3482);
          *(_QWORD *)(v23 - 137) = v38;
          *v46 = v39;
          *(_QWORD *)(v23 - 153) = v40;
          v41 = *(_QWORD *)(v13 + v24 + 3506);
          v42 = *(_QWORD *)(v13 + v24 + 3514);
          LOWORD(v38) = *(_WORD *)(v13 + v24 + 3522);
          *(_QWORD *)(v23 - 129) = *(_QWORD *)(v13 + v24 + 3498);
          *(_WORD *)(v23 - 105) = v38;
          *(_QWORD *)(v23 - 121) = v41;
          *(_QWORD *)(v23 - 113) = v42;
          LOBYTE(v37) = v37 & 0xFD | (2 * ((*(_BYTE *)(v13 + v24 + 3638) & 2) != 0));
          *v23 = v37;
          *v23 = v37 & 0xFB | *(_BYTE *)(v13 + v24 + 3638) & 4;
          *(_WORD *)(v83 + 18) |= v45;
          *(_BYTE *)(v43 + 3234) = 2;
        }
      }
      v24 += 728;
      ++v22;
      v23 += 163;
    }
    while ( v24 );
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: Sending aggregated message to HAL 0x%x",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "sme_qos_ft_aggr_qos_req",
      *(unsigned __int16 *)(v83 + 18));
    if ( (unsigned int)umac_send_mb_message_to_mac(v83) )
    {
      return 16;
    }
    else
    {
      qdf_trace_msg(
        0x34u,
        4u,
        "%s: sent down a AGGR QoS req to PE",
        v75,
        v76,
        v77,
        v78,
        v79,
        v80,
        v81,
        v82,
        "sme_qos_ft_aggr_qos_req");
      return 0;
    }
  }
  return result;
}
