__int64 __fastcall hdd_wmm_classify_critical_pkt(__int64 a1, int *a2, _BYTE *a3)
{
  __int64 result; // x0
  int v7; // w8

  result = _qdf_nbuf_data_is_ipv4_eapol_pkt(*(_QWORD *)(a1 + 224));
  if ( (result & 1) != 0 )
  {
    v7 = 6;
LABEL_7:
    *a3 = 1;
    *a2 = v7;
    return result;
  }
  result = _qdf_nbuf_data_is_ipv4_arp_pkt(*(_QWORD *)(a1 + 224));
  if ( (result & 1) != 0
    || (result = _qdf_nbuf_data_is_ipv4_dhcp_pkt(*(_QWORD *)(a1 + 224)), (result & 1) != 0)
    || (result = _qdf_nbuf_data_is_ipv6_dhcp_pkt(*(unsigned __int16 **)(a1 + 224)), (result & 1) != 0)
    || (result = _qdf_nbuf_data_is_icmpv6_pkt(*(_QWORD *)(a1 + 224)), (result & 1) != 0)
    && (result = _qdf_nbuf_data_get_icmpv6_subtype(*(_BYTE **)(a1 + 224)), (unsigned int)(result - 21) <= 1) )
  {
    v7 = 0;
    goto LABEL_7;
  }
  return result;
}
