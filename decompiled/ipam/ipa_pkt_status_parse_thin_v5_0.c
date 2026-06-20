__int64 __fastcall ipa_pkt_status_parse_thin_v5_0(__int64 *a1, __int64 a2)
{
  __int64 v2; // x21
  long double v5; // q0
  __int64 ipc_logbuf_low; // x0
  __int64 result; // x0

  v2 = *a1;
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    v5 = ipc_log_string(
           ipc_logbuf_low,
           "ipahal %s:%d Parse Thin Status Packet\n",
           "ipa_pkt_status_parse_thin_v5_0",
           1810);
  }
  *(_DWORD *)(a2 + 4) = a1[1];
  *(_BYTE *)(a2 + 8) = *((_WORD *)a1 + 3);
  *(_BYTE *)(a2 + 9) = a1[3] < 0;
  result = pkt_status_parse_exception((v2 & 0x800000) == 0, *((unsigned __int8 *)a1 + 1), v5);
  *(_DWORD *)a2 = result;
  return result;
}
