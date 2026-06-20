const char *__fastcall ipa3_usb_state_to_string(unsigned int a1)
{
  if ( a1 > 7 )
    return "UNSUPPORTED";
  else
    return off_1E52B8[a1];
}
