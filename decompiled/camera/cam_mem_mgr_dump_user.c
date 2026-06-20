__int64 __fastcall cam_mem_mgr_dump_user(__int64 a1)
{
  int v2; // w0
  unsigned int cpu_buf; // w0
  unsigned int v4; // w21
  size_t v5; // x7
  char *v7; // x20
  __int64 v8; // x24
  bool v9; // cf
  unsigned int v10; // w0
  int v11; // w0
  __int64 v12; // [xsp+8h] [xbp-48h] BYREF
  size_t v13; // [xsp+10h] [xbp-40h] BYREF
  _QWORD v14[3]; // [xsp+18h] [xbp-38h] BYREF
  size_t v15; // [xsp+30h] [xbp-20h]
  __int64 v16; // [xsp+38h] [xbp-18h]
  __int64 v17; // [xsp+40h] [xbp-10h]
  __int64 v18; // [xsp+48h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a1 + 16);
  v17 = 0;
  v12 = 0;
  v13 = 0;
  cpu_buf = cam_mem_get_cpu_buf(v2, &v12, &v13);
  if ( cpu_buf )
  {
    v4 = cpu_buf;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x400000,
      1,
      "cam_mem_mgr_dump_user",
      3463,
      "Invalid handle %u rc %d",
      *(_DWORD *)(a1 + 16),
      cpu_buf);
    goto LABEL_8;
  }
  v5 = *(_QWORD *)(a1 + 8);
  if ( v13 <= v5 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x400000,
      2,
      "cam_mem_mgr_dump_user",
      3468,
      "Dump buffer overshoot len %zu offset %zu",
      v13,
      v5);
    goto LABEL_7;
  }
  if ( (v13 - v5) >> 14 <= 0x2E )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x400000,
      2,
      "cam_mem_mgr_dump_user",
      3481,
      "Dump buffer exhaust remain %zu min %u",
      v13 - v5,
      770048);
LABEL_7:
    cam_mem_put_cpu_buf(*(_DWORD *)(a1 + 16));
    v4 = -28;
    goto LABEL_8;
  }
  v7 = (char *)&unk_2FDCC8;
  v8 = -2047;
  v14[0] = *(_QWORD *)a1;
  v14[1] = v12;
  v14[2] = v13;
  v15 = v5;
  v16 = 0;
  do
  {
    mutex_lock(v7 + 8);
    if ( v7[120] == 1 )
    {
      v10 = cam_common_user_dump_helper(v14, cam_mem_mgr_user_dump_buf, v7, 8, "MEM_MGR_BUF.%d:", (int)v8 + 2048);
      if ( v10 )
      {
        v4 = v10;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          16,
          1,
          "cam_mem_mgr_dump_user",
          3502,
          "Dump state info failed, rc: %d",
          v10);
        mutex_unlock(v7 + 8);
        goto LABEL_8;
      }
    }
    mutex_unlock(v7 + 8);
    v9 = __CFADD__(v8++, 1);
    v7 += 296;
  }
  while ( !v9 );
  v11 = *(_DWORD *)(a1 + 16);
  *(_QWORD *)(a1 + 8) = v15;
  cam_mem_put_cpu_buf(v11);
  v4 = 0;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return v4;
}
