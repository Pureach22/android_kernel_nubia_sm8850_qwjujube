__int64 __fastcall dp_mon_filter_update(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 v11; // x8
  void (*v12)(void); // x8

  v9 = *(_QWORD *)(a1 + 8);
  if ( v9 && (v10 = *(_QWORD *)(v9 + 20112)) != 0 && (v11 = *(_QWORD *)(v10 + 416)) != 0 )
  {
    v12 = *(void (**)(void))(v11 + 648);
    if ( v12 )
    {
      if ( *((_DWORD *)v12 - 1) != -1116635294 )
        __break(0x8228u);
      v12();
    }
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x73u,
      2u,
      "%s: Rx mon filter update failed ops uninitialized",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "dp_mon_filter_update");
    return 16;
  }
}
