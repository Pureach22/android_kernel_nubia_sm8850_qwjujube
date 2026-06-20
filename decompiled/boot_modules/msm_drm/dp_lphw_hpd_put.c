__int64 __fastcall dp_lphw_hpd_put(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x19
  int v3; // w23
  __int64 v4; // x25
  int v5; // w24
  __int64 v6; // x0
  __int64 ipc_log_context; // x0

  if ( result )
  {
    v1 = *(_QWORD *)(result + 72);
    v2 = result;
    v3 = *(_DWORD *)(v1 + 112);
    if ( v3 )
    {
      v4 = *(_QWORD *)(v1 + 120);
      v5 = 0;
      while ( strcmp((const char *)(v4 + 72LL * v5 + 8), "hpd-pwr") )
      {
        if ( v3 == ++v5 )
          goto LABEL_9;
      }
      v6 = msm_dss_enable_vreg(v4 + 72LL * v5, 1, 0);
      if ( (_DWORD)v6 )
      {
        ipc_log_context = get_ipc_log_context(v6);
        ipc_log_string(
          ipc_log_context,
          "[e][%-4d]hpd-pwr vreg not disabled\n",
          *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
        printk(&unk_264C67, "dp_lphw_hpd_deinit");
      }
    }
LABEL_9:
    gpio_free(*(unsigned int *)(v2 + 88));
    return devm_kfree(*(_QWORD *)(v2 - 8));
  }
  return result;
}
