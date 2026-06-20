__int64 __fastcall wlan_cfg_set_max_ast_idx(
        __int64 result,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30
  int v12; // w4
  __int64 v13; // x19

  v12 = *(_DWORD *)(result + 640);
  *(_DWORD *)(result + 636) = a2;
  if ( v12 > a2 )
  {
    v13 = result;
    result = qdf_trace_msg(
               0x38u,
               2u,
               "%s: resv_ast_idx %u is greater than max_ast_idx %u",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "wlan_cfg_set_max_ast_idx",
               v10,
               v11);
    *(_DWORD *)(v13 + 640) = *(_DWORD *)(v13 + 636);
  }
  return result;
}
