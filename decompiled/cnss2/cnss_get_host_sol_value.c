__int64 __fastcall cnss_get_host_sol_value(__int64 a1)
{
  __int64 v1; // x0

  if ( (*(_DWORD *)(a1 + 148) & 0x80000000) != 0 )
    return 4294967274LL;
  v1 = gpio_to_desc();
  return gpiod_get_raw_value(v1);
}
