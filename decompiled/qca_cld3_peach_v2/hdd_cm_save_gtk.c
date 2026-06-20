__int64 __fastcall hdd_cm_save_gtk(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned __int8 *a10)
{
  _QWORD *context; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 *link_info_by_vdev; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned __int8 *v29; // x9
  char v30; // w2
  const void *v31; // x3
  unsigned __int8 *v32; // x8
  const void *v33; // x1
  __int64 *v34; // x5
  __int64 v35; // x8
  __int64 result; // x0
  __int64 v37; // [xsp+0h] [xbp-10h] BYREF
  __int64 v38; // [xsp+8h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v37 = 0;
  context = _cds_get_context(51, (__int64)"hdd_cm_save_gtk", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( !context )
  {
    qdf_trace_msg(0x33u, 2u, "%s: hdd_ctx is NULL", v12, v13, v14, v15, v16, v17, v18, v19, "hdd_cm_save_gtk", v37, v38);
LABEL_12:
    result = 4;
    goto LABEL_13;
  }
  link_info_by_vdev = (__int64 *)hdd_get_link_info_by_vdev(context);
  if ( !link_info_by_vdev )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: adapter is NULL for vdev %d",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "hdd_cm_save_gtk",
      *a10,
      v37,
      v38);
    goto LABEL_12;
  }
  if ( (a10[1] & 4) != 0 )
  {
    v29 = *((unsigned __int8 **)a10 + 18);
    if ( v29 )
    {
      v30 = v29[2];
      v31 = v29 + 36;
      v32 = v29 + 35;
      v33 = v29 + 3;
      v34 = (__int64 *)(v29 + 100);
LABEL_9:
      wlan_hdd_save_gtk_offload_params(*link_info_by_vdev, v33, v30, v31, *v32, v34);
      goto LABEL_10;
    }
  }
  v35 = *((_QWORD *)a10 + 17);
  if ( v35 )
  {
    v33 = nullptr;
    v30 = 0;
    v31 = (const void *)(v35 + 25);
    v32 = (unsigned __int8 *)(v35 + 89);
    v34 = &v37;
    goto LABEL_9;
  }
LABEL_10:
  result = 0;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
