__int64 __fastcall lim_admit_control_delete_sta(
        __int64 a1,
        unsigned __int16 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w19
  unsigned int v11; // w20
  __int64 v12; // x24

  v10 = 0;
  v11 = a2;
  v12 = a1 + 8920;
  do
  {
    if ( *(unsigned __int16 *)(v12 + 8) == v11 )
    {
      if ( v12 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: tspec entry: %d delete tspec: %pK",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "lim_tspec_delete",
          *(unsigned __int8 *)(v12 + 1),
          v12);
        *(_BYTE *)v12 = 0;
      }
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Deleting TSPEC: %d for assocId: %d",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "lim_admit_control_delete_sta",
        v10,
        v11);
    }
    ++v10;
    v12 += 163;
  }
  while ( v10 != 15 );
  qdf_trace_msg(0x35u, 8u, "%s: assocId: %d done", a3, a4, a5, a6, a7, a8, a9, a10, "lim_admit_control_delete_sta", v11);
  return 0;
}
