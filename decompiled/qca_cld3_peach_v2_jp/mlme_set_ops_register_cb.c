void *__fastcall mlme_set_ops_register_cb(void *result)
{
  glbl_ops_cb = result;
  return result;
}
