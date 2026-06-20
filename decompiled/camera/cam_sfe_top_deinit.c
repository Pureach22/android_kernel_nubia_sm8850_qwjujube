__int64 __fastcall cam_sfe_top_deinit(int a1, _QWORD **a2)
{
  _QWORD *v2; // x20
  _QWORD *v4; // x22
  __int64 v5; // x1
  __int64 v6; // x9
  _QWORD *v7; // x8
  _QWORD *v8; // x24
  __int64 v9; // x25
  _QWORD *v10; // x0
  const char *v11; // x5
  __int64 v12; // x4
  _QWORD *v13; // x0
  unsigned int v14; // w21

  if ( !a2 )
  {
    v11 = "Error Invalid input";
    v12 = 2432;
LABEL_21:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_top_deinit",
      v12,
      v11);
    return (unsigned int)-19;
  }
  v2 = *a2;
  if ( !*a2 )
  {
    v11 = "Error sfe top NULL";
    v12 = 2438;
    goto LABEL_21;
  }
  v4 = (_QWORD *)*v2;
  if ( *v2 )
  {
    if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x40000000,
        4,
        "cam_sfe_top_deinit",
        2452,
        "Deinit SFE [%u] top with hw_version 0x%x",
        *(_DWORD *)(v4[1] + 4LL),
        a1);
    v5 = raw_spin_lock_irqsave(v4 + 4034);
    v6 = 256;
    v4[2821] = v4 + 2821;
    v4[2822] = v4 + 2821;
    v7 = v4 + 5;
    do
    {
      *v7 = v7;
      --v6;
      v7[1] = v7;
      v7 += 11;
    }
    while ( v6 );
    raw_spin_unlock_irqrestore(v4 + 4034, v5);
    v8 = v4 + 2824;
    v9 = 6;
    do
    {
      v10 = (_QWORD *)v8[2];
      *(_DWORD *)v8 = 0;
      v8[10] = 0;
      v8[11] = 0;
      v8[12] = 0;
      v8[13] = 0;
      v8[14] = 0;
      if ( v10 )
      {
        if ( mem_trace_en == 1 )
          cam_mem_trace_free(v10, 0);
        else
          kvfree(v10);
        v8[2] = 0;
      }
      else
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x40000000,
          1,
          "cam_sfe_top_deinit",
          2472,
          "Error res_priv is NULL");
      }
      --v9;
      v8 += 19;
    }
    while ( v9 );
    v13 = (_QWORD *)*v2;
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v13, 0);
    else
      kvfree(v13);
    v14 = 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_top_deinit",
      2444,
      "Error sfe top priv NULL");
    v14 = -19;
  }
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v2, 0);
  else
    kvfree(v2);
  *a2 = nullptr;
  return v14;
}
