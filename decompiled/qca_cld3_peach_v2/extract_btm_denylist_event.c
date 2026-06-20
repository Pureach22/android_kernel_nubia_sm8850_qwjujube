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
  __int64 v12; // x22
  const char *v13; // x2
  __int64 v14; // x19
  __int64 v16; // x23
  _BYTE *v18; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  int v27; // w8
  __int64 v28; // x20
  _DWORD *v29; // x22
  __int64 v30; // x23
  int v31; // w25
  __int64 v32; // x26
  unsigned int v33; // w8
  int v34; // w8
  unsigned int v35; // w4
  int v36; // t1

  if ( !a10 )
  {
    v13 = "%s: Invalid event buffer";
    goto LABEL_13;
  }
  v12 = *a10;
  if ( !*a10 )
  {
    v13 = "%s: received null event data from target";
    goto LABEL_13;
  }
  if ( *(_DWORD *)(v12 + 4) >= 6u )
  {
    v13 = "%s: received invalid vdev_id %d";
LABEL_13:
    qdf_trace_msg(0x31u, 2u, v13, a1, a2, a3, a4, a5, a6, a7, a8, "extract_btm_denylist_event");
    return 4;
  }
  v14 = *((unsigned int *)a10 + 6);
  if ( !(_DWORD)v14 )
    return 0;
  if ( (unsigned int)v14 >= 0xB )
  {
    v13 = "%s: num blacklist entries:%d exceeds maximum value";
    goto LABEL_13;
  }
  if ( 92 * (unsigned __int64)(unsigned int)v14 + 8 > a11 )
  {
    v13 = "%s: Invalid length:%d";
    goto LABEL_13;
  }
  v16 = a10[2];
  v18 = (_BYTE *)_qdf_mem_malloc((96 * v14) | 8, "extract_btm_denylist_event", 2953);
  if ( v18 )
  {
    v27 = *(_DWORD *)(v12 + 4);
    v28 = (__int64)v18;
    v29 = (_DWORD *)(v16 + 44);
    v30 = 8;
    v31 = v14;
    *v18 = v27;
    while ( 1 )
    {
      v32 = v28 + v30;
      *(_WORD *)v32 = *(v29 - 10);
      *(_BYTE *)(v32 + 2) = *((_WORD *)v29 - 19);
      *(_BYTE *)(v32 + 3) = *((_BYTE *)v29 - 37);
      *(_WORD *)(v32 + 4) = *(v29 - 9);
      *(_DWORD *)(v32 + 8) = *(v29 - 8);
      *(_QWORD *)(v32 + 16) = (unsigned int)*(v29 - 4);
      *(_DWORD *)(v32 + 32) = *(v29 - 3);
      v33 = *(v29 - 6) - 1;
      v34 = v33 > 0x10 ? 0 : dword_B34280[v33];
      *(_DWORD *)(v32 + 28) = v34;
      *(_DWORD *)(v32 + 36) = *(v29 - 5);
      v35 = v29[11];
      if ( v35 >= 0xB )
        break;
      qdf_mem_copy((void *)(v32 + 48), v29 + 1, 4 * v35);
      --v31;
      v30 += 96;
      *(_BYTE *)(v32 + 88) = v29[11];
      *(_WORD *)(v32 + 40) = *(v29 - 1);
      *(_BYTE *)(v32 + 42) = *((_WORD *)v29 - 1);
      *(_BYTE *)(v32 + 43) = *((_BYTE *)v29 - 1);
      *(_BYTE *)(v32 + 44) = *v29;
      v36 = *v29;
      v29 += 23;
      *(_BYTE *)(v32 + 45) = BYTE1(v36);
      if ( !v31 )
      {
        *(_DWORD *)(v28 + 4) = v14;
        *a12 = v28;
        return 0;
      }
    }
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
    _qdf_mem_free(v28);
    return 4;
  }
  return 2;
}
