__int64 __fastcall wlan_chan_eq(__int64 a1, __int64 a2)
{
  if ( *(unsigned __int8 *)(a1 + 2) == *(unsigned __int8 *)(a2 + 2) )
    return 16 * (unsigned int)(*(unsigned __int8 *)(a1 + 4) != *(unsigned __int8 *)(a2 + 4));
  else
    return 16;
}
