const char *__fastcall hdcp_transport_cmd_to_str(int a1)
{
  if ( (unsigned int)(a1 - 1) > 6 )
    return "UNKNOWN";
  else
    return off_280518[a1 - 1];
}
