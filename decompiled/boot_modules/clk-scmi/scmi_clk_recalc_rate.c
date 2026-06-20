__int64 __fastcall scmi_clk_recalc_rate(__int64 a1)
{
  __int64 v1; // x1
  _DWORD *v2; // x9
  __int64 v3; // x0
  int v4; // w0
  _QWORD v6[2]; // [xsp+0h] [xbp-10h] BYREF

  v6[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(unsigned int *)(a1 - 16);
  v6[0] = 0;
  v2 = *(_DWORD **)(scmi_proto_clk_ops + 16);
  v3 = *(_QWORD *)(a1 + 32);
  if ( *(v2 - 1) != -1838978014 )
    __break(0x8229u);
  v4 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *))v2)(v3, v1, v6);
  _ReadStatusReg(SP_EL0);
  if ( v4 )
    return 0;
  else
    return v6[0];
}
