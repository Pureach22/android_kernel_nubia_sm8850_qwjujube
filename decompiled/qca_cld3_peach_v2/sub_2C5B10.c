// positive sp value has been detected, the output may be wrong!
__int64 __fastcall sub_2C5B10(
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
        const char *a11,
        __int64 a12)
{
  int v12; // w14
  unsigned int v13; // w19
  __int64 v14; // x20
  __int64 v15; // x24
  unsigned int v17; // w8
  __int64 v18; // x10
  __int64 v19; // x21
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  const char *v28; // x2
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  const char *v37; // x5

  if ( !v12 )
    return vdevmgr_vdev_peer_delete_all_rsp_handle();
  qdf_trace_msg(0x33u, 8u, a11, a1, a2, a3, a4, a5, a6, a7, a8, a12 + 3717);
  *(_DWORD *)(v14 + 36) = 18;
  ((void (__fastcall *)(__int64))hdd_wmm_notify_app)(v14);
  v17 = *(_DWORD *)(v14 + 32);
  if ( v17 >= 5 )
  {
    __break(0x5512u);
    JUMPOUT(0x3AF6D0);
  }
  v18 = *(_QWORD *)(v14 + 24);
  v19 = v18 + 280LL * v17 + 1880;
  *(_QWORD *)(v18 + 280LL * v17 + 1980) = 0;
  if ( *(_BYTE *)(v14 + 76) == 1 )
  {
    *(_BYTE *)(v14 + 76) = 0;
    if ( (unsigned int)qdf_mc_timer_stop(v18 + 280LL * v17 + 1992) )
    {
      v28 = "%s: Failed to stop inactivity timer";
LABEL_9:
      qdf_trace_msg(0x33u, 2u, v28, v20, v21, v22, v23, v24, v25, v26, v27, "hdd_wmm_disable_inactivity_timer");
      goto LABEL_10;
    }
    if ( (unsigned int)qdf_mc_timer_destroy(v19 + 112) )
    {
      v28 = "%s: Failed to destroy inactivity timer:Timer started";
      goto LABEL_9;
    }
  }
LABEL_10:
  ((void (__fastcall *)(__int64))hdd_wmm_free_context)(v14);
  if ( *(_BYTE *)(v15 + 6) == 1 )
  {
    if ( *(_DWORD *)(v15 + 24) == 1 )
      *(_BYTE *)(v15 + 5) = 0;
    if ( *(_DWORD *)(v15 + 24) != 1 )
      goto LABEL_18;
  }
  if ( *(_BYTE *)v15 == 1 )
  {
    if ( (*(_BYTE *)(v15 + 5) & 1) != 0 )
      v37 = " ";
    else
      v37 = " not ";
  }
  else
  {
LABEL_18:
    v37 = " ";
    *(_BYTE *)(v15 + 5) = 1;
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: complete, access for TL AC %d is%sallowed",
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    "hdd_wmm_sme_callback",
    v13,
    v37);
  return 0;
}
