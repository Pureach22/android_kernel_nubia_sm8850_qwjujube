__int64 __fastcall cam_vfe_bus_stop_vfe_bus_rd(__int64 a1)
{
  __int128 v1; // q15
  int v2; // w8
  __int64 v3; // x20
  __int64 result; // x0
  __int64 v6; // x24
  __int64 v7; // x23
  char v8; // w8
  __int64 v9; // x24
  __int64 v10; // x23
  __int64 v11; // x0
  __int64 v12; // x15
  __int128 v13; // q22
  char v14; // w8
  char v15; // w8
  int v16; // w7
  unsigned int v17; // w19

  if ( a1 )
  {
    v2 = *(_DWORD *)(a1 + 8);
    v3 = *(_QWORD *)(a1 + 24);
    if ( (unsigned int)(v2 - 1) >= 2 )
    {
      if ( !*(_DWORD *)(v3 + 16) )
        goto LABEL_26;
      v6 = *(_QWORD *)(v3 + 24);
      v7 = *(_QWORD *)(v6 + 24);
      cam_io_w_mb(0, *(_QWORD *)(*(_QWORD *)(v7 + 8) + 8LL) + **(unsigned int **)(v7 + 16));
      v8 = debug_mdl;
      *(_DWORD *)(v6 + 8) = 2;
      *(_BYTE *)(v7 + 32) = 0;
      if ( (v8 & 8) != 0 && !debug_priority )
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v8 & 8,
          4,
          "cam_vfe_bus_stop_rm",
          493,
          "VFE:%d RM:%d stopped",
          **(_DWORD **)(v7 + 8),
          *(_DWORD *)v7);
      if ( *(_DWORD *)(v3 + 16) < 2u )
        goto LABEL_26;
      v9 = *(_QWORD *)(v3 + 32);
      v10 = *(_QWORD *)(v9 + 24);
      v11 = cam_io_w_mb(0, *(_QWORD *)(*(_QWORD *)(v10 + 8) + 8LL) + **(unsigned int **)(v10 + 16));
      v14 = debug_mdl;
      *(_DWORD *)(v9 + 8) = 2;
      *(_BYTE *)(v10 + 32) = 0;
      if ( (v14 & 8) != 0 && !debug_priority )
        v11 = ((__int64 (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                v14 & 8,
                4,
                "cam_vfe_bus_stop_rm",
                493,
                "VFE:%d RM:%d stopped",
                **(_DWORD **)(v10 + 8),
                *(_DWORD *)v10);
      if ( *(_DWORD *)(v3 + 16) > 2u )
      {
        __break(0x5512u);
        *(_OWORD *)(v12 - 64) = v13;
        *(_OWORD *)(v12 - 48) = v1;
        return cam_vfe_bus_rd_process_cmd(v11);
      }
      else
      {
LABEL_26:
        if ( *(_DWORD *)(v3 + 100) )
        {
          result = ((__int64 (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq)(*(_QWORD *)(*(_QWORD *)(v3 + 8)
                                                                                                  + 24LL));
          *(_DWORD *)(v3 + 100) = 0;
        }
        else
        {
          result = 0;
        }
        v15 = debug_mdl;
        *(_DWORD *)(a1 + 8) = 2;
        if ( (v15 & 8) != 0 && !debug_priority )
        {
          v16 = *(_DWORD *)(a1 + 4);
          v17 = result;
          ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v15 & 8,
            4,
            "cam_vfe_bus_stop_vfe_bus_rd",
            769,
            "VFE:%d stopped Bus RD:0x%x",
            **(_DWORD **)(v3 + 8),
            v16);
          return v17;
        }
      }
    }
    else
    {
      result = 0;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_bus_stop_vfe_bus_rd",
          752,
          "VFE:%d Bus RD 0x%x state: %d",
          **(_DWORD **)(v3 + 8),
          *(_DWORD *)(a1 + 4),
          v2);
        return 0;
      }
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_stop_vfe_bus_rd",
      742,
      "Invalid input");
    return 4294967274LL;
  }
  return result;
}
