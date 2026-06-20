__int64 __fastcall wma_set_tsf_gpio_pin(__int64 *a1, unsigned int a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 result; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7

  _ReadStatusReg(SP_EL0);
  if ( (unsigned int)_wma_validate_handle(a1, "wma_set_tsf_gpio_pin")
    || (v12 = *a1,
        (unsigned int)_wmi_validate_handle(v12, (__int64)"wma_set_tsf_gpio_pin", v4, v5, v6, v7, v8, v9, v10, v11)) )
  {
    result = 4;
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: set tsf gpio pin: %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wma_set_tsf_gpio_pin",
      a2);
    result = wmi_unified_pdev_param_send(v12);
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Failed to set tsf gpio pin (status=%d)",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "wma_set_tsf_gpio_pin",
        (unsigned int)result);
      result = 16;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
