__int64 __fastcall cam_icp_mgr_release_hw(__int64 a1, _BYTE *a2)
{
  __int64 v2; // x27
  __int64 *v5; // x20
  _DWORD *v6; // x25
  __int64 *v7; // x22
  _DWORD *v8; // x26
  __int64 v9; // x21
  __int64 *v10; // x23
  unsigned int v11; // w20
  __int64 v12; // x23
  __int64 *v13; // x21
  __int16 v14; // w8
  __int64 v15; // x9
  __int64 v17; // x8
  int v18; // w10
  const char *v19; // x7
  unsigned __int64 v25; // x10
  __int64 *v26; // x26
  _DWORD *v27; // x8
  __int64 v28; // x0
  unsigned int *v29; // x26
  unsigned int v30; // w7
  __int64 i; // x21
  unsigned int v32; // w7
  __int64 v33; // x8
  unsigned __int64 v36; // x12
  _QWORD *v37; // x0
  __int64 v38; // x8
  unsigned int v39; // w10
  unsigned int v40; // w9
  unsigned int v41; // w9
  _QWORD *v42; // x0
  __int64 v43; // x8
  _QWORD *v44; // x0
  _QWORD *v45; // x1
  _QWORD *v46; // x0
  __int16 v47; // w8
  __int64 v48; // x21
  _QWORD *v49; // x0
  _QWORD *v50; // x0
  unsigned int v51; // w8
  unsigned int v52; // w8
  __int64 v53; // x12
  __int64 v54; // x13
  unsigned int v55; // w9
  unsigned int j; // w21
  __int64 v57; // x23
  unsigned __int64 v60; // x10
  __int64 *v61; // x26
  _DWORD *v62; // x8
  __int64 v63; // x0
  unsigned int v64; // w7
  __int64 v66; // [xsp+10h] [xbp-100h]
  unsigned int v67; // [xsp+18h] [xbp-F8h]
  __int64 v68; // [xsp+20h] [xbp-F0h]
  __int64 *v69; // [xsp+28h] [xbp-E8h]
  int v70; // [xsp+34h] [xbp-DCh] BYREF
  __int64 *v71; // [xsp+38h] [xbp-D8h] BYREF
  __int64 v72; // [xsp+40h] [xbp-D0h]
  __int64 v73; // [xsp+48h] [xbp-C8h] BYREF
  __int64 v74; // [xsp+50h] [xbp-C0h]
  __int64 v75; // [xsp+58h] [xbp-B8h]
  __int64 v76; // [xsp+60h] [xbp-B0h]
  __int64 v77; // [xsp+68h] [xbp-A8h]
  __int64 v78; // [xsp+70h] [xbp-A0h]
  __int64 v79; // [xsp+78h] [xbp-98h]
  __int64 v80; // [xsp+80h] [xbp-90h]
  __int64 v81; // [xsp+88h] [xbp-88h]
  __int64 v82; // [xsp+90h] [xbp-80h]
  __int64 v83; // [xsp+98h] [xbp-78h]
  __int64 v84; // [xsp+A0h] [xbp-70h]
  __int64 v85; // [xsp+A8h] [xbp-68h]
  __int64 v86; // [xsp+B0h] [xbp-60h]
  __int64 v87; // [xsp+B8h] [xbp-58h]
  __int64 v88; // [xsp+C0h] [xbp-50h]
  __int64 v89; // [xsp+C8h] [xbp-48h]
  __int64 v90; // [xsp+D0h] [xbp-40h]
  __int64 v91; // [xsp+D8h] [xbp-38h]
  __int64 v92; // [xsp+E0h] [xbp-30h]
  __int64 v93; // [xsp+E8h] [xbp-28h]
  __int64 v94; // [xsp+F0h] [xbp-20h]
  __int64 v95; // [xsp+F8h] [xbp-18h]
  __int64 v96; // [xsp+100h] [xbp-10h]

  v96 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v70 = 256;
  if ( !a1 || !a2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_release_hw",
      8140,
      "Invalid args: %pK %pK",
      a2,
      (const void *)a1);
    v11 = -22;
    goto LABEL_111;
  }
  v5 = *(__int64 **)a2;
  if ( !*(_QWORD *)a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_release_hw",
      8150,
      "NULL ctx data");
    v11 = -22;
    goto LABEL_111;
  }
  v6 = (_DWORD *)(a1 + 40960);
  v7 = v5 + 3584;
  v8 = &unk_393000;
  if ( (debug_mdl & 0x100) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x100,
      4,
      "cam_icp_mgr_release_hw",
      8155,
      "%s: Enter recovery set %d",
      (const char *)v5 + 29824,
      *(_DWORD *)(a1 + 44148));
  mutex_lock(*(_QWORD *)(a1 + 88) + 48LL * *((unsigned int *)v5 + 7306));
  if ( *((_DWORD *)v5 + 26) == 2 )
  {
    mutex_unlock(*(_QWORD *)(a1 + 88) + 48LL * *((unsigned int *)v5 + 7306));
    mutex_lock(a1);
    if ( *(_DWORD *)(a1 + 44148) || a2[8] != 1 )
    {
      mutex_unlock(a1);
    }
    else
    {
      mutex_unlock(a1);
      cam_icp_mgr_abort_handle(v5);
      v71 = nullptr;
      v72 = 0;
      v94 = 0;
      v95 = 0;
      v92 = 0;
      v93 = 0;
      v90 = 0;
      v91 = 0;
      v88 = 0;
      v89 = 0;
      v87 = 0;
      v85 = 0;
      v86 = 0;
      v83 = 0;
      v84 = 0;
      v81 = 0;
      v82 = 0;
      v79 = 0;
      v80 = 0;
      v77 = 0;
      v78 = 0;
      v75 = 0;
      v76 = 0;
      v73 = 0;
      v74 = 0;
      v68 = v5[1];
      mutex_lock(*(_QWORD *)(v68 + 88) + 48LL * *((unsigned int *)v5 + 7306));
      v9 = 0;
      v10 = v5 + 563;
      v2 = 1;
      LODWORD(v95) = 113;
      LODWORD(v72) = 2;
      do
      {
        v61 = &v10[v9 - 340];
        if ( *v61 )
        {
          v94 = *v61;
          v71 = &v73;
          v62 = (_DWORD *)v5[12];
          v63 = *v5;
          if ( *(v62 - 1) != 414296116 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD, __int64 **))v62)(v63, 0, &v71);
          *v61 = 0;
          v64 = *((_DWORD *)v10 + v9);
          if ( v64 )
          {
            if ( (debug_mdl & 0x100) != 0 && !debug_priority )
            {
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64 *))cam_print_log)(
                3,
                debug_mdl & 0x100,
                4,
                "cam_icp_mgr_send_abort_status",
                7486,
                "%s: Delete merged sync in object: %d",
                v5 + 3728);
              v64 = *((_DWORD *)v10 + v9);
            }
            cam_sync_destroy(v64);
            *((_DWORD *)v10 + v9) = 0;
          }
          _X8 = (unsigned __int64 *)v5[215];
          __asm { PRFM            #0x11, [X8] }
          do
            v60 = __ldxr(_X8);
          while ( __stxr(v60 & ~(1LL << v9), _X8) );
        }
        ++v9;
      }
      while ( v9 != 40 );
      v7 = v5 + 3584;
      mutex_unlock(*(_QWORD *)(v68 + 88) + 48LL * *((unsigned int *)v5 + 7306));
      v8 = &unk_393000;
    }
    v12 = 33554688;
    mutex_lock(a1);
    v13 = (__int64 *)*((int *)v7 + 138);
    mutex_lock(*(_QWORD *)(a1 + 88) + 48LL * (int)v13);
    if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64 *))cam_print_log)(
        3,
        debug_mdl & 0x2000100,
        4,
        "cam_icp_mgr_release_ctx",
        5151,
        "Avg response time on %s: total_processed_requests: %llu avg_time: %llums",
        v5 + 3728);
    v5[3749] = 0;
    v5[3748] = 0;
    v5[3747] = 0;
    v5[3746] = 0;
    cam_icp_remove_ctx_bw(a1, v5);
    if ( *((_DWORD *)v5 + 26) == 2 )
    {
      cam_icp_mgr_dev_power_collapse(a1, v5);
      v14 = debug_mdl;
      *((_DWORD *)v5 + 26) = 3;
      if ( (v14 & 0x100) != 0 && !debug_priority )
      {
        if ( *(_DWORD *)(a1 + 44148) )
          v19 = "Y";
        else
          v19 = "N";
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v14 & 0x100,
          4,
          "cam_icp_mgr_release_ctx",
          5169,
          "%s: E: Recovery: %s",
          (const char *)v5 + 29824,
          v19);
      }
      v69 = v7;
      cam_icp_mgr_abort_handle(v5);
      cam_icp_mgr_destroy_handle(v5);
      if ( *(_DWORD *)(v5[10] + 16) == 1 )
      {
        _X8 = *(unsigned int *)(v5[2] + 8);
        if ( (unsigned int)_X8 >= 6 )
        {
          __break(0x5512u);
          goto LABEL_37;
        }
        v17 = a1 + 4 * _X8;
        v18 = *(_DWORD *)(v17 + 44240) - 1;
        *(_DWORD *)(v17 + 44240) = v18;
        if ( !v18 )
          cam_icp_handle_secure_port_config(v5, 1);
      }
      v68 = a1 + 40960;
      v6 = &unk_393000;
      v66 = (unsigned int)v13;
      v67 = (unsigned int)v13;
      v7 = nullptr;
      v13 = v5 + 603;
      v2 = 1;
      v12 = (__int64)&v73;
      v71 = nullptr;
      v72 = 0;
      v94 = 0;
      v95 = 0;
      v92 = 0;
      v93 = 0;
      v90 = 0;
      v91 = 0;
      v88 = 0;
      v89 = 0;
      v87 = 0;
      v85 = 0;
      v86 = 0;
      v83 = 0;
      v84 = 0;
      v81 = 0;
      v82 = 0;
      v79 = 0;
      v80 = 0;
      v77 = 0;
      v78 = 0;
      v75 = 0;
      v76 = 0;
      v73 = 0;
      v74 = 0;
      do
      {
        v26 = &v13[(_QWORD)v7 - 380];
        if ( *v26 )
        {
          v94 = *v26;
          LODWORD(v72) = v2;
          v27 = (_DWORD *)v5[12];
          v71 = (__int64 *)v12;
          v28 = *v5;
          if ( *(v27 - 1) != 414296116 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD, __int64 **))v27)(v28, 0, &v71);
          *v26 = 0;
          v29 = (unsigned int *)v13 + (_QWORD)v7 - 80;
          v30 = *v29;
          if ( *v29 )
          {
            if ( (debug_mdl & 0x100) != 0 && !v6[919] )
            {
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64 *))cam_print_log)(
                3,
                debug_mdl & 0x100,
                4,
                "cam_icp_mgr_cleanup_ctx",
                2402,
                "%s: Delete merged sync in object: %d",
                v5 + 3728);
              v30 = *v29;
            }
            cam_sync_destroy(v30);
            *v29 = 0;
          }
          _X8 = v5[215];
          v15 = v2 << (char)v7;
          *((_BYTE *)v7 + (_QWORD)v13) = 0;
LABEL_37:
          __asm { PRFM            #0x11, [X8] }
          do
            v25 = __ldxr((unsigned __int64 *)_X8);
          while ( __stxr(v25 & ~v15, (unsigned __int64 *)_X8) );
        }
        v7 = (__int64 *)((char *)v7 + 1);
      }
      while ( v7 != &qword_28 );
      v8 = v6;
      v6 = (_DWORD *)v68;
      for ( i = 1166; i != 1206; ++i )
      {
        v32 = *((_DWORD *)v5 + i);
        if ( v32 )
        {
          if ( (debug_mdl & 0x100) != 0 && !v8[919] )
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64 *))cam_print_log)(
              3,
              debug_mdl & 0x100,
              4,
              "cam_icp_mgr_cleanup_ctx",
              2417,
              "%s: Delete merged sync in object: %d",
              v5 + 3728);
            v32 = *((_DWORD *)v5 + i);
          }
          cam_sync_destroy(v32);
          *((_DWORD *)v5 + i) = 0;
        }
      }
      *((_BYTE *)v69 + 1328) = 0;
      cam_icp_cpas_deactivate_llcc(v5);
      v33 = 0;
      v5[9] = 0;
      v5[3727] = 0;
      do
      {
        _X10 = (unsigned __int64 *)v5[215];
        __asm { PRFM            #0x11, [X10] }
        do
          v36 = __ldxr(_X10);
        while ( __stxr(v36 & ~(1LL << v33), _X10) );
        ++v33;
      }
      while ( v33 != 40 );
      v37 = (_QWORD *)v5[215];
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v37, 0);
      else
        kvfree(v37);
      v38 = v5[2];
      v5[215] = 0;
      v39 = *((_DWORD *)v69 + 142);
      v40 = *(_DWORD *)(v38 + 24);
      _CF = v40 >= v39;
      v41 = v40 - v39;
      if ( _CF )
        *(_DWORD *)(v38 + 24) = v41;
      *((_DWORD *)v69 + 140) = 0;
      *((_DWORD *)v69 + 142) = 0;
      --*(_DWORD *)(v68 + 3120);
      v42 = (_QWORD *)v5[10];
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v42, 0);
      else
        kvfree(v42);
      v43 = v5[3725];
      v5[10] = 0;
      if ( v43 )
      {
        if ( (debug_mdl & 0x2000100) != 0 && !v8[919] )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x2000100,
            4,
            "cam_icp_ctx_timer_stop",
            1013,
            "%s: stop timer",
            (const char *)v5 + 29824);
        *((_DWORD *)v69 + 284) = 0;
        crm_timer_exit((const void **)v5 + 3725);
        v5[3725] = 0;
      }
      v44 = (_QWORD *)v5[3772];
      v45 = (_QWORD *)v5[3773];
      v5[1] = 0;
      v46 = cam_packet_util_put_unique_tbl(v44, v45);
      v47 = debug_mdl;
      v5[3773] = 0;
      v5[3772] = 0;
      if ( (v47 & 0x100) != 0 && !v8[919] )
        v46 = (_QWORD *)((__int64 (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                          3,
                          v47 & 0x100,
                          4,
                          "cam_icp_mgr_release_ctx",
                          5206,
                          "[%s] X: ctx_id = %d",
                          (const char *)(a1 + 112),
                          *((_DWORD *)v69 + 138));
      v48 = v66;
      if ( (cam_presil_mode_enabled(v46) & 1) != 0 )
      {
        v48 = v67;
        v49 = *(_QWORD **)(*(_QWORD *)(*(_QWORD *)(a1 + 96) + 8LL * v67) + 29184LL);
        if ( mem_trace_en == 1 )
          cam_mem_trace_free(v49, 0);
        else
          kvfree(v49);
        *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 96) + 8LL * v67) + 29184LL) = 0;
      }
      v50 = *(_QWORD **)(*(_QWORD *)(a1 + 96) + 8 * v48);
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v50, 0);
      else
        kvfree(v50);
      *(_QWORD *)(*(_QWORD *)(a1 + 96) + 8 * v48) = 0;
      mutex_unlock(*(_QWORD *)(a1 + 88) + 48LL * (int)v67);
    }
    else
    {
      mutex_unlock(*(_QWORD *)(a1 + 88) + 48LL * (int)v13);
      if ( (debug_mdl & 0x100) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x100,
          4,
          "cam_icp_mgr_release_ctx",
          5161,
          "%s: Not in right state to release: %d",
          (const char *)v5 + 29824,
          *((_DWORD *)v5 + 26));
    }
    if ( v6[780] )
    {
      v11 = 0;
      v51 = *(_DWORD *)(a1 + 64);
      if ( !v51 )
      {
LABEL_108:
        mutex_unlock(a1);
        if ( (debug_mdl & 0x100) != 0 && !v8[919] )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x100,
            4,
            "cam_icp_mgr_release_hw",
            8195,
            "[%s] Release done.",
            (const char *)(a1 + 112));
        goto LABEL_111;
      }
    }
    else
    {
      v6[804] = 0;
      if ( (debug_mdl & 0x100) != 0 && !v8[919] )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x100,
          4,
          "cam_icp_mgr_release_hw",
          8180,
          "[%s] Last Release",
          (const char *)(a1 + 112));
      cam_icp_mgr_icp_power_collapse(a1, &v70);
      if ( *(_DWORD *)(a1 + 64) )
      {
        v52 = 0;
        do
        {
          v53 = *(_QWORD *)(a1 + 56) + 584LL * (int)v52++;
          *(_DWORD *)(v53 + 24) = 0;
          v54 = *((_QWORD *)v6 + 400);
          *(_QWORD *)(v53 + 36) = 5;
          *(_QWORD *)(v53 + 48) = 1024;
          *(_QWORD *)(v53 + 56) = 1024;
          *(_DWORD *)(v53 + 28) = v54;
        }
        while ( v52 < *(_DWORD *)(a1 + 64) );
      }
      *((_QWORD *)v6 + 393) = *((_QWORD *)v6 + 400);
      v11 = cam_icp_device_deint(a1);
      v51 = *(_DWORD *)(a1 + 64);
      if ( !v51 )
        goto LABEL_108;
    }
    v55 = 0;
    while ( !*(_DWORD *)(*(_QWORD *)(a1 + 56) + 584LL * (int)v55 + 576) )
    {
      if ( v51 == ++v55 )
      {
        v55 = v51;
        break;
      }
    }
    if ( v55 == v51 )
    {
      for ( j = 0; j < v51; ++j )
      {
        v57 = *(_QWORD *)(a1 + 56) + 584LL * (int)j;
        if ( !*(_DWORD *)(v57 + 576) && *(_QWORD *)(v57 + 552) )
        {
          *(_DWORD *)(v57 + 560) = 0;
          crm_timer_exit((const void **)(v57 + 552));
          *(_QWORD *)(v57 + 552) = 0;
          v51 = *(_DWORD *)(a1 + 64);
        }
      }
    }
    goto LABEL_108;
  }
  if ( (debug_mdl & 0x100) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x100,
      4,
      "cam_icp_mgr_release_hw",
      8160,
      "%s: is not acquired",
      (const char *)v5 + 29824);
  mutex_unlock(*(_QWORD *)(a1 + 88) + 48LL * *((unsigned int *)v5 + 7306));
  v11 = -22;
LABEL_111:
  _ReadStatusReg(SP_EL0);
  return v11;
}
