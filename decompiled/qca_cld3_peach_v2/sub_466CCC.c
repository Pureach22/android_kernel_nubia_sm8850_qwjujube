__int64 sub_466CCC()
{
  __int64 v0; // x13

  if ( (v0 & 0x1000000000LL) == 0 )
    JUMPOUT(0x461004);
  return pld_get_global_context();
}
