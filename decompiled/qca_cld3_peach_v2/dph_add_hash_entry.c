__int64 __fastcall dph_add_hash_entry(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned __int8 *a10,
        unsigned __int16 a11,
        __int64 a12)
{
  int v13; // w8
  int v15; // w9
  unsigned int v16; // w19
  unsigned int v17; // w22
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x8
  __int64 v27; // x23
  __int64 v28; // x9
  bool v29; // zf
  const char *v30; // x2
  _WORD *v32; // x22
  __int64 v33; // x24
  __int16 v34; // w8

  v13 = a10[2];
  v15 = a10[5];
  v16 = a11;
  v17 = (a10[1] + *a10 + v13 + a10[3] + (unsigned int)a10[4] + v15) % *(unsigned __int16 *)(a12 + 16);
  if ( !a10 )
  {
    v13 = 0;
    v15 = 0;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: assocId: %d index: %d STA addr: %02x:%02x:%02x:**:**:%02x",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "dph_add_hash_entry",
    a11,
    v17,
    v13,
    v15);
  if ( *(unsigned __int16 *)(a12 + 16) <= v16 )
  {
    v30 = "%s: invalid STA id %d";
  }
  else
  {
    v26 = *(_QWORD *)(a12 + 8);
    if ( (*(_WORD *)(v26 + 1272LL * v16) & 8) != 0 )
    {
      v30 = "%s: already added STA %d";
    }
    else
    {
      v27 = (unsigned __int16)v17;
      v28 = *(_QWORD *)(*(_QWORD *)a12 + 8LL * (unsigned __int16)v17);
      while ( v28 )
      {
        if ( v28 == *(_QWORD *)(v28 + 1072) )
        {
          qdf_trace_msg(0x35u, 2u, "%s: Infinite Loop", v18, v19, v20, v21, v22, v23, v24, v25, "dph_add_hash_entry");
          return 0;
        }
        if ( *a10 != *(unsigned __int8 *)(v28 + 350)
          || a10[1] != *(unsigned __int8 *)(v28 + 351)
          || a10[2] != *(unsigned __int8 *)(v28 + 352)
          || a10[3] != *(unsigned __int8 *)(v28 + 353)
          || a10[4] != *(unsigned __int8 *)(v28 + 354)
          || a10[5] != *(unsigned __int8 *)(v28 + 355) )
        {
          v29 = *(unsigned __int16 *)(v28 + 348) == v16;
          v28 = *(_QWORD *)(v28 + 1072);
          if ( !v29 )
            continue;
        }
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: assocId %d hashIndex %d entry exists",
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          "dph_add_hash_entry",
          v16,
          v17);
        return 0;
      }
      v32 = (_WORD *)(v26 + 1272LL * (unsigned __int8)v16);
      v33 = *((_QWORD *)v32 + 134);
      qdf_mem_set(v32, 0x4F8u, 0);
      *((_QWORD *)v32 + 134) = v33;
      v32[174] = v16;
      qdf_mem_copy(v32 + 175, a10, 6u);
      v34 = *v32;
      *((_BYTE *)v32 + 661) = 0;
      *v32 = v34 | 9;
      *(_WORD *)((char *)v32 + 657) = 0;
      if ( v32 )
      {
        *(_QWORD *)(*(_QWORD *)(a12 + 8) + 1272LL * v16 + 1072) = *(_QWORD *)(*(_QWORD *)a12 + 8 * v27);
        *(_QWORD *)(*(_QWORD *)a12 + 8 * v27) = *(_QWORD *)(a12 + 8) + 1272LL * v16;
        return *(_QWORD *)(*(_QWORD *)a12 + 8 * v27);
      }
      v30 = "%s: could not Init STA id: %d";
    }
  }
  qdf_trace_msg(0x35u, 2u, v30, v18, v19, v20, v21, v22, v23, v24, v25, "dph_add_hash_entry", v16);
  return 0;
}
