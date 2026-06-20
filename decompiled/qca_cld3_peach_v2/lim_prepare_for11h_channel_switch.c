__int64 __fastcall lim_prepare_for11h_channel_switch(__int64 a1, __int64 a2)
{
  unsigned int v2; // w8

  if ( *(_DWORD *)(a2 + 88) != 2 )
    return 4;
  v2 = *(unsigned __int8 *)(a2 + 8);
  *(_DWORD *)(a2 + 7196) = 1;
  return lim_stop_tx_and_switch_channel(a1, v2);
}
