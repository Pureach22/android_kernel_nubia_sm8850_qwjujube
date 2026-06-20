__int64 __fastcall lim_del_sta(__int64 a1, __int64 a2, char a3, __int64 a4)
{
  __int64 v8; // x0
  unsigned __int16 *v9; // x19
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  int v19; // w8
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  char v28; // w8
  unsigned int v29; // w22
  int v30; // w10
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  int v47; // w8
  __int64 v49; // [xsp+38h] [xbp-68h] BYREF
  unsigned __int16 *v50; // [xsp+40h] [xbp-60h]
  __int64 v51; // [xsp+48h] [xbp-58h]
  __int64 v52; // [xsp+50h] [xbp-50h]
  __int64 v53; // [xsp+58h] [xbp-48h]
  __int64 v54; // [xsp+60h] [xbp-40h]
  __int64 v55; // [xsp+68h] [xbp-38h] BYREF
  __int64 v56; // [xsp+70h] [xbp-30h]
  __int64 v57; // [xsp+78h] [xbp-28h]
  __int64 v58; // [xsp+80h] [xbp-20h]
  __int64 v59; // [xsp+88h] [xbp-18h]
  __int64 v60; // [xsp+90h] [xbp-10h]
  __int64 v61; // [xsp+98h] [xbp-8h]

  v61 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v53 = 0;
  v54 = 0;
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = nullptr;
  v8 = _qdf_mem_malloc(0x14u, "lim_del_sta", 2753);
  if ( v8 )
  {
    v9 = (unsigned __int16 *)v8;
    if ( !policy_mgr_is_hw_dbs_2x2_capable(*(_QWORD *)(a1 + 21552))
      && *(_DWORD *)(a4 + 88) == 1
      && *(_BYTE *)(a2 + 344) == 1
      && (*(_BYTE *)(a2 + 32) & 0x10) == 0
      && *(_BYTE *)(a4 + 8635) == 2
      && --*(_BYTE *)(a4 + 9793) == 0 )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: clearing SMPS intolrent vdev_param",
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        "lim_del_sta");
      wma_cli_set_command(*(unsigned __int8 *)(a4 + 10), 113, 0, 1);
    }
    *v9 = *(_WORD *)(a2 + 336);
    *(_WORD *)a2 &= ~1u;
    if ( (a3 & 1) != 0 )
    {
      if ( *(_BYTE *)(a2 + 344) != 4 )
      {
        if ( *(_DWORD *)(a2 + 8) != 23 )
        {
          qdf_trace(53, 0, *(_WORD *)(a4 + 8), 22);
          *(_DWORD *)(a2 + 8) = 22;
        }
        if ( *(_DWORD *)(a4 + 88) == 2 )
        {
          qdf_trace(53, 0, *(_WORD *)(a4 + 8), 22);
          *(_DWORD *)(a4 + 72) = 22;
        }
      }
      *(_BYTE *)(a1 + 8885) = 0;
      *(_QWORD *)(a1 + 8888) = "lim_del_sta";
      qdf_trace_msg(0x35u, 8u, "%s: Defer LIM msg %d", v10, v11, v12, v13, v14, v15, v16, v17, "lim_del_sta", 0);
      v19 = *(unsigned __int8 *)(a1 + 8885);
      v59 = 0;
      v60 = 0;
      v57 = 0;
      v58 = 0;
      v55 = 0;
      v56 = 0;
      if ( v19 )
      {
        if ( *(_WORD *)(a1 + 8688) )
        {
          LOWORD(v55) = 5119;
          if ( (unsigned int)lim_post_msg_api(a1, (unsigned __int16 *)&v55) )
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: Failed to post lim msg:0x%x",
              v20,
              v21,
              v22,
              v23,
              v24,
              v25,
              v26,
              v27,
              "lim_post_msg_to_process_deferred_queue",
              (unsigned __int16)v55);
        }
      }
      v28 = 1;
    }
    else
    {
      v28 = 0;
    }
    *((_BYTE *)v9 + 8) = v28;
    *((_BYTE *)v9 + 9) = *(_BYTE *)(a4 + 8);
    *((_BYTE *)v9 + 10) = *(_BYTE *)(a4 + 10);
    *((_BYTE *)v9 + 11) = *(_BYTE *)(a2 + 344);
    qdf_mem_copy(v9 + 6, (const void *)(a2 + 338), 6u);
    *((_DWORD *)v9 + 1) = 0;
    v50 = v9;
    v30 = *(unsigned __int8 *)(a2 + 338);
    v49 = 4131;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Sessionid %d :Sending SIR_HAL_DELETE_STA_REQ for mac_addr %02x:%02x:%02x:**:**:%02x and AssocID: %d MAC : %02x"
      ":%02x:%02x:**:**:%02x",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "lim_del_sta",
      *((unsigned __int8 *)v9 + 9),
      *((unsigned __int8 *)v9 + 12),
      *((unsigned __int8 *)v9 + 13),
      *((unsigned __int8 *)v9 + 14),
      *((unsigned __int8 *)v9 + 17),
      *v9,
      v30,
      *(unsigned __int8 *)(a2 + 339),
      *(unsigned __int8 *)(a2 + 340),
      *(unsigned __int8 *)(a2 + 343));
    mac_trace_msg_tx(a1, *(unsigned __int8 *)(a4 + 8), 4131);
    v29 = wma_post_ctrl_msg(a1, &v49);
    if ( v29 )
    {
      if ( (a3 & 1) != 0 )
      {
        *(_BYTE *)(a1 + 8885) = 1;
        *(_QWORD *)(a1 + 8888) = "lim_del_sta";
        qdf_trace_msg(0x35u, 8u, "%s: Defer LIM msg %d", v39, v40, v41, v42, v43, v44, v45, v46, "lim_del_sta", 1);
        v47 = *(unsigned __int8 *)(a1 + 8885);
        v59 = 0;
        v60 = 0;
        v57 = 0;
        v58 = 0;
        v55 = 0;
        v56 = 0;
        if ( v47 )
        {
          if ( *(_WORD *)(a1 + 8688) )
          {
            LOWORD(v55) = 5119;
            if ( (unsigned int)lim_post_msg_api(a1, (unsigned __int16 *)&v55) )
              qdf_trace_msg(
                0x35u,
                2u,
                "%s: Failed to post lim msg:0x%x",
                v39,
                v40,
                v41,
                v42,
                v43,
                v44,
                v45,
                v46,
                "lim_post_msg_to_process_deferred_queue",
                (unsigned __int16)v55);
          }
        }
      }
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Posting DELETE_STA_REQ to HAL failed, reason=%X",
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        "lim_del_sta",
        v29);
      _qdf_mem_free((__int64)v9);
    }
  }
  else
  {
    v29 = 2;
  }
  _ReadStatusReg(SP_EL0);
  return v29;
}
