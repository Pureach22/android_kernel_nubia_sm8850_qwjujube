__int64 ipa_config_mem_alloc()
{
  __int64 v1; // x0

  if ( g_ipa_config )
    return 0;
  v1 = _qdf_mem_malloc(0x28u, "ipa_config_mem_alloc", 79);
  if ( !v1 )
    return 2;
  g_ipa_config = v1;
  return 0;
}
