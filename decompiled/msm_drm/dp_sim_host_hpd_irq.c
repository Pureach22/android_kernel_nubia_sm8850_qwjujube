__int64 __fastcall dp_sim_host_hpd_irq(__int64 result)
{
  __int64 (__fastcall *v1)(__int64, __int64, __int64); // x8
  __int64 v2; // x0

  v1 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(result + 80);
  if ( v1 )
  {
    v2 = *(_QWORD *)(result + 72);
    if ( *((_DWORD *)v1 - 1) != -121262737 )
      __break(0x8228u);
    return v1(v2, 1, 1);
  }
  return result;
}
