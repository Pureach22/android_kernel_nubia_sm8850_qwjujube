__int64 __fastcall sme_set_ps_host_offload(
        __int64 a1,
        unsigned __int8 *a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v14; // x4
  __int64 v15; // x5
  __int64 v16; // x6
  __int64 v17; // x7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x8
  __int64 v27; // x0
  void *v28; // x22
  __int64 result; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // [xsp+8h] [xbp-38h] BYREF
  void *v39; // [xsp+10h] [xbp-30h]
  __int64 v40; // [xsp+18h] [xbp-28h]
  __int64 v41; // [xsp+20h] [xbp-20h]
  __int64 v42; // [xsp+28h] [xbp-18h]
  __int64 v43; // [xsp+30h] [xbp-10h]
  __int64 v44; // [xsp+38h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = a2[8];
  v15 = a2[9];
  v16 = a2[10];
  v17 = a2[11];
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = nullptr;
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: IP address = %d.%d.%d.%d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "sme_set_ps_host_offload",
    v14,
    v15,
    v16,
    v17);
  if ( a1 && a3 <= 5u && (v26 = *(_QWORD *)(a1 + 17224)) != 0 && (*(_BYTE *)(v26 + 96LL * a3 + 1) & 1) != 0 )
  {
    v27 = _qdf_mem_malloc(0x20u, "sme_set_ps_host_offload", 799);
    if ( v27 )
    {
      v28 = (void *)v27;
      wlan_mlme_get_bssid_vdev_id(*(_QWORD *)(a1 + 21560), a3, a2 + 24);
      qdf_mem_copy(v28, a2, 0x20u);
      LODWORD(v38) = 4228;
      v39 = v28;
      qdf_trace(52, 0xFBu, a3, 4228);
      result = scheduler_post_message_debug(
                 0x34u,
                 0x36u,
                 54,
                 (unsigned __int16 *)&v38,
                 0x32Fu,
                 (__int64)"sme_set_ps_host_offload");
      if ( (_DWORD)result )
      {
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: Not able to post WMA_SET_HOST_OFFLOAD msg to WMA",
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          "sme_set_ps_host_offload");
        _qdf_mem_free((__int64)v28);
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
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: CSR session is invalid",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "sme_set_ps_host_offload");
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
