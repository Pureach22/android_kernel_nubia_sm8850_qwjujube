void *__fastcall qdf_register_mc_timer_callback(void *result)
{
  scheduler_timer_callback = result;
  return result;
}
