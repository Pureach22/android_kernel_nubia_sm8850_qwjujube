const char *__fastcall cam_fence_op_to_string(unsigned int a1)
{
  if ( a1 > 7 )
    return "INVALID";
  else
    return off_44A7E0[a1];
}
