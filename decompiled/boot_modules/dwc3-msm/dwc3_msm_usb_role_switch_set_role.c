__int64 __fastcall dwc3_msm_usb_role_switch_set_role(__int64 a1, unsigned int a2)
{
  __int64 drvdata; // x0

  drvdata = usb_role_switch_get_drvdata();
  return dwc3_msm_set_role(drvdata, a2);
}
