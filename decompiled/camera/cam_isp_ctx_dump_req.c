__int64 __fastcall cam_isp_ctx_dump_req(__int64 a1)
{
  int v1; // w8
  int v3; // w8
  __int64 v4; // x0
  __int64 v5; // x25
  unsigned int cmd_mem_addr; // w23
  __int64 v7; // x8
  __int64 v8; // x6
  __int64 v9; // x8
  const char *v10; // x5
  __int64 v11; // x4
  __int64 v13; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v14[2]; // [xsp+10h] [xbp-10h] BYREF

  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_DWORD *)(a1 + 16);
  v14[0] = 0;
  if ( !v1 )
  {
    cmd_mem_addr = 0;
    goto LABEL_16;
  }
  v3 = 0;
  v13 = 0;
  while ( 1 )
  {
    v5 = v3;
    cmd_mem_addr = cam_packet_util_get_cmd_mem_addr(*(_DWORD *)(*(_QWORD *)(a1 + 8) + 32LL * v3), &v13, v14);
    if ( cmd_mem_addr )
    {
      if ( (unsigned int)__ratelimit(&cam_isp_ctx_dump_req__rs, "cam_isp_ctx_dump_req") )
        v4 = 3;
      else
        v4 = 2;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        v4,
        8,
        1,
        "cam_isp_ctx_dump_req",
        1026,
        "Failed to get_cmd_mem_addr, rc=%d",
        cmd_mem_addr);
      goto LABEL_7;
    }
    v7 = *(_QWORD *)(a1 + 8) + 32 * v5;
    v8 = *(unsigned int *)(v7 + 4);
    if ( LODWORD(v14[0]) <= (unsigned int)v8 )
    {
      v10 = "Invalid offset exp %u actual %u";
      v11 = 1031;
      goto LABEL_15;
    }
    v9 = *(unsigned int *)(v7 + 8);
    if ( (unsigned int)v9 > LODWORD(v14[0]) - (int)v8 )
      break;
    cam_cdm_util_dump_cmd_buf((unsigned __int16 *)(v13 + v8), (unsigned __int16 *)(v13 + v8 + v9 - 1));
    cam_mem_put_cpu_buf(*(_DWORD *)(*(_QWORD *)(a1 + 8) + 32 * v5));
LABEL_7:
    v3 = v5 + 1;
    if ( (unsigned int)(v5 + 1) >= *(_DWORD *)(a1 + 16) )
      goto LABEL_16;
  }
  v10 = "Invalid len exp %u remain_len %u";
  v11 = 1042;
LABEL_15:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    1,
    "cam_isp_ctx_dump_req",
    v11,
    v10);
  cam_mem_put_cpu_buf(*(_DWORD *)(*(_QWORD *)(a1 + 8) + 32 * v5));
  cmd_mem_addr = -22;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return cmd_mem_addr;
}
