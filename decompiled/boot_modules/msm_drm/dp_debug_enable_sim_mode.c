__int64 __fastcall dp_debug_enable_sim_mode(__int64 result, int a2)
{
  __int64 v2; // x19
  __int64 v3; // x0
  int v5; // w8
  __int64 v6; // x0
  __int64 v7; // x1
  void (__fastcall *v8)(__int64, __int64); // x8
  __int64 v9; // x0
  void (__fastcall *v10)(__int64, __int64 (__fastcall *)()); // x8

  if ( (a2 & ~*(_DWORD *)(result + 28)) != 0 )
  {
    v2 = result;
    v3 = *(_QWORD *)(result + 424);
    if ( !v3 )
    {
      result = dp_sim_create_bridge(*(_QWORD *)(v2 + 152), v2 + 424);
      if ( (_DWORD)result )
        return result;
      v3 = *(_QWORD *)(v2 + 424);
      v10 = *(void (__fastcall **)(__int64, __int64 (__fastcall *)()))(v3 + 48);
      if ( v10 )
      {
        if ( *((_DWORD *)v10 - 1) != 461496586 )
          __break(0x8228u);
        v10(v3, dp_debug_sim_hpd_cb);
        v3 = *(_QWORD *)(v2 + 424);
      }
    }
    dp_sim_update_port_num(v3, 1);
    v5 = *(_DWORD *)(v2 + 28);
    if ( !v5 )
    {
      v6 = *(_QWORD *)(v2 + 128);
      v7 = *(_QWORD *)(v2 + 424);
      v8 = *(void (__fastcall **)(__int64, __int64))(v6 + 88);
      if ( *((_DWORD *)v8 - 1) != -1759750187 )
        __break(0x8228u);
      v8(v6, v7);
      v5 = *(_DWORD *)(v2 + 28);
    }
    v9 = *(_QWORD *)(v2 + 424);
    *(_DWORD *)(v2 + 28) = v5 | a2;
    return dp_sim_set_sim_mode(v9);
  }
  return result;
}
