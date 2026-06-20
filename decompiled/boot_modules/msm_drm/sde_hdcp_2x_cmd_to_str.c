const char *__fastcall sde_hdcp_2x_cmd_to_str(int a1)
{
  if ( (unsigned int)(a1 - 3) > 0xD )
    return "UNKNOWN";
  else
    return off_27FCA0[a1 - 3];
}
