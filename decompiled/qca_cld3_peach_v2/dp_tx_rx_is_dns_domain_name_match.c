bool __fastcall dp_tx_rx_is_dns_domain_name_match(__int64 a1, __int64 a2)
{
  int v2; // w8
  int v3; // w10
  const char *dns_domain_name; // x0

  v2 = *(_DWORD *)(a2 + 3340);
  if ( !v2 )
    return 0;
  v3 = (*(_BYTE *)(a1 + 68) & 4) != 0 ? *(unsigned __int16 *)(a1 + 66) : 0;
  if ( *(_DWORD *)(a1 + 112) + v3 < (unsigned int)(v2 + 54) )
    return 0;
  dns_domain_name = (const char *)_qdf_nbuf_get_dns_domain_name(*(_QWORD *)(a1 + 224));
  return strncmp(dns_domain_name, (const char *)(a2 + 3084), *(unsigned int *)(a2 + 3340)) == 0;
}
