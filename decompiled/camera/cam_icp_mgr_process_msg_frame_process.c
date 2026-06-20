__int64 __fastcall cam_icp_mgr_process_msg_frame_process(__int64 a1, __int64 a2)
{
  _BOOL4 v3; // w23
  __int64 result; // x0
  __int64 v5; // x19
  __int64 v6; // x22
  __int64 v7; // x25
  __int64 *v8; // x27
  __int64 v9; // x24
  int v10; // w8
  unsigned __int64 v11; // x28
  int *v12; // x24
  int v13; // w26
  unsigned int scid; // w25
  int llcc_status; // w0
  unsigned int *v16; // x0
  __int64 v17; // x21
  unsigned int *v18; // x0
  __int64 v19; // x24
  __int64 v20; // x26
  __int64 *v21; // x28
  __int64 v22; // x0
  int v23; // w12
  unsigned __int64 v24; // x9
  unsigned __int64 v25; // x8
  __int64 v26; // x1
  unsigned int v27; // w23
  int v28; // w21
  const char *v29; // x0
  int v30; // w8
  int v31; // w8
  __int64 v32; // x25
  unsigned __int64 v33; // x23
  _DWORD *v34; // x21
  _DWORD *v35; // x8
  __int64 v36; // x0
  int v37; // w8
  _DWORD *v38; // x8
  __int64 v39; // x0
  __int64 *v40; // x21
  unsigned int v41; // w7
  __int64 v43; // x0
  __int64 v44; // x9
  void (__fastcall *v45)(__int64, __int64, __int64 *); // x8
  __int64 v46; // x0
  const char *v47; // x5
  __int64 v48; // x1
  __int64 *v49; // x6
  __int64 v50; // x2
  __int64 v51; // x4
  unsigned __int64 v57; // x10
  int v58; // [xsp+1Ch] [xbp-124h]
  __int64 v59; // [xsp+20h] [xbp-120h]
  int v60; // [xsp+28h] [xbp-118h]
  int v61; // [xsp+28h] [xbp-118h]
  __int64 v63; // [xsp+40h] [xbp-100h] BYREF
  __int64 v64; // [xsp+48h] [xbp-F8h]
  _QWORD *v65; // [xsp+50h] [xbp-F0h] BYREF
  __int64 v66; // [xsp+58h] [xbp-E8h]
  int v67; // [xsp+64h] [xbp-DCh] BYREF
  _QWORD v68[2]; // [xsp+68h] [xbp-D8h] BYREF
  _QWORD v69[21]; // [xsp+78h] [xbp-C8h] BYREF
  __int64 v70; // [xsp+120h] [xbp-20h]
  __int64 v71; // [xsp+128h] [xbp-18h]
  __int64 v72; // [xsp+130h] [xbp-10h]

  v72 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    if ( *(_DWORD *)(a2 + 28) )
      v3 = 1;
    else
      v3 = *(_DWORD *)(a2 + 32) != 0;
    v5 = *(_QWORD *)(a2 + 12);
    v6 = *(_QWORD *)(a2 + 20);
    v70 = 0;
    v71 = 0;
    memset(v69, 0, sizeof(v69));
    v65 = nullptr;
    v66 = 0;
    v63 = 0;
    v64 = 0;
    if ( !v5 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_mgr_handle_frame_process",
        2665,
        "Invalid Context req %llu",
        v6);
LABEL_14:
      result = 0;
      goto LABEL_15;
    }
    v7 = *(int *)(v5 + 4);
    v8 = *(__int64 **)(v5 + 16);
    mutex_lock(*(_QWORD *)(a1 + 88) + 48LL * (int)v7);
    if ( v8 != *(__int64 **)(*(_QWORD *)(a1 + 96) + 8 * v7) )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        2,
        "cam_icp_mgr_handle_frame_process",
        2674,
        "ctx data is released before accessing it, ctx_id: %u",
        v7);
LABEL_9:
      mutex_unlock(*(_QWORD *)(a1 + 88) + 48LL * (int)v7);
      goto LABEL_10;
    }
    v9 = a1 + 40960;
    if ( *(_BYTE *)(a1 + 44261) == 1 )
    {
      v60 = v7;
      if ( (debug_mdl & 0x100) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x100,
          4,
          "cam_icp_mgr_handle_frame_process",
          2682,
          "starting debugging llcc register ctx_id: %u request_id: %llu",
          v7,
          v6);
      v10 = *(unsigned __int8 *)(a1 + 44236);
      v67 = 0;
      LODWORD(v68[0]) = 0;
      if ( v10 == 1 && *((_DWORD *)v8 + 7501) )
      {
        v11 = 0;
        v12 = (int *)(v8 + 3751);
        while ( 1 )
        {
          if ( v11 == 5 )
            goto LABEL_135;
          v13 = *v12;
          scid = cam_cpas_get_scid(*v12);
          llcc_status = cam_cpas_read_llcc_status(scid, (__int64)v68, (__int64)&v67);
          if ( llcc_status )
            break;
          if ( (debug_mdl & 0x100) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x100,
              4,
              "cam_icp_llcc_print_scid_state",
              2637,
              "llcc cfg value = 0x%x status value = 0x%x llcc_scid = %u internal_scid = %u",
              LODWORD(v68[0]),
              v67,
              scid,
              v13);
          ++v11;
          v12 += 5;
          if ( v11 >= *((unsigned int *)v8 + 7501) )
            goto LABEL_30;
        }
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_llcc_print_scid_state",
          2630,
          "llcc register read is failed = %d llcc_scid =  %u",
          llcc_status,
          scid);
      }
LABEL_30:
      LODWORD(v7) = v60;
      v9 = a1 + 40960;
    }
    if ( v8 )
    {
      v16 = (unsigned int *)v8[3725];
      if ( v16 )
      {
        ++*((_DWORD *)v8 + 7452);
        if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64 *))cam_print_log)(
            3,
            debug_mdl & 0x2000100,
            4,
            "cam_icp_ctx_timer_reset",
            427,
            "%s: reset timer : counter=%d",
            v8 + 3728);
          v16 = (unsigned int *)v8[3725];
        }
        crm_timer_reset(v16);
      }
    }
    if ( *((_DWORD *)v8 + 26) != 2 )
    {
      if ( (debug_mdl & 0x100) != 0 && !debug_priority )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64 *))cam_print_log)(
          3,
          debug_mdl & 0x100,
          4,
          "cam_icp_mgr_handle_frame_process",
          2689,
          "%s: is in %d state",
          v8 + 3728);
      goto LABEL_9;
    }
    if ( (debug_mdl & 0x1000100) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x1000100,
        4,
        "cam_icp_mgr_handle_frame_process",
        2696,
        "%s: request_id: %lld",
        (const char *)v8 + 29824,
        v6);
    v17 = v8[2];
    v18 = *(unsigned int **)(v17 + 552);
    if ( v18 )
    {
      if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x2000100,
          4,
          "cam_icp_device_timer_reset",
          441,
          "[%s] reset timer for device: %s",
          (const char *)(a1 + 112),
          *(const char **)v17);
        v18 = *(unsigned int **)(v17 + 552);
      }
      crm_timer_reset(v18);
      ++*(_DWORD *)(v17 + 560);
    }
    v59 = v9;
    v19 = 0;
    v20 = 0;
    while ( 1 )
    {
      v21 = &v8[v20];
      if ( v21[223] == v6 )
        break;
      ++v20;
      v19 += 164;
      if ( v20 == 40 )
        goto LABEL_54;
    }
    if ( (unsigned int)v20 >= 0x28 )
    {
LABEL_54:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_mgr_handle_frame_process",
        2705,
        "%s: pkt not found for req_id =%lld",
        (const char *)v8 + 29824,
        v6);
      goto LABEL_9;
    }
    v22 = ktime_get_with_offset(1);
    v23 = debug_mdl;
    v24 = (v22 - v21[3608]) / 1000000 + v8[3744];
    v25 = v8[3745] + 1;
    v8[3744] = v24;
    v26 = v23 & 0x2000100;
    v8[3745] = v25;
    if ( (v23 & 0x2000100) != 0 && !debug_priority )
      v22 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              v26,
              4,
              "cam_icp_mgr_compute_fw_avg_response_time",
              2607,
              "%s: Avg response time: current_req: %llu total_processed_requests: %llu avg_time: %llums",
              (const char *)v8 + 29824,
              v21[223],
              v25,
              v24 / v25);
    v61 = v7;
    if ( !v3 )
    {
      v58 = 0;
LABEL_99:
      if ( (cam_presil_mode_enabled(v22) & 1) != 0 )
      {
        v32 = v8[3648];
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          3,
          "cam_icp_mgr_handle_frame_process",
          2735,
          "Hangdump Num Regions %d",
          *(_DWORD *)(v32 + v19));
        if ( *(_DWORD *)(v32 + v19) )
        {
          v33 = 0;
          v34 = (_DWORD *)(v32 + v19 + 8);
          while ( v33 != 10 )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x8000000,
              3,
              "cam_icp_mgr_handle_frame_process",
              2740,
              "Hangdump Mem %d handle 0x%08x offset 0x%08x len %u",
              v33,
              *(v34 - 1),
              *v34,
              v34[1]);
            cam_mem_mgr_retrieve_buffer_from_presil();
            ++v33;
            v34 += 4;
            if ( v33 >= *(unsigned int *)(v32 + v19) )
              goto LABEL_104;
          }
LABEL_135:
          __break(0x5512u);
LABEL_136:
          panic("CAMERA - [%s] ENOMEM......\n", (const char *)(a1 + 112));
        }
      }
LABEL_104:
      ((void (*)(__int64, __int64, _QWORD, const char *, __int64, const char *, ...))cam_print_log)(
        2,
        256,
        0,
        "cam_icp_mgr_handle_frame_process",
        2751,
        "%s: BufDone Req %llu event_id %d",
        (const char *)v8 + 29824,
        v21[223],
        v58);
      v70 = v21[223];
      if ( *((_BYTE *)v8 + 29996) != 1 || v8[3747] != v6 )
        goto LABEL_111;
      v35 = (_DWORD *)v8[12];
      v68[0] = v69;
      v68[1] = v8 + 3746;
      if ( v35 )
      {
        v36 = *v8;
        if ( *(v35 - 1) != 414296116 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, __int64, _QWORD *))v35)(v36, 2, v68);
      }
      v37 = *((unsigned __int8 *)v8 + 29968);
      *((_BYTE *)v8 + 29996) = 0;
      if ( v37 )
      {
LABEL_111:
        v38 = (_DWORD *)v8[12];
        LODWORD(v66) = v58;
        v65 = v69;
        if ( v38 )
        {
          v39 = *v8;
          if ( *(v38 - 1) != 414296116 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD, _QWORD **))v38)(v39, 0, &v65);
        }
      }
      v21[223] = 0;
      v40 = v8 + 563;
      v41 = *((_DWORD *)v8 + v20 + 1126);
      if ( v41 )
      {
        if ( (debug_mdl & 0x100) != 0 && !debug_priority )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64 *))cam_print_log)(
            3,
            debug_mdl & 0x100,
            4,
            "cam_icp_mgr_handle_frame_process",
            2770,
            "%s: Delete merged sync in object: %d",
            v8 + 3728);
          v41 = *((_DWORD *)v40 + v20);
        }
        cam_sync_destroy(v41);
        *((_DWORD *)v40 + v20) = 0;
      }
      _X8 = (unsigned __int64 *)v8[215];
      __asm { PRFM            #0x11, [X8] }
      do
        v57 = __ldxr(_X8);
      while ( __stxr(v57 & ~(1LL << v20), _X8) );
      *((_BYTE *)v8 + v20 + 4824) = 0;
      v43 = mutex_unlock(*(_QWORD *)(a1 + 88) + 48LL * v61);
      if ( *(_DWORD *)(a2 + 28) == 2 )
      {
        cam_icp_mgr_dump_active_req_info(a1);
        v44 = *(_QWORD *)(a1 + 88);
        LODWORD(v64) = 0;
        v63 = v6;
        mutex_lock(v44 + 48LL * v61);
        v45 = (void (__fastcall *)(__int64, __int64, __int64 *))v8[12];
        if ( v45 )
        {
          v46 = *v8;
          if ( *((_DWORD *)v45 - 1) != 414296116 )
            __break(0x8228u);
          v45(v46, 1, &v63);
        }
        if ( *(_BYTE *)(v59 + 3300) == 1 )
          goto LABEL_136;
        v43 = mutex_unlock(*(_QWORD *)(a1 + 88) + 48LL * v61);
      }
      if ( (cam_presil_mode_enabled(v43) & 1) != 0 )
      {
        if ( *(_DWORD *)(v59 + 3208) )
        {
          *(_DWORD *)(v59 + 3212) = -1;
          *(_DWORD *)(v59 + 3208) = 0;
          up_write(&frame_in_process_sem);
          if ( (debug_mdl & 0x8000000) == 0 || debug_priority )
            goto LABEL_10;
          v47 = "%s: presil: unlocked frame_in_process";
          v48 = debug_mdl & 0x8000000;
          v49 = v8 + 3728;
          v50 = 4;
          v51 = 2804;
        }
        else
        {
          v47 = "%s: presil: frame_in_process not set";
          v49 = v8 + 3728;
          v48 = 0x8000000;
          v50 = 1;
          v51 = 2798;
        }
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64 *))cam_print_log)(
          3,
          v48,
          v50,
          "cam_icp_mgr_handle_frame_process",
          v51,
          v47,
          v49);
      }
LABEL_10:
      if ( mem_trace_en == 1 )
        cam_mem_trace_free((_QWORD *)v5, 0);
      else
        kvfree(v5);
      goto LABEL_14;
    }
    v27 = *(_DWORD *)(a2 + 28);
    if ( v27 == 10 )
    {
      v28 = 2;
      v22 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              256,
              2,
              "cam_icp_mgr_handle_frame_process",
              2717,
              "%s: req %llu has been aborted[flushed]",
              (const char *)v8 + 29824,
              v6);
    }
    else
    {
      v29 = (const char *)cam_icp_error_handle_id_to_type(v27, v26);
      v28 = 1;
      v22 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              256,
              1,
              "cam_icp_mgr_handle_frame_process",
              2724,
              "%s: Done with error: %u err_type= [%s] for req %llu",
              (const char *)v8 + 29824,
              v27,
              v29,
              v6);
    }
    v30 = *(_DWORD *)(a2 + 28);
    if ( v30 > 8 )
    {
      if ( v30 > 999 )
      {
        if ( v30 <= 1001 )
        {
          if ( v30 == 1000 )
            v31 = 116;
          else
            v31 = 117;
          goto LABEL_98;
        }
        if ( v30 == 1002 )
        {
          v31 = 118;
          goto LABEL_98;
        }
        if ( v30 == 1003 )
        {
          v31 = 119;
          goto LABEL_98;
        }
      }
      else
      {
        if ( v30 <= 10 )
        {
          if ( v30 == 9 )
            v31 = 112;
          else
            v31 = 113;
          goto LABEL_98;
        }
        if ( v30 == 11 )
        {
          v31 = 114;
          goto LABEL_98;
        }
        if ( v30 == 12 )
        {
          v31 = 115;
          goto LABEL_98;
        }
      }
    }
    else
    {
      if ( v30 > 4 )
      {
        if ( v30 > 6 )
        {
          if ( v30 == 7 )
            v31 = 110;
          else
            v31 = 111;
        }
        else if ( v30 == 5 )
        {
          v31 = 108;
        }
        else
        {
          v31 = 109;
        }
        goto LABEL_98;
      }
      if ( v30 > 2 )
      {
        if ( v30 == 3 )
          v31 = 106;
        else
          v31 = 107;
        goto LABEL_98;
      }
      if ( v30 == 1 )
      {
        v31 = 103;
        goto LABEL_98;
      }
      if ( v30 == 2 )
      {
        v31 = 105;
LABEL_98:
        v58 = v28;
        LODWORD(v71) = v31;
        goto LABEL_99;
      }
    }
    v31 = 102;
    goto LABEL_98;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    256,
    1,
    "cam_icp_mgr_process_msg_frame_process",
    2822,
    "msg ptr is NULL");
  result = 4294967274LL;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
