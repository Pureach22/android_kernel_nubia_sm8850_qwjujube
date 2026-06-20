__int64 __fastcall lim_addba_rsp_tx_complete_cnf(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 **context; // x22
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  const char *v25; // x2
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x23
  unsigned int v35; // w9
  __int64 v36; // x8
  unsigned int v37; // w24
  const char *v38; // x2
  __int64 v39; // x0
  __int64 v40; // x1
  __int64 v41; // x0
  __int64 v42; // x25
  __int64 cmpt_obj; // x0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  unsigned int *v52; // x8
  const char *v53; // x2
  unsigned int *v54; // x8
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 v63; // x25
  unsigned int v64; // w8
  unsigned __int8 *v65; // x26
  int v66; // w9
  unsigned __int8 *v67; // x1
  unsigned __int8 *v68; // x10
  int v69; // w11
  int v70; // t1
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  __int64 v79; // x8
  _DWORD *v80; // x8
  __int64 v81; // x2
  __int64 v82; // x3
  __int64 v84; // [xsp+0h] [xbp-20h] BYREF
  __int64 v85; // [xsp+8h] [xbp-18h] BYREF
  __int64 v86; // [xsp+10h] [xbp-10h]
  __int64 v87; // [xsp+18h] [xbp-8h]

  v87 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LODWORD(v86) = 0;
  v85 = 0;
  context = (__int64 **)_cds_get_context(
                          71,
                          (__int64)"lim_addba_rsp_tx_complete_cnf",
                          a5,
                          a6,
                          a7,
                          a8,
                          a9,
                          a10,
                          a11,
                          a12);
  if ( a3 )
    v25 = "%s: Fail to send add ba response";
  else
    v25 = "%s: Add ba response successfully sent";
  qdf_trace_msg(0x35u, 8u, v25, v17, v18, v19, v20, v21, v22, v23, v24, "lim_addba_rsp_tx_complete_cnf");
  if ( a2 )
  {
    v34 = *(_QWORD *)(a2 + 224);
    if ( v34 )
    {
      if ( (*(_WORD *)v34 & 0x4000) == 0 )
      {
        v35 = 24;
        v36 = *(_QWORD *)(a2 + 224);
        goto LABEL_21;
      }
      v39 = *(_QWORD *)(a1 + 21552);
      v40 = *(unsigned __int8 *)(a4 + 10);
      BYTE4(v84) = 0;
      LOBYTE(v84) = 0;
      v41 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v39, v40, 7);
      if ( v41 )
      {
        v42 = v41;
        cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v41, v26, v27, v28, v29, v30, v31, v32, v33);
        if ( cmpt_obj )
        {
          if ( *(_BYTE *)(cmpt_obj + 163) == 7 )
          {
            v52 = (unsigned int *)&qword_8;
            LOBYTE(v84) = 8;
            BYTE4(v84) = 8;
LABEL_20:
            wlan_objmgr_vdev_release_ref(v42, 7u, v52, v44, v45, v46, v47, v48, v49, v50, v51);
            v36 = *(_QWORD *)(a2 + 224);
            v35 = (unsigned __int8)v84 + 24;
LABEL_21:
            v63 = *(_QWORD *)(a2 + 216) + *(unsigned int *)(a2 + 212) - v36;
            if ( (unsigned __int64)v35 + 12 <= (unsigned int)v63 )
            {
              v64 = v63 - v35;
              v65 = (unsigned __int8 *)(v34 + v35);
              if ( (unsigned int)v63 - v35 < 0xC )
                goto LABEL_29;
              v66 = *v65;
              v67 = v65;
              v68 = v65;
              while ( 1 )
              {
                v69 = v66;
                v70 = *++v68;
                v66 = v70;
                if ( v69 == 3 && v66 == 1 )
                  break;
                --v64;
                v67 = v68;
                if ( v64 < 0xC )
                  goto LABEL_29;
              }
              if ( !v67 )
              {
LABEL_29:
                qdf_trace_msg(
                  0x35u,
                  8u,
                  "%s: null addba_rsp_ptr",
                  v26,
                  v27,
                  v28,
                  v29,
                  v30,
                  v31,
                  v32,
                  v33,
                  "lim_addba_rsp_tx_complete_cnf",
                  v84,
                  v85,
                  v86,
                  v87);
                ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(
                  53,
                  8,
                  v34,
                  (unsigned int)v63);
                v67 = v65;
              }
              v37 = dot11f_unpack_addba_rsp(a1, v67, 12, &v85, 0);
              if ( (v37 & 0x10000000) != 0 )
              {
                qdf_trace_msg(
                  0x35u,
                  2u,
                  "%s: Failed to unpack and parse (0x%08x, %d bytes)",
                  v71,
                  v72,
                  v73,
                  v74,
                  v75,
                  v76,
                  v77,
                  v78,
                  "lim_addba_rsp_tx_complete_cnf",
                  v37,
                  12);
                v37 = 0;
              }
              else if ( context && *context )
              {
                v79 = **context;
                if ( v79 )
                {
                  v80 = *(_DWORD **)(v79 + 432);
                  if ( v80 )
                  {
                    v81 = *(unsigned __int8 *)(a4 + 10);
                    v82 = (BYTE6(v85) >> 2) & 0xF;
                    if ( *(v80 - 1) != 75369535 )
                      __break(0x8228u);
                    ((void (__fastcall *)(__int64 **, __int64, __int64, __int64, _QWORD))v80)(
                      context,
                      v34 + 4,
                      v81,
                      v82,
                      a3);
                  }
                }
              }
              else
              {
                qdf_trace_msg(
                  0x89u,
                  8u,
                  "%s: Invalid Instance:",
                  v71,
                  v72,
                  v73,
                  v74,
                  v75,
                  v76,
                  v77,
                  v78,
                  "cdp_addba_resp_tx_completion",
                  v84);
              }
            }
            else
            {
              qdf_trace_msg(
                0x35u,
                2u,
                "%s: Invalid data len %d",
                v26,
                v27,
                v28,
                v29,
                v30,
                v31,
                v32,
                v33,
                "lim_addba_rsp_tx_complete_cnf",
                (unsigned int)v63);
              v37 = 16;
            }
            goto LABEL_40;
          }
          if ( !(unsigned int)mlme_get_peer_mic_len(
                                *(_QWORD *)(a1 + 21552),
                                *(_BYTE *)(*(_QWORD *)(a1 + 21560) + 40LL),
                                (unsigned __int8 *)(v34 + 4),
                                (_BYTE *)&v84 + 4,
                                (unsigned __int8 *)&v84,
                                v44,
                                v45,
                                v46,
                                v47,
                                v48,
                                v49,
                                v50,
                                v51) )
            goto LABEL_20;
          v53 = "%s: Fail to get mic info";
        }
        else
        {
          v53 = "%s: Failed to get vdev mlme obj!";
        }
        qdf_trace_msg(0x35u, 2u, v53, v44, v45, v46, v47, v48, v49, v50, v51, "lim_addba_rsp_tx_complete_cnf");
        wlan_objmgr_vdev_release_ref(v42, 7u, v54, v55, v56, v57, v58, v59, v60, v61, v62);
        v37 = 16;
LABEL_40:
        _qdf_nbuf_free(a2);
        goto LABEL_41;
      }
      v38 = "%s: vdev is NULL";
    }
    else
    {
      v38 = "%s: Addba response frame is NULL";
    }
    qdf_trace_msg(0x35u, 2u, v38, v26, v27, v28, v29, v30, v31, v32, v33, "lim_addba_rsp_tx_complete_cnf");
    v37 = 16;
    goto LABEL_40;
  }
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: Addba response frame buffer is NULL",
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    "lim_addba_rsp_tx_complete_cnf");
  v37 = 16;
LABEL_41:
  _ReadStatusReg(SP_EL0);
  return v37;
}
