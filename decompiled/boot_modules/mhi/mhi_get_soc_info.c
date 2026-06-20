__int64 __fastcall mhi_get_soc_info(_DWORD *a1)
{
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  result = mhi_read_reg((__int64)a1);
  if ( !(_DWORD)result )
  {
    a1[57] = 0;
    a1[58] = 0;
    a1[59] = 0;
    a1[60] = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
