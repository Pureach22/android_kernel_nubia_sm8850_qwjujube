__int64 __fastcall target_if_dbr_fill_ring(
        __int64 a1,
        _QWORD *a2,
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
  _DWORD *v20; // x24
  __int64 result; // x0
  __int64 v22; // x25
  unsigned __int64 v23; // x21
  _BYTE *v24; // x26
  unsigned int v25; // w4
  __int64 v26; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x23
  char v36; // w8
  __int64 v37; // x2
  unsigned int v38; // w0
  __int64 v39; // [xsp+0h] [xbp-20h] BYREF
  __int64 v40; // [xsp+8h] [xbp-18h] BYREF
  __int64 v41[2]; // [xsp+10h] [xbp-10h] BYREF

  v41[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(0x5Bu, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "target_if_dbr_fill_ring");
  v20 = (_DWORD *)a2[3];
  if ( *v20 == 1 )
  {
LABEL_2:
    qdf_trace_msg(0x5Bu, 8u, "%s: exit", v12, v13, v14, v15, v16, v17, v18, v19, "target_if_dbr_fill_ring");
    result = 0;
  }
  else
  {
    v22 = a2[2];
    v23 = 0;
    v24 = (_BYTE *)(a2[4] + 24LL);
    while ( 1 )
    {
      v25 = *(_DWORD *)(v22 + 8);
      v40 = 0;
      v41[0] = 0;
      v39 = 0;
      v26 = qdf_aligned_malloc_fl((unsigned int *)(v22 + 4), v41, &v39, &v40, v25, "target_if_dbr_mem_get", 0x31Du);
      if ( !v26 || (v35 = v41[0]) == 0 )
      {
        qdf_trace_msg(
          0x5Bu,
          2u,
          "%s: dir buf rx ring alloc failed",
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          "target_if_dbr_fill_ring");
        result = 2;
        goto LABEL_11;
      }
      v36 = v26 - LOBYTE(v41[0]);
      v37 = v41[0] + (unsigned __int8)(v26 - LOBYTE(v41[0]));
      *((_QWORD *)v24 - 1) = v41[0];
      *v24 = v36;
      *((_DWORD *)v24 - 6) = v23;
      v38 = target_if_dbr_replenish_ring(a1, a2, v37, v23, v27, v28, v29, v30, v31, v32, v33, v34);
      if ( v38 )
        break;
      ++v23;
      v24 += 32;
      if ( v23 >= (unsigned int)(*v20 - 1) )
        goto LABEL_2;
    }
    qdf_trace_msg(
      0x5Bu,
      2u,
      "%s: replenish failed with status : %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "target_if_dbr_fill_ring",
      v38);
    _qdf_mem_free(v35);
    result = 16;
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
