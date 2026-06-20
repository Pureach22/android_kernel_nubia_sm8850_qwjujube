__int64 ipahal_get_reg_base()
{
  __int64 result; // x0
  unsigned int v1; // w8

  result = 0x40000;
  if ( ipahal_ctx )
  {
    v1 = *(_DWORD *)(ipahal_ctx + 16);
    if ( v1 )
      return v1;
    else
      return 0x40000;
  }
  return result;
}
