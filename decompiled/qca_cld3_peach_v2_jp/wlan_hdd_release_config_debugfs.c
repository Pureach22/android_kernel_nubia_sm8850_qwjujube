__int64 __fastcall wlan_hdd_release_config_debugfs(__int64 a1, __int64 a2)
{
  _qdf_mem_free(*(_QWORD *)(a2 + 32));
  *(_QWORD *)(a2 + 32) = 0;
  return 0;
}
