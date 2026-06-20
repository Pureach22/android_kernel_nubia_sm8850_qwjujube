__int64 __fastcall msm_m31_eusb2_phy_remove(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 v3; // x20
  __int64 v4; // x20

  v1 = *(_QWORD *)(a1 + 168);
  flush_work(v1 + 496);
  if ( *(_QWORD *)(v1 + 480) )
    power_supply_put();
  debugfs_remove(*(_QWORD *)(v1 + 544));
  usb_remove_phy(v1);
  v2 = *(_QWORD *)(v1 + 416);
  if ( v2 )
  {
    clk_disable(*(_QWORD *)(v1 + 416));
    clk_unprepare(v2);
  }
  if ( *(_BYTE *)(v1 + 468) )
  {
    v3 = *(_QWORD *)(v1 + 416);
    if ( v3 )
    {
      clk_disable(*(_QWORD *)(v1 + 416));
      clk_unprepare(v3);
    }
    v4 = *(_QWORD *)(v1 + 408);
    clk_disable(v4);
    clk_unprepare(v4);
    *(_BYTE *)(v1 + 468) = 0;
  }
  return msm_m31_eusb2_phy_power(v1, 0);
}
