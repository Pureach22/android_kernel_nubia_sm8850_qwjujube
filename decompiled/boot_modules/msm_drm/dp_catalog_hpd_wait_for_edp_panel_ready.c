__int64 __fastcall dp_catalog_hpd_wait_for_edp_panel_ready(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x0
  __int64 v3; // x20
  int v5; // w19
  __int64 ipc_log_context; // x0

  v1 = *(_QWORD *)(*(_QWORD *)(a1 - 1280) + 24LL);
  v2 = readl_0(v1 + 4);
  if ( (v2 & 0x40000000) != 0 )
  {
LABEL_5:
    if ( (v2 & 0x40000000) == 0 )
    {
LABEL_8:
      v5 = v2;
      ipc_log_context = get_ipc_log_context(v2);
      ipc_log_string(
        ipc_log_context,
        "[e][%-4d]DP_HPD_STATE_STATUS CONNECTED bit is still low, status=%x\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        v5);
      printk(&unk_248268, "dp_catalog_hpd_wait_for_edp_panel_ready");
      LODWORD(v2) = v5;
    }
  }
  else
  {
    v3 = 1002000001;
    while ( 1 )
    {
      v3 -= 2000001;
      if ( v3 < 0 )
        break;
      _const_udelay(8590000);
      __yield();
      v2 = readl_0(v1 + 4);
      if ( (v2 & 0x40000000) != 0 )
        goto LABEL_5;
    }
    v2 = readl_0(v1 + 4);
    if ( (v2 & 0x40000000) == 0 )
      goto LABEL_8;
  }
  return ((unsigned int)v2 >> 30) & 1;
}
