__int64 __fastcall qcom_glink_set_flow_control(__int64 a1, char a2)
{
  int v2; // w9
  __int64 v3; // x0
  int v4; // w8
  __int64 result; // x0
  _QWORD v6[2]; // [xsp+0h] [xbp-10h] BYREF

  v6[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a1 + 136);
  v3 = *(_QWORD *)(a1 + 112);
  v6[0] = 15;
  if ( (a2 & 1) != 0 )
    v4 = -1073741824;
  else
    v4 = 0;
  WORD1(v6[0]) = v2;
  HIDWORD(v6[0]) = v4;
  result = qcom_glink_tx(v3, (__int64)v6, 8, 0, 0, 1);
  _ReadStatusReg(SP_EL0);
  return result;
}
