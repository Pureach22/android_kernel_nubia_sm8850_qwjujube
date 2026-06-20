__int64 __fastcall wlan_cfg_pdev_detach(__int64 result)
{
  if ( result )
    return _qdf_mem_free(result);
  return result;
}
