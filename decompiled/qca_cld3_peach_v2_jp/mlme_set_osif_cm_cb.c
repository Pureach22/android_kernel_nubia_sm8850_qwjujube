void *__fastcall mlme_set_osif_cm_cb(void *result)
{
  glbl_cm_ops_cb = result;
  return result;
}
