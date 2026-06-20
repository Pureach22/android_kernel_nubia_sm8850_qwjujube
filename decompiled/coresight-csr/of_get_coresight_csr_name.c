__int64 __fastcall of_get_coresight_csr_name(__int64 a1, __int64 a2)
{
  int v3; // w8
  __int64 result; // x0
  _QWORD v5[11]; // [xsp+8h] [xbp-58h] BYREF

  v5[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v5, 0, 80);
  v3 = _of_parse_phandle_with_args(a1, "coresight-csr", 0, 0, 0, v5);
  result = 4294967274LL;
  if ( !v3 && v5[0] )
    result = of_property_read_string(v5[0], "device-name", a2);
  _ReadStatusReg(SP_EL0);
  return result;
}
