__int64 __fastcall dsi_panel_gpio_release(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0

  v2 = *(unsigned int *)(a1 + 1596);
  if ( (v2 & 0x80000000) == 0 )
    gpio_free(v2);
  v3 = *(unsigned int *)(a1 + 1600);
  if ( (v3 & 0x80000000) == 0 )
    gpio_free(v3);
  if ( *(_BYTE *)(a1 + 2232) == 1 )
  {
    v4 = *(unsigned int *)(a1 + 1604);
    if ( (v4 & 0x80000000) == 0 )
      gpio_free(v4);
  }
  v5 = *(unsigned int *)(a1 + 1540);
  if ( (v5 & 0x80000000) == 0 )
    gpio_free(v5);
  v6 = *(unsigned int *)(a1 + 1608);
  if ( (v6 & 0x80000000) == 0 )
    gpio_free(v6);
  v7 = *(unsigned int *)(a1 + 2216);
  if ( (v7 & 0x80000000) == 0 )
    gpio_free(v7);
  return 0;
}
