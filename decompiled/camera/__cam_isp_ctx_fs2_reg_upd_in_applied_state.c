__int64 __fastcall _cam_isp_ctx_fs2_reg_upd_in_applied_state(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  __int64 v4; // x22
  unsigned __int64 v6; // x1
  unsigned int *v7; // x20
  unsigned int **v8; // x8
  __int64 v9; // x9
  __int64 v10; // x23
  __int64 v11; // x2
  unsigned int *v12; // x1
  int v13; // w7
  __int64 v14; // x8
  __int64 v15; // x2
  unsigned int *v16; // x1
  unsigned __int64 v17; // x1
  char v18; // w22
  const char *v20; // x0
  __int64 v21; // [xsp+28h] [xbp+18h]

  v2 = *(_QWORD *)a1;
  v4 = a1 + 36864;
  if ( a2 && *(_BYTE *)(a2 + 16) == 1 )
  {
    v6 = *(_QWORD *)a2;
    if ( v6 == *(_QWORD *)(a1 + 37304) )
    {
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "__cam_isp_ctx_fs2_reg_upd_in_applied_state",
          5219,
          "SOF timestamp is updated at early time, qtimer: [%llu:%09llu], boot: [%llu:%09llu]",
          v6 / 0x3B9ACA00,
          v6 % 0x3B9ACA00,
          *(_QWORD *)(a1 + 37312) / 0x3B9ACA00uLL,
          *(_QWORD *)(a1 + 37312) % 0x3B9ACA00uLL);
    }
    else
    {
      _cam_isp_ctx_update_sof_ts((__int64 *)a1, v6, *(_QWORD *)(a2 + 8));
    }
  }
  v7 = *(unsigned int **)(v2 + 160);
  if ( v7 == (unsigned int *)(v2 + 160) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_fs2_reg_upd_in_applied_state",
      5224,
      "Reg upd ack with no waiting request, ctx_idx: %u, link: 0x%x",
      *(_DWORD *)(v2 + 32),
      *(_DWORD *)(v2 + 64));
    return 0;
  }
  v8 = *((unsigned int ***)v7 + 1);
  if ( *v8 == v7 && (v9 = *(_QWORD *)v7, *(unsigned int **)(*(_QWORD *)v7 + 8LL) == v7) )
  {
    *(_QWORD *)(v9 + 8) = v8;
    *v8 = (unsigned int *)v9;
  }
  else
  {
    _list_del_entry_valid_or_report(*(_QWORD *)(v2 + 160));
  }
  *(_QWORD *)v7 = v7;
  *((_QWORD *)v7 + 1) = v7;
  v10 = *((_QWORD *)v7 + 4);
  if ( !*(_DWORD *)(v10 + 32) )
  {
    cam_smmu_buffer_tracker_putref(v7 + 28);
    v14 = *((_QWORD *)v7 + 4);
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v21 = *((_QWORD *)v7 + 4);
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "__cam_isp_ctx_move_req_to_free_list",
        1404,
        "Free req id: %lld, packet: 0x%x, ctx_idx: %u, link: 0x%x",
        *((_QWORD *)v7 + 3),
        *((_QWORD *)v7 + 17),
        *(_DWORD *)(v2 + 32),
        *(_DWORD *)(v2 + 64));
      v14 = v21;
      if ( !*((_QWORD *)v7 + 17) )
        goto LABEL_25;
    }
    else if ( !*((_QWORD *)v7 + 17) )
    {
LABEL_25:
      v15 = v2 + 176;
      v16 = *(unsigned int **)(v2 + 184);
      if ( (unsigned int *)(v2 + 176) == v7 || v16 == v7 || *(_QWORD *)v16 != v15 )
      {
        _list_add_valid_or_report(v7);
      }
      else
      {
        *(_QWORD *)(v2 + 184) = v7;
        *(_QWORD *)v7 = v15;
        *((_QWORD *)v7 + 1) = v16;
        *(_QWORD *)v16 = v7;
      }
      goto LABEL_29;
    }
    cam_mem_put_kref(*(_DWORD *)(v14 + 4328));
    cam_common_mem_free(*((_QWORD *)v7 + 17));
    *((_QWORD *)v7 + 17) = 0;
    goto LABEL_25;
  }
  v11 = v2 + 128;
  v12 = *(unsigned int **)(v2 + 136);
  if ( v7 == (unsigned int *)(v2 + 128) || v7 == v12 || *(_QWORD *)v12 != v11 )
  {
    _list_add_valid_or_report(v7);
  }
  else
  {
    *(_QWORD *)(v2 + 136) = v7;
    *(_QWORD *)v7 = v11;
    *((_QWORD *)v7 + 1) = v12;
    *(_QWORD *)v12 = v7;
  }
  v13 = *(_DWORD *)(v4 + 456) + 1;
  *(_DWORD *)(v4 + 456) = v13;
  if ( (debug_mdl & 0x1000008) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x1000008,
      4,
      "__cam_isp_ctx_fs2_reg_upd_in_applied_state",
      5237,
      "move request %lld to active list(cnt = %d), ctx:%u,link:0x%x",
      *((_QWORD *)v7 + 3),
      v13,
      *(_DWORD *)(v2 + 32),
      *(_DWORD *)(v2 + 64));
LABEL_29:
  *(_DWORD *)(a1 + 20) = 2;
  if ( *(_DWORD *)(v10 + 32) == 1 )
  {
    if ( *(int *)(v4 + 456) <= 2 )
    {
      v7 = (unsigned int *)(v2 + 128);
      while ( 1 )
      {
        v7 = *(unsigned int **)v7;
        if ( v7 == (unsigned int *)(v2 + 128) )
          break;
        v17 = *((_QWORD *)v7 + 3);
        if ( v17 > *(_QWORD *)(v4 + 464) )
        {
          *(_QWORD *)(v4 + 464) = v17;
          goto LABEL_36;
        }
      }
      v17 = 0;
LABEL_36:
      _cam_isp_ctx_send_sof_timestamp(a1, v17, 0);
      _cam_isp_ctx_notify_trigger_util(1, (__int64 *)a1);
    }
    v18 = debug_mdl;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v20 = _cam_isp_ctx_substate_val_to_type(*(_DWORD *)(a1 + 20));
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v18 & 8,
        4,
        "__cam_isp_ctx_fs2_reg_upd_in_applied_state",
        5269,
        "next Substate[%s], ctx_idx: %u, link: 0x%x",
        v20,
        *(_DWORD *)(v2 + 32),
        *(_DWORD *)(v2 + 64));
      if ( !v7 )
        return 0;
      goto LABEL_40;
    }
  }
  if ( v7 )
LABEL_40:
    _cam_isp_ctx_update_state_monitor_array(a1, 2, *((_QWORD *)v7 + 3));
  return 0;
}
