__int64 __fastcall hal_rx_flow_get_tuple_info_be(_QWORD *a1, int a2, __int64 a3)
{
  __int64 result; // x0
  __int64 v5; // x8

  result = 0;
  if ( a3 )
  {
    v5 = *a1 + (unsigned int)(a2 << 6);
    if ( v5 )
    {
      if ( (*(_BYTE *)(v5 + 37) & 1) != 0 )
      {
        *(_DWORD *)(a3 + 16) = bswap32(*(_DWORD *)v5);
        *(_DWORD *)(a3 + 20) = bswap32(*(_DWORD *)(v5 + 4));
        *(_DWORD *)(a3 + 24) = bswap32(*(_DWORD *)(v5 + 8));
        *(_DWORD *)(a3 + 28) = bswap32(*(_DWORD *)(v5 + 12));
        *(_DWORD *)a3 = bswap32(*(_DWORD *)(v5 + 16));
        *(_DWORD *)(a3 + 4) = bswap32(*(_DWORD *)(v5 + 20));
        *(_DWORD *)(a3 + 8) = bswap32(*(_DWORD *)(v5 + 24));
        *(_DWORD *)(a3 + 12) = bswap32(*(_DWORD *)(v5 + 28));
        *(_WORD *)(a3 + 32) = *(_WORD *)(v5 + 34);
        *(_WORD *)(a3 + 34) = *(_DWORD *)(v5 + 32);
        *(_WORD *)(a3 + 36) = *(unsigned __int8 *)(v5 + 36);
        return v5;
      }
      else
      {
        return 0;
      }
    }
  }
  return result;
}
