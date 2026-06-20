__int64 __fastcall dp_panel_set_stream_info(_DWORD *a1, unsigned int a2, int a3, int a4, int a5, int a6)
{
  __int64 ipc_log_context; // x0

  if ( a1 && a2 < 3 )
  {
    a1[229] = a6;
    a1[228] = a2;
    a1[230] = a3;
    a1[231] = a4;
    a1[232] = a5;
    return 0;
  }
  else
  {
    ipc_log_context = get_ipc_log_context(a1);
    ipc_log_string(
      ipc_log_context,
      "[e][%-4d]invalid input. stream_id: %d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      a2);
    printk(&unk_2725D8, "dp_panel_set_stream_info");
    return 4294967274LL;
  }
}
