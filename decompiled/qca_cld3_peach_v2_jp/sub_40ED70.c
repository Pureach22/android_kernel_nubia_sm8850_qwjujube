__int64 sub_40ED70()
{
  __int64 v0; // x13

  if ( (v0 & 0x1000000000LL) == 0 )
    JUMPOUT(0x4090A8);
  return pld_get_global_context();
}
