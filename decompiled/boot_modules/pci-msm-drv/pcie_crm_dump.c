__int64 __fastcall pcie_crm_dump(__int64 result)
{
  __int64 v1; // x19

  if ( *(_QWORD *)(result + 3128) )
  {
    v1 = result;
    result = crm_dump_regs("pcie_crm");
    if ( v1 )
    {
      if ( (_DWORD)result )
        return ipc_log_string(
                 *(_QWORD *)(v1 + 1712),
                 "DUMP:%s: PCIe: RC%d Error dumping crm regs %d\n",
                 "pcie_crm_dump",
                 *(_DWORD *)(v1 + 1348),
                 result);
    }
  }
  return result;
}
