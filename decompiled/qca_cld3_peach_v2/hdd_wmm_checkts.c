__int64 __fastcall hdd_wmm_checkts(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 *v20; // x21
  unsigned int v21; // w20

  qdf_trace_msg(0x33u, 8u, "%s: Entered with handle 0x%x", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_wmm_checkts", a2);
  mutex_lock(a1 + 1832);
  v20 = (__int64 *)(a1 + 1816);
  while ( 1 )
  {
    v20 = (__int64 *)*v20;
    if ( v20 == (__int64 *)(a1 + 1816) )
      break;
    if ( *((_DWORD *)v20 + 4) == a2 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: found handle 0x%x, context %pK",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "hdd_wmm_checkts",
        a2,
        v20);
      v21 = *((_DWORD *)v20 + 9);
      goto LABEL_6;
    }
  }
  v21 = 18;
LABEL_6:
  mutex_unlock(a1 + 1832);
  return v21;
}
