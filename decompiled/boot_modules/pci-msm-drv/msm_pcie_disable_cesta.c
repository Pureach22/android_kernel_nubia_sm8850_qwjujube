__int64 __fastcall msm_pcie_disable_cesta(__int64 result)
{
  __int64 v1; // x20
  int v2; // w19

  if ( *(_QWORD *)(result + 3128) )
  {
    v1 = result;
    result = msm_pcie_cesta_map_apply(result, 0);
    if ( (_DWORD)result )
    {
      v2 = result;
      if ( v1 )
      {
        ipc_log_string(
          *(_QWORD *)(v1 + 1704),
          "ERR:%s: Fail to move to D3 cold state %d\n",
          "msm_pcie_disable_cesta",
          result);
        ipc_log_string(*(_QWORD *)(v1 + 1696), "%s: Fail to move to D3 cold state %d\n", "msm_pcie_disable_cesta", v2);
      }
      return printk(&unk_2717E);
    }
  }
  return result;
}
