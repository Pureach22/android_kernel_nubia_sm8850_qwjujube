__int64 __fastcall hdd_convert_ch_width_to_cdp_peer_bw(int a1)
{
  if ( (unsigned int)(a1 - 1) > 6 )
    return 0;
  else
    return (unsigned int)dword_9FF410[a1 - 1];
}
