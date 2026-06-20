__int64 __fastcall reg_get_current_dfs_region(
        __int64 a1,
        _DWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  result = reg_get_pdev_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !result )
    return qdf_trace_msg(
             0x51u,
             2u,
             "%s: reg component pdev priv is NULL",
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             "reg_get_current_dfs_region");
  *a2 = *(_DWORD *)(result + 56716);
  return result;
}
