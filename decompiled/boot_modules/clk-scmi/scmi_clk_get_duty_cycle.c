__int64 __fastcall scmi_clk_get_duty_cycle(__int64 a1, _DWORD *a2)
{
  __int64 v4; // x0
  __int64 v5; // x1
  _DWORD *v6; // x8
  __int64 result; // x0
  unsigned int v8; // w19
  int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 32);
  v5 = *(unsigned int *)(a1 - 16);
  v9 = 0;
  v6 = *(_DWORD **)(scmi_proto_clk_ops + 56);
  if ( *(v6 - 1) != -1658842783 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, __int64, __int64, int *, _QWORD, _QWORD))v6)(v4, v5, 1, &v9, 0, 0);
  if ( (_DWORD)result )
  {
    v8 = result;
    dev_warn(*(_QWORD *)(a1 - 8), "Failed to get duty cycle for clock ID %d\n", *(_DWORD *)(a1 - 16));
    result = v8;
  }
  else
  {
    *a2 = v9;
    a2[1] = 100;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
