bool __fastcall osif_dp_classify_pkt(__int64 a1)
{
  __int64 v2; // x20
  char v3; // w8
  _BOOL8 result; // x0
  char v5; // w8

  v2 = *(_QWORD *)(a1 + 224);
  qdf_mem_set((void *)(a1 + 40), 0x30u, 0);
  if ( (unsigned __int16)(*(_WORD *)(v2 + 2) & *(_WORD *)v2 & *(_WORD *)(v2 + 4)) == 0xFFFF )
  {
    v3 = 2;
  }
  else
  {
    if ( (*(_BYTE *)v2 & 1) == 0 )
      goto LABEL_6;
    v3 = 4;
  }
  *(_BYTE *)(a1 + 71) |= v3;
LABEL_6:
  result = _qdf_nbuf_data_is_ipv4_arp_pkt(*(_QWORD *)(a1 + 224));
  if ( result )
  {
    v5 = 16;
  }
  else
  {
    result = _qdf_nbuf_data_is_ipv4_dhcp_pkt(*(_QWORD *)(a1 + 224));
    if ( result )
    {
      v5 = 32;
    }
    else
    {
      result = _qdf_nbuf_data_is_ipv4_eapol_pkt(*(_QWORD *)(a1 + 224));
      if ( result )
      {
        v5 = 8;
      }
      else
      {
        result = _qdf_nbuf_is_ipv4_wapi_pkt(a1);
        if ( result )
        {
          v5 = 24;
        }
        else
        {
          result = _qdf_nbuf_data_is_icmp_pkt(*(_QWORD *)(a1 + 224));
          if ( result )
          {
            v5 = 40;
          }
          else
          {
            result = _qdf_nbuf_data_is_icmpv6_pkt(*(_QWORD *)(a1 + 224));
            if ( !result )
              return result;
            v5 = 48;
          }
        }
      }
    }
  }
  *(_BYTE *)(a1 + 71) = *(_BYTE *)(a1 + 71) & 0x87 | v5;
  return result;
}
