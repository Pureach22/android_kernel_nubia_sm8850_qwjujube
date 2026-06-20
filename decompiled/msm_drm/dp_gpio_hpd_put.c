__int64 __fastcall dp_gpio_hpd_put(__int64 result)
{
  __int64 v1; // x19

  if ( result )
  {
    v1 = result;
    gpio_free(*(unsigned int *)(result + 72));
    return devm_kfree(*(_QWORD *)(v1 - 8));
  }
  return result;
}
