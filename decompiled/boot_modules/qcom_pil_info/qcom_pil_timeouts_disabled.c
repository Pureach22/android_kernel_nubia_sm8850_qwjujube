__int64 qcom_pil_timeouts_disabled()
{
  _DWORD *v0; // x0
  __int64 result; // x0
  _QWORD v2[13]; // [xsp+8h] [xbp-68h] BYREF

  v2[12] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v0 = (_DWORD *)pil_timeout_base;
  memset(v2, 0, 96);
  if ( !pil_timeout_base )
  {
    v0 = (_DWORD *)qcom_map_pil_imem_resource("qcom,msm-imem-pil-disable-timeout", v2);
    if ( (unsigned __int64)v0 > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_5;
    pil_timeout_base = (__int64)v0;
  }
  if ( *v0 == 1396982343 )
  {
    printk(&unk_6538);
    result = 1;
    goto LABEL_6;
  }
LABEL_5:
  result = 0;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
