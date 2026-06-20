__int64 __fastcall extract_cfr_peer_tx_event_param_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 *a10,
        __int64 a11)
{
  __int64 v11; // x21
  __int64 v14; // x8

  if ( a10 )
  {
    v11 = *a10;
    if ( *a10 )
    {
      *(_DWORD *)a11 = *(_DWORD *)(v11 + 4);
      *(_DWORD *)(a11 + 4) = *(_DWORD *)(v11 + 8);
      *(_WORD *)(a11 + 8) = *(_DWORD *)(v11 + 12);
      *(_BYTE *)(a11 + 10) = *(_WORD *)(v11 + 14);
      *(_BYTE *)(a11 + 11) = *(_BYTE *)(v11 + 15);
      *(_WORD *)(a11 + 12) = *(_DWORD *)(v11 + 16);
      *(_DWORD *)(a11 + 16) = *(_DWORD *)(v11 + 20);
      *(_DWORD *)(a11 + 20) = *(_DWORD *)(v11 + 24);
      *(_DWORD *)(a11 + 24) = *(_DWORD *)(v11 + 28);
      *(_DWORD *)(a11 + 28) = *(_DWORD *)(v11 + 32);
      *(_DWORD *)(a11 + 32) = *(_DWORD *)(v11 + 36);
      *(_DWORD *)(a11 + 36) = *(_DWORD *)(v11 + 40);
      *(_DWORD *)(a11 + 40) = *(_DWORD *)(v11 + 44);
      *(_DWORD *)(a11 + 44) = *(_DWORD *)(v11 + 48);
      *(_DWORD *)(a11 + 48) = *(_DWORD *)(v11 + 52);
      *(_DWORD *)(a11 + 52) = *(_DWORD *)(v11 + 56);
      *(_DWORD *)(a11 + 56) = *(_DWORD *)(v11 + 60);
      qdf_mem_copy((void *)(a11 + 60), (const void *)(v11 + 64), 0x20u);
      *(_DWORD *)(a11 + 108) = (unsigned __int16)((__int16)((unsigned __int16)*(_DWORD *)(v11 + 96) << 15) >> 15)
                             & (unsigned __int16)(*(_DWORD *)(v11 + 96) >> 1)
                             & 0x3FFF;
      *(_DWORD *)(a11 + 120) = *(_DWORD *)(v11 + 100);
      *(_DWORD *)(a11 + 124) = *(_DWORD *)(v11 + 104);
      *(_DWORD *)(a11 + 128) = *(unsigned __int8 *)(v11 + 108);
      *(_DWORD *)(a11 + 132) = *(unsigned __int8 *)(v11 + 109);
      v14 = a10[2];
      if ( v14 )
      {
        *(_WORD *)(a11 + 92) = *(_DWORD *)(v14 + 4);
        *(_BYTE *)(a11 + 112) = *(_DWORD *)(v14 + 36);
        *(_BYTE *)(a11 + 136) = *(_DWORD *)(v14 + 44);
        *(_WORD *)(a11 + 94) = *(_DWORD *)(v14 + 8);
        *(_BYTE *)(a11 + 113) = BYTE1(*(_DWORD *)(v14 + 36));
        *(_BYTE *)(a11 + 137) = BYTE1(*(_DWORD *)(v14 + 44));
        *(_WORD *)(a11 + 96) = *(_DWORD *)(v14 + 12);
        *(_BYTE *)(a11 + 114) = *(_WORD *)(v14 + 38);
        *(_BYTE *)(a11 + 138) = *(_WORD *)(v14 + 46);
        *(_WORD *)(a11 + 98) = *(_DWORD *)(v14 + 16);
        *(_BYTE *)(a11 + 115) = *(_BYTE *)(v14 + 39);
        *(_BYTE *)(a11 + 139) = *(_BYTE *)(v14 + 47);
        *(_WORD *)(a11 + 100) = *(_DWORD *)(v14 + 20);
        *(_BYTE *)(a11 + 116) = *(_DWORD *)(v14 + 40);
        *(_BYTE *)(a11 + 140) = *(_DWORD *)(v14 + 48);
        *(_WORD *)(a11 + 102) = *(_DWORD *)(v14 + 24);
        *(_BYTE *)(a11 + 117) = BYTE1(*(_DWORD *)(v14 + 40));
        *(_BYTE *)(a11 + 141) = BYTE1(*(_DWORD *)(v14 + 48));
        *(_WORD *)(a11 + 104) = *(_DWORD *)(v14 + 28);
        *(_BYTE *)(a11 + 118) = *(_WORD *)(v14 + 42);
        *(_BYTE *)(a11 + 142) = *(_WORD *)(v14 + 50);
        *(_WORD *)(a11 + 106) = *(_DWORD *)(v14 + 32);
        *(_BYTE *)(a11 + 119) = *(_BYTE *)(v14 + 43);
        *(_BYTE *)(a11 + 143) = *(_BYTE *)(v14 + 51);
      }
      return 0;
    }
    else
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: peer cfr capture buffer is null",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_cfr_peer_tx_event_param_tlv");
      return 29;
    }
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Invalid cfr capture buffer",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_cfr_peer_tx_event_param_tlv");
    return 4;
  }
}
