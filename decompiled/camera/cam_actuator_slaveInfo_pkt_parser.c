__int64 __fastcall cam_actuator_slaveInfo_pkt_parser(__int64 a1, _DWORD *a2, unsigned __int64 a3)
{
  int v3; // w6
  __int64 result; // x0
  __int64 v6; // x11
  __int16 v7; // w8
  __int64 v8; // x8

  if ( !a1 || !a2 || a3 <= 7 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x2000,
      1,
      "cam_actuator_slaveInfo_pkt_parser",
      226,
      "Invalid Args");
    return 4294967274LL;
  }
  v3 = *(_DWORD *)(a1 + 32);
  if ( v3 != 2 )
  {
    if ( v3 == 1 )
    {
      result = 0;
      *(_DWORD *)(*(_QWORD *)(a1 + 48) + 12LL) = *((unsigned __int8 *)a2 + 4);
      v6 = *(_QWORD *)(a1 + 48);
      v7 = debug_mdl;
      *(_WORD *)(v6 + 20) = *a2 >> 1;
      if ( (v7 & 0x2000) != 0 && !debug_priority )
      {
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v7 & 0x2000,
          4,
          "cam_actuator_slaveInfo_pkt_parser",
          237,
          "Slave addr: 0x%x Freq Mode: %d",
          *a2,
          *((unsigned __int8 *)a2 + 4));
        return 0;
      }
      return result;
    }
    goto LABEL_14;
  }
  v8 = *(_QWORD *)(a1 + 40);
  if ( !v8 )
  {
LABEL_14:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x2000,
      1,
      "cam_actuator_slaveInfo_pkt_parser",
      244,
      "Invalid Master type: %d",
      v3);
    return 4294967274LL;
  }
  result = 0;
  *(_WORD *)(*(_QWORD *)v8 + 2LL) = *a2;
  if ( (debug_mdl & 0x2000) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x2000,
      4,
      "cam_actuator_slaveInfo_pkt_parser",
      241,
      "Slave addr: 0x%x",
      *a2);
    return 0;
  }
  return result;
}
