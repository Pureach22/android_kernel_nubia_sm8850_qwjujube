__int64 __fastcall dwc3_dbg_dma_unmap(__int64 result, unsigned __int8 a2, __int64 a3)
{
  __int64 v3; // x29
  __int64 v4; // x30
  const char *v5; // x3
  const char *v6; // x9

  if ( a2 >= 2u )
  {
    if ( (a2 & 1) != 0 )
      v5 = "IN";
    else
      v5 = "OUT";
    v6 = (const char *)&unk_16A05;
    if ( (*(_DWORD *)(*(_QWORD *)(a3 + 168) + 12LL) & 1) != 0 )
      v6 = "HWO";
    return ipc_log_string(
             result,
             "%02X-%-3.3s %-25.25s 0x%pK %pad %u %pad %s",
             a2 >> 1,
             v5,
             "UNMAP",
             a3,
             a3 + 16,
             *(unsigned int *)(a3 + 8),
             a3 + 176,
             v6,
             v3,
             v4);
  }
  return result;
}
