__int64 __fastcall wma_vdev_tsf_handler(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        _QWORD *a10)
{
  unsigned int *v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  _DWORD *v20; // x20
  unsigned int *v21; // x19
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30; // w4
  unsigned int v31; // w5
  unsigned int v32; // w6
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 result; // x0
  __int64 v42; // [xsp+8h] [xbp-38h] BYREF
  unsigned int *v43; // [xsp+10h] [xbp-30h]
  __int64 v44; // [xsp+18h] [xbp-28h]
  __int64 v45; // [xsp+20h] [xbp-20h]
  __int64 v46; // [xsp+28h] [xbp-18h]
  __int64 v47; // [xsp+30h] [xbp-10h]
  __int64 v48; // [xsp+38h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v46 = 0;
  v47 = 0;
  v44 = 0;
  v45 = 0;
  v42 = 0;
  v43 = nullptr;
  if ( !a10 )
  {
    qdf_trace_msg(0x36u, 2u, "%s: invalid pointer", a1, a2, a3, a4, a5, a6, a7, a8, "wma_vdev_tsf_handler");
    goto LABEL_6;
  }
  v11 = (unsigned int *)_qdf_mem_malloc(0x2Cu, "wma_vdev_tsf_handler", 371);
  if ( !v11 )
  {
    result = 4294967284LL;
    goto LABEL_8;
  }
  v20 = (_DWORD *)*a10;
  v21 = v11;
  *v11 = v20[1];
  v11[1] = v20[2];
  v11[2] = v20[3];
  v11[3] = v20[4];
  v11[4] = v20[5];
  v11[5] = v20[10];
  v11[6] = v20[11];
  qdf_trace_msg(
    0x36u,
    8u,
    "receive WMI_VDEV_TSF_REPORT_EVENTID on %d, tsf: %d %d",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19);
  qdf_trace_msg(
    0x36u,
    8u,
    "g_tsf: %d %d; soc_timer: %d %d",
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v21[5],
    v21[6],
    v21[3],
    v21[4]);
  v30 = v20[9];
  v31 = v20[6];
  v32 = v20[7];
  v21[7] = v20[8];
  v21[8] = v30;
  v21[9] = v31;
  v21[10] = v32;
  qdf_trace_msg(
    0x36u,
    8u,
    "mac_id %d mac_id_valid %d tsf_id %d tsf_id_valid %d",
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40);
  v43 = v21;
  LOWORD(v42) = 5245;
  HIDWORD(v42) = 0;
  result = scheduler_post_message_debug(
             0x36u,
             0x34u,
             52,
             (unsigned __int16 *)&v42,
             0x193u,
             (__int64)"wma_vdev_tsf_handler");
  if ( (_DWORD)result )
  {
    _qdf_mem_free((__int64)v21);
LABEL_6:
    result = 4294967274LL;
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
