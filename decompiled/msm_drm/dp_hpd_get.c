unsigned __int64 __fastcall dp_hpd_get(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v7; // x21
  __int64 v8; // x22
  unsigned __int64 result; // x0
  int v10; // w8
  __int64 ipc_log_context; // x0

  if ( a4 )
  {
    if ( (*(_BYTE *)(a4 + 16) & 1) != 0 )
    {
      v7 = a2;
      v8 = a3;
      result = dp_bridge_hpd_get(a1, a5, a4);
      a2 = v7;
      a3 = v8;
      if ( result <= 0xFFFFFFFFFFFFF000LL )
      {
        v10 = 4;
LABEL_15:
        *(_DWORD *)result = v10;
        if ( *(_QWORD *)(result + 32) )
          goto LABEL_16;
        goto LABEL_19;
      }
    }
  }
  result = dp_lphw_hpd_get(a1, a2, a3, a5);
  if ( result && result <= 0xFFFFFFFFFFFFF000LL )
  {
    v10 = 3;
    goto LABEL_15;
  }
  result = dp_gpio_hpd_get(a1, a5);
  if ( result && result <= 0xFFFFFFFFFFFFF000LL )
  {
    v10 = 2;
    goto LABEL_15;
  }
  result = dp_altmode_get(a1, a5);
  if ( !result || result > 0xFFFFFFFFFFFFF000LL )
  {
    ipc_log_context = get_ipc_log_context(result);
    ipc_log_string(ipc_log_context, "[e][%-4d]Failed to detect HPD type\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_25D86E, "dp_hpd_get");
    return -19;
  }
  *(_DWORD *)result = 0;
  if ( *(_QWORD *)(result + 32) )
  {
LABEL_16:
    if ( *(_QWORD *)(result + 40) )
      goto LABEL_17;
LABEL_20:
    *(_QWORD *)(result + 40) = dp_hpd_host_deinit;
    if ( *(_QWORD *)(result + 16) )
      return result;
    goto LABEL_21;
  }
LABEL_19:
  *(_QWORD *)(result + 32) = dp_hpd_host_init;
  if ( !*(_QWORD *)(result + 40) )
    goto LABEL_20;
LABEL_17:
  if ( *(_QWORD *)(result + 16) )
    return result;
LABEL_21:
  *(_QWORD *)(result + 16) = dp_hpd_isr;
  return result;
}
