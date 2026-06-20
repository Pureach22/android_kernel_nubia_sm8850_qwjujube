__int64 __fastcall scmi_clk_enable(__int64 a1)
{
  __int64 v1; // x1
  _DWORD *v2; // x9
  __int64 v3; // x0

  v1 = *(unsigned int *)(a1 - 16);
  v2 = *(_DWORD **)(scmi_proto_clk_ops + 32);
  v3 = *(_QWORD *)(a1 + 32);
  if ( *(v2 - 1) != -608895375 )
    __break(0x8229u);
  return ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v2)(v3, v1, 0);
}
