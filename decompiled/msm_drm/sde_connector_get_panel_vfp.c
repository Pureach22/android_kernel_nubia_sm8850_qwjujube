__int64 __fastcall sde_connector_get_panel_vfp(__int64 a1, __int64 a2)
{
  __int64 (__fastcall *v2)(__int64, __int64, __int64); // x9
  __int64 v3; // x0
  __int64 v4; // x2
  __int64 v5; // x1
  __int64 result; // x0
  unsigned int v7; // w19

  if ( !a1 || !a2 )
  {
    printk(&unk_242658, "sde_connector_get_panel_vfp");
    return 4294967274LL;
  }
  v2 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 + 3136);
  if ( !v2 )
    return 4294967274LL;
  v3 = *(_QWORD *)(a1 + 2760);
  v4 = *(unsigned __int16 *)(a2 + 14);
  v5 = *(unsigned __int16 *)(a2 + 4);
  if ( *((_DWORD *)v2 - 1) != 731400050 )
    __break(0x8229u);
  result = v2(v3, v5, v4);
  if ( (int)result <= 0 )
  {
    v7 = result;
    printk(&unk_265ED9, "sde_connector_get_panel_vfp");
    return v7;
  }
  return result;
}
