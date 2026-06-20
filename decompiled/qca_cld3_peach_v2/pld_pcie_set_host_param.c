__int64 __fastcall pld_pcie_set_host_param(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  _QWORD v3[2]; // [xsp+0h] [xbp-10h] BYREF

  v3[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3[0] = a2;
  result = cnss_set_host_param(a1, v3);
  _ReadStatusReg(SP_EL0);
  return result;
}
