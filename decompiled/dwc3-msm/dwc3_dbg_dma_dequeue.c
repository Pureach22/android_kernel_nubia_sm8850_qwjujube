__int64 __fastcall dwc3_dbg_dma_dequeue(__int64 result, unsigned __int8 a2, __int64 a3)
{
  __int64 v3; // x29
  __int64 v4; // x30
  const char *v5; // x3

  if ( a2 >= 2u )
  {
    if ( (a2 & 1) != 0 )
      v5 = "IN";
    else
      v5 = "OUT";
    return ipc_log_string(
             result,
             "%02X-%-3.3s %-25.25s 0x%pK %pad %pad",
             a2 >> 1,
             v5,
             "DEQUEUE",
             a3,
             a3 + 16,
             a3 + 176,
             v3,
             v4);
  }
  return result;
}
