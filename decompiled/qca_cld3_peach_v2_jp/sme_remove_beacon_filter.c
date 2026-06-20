__int64 __fastcall sme_remove_beacon_filter(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  unsigned int v11; // w19
  _DWORD *v12; // x0
  __int64 v13; // x20
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w21
  __int64 v24; // [xsp+8h] [xbp-38h] BYREF
  _DWORD *v25; // [xsp+10h] [xbp-30h]
  __int64 v26; // [xsp+18h] [xbp-28h]
  __int64 v27; // [xsp+20h] [xbp-20h]
  __int64 v28; // [xsp+28h] [xbp-18h]
  __int64 v29; // [xsp+30h] [xbp-10h]
  __int64 v30; // [xsp+38h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = nullptr;
  if ( !a1 || a2 > 5u || (v10 = *(_QWORD *)(a1 + 17224)) == 0 || (*(_BYTE *)(v10 + 96LL * a2 + 1) & 1) == 0 )
  {
    qdf_trace_msg(0x34u, 2u, "%s: vdev %d not valid", a3, a4, a5, a6, a7, a8, a9, a10, "sme_remove_beacon_filter", a2);
    goto LABEL_9;
  }
  v11 = a2;
  v12 = (_DWORD *)_qdf_mem_malloc(0x44u, "sme_remove_beacon_filter", 13026);
  if ( !v12 )
  {
LABEL_9:
    result = 16;
    goto LABEL_10;
  }
  *v12 = v11;
  v13 = (__int64)v12;
  v25 = v12;
  LOWORD(v24) = 4468;
  result = scheduler_post_message_debug(
             0x34u,
             0x36u,
             54,
             (unsigned __int16 *)&v24,
             0x32EDu,
             (__int64)"sme_remove_beacon_filter");
  if ( (_DWORD)result )
  {
    v23 = result;
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: vdev %d Not able to post msg to WDA!",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "sme_remove_beacon_filter",
      v11);
    _qdf_mem_free(v13);
    result = v23;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
