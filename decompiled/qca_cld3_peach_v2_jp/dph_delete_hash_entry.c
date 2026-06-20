__int64 __fastcall dph_delete_hash_entry(
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
  unsigned int v17; // w22
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  const char *v26; // x2
  __int16 *v28; // x12
  __int16 *v29; // x10
  __int16 *v30; // x8
  __int64 v31; // x4
  __int64 v32; // x5
  __int64 v33; // x6
  __int64 v34; // x7
  __int16 v35; // w11
  __int16 v36; // w12
  __int64 v37; // x11
  _QWORD *v38; // x9
  __int16 v39; // w9

  v13 = a10[2];
  v15 = a10[5];
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
    "dph_delete_hash_entry",
    a11,
    v17,
    v13,
    v15);
  if ( *(unsigned __int16 *)(a12 + 16) <= (unsigned int)a11 )
  {
    v26 = "%s: invalid STA id %d";
    goto LABEL_7;
  }
  if ( (*(_WORD *)(*(_QWORD *)(a12 + 8) + 952LL * a11) & 8) == 0 )
  {
    v26 = "%s: STA %d never added";
LABEL_7:
    qdf_trace_msg(0x35u, 2u, v26, v18, v19, v20, v21, v22, v23, v24, v25, "dph_delete_hash_entry", a11);
    return 16;
  }
  v28 = *(__int16 **)(*(_QWORD *)a12 + 8LL * (unsigned __int16)v17);
  if ( !v28 )
  {
LABEL_20:
    if ( a10 )
    {
      v31 = *a10;
      v32 = a10[1];
      v33 = a10[2];
      v34 = a10[5];
    }
    else
    {
      v33 = 0;
      v31 = 0;
      v32 = 0;
      v34 = 0;
    }
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Entry not present STA addr: %02x:%02x:%02x:**:**:%02x",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "dph_delete_hash_entry",
      v31,
      v32,
      v33,
      v34);
    return 16;
  }
  v29 = nullptr;
  while ( 1 )
  {
    v30 = v28;
    if ( *a10 == *((unsigned __int8 *)v28 + 338)
      && a10[1] == *((unsigned __int8 *)v28 + 339)
      && a10[2] == *((unsigned __int8 *)v28 + 340)
      && a10[3] == *((unsigned __int8 *)v28 + 341)
      && a10[4] == *((unsigned __int8 *)v28 + 342)
      && a10[5] == *((unsigned __int8 *)v28 + 343) )
    {
      break;
    }
    if ( v29 == v28 )
    {
      qdf_trace_msg(0x35u, 2u, "%s: Infinite Loop", v18, v19, v20, v21, v22, v23, v24, v25, "dph_delete_hash_entry");
      return 16;
    }
    v28 = *((__int16 **)v28 + 117);
    v29 = v30;
    if ( !v28 )
      goto LABEL_20;
  }
  v35 = *v28;
  v28[171] = 0;
  *(_DWORD *)(v28 + 169) = 0;
  v36 = v35 & 0xFFFE;
  v37 = *((_QWORD *)v30 + 117);
  *v30 = v36;
  if ( v29 )
    v38 = v29 + 468;
  else
    v38 = (_QWORD *)(*(_QWORD *)a12 + 8LL * (unsigned __int16)v17);
  *v38 = v37;
  v39 = *v30;
  *((_BYTE *)v30 + 642) = 0;
  *((_BYTE *)v30 + 645) = 0;
  *((_DWORD *)v30 + 208) = 0;
  *v30 = v39 & 0xF7F7;
  *((_QWORD *)v30 + 117) = 0;
  return 0;
}
