__int64 __fastcall ce_get_direct_link_dest_srng_buffers(
        __int64 a1,
        __int64 *a2,
        _DWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned __int64 v11; // x8
  unsigned int *v12; // x9
  __int64 v13; // x4
  __int64 v14; // x20
  __int64 *v17; // x22
  __int64 v18; // x0
  __int64 v19; // x10
  __int64 v20; // x11

  v11 = *(unsigned int *)(a1 + 30712);
  if ( !(_DWORD)v11 )
  {
LABEL_14:
    v18 = 0;
    goto LABEL_15;
  }
  v12 = (unsigned int *)(*(_QWORD *)(a1 + 30704) + 8LL);
  while ( *(v12 - 2) != 1792 || *(v12 - 1) != 1 )
  {
    --v11;
    v12 += 3;
    if ( !v11 )
      goto LABEL_14;
  }
  v13 = *v12;
  if ( (unsigned int)v13 < 0xC )
  {
    v14 = *(_QWORD *)(a1 + 8 * v13 + 480);
    if ( !v14 || !*(_QWORD *)(v14 + 144) )
    {
      qdf_trace_msg(
        0x3Du,
        2u,
        "%s: Direct Link CE pipe %d not initialized",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "ce_get_direct_link_dest_srng_buffers");
      LODWORD(v11) = 16;
      return (unsigned int)v11;
    }
    v17 = a2;
    v18 = _qdf_mem_malloc(8LL * *(unsigned __int16 *)(a1 + 26394), "ce_get_direct_link_dest_srng_buffers", 1196);
    if ( !v18 )
    {
      LODWORD(v11) = 0;
      return (unsigned int)v11;
    }
    LODWORD(v11) = *(unsigned __int16 *)(a1 + 26394);
    if ( *(_WORD *)(a1 + 26394) )
    {
      v11 = 0;
      v19 = 16;
      a2 = v17;
      do
      {
        v20 = *(_QWORD *)(*(_QWORD *)(a1 + 26400) + v19);
        v19 += 24;
        *(_QWORD *)(v18 + 8 * v11++) = v20;
      }
      while ( v11 < *(unsigned __int16 *)(a1 + 26394) );
    }
    else
    {
      a2 = v17;
    }
    *a3 = *(_DWORD *)(v14 + 132);
LABEL_15:
    *a2 = v18;
    return (unsigned int)v11;
  }
  __break(0x5512u);
  return ce_get_direct_link_srng_info();
}
