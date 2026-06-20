__int64 __fastcall cm_get_active_connect_req(
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
  unsigned int v29; // w10
  _QWORD *v30; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v31[2]; // [xsp+10h] [xbp-10h] BYREF

  v31[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30 = nullptr;
  v31[0] = 0;
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
        "cm_get_active_connect_req",
        1756);
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
      "cm_get_active_connect_req",
      1756,
      *(unsigned __int8 *)(a1 + 168));
    goto LABEL_15;
  }
  qdf_mutex_acquire(v21 + 120);
  qdf_list_peek_front((_QWORD *)(v21 + 96), v31);
  v22 = (_QWORD *)v31[0];
  if ( !v31[0] )
  {
LABEL_11:
    qdf_mutex_release(v21 + 120);
    goto LABEL_15;
  }
  while ( 1 )
  {
    qdf_list_peek_next((_QWORD *)(v21 + 96), v22, &v30);
    v23 = v31[0];
    v24 = *(_DWORD *)(v31[0] + 16LL);
    if ( v24 == *(_DWORD *)(v21 + 88) && (v24 & 0xF000000) == 201326592 )
      break;
    v22 = v30;
    v30 = nullptr;
    v31[0] = v22;
    if ( !v22 )
      goto LABEL_11;
  }
  v28 = *(unsigned __int8 *)(a2 + 8);
  *(_BYTE *)a2 = *(_BYTE *)(a1 + 168);
  *(_DWORD *)(a2 + 4) = *(_DWORD *)(v23 + 24);
  *(_QWORD *)(a2 + 56) = *(_QWORD *)(v23 + 1040);
  v29 = v28 & 0xFFFFFFFD | (2 * ((*(unsigned __int8 *)(v23 + 216) >> 1) & 1));
  *(_BYTE *)(a2 + 8) = v29;
  *(_BYTE *)(a2 + 8) = v29 & 0xFB | *(_BYTE *)(v23 + 216) & 4;
  *(_BYTE *)(a2 + 72) = *(_BYTE *)(v23 + 840);
  if ( *(_BYTE *)(v23 + 848) )
    qdf_mem_copy((void *)(a2 + 80), (const void *)(v23 + 848), 0xB0u);
  qdf_mutex_release(v21 + 120);
  result = 1;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
