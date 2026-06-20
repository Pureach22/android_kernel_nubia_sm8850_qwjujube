__int64 __fastcall cam_sfe_bus_rd_deinit(_QWORD **a1)
{
  _QWORD *v1; // x20
  _QWORD *v3; // x26
  __int64 v4; // x0
  _QWORD *v5; // x0
  int v6; // w6
  int v7; // w7
  unsigned __int64 v8; // x23
  _QWORD *v9; // x24
  _QWORD *v10; // x0
  unsigned int v11; // w21
  unsigned __int64 v12; // x27
  _QWORD *v13; // x28
  _QWORD *v14; // x0
  _QWORD *v15; // x0

  if ( !a1 || (v1 = *a1) == nullptr )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_bus_rd_deinit",
      2223,
      "Invalid input");
    return (unsigned int)-22;
  }
  v3 = (_QWORD *)*v1;
  if ( !*v1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_bus_rd_deinit",
      2230,
      "bus_priv is NULL");
    v11 = -19;
LABEL_33:
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v1, 0);
    else
      kvfree(v1);
    *a1 = nullptr;
    return v11;
  }
  v4 = raw_spin_lock_irqsave(v3 + 49);
  v3[50] = v3 + 50;
  v3[51] = v3 + 50;
  v3[52] = v3 + 52;
  v3[53] = v3 + 52;
  v3[63] = v3 + 63;
  v3[64] = v3 + 63;
  v3[74] = v3 + 74;
  v3[75] = v3 + 74;
  v3[85] = v3 + 85;
  v3[86] = v3 + 85;
  v3[96] = v3 + 96;
  v3[97] = v3 + 96;
  v3[107] = v3 + 107;
  v3[108] = v3 + 107;
  v3[118] = v3 + 118;
  v3[119] = v3 + 118;
  v3[129] = v3 + 129;
  v3[130] = v3 + 129;
  v3[140] = v3 + 140;
  v3[141] = v3 + 140;
  v3[151] = v3 + 151;
  v3[152] = v3 + 151;
  v3[162] = v3 + 162;
  v3[163] = v3 + 162;
  v3[173] = v3 + 173;
  v3[174] = v3 + 173;
  v3[184] = v3 + 184;
  v3[185] = v3 + 184;
  v3[195] = v3 + 195;
  v3[196] = v3 + 195;
  v3[206] = v3 + 206;
  v3[207] = v3 + 206;
  v3[217] = v3 + 217;
  v3[218] = v3 + 217;
  v5 = (_QWORD *)raw_spin_unlock_irqrestore(v3 + 49, v4);
  if ( *((_DWORD *)v3 + 466) )
  {
    v8 = 0;
    v9 = v3 + 235;
    while ( v8 != 4 )
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
          v5 = cam_mem_trace_free(v10, 0);
        else
          v5 = (_QWORD *)kvfree(v10);
      }
      else
      {
        v5 = (_QWORD *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                         3,
                         0x40000000,
                         1,
                         "cam_sfe_bus_rd_deinit",
                         2245,
                         "Deinit RM failed rc=%d",
                         -12);
      }
      ++v8;
      v9 += 19;
      if ( v8 >= *((unsigned int *)v3 + 466) )
        goto LABEL_14;
    }
    goto LABEL_38;
  }
LABEL_14:
  if ( !*((_DWORD *)v3 + 467) )
  {
LABEL_27:
    v11 = cam_irq_controller_deinit(v3 + 47);
    if ( v11 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x40000000,
        1,
        "cam_sfe_bus_rd_deinit",
        2260,
        "Deinit IRQ Controller failed rc=%d",
        v11);
    v15 = (_QWORD *)*v1;
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v15, 0);
    else
      kvfree(v15);
    goto LABEL_33;
  }
  v12 = 0;
  v13 = v3 + 292;
  while ( v12 != 4 )
  {
    if ( *(_DWORD *)v13 )
    {
      v14 = (_QWORD *)v13[2];
      *(_DWORD *)v13 = 0;
      v13[10] = 0;
      v13[11] = 0;
      v13[13] = 0;
      v13[14] = 0;
      v13[3] = v13 + 3;
      v13[4] = v13 + 3;
      v13[1] = 0;
      v13[2] = 0;
      if ( v14 )
      {
        if ( mem_trace_en == 1 )
          v5 = cam_mem_trace_free(v14, 0);
        else
          v5 = (_QWORD *)kvfree(v14);
      }
      else
      {
        v5 = (_QWORD *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                         3,
                         0x40000000,
                         1,
                         "cam_sfe_bus_rd_deinit",
                         2253,
                         "Deinit SFE RD failed rc=%d",
                         -12);
      }
    }
    else if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
    {
      v5 = (_QWORD *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                       3,
                       debug_mdl & 0x40000000,
                       4,
                       "cam_sfe_bus_deinit_sfe_bus_rd_resource",
                       1338,
                       "HW%d Res %d already deinitialized",
                       v6,
                       v7);
    }
    ++v12;
    v13 += 19;
    if ( v12 >= *((unsigned int *)v3 + 467) )
      goto LABEL_27;
  }
LABEL_38:
  __break(0x5512u);
  return cam_sfe_bus_start_rm(v5);
}
