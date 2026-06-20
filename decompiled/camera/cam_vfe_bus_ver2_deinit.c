__int64 __fastcall cam_vfe_bus_ver2_deinit(_QWORD **a1)
{
  _QWORD *v1; // x28
  _QWORD *v2; // x27
  _QWORD *v3; // x26
  __int64 v4; // x1
  __int64 v5; // x8
  _QWORD *v6; // x9
  _QWORD *v7; // x0
  unsigned __int64 v8; // x20
  _QWORD *v9; // x24
  _QWORD *v10; // x0
  unsigned int v11; // w21
  _QWORD *v12; // x28
  __int64 v13; // x20
  int v14; // w6
  int v15; // w7
  _QWORD *v16; // x8
  __int64 *v17; // x9
  _QWORD *v18; // x0
  __int64 v19; // x10
  _QWORD *v20; // x10
  _QWORD *v21; // x22
  __int64 v22; // x20
  _QWORD *v23; // x27
  _QWORD *v24; // x0
  _QWORD *v25; // x0
  _QWORD **v27; // [xsp+8h] [xbp-8h]

  if ( !a1 || (v1 = *a1, v2 = a1, !*a1) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_ver2_deinit",
      3980,
      "Invalid input");
    return (unsigned int)-22;
  }
  v3 = (_QWORD *)*v1;
  if ( !*v1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_ver2_deinit",
      3987,
      "bus_priv is NULL");
    v11 = -19;
LABEL_44:
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v1, 0);
    else
      kvfree(v1);
    *v2 = 0;
    return v11;
  }
  v4 = raw_spin_lock_irqsave(v3 + 4191);
  v5 = 0;
  v3[4189] = v3 + 4189;
  v3[4190] = v3 + 4189;
  do
  {
    v6 = &v3[v5];
    v5 += 16;
    v6[93] = v6 + 93;
    v6[94] = v6 + 93;
  }
  while ( v5 != 4096 );
  *((_BYTE *)v3 + 33608) = 0;
  v7 = (_QWORD *)raw_spin_unlock_irqrestore(v3 + 4191, v4);
  if ( !*((_DWORD *)v3 + 8404) )
  {
LABEL_16:
    v27 = (_QWORD **)v1;
    v12 = v3 + 4661;
    v13 = 12;
    do
    {
      v16 = (_QWORD *)v12[4];
      v12[1] = 0;
      v17 = v12 + 3;
      v12[10] = 0;
      v12[11] = 0;
      v18 = (_QWORD *)v12[2];
      v12[13] = 0;
      v12[14] = 0;
      if ( v12 + 3 == (_QWORD *)*v16 && (v19 = *v17, v17 == *(__int64 **)(*v17 + 8)) )
      {
        *(_QWORD *)(v19 + 8) = v16;
        *v16 = v19;
      }
      else
      {
        _list_del_entry_valid_or_report(v12 + 3);
        v18 = v20;
      }
      v12[3] = v12 + 3;
      v12[4] = v17;
      *(_DWORD *)v12 = 0;
      v12[2] = 0;
      if ( v18 )
      {
        if ( mem_trace_en == 1 )
          cam_mem_trace_free(v18, 0);
        else
          kvfree(v18);
      }
      else
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_bus_deinit_comp_grp",
          2037,
          "comp_grp_priv is NULL");
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_bus_ver2_deinit",
          4010,
          "Deinit Comp Grp failed rc=%d",
          -19);
      }
      --v13;
      v12 += 19;
    }
    while ( v13 );
    v21 = v2;
    v22 = 23;
    v23 = v3 + 4889;
    do
    {
      if ( *(_DWORD *)v23 )
      {
        v24 = (_QWORD *)v23[2];
        *((_DWORD *)v23 + 14) = 0;
        *(_DWORD *)v23 = 0;
        v23[10] = 0;
        v23[11] = 0;
        v23[13] = 0;
        v23[14] = 0;
        v23[3] = v23 + 3;
        v23[4] = v23 + 3;
        v23[1] = 0;
        v23[2] = 0;
        if ( v24 )
        {
          if ( mem_trace_en == 1 )
            cam_mem_trace_free(v24, 0);
          else
            kvfree(v24);
        }
        else
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_vfe_bus_ver2_deinit",
            4017,
            "Deinit VFE Out failed rc=%d",
            -12);
        }
      }
      else if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_bus_deinit_vfe_out_resource",
          2543,
          "HW%d Res %d already deinitialized",
          v14,
          v15);
      }
      --v22;
      v23 += 19;
    }
    while ( v22 );
    v3[5325] = v3 + 5325;
    v3[5326] = v3 + 5325;
    v3[5327] = v3 + 5327;
    v3[5328] = v3 + 5327;
    v3[5329] = v3 + 5329;
    v3[5330] = v3 + 5329;
    v11 = cam_irq_controller_deinit(v3 + 3);
    v2 = v21;
    if ( v11 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_bus_ver2_deinit",
        4028,
        "Deinit IRQ Controller failed rc=%d",
        v11);
    v1 = v27;
    v25 = *v27;
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v25, 0);
    else
      kvfree(v25);
    goto LABEL_44;
  }
  v8 = 0;
  v9 = v3 + 4205;
  while ( v8 != 25 )
  {
    *(_DWORD *)v9 = 0;
    v9[3] = v9 + 3;
    v9[4] = v9 + 3;
    v10 = (_QWORD *)v9[2];
    v9[10] = 0;
    v9[11] = 0;
    v9[13] = 0;
    v9[14] = 0;
    v9[1] = 0;
    v9[2] = 0;
    if ( v10 )
    {
      if ( mem_trace_en == 1 )
        v7 = cam_mem_trace_free(v10, 0);
      else
        v7 = (_QWORD *)kvfree(v10);
    }
    else
    {
      v7 = (_QWORD *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                       3,
                       8,
                       1,
                       "cam_vfe_bus_ver2_deinit",
                       4003,
                       "Deinit WM failed rc=%d",
                       -12);
    }
    ++v8;
    v9 += 19;
    if ( v8 >= *((unsigned int *)v3 + 8404) )
      goto LABEL_16;
  }
  __break(0x5512u);
  return cam_vfe_bus_handle_wm_done_top_half(v7);
}
