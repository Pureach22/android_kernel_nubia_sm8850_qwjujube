__int64 dp_get_soc_context_size()
{
  if ( (unsigned int)cdp_get_arch_type_from_devid() == 1 )
    return dp_get_soc_context_size_be();
  else
    return 0;
}
