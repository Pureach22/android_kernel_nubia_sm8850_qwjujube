__int64 __fastcall pcie_sm_dump(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x8
  unsigned __int64 v3; // x25
  unsigned __int64 v4; // x26
  __int64 v5; // x22
  int v6; // w23
  __int64 v7; // x24
  int v8; // w0

  if ( *(_QWORD *)(result + 3128) )
  {
    v1 = result;
    if ( result )
      result = ipc_log_string(
                 *(_QWORD *)(result + 1712),
                 "DUMP:%s: PCIe: RC%d State Manager reg dump\n",
                 "pcie_sm_dump",
                 *(_DWORD *)(result + 1348));
    v2 = *(_QWORD *)(v1 + 3136);
    if ( *(int *)(v2 + 40) >= 1 && *(_DWORD *)(*(_QWORD *)(v1 + 480) + 8LL) - **(_DWORD **)(v1 + 480) != -1 )
    {
      v3 = 0;
      v4 = (unsigned int)(*(_DWORD *)(*(_QWORD *)(v1 + 480) + 8LL) - **(_DWORD **)(v1 + 480) + 1);
      do
      {
        if ( v1 )
        {
          v5 = *(_QWORD *)(v1 + 1712);
          v6 = *(_DWORD *)(v1 + 1348);
          v7 = *(unsigned int *)(*(_QWORD *)(v2 + 24) + 4 * v3);
          v8 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(v1 + 3128) + v7));
          result = ipc_log_string(v5, "DUMP:%s: RC%d: 0x%04x %08x\n", "pcie_sm_dump", v6, v7, v8);
          v2 = *(_QWORD *)(v1 + 3136);
        }
        ++v3;
      }
      while ( (__int64)v3 < *(int *)(v2 + 40) && v3 < v4 );
    }
  }
  return result;
}
