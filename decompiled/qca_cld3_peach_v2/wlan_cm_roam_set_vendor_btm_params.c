char *__fastcall wlan_cm_roam_set_vendor_btm_params(__int64 a1, const void *a2)
{
  char *result; // x0

  result = (char *)mlme_get_psoc_ext_obj_fl(a1);
  if ( result )
    return (char *)qdf_mem_copy(result + 1688, a2, 0x18u);
  return result;
}
