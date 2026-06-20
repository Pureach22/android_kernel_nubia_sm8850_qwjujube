void *__fastcall wlan_cm_free_connect_req(void *result)
{
  if ( result )
    return (void *)cm_free_connect_req(result);
  return result;
}
