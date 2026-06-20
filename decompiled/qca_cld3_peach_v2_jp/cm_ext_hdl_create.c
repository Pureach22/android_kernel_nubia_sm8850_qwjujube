__int64 __fastcall cm_ext_hdl_create(__int64 a1, __int64 *a2)
{
  __int64 v4; // x0

  v4 = _qdf_mem_malloc(0x670u, "cm_ext_hdl_create", 321);
  *a2 = v4;
  if ( !v4 )
    return 2;
  wlan_cm_rso_config_init(a1, v4);
  return 0;
}
