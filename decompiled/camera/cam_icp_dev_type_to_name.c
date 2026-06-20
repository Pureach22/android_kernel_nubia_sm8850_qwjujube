const char *__fastcall cam_icp_dev_type_to_name(int a1)
{
  if ( (unsigned int)(a1 - 1) > 8 )
    return "Invalid dev type";
  else
    return off_451FD8[a1 - 1];
}
