__int64 __fastcall sme_set_keep_alive(
        __int64 a1,
        unsigned __int8 a2,
        unsigned int *a3,
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
  unsigned int v15; // w21
  __int64 v16; // x0
  __int64 v17; // x20
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 result; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // [xsp+8h] [xbp-38h] BYREF
  __int64 v36; // [xsp+10h] [xbp-30h]
  __int64 v37; // [xsp+18h] [xbp-28h]
  __int64 v38; // [xsp+20h] [xbp-20h]
  __int64 v39; // [xsp+28h] [xbp-18h]
  __int64 v40; // [xsp+30h] [xbp-10h]
  __int64 v41; // [xsp+38h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  if ( a1 && a2 <= 5u && (v11 = *(_QWORD *)(a1 + 17296)) != 0 && (*(_BYTE *)(v11 + 96LL * a2 + 1) & 1) != 0 )
  {
    v15 = a2;
    v16 = _qdf_mem_malloc(0x20u, "sme_set_keep_alive", 5551);
    if ( v16 )
    {
      v17 = v16;
      wlan_mlme_get_bssid_vdev_id(*(_QWORD *)(a1 + 21632), a2, (char *)a3 + 22);
      qdf_mem_copy((void *)v17, a3, 0x20u);
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: vdev %d buff TP %d input TP %d ",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "sme_set_keep_alive",
        v15,
        *(unsigned int *)(v17 + 4),
        a3[1]);
      *(_BYTE *)(v17 + 28) = a2;
      LODWORD(v35) = 4245;
      v36 = v17;
      qdf_trace(52, 0xFBu, a2, 4245);
      result = scheduler_post_message_debug(
                 0x34u,
                 0x36u,
                 54,
                 (unsigned __int16 *)&v35,
                 0x15C3u,
                 (__int64)"sme_set_keep_alive");
      if ( (_DWORD)result )
      {
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: Not able to post WMA_SET_KEEP_ALIVE message to WMA",
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          "sme_set_keep_alive");
        _qdf_mem_free(v17);
        result = 16;
      }
    }
    else
    {
      result = 2;
    }
  }
  else
  {
    qdf_trace_msg(0x34u, 2u, "%s: invalid vdev %d", a4, a5, a6, a7, a8, a9, a10, a11, "sme_set_keep_alive", a2);
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
