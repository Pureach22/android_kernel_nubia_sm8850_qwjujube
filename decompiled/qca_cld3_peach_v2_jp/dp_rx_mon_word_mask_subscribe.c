__int64 __fastcall dp_rx_mon_word_mask_subscribe(__int64 result, __int64 a2, int a3, __int64 a4)
{
  int v4; // w8

  if ( a2 && a4 && (*(_BYTE *)(a4 + 75) & 0x80) != 0 )
  {
    if ( a3 )
    {
      __break(0x5512u);
      return dp_rx_mon_pkt_tlv_offset_subscribe();
    }
    else if ( !*(_BYTE *)(*(_QWORD *)(*(_QWORD *)(result + 72) + 95560LL) + 39097LL) )
    {
      v4 = *(_DWORD *)a2 | 0x800000;
      *(_QWORD *)(a2 + 12) = 0xAE1000707F8LL;
      *(_QWORD *)(a2 + 24) = 0xAE10FF007F8LL;
      *(_DWORD *)a2 = v4;
      *(_DWORD *)(a2 + 32) = 3967;
    }
  }
  return result;
}
