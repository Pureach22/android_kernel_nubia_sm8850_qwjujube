__int64 __fastcall ml_nlink_convert_linkid_bitmap_to_vdev_bitmap(
        int a1,
        __int64 a2,
        unsigned int a3,
        int *a4,
        unsigned int *a5,
        unsigned int *a6,
        _BYTE *a7,
        _BYTE *a8)
{
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  _QWORD *v23; // x26
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x8
  __int64 v33; // x11
  unsigned __int64 v34; // x4
  const char *v35; // x2
  unsigned int v36; // w1
  unsigned int v38; // w8
  __int64 v39; // x19
  unsigned int v40; // w19
  unsigned int v41; // w28
  int v42; // w27
  __int64 v43; // x8
  unsigned __int64 v44; // x4
  const char *v45; // x2
  unsigned int v46; // w1
  unsigned int v47; // w8
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  int v56; // w8
  unsigned __int64 v57; // x8
  unsigned int v58; // [xsp+0h] [xbp-20h]
  int v59; // [xsp+8h] [xbp-18h]
  int v60; // [xsp+10h] [xbp-10h]
  unsigned int v61; // [xsp+1Ch] [xbp-4h]

  *a5 = 0;
  *a7 = 0;
  qdf_mem_set(a6, 8u, 0);
  qdf_mem_set(a8, 2u, 0);
  if ( a4 )
    *a4 = 0;
  v23 = *(_QWORD **)(a2 + 1360);
  if ( !v23 || !v23[278] )
    return qdf_trace_msg(
             0x8Fu,
             2u,
             "%s: mlo_ctx or sta_ctx null",
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             "ml_nlink_convert_linkid_bitmap_to_vdev_bitmap");
  qdf_mutex_acquire((__int64)(v23 + 207));
  v32 = v23[3];
  v33 = v23[278];
  v61 = a3;
  if ( !v32 )
    goto LABEL_12;
  v34 = *(unsigned __int8 *)(v32 + 168);
  if ( (*(_QWORD *)(v33 + 8) & 1) == 0 )
  {
    v35 = "%s: vdev %d is not connected";
    v36 = 8;
LABEL_11:
    v39 = v23[278];
    qdf_trace_msg(
      0x8Fu,
      v36,
      v35,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "ml_nlink_convert_linkid_bitmap_to_vdev_bitmap",
      v34);
    v33 = v39;
LABEL_12:
    v40 = 0;
    v41 = 0;
    v42 = 0;
    goto LABEL_13;
  }
  v38 = *(unsigned __int8 *)(v32 + 93);
  if ( v38 >= 0xF )
  {
    v35 = "%s: invalid link id %d";
    v36 = 2;
    v34 = v38;
    goto LABEL_11;
  }
  v42 = 1 << v38;
  if ( ((1 << v38) & a3) != 0 )
  {
    if ( (unsigned int)v34 > 0x3F )
    {
      v41 = 0;
      v40 = 0;
      goto LABEL_19;
    }
    v41 = 1;
    v40 = (v34 >> 5) + 1;
    a6[v34 >> 5] |= 1 << v34;
    *a8 = v34;
  }
  else
  {
    v40 = 0;
    v41 = 0;
  }
LABEL_13:
  v43 = v23[4];
  if ( v43 )
  {
    v44 = *(unsigned __int8 *)(v43 + 168);
    if ( (*(_QWORD *)(v33 + 8) & 2) != 0 )
    {
      v47 = *(unsigned __int8 *)(v43 + 93);
      if ( v47 <= 0xE )
      {
        v56 = 1 << v47;
        v42 |= v56;
        if ( (v56 & v61) != 0 && (unsigned int)v44 <= 0x3F )
        {
          v57 = v44 >> 5;
          if ( (unsigned int)(v44 >> 5) >= v40 )
            v40 = v57 + 1;
          a6[v57] = a6[v44 >> 5] | (1 << v44);
          a8[v41++] = v44;
        }
        goto LABEL_19;
      }
      v45 = "%s: invalid link id %d";
      v46 = 2;
      v44 = v47;
    }
    else
    {
      v45 = "%s: vdev %d is not connected";
      v46 = 8;
    }
    qdf_trace_msg(
      0x8Fu,
      v46,
      v45,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "ml_nlink_convert_linkid_bitmap_to_vdev_bitmap",
      v44);
  }
LABEL_19:
  qdf_mutex_release((__int64)(v23 + 207));
  *a5 = v40;
  *a7 = v41;
  if ( a4 )
    *a4 = v42;
  v60 = v61;
  v59 = v42;
  v58 = v41;
  return qdf_trace_msg(
           0x8Fu,
           8u,
           "%s: vdev %d link bitmap 0x%x vdev_bitmap 0x%x sz %d num %d assoc 0x%x for bitmap 0x%x",
           v48,
           v49,
           v50,
           v51,
           v52,
           v53,
           v54,
           v55,
           "ml_nlink_convert_linkid_bitmap_to_vdev_bitmap",
           *(unsigned __int8 *)(a2 + 168),
           v42 & v61,
           *a6,
           *a5,
           v58,
           v59,
           v60);
}
