const char *__fastcall get_e_roam_cmd_status_str(int a1)
{
  if ( (unsigned int)(a1 - 12) > 0x27 )
    return "unknown";
  else
    return off_B09718[a1 - 12];
}
