__int64 __fastcall sme_add_beacon_filter(
        __int64 a1,
        unsigned __int8 a2,
        const void *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  unsigned int v13; // w19
  _DWORD *v14; // x0
  __int64 v15; // x20
  __int64 result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w21
  __int64 v26; // [xsp+8h] [xbp-38h] BYREF
  __int64 v27; // [xsp+10h] [xbp-30h]
  __int64 v28; // [xsp+18h] [xbp-28h]
  __int64 v29; // [xsp+20h] [xbp-20h]
  __int64 v30; // [xsp+28h] [xbp-18h]
  __int64 v31; // [xsp+30h] [xbp-10h]
  __int64 v32; // [xsp+38h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  if ( !a1 || a2 > 5u || (v11 = *(_QWORD *)(a1 + 17224)) == 0 || (*(_BYTE *)(v11 + 96LL * a2 + 1) & 1) == 0 )
  {
    qdf_trace_msg(0x34u, 2u, "%s: vdev %d not valid", a4, a5, a6, a7, a8, a9, a10, a11, "sme_add_beacon_filter", a2);
    goto LABEL_9;
  }
  v13 = a2;
  v14 = (_DWORD *)_qdf_mem_malloc(0x44u, "sme_add_beacon_filter", 12991);
  if ( !v14 )
  {
LABEL_9:
    result = 16;
    goto LABEL_10;
  }
  v15 = (__int64)v14;
  *v14 = v13;
  qdf_mem_copy(v14 + 1, a3, 0x40u);
  LOWORD(v26) = 4467;
  v27 = v15;
  result = scheduler_post_message_debug(
             0x34u,
             0x36u,
             54,
             (unsigned __int16 *)&v26,
             0x32CDu,
             (__int64)"sme_add_beacon_filter");
  if ( (_DWORD)result )
  {
    v25 = result;
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: vdev %d Not able to post msg to WDA!",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "sme_add_beacon_filter",
      v13);
    _qdf_mem_free(v15);
    result = v25;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
