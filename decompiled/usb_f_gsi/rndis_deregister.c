unsigned int *__fastcall rndis_deregister(unsigned int *result)
{
  unsigned int v1; // w19

  if ( result )
  {
    v1 = *result;
    kfree(result);
    return (unsigned int *)ida_free(&rndis_ida, v1);
  }
  return result;
}
