__int64 __fastcall cm_get_rnr(
        __int64 a1,
        int a2,
        void *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 cmpt_obj; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x21
  _QWORD *v24; // x1
  __int64 v25; // x20
  __int64 result; // x0
  __int64 v27; // x8
  __int64 v28; // x8
  _QWORD *v29; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v30[2]; // [xsp+10h] [xbp-10h] BYREF

  v30[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29 = nullptr;
  v30[0] = 0;
  if ( (a2 & 0xF000000) != 0xC000000 )
    goto LABEL_13;
  if ( !a1 )
  {
    v25 = jiffies;
    if ( cm_get_cm_ctx_fl___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(0x68u, 2u, "%s:%u: vdev is NULL", a4, a5, a6, a7, a8, a9, a10, a11, "cm_get_rnr", 1897);
      cm_get_cm_ctx_fl___last_ticks = v25;
    }
    goto LABEL_13;
  }
  if ( (*(_DWORD *)(a1 + 16) & 0xFFFFFFFD) != 0 )
  {
LABEL_13:
    result = 4;
    goto LABEL_14;
  }
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1);
  if ( !cmpt_obj || (v23 = *(_QWORD *)(cmpt_obj + 496)) == 0 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s:%u: vdev %d cm_ctx is NULL",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "cm_get_rnr",
      1897,
      *(unsigned __int8 *)(a1 + 104));
    goto LABEL_13;
  }
  qdf_mutex_acquire(v23 + 120);
  qdf_list_peek_front((_QWORD *)(v23 + 96), v30);
  v24 = (_QWORD *)v30[0];
  if ( !v30[0] )
    goto LABEL_18;
  while ( 1 )
  {
    qdf_list_peek_next((_QWORD *)(v23 + 96), v24, &v29);
    if ( *(_DWORD *)(v30[0] + 16LL) == a2 )
      break;
    v24 = v29;
    v29 = nullptr;
    v30[0] = v24;
    if ( !v24 )
      goto LABEL_18;
  }
  v27 = *(_QWORD *)(v30[0] + 864LL);
  if ( v27 && (v28 = *(_QWORD *)(v27 + 24)) != 0 )
  {
    qdf_mem_copy(a3, (const void *)(v28 + 132), 0x3A0u);
    qdf_mutex_release(v23 + 120);
    result = 0;
  }
  else
  {
LABEL_18:
    qdf_mutex_release(v23 + 120);
    result = 16;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
