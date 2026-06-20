void *__fastcall wlan_cm_free_connect_resp(void *result)
{
  if ( result )
    return (void *)cm_free_connect_rsp(result);
  return result;
}
