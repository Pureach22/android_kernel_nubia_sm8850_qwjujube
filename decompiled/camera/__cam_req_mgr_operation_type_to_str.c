const char *__fastcall _cam_req_mgr_operation_type_to_str(unsigned int a1)
{
  if ( a1 > 5 )
    return "INVALID_TYPE";
  else
    return off_448570[a1];
}
