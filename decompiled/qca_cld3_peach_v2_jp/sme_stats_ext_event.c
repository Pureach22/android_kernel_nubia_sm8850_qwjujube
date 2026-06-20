__int64 __fastcall sme_stats_ext_event(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  void (__fastcall *v10)(_QWORD); // x8
  __int64 v11; // x0

  if ( a2 )
  {
    v10 = *(void (__fastcall **)(_QWORD))(a1 + 13016);
    if ( v10 )
    {
      v11 = *(_QWORD *)(a1 + 12760);
      if ( *((_DWORD *)v10 - 1) != -1170810323 )
        __break(0x8228u);
      v10(v11);
    }
    return 0;
  }
  else
  {
    qdf_trace_msg(0x34u, 2u, "%s: Null msg", a3, a4, a5, a6, a7, a8, a9, a10, "sme_stats_ext_event");
    return 16;
  }
}
