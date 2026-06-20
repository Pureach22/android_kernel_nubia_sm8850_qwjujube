__int64 __fastcall lpi_gpio_set_mux(__int64 a1, int a2, unsigned int a3)
{
  __int64 v3; // x19
  int v4; // w0

  v3 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 8LL) + 24LL * a3 + 16);
  if ( v3 )
  {
    *(_DWORD *)(v3 + 56) = a2;
    v4 = lpi_gpio_read(v3, 0);
    lpi_gpio_write(v3, 0, v4 & 0xFFFFFFC3 | (4 * *(_DWORD *)(v3 + 56)));
  }
  return 0;
}
