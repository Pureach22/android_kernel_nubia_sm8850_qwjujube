__int64 __fastcall ml_nlink_convert_vdev_bitmap_to_linkid_bitmap(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        unsigned int a11,
        unsigned int *a12,
        unsigned int *a13,
        int *a14)
{
  _QWORD *v15; // x22
  __int64 v16; // x26
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x8
  unsigned __int64 v30; // x4
  const char *v31; // x2
  unsigned int v32; // w1
  unsigned int v34; // w8
  int v35; // w25
  __int64 v36; // x8
  unsigned __int64 v37; // x4
  const char *v38; // x2
  unsigned int v39; // w1
  unsigned int v40; // w8
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  int v49; // w8
  int v50; // [xsp+0h] [xbp-10h]

  *a13 = 0;
  if ( a14 )
    *a14 = 0;
  if ( !a11 )
    return qdf_trace_msg(
             0x8Fu,
             8u,
             "%s: vdev_id_bitmap_sz 0",
             a1,
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             "ml_nlink_convert_vdev_bitmap_to_linkid_bitmap");
  v15 = *(_QWORD **)(a10 + 1360);
  if ( !v15 )
    return qdf_trace_msg(
             0x8Fu,
             2u,
             "%s: mlo_ctx or sta_ctx null",
             a1,
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             "ml_nlink_convert_vdev_bitmap_to_linkid_bitmap");
  v16 = v15[278];
  if ( !v16 )
    return qdf_trace_msg(
             0x8Fu,
             2u,
             "%s: mlo_ctx or sta_ctx null",
             a1,
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             "ml_nlink_convert_vdev_bitmap_to_linkid_bitmap");
  qdf_mutex_acquire((__int64)(v15 + 207));
  v29 = v15[3];
  if ( !v29 )
    goto LABEL_14;
  v30 = *(unsigned __int8 *)(v29 + 168);
  if ( (*(_QWORD *)(v16 + 8) & 1) == 0 )
  {
    v31 = "%s: vdev %d is not connected";
    v32 = 8;
LABEL_13:
    qdf_trace_msg(
      0x8Fu,
      v32,
      v31,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "ml_nlink_convert_vdev_bitmap_to_linkid_bitmap",
      v30);
LABEL_14:
    v35 = 0;
    goto LABEL_15;
  }
  v34 = *(unsigned __int8 *)(v29 + 93);
  if ( v34 >= 0xF )
  {
    v31 = "%s: invalid link id %d";
    v32 = 2;
    v30 = v34;
    goto LABEL_13;
  }
  v35 = 1 << v34;
  if ( (unsigned int)(v30 >> 5) >= a11 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: invalid vdev id %d",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "ml_nlink_convert_vdev_bitmap_to_linkid_bitmap");
  }
  else if ( ((a12[v30 >> 5] >> v30) & 1) != 0 )
  {
    *a13 |= v35;
  }
LABEL_15:
  v36 = v15[4];
  if ( v36 )
  {
    v37 = *(unsigned __int8 *)(v36 + 168);
    if ( (*(_QWORD *)(v16 + 8) & 2) != 0 )
    {
      v40 = *(unsigned __int8 *)(v36 + 93);
      if ( v40 <= 0xE )
      {
        v49 = 1 << v40;
        v35 |= v49;
        if ( (unsigned int)(v37 >> 5) < a11 )
        {
          if ( ((a12[v37 >> 5] >> v37) & 1) != 0 )
            *a13 |= v49;
          goto LABEL_21;
        }
        v38 = "%s: invalid vdev id %d";
        v39 = 2;
      }
      else
      {
        v38 = "%s: invalid link id %d";
        v39 = 2;
        v37 = v40;
      }
    }
    else
    {
      v38 = "%s: vdev %d is not connected";
      v39 = 8;
    }
    qdf_trace_msg(
      0x8Fu,
      v39,
      v38,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "ml_nlink_convert_vdev_bitmap_to_linkid_bitmap",
      v37);
  }
LABEL_21:
  qdf_mutex_release((__int64)(v15 + 207));
  if ( a14 )
    *a14 = v35;
  v50 = v35;
  return qdf_trace_msg(
           0x8Fu,
           8u,
           "%s: vdev %d link bitmap 0x%x vdev_bitmap 0x%x sz %d assoc 0x%x",
           v41,
           v42,
           v43,
           v44,
           v45,
           v46,
           v47,
           v48,
           "ml_nlink_convert_vdev_bitmap_to_linkid_bitmap",
           *(unsigned __int8 *)(a10 + 168),
           *a13,
           *a12,
           a11,
           v50);
}
