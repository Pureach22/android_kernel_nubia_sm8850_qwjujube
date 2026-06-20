__int64 __fastcall hdd_vdev_ready(__int64 a1)
{
  unsigned int v2; // w0

  v2 = pmo_vdev_ready();
  if ( !v2 )
  {
    v2 = ucfg_reg_11d_vdev_created_update(a1);
    if ( !v2 )
    {
      if ( (wma_capability_enhanced_mcast_filter() & 1) != 0 )
        v2 = pmo_core_enhanced_mc_filter_enable(a1);
      else
        v2 = pmo_core_enhanced_mc_filter_disable(a1);
    }
  }
  return qdf_status_to_os_return(v2);
}
