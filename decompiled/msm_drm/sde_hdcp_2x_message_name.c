const char *__fastcall sde_hdcp_2x_message_name(unsigned int a1)
{
  if ( a1 > 0x12 )
    return "UNKNOWN";
  else
    return off_280550[a1];
}
