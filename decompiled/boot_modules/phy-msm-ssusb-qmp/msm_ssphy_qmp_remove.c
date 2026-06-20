__int64 __fastcall msm_ssphy_qmp_remove(__int64 result)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(result + 168);
  if ( v1 )
  {
    usb_remove_phy(*(_QWORD *)(result + 168));
    msm_ssphy_qmp_enable_clks(v1, 0);
    return msm_ssusb_qmp_ldo_enable(v1, 0);
  }
  return result;
}
