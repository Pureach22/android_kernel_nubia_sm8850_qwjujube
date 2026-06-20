__int64 __fastcall dp_tx_update_stats(__int64 result, __int64 a2, unsigned __int8 a3, __int64 a4, __int64 _X4)
{
  unsigned int v5; // w8
  __int64 v6; // x9
  __int64 v7; // x8

  if ( *(_BYTE *)(a2 + 65) == 1 )
    v5 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a2 + 72) + 40LL) + 36LL);
  else
    v5 = *(unsigned __int16 *)(a2 + 16);
  if ( result )
  {
    if ( a3 >= 5u )
    {
      __break(0x5512u);
      __asm { STZG            X4, [X2,#-0x880]! }
      return dp_tx_ring_access_end();
    }
    else
    {
      v6 = result + 16LL * a3;
      v7 = *(_QWORD *)(v6 + 13352) + v5;
      ++*(_QWORD *)(v6 + 13344);
      *(_QWORD *)(v6 + 13352) = v7;
    }
  }
  return result;
}
