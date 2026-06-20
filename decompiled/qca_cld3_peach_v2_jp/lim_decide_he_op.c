__int64 __fastcall lim_decide_he_op(__int64 a1, __int64 a2, __int64 a3)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned int v14; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 result; // x0
  int v24; // w23
  int v25; // w22
  __int64 v26; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x24
  int v36; // w23
  __int64 v37; // x25
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
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  _BYTE v78[4]; // [xsp+0h] [xbp-40h] BYREF
  _BYTE v79[4]; // [xsp+4h] [xbp-3Ch] BYREF
  _QWORD v80[2]; // [xsp+8h] [xbp-38h] BYREF
  __int16 v81; // [xsp+18h] [xbp-28h]
  _QWORD v82[2]; // [xsp+20h] [xbp-20h] BYREF
  char v83; // [xsp+30h] [xbp-10h]
  __int64 v84; // [xsp+38h] [xbp-8h]

  v84 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v78[0] = 0;
  v81 = 0;
  v80[0] = 0;
  v80[1] = 0;
  v83 = 0;
  v82[0] = 0;
  v82[1] = 0;
  qdf_mem_set(v82, 0x11u, 0);
  v14 = wlan_strip_ie(
          *(unsigned __int8 **)(a3 + 7328),
          (unsigned __int16 *)(a3 + 7320),
          0xFFu,
          1,
          "$",
          1u,
          (char *)v82,
          15,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13);
  if ( v14 )
  {
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: Failed to strip HE OP IE status: %d",
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               "lim_decide_he_op",
               v14);
  }
  else
  {
    v24 = *(_DWORD *)((char *)v82 + 3);
    v25 = HIBYTE(*(_DWORD *)((char *)v82 + 3)) & 0x3F;
    if ( !v25 )
    {
      get_random_bytes(v78, 1);
      v24 = *(_DWORD *)((char *)v82 + 3);
      v25 = v78[0] % 0x3Fu + 1;
    }
    v26 = *(_QWORD *)(a1 + 21552);
    BYTE5(v80[0]) = v25;
    v79[0] = 0;
    *(_DWORD *)((char *)v80 + 1) = (16 * v24) & 0x3FF00 | v24 & 0xF;
    if ( (unsigned int)wlan_mlme_get_fw_optimized_power_cap(v26, v79, v15, v16, v17, v18, v19, v20, v21, v22) )
    {
      v35 = jiffies;
      if ( lim_refill_rts_threshold___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Unable to get optimized power capability info",
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          "lim_refill_rts_threshold");
        lim_refill_rts_threshold___last_ticks = v35;
      }
    }
    else if ( v79[0] == 1 )
    {
      v36 = v24 & 0xF;
      v37 = jiffies;
      if ( lim_refill_rts_threshold___last_ticks_422 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Overriding the rts_threshold value",
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          "lim_refill_rts_threshold");
        lim_refill_rts_threshold___last_ticks_422 = v37;
      }
      *(_DWORD *)((char *)v80 + 1) = v36 | 0x100;
    }
    HIWORD(v80[0]) = *(_DWORD *)(*(_QWORD *)(a1 + 8) + 1460LL);
    BYTE5(v80[0]) = BYTE6(v82[0]) & 0x40 | v25;
    qdf_mem_copy((void *)(a3 + 8740), v80, 0x12u);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: HE Op: bss_color: 0x%0x, default_pe_duration: 0x%0x",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "lim_decide_he_op",
      BYTE5(v80[0]) & 0x3F,
      BYTE1(v80[0]) & 7);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: He Op: twt_required: 0x%0x, txop_rts_threshold: 0x%0x",
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      "lim_decide_he_op",
      (*(_DWORD *)((char *)v80 + 1) >> 3) & 1,
      (*(_DWORD *)((char *)v80 + 1) >> 8) & 0x3FF);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: HE Op: partial_bss_color: 0x%0x",
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      "lim_decide_he_op",
      (BYTE5(v80[0]) >> 6) & 1);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: HE Op: BSS color disabled: 0x%0x",
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      "lim_decide_he_op",
      BYTE5(v80[0]) >> 7);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: HE Op: Basic MCS NSS: 0x%04x",
      v70,
      v71,
      v72,
      v73,
      v74,
      v75,
      v76,
      v77,
      "lim_decide_he_op",
      HIWORD(v80[0]));
    result = wma_update_vdev_he_ops(a2, v80);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
