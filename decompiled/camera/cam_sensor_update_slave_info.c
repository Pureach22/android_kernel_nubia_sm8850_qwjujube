__int64 __fastcall cam_sensor_update_slave_info(__int64 a1, __int64 a2, __int64 a3, char a4)
{
  char *v4; // x6
  __int16 v5; // w9
  __int64 v6; // x9
  __int64 v7; // x11
  __int64 v8; // x10
  __int64 v9; // x10
  __int64 v10; // x12
  __int64 v11; // x11

  v4 = (char *)(a3 + 7560);
  *(_QWORD *)(a3 + 7584) = 0;
  *(_QWORD *)(a3 + 7576) = 0;
  *(_QWORD *)(a3 + 7568) = 0;
  *(_QWORD *)(a3 + 7560) = 0;
  *(_QWORD *)(a3 + 6512) = 0;
  *(_QWORD *)(a3 + 6520) = 0;
  *(_QWORD *)(a3 + 6528) = 0;
  *(_QWORD *)(a3 + 6536) = 0;
  if ( a4 == 8 )
  {
    *(_DWORD *)(*(_QWORD *)(a3 + 3656) + 4LL) = *(_DWORD *)(a1 + 4);
    *(_DWORD *)(*(_QWORD *)(a3 + 3656) + 8LL) = *(_DWORD *)(a1 + 8);
    *(_DWORD *)(*(_QWORD *)(a3 + 3656) + 12LL) = *(_DWORD *)(a1 + 12);
    *(_WORD *)(a3 + 7556) = *(unsigned __int8 *)(a1 + 18);
    *(_WORD *)(a3 + 7558) = *(unsigned __int8 *)(a1 + 19);
    *(_BYTE *)(a3 + 7040) = *(_BYTE *)(a1 + 1);
    *(_BYTE *)(a3 + 7041) = *(_BYTE *)a1;
    v7 = *(_QWORD *)(a1 + 32);
    v6 = *(_QWORD *)(a1 + 40);
    v8 = *(_QWORD *)(a1 + 24);
    *(_QWORD *)(a3 + 7583) = *(_QWORD *)(a1 + 47);
    *(_QWORD *)(a3 + 7568) = v7;
    *(_QWORD *)(a3 + 7576) = v6;
    *(_QWORD *)v4 = v8;
    *(_DWORD *)(a3 + 7592) = *(_DWORD *)(a1 + 56);
    v10 = *(_QWORD *)(a1 + 32);
    v9 = *(_QWORD *)(a1 + 40);
    v11 = *(_QWORD *)(a1 + 24);
    *(_QWORD *)(a3 + 6535) = *(_QWORD *)(a1 + 47);
    *(_QWORD *)(a3 + 6520) = v10;
    *(_QWORD *)(a3 + 6528) = v9;
    *(_QWORD *)(a3 + 6512) = v11;
  }
  else if ( a4 == 3 )
  {
    *(_DWORD *)(*(_QWORD *)(a3 + 3656) + 4LL) = *(_DWORD *)(a1 + 4);
    *(_DWORD *)(*(_QWORD *)(a3 + 3656) + 8LL) = *(_DWORD *)(a1 + 8);
    *(_DWORD *)(*(_QWORD *)(a3 + 3656) + 12LL) = *(_DWORD *)(a1 + 12);
    v5 = *(_WORD *)(a1 + 18);
    *(_WORD *)(a3 + 7558) = 0;
    *(_WORD *)(a3 + 7556) = v5;
    *(_BYTE *)(a3 + 7040) = *(_BYTE *)(a1 + 1);
    LOBYTE(v5) = *(_BYTE *)a1;
    *(_DWORD *)(a3 + 7592) = 0;
    *(_BYTE *)(a3 + 7041) = v5;
  }
  if ( (debug_mdl & 0x20) == 0 || debug_priority )
    return 0;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 0x20,
    4,
    "cam_sensor_update_slave_info",
    937,
    "%s Sensor Addr: 0x%x sensor_id: 0x%x sensor_mask: 0x%x sensor_pipeline_delay:0x%x",
    v4,
    *(_DWORD *)(*(_QWORD *)(a3 + 3656) + 4LL),
    *(_DWORD *)(*(_QWORD *)(a3 + 3656) + 8LL),
    *(_DWORD *)(*(_QWORD *)(a3 + 3656) + 12LL),
    *(unsigned __int16 *)(a3 + 7556));
  return 0;
}
