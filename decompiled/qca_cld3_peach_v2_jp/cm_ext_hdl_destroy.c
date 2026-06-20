__int64 __fastcall cm_ext_hdl_destroy(__int64 a1, __int64 a2)
{
  wlan_cm_rso_config_deinit();
  _qdf_mem_free(a2);
  return 0;
}
