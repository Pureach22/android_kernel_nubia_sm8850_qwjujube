__int64 __fastcall qcom_pdm_pfr(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = 0;
  if ( (unsigned int)__ratelimit(&qcom_pdm_pfr__rs, "qcom_pdm_pfr") )
    printk(&unk_8316);
  result = qmi_send_response(a1, a2, a3, 36, 10, &servreg_loc_pfr_resp_ei, &v7);
  if ( (_DWORD)result )
    result = printk(&unk_82B8);
  _ReadStatusReg(SP_EL0);
  return result;
}
