__int64 __fastcall dp_nud_incr_gw_rx_pkt_cnt(__int64 result, __int64 a2)
{
  unsigned int v8; // w9

  if ( *(_BYTE *)(result + 3568) == 1
    && *(_BYTE *)(result + 3569) == 1
    && *(_DWORD *)(result + 3512) == *(_DWORD *)a2
    && *(unsigned __int16 *)(result + 3516) == *(unsigned __int16 *)(a2 + 4) )
  {
    _X8 = (unsigned int *)(result + 3508);
    __asm { PRFM            #0x11, [X8] }
    do
      v8 = __ldxr(_X8);
    while ( __stxr(v8 + 1, _X8) );
  }
  return result;
}
