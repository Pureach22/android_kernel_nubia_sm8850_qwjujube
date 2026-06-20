unsigned __int64 __fastcall gpi_setup_debug(__int64 a1)
{
  _QWORD *v2; // x8
  unsigned __int64 result; // x0
  unsigned __int64 v4; // x8
  unsigned int v5; // w20
  __int64 v6; // x24
  unsigned __int64 v7; // x8
  _QWORD v8[34]; // [xsp+0h] [xbp-110h] BYREF

  v8[32] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD **)(a1 + 400);
  memset(v8, 0, 256);
  snprintf((char *)v8, 0x100u, "%s%llx", "gpi_dma", *v2);
  result = ipc_log_context_create(2, v8, 0);
  *(_QWORD *)(a1 + 472) = result;
  v4 = pdentry;
  *(_DWORD *)(a1 + 480) = 2;
  if ( v4 )
  {
    if ( v4 <= 0xFFFFFFFFFFFFF000LL )
    {
      snprintf((char *)v8, 0x100u, "%llx", **(_QWORD **)(a1 + 400));
      result = debugfs_create_dir(v8, pdentry);
      *(_QWORD *)(a1 + 488) = result;
      if ( result )
      {
        if ( result <= 0xFFFFFFFFFFFFF000LL )
        {
          debugfs_create_u32("ipc_log_lvl", 384, result, a1 + 480);
          result = debugfs_create_u32("klog_lvl", 384, *(_QWORD *)(a1 + 488), a1 + 484);
        }
      }
    }
  }
  if ( *(_DWORD *)(a1 + 424) )
  {
    v5 = 0;
    do
    {
      if ( (*(_DWORD *)(a1 + 428) & (1 << v5)) != 0 || (*(_DWORD *)(a1 + 432) & (1 << v5)) != 0 )
      {
        v6 = *(_QWORD *)(a1 + 464) + 1480LL * (int)v5;
        snprintf((char *)(v6 + 1076), 0x100u, "%s%llx_gpii%d", "gpi_dma", **(_QWORD **)(a1 + 400), v5);
        result = ipc_log_context_create(2, v6 + 1076, 0);
        *(_QWORD *)(v6 + 1064) = 0x100000002LL;
        *(_QWORD *)(v6 + 1056) = result;
        v7 = *(_QWORD *)(a1 + 488);
        if ( v7 )
        {
          if ( v7 <= 0xFFFFFFFFFFFFF000LL )
          {
            snprintf((char *)v8, 0x100u, "gpii%d", v5);
            result = debugfs_create_dir(v8, *(_QWORD *)(a1 + 488));
            *(_QWORD *)(v6 + 1336) = result;
            if ( result )
            {
              if ( result <= 0xFFFFFFFFFFFFF000LL )
              {
                debugfs_create_u32("ipc_log_lvl", 384, result, v6 + 1064);
                result = debugfs_create_u32("klog_lvl", 384, *(_QWORD *)(v6 + 1336), v6 + 1068);
              }
            }
          }
        }
      }
      ++v5;
    }
    while ( v5 < *(_DWORD *)(a1 + 424) );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
