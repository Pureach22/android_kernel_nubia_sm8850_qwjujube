__int64 __fastcall target_if_dfs_is_pdev_5ghz(
        __int64 a1,
        _BYTE *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x0
  unsigned int v12; // w20
  __int64 hal_reg_cap; // x0
  const char *v16; // x2

  v11 = *(_QWORD *)(a1 + 80);
  if ( v11 )
  {
    v12 = *(unsigned __int8 *)(a1 + 40);
    hal_reg_cap = ucfg_reg_get_hal_reg_cap(v11, a3, a4, a5, a6, a7, a8, a9, a10);
    if ( hal_reg_cap )
    {
      *a2 = *(_BYTE *)(hal_reg_cap + 48LL * v12 + 24) & 1;
      return 0;
    }
    v16 = "%s: dfs: reg cap null";
  }
  else
  {
    v16 = "%s: dfs: null psoc";
  }
  qdf_trace_msg(0x49u, 2u, v16, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_dfs_is_pdev_5ghz");
  return 16;
}
