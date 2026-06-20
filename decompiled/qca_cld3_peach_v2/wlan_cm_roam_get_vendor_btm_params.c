char *__fastcall wlan_cm_roam_get_vendor_btm_params(__int64 a1, void *a2)
{
  char *result; // x0

  result = (char *)mlme_get_psoc_ext_obj_fl(a1);
  if ( result )
    return (char *)qdf_mem_copy(a2, result + 1688, 0x18u);
  return result;
}
