const char *__fastcall cam_isp_hw_evt_type_to_string(unsigned int a1)
{
  if ( a1 > 5 )
    return "INVALID_EVT";
  else
    return off_451420[a1];
}
