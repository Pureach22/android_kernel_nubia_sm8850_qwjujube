__int64 sub_16EF4C()
{
  __int64 v0; // x24

  if ( (v0 & 0x10000000000000LL) != 0 )
    JUMPOUT(0x16EA50);
  return hif_bus_get_context_size();
}
