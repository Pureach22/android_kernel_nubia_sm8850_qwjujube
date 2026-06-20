__int64 __fastcall sme_qos_ese_process_reassoc_tspec_rsp(
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
  unsigned int v11; // w28
  __int64 v12; // x8
  unsigned int v13; // w22
  const char *v14; // x2
  __int64 v16; // x21
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned __int64 v25; // x8
  unsigned int v26; // w22
  int v27; // w26
  unsigned int v28; // w23
  unsigned __int8 v29; // w24
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  int v38; // w25
  unsigned int v39; // w26
  int v40; // w20
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 v49; // x0
  __int64 v50; // x19
  unsigned int v51; // w28
  char v52; // w9
  __int64 v53; // x4
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 v62; // x19
  unsigned int v63; // w24
  char v64; // w9
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  unsigned int v73; // [xsp+8h] [xbp-28h]
  unsigned int v74; // [xsp+14h] [xbp-1Ch]
  __int64 v75; // [xsp+18h] [xbp-18h]

  if ( (unsigned __int8)a2 <= 5u
    && (v11 = (unsigned __int8)a2, (v12 = *(_QWORD *)(a1 + 17296) + 96LL * (unsigned __int8)a2) != 0) )
  {
    v13 = *(_DWORD *)(v12 + 24);
    if ( v13 > 0x3B )
    {
      v16 = *(_QWORD *)(v12 + 32)
          + *(unsigned int *)(v12 + 8)
          + *(unsigned int *)(v12 + 12)
          + (unsigned __int64)*(unsigned int *)(v12 + 16)
          + *(unsigned int *)(v12 + 20);
      v75 = qword_91F2D8;
      qdf_trace_msg(
        0x34u,
        3u,
        "%s: TspecLen = %d, pbFrames = %pK, pTspecIE = %pK",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "sme_qos_ese_process_reassoc_tspec_rsp",
        v13);
      v25 = 2290649225LL * v13;
      if ( !(unsigned __int8)(v13 / 0x3C) )
        return sme_qos_ft_aggr_qos_req(a2);
      v26 = 0;
      v73 = v11;
      v74 = (unsigned __int8)(v25 >> 37);
      while ( 1 )
      {
        v27 = sme_qos_up_to_ac_map[((unsigned __int64)*(unsigned int *)(v16 + 2) >> 11) & 7];
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: up = %d ac = %d returned",
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          "sme_qos_up_to_ac");
        v28 = (unsigned __int8)v27;
        if ( (unsigned __int8)v27 >= 4u )
        {
          v14 = "%s: ac %d more than it`s max value";
          goto LABEL_6;
        }
        v29 = *(_BYTE *)(v75 + 3040LL * v11 + 728LL * (unsigned __int8)v27 + 321);
        qdf_trace_msg(
          0x34u,
          3u,
          "%s: UP=%d, ac=%d, tspec_mask_status=%x",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "sme_qos_ese_process_reassoc_tspec_rsp",
          (*(_DWORD *)(v16 + 2) >> 11) & 7,
          (unsigned __int8)v27,
          v29);
        v38 = v27 & 0xFC;
        v39 = v27 & 3;
        if ( (v29 & 1) != 0 )
        {
          v49 = qdf_trace_msg(
                  0x34u,
                  3u,
                  "%s: Found Tspec entry flow = %d AC = %d",
                  v30,
                  v31,
                  v32,
                  v33,
                  v34,
                  v35,
                  v36,
                  v37,
                  "sme_qos_ese_process_reassoc_tspec_rsp",
                  0,
                  v28);
          if ( v38 )
            goto LABEL_25;
          v50 = qword_91F2D8 + 3040LL * v11 + 728LL * v39;
          v40 = 0;
          v51 = LOBYTE(sme_qos_up_to_ac_map[((unsigned __int64)*(unsigned int *)(v16 + 2) >> 11) & 7]);
          qdf_mem_set((void *)(v50 + 328), 0xC8u, 0);
          *(_DWORD *)(v50 + 336) = 0;
          v52 = *(_BYTE *)(v50 + 526);
          *(_BYTE *)(v50 + 332) = a2;
          *(_DWORD *)(v50 + 328) = 13112349;
          *(_BYTE *)(v50 + 340) = 0;
          *(_DWORD *)(v50 + 344) = 0;
          v53 = v51;
          v11 = v73;
          *(_BYTE *)(v50 + 526) = v52 & 0xFD | (2 * (*(_BYTE *)v16 & 1));
          qdf_trace_msg(
            0x34u,
            8u,
            "%s: Copy Tspec to local data structure ac=%d, tspecIdx=%d",
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            "sme_qos_ese_save_tspec_response",
            v53,
            0);
          if ( (*(_BYTE *)(v50 + 526) & 2) != 0 )
            convert_wmmtspec(a1, v50 + 354, v16);
        }
        else
        {
          v40 = v38;
          qdf_trace_msg(
            0x34u,
            3u,
            "%s: Not found Tspec entry flow = %d AC = %d",
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            "sme_qos_ese_process_reassoc_tspec_rsp",
            0,
            v28);
        }
        if ( (v29 & 2) != 0 )
        {
          v49 = qdf_trace_msg(
                  0x34u,
                  3u,
                  "%s: Found Tspec entry flow = %d AC = %d",
                  v41,
                  v42,
                  v43,
                  v44,
                  v45,
                  v46,
                  v47,
                  v48,
                  "sme_qos_ese_process_reassoc_tspec_rsp",
                  1,
                  v28);
          if ( v40 )
          {
LABEL_25:
            __break(0x5512u);
            return sme_qos_ft_aggr_qos_req(v49);
          }
          v62 = qword_91F2D8 + 3040LL * v11 + 728LL * v39;
          v63 = LOBYTE(sme_qos_up_to_ac_map[((unsigned __int64)*(unsigned int *)(v16 + 2) >> 11) & 7]);
          qdf_mem_set((void *)(v62 + 528), 0xC8u, 0);
          *(_DWORD *)(v62 + 536) = 0;
          v64 = *(_BYTE *)(v62 + 726);
          *(_BYTE *)(v62 + 532) = a2;
          *(_DWORD *)(v62 + 528) = 13112349;
          *(_BYTE *)(v62 + 540) = 0;
          *(_DWORD *)(v62 + 544) = 0;
          *(_BYTE *)(v62 + 726) = v64 & 0xFD | (2 * (*(_BYTE *)v16 & 1));
          qdf_trace_msg(
            0x34u,
            8u,
            "%s: Copy Tspec to local data structure ac=%d, tspecIdx=%d",
            v65,
            v66,
            v67,
            v68,
            v69,
            v70,
            v71,
            v72,
            "sme_qos_ese_save_tspec_response",
            v63,
            1);
          if ( (*(_BYTE *)(v62 + 726) & 2) != 0 )
            convert_wmmtspec(a1, v62 + 554, v16);
        }
        else
        {
          qdf_trace_msg(
            0x34u,
            3u,
            "%s: Not found Tspec entry flow = %d AC = %d",
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            "sme_qos_ese_process_reassoc_tspec_rsp",
            1,
            v28);
        }
        ++v26;
        v16 += 60;
        if ( v26 >= v74 )
          return sme_qos_ft_aggr_qos_req(a2);
      }
    }
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: ESE Tspec IE len %d less than min %zu",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "sme_qos_ese_process_reassoc_tspec_rsp",
      v13,
      60);
  }
  else
  {
    v14 = "%s: session %d not found";
LABEL_6:
    qdf_trace_msg(0x34u, 2u, v14, a3, a4, a5, a6, a7, a8, a9, a10, "sme_qos_ese_process_reassoc_tspec_rsp");
  }
  return 16;
}
