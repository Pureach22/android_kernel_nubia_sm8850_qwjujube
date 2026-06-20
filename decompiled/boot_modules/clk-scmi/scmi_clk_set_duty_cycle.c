__int64 __fastcall scmi_clk_set_duty_cycle(__int64 a1, _DWORD *a2)
{
  int v2; // w8
  unsigned int v3; // w10
  __int64 v6; // x0
  __int64 v7; // x1
  __int64 v8; // x3
  _DWORD *v9; // x8
  __int64 result; // x0
  __int64 v11; // x8
  int v12; // w4
  unsigned int v13; // w19

  v2 = *a2;
  v3 = a2[1];
  v6 = *(_QWORD *)(a1 + 32);
  v7 = *(unsigned int *)(a1 - 16);
  v8 = 100 * v2 / v3;
  v9 = *(_DWORD **)(scmi_proto_clk_ops + 64);
  if ( *(v9 - 1) != 1096263296 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64, _QWORD))v9)(v6, v7, 1, v8, 0);
  if ( (_DWORD)result )
  {
    v11 = *(_QWORD *)(a1 - 8);
    v12 = *(_DWORD *)(a1 - 16);
    v13 = result;
    dev_warn(v11, "Failed to set duty cycle(%u/%u) for clock ID %d\n", *a2, a2[1], v12);
    return v13;
  }
  return result;
}
