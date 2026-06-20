void *__fastcall qdf_register_get_dump_inprogress_cb(void *result)
{
  get_dump_inprogress_cb = result;
  return result;
}
