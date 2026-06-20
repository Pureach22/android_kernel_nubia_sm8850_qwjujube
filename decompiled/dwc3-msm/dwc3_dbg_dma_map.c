__int64 __fastcall dwc3_dbg_dma_map(__int64 result, unsigned __int8 a2, __int64 a3)
{
  const char *v3; // x3

  if ( a2 >= 2u )
  {
    if ( (a2 & 1) != 0 )
      v3 = "IN";
    else
      v3 = "OUT";
    return ipc_log_string(
             result,
             "%02X-%-3.3s %-25.25s 0x%pK %pad %u %pad",
             a2 >> 1,
             v3,
             "MAP",
             a3,
             a3 + 16,
             *(unsigned int *)(a3 + 8),
             a3 + 176);
  }
  return result;
}
