__int64 __fastcall gh_dbgfs_hyp_uart_ctrl_fops_open(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  return simple_attr_open(a1, a2, gh_dbgfs_hyp_uart_get, gh_dbgfs_hyp_uart_set, "0x%llx\n", a6);
}
