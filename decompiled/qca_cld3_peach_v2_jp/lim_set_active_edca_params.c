__int64 __fastcall lim_set_active_edca_params(_BYTE *a1, int *a2, __int64 a3)
{
  int v3; // w9
  __int64 v4; // x23
  char v7; // w10
  _BYTE *v8; // x24
  char v9; // w10
  _BYTE *v10; // x25
  _BYTE *v11; // x26
  __int64 result; // x0
  __int64 v13; // x21
  int v14; // w28
  unsigned int v15; // w0
  unsigned int v16; // w22
  char v17; // w10
  int v18; // w0
  int v19; // w28
  int v20; // w0
  unsigned int v21; // w27
  __int64 v22; // x22
  int v23; // w0
  int *v24; // x8
  int v25; // w10
  int v26; // w22
  int v27; // w0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int v36; // w22
  int *v37; // x8
  int v38; // w10
  __int64 v39; // x20

  v3 = *a2;
  v4 = a3 + 4096;
  *(_BYTE *)(a3 + 7140) = *((_BYTE *)a2 + 4);
  *(_DWORD *)(a3 + 7136) = v3;
  v7 = *((_BYTE *)a2 + 9);
  v8 = (char *)a2 + 5;
  *(_DWORD *)(a3 + 7141) = *(int *)((char *)a2 + 5);
  *(_BYTE *)(a3 + 7145) = v7;
  v9 = *((_BYTE *)a2 + 14);
  v10 = (char *)a2 + 10;
  *(_DWORD *)(a3 + 7146) = *(int *)((char *)a2 + 10);
  *(_BYTE *)(a3 + 7150) = v9;
  v11 = (char *)a2 + 15;
  LOBYTE(v3) = *((_BYTE *)a2 + 19);
  *(_DWORD *)(a3 + 7151) = *(int *)((char *)a2 + 15);
  *(_BYTE *)(a3 + 7155) = v3;
  *(_BYTE *)(a3 + 7140) = a1[21625];
  *(_BYTE *)(a3 + 7145) = a1[21626];
  *(_BYTE *)(a3 + 7150) = a1[21627];
  *(_BYTE *)(a3 + 7155) = a1[21628];
  result = _qdf_mem_malloc(0x200u, "lim_set_active_edca_params", 229);
  if ( result )
  {
    v13 = result;
    v14 = *(unsigned __int8 *)(v4 + 3181) >> 1;
    scnprintf(
      result,
      512,
      "AC[%d]:acm=%d ac_admitted=%d,",
      1,
      ((unsigned __int8)*v8 >> 4) & 1,
      (*(_BYTE *)(v4 + 3181) & 2) != 0);
    v16 = v15;
    if ( (v14 & 1) == 0 && (*v8 & 0x10) != 0 )
    {
      scnprintf(v13 + v15, 512 - v15, "AC %d ---> AC %d, ", 1, 0);
      v17 = *((_BYTE *)a2 + 4);
      v16 += v18;
      *(_DWORD *)(a3 + 7141) = *a2;
      *(_BYTE *)(a3 + 7145) = v17;
    }
    v19 = *(unsigned __int8 *)(v4 + 3181) >> 2;
    scnprintf(
      v13 + v16,
      512 - v16,
      "AC[%d]:acm=%d ac_admitted=%d,",
      2,
      ((unsigned __int8)*v10 >> 4) & 1,
      (*(_BYTE *)(v4 + 3181) & 4) != 0);
    v21 = v20 + v16;
    if ( (v19 & 1) == 0 && (*v10 & 0x10) != 0 )
    {
      v22 = ~(*((unsigned __int8 *)a2 + 5) >> 4) & 1LL;
      scnprintf(v13 + v21, 512 - v21, "AC %d ---> AC %d, ", 2, ((*((unsigned __int8 *)a2 + 5) >> 4) & 1) == 0);
      v21 += v23;
      v24 = (int *)((char *)a2 + (v22 | (4 * v22)));
      v25 = *v24;
      LOBYTE(v24) = *((_BYTE *)v24 + 4);
      *(_DWORD *)(a3 + 7146) = v25;
      *(_BYTE *)(a3 + 7150) = (_BYTE)v24;
    }
    v26 = *(unsigned __int8 *)(v4 + 3181) >> 3;
    v28 = scnprintf(
            v13 + v21,
            512 - v21,
            "AC[%d]:acm=%d ac_admitted=%d,",
            3,
            ((unsigned __int8)*v11 >> 4) & 1,
            (*(_BYTE *)(v4 + 3181) & 8) != 0);
    if ( (v26 & 1) == 0 && (*v11 & 0x10) != 0 )
    {
      if ( (*v10 & 0x10) != 0 )
        v36 = (((unsigned __int8)*v8 >> 4) & 1) == 0;
      else
        v36 = 2;
      v28 = scnprintf(v13 + v27 + v21, 512 - (v27 + v21), "AC %d ---> AC %d, ", 3, v36);
      v37 = (int *)((char *)a2 + (v36 | (4LL * v36)));
      v38 = *v37;
      LOBYTE(v37) = *((_BYTE *)v37 + 4);
      *(_DWORD *)(a3 + 7151) = v38;
      *(_BYTE *)(a3 + 7155) = (_BYTE)v37;
    }
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Vdev_id: %d adAdmitMask: uplink 0x%x downlink 0x%x,  %s",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "lim_set_active_edca_params",
      *(unsigned __int8 *)(a3 + 10),
      *(unsigned __int8 *)(v4 + 3181),
      *(unsigned __int8 *)(v4 + 3182),
      v13);
    _qdf_mem_free(v13);
    result = _qdf_mem_malloc(0x1Cu, "lim_set_active_edca_params", 269);
    if ( result )
    {
      v39 = result;
      host_diag_log_set_code(result, 5274);
      host_diag_log_set_length(v39, 28);
      *(_BYTE *)(v39 + 12) = (*(_BYTE *)(v4 + 3040) >> 5) & 3;
      *(_BYTE *)(v39 + 13) = *(_BYTE *)(v4 + 3041);
      *(_WORD *)(v39 + 14) = *(_WORD *)(a3 + 7138);
      *(_BYTE *)(v39 + 16) = (*(_BYTE *)(v4 + 3045) >> 5) & 3;
      *(_BYTE *)(v39 + 17) = *(_BYTE *)(v4 + 3046);
      *(_WORD *)(v39 + 18) = *(_WORD *)(v4 + 3047);
      *(_BYTE *)(v39 + 20) = (*(_BYTE *)(v4 + 3050) >> 5) & 3;
      *(_BYTE *)(v39 + 21) = *(_BYTE *)(v4 + 3051);
      *(_WORD *)(v39 + 22) = *(_WORD *)(a3 + 7148);
      *(_BYTE *)(v39 + 24) = (*(_BYTE *)(v4 + 3055) >> 5) & 3;
      *(_BYTE *)(v39 + 25) = *(_BYTE *)(v4 + 3056);
      *(_WORD *)(v39 + 26) = *(_WORD *)(v4 + 3057);
      host_diag_log_submit(v39);
      return _qdf_mem_free(v39);
    }
  }
  return result;
}
