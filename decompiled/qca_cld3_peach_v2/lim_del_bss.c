__int64 __fastcall lim_del_bss(__int64 a1, __int16 *a2, __int64 a3, __int64 a4)
{
  __int16 v6; // w8
  __int16 v7; // w2
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  int v24; // w8
  __int64 v25; // x4
  __int64 v26; // x5
  __int64 v27; // x6
  __int64 v28; // x7
  int v29; // w8
  unsigned int v30; // w22
  unsigned int v31; // w20
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  int v48; // w8
  int v50; // [xsp+0h] [xbp-70h]
  _QWORD v51[2]; // [xsp+8h] [xbp-68h] BYREF
  __int64 v52; // [xsp+18h] [xbp-58h]
  __int64 v53; // [xsp+20h] [xbp-50h]
  __int64 v54; // [xsp+28h] [xbp-48h]
  __int64 v55; // [xsp+30h] [xbp-40h]
  __int64 v56; // [xsp+38h] [xbp-38h] BYREF
  __int64 v57; // [xsp+40h] [xbp-30h]
  __int64 v58; // [xsp+48h] [xbp-28h]
  __int64 v59; // [xsp+50h] [xbp-20h]
  __int64 v60; // [xsp+58h] [xbp-18h]
  __int64 v61; // [xsp+60h] [xbp-10h]
  __int64 v62; // [xsp+68h] [xbp-8h]

  v62 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v54 = 0;
  v55 = 0;
  v52 = 0;
  v53 = 0;
  v51[0] = 0;
  v51[1] = 0;
  if ( a2 )
  {
    v6 = *a2;
    *((_DWORD *)a2 + 2) = 17;
    *a2 = v6 & 0xFFFE;
  }
  v7 = *(_WORD *)(a4 + 8);
  *(_DWORD *)(a4 + 72) = 17;
  qdf_trace(53, 0, v7, 17);
  if ( *(_WORD *)(a4 + 8) == *(unsigned __int8 *)(a1 + 1122) && (tx_timer_running(a1 + 1072) & 1) != 0 )
    lim_deactivate_and_change_timer(a1, 2);
  *(_BYTE *)(a1 + 8885) = 0;
  *(_QWORD *)(a1 + 8888) = "lim_del_bss";
  qdf_trace_msg(0x35u, 8u, "%s: Defer LIM msg %d", v8, v9, v10, v11, v12, v13, v14, v15);
  v24 = *(unsigned __int8 *)(a1 + 8885);
  v60 = 0;
  v61 = 0;
  v58 = 0;
  v59 = 0;
  v56 = 0;
  v57 = 0;
  if ( v24 )
  {
    if ( *(_WORD *)(a1 + 8688) )
    {
      LOWORD(v56) = 5119;
      if ( (unsigned int)lim_post_msg_api(a1, (unsigned __int16 *)&v56) )
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Failed to post lim msg:0x%x",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "lim_post_msg_to_process_deferred_queue",
          (unsigned __int16)v56);
    }
  }
  v25 = *(unsigned __int16 *)(a4 + 8);
  v26 = *(unsigned __int8 *)(a4 + 24);
  v27 = *(unsigned __int8 *)(a4 + 25);
  v28 = *(unsigned __int8 *)(a4 + 26);
  v29 = *(unsigned __int8 *)(a4 + 29);
  if ( *(_BYTE *)(a4 + 8674) )
    v30 = 4174;
  else
    v30 = 4135;
  HIDWORD(v51[0]) = *(unsigned __int8 *)(a4 + 10);
  LODWORD(v51[0]) = (unsigned __int16)v30;
  v50 = v29;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Sessionid %d : Sending HAL_DELETE_BSS_REQ BSSID:%02x:%02x:%02x:**:**:%02x",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "lim_del_bss",
    v25,
    v26,
    v27,
    v28,
    v50,
    v51[0],
    0,
    v52,
    v53,
    v54,
    v55,
    v56,
    v57,
    v58,
    v59,
    v60,
    v61,
    v62);
  mac_trace_msg_tx(a1, *(unsigned __int8 *)(a4 + 8), v30);
  v31 = wma_post_ctrl_msg(a1, v51);
  if ( v31 )
  {
    *(_BYTE *)(a1 + 8885) = 1;
    *(_QWORD *)(a1 + 8888) = "lim_del_bss";
    qdf_trace_msg(0x35u, 8u, "%s: Defer LIM msg %d", v32, v33, v34, v35, v36, v37, v38, v39, "lim_del_bss", 1);
    v48 = *(unsigned __int8 *)(a1 + 8885);
    v60 = 0;
    v61 = 0;
    v58 = 0;
    v59 = 0;
    v56 = 0;
    v57 = 0;
    if ( v48 )
    {
      if ( *(_WORD *)(a1 + 8688) )
      {
        LOWORD(v56) = 5119;
        if ( (unsigned int)lim_post_msg_api(a1, (unsigned __int16 *)&v56) )
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Failed to post lim msg:0x%x",
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            "lim_post_msg_to_process_deferred_queue",
            (unsigned __int16)v56);
      }
    }
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Posting DELETE_BSS_REQ to HAL failed, reason=%X",
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      "lim_del_bss",
      v31);
  }
  _ReadStatusReg(SP_EL0);
  return v31;
}
