__int64 __fastcall cam_flash_slaveInfo_pkt_parser(__int64 a1, _DWORD *a2, unsigned __int64 a3)
{
  const char *v3; // x5
  __int64 v4; // x4
  int v5; // w6
  __int64 result; // x0
  __int64 v8; // x11
  __int16 v9; // w8
  __int64 v10; // x8

  if ( a3 <= 7 )
  {
    v3 = "Not enough buffer";
    v4 = 959;
LABEL_3:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4096,
      1,
      "cam_flash_slaveInfo_pkt_parser",
      v4,
      v3);
    return 4294967274LL;
  }
  v5 = *(_DWORD *)(a1 + 6280);
  if ( v5 == 2 )
  {
    v10 = *(_QWORD *)(a1 + 6288);
    if ( !v10 )
    {
      v3 = "io_master_info.qup_client is NULL";
      v4 = 973;
      goto LABEL_3;
    }
    result = 0;
    *(_WORD *)(*(_QWORD *)v10 + 2LL) = *a2;
    if ( (debug_mdl & 0x1000) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x1000,
        4,
        "cam_flash_slaveInfo_pkt_parser",
        978,
        "Slave addr: 0x%x",
        *a2);
      return 0;
    }
  }
  else
  {
    if ( v5 != 1 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4096,
        1,
        "cam_flash_slaveInfo_pkt_parser",
        981,
        "Invalid Master type: %d",
        v5);
      return 4294967274LL;
    }
    result = 0;
    *(_DWORD *)(*(_QWORD *)(a1 + 6296) + 16LL) = *(_DWORD *)(a1 + 6272);
    *(_DWORD *)(*(_QWORD *)(a1 + 6296) + 12LL) = *((unsigned __int8 *)a2 + 4);
    v8 = *(_QWORD *)(a1 + 6296);
    v9 = debug_mdl;
    *(_WORD *)(v8 + 20) = *a2 >> 1;
    if ( (v9 & 0x1000) != 0 && !debug_priority )
    {
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v9 & 0x1000,
        4,
        "cam_flash_slaveInfo_pkt_parser",
        970,
        "Slave addr: 0x%x Freq Mode: %d",
        *a2,
        *((unsigned __int8 *)a2 + 4));
      return 0;
    }
  }
  return result;
}
