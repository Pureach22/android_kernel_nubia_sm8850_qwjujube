__int64 __fastcall rmnet_perf_is_quic_initial_packet(__int64 a1, __int64 a2)
{
  int v2; // w20
  __int64 result; // x0
  __int64 v5; // x1
  unsigned __int8 *v6; // x19
  __int64 v7; // x0
  __int64 v8; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v9[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+18h] [xbp-8h]

  v2 = a2;
  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9[0] = 0;
  v8 = 0;
  result = skb_header_pointer(a1, a2, 8, (__int64)&v8);
  if ( result )
  {
    if ( (*(unsigned __int16 *)result == 47873 || *(unsigned __int16 *)(result + 2) == 47873)
      && bswap32(*(unsigned __int16 *)(result + 4)) >> 16 >= 9 )
    {
      v5 = (unsigned int)(v2 + 8);
      if ( *(_DWORD *)(a1 + 112) - (*(_DWORD *)(a1 + 116) + v2) - 8 <= 0 )
      {
        if ( a1 )
        {
          v7 = a1;
          v6 = v9;
          if ( (skb_copy_bits(v7, v5, v9, 1) & 0x80000000) == 0 )
            goto LABEL_7;
        }
      }
      else
      {
        v6 = (unsigned __int8 *)(*(_QWORD *)(a1 + 224) + (int)v5);
        if ( v6 )
        {
LABEL_7:
          result = *v6 > 0xBFu;
          goto LABEL_11;
        }
      }
    }
    result = 0;
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
