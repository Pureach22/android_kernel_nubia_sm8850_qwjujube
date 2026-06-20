__int64 __fastcall hdd_vendor_attr_ldpc_get(__int64 *a1, __int64 a2)
{
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  const char *v12; // x2
  __int64 result; // x0
  unsigned int v14; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v15[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a1;
  v14 = 0;
  if ( (unsigned int)hdd_get_ldpc(v3, &v14) )
  {
    v12 = "%s: get ldpc failed";
LABEL_5:
    qdf_trace_msg(0x33u, 2u, v12, v4, v5, v6, v7, v8, v9, v10, v11, "hdd_vendor_attr_ldpc_get");
    result = 4294967274LL;
    goto LABEL_6;
  }
  qdf_trace_msg(0x33u, 8u, "%s: ldpc %u", v4, v5, v6, v7, v8, v9, v10, v11, "hdd_vendor_attr_ldpc_get", v14);
  v15[0] = v14;
  result = nla_put(a2, 67, 1, v15);
  if ( (_DWORD)result )
  {
    v12 = "%s: nla_put failure";
    goto LABEL_5;
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
