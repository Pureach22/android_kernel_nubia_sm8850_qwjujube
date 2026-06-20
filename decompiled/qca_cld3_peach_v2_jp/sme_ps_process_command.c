__int64 __fastcall sme_ps_process_command(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v12; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  _DWORD *v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x19
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 result; // x0
  __int64 v43; // x21
  __int64 v44; // x0
  __int64 v45; // x20
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 v54; // x4
  __int64 v55; // x0
  __int64 v56; // x21
  int v57; // w22
  unsigned int v58; // w9
  int v59; // w10
  int v60; // w12
  __int64 v61; // x0
  __int64 v62; // x22
  __int64 v63; // x8
  unsigned int v64; // w9
  unsigned int v65; // w10
  int v66; // w23
  unsigned int v67; // w20
  __int64 v68; // x19
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  __int64 v77; // [xsp+8h] [xbp-38h] BYREF
  __int64 v78; // [xsp+10h] [xbp-30h]
  __int64 v79; // [xsp+18h] [xbp-28h]
  __int64 v80; // [xsp+20h] [xbp-20h]
  __int64 v81; // [xsp+28h] [xbp-18h]
  __int64 v82; // [xsp+30h] [xbp-10h]
  __int64 v83; // [xsp+38h] [xbp-8h]

  v83 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || a2 > 5 || (v12 = *(_QWORD *)(a1 + 17224)) == 0 || (*(_BYTE *)(v12 + 96LL * a2 + 1) & 1) == 0 )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Invalid Session_id: %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "sme_ps_process_command",
      a2);
    result = 4;
    goto LABEL_11;
  }
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: Vdev id %d, Power Save command %d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "sme_ps_process_command",
    a2,
    a3);
  if ( (int)a3 > 1 )
  {
    if ( a3 == 2 )
    {
      v61 = _qdf_mem_malloc(0x10u, "sme_ps_enable_uapsd_req_params", 219);
      if ( !v61 )
        goto LABEL_27;
      v62 = a1 + 13120;
      v63 = v62 + 192LL * a2;
      v64 = *(unsigned __int8 *)(v63 + 20);
      v65 = *(unsigned __int8 *)(v63 + 17) | v64;
      *(_BYTE *)v61 = (2 * v65) & 4
                    | (v65 >> 2) & 3
                    | (8 * (v65 & 1)) & 0x8F
                    | ((*(_BYTE *)(v63 + 16) | (unsigned __int8)v64) << 7)
                    | (16 * (((*(unsigned __int8 *)(v63 + 16) | v64) >> 2) & 3)) & 0xBF
                    | ((((*(unsigned __int8 *)(v63 + 16) | v64) & 2) != 0) << 6);
      v66 = *(_DWORD *)(v63 + 12);
      *(_DWORD *)(v61 + 8) = a2;
      v45 = v61;
      *(_BYTE *)(v61 + 1) = v66 != 0;
      v77 = 4365;
      v78 = v61;
      v81 = 0;
      v82 = 0;
      v79 = 0;
      v80 = 0;
      if ( !(unsigned int)scheduler_post_message_debug(
                            0x34u,
                            0x36u,
                            54,
                            (unsigned __int16 *)&v77,
                            0x34u,
                            (__int64)"sme_post_ps_msg_to_wma") )
      {
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: Msg WMA_ENABLE_UAPSD_REQ Successfully sent to WMA",
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          "sme_ps_enable_uapsd_req_params");
        result = 0;
        *(_DWORD *)(v62 + 192LL * a2 + 12) = 2 * (v66 != 0);
        goto LABEL_11;
      }
      v54 = 4365;
    }
    else
    {
      if ( a3 != 3 )
      {
LABEL_18:
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: Invalid command type: %d",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "sme_ps_process_command",
          a3);
LABEL_26:
        v67 = 16;
LABEL_28:
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: Not able to enter in PS, Command: %d",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "sme_ps_process_command",
          a3);
        result = v67;
        goto LABEL_11;
      }
      v43 = a1 + 192LL * a2;
      if ( *(_DWORD *)(v43 + 13132) != 2 )
      {
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: UAPSD is already disabled",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "sme_ps_disable_uapsd_req_params");
        result = 0;
        goto LABEL_11;
      }
      v44 = _qdf_mem_malloc(0x10u, "sme_ps_disable_uapsd_req_params", 258);
      if ( !v44 )
      {
LABEL_27:
        v67 = 2;
        goto LABEL_28;
      }
      *(_DWORD *)(v44 + 8) = a2;
      v45 = v44;
      v77 = 4366;
      v78 = v44;
      v81 = 0;
      v82 = 0;
      v79 = 0;
      v80 = 0;
      if ( !(unsigned int)scheduler_post_message_debug(
                            0x34u,
                            0x36u,
                            54,
                            (unsigned __int16 *)&v77,
                            0x34u,
                            (__int64)"sme_post_ps_msg_to_wma") )
      {
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: Message WMA_DISABLE_UAPSD_REQ Successfully sent to WMA",
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          "sme_ps_disable_uapsd_req_params");
        result = 0;
        *(_DWORD *)(v43 + 13132) = 1;
        goto LABEL_11;
      }
      v54 = 4366;
    }
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Posting message %d failed",
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      "sme_post_ps_msg_to_wma",
      v54);
    _qdf_mem_free(v45);
    goto LABEL_26;
  }
  if ( a3 )
  {
    if ( a3 == 1 )
    {
      v24 = (_DWORD *)_qdf_mem_malloc(8u, "sme_ps_disable_ps_req_params", 187);
      if ( v24 )
      {
        *v24 = 0;
        v24[1] = a2;
        v33 = (__int64)v24;
        wma_disable_sta_ps_mode();
        _qdf_mem_free(v33);
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: Powersave disable sent to FW",
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          "sme_ps_disable_ps_req_params");
        result = 0;
        *(_DWORD *)(a1 + 192LL * a2 + 13132) = 0;
        goto LABEL_11;
      }
      goto LABEL_27;
    }
    goto LABEL_18;
  }
  v55 = _qdf_mem_malloc(0xCu, "sme_ps_enable_ps_req_params", 148);
  if ( !v55 )
    goto LABEL_27;
  v56 = a1 + 192LL * a2 + 13120;
  if ( *(_BYTE *)(a1 + 192LL * a2 + 13140) )
  {
    v57 = 2;
    *(_DWORD *)v55 = 1;
    v58 = *(unsigned __int8 *)(v56 + 20);
    v59 = *(unsigned __int8 *)(v56 + 17);
    v60 = *(unsigned __int8 *)(v56 + 16);
    *(_BYTE *)(v55 + 5) = 1;
    *(_BYTE *)(v55 + 4) = (2 * (v59 | v58)) & 4
                        | ((v59 | v58) >> 2) & 3
                        | (8 * ((v59 | v58) & 1)) & 0x8F
                        | (((unsigned __int8)v60 | (unsigned __int8)v58) << 7)
                        | (16 * (((v60 | v58) >> 2) & 3)) & 0xBF
                        | ((((v60 | v58) & 2) != 0) << 6);
  }
  else
  {
    v57 = 1;
    *(_DWORD *)v55 = 0;
  }
  *(_DWORD *)(v55 + 8) = a2;
  v68 = v55;
  wma_enable_sta_ps_mode();
  _qdf_mem_free(v68);
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: Powersave Enable sent to FW",
    v69,
    v70,
    v71,
    v72,
    v73,
    v74,
    v75,
    v76,
    "sme_ps_enable_ps_req_params");
  result = 0;
  *(_DWORD *)(v56 + 12) = v57;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
