__int64 __fastcall dp_power_set_pixel_clk_parent(__int64 a1, unsigned int a2)
{
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 result; // x0
  __int64 ipc_log_context; // x0
  unsigned int v7; // w20
  __int64 v8; // x0
  __int64 v9; // x0

  if ( !a1 || a2 >= 2 )
  {
    ipc_log_context = get_ipc_log_context(a1);
    ipc_log_string(
      ipc_log_context,
      "[e][%-4d]invalid power data. stream %d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      a2);
    printk(&unk_2299D9, "dp_power_set_pixel_clk_parent");
    return 4294967274LL;
  }
  if ( a2 )
  {
    v3 = *(_QWORD *)(a1 - 32);
    if ( !v3 || !*(_QWORD *)(a1 - 40) )
    {
      v4 = get_ipc_log_context(a1);
      ipc_log_string(v4, "[w][%-4d]skipped for strm_id=%d\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), 1);
LABEL_14:
      printk(&unk_25D13E, "dp_power_set_pixel_clk_parent");
      return 0;
    }
  }
  else
  {
    v3 = *(_QWORD *)(a1 - 48);
    if ( !v3 || !*(_QWORD *)(a1 - 40) )
    {
      v9 = get_ipc_log_context(a1);
      ipc_log_string(v9, "[w][%-4d]skipped for strm_id=%d\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), 0);
      goto LABEL_14;
    }
  }
  result = clk_set_parent(v3);
  if ( (_DWORD)result )
  {
    v7 = result;
    v8 = get_ipc_log_context(result);
    ipc_log_string(v8, "[e][%-4d]failed. strm_id=%d, rc=%d\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), a2, v7);
    printk(&unk_26EEAA, "dp_power_set_pixel_clk_parent");
    return v7;
  }
  return result;
}
