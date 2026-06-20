unsigned int *__fastcall crm_timer_reset(unsigned int *result)
{
  if ( result )
    return (unsigned int *)cam_common_modify_timer(result + 2, *result);
  return result;
}
