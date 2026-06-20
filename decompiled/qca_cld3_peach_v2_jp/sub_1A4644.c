__int64 sub_1A4644()
{
  __int64 v0; // x20
  __int64 v1; // d13
  __int64 v2; // d30

  *(_QWORD *)(v0 - 152) = v2;
  *(_QWORD *)(v0 - 144) = v1;
  return wlan_mgmt_txrx_desc_get();
}
