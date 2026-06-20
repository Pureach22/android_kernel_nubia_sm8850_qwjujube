__int64 __fastcall dp_power_clk_status(_BYTE *a1, int a2)
{
  char v2; // w8
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    v2 = 0;
    if ( a2 > 3 )
    {
      if ( a2 == 4 )
      {
        v2 = a1[123];
      }
      else if ( a2 == 5 )
      {
        return a1[121] & 1;
      }
    }
    else
    {
      if ( !a2 )
        return a1[120] & 1;
      if ( a2 == 3 )
        return a1[122] & 1;
    }
    return v2 & 1;
  }
  else
  {
    ipc_log_context = get_ipc_log_context((unsigned __int8)a1);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid power data\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_22992C, "dp_power_clk_status");
    return 0;
  }
}
