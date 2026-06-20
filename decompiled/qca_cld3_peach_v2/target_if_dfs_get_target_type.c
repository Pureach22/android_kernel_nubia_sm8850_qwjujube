__int64 __fastcall target_if_dfs_get_target_type(
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
  __int64 v10; // x8
  __int64 v11; // x8
  const char *v13; // x2

  v10 = *(_QWORD *)(a1 + 80);
  if ( v10 )
  {
    v11 = *(_QWORD *)(v10 + 2800);
    if ( v11 )
    {
      *a2 = *(_DWORD *)(v11 + 496);
      return 0;
    }
    v13 = "%s: null tgt_psoc_info";
  }
  else
  {
    v13 = "%s: null psoc";
  }
  qdf_trace_msg(0x49u, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_dfs_get_target_type");
  return 16;
}
