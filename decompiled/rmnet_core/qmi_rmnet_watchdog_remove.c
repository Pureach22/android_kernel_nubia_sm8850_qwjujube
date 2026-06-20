unsigned __int8 *__fastcall qmi_rmnet_watchdog_remove(unsigned __int8 *result)
{
  int v1; // w9
  unsigned __int8 *v2; // x19

  v1 = result[120];
  result[121] = 1;
  if ( v1 == 1 )
  {
    v2 = result;
    result = (unsigned __int8 *)timer_delete(result + 80);
    v2[120] = 0;
  }
  return result;
}
