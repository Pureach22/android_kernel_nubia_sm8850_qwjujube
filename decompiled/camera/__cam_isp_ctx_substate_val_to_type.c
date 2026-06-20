const char *__fastcall _cam_isp_ctx_substate_val_to_type(unsigned int a1)
{
  if ( a1 > 6 )
    return "INVALID";
  else
    return off_451850[a1];
}
