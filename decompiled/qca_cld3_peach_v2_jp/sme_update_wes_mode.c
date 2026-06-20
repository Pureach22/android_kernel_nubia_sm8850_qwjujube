__int64 __fastcall sme_update_wes_mode(
        __int64 a1,
        char a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  if ( a3 < 6u )
  {
    result = qdf_mutex_acquire(a1 + 12776);
    if ( !(_DWORD)result )
    {
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: LFR runtime successfully set WES Mode to %d - old value is %d",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "sme_update_wes_mode",
        a2 & 1,
        *(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 1566LL));
      *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1566LL) = a2 & 1;
      qdf_mutex_release(a1 + 12776);
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(0x34u, 2u, "%s: Invalid vdev %d", a4, a5, a6, a7, a8, a9, a10, a11, "sme_update_wes_mode");
    return 4;
  }
  return result;
}
