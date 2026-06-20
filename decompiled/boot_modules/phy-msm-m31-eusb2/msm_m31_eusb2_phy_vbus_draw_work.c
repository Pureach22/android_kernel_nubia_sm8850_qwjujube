__int64 __fastcall msm_m31_eusb2_phy_vbus_draw_work(__int64 a1)
{
  _QWORD *v2; // x20
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 result; // x0
  __int64 v6; // x0
  _QWORD v7[2]; // [xsp+0h] [xbp-10h] BYREF

  v2 = (_QWORD *)(a1 - 496);
  v7[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 - 16);
  v7[0] = 0;
  if ( v3 || (v4 = power_supply_get_by_name("usb"), (*(_QWORD *)(a1 - 16) = v4) != 0) )
  {
    dev_info(*v2, "Avail curr from USB = %u\n", *(_DWORD *)(a1 - 8));
    v6 = *(_QWORD *)(a1 - 16);
    LODWORD(v7[0]) = 1000 * *(_DWORD *)(a1 - 8);
    result = power_supply_set_property(v6, 38, v7);
  }
  else
  {
    result = dev_err(*v2, "Could not get usb psy\n");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
