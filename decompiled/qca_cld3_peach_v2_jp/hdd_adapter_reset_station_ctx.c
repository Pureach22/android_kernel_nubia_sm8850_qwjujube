char *__fastcall hdd_adapter_reset_station_ctx(char *result)
{
  char *v1; // x9
  char *v2; // x19

  if ( result )
    v1 = result + 52832;
  else
    v1 = nullptr;
  if ( v1 )
  {
    if ( v1 == result + 52832 )
    {
      v2 = result + 53132;
      result = (char *)qdf_mem_set(result + 53132, 6u, 0);
      v2[1357] = 8;
    }
  }
  return result;
}
