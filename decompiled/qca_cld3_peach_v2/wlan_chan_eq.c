__int64 __fastcall wlan_chan_eq(__int64 a1, __int64 a2)
{
  if ( *(unsigned __int8 *)(a1 + 2) == *(unsigned __int8 *)(a2 + 2)
    && *(unsigned __int8 *)(a1 + 4) == *(unsigned __int8 *)(a2 + 4)
    && *(unsigned __int16 *)(a1 + 32) == *(unsigned __int16 *)(a2 + 32) )
  {
    return 0;
  }
  else
  {
    return 16;
  }
}
