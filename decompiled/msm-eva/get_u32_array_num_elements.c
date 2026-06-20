unsigned __int64 __fastcall get_u32_array_num_elements(__int64 a1)
{
  unsigned __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x1
  __int64 v4; // x2
  void *v5; // x0
  unsigned __int64 v6; // x8
  unsigned int v7; // [xsp+4h] [xbp-Ch]
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = 0;
  result = of_get_property(a1);
  if ( result )
  {
    if ( v7 > 3 )
    {
      result = (unsigned __int64)(int)v7 >> 2;
      goto LABEL_11;
    }
    result = 0;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      v3 = *(unsigned int *)(StatusReg + 1800);
      v4 = *(unsigned int *)(StatusReg + 1804);
      v5 = &unk_91007;
LABEL_9:
      printk(v5, v3, v4, &unk_8E7CE);
      result = 0;
    }
  }
  else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v6 = _ReadStatusReg(SP_EL0);
    v3 = *(unsigned int *)(v6 + 1800);
    v4 = *(unsigned int *)(v6 + 1804);
    v5 = &unk_90FCB;
    goto LABEL_9;
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
