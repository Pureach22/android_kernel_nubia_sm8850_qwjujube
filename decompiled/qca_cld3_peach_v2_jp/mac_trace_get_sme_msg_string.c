const char *__fastcall mac_trace_get_sme_msg_string(__int16 a1)
{
  if ( (unsigned __int16)(a1 - 5121) > 0xB2u )
    return "UNKNOWN";
  else
    return off_A166C8[(unsigned __int16)(a1 - 5121)];
}
