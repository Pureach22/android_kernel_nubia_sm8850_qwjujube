__int64 __fastcall msm_find_source_device(__int64 a1, unsigned __int16 *a2)
{
  *((_DWORD *)a2 + 12) = 0;
  if ( (unsigned int)msm_find_device_iter() )
    return 1;
  pci_walk_bus(*(_QWORD *)(a1 + 24), msm_find_device_iter, a2);
  if ( *((_DWORD *)a2 + 12) )
    return 1;
  if ( *(_QWORD *)a2 )
  {
    ipc_log_string(
      *(_QWORD *)(*(_QWORD *)a2 + 1704LL),
      "DBG1:%s: PCIe: RC%d: can't find device of ID%04x\n",
      "msm_find_source_device",
      *(_DWORD *)(*(_QWORD *)a2 + 1348LL),
      a2[26]);
    ipc_log_string(
      *(_QWORD *)(*(_QWORD *)a2 + 1696LL),
      "%s: PCIe: RC%d: can't find device of ID%04x\n",
      "msm_find_source_device",
      *(_DWORD *)(*(_QWORD *)a2 + 1348LL),
      a2[26]);
  }
  return 0;
}
