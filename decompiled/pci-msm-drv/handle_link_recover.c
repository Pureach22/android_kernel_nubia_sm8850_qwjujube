__int64 __fastcall handle_link_recover(__int64 a1)
{
  __int64 v1; // x19
  _DWORD *v2; // x21

  v1 = a1 - 1760;
  if ( a1 != 1760 )
  {
    v2 = (_DWORD *)(a1 - 412);
    ipc_log_string(
      *(_QWORD *)(a1 - 56),
      "DBG1:%s: PCIe: link recover start for RC%d\n",
      "handle_link_recover",
      *(_DWORD *)(a1 - 412));
    ipc_log_string(*(_QWORD *)(a1 - 64), "%s: PCIe: link recover start for RC%d\n", "handle_link_recover", *v2);
  }
  return msm_pcie_notify_client(v1, 64);
}
