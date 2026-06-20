__int64 __fastcall validate_write_multi_lut_reg(unsigned int *a1)
{
  __int64 result; // x0
  unsigned int v3; // w1

  result = validate_write_reg(a1);
  if ( !(_DWORD)result )
  {
    v3 = a1[3];
    if ( v3 - 16 > 0xFFFFFFF1 )
    {
      return 0;
    }
    else
    {
      _drm_err("invalid wrap sz %d min %d max %zd\n", v3, 2, 0xFu);
      return 4294967274LL;
    }
  }
  return result;
}
