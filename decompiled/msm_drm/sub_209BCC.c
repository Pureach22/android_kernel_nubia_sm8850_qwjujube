// positive sp value has been detected, the output may be wrong!
__int64 sub_209BCC()
{
  unsigned int v0; // w23
  unsigned int v1; // w23
  unsigned int v2; // w23
  unsigned int v3; // w23
  __int64 v4; // x8
  unsigned int v5; // w1
  unsigned int v6; // w21
  _DWORD *v7; // x9
  unsigned int v8; // w19
  __int64 v9; // x20
  const char *v10; // x21
  __int64 v11; // x22
  unsigned int v12; // w23
  __int64 v13; // x24
  __int64 v14; // x25
  char v16[112]; // [xsp-70h] [xbp-70h] BYREF

  if ( v14 )
    return msm_ioctl_deregister_event();
  sde_dbg_reg_register_dump_range(v11, v16, v12, v12 + 128, *(_DWORD *)(*(_QWORD *)(v9 + 16) + 40LL));
  v0 = *(_DWORD *)(*(_QWORD *)(v9 + 16) + 16LL) + 2747792;
  snprintf(v16, 0x14u, v10, 3);
  sde_dbg_reg_register_dump_range(v11, v16, v0, v0 + 128, *(_DWORD *)(*(_QWORD *)(v9 + 16) + 40LL));
  v1 = *(_DWORD *)(*(_QWORD *)(v9 + 16) + 16LL) + 1101372;
  snprintf(v16, 0x14u, v10, 4);
  sde_dbg_reg_register_dump_range(v11, v16, v1, v1 + 128, *(_DWORD *)(*(_QWORD *)(v9 + 16) + 40LL));
  v2 = *(_DWORD *)(*(_QWORD *)(v9 + 16) + 16LL) + 2747898;
  snprintf(v16, 0x14u, v10, 5);
  sde_dbg_reg_register_dump_range(v11, v16, v2, v2 + 128, *(_DWORD *)(*(_QWORD *)(v9 + 16) + 40LL));
  v3 = *(_DWORD *)(*(_QWORD *)(v9 + 16) + 16LL) + 2747780;
  snprintf(v16, 0x14u, v10, 6);
  sde_dbg_reg_register_dump_range(v11, v16, v3, v3 + 128, *(_DWORD *)(*(_QWORD *)(v9 + 16) + 40LL));
  qword_299EA0 = 0x104400001044LL;
  qword_299EA8 = 0x204400002044LL;
  qword_299ED8 = 0x104800001048LL;
  qword_299EE0 = 0x204800002048LL;
  qword_299F10 = 0x105400001054LL;
  qword_299F18 = 0x205400002054LL;
  qword_299EB0 = 0x304400003044LL;
  qword_299EB8 = 0x404400004044LL;
  qword_B650 = 0x1000000008LL;
  qword_B658 = 0x1000000008LL;
  qword_299EE8 = 0x304800003048LL;
  qword_299EF0 = 0x404800004048LL;
  qword_B660 = 0x1000000008LL;
  qword_B668 = 0x1000000008LL;
  qword_299F20 = 0x305400003054LL;
  qword_299F28 = 0x405400004054LL;
  qword_B670 = 0x1000000008LL;
  qword_B678 = 0x1000000008LL;
  qword_299EC0 = 0x504400005044LL;
  qword_299EC8 = 0x604400006044LL;
  qword_299EF8 = 0x504800005048LL;
  qword_299F00 = 0x604800006048LL;
  qword_299F30 = 0x505400005054LL;
  qword_299F38 = 0x605400006054LL;
  dword_B6D0 |= 0xC00u;
  dword_B6D4 |= 0xC00u;
  qword_B6D8 = 0x8000050080000500LL;
  dword_B6E0 = -2147482368;
  if ( v8 >= 2 )
  {
    __break(0x5512u);
    JUMPOUT(0x19C954);
  }
  v4 = last_cmd_buf[v8];
  if ( v4 && *(_QWORD *)(v4 + 24) )
  {
    v5 = *(_DWORD *)(v4 + 16);
    *(_DWORD *)(v4 + 20) = 0;
    *(_QWORD *)(v4 + 40) = 1;
    *(_DWORD *)(v4 + 48) = 0;
    if ( v5 > 3 )
    {
      v7 = *(_DWORD **)(v4 + 32);
      v6 = 0;
      *v7 = *(_DWORD *)(v13 + 3708);
      v7[1] = 0;
      *(_DWORD *)(v4 + 20) = 8;
      *(_QWORD *)(v4 + 40) = 0x7F0000007ELL;
      goto LABEL_10;
    }
    _drm_err("buffer is full sz %d needs %d bytes\n", v5, 4);
    _drm_err("validate last_cmd_buf failed\n");
  }
  else
  {
    _drm_err("invalid last cmd buf for dpu idx %d\n", v8);
  }
  dealloc_reg_dma_v1((_QWORD *)last_cmd_buf[v8], v8);
  v6 = -22;
  last_cmd_buf[v8] = 0;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return v6;
}
