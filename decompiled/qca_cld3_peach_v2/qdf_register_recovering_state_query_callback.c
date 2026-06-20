void *__fastcall qdf_register_recovering_state_query_callback(void *result)
{
  is_recovering_cb = result;
  return result;
}
