__int64 __fastcall dp_tx_ndp_bw_queues_unpause_flow_ctrl(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 v4; // x9
  __int64 v5; // x11
  _DWORD *v6; // x9
  __int64 v7; // x0

  v3 = *(unsigned __int16 *)(a3 + 136);
  if ( (unsigned int)v3 <= 4 )
  {
    v4 = *(unsigned __int8 *)(a2 + 248);
    if ( ((1LL << v3) & v4) != 0 )
    {
      v5 = a2 + 2 * v3;
      if ( *(_WORD *)(v5 + 152) )
      {
        if ( *(_DWORD *)(a2 + 4 * v3 + 204) <= (int)*(unsigned __int16 *)(v5 + 234) )
          return result;
      }
      else if ( *(_DWORD *)(a2 + 4 * v3 + 204) )
      {
        return result;
      }
      *(_BYTE *)(a2 + 248) = v4 & ~(unsigned __int8)(1LL << v3);
      v6 = *(_DWORD **)(result + 12920);
      v7 = *(unsigned __int8 *)(a2 + 58);
      if ( *(v6 - 1) != 694643930 )
        __break(0x8229u);
      return ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v6)(
               v7,
               (unsigned int)(2 * v3 + 21),
               (unsigned int)(v3 + 13));
    }
  }
  return result;
}
