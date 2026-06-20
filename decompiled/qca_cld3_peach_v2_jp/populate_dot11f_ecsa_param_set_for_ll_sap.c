void *__fastcall populate_dot11f_ecsa_param_set_for_ll_sap(void *result, __int64 a2)
{
  _QWORD v3[2]; // [xsp+0h] [xbp-10h] BYREF

  v3[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result )
  {
    *(_BYTE *)a2 = 1;
    *(_WORD *)(a2 + 32) = 1;
    v3[0] = wlan_ll_sap_get_target_tsf(result, 0);
    result = qdf_mem_copy((void *)(a2 + 36), v3, 8u);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
