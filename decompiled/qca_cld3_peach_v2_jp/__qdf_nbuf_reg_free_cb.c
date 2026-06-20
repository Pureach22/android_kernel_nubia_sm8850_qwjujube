void *__fastcall _qdf_nbuf_reg_free_cb(void *result)
{
  nbuf_free_cb = result;
  return result;
}
