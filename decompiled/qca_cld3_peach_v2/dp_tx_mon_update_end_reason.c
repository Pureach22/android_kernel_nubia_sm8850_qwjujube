__int64 __fastcall dp_tx_mon_update_end_reason(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  if ( result )
  {
    if ( (unsigned __int8)a4 >= 3u )
    {
      __break(0x5512u);
      return dp_tx_mon_process_status_tlv(result, a2, a3, a4, a5, a6, a7);
    }
    else
    {
      *(_DWORD *)(result + 2576LL * (unsigned __int8)a4 + 39348) |= 1 << a3;
    }
  }
  return result;
}
