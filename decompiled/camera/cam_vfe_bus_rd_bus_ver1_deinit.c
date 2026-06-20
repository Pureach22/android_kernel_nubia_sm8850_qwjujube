__int64 __fastcall cam_vfe_bus_rd_bus_ver1_deinit(
        _QWORD **a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  _QWORD *v8; // x20
  _QWORD *v10; // x21
  _QWORD *v11; // x0
  unsigned int v12; // w21
  _QWORD *v13; // x0
  _QWORD *v14; // x0
  _QWORD *v15; // x0
  _QWORD *v16; // x0

  if ( !a1 || (v8 = *a1) == nullptr )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_rd_bus_ver1_deinit",
      1351,
      "Invalid input");
    return (unsigned int)-22;
  }
  v10 = (_QWORD *)*v8;
  if ( !*v8 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_rd_bus_ver1_deinit",
      1358,
      "bus_priv is NULL");
    v12 = -19;
LABEL_33:
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v8, 0);
    else
      kvfree(v8);
    *a1 = nullptr;
    return v12;
  }
  if ( !*((_DWORD *)v10 + 78) )
    goto LABEL_41;
  *((_DWORD *)v10 + 82) = 0;
  v10[44] = v10 + 44;
  v10[45] = v10 + 44;
  v11 = (_QWORD *)v10[43];
  v10[51] = 0;
  v10[52] = 0;
  v10[54] = 0;
  v10[55] = 0;
  v10[42] = 0;
  v10[43] = 0;
  if ( v11 )
  {
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v11, 0);
    else
      kvfree(v11);
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_rd_bus_ver1_deinit",
      1367,
      "Deinit RM failed rc=%d",
      -12);
  }
  if ( *((_DWORD *)v10 + 78) < 2u )
    goto LABEL_41;
  *((_DWORD *)v10 + 120) = 0;
  v10[63] = v10 + 63;
  v10[64] = v10 + 63;
  v13 = (_QWORD *)v10[62];
  v10[70] = 0;
  v10[71] = 0;
  v10[73] = 0;
  v10[74] = 0;
  v10[61] = 0;
  v10[62] = 0;
  if ( v13 )
    v14 = (mem_trace_en & 1) != 0 ? cam_mem_trace_free(v13, 0) : (_QWORD *)kvfree(v13);
  else
    v14 = (_QWORD *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                      3,
                      8,
                      1,
                      "cam_vfe_bus_rd_bus_ver1_deinit",
                      1367,
                      "Deinit RM failed rc=%d",
                      -12);
  if ( *((_DWORD *)v10 + 78) <= 2u )
  {
LABEL_41:
    if ( *((_DWORD *)v10 + 120) )
    {
      v15 = (_QWORD *)v10[62];
      *((_DWORD *)v10 + 120) = 0;
      v10[70] = 0;
      v10[71] = 0;
      v10[73] = 0;
      v10[74] = 0;
      v10[63] = v10 + 63;
      v10[64] = v10 + 63;
      v10[61] = 0;
      v10[62] = 0;
      if ( v15 )
      {
        if ( mem_trace_en == 1 )
          cam_mem_trace_free(v15, 0);
        else
          kvfree(v15);
      }
      else
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_bus_rd_bus_ver1_deinit",
          1374,
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
        "cam_vfe_bus_deinit_vfe_bus_rd_resource",
        839,
        "HW%d Res %d already deinitialized",
        a7,
        a8);
    }
    v12 = cam_irq_controller_deinit(v10 + 3);
    if ( v12 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_bus_rd_bus_ver1_deinit",
        1381,
        "Deinit IRQ Controller failed rc=%d",
        v12);
    v16 = (_QWORD *)*v8;
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v16, 0);
    else
      kvfree(v16);
    goto LABEL_33;
  }
  __break(0x5512u);
  return cam_vfe_bus_start_rm(v14);
}
