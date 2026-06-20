__int64 __fastcall dp_runtime_suspend(
        __int64 a1,
        char a2,
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
  __int64 v11; // x20
  __int64 v12; // x22
  __int64 v13; // x19
  __int64 v14; // x19
  void (__fastcall *v15)(__int64, __int64); // x8

  if ( a2 || (v10 = *(_QWORD *)(a1 + 72)) == 0 )
  {
    qdf_trace_msg(0x45u, 2u, "%s: pdev is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "dp_runtime_suspend");
    return 4;
  }
  else
  {
    v11 = a1 + 0x4000;
    if ( *(_DWORD *)(v10 + 94396) )
    {
      v12 = jiffies;
      if ( dp_runtime_suspend___last_ticks - jiffies + 125 < 0 )
      {
        v13 = a1;
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: %pK: Abort suspend due to pending TX packets %d",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "dp_runtime_suspend",
          a1);
        a1 = v13;
        dp_runtime_suspend___last_ticks = v12;
      }
      v14 = a1;
      dp_find_missing_tx_comp(a1, a3, a4, a5, a6, a7, a8, a9, a10);
      v15 = *(void (__fastcall **)(__int64, __int64))(v14 + 1816);
      if ( *((_DWORD *)v15 - 1) != 357773931 )
        __break(0x8228u);
      v15(v14, 1);
      *(_DWORD *)(v11 + 3604) = 0;
      return 3;
    }
    else if ( *(_DWORD *)(a1 + 19984) )
    {
      qdf_trace_msg(
        0x7Cu,
        5u,
        "%s: refcount: %d",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "dp_runtime_suspend",
        *(unsigned int *)(a1 + 19984));
      return 3;
    }
    else
    {
      if ( *(_BYTE *)(a1 + 17840) == 2 )
        timer_delete((timer_t)(a1 + 17784));
      return 0;
    }
  }
}
