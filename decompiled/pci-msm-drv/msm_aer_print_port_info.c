__int64 __fastcall msm_aer_print_port_info(__int64 result, unsigned int *a2)
{
  unsigned __int64 v2; // x8
  __int64 v4; // x10
  __int64 v5; // x19
  const char *v6; // x4
  unsigned __int64 v7; // x8
  __int64 v8; // x9
  const char *v9; // x4

  if ( *(_QWORD *)a2 )
  {
    v2 = a2[13];
    v4 = (v2 >> 16) & 3;
    if ( (_DWORD)v4 == 3
      || ((v5 = result, (v2 & 0x800000) != 0) ? (v6 = "Multiple ") : (v6 = (const char *)&unk_24FCB),
          result = ipc_log_string(
                     *(_QWORD *)(*(_QWORD *)a2 + 1704LL),
                     "DBG1:%s: PCIe: RC%d: %s%s error received: %04x:%02x:%02x.%d\n",
                     "msm_aer_print_port_info",
                     *(_DWORD *)(*(_QWORD *)a2 + 1348LL),
                     v6,
                     aer_error_severity_string[v4],
                     *(_DWORD *)(*(_QWORD *)(result + 16) + 252LL),
                     (unsigned __int8)BYTE1(a2[13]),
                     (unsigned __int8)a2[13] >> 3,
                     a2[13] & 7),
          v7 = a2[13],
          v8 = (v7 >> 16) & 3,
          (_DWORD)v8 == 3) )
    {
      __break(0x5512u);
      return msm_find_source_device(result, a2);
    }
    else
    {
      if ( (v7 & 0x800000) != 0 )
        v9 = "Multiple ";
      else
        v9 = (const char *)&unk_24FCB;
      return ipc_log_string(
               *(_QWORD *)(*(_QWORD *)a2 + 1696LL),
               "%s: PCIe: RC%d: %s%s error received: %04x:%02x:%02x.%d\n",
               "msm_aer_print_port_info",
               *(_DWORD *)(*(_QWORD *)a2 + 1348LL),
               v9,
               aer_error_severity_string[v8],
               *(_DWORD *)(*(_QWORD *)(v5 + 16) + 252LL),
               (unsigned __int8)BYTE1(a2[13]),
               (unsigned __int8)a2[13] >> 3,
               a2[13] & 7);
    }
  }
  return result;
}
