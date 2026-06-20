__int64 __fastcall qdf_get_dump_inprogress(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 (*v8)(void); // x8

  v8 = (__int64 (*)(void))get_dump_inprogress_cb;
  if ( get_dump_inprogress_cb )
  {
    if ( *((_DWORD *)get_dump_inprogress_cb - 1) != -1984421533 )
      __break(0x8228u);
    return v8();
  }
  else
  {
    qdf_trace_msg(0x38u, 2u, "Error getting dump_inprogress", a1, a2, a3, a4, a5, a6, a7, a8);
    return 4;
  }
}
