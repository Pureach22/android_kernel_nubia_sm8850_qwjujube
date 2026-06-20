__int64 __fastcall sme_set_ps_ns_offload(
        __int64 a1,
        __int64 *a2,
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
  __int64 v12; // x8
  _QWORD *v14; // x0
  __int64 v15; // x8
  __int64 v16; // x9
  __int64 v17; // x10
  __int64 v18; // x11
  __int64 v19; // x20
  __int64 result; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // [xsp+8h] [xbp-38h] BYREF
  _QWORD *v30; // [xsp+10h] [xbp-30h]
  __int64 v31; // [xsp+18h] [xbp-28h]
  __int64 v32; // [xsp+20h] [xbp-20h]
  __int64 v33; // [xsp+28h] [xbp-18h]
  __int64 v34; // [xsp+30h] [xbp-10h]
  __int64 v35; // [xsp+38h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = nullptr;
  if ( a1 && a3 <= 5u && (v12 = *(_QWORD *)(a1 + 17296)) != 0 && (*(_BYTE *)(v12 + 96LL * a3 + 1) & 1) != 0 )
  {
    wlan_mlme_get_bssid_vdev_id(*(_QWORD *)(a1 + 21632), a3, a2 + 3);
    v14 = (_QWORD *)_qdf_mem_malloc(0x20u, "sme_set_ps_ns_offload", 850);
    if ( v14 )
    {
      v16 = a2[2];
      v15 = a2[3];
      v17 = *a2;
      v18 = a2[1];
      v19 = (__int64)v14;
      v14[2] = v16;
      v14[3] = v15;
      *v14 = v17;
      v14[1] = v18;
      v30 = v14;
      LODWORD(v29) = 4246;
      qdf_trace(52, 0xFBu, a3, 4246);
      result = scheduler_post_message_debug(
                 0x34u,
                 0x36u,
                 54,
                 (unsigned __int16 *)&v29,
                 0x360u,
                 (__int64)"sme_set_ps_ns_offload");
      if ( (_DWORD)result )
      {
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: Not able to post SIR_HAL_SET_HOST_OFFLOAD message to HAL",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "sme_set_ps_ns_offload");
        _qdf_mem_free(v19);
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
    qdf_trace_msg(0x34u, 2u, "%s: CSR session is invalid", a4, a5, a6, a7, a8, a9, a10, a11, "sme_set_ps_ns_offload");
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
