__int64 __fastcall cm_get_active_disconnect_req(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 cmpt_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x19
  _QWORD *v22; // x1
  __int64 v23; // x8
  int v24; // w9
  __int64 v26; // x20
  __int64 result; // x0
  int v28; // w10
  _QWORD *v29; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v30[2]; // [xsp+10h] [xbp-10h] BYREF

  v30[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29 = nullptr;
  v30[0] = 0;
  if ( !a1 )
  {
    v26 = jiffies;
    if ( cm_get_cm_ctx_fl___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s:%u: vdev is NULL",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "cm_get_active_disconnect_req",
        1801);
      result = 0;
      cm_get_cm_ctx_fl___last_ticks = v26;
      goto LABEL_16;
    }
LABEL_15:
    result = 0;
    goto LABEL_16;
  }
  if ( (*(_DWORD *)(a1 + 16) & 0xFFFFFFFD) != 0 )
    goto LABEL_15;
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1);
  if ( !cmpt_obj || (v21 = *(_QWORD *)(cmpt_obj + 512)) == 0 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s:%u: vdev %d cm_ctx is NULL",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "cm_get_active_disconnect_req",
      1801,
      *(unsigned __int8 *)(a1 + 168));
    goto LABEL_15;
  }
  qdf_mutex_acquire(v21 + 120);
  qdf_list_peek_front((_QWORD *)(v21 + 96), v30);
  v22 = (_QWORD *)v30[0];
  if ( !v30[0] )
  {
LABEL_11:
    qdf_mutex_release(v21 + 120);
    goto LABEL_15;
  }
  while ( 1 )
  {
    qdf_list_peek_next((_QWORD *)(v21 + 96), v22, &v29);
    v23 = v30[0];
    v24 = *(_DWORD *)(v30[0] + 16LL);
    if ( v24 == *(_DWORD *)(v21 + 88) && (v24 & 0xF000000) == 218103808 )
      break;
    v22 = v29;
    v29 = nullptr;
    v30[0] = v22;
    if ( !v22 )
      goto LABEL_11;
  }
  *(_DWORD *)a2 = v24;
  *(_BYTE *)(a2 + 4) = *(_BYTE *)(a1 + 168);
  *(_DWORD *)(a2 + 8) = *(_DWORD *)(v23 + 32);
  *(_DWORD *)(a2 + 12) = *(_DWORD *)(v23 + 36);
  v28 = *(_DWORD *)(v23 + 40);
  *(_WORD *)(a2 + 20) = *(_WORD *)(v23 + 44);
  *(_DWORD *)(a2 + 16) = v28;
  *(_BYTE *)(a2 + 22) = *(_BYTE *)(v23 + 46);
  qdf_mutex_release(v21 + 120);
  result = 1;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
