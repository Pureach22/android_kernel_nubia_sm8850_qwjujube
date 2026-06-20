__int64 __fastcall scmi_clk_set_rate(__int64 a1, __int64 a2)
{
  __int64 v3; // x1
  __int64 (__fastcall *v4)(__int64, __int64, __int64); // x10
  __int64 v5; // x0

  v3 = *(unsigned int *)(a1 - 16);
  v4 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(scmi_proto_clk_ops + 24);
  v5 = *(_QWORD *)(a1 + 32);
  if ( *((_DWORD *)v4 - 1) != 1768298290 )
    __break(0x822Au);
  return v4(v5, v3, a2);
}
