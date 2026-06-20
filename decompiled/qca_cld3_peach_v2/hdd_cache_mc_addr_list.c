__int64 hdd_cache_mc_addr_list()
{
  unsigned int v0; // w0

  v0 = ucfg_pmo_cache_mc_addr_list();
  return qdf_status_to_os_return(v0);
}
