__int64 __fastcall dwc3_msm_config_gdsc(__int64 result, int a2)
{
  unsigned __int64 v2; // x8
  _QWORD *v3; // x19
  _QWORD *v4; // x19

  if ( (*(_BYTE *)(result + 2804) & 1) == 0 )
  {
    v2 = *(_QWORD *)(result + 440);
    if ( v2 )
    {
      if ( v2 <= 0xFFFFFFFFFFFFF000LL )
      {
        if ( a2 )
        {
          v3 = (_QWORD *)result;
          if ( (unsigned int)regulator_enable(v2) )
            return dev_err(*v3, "unable to enable usb3 gdsc\n");
          else
            return qcom_clk_set_flags(v3[42], 2);
        }
        else
        {
          v4 = (_QWORD *)result;
          qcom_clk_set_flags(*(_QWORD *)(result + 336), 3);
          result = regulator_disable(v4[55]);
          if ( (_DWORD)result )
            return dev_err(*v4, "unable to disable usb3 gdsc\n");
        }
      }
    }
  }
  return result;
}
