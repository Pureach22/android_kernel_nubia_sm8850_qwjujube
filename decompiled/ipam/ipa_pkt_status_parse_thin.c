__int64 __fastcall ipa_pkt_status_parse_thin(__int64 *a1, __int64 a2)
{
  __int64 v2; // x21
  long double v5; // q0
  __int64 ipc_logbuf_low; // x0
  __int64 result; // x0

  v2 = *a1;
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    v5 = ipc_log_string(ipc_logbuf_low, "ipahal %s:%d Parse Thin Status Packet\n", "ipa_pkt_status_parse_thin", 1786);
  }
  *(_DWORD *)(a2 + 4) = a1[1];
  *(_BYTE *)(a2 + 8) = *((_BYTE *)a1 + 6) & 0x1F;
  *(_BYTE *)(a2 + 9) = *((_BYTE *)a1 + 14) & 1;
  result = pkt_status_parse_exception((v2 & 0x800000) == 0, *((unsigned __int8 *)a1 + 1), v5);
  *(_DWORD *)a2 = result;
  return result;
}
