__int64 __fastcall _cam_isp_ctx_reg_upd_in_applied_state(unsigned __int64 *a1, __int64 *a2)
{
  unsigned __int64 v2; // x24
  unsigned int *v3; // x21
  unsigned int **v4; // x8
  _DWORD *v7; // x23
  __int64 v8; // x9
  unsigned __int64 v9; // x2
  unsigned int *v10; // x1
  int v11; // w7
  __int64 v12; // x22
  unsigned __int64 v14; // x27
  __int64 v15; // x0
  unsigned __int64 *v16; // x8
  __int64 v17; // x9
  __int64 v18; // x22
  unsigned __int64 v19; // x2
  unsigned int *v20; // x1
  unsigned __int64 v21; // x1
  char v22; // w8
  unsigned __int64 v29; // x9
  unsigned __int64 v30; // x9

  v2 = *a1;
  v3 = *(unsigned int **)(*a1 + 160);
  if ( v3 != (unsigned int *)(*a1 + 160) )
  {
    v4 = *((unsigned int ***)v3 + 1);
    v7 = a1 + 4663;
    if ( *v4 == v3 && (v8 = *(_QWORD *)v3, *(unsigned int **)(*(_QWORD *)v3 + 8LL) == v3) )
    {
      *(_QWORD *)(v8 + 8) = v4;
      *v4 = (unsigned int *)v8;
    }
    else
    {
      _list_del_entry_valid_or_report(*(_QWORD *)(*a1 + 160));
    }
    *(_QWORD *)v3 = v3;
    *((_QWORD *)v3 + 1) = v3;
    if ( *(_DWORD *)(*((_QWORD *)v3 + 4) + 32LL) )
    {
      v9 = v2 + 128;
      v10 = *(unsigned int **)(v2 + 136);
      if ( v3 == (unsigned int *)(v2 + 128) || v3 == v10 || *(_QWORD *)v10 != v9 )
      {
        _list_add_valid_or_report(v3);
      }
      else
      {
        *(_QWORD *)(v2 + 136) = v3;
        *(_QWORD *)v3 = v9;
        *((_QWORD *)v3 + 1) = v10;
        *(_QWORD *)v10 = v3;
      }
      v11 = v7[4] + 1;
      v7[4] = v11;
      v12 = *((_QWORD *)v3 + 3);
      if ( (debug_mdl & 0x1000008) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x1000008,
          4,
          "__cam_isp_ctx_reg_upd_in_applied_state",
          3652,
          "move request %lld to active list(cnt = %d), ctx %u, link: 0x%x",
          *((_QWORD *)v3 + 3),
          v11,
          *(_DWORD *)(v2 + 32),
          *(_DWORD *)(v2 + 64));
        if ( a1 )
        {
LABEL_13:
          _X8 = a1 + 5267;
          __asm { PRFM            #0x11, [X8] }
          do
          {
            v29 = __ldxr(_X8);
            v30 = v29 + 1;
          }
          while ( __stlxr(v30, _X8) );
          __dmb(0xBu);
          v14 = v30 & 7;
          v15 = ktime_get_with_offset(1);
          v16 = &a1[8 * v14];
          if ( v3 )
          {
            v17 = *((_QWORD *)v3 + 4);
            v16[5462] = *((_QWORD *)v3 + 3);
            *(_QWORD *)(v17 + 4480) = v15;
          }
          else
          {
            v16[5462] = 0;
          }
          v16[5463] = v15;
          goto LABEL_31;
        }
      }
      else if ( a1 )
      {
        goto LABEL_13;
      }
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        1,
        "__cam_isp_ctx_update_event_record",
        98,
        "Invalid Args");
      if ( !a2 )
        goto LABEL_41;
LABEL_32:
      if ( *((_BYTE *)a2 + 16) == 1 )
      {
        v21 = *a2;
        if ( *a2 == *(_QWORD *)v7 )
        {
          if ( (debug_mdl & 8) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "__cam_isp_ctx_reg_upd_in_applied_state",
              3674,
              "SOF timestamp is updated at early time, qtimer: [%llu:%09llu], boot: [%llu:%09llu]",
              v21 / 0x3B9ACA00,
              v21 % 0x3B9ACA00,
              *((_QWORD *)v7 + 1) / 0x3B9ACA00uLL,
              *((_QWORD *)v7 + 1) % 0x3B9ACA00uLL);
        }
        else
        {
          _cam_isp_ctx_update_sof_ts(a1, v21, a2[1]);
        }
      }
LABEL_41:
      v22 = debug_mdl;
      *((_DWORD *)a1 + 5) = 2;
      if ( (v22 & 8) != 0 && !debug_priority )
      {
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v22 & 8,
          4,
          "__cam_isp_ctx_reg_upd_in_applied_state",
          3684,
          "next Substate[%s], ctx %u, link: 0x%x",
          "EPOCH",
          *(_DWORD *)(v2 + 32),
          *(_DWORD *)(v2 + 64));
        if ( !v12 )
          goto LABEL_45;
      }
      else if ( !v12 )
      {
LABEL_45:
        _cam_isp_ctx_send_sof_timestamp(a1, v12, 0);
        _cam_isp_ctx_update_state_monitor_array((__int64)a1, 2, v12);
        return 0;
      }
      *((_QWORD *)v7 + 3) = v12;
      goto LABEL_45;
    }
    cam_smmu_buffer_tracker_putref(v3 + 28);
    v18 = *((_QWORD *)v3 + 4);
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "__cam_isp_ctx_move_req_to_free_list",
        1404,
        "Free req id: %lld, packet: 0x%x, ctx_idx: %u, link: 0x%x",
        *((_QWORD *)v3 + 3),
        *((_QWORD *)v3 + 17),
        *(_DWORD *)(v2 + 32),
        *(_DWORD *)(v2 + 64));
      if ( !*((_QWORD *)v3 + 17) )
      {
LABEL_21:
        v19 = v2 + 176;
        v20 = *(unsigned int **)(v2 + 184);
        if ( (unsigned int *)(v2 + 176) == v3 || v20 == v3 || *(_QWORD *)v20 != v19 )
        {
          _list_add_valid_or_report(v3);
        }
        else
        {
          *(_QWORD *)(v2 + 184) = v3;
          *(_QWORD *)v3 = v19;
          *((_QWORD *)v3 + 1) = v20;
          *(_QWORD *)v20 = v3;
        }
        v12 = 0;
        if ( (debug_mdl & 8) == 0 || debug_priority )
        {
LABEL_31:
          if ( !a2 )
            goto LABEL_41;
          goto LABEL_32;
        }
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "__cam_isp_ctx_reg_upd_in_applied_state",
          3661,
          "move active request %lld to free list(cnt = %d), ctx %u, link: 0x%x",
          *((_QWORD *)v3 + 3),
          v7[4],
          *(_DWORD *)(v2 + 32),
          *(_DWORD *)(v2 + 64));
        v12 = 0;
        if ( !a2 )
          goto LABEL_41;
        goto LABEL_32;
      }
    }
    else if ( !*((_QWORD *)v3 + 17) )
    {
      goto LABEL_21;
    }
    cam_mem_put_kref(*(_DWORD *)(v18 + 4328));
    cam_common_mem_free(*((_QWORD *)v3 + 17));
    *((_QWORD *)v3 + 17) = 0;
    goto LABEL_21;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    1,
    "__cam_isp_ctx_reg_upd_in_applied_state",
    3638,
    "Reg upd ack with no waiting request, ctx_idx: %u, link: 0x%x",
    *(_DWORD *)(v2 + 32),
    *(_DWORD *)(v2 + 64));
  return 0;
}
