__int64 __fastcall extract_btm_denylist_event(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 *a10,
        unsigned int a11,
        __int64 *a12)
{
  __int64 v12; // x21
  const char *v13; // x2
  unsigned int v15; // w19
  __int64 v16; // x20
  __int64 v18; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x8
  unsigned int v28; // w11
  __int64 v29; // x12
  unsigned int v30; // w13
  int v31; // w13
  __int64 v32; // x19

  if ( !a10 )
  {
    v13 = "%s: Invalid event buffer";
    goto LABEL_7;
  }
  v12 = *a10;
  if ( !*a10 )
  {
    v13 = "%s: received null event data from target";
    goto LABEL_7;
  }
  if ( *(_DWORD *)(v12 + 4) >= 6u )
  {
    v13 = "%s: received invalid vdev_id %d";
LABEL_7:
    qdf_trace_msg(0x31u, 2u, v13, a1, a2, a3, a4, a5, a6, a7, a8, "extract_btm_denylist_event");
    return 4;
  }
  v15 = *((_DWORD *)a10 + 6);
  if ( !v15 )
    return 0;
  if ( v15 >= 0xB )
  {
    v13 = "%s: num blacklist entries:%d exceeds maximum value";
    goto LABEL_7;
  }
  if ( 92 * (unsigned __int64)v15 + 8 > a11 )
  {
    v13 = "%s: Invalid length:%d";
    goto LABEL_7;
  }
  v16 = a10[2];
  v18 = _qdf_mem_malloc(40LL * v15 + 8, "extract_btm_denylist_event", 2953);
  if ( !v18 )
    return 2;
  v27 = 8;
  v28 = v15;
  *(_BYTE *)v18 = *(_DWORD *)(v12 + 4);
  while ( 1 )
  {
    v29 = v18 + v27;
    *(_WORD *)v29 = *(_DWORD *)(v16 + 4);
    *(_BYTE *)(v29 + 2) = *(_WORD *)(v16 + 6);
    *(_BYTE *)(v29 + 3) = *(_BYTE *)(v16 + 7);
    *(_WORD *)(v29 + 4) = *(_DWORD *)(v16 + 8);
    *(_DWORD *)(v29 + 8) = *(_DWORD *)(v16 + 12);
    *(_QWORD *)(v29 + 16) = *(unsigned int *)(v16 + 28);
    *(_DWORD *)(v29 + 32) = *(_DWORD *)(v16 + 32);
    v30 = *(_DWORD *)(v16 + 20) - 1;
    v31 = v30 > 0x10 ? 0 : dword_A2E998[v30];
    *(_DWORD *)(v29 + 28) = v31;
    *(_DWORD *)(v29 + 36) = *(_DWORD *)(v16 + 24);
    if ( *(_DWORD *)(v16 + 88) >= 0xBu )
      break;
    --v28;
    v16 += 92;
    v27 += 40;
    if ( !v28 )
    {
      *(_DWORD *)(v18 + 4) = v15;
      *a12 = v18;
      return 0;
    }
  }
  v32 = v18;
  qdf_trace_msg(
    0x31u,
    2u,
    "%s: link_count size %d exceeds max combo_count size %d",
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    "extract_btm_denylist_event");
  _qdf_mem_free(v32);
  return 4;
}
