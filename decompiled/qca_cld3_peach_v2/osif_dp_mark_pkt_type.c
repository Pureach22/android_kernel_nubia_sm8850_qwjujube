bool __fastcall osif_dp_mark_pkt_type(__int64 a1)
{
  __int64 v2; // x20
  char v3; // w8
  __int64 v4; // x0
  _BOOL8 result; // x0
  char v6; // w8
  char v7; // w8

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
  v4 = *(_QWORD *)(a1 + 224);
  if ( !*(_WORD *)(a1 + 124) )
  {
    result = _qdf_nbuf_data_is_ipv4_eapol_pkt(v4);
    if ( result )
    {
      v7 = 8;
    }
    else
    {
      result = _qdf_nbuf_data_is_ipv4_arp_pkt(*(_QWORD *)(a1 + 224));
      if ( result )
      {
        v7 = 16;
      }
      else
      {
        result = _qdf_nbuf_data_is_ipv4_dhcp_pkt(*(_QWORD *)(a1 + 224));
        if ( result )
        {
          v7 = 32;
        }
        else
        {
          result = _qdf_nbuf_data_is_ipv6_dhcp_pkt(*(unsigned __int16 **)(a1 + 224));
          if ( result )
          {
            v7 = 56;
          }
          else
          {
            result = _qdf_nbuf_data_is_icmpv6_pkt(*(_QWORD *)(a1 + 224));
            if ( !result )
            {
LABEL_23:
              *(_BYTE *)(a1 + 68) |= 0x80u;
              return result;
            }
            v7 = 48;
          }
        }
      }
    }
    *(_BYTE *)(a1 + 71) = *(_BYTE *)(a1 + 71) & 0x87 | v7;
    goto LABEL_23;
  }
  result = _qdf_nbuf_data_is_icmp_pkt(v4);
  if ( result )
  {
    v6 = 40;
  }
  else
  {
    result = _qdf_nbuf_is_ipv4_wapi_pkt(a1);
    if ( !result )
      return result;
    v6 = 24;
  }
  *(_BYTE *)(a1 + 71) = *(_BYTE *)(a1 + 71) & 0x87 | v6;
  return result;
}
