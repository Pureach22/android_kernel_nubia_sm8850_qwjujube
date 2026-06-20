unsigned __int64 __fastcall qcom_icc_bcm_voter_probe(__int64 a1)
{
  __int64 v1; // x20
  __int64 v2; // x21
  __int64 v3; // x0
  __int64 v4; // x19
  _QWORD *v5; // x1
  unsigned __int64 result; // x0
  __int64 v7; // x0
  __int64 v8; // x22
  unsigned int variable_u32_array; // w0
  const char *v10; // x1
  unsigned int v11; // w19
  _QWORD v12[2]; // [xsp+0h] [xbp-10h] BYREF

  v1 = a1 + 16;
  v12[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 760);
  v12[0] = 0;
  v3 = devm_kmalloc(a1 + 16, 128, 3520);
  if ( !v3 )
    goto LABEL_14;
  v4 = v3;
  *(_QWORD *)v3 = v1;
  *(_QWORD *)(v3 + 8) = v2;
  *(_BYTE *)(v3 + 124) = of_find_property(v2, "qcom,no-amc", 0) == 0;
  if ( (of_property_read_variable_u32_array(v2, "qcom,tcs-wait", v4 + 120, 1, 0) & 0x80000000) != 0 )
    *(_DWORD *)(v4 + 120) = 3;
  _mutex_init(v4 + 24, "&voter->lock", &qcom_icc_bcm_voter_probe___key);
  *(_QWORD *)(v4 + 72) = v4 + 72;
  *(_QWORD *)(v4 + 80) = v4 + 72;
  *(_QWORD *)(v4 + 88) = v4 + 88;
  *(_QWORD *)(v4 + 96) = v4 + 88;
  if ( (unsigned int)of_property_read_string(v2, "qcom,crm-name", v12) )
    goto LABEL_5;
  v7 = devm_kmalloc(v1, 32, 3520);
  if ( !v7 )
  {
LABEL_14:
    result = 4294967284LL;
    goto LABEL_15;
  }
  v8 = v7;
  result = crm_get_device(v12[0]);
  *(_QWORD *)(v8 + 8) = result;
  if ( result >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( result == -19 )
      result = 4294966779LL;
    else
      result = (unsigned int)result;
    goto LABEL_15;
  }
  *(_DWORD *)(v8 + 16) = of_find_property(v2, "qcom,crm-sw-client", 0) != 0;
  variable_u32_array = of_property_read_variable_u32_array(v2, "qcom,crm-client-idx", v8 + 20, 1, 0);
  if ( (variable_u32_array & 0x80000000) != 0 )
  {
    v10 = "Error getting crm-client-idx, ret=%d\n";
LABEL_21:
    v11 = variable_u32_array;
    dev_err(v1, v10, variable_u32_array);
    result = v11;
    goto LABEL_15;
  }
  variable_u32_array = of_property_read_variable_u32_array(v2, "qcom,crm-pwr-states", v8 + 24, 1, 0);
  if ( (variable_u32_array & 0x80000000) != 0 )
  {
    v10 = "Error getting crm-pwr-states, ret=%d\n";
    goto LABEL_21;
  }
  *(_QWORD *)(v4 + 16) = v8;
LABEL_5:
  mutex_lock(&bcm_voter_lock);
  v5 = off_1B8;
  if ( off_1B8 == (_UNKNOWN *)(v4 + 104) || *(_UNKNOWN ***)off_1B8 != &bcm_voters )
  {
    _list_add_valid_or_report();
  }
  else
  {
    off_1B8 = (_UNKNOWN *)(v4 + 104);
    *(_QWORD *)(v4 + 104) = &bcm_voters;
    *(_QWORD *)(v4 + 112) = v5;
    *v5 = v4 + 104;
  }
  mutex_unlock(&bcm_voter_lock);
  result = 0;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
