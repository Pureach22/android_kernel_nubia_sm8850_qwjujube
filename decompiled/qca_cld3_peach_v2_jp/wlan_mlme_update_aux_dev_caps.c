char *__fastcall wlan_mlme_update_aux_dev_caps(__int64 a1, const void *a2)
{
  char *result; // x0

  result = (char *)mlme_get_psoc_ext_obj_fl(a1);
  if ( result )
    return (char *)qdf_mem_copy(result + 1132, a2, 0x84u);
  return result;
}
