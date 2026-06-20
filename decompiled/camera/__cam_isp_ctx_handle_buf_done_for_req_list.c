__int64 __fastcall _cam_isp_ctx_handle_buf_done_for_req_list(__int64 a1, unsigned int *a2)
{
  __int64 v2; // x28
  __int64 v3; // x26
  __int64 v4; // x27
  __int64 v8; // x11
  unsigned __int64 v9; // x21
  unsigned int **v10; // x8
  __int64 v11; // x9
  unsigned int *v12; // x1
  unsigned int *v13; // x2
  unsigned int v14; // w22
  __int64 v15; // x1
  unsigned int **v16; // x8
  __int64 v17; // x9
  unsigned __int64 v18; // x23
  __int64 v19; // x21
  _DWORD *v20; // x10
  __int64 v21; // x2
  unsigned int *v22; // x1
  int v23; // w8
  __int64 v24; // x8
  __int64 v25; // x24
  _QWORD *v26; // x23
  __int64 v27; // x1
  unsigned __int64 v28; // x27
  __int64 v29; // x21
  __int64 v30; // x6
  __int64 v31; // x7
  int v32; // w8
  __int64 v33; // x4
  __int64 v34; // x23
  __int64 v35; // x1
  int v36; // w8
  __int64 v37; // x22
  __int64 v38; // x23
  unsigned int v39; // w0
  signed int v40; // w8
  unsigned __int64 v41; // x21
  __int64 v42; // x0
  __int64 v43; // x8
  __int64 v44; // x9
  __int64 v46; // x21
  __int64 v47; // x2
  unsigned int *v48; // x1
  _QWORD *v49; // x8
  __int64 v50; // x9
  _QWORD *v51; // x1
  _QWORD *v52; // x2
  __int64 v53; // x6
  __int64 v54; // x6
  unsigned __int64 v60; // x8
  unsigned __int64 v61; // x8
  unsigned __int64 v62; // [xsp+18h] [xbp-8h]

  v2 = *((_QWORD *)a2 + 4);
  v3 = a1 + 37304;
  v4 = *(_QWORD *)a1;
  _X25 = a1 + 42144;
  v8 = 16777224;
  --*(_DWORD *)(a1 + 37320);
  v9 = *((_QWORD *)a2 + 3);
  if ( *(_BYTE *)(v2 + 4504) == 1 && *(_DWORD *)(v2 + 72) )
  {
    *(_QWORD *)(v2 + 52) = 0;
    *(_BYTE *)(v2 + 4504) = 0;
    v10 = *((unsigned int ***)a2 + 1);
    if ( *v10 == a2 && (v11 = *(_QWORD *)a2, *(unsigned int **)(*(_QWORD *)a2 + 8LL) == a2) )
    {
      *(_QWORD *)(v11 + 8) = v10;
      *v10 = (unsigned int *)v11;
    }
    else
    {
      _list_del_entry_valid_or_report(a2);
    }
    *(_QWORD *)a2 = a2;
    *((_QWORD *)a2 + 1) = a2;
    *(_DWORD *)(a1 + 24) = 0;
    *(_BYTE *)(v2 + 4505) = 0;
    *(_DWORD *)(v3 + 72) = 0;
    if ( v9 > *(unsigned int *)(v4 + 464) )
    {
      v12 = (unsigned int *)(v4 + 144);
      v13 = *(unsigned int **)(v4 + 144);
      if ( *((_QWORD *)v13 + 1) != v4 + 144 || v12 == a2 || v13 == a2 )
      {
        _list_add_valid_or_report(a2);
      }
      else
      {
        *((_QWORD *)v13 + 1) = a2;
        *(_QWORD *)a2 = v13;
        *((_QWORD *)a2 + 1) = v12;
        *(_QWORD *)v12 = a2;
      }
      v14 = 0;
      if ( (debug_mdl & v8) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & v8,
          4,
          "__cam_isp_ctx_handle_buf_done_for_req_list",
          2042,
          "Move active request %lld to pending list(cnt = %d) [bubble recovery], ctx %u, link: 0x%x",
          *((_QWORD *)a2 + 3),
          *(_DWORD *)(v3 + 16),
          *(_DWORD *)(v4 + 32),
          *(_DWORD *)(v4 + 64));
        v14 = 0;
      }
      goto LABEL_34;
    }
    v62 = v9;
    cam_smmu_buffer_tracker_putref(a2 + 28);
    if ( *(_DWORD *)(v2 + 32) )
    {
      v36 = 0;
      do
      {
        v37 = (__int64)v36 << 6;
        v38 = v36;
        v39 = cam_sync_signal(*(_DWORD *)(*(_QWORD *)(v2 + 24) + v37 + 16), 3u, 0x34u);
        v40 = *(_DWORD *)(*(_QWORD *)(v2 + 24) + v37 + 20);
        if ( v40 < 1 )
        {
          v14 = v39;
        }
        else
        {
          v14 = cam_sync_signal(v40, 3u, 0x34u);
          if ( v14 )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              1,
              "__cam_isp_ctx_handle_buf_done_for_req_list",
              2023,
              "Early sync=%d for req=%llu failed with rc=%d ctx:%u link[0x%x]",
              *(_DWORD *)(*(_QWORD *)(v2 + 24) + (v38 << 6) + 20),
              *((_QWORD *)a2 + 3),
              v14,
              *(_DWORD *)(v4 + 32),
              *(_DWORD *)(v4 + 64));
          *(_DWORD *)(*(_QWORD *)(v2 + 24) + (v38 << 6) + 20) = -1;
        }
        v36 = v38 + 1;
      }
      while ( (unsigned int)(v38 + 1) < *(_DWORD *)(v2 + 32) );
    }
    else
    {
      v14 = 0;
    }
    v46 = *((_QWORD *)a2 + 4);
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "__cam_isp_ctx_move_req_to_free_list",
        1404,
        "Free req id: %lld, packet: 0x%x, ctx_idx: %u, link: 0x%x",
        *((_QWORD *)a2 + 3),
        *((_QWORD *)a2 + 17),
        *(_DWORD *)(v4 + 32),
        *(_DWORD *)(v4 + 64));
      if ( !*((_QWORD *)a2 + 17) )
      {
LABEL_67:
        v47 = v4 + 176;
        v48 = *(unsigned int **)(v4 + 184);
        if ( (unsigned int *)(v4 + 176) == a2 || v48 == a2 || *(_QWORD *)v48 != v47 )
        {
          _list_add_valid_or_report(a2);
        }
        else
        {
          *(_QWORD *)(v4 + 184) = a2;
          *(_QWORD *)a2 = v47;
          *((_QWORD *)a2 + 1) = v48;
          *(_QWORD *)v48 = a2;
        }
        v9 = v62;
        if ( (debug_mdl & 0x1000008) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x1000008,
            4,
            "__cam_isp_ctx_handle_buf_done_for_req_list",
            2035,
            "Move active request %lld to free list(cnt = %d) [flushed], ctx %u, link: 0x%x",
            v62,
            *(_DWORD *)(v3 + 16),
            *(_DWORD *)(v4 + 32),
            *(_DWORD *)(v4 + 64));
        *(_QWORD *)(_X25 + 3464) = 0;
        goto LABEL_34;
      }
    }
    else if ( !*((_QWORD *)a2 + 17) )
    {
      goto LABEL_67;
    }
    cam_mem_put_kref(*(_DWORD *)(v46 + 4328));
    cam_common_mem_free(*((_QWORD *)a2 + 17));
    *((_QWORD *)a2 + 17) = 0;
    goto LABEL_67;
  }
  if ( (*(_BYTE *)(a1 + 45744) & 1) == 0 && *(_QWORD *)(a1 + 37328) < v9 )
  {
    v15 = *((_QWORD *)a2 + 3);
    *(_QWORD *)(a1 + 37328) = v9;
    _cam_isp_ctx_send_sof_timestamp(a1, v15, 0);
    *(_QWORD *)(v3 + 64) = *(_QWORD *)v3;
  }
  v16 = *((unsigned int ***)a2 + 1);
  if ( *v16 == a2 && (v17 = *(_QWORD *)a2, *(unsigned int **)(*(_QWORD *)a2 + 8LL) == a2) )
  {
    v18 = v9;
    *(_QWORD *)(v17 + 8) = v16;
    *v16 = (unsigned int *)v17;
  }
  else
  {
    v18 = v9;
    _list_del_entry_valid_or_report(a2);
  }
  *(_QWORD *)a2 = a2;
  *((_QWORD *)a2 + 1) = a2;
  cam_smmu_buffer_tracker_putref(a2 + 28);
  v19 = *((_QWORD *)a2 + 4);
  v20 = &unk_393000;
  if ( (debug_mdl & 8) == 0 || debug_priority )
  {
    if ( !*((_QWORD *)a2 + 17) )
      goto LABEL_24;
    goto LABEL_23;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 8,
    4,
    "__cam_isp_ctx_move_req_to_free_list",
    1404,
    "Free req id: %lld, packet: 0x%x, ctx_idx: %u, link: 0x%x",
    *((_QWORD *)a2 + 3),
    *((_QWORD *)a2 + 17),
    *(_DWORD *)(v4 + 32),
    *(_DWORD *)(v4 + 64));
  v20 = &unk_393000;
  if ( *((_QWORD *)a2 + 17) )
  {
LABEL_23:
    cam_mem_put_kref(*(_DWORD *)(v19 + 4328));
    cam_common_mem_free(*((_QWORD *)a2 + 17));
    v20 = &unk_393000;
    *((_QWORD *)a2 + 17) = 0;
  }
LABEL_24:
  v21 = v4 + 176;
  v22 = *(unsigned int **)(v4 + 184);
  if ( (unsigned int *)(v4 + 176) == a2 || v22 == a2 || *(_QWORD *)v22 != v21 )
  {
    _list_add_valid_or_report(a2);
  }
  else
  {
    *(_QWORD *)(v4 + 184) = a2;
    *(_QWORD *)a2 = v21;
    *((_QWORD *)a2 + 1) = v22;
    *(_QWORD *)v22 = a2;
  }
  v23 = *(unsigned __int8 *)(v2 + 4504);
  v9 = v18;
  *(_DWORD *)(v2 + 4448) = 0;
  *(_BYTE *)(v2 + 4505) = 0;
  *(_QWORD *)(v2 + 52) = 0;
  if ( v23 == 1 )
  {
    *(_DWORD *)(a1 + 24) = 0;
    *(_DWORD *)(v3 + 72) = 0;
    *(_BYTE *)(v2 + 4504) = 0;
  }
  if ( (debug_mdl & 0x1000008) != 0 && !v20[919] )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x1000008,
      4,
      "__cam_isp_ctx_handle_buf_done_for_req_list",
      2076,
      "Move active request %lld to free list(cnt = %d) [all fences done], ctx %u link: 0x%x",
      v18,
      *(_DWORD *)(v3 + 16),
      *(_DWORD *)(v4 + 32),
      *(_DWORD *)(v4 + 64));
  v24 = *((_QWORD *)a2 + 3);
  v14 = 0;
  *(_QWORD *)(_X25 + 3464) = 0;
  *(_QWORD *)(v3 + 88) = v24;
LABEL_34:
  *(_DWORD *)(_X25 + 3420) = 0;
  if ( !*(_DWORD *)(_X25 + 3428) || *(_DWORD *)(v3 + 16) )
    goto LABEL_54;
  v25 = *(_QWORD *)a1;
  v26 = *(_QWORD **)(*(_QWORD *)a1 + 160LL);
  if ( v26 == (_QWORD *)(*(_QWORD *)a1 + 160LL) || (v27 = v26[3], v27 != *(_QWORD *)(v3 + 56)) )
  {
    v34 = *(_QWORD *)(v25 + 144);
    if ( v34 == v25 + 144 || (v35 = *(_QWORD *)(v34 + 24), v35 != *(_QWORD *)(v3 + 56)) )
    {
      *(_DWORD *)(_X25 + 3428) = 0;
      *(_DWORD *)(a1 + 24) = 0;
      *(_QWORD *)(v3 + 72) = 0;
      *(_DWORD *)(v3 + 84) = 0;
      *(_BYTE *)(_X25 + 3602) = 0;
    }
    else
    {
      v28 = v9;
      v29 = *(_QWORD *)(v34 + 32);
      if ( (unsigned int)_cam_isp_ctx_notify_error_util(7, v35, (__int64 *)a1) )
      {
        v30 = *(_QWORD *)(v34 + 24);
        v31 = *(unsigned int *)(v25 + 32);
        v32 = *(_DWORD *)(v25 + 64);
        v33 = 1963;
        goto LABEL_44;
      }
      v54 = *(_QWORD *)(v3 + 56);
      *(_DWORD *)(a1 + 20) = 3;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        3,
        "__cam_isp_context_try_internal_recovery",
        1971,
        "Internal recovery for req: %llu in ctx: %u on link: 0x%x triggered",
        v54,
        *(_DWORD *)(v25 + 32),
        *(_DWORD *)(v25 + 64));
      v9 = v28;
    }
  }
  else
  {
    v28 = v9;
    v29 = v26[4];
    if ( (unsigned int)_cam_isp_ctx_notify_error_util(7, v27, (__int64 *)a1) )
    {
      v30 = v26[3];
      v31 = *(unsigned int *)(v25 + 32);
      v32 = *(_DWORD *)(v25 + 64);
      v33 = 1930;
LABEL_44:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, int))cam_print_log)(
        3,
        8,
        2,
        "__cam_isp_context_try_internal_recovery",
        v33,
        "Unable to perform internal recovery [bubble reporting failed] for req: %llu in ctx: %u on link: 0x%x",
        v30,
        v31,
        v32);
      *(_DWORD *)(_X25 + 3428) = 0;
      *(_DWORD *)(a1 + 24) = 0;
      *(_QWORD *)(v3 + 72) = 0;
      *(_DWORD *)(v3 + 84) = 0;
      *(_BYTE *)(_X25 + 3602) = 0;
      *(_BYTE *)(v29 + 4504) = 0;
      v9 = v28;
      goto LABEL_54;
    }
    v49 = (_QWORD *)v26[1];
    if ( (_QWORD *)*v49 == v26 && (v50 = *v26, *(_QWORD **)(*v26 + 8LL) == v26) )
    {
      *(_QWORD *)(v50 + 8) = v49;
      *v49 = v50;
    }
    else
    {
      _list_del_entry_valid_or_report(v26);
    }
    *v26 = v26;
    v9 = v28;
    v26[1] = v26;
    v51 = (_QWORD *)(v25 + 144);
    v52 = *(_QWORD **)(v25 + 144);
    if ( v52[1] != v25 + 144 || v26 == v51 || v26 == v52 )
    {
      _list_add_valid_or_report(v26);
    }
    else
    {
      v52[1] = v26;
      *v26 = v52;
      v26[1] = v51;
      *v51 = v26;
    }
    v53 = *(_QWORD *)(v3 + 56);
    *(_DWORD *)(a1 + 20) = 3;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "__cam_isp_context_try_internal_recovery",
      1941,
      "Internal recovery for req: %llu in ctx: %u on link: 0x%x triggered",
      v53,
      *(_DWORD *)(v25 + 32),
      *(_DWORD *)(v25 + 64));
  }
LABEL_54:
  cam_cpas_notify_event((__int64)"IFE BufDone", v9);
  _cam_isp_ctx_update_state_monitor_array(a1, 5, v9);
  if ( a1 )
  {
    __asm { PRFM            #0x11, [X25] }
    do
    {
      v60 = __ldxr((unsigned __int64 *)_X25);
      v61 = v60 + 1;
    }
    while ( __stlxr(v61, (unsigned __int64 *)_X25) );
    __dmb(0xBu);
    v41 = v61 & 7;
    v42 = ktime_get_with_offset(1);
    v43 = a1 + (v41 << 6);
    if ( a2 )
    {
      v44 = *((_QWORD *)a2 + 4);
      *(_QWORD *)(v43 + 44208) = *((_QWORD *)a2 + 3);
      *(_QWORD *)(v44 + 4488) = v42;
    }
    else
    {
      *(_QWORD *)(v43 + 44208) = 0;
    }
    *(_QWORD *)(v43 + 44216) = v42;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_update_event_record",
      98,
      "Invalid Args");
  }
  return v14;
}
