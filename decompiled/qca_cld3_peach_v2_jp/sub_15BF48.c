__int64 sub_15BF48()
{
  __int64 v0; // x24

  if ( (v0 & 0x10000000000000LL) != 0 )
    JUMPOUT(0x15BA4C);
  return hif_bus_get_context_size();
}
