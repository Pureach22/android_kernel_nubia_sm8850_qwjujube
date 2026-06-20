__int64 ipa3_get_num_pipes()
{
  __int64 result; // x0
  int v1; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v2; // [xsp+8h] [xbp-8h]

  v2 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(ipa3_ctx + 32240) < 0x15u )
  {
    result = ipahal_read_reg_n(11, 0);
  }
  else
  {
    v1 = 0;
    ipahal_read_reg_n_fields(130, 0, &v1);
    result = (unsigned __int8)v1;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
