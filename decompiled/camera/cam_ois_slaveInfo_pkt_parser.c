__int64 __fastcall cam_ois_slaveInfo_pkt_parser(__int64 a1, _DWORD *a2, unsigned __int64 a3)
{
  int v3; // w6
  __int64 v4; // x10
  __int64 v5; // x12
  __int64 v6; // x13
  __int64 v7; // x10
  __int64 v8; // x10
  int v9; // w8
  __int64 result; // x0
  const char *v11; // x5
  __int64 v12; // x4
  __int64 v13; // x8

  if ( !a2 || a3 <= 0x37 )
  {
    v11 = "Invalid Args";
    v12 = 387;
LABEL_10:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x100000,
      1,
      "cam_ois_slaveInfo_pkt_parser",
      v12,
      v11);
    return 4294967274LL;
  }
  v3 = *(_DWORD *)(a1 + 3656);
  if ( v3 != 2 )
  {
    if ( v3 == 1 )
    {
      *(_DWORD *)(*(_QWORD *)(a1 + 3672) + 12LL) = *((unsigned __int8 *)a2 + 4);
      *(_WORD *)(*(_QWORD *)(a1 + 3672) + 20LL) = *a2 >> 1;
      *(_BYTE *)(a1 + 4548) = *((_BYTE *)a2 + 6);
      *(_BYTE *)(a1 + 4549) = *((_BYTE *)a2 + 7);
      v4 = *((_QWORD *)a2 + 4);
      v5 = *((_QWORD *)a2 + 1);
      v6 = *((_QWORD *)a2 + 2);
      *(_QWORD *)(a1 + 4532) = *((_QWORD *)a2 + 3);
      *(_QWORD *)(a1 + 4540) = v4;
      v7 = *(_QWORD *)(a1 + 3672);
      *(_QWORD *)(a1 + 4516) = v5;
      *(_QWORD *)(a1 + 4524) = v6;
      *(_BYTE *)(a1 + 4547) = 0;
      *(_WORD *)(v7 + 28) = 3;
      *(_WORD *)(*(_QWORD *)(a1 + 3672) + 30LL) = 0;
      v8 = *((_QWORD *)a2 + 6);
      v9 = debug_mdl;
      *(_QWORD *)(a1 + 4550) = *((_QWORD *)a2 + 5);
      *(_QWORD *)(a1 + 4558) = v8;
      if ( (v9 & 0x100000) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          *(_QWORD *)&v9 & 0x100000LL,
          4,
          "cam_ois_slaveInfo_pkt_parser",
          406,
          "Slave addr: 0x%x Freq Mode: %d",
          *a2,
          *((unsigned __int8 *)a2 + 4));
      msm_ois_enable_debugfs();
      return 0;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x100000,
      1,
      "cam_ois_slaveInfo_pkt_parser",
      418,
      "Invalid Master type : %d",
      v3);
    return 4294967274LL;
  }
  v13 = *(_QWORD *)(a1 + 3664);
  if ( !v13 )
  {
    v11 = "io_master_info.qup_client is NULL";
    v12 = 410;
    goto LABEL_10;
  }
  result = 0;
  *(_WORD *)(*(_QWORD *)v13 + 2LL) = *a2;
  if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x100000,
      4,
      "cam_ois_slaveInfo_pkt_parser",
      415,
      "Slave addr: 0x%x",
      *a2);
    return 0;
  }
  return result;
}
