__int64 __fastcall cam_flash_pmic_query_current(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  int v4; // w6
  unsigned int v5; // w20
  int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = *(_QWORD *)(a1 + 6720);
  v6 = 0;
  if ( result )
  {
    result = qcom_flash_led_get_max_avail_current(result, &v6);
    v4 = v6;
  }
  else
  {
    v4 = 0;
  }
  if ( (debug_mdl & 0x1000) != 0 && !debug_priority )
  {
    v5 = result;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x1000,
      4,
      "cam_flash_pmic_query_current",
      1627,
      "query_curr_ma = %d",
      v4);
    v4 = v6;
    result = v5;
  }
  *(_DWORD *)(a2 + 4) = v4;
  _ReadStatusReg(SP_EL0);
  return result;
}
