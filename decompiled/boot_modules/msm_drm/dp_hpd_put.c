int *__fastcall dp_hpd_put(int *result)
{
  int v1; // w8
  int *v2; // x19
  __int64 ipc_log_context; // x0

  if ( result )
  {
    v1 = *result;
    if ( *result <= 1 )
    {
      if ( v1 )
      {
        if ( v1 == 1 )
          return result;
        goto LABEL_9;
      }
      return (int *)dp_altmode_put((__int64)result);
    }
    else
    {
      switch ( v1 )
      {
        case 2:
          return (int *)dp_gpio_hpd_put();
        case 3:
          return (int *)dp_lphw_hpd_put();
        case 4:
          return (int *)dp_bridge_hpd_put();
        default:
LABEL_9:
          v2 = result;
          ipc_log_context = get_ipc_log_context(result);
          ipc_log_string(
            ipc_log_context,
            "[e][%-4d]unknown hpd type %d\n",
            *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
            *v2);
          return (int *)printk(&unk_2115B7, "dp_hpd_put");
      }
    }
  }
  return result;
}
