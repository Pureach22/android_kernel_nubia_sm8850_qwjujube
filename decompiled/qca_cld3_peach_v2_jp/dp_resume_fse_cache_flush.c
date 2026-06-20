__int64 __fastcall dp_resume_fse_cache_flush(
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

  v9 = *(_QWORD *)(a1 + 1480);
  if ( v9 )
  {
    *(_DWORD *)(v9 + 88) = 0;
    *(_BYTE *)(v9 + 152) = 1;
  }
  return qdf_trace_msg(
           0x45u,
           5u,
           "%s: fse cache flush resumed",
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           "dp_resume_fse_cache_flush");
}
