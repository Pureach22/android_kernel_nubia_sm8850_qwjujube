void *__fastcall wlan_mlme_get_wps_uuid(__int64 a1, void *a2)
{
  return qdf_mem_copy(a2, (const void *)(a1 + 40), *(unsigned int *)(a1 + 32));
}
