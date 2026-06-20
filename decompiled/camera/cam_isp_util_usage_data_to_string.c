const char *__fastcall cam_isp_util_usage_data_to_string(int a1)
{
  if ( (unsigned int)(a1 - 1) > 5 )
    return "USAGE_INVALID";
  else
    return off_451530[a1 - 1];
}
