__int64 __fastcall cam_vfe_bus_handle_wm_done_bottom_half(__int64 a1, _DWORD *a2)
{
  __int64 result; // x0
  _DWORD *v4; // x19
  int v5; // w9
  __int64 v6; // x8
  __int64 v7; // x6
  __int64 v8; // x8
  char v9; // w8
  _DWORD *v10; // [xsp+28h] [xbp+18h]
  _DWORD *v11; // [xsp+28h] [xbp+18h]
  _DWORD *v12; // [xsp+28h] [xbp+18h]
  _DWORD *v13; // [xsp+28h] [xbp+18h]
  _DWORD *v14; // [xsp+28h] [xbp+18h]
  _DWORD *v15; // [xsp+28h] [xbp+18h]
  _DWORD *v16; // [xsp+28h] [xbp+18h]
  _DWORD *v17; // [xsp+28h] [xbp+18h]
  unsigned int v18; // [xsp+28h] [xbp+18h]

  if ( !a1 )
    return 0xFFFFFFFFLL;
  result = 0xFFFFFFFFLL;
  if ( !a2 )
    return result;
  v4 = *(_DWORD **)(a1 + 24);
  if ( !v4 )
    return result;
  v5 = debug_priority;
  v6 = debug_mdl & 8;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v10 = a2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_bus_handle_wm_done_bottom_half",
      1350,
      "addr of evt_payload = %llx core index:0x%x",
      a2,
      a2[4]);
    a2 = v10;
    v5 = debug_priority;
    v6 = debug_mdl & 8;
    if ( (debug_mdl & 8) == 0 )
      goto LABEL_9;
  }
  else if ( (debug_mdl & 8) == 0 )
  {
    goto LABEL_9;
  }
  if ( !v5 )
  {
    v11 = a2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v6,
      4,
      "cam_vfe_bus_handle_wm_done_bottom_half",
      1351,
      "bus_irq_status_0: = %x",
      a2[10]);
    a2 = v11;
    v5 = debug_priority;
    v6 = debug_mdl & 8;
  }
LABEL_9:
  if ( v6 && !v5 )
  {
    v12 = a2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v6,
      4,
      "cam_vfe_bus_handle_wm_done_bottom_half",
      1352,
      "bus_irq_status_1: = %x",
      a2[11]);
    a2 = v12;
    v5 = debug_priority;
    v6 = debug_mdl & 8;
    if ( (debug_mdl & 8) == 0 )
      goto LABEL_14;
  }
  else if ( !v6 )
  {
    goto LABEL_14;
  }
  if ( !v5 )
  {
    v13 = a2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v6,
      4,
      "cam_vfe_bus_handle_wm_done_bottom_half",
      1353,
      "bus_irq_status_2: = %x",
      a2[12]);
    a2 = v13;
    v5 = debug_priority;
    v6 = debug_mdl & 8;
  }
LABEL_14:
  if ( v6 && !v5 )
  {
    v14 = a2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v6,
      4,
      "cam_vfe_bus_handle_wm_done_bottom_half",
      1354,
      "bus_irq_comp_err: = %x",
      a2[13]);
    a2 = v14;
    v5 = debug_priority;
    v6 = debug_mdl & 8;
    if ( (debug_mdl & 8) == 0 )
      goto LABEL_19;
  }
  else if ( !v6 )
  {
    goto LABEL_19;
  }
  if ( !v5 )
  {
    v15 = a2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v6,
      4,
      "cam_vfe_bus_handle_wm_done_bottom_half",
      1356,
      "bus_irq_comp_owrt: = %x",
      a2[14]);
    a2 = v15;
    v5 = debug_priority;
    v6 = debug_mdl & 8;
  }
LABEL_19:
  if ( v6 && !v5 )
  {
    v16 = a2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v6,
      4,
      "cam_vfe_bus_handle_wm_done_bottom_half",
      1358,
      "bus_irq_dual_comp_err: = %x",
      a2[15]);
    a2 = v16;
    v5 = debug_priority;
    v6 = debug_mdl & 8;
    if ( (debug_mdl & 8) != 0 )
    {
LABEL_22:
      if ( !v5 )
      {
        v17 = a2;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v6,
          4,
          "cam_vfe_bus_handle_wm_done_bottom_half",
          1360,
          "bus_irq_dual_comp_owrt: = %x",
          a2[16]);
        a2 = v17;
      }
    }
  }
  else if ( v6 )
  {
    goto LABEL_22;
  }
  v7 = (unsigned int)a2[11];
  v8 = 1LL << *v4;
  if ( (v8 & v7) != 0 )
  {
    result = 0;
    a2[11] = v7 & ~(_DWORD)v8;
    a2[9] = 5;
    v9 = debug_mdl;
    if ( (debug_mdl & 8) == 0 )
      return result;
  }
  else
  {
    result = 0xFFFFFFFFLL;
    v9 = debug_mdl;
    if ( (debug_mdl & 8) == 0 )
      return result;
  }
  if ( !debug_priority )
  {
    v18 = result;
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v9 & 8,
      4,
      "cam_vfe_bus_handle_wm_done_bottom_half",
      1372,
      "status_reg %x rc %d wm_idx %d",
      v7,
      result,
      *v4);
    return v18;
  }
  return result;
}
