__int64 __fastcall _cam_isp_ctx_fs2_reg_upd_in_sof(__int64 *a1, __int64 a2)
{
  __int64 v2; // x21
  unsigned __int64 v5; // x1
  unsigned int *v6; // x20
  unsigned int **v7; // x8
  __int64 v8; // x9
  _DWORD *v9; // x8
  __int64 v10; // x2
  unsigned int *v11; // x1
  _DWORD *v13; // [xsp+28h] [xbp+18h]

  v2 = *a1;
  if ( a2 && *(_BYTE *)(a2 + 16) == 1 )
  {
    v5 = *(_QWORD *)a2;
    if ( v5 == a1[4663] )
    {
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "__cam_isp_ctx_fs2_reg_upd_in_sof",
          5164,
          "SOF timestamp is updated at early time, qtimer: [%llu:%09llu], boot: [%llu:%09llu]",
          v5 / 0x3B9ACA00,
          v5 % 0x3B9ACA00,
          a1[4664] / 0x3B9ACA00uLL,
          a1[4664] % 0x3B9ACA00uLL);
    }
    else
    {
      _cam_isp_ctx_update_sof_ts(a1, v5, *(_QWORD *)(a2 + 8));
    }
  }
  if ( *(_DWORD *)(v2 + 240) == 5 || (unsigned __int64)a1[1] < 2 )
  {
    v6 = *(unsigned int **)(v2 + 160);
    if ( v6 == (unsigned int *)(v2 + 160) )
      return 0;
    v7 = *((unsigned int ***)v6 + 1);
    if ( *v7 == v6 && (v8 = *(_QWORD *)v6, *(unsigned int **)(*(_QWORD *)v6 + 8LL) == v6) )
    {
      *(_QWORD *)(v8 + 8) = v7;
      *v7 = (unsigned int *)v8;
    }
    else
    {
      _list_del_entry_valid_or_report(*(_QWORD *)(v2 + 160));
    }
    *(_QWORD *)v6 = v6;
    *((_QWORD *)v6 + 1) = v6;
    cam_smmu_buffer_tracker_putref(v6 + 28);
    v9 = *((_DWORD **)v6 + 4);
    if ( v9[8] != v9[13] )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "__cam_isp_ctx_fs2_reg_upd_in_sof",
        5187,
        "receive rup in unexpected state, ctx_idx: %u, link: 0x%x",
        *(_DWORD *)(v2 + 32),
        *(_DWORD *)(v2 + 64));
      if ( !v6 )
        return 0;
LABEL_28:
      _cam_isp_ctx_update_state_monitor_array((__int64)a1, 2, *((_QWORD *)v6 + 3));
      return 0;
    }
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v13 = *((_DWORD **)v6 + 4);
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
      v9 = v13;
      if ( !*((_QWORD *)v6 + 17) )
        goto LABEL_22;
    }
    else if ( !*((_QWORD *)v6 + 17) )
    {
LABEL_22:
      v10 = v2 + 176;
      v11 = *(unsigned int **)(v2 + 184);
      if ( (unsigned int *)(v2 + 176) == v6 || v11 == v6 || *(_QWORD *)v11 != v10 )
      {
        _list_add_valid_or_report(v6);
        if ( !v6 )
          return 0;
      }
      else
      {
        *(_QWORD *)(v2 + 184) = v6;
        *(_QWORD *)v6 = v10;
        *((_QWORD *)v6 + 1) = v11;
        *(_QWORD *)v11 = v6;
        if ( !v6 )
          return 0;
      }
      goto LABEL_28;
    }
    cam_mem_put_kref(v9[1082]);
    cam_common_mem_free(*((_QWORD *)v6 + 17));
    *((_QWORD *)v6 + 17) = 0;
    goto LABEL_22;
  }
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "__cam_isp_ctx_fs2_reg_upd_in_sof",
      5168,
      "invalid RUP");
  return 0;
}
