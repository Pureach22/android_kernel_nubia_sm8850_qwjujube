__int64 __fastcall _cam_isp_ctx_reg_upd_in_sof(__int64 a1, __int64 *a2)
{
  __int64 v2; // x20
  __int64 result; // x0
  unsigned __int64 v4; // x1
  __int64 v5; // x19
  unsigned int *v6; // x19
  unsigned int **v7; // x8
  __int64 v8; // x21
  __int64 v9; // x9
  _DWORD *v10; // x8
  __int64 v11; // x2
  unsigned int *v12; // x1
  __int64 v13; // x0
  _DWORD *v14; // x19
  _DWORD *v15; // [xsp+28h] [xbp+18h]

  if ( !a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_reg_upd_in_sof",
      3938,
      "Invalid event data");
    return 4294967274LL;
  }
  v2 = *(_QWORD *)a1;
  if ( *(_DWORD *)(*(_QWORD *)a1 + 240LL) == 5 || *(_QWORD *)(a1 + 8) < 2u )
  {
    if ( *((_BYTE *)a2 + 16) != 1 )
      goto LABEL_15;
    v4 = *a2;
    if ( v4 == *(_QWORD *)(a1 + 37304) )
    {
      if ( (debug_mdl & 8) == 0 || debug_priority )
      {
LABEL_15:
        v6 = *(unsigned int **)(v2 + 160);
        if ( v6 == (unsigned int *)(v2 + 160) )
        {
          v14 = (_DWORD *)(a1 + 45564);
          if ( !*(_DWORD *)(a1 + 45568) )
            *v14 = 1;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            2,
            "__cam_isp_ctx_reg_upd_in_sof",
            3984,
            "Received a unserved rup ctx:%u link: 0x%x, last_applied_default:%d, unserved_rup:%d",
            *(_DWORD *)(v2 + 32),
            *(_DWORD *)(v2 + 64),
            *(_DWORD *)(a1 + 45568),
            *v14);
          v14[1] = 0;
          return 0;
        }
        v7 = *((unsigned int ***)v6 + 1);
        v8 = a1;
        if ( *v7 == v6 && (v9 = *(_QWORD *)v6, *(unsigned int **)(*(_QWORD *)v6 + 8LL) == v6) )
        {
          *(_QWORD *)(v9 + 8) = v7;
          *v7 = (unsigned int *)v9;
        }
        else
        {
          _list_del_entry_valid_or_report(*(_QWORD *)(v2 + 160));
        }
        *(_QWORD *)v6 = v6;
        *((_QWORD *)v6 + 1) = v6;
        cam_smmu_buffer_tracker_putref(v6 + 28);
        v10 = *((_DWORD **)v6 + 4);
        if ( v10[8] != v10[13] )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "__cam_isp_ctx_reg_upd_in_sof",
            3975,
            "receive rup in unexpected state, ctx_idx: %u, link: 0x%x",
            *(_DWORD *)(v2 + 32),
            *(_DWORD *)(v2 + 64));
          v13 = v8;
          if ( !v6 )
            return 0;
LABEL_33:
          _cam_isp_ctx_update_state_monitor_array(v13, 2, *((_QWORD *)v6 + 3));
          return 0;
        }
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          v15 = *((_DWORD **)v6 + 4);
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "__cam_isp_ctx_move_req_to_free_list",
            1404,
            "Free req id: %lld, packet: 0x%x, ctx_idx: %u, link: 0x%x",
            *((_QWORD *)v6 + 3),
            *((_QWORD *)v6 + 17),
            *(_DWORD *)(v2 + 32),
            *(_DWORD *)(v2 + 64));
          v10 = v15;
          if ( !*((_QWORD *)v6 + 17) )
            goto LABEL_24;
        }
        else if ( !*((_QWORD *)v6 + 17) )
        {
LABEL_24:
          v11 = v2 + 176;
          v12 = *(unsigned int **)(v2 + 184);
          if ( (unsigned int *)(v2 + 176) == v6 || v12 == v6 || *(_QWORD *)v12 != v11 )
          {
            _list_add_valid_or_report(v6);
            v13 = v8;
            if ( !v6 )
              return 0;
          }
          else
          {
            *(_QWORD *)(v2 + 184) = v6;
            *(_QWORD *)v6 = v11;
            *((_QWORD *)v6 + 1) = v12;
            *(_QWORD *)v12 = v6;
            v13 = v8;
            if ( !v6 )
              return 0;
          }
          goto LABEL_33;
        }
        cam_mem_put_kref(v10[1082]);
        cam_common_mem_free(*((_QWORD *)v6 + 17));
        *((_QWORD *)v6 + 17) = 0;
        goto LABEL_24;
      }
      v5 = a1;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "__cam_isp_ctx_reg_upd_in_sof",
        3957,
        "SOF timestamp is updated at early time, qtimer: [%llu:%09llu], boot: [%llu:%09llu]",
        v4 / 0x3B9ACA00,
        v4 % 0x3B9ACA00,
        *(_QWORD *)(a1 + 37312) / 0x3B9ACA00uLL,
        *(_QWORD *)(a1 + 37312) % 0x3B9ACA00uLL);
    }
    else
    {
      v5 = a1;
      _cam_isp_ctx_update_sof_ts();
    }
    a1 = v5;
    goto LABEL_15;
  }
  result = 0;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "__cam_isp_ctx_reg_upd_in_sof",
      3943,
      "invalid RUP");
    return 0;
  }
  return result;
}
