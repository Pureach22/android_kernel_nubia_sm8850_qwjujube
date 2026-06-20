void *__fastcall mlme_set_osif_twt_cb(void *result)
{
  glbl_twt_ops_cb = result;
  return result;
}
