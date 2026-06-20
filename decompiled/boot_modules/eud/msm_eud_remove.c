__int64 __fastcall msm_eud_remove(__int64 a1)
{
  __int64 *v1; // x20
  __int64 v2; // x19
  __int64 result; // x0
  __int64 v4; // x19

  v1 = *(__int64 **)(a1 + 168);
  if ( v1[77] )
    power_supply_put();
  uart_remove_one_port(&eud_uart_driver, v1 + 5);
  v2 = *v1;
  device_wakeup_disable(*v1);
  result = device_set_wakeup_capable(v2, 0);
  if ( *((_BYTE *)v1 + 625) == 1 )
  {
    v4 = v1[80];
    clk_disable(v4);
    return clk_unprepare(v4);
  }
  return result;
}
