__int64 __fastcall dsi_display_change_te_irq_status(__int64 result, char a2)
{
  __int64 v2; // x19
  __int64 v3; // x0
  __int64 v4; // x0
  char v5; // w8
  __int64 v6; // x0
  __int64 v7; // x0

  v2 = result;
  if ( (a2 & 1) != 0 )
  {
    if ( (*(_BYTE *)(result + 124) & 1) != 0 )
      return result;
    v3 = gpio_to_desc(*(unsigned int *)(result + 120));
    v4 = gpiod_to_irq(v3);
    result = enable_irq(v4);
    v5 = 1;
  }
  else
  {
    if ( !*(_BYTE *)(result + 124) )
      return result;
    v6 = gpio_to_desc(*(unsigned int *)(result + 120));
    v7 = gpiod_to_irq(v6);
    result = disable_irq(v7);
    v5 = 0;
  }
  *(_BYTE *)(v2 + 124) = v5;
  return result;
}
