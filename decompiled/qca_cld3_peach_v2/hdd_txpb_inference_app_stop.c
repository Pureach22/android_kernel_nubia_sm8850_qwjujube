__int64 __fastcall hdd_txpb_inference_app_stop(
        __int64 a1,
        const void *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w20
  _QWORD *v30; // x21
  _QWORD *v31; // x23
  _QWORD v33[2]; // [xsp+0h] [xbp-50h] BYREF
  __int64 v34; // [xsp+10h] [xbp-40h]
  __int64 v35; // [xsp+18h] [xbp-38h]
  __int64 v36; // [xsp+20h] [xbp-30h]
  __int64 v37; // [xsp+28h] [xbp-28h]
  __int64 v38; // [xsp+30h] [xbp-20h]
  __int64 v39; // [xsp+38h] [xbp-18h]
  __int64 v40; // [xsp+40h] [xbp-10h]
  __int64 v41; // [xsp+48h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a1 + 1464) == 1 || *(_QWORD *)(a1 + 8) )
  {
    v39 = 0;
    v40 = 0;
    v37 = 0;
    v38 = 0;
    v35 = 0;
    v36 = 0;
    v33[1] = 0;
    v34 = 0;
    v33[0] = 0;
    qdf_mem_copy(v33, a2, 0x40u);
    v11 = *(_QWORD *)(a1 + 8);
    HIDWORD(v34) = 2;
    v20 = ucfg_reg_txpb_send_inference_cmd(v11, v12, v13, v14, v15, v16, v17, v18, v19);
    if ( v20 )
    {
      v29 = v20;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: TPB: hdd_txpb_inference_send_abort failed: %d",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "hdd_txpb_inference_app_stop",
        v20);
      goto LABEL_9;
    }
  }
  else
  {
    qdf_trace_msg(0x33u, 3u, "%s: TPB: pdev is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_txpb_inference_app_stop");
  }
  qdf_mutex_acquire(a1 + 8848);
  v30 = *(_QWORD **)(a1 + 8824);
  if ( v30 != (_QWORD *)(a1 + 8824) )
  {
    do
    {
      v31 = (_QWORD *)*v30;
      qdf_list_remove_node(a1 + 8824, v30);
      _qdf_mem_free((__int64)v30);
      v30 = v31;
    }
    while ( v31 != (_QWORD *)(a1 + 8824) );
  }
  qdf_mutex_release(a1 + 8848);
  v29 = 0;
  *(_BYTE *)(a1 + 8568) = 0;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return v29;
}
