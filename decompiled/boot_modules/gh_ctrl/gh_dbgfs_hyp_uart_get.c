__int64 __fastcall gh_dbgfs_hyp_uart_get(__int64 a1, _QWORD *a2)
{
  *a2 = (unsigned __int8)hyp_uart_enable;
  return 0;
}
