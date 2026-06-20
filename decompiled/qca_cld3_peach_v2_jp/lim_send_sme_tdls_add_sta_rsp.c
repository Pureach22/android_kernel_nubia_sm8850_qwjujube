__int64 __fastcall lim_send_sme_tdls_add_sta_rsp(
        __int64 a1,
        char a2,
        const void *a3,
        char a4,
        __int64 a5,
        unsigned __int8 a6)
{
  __int64 v11; // x0
  __int64 v12; // x19
  int v13; // w8
  unsigned int v14; // w20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v24; // [xsp+8h] [xbp-38h] BYREF
  __int64 v25; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v26)(__int64, double, double, double, double, double, double, double, double); // [xsp+18h] [xbp-28h]
  __int64 v27; // [xsp+20h] [xbp-20h]
  __int64 v28; // [xsp+28h] [xbp-18h]
  __int64 v29; // [xsp+30h] [xbp-10h]
  __int64 v30; // [xsp+38h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28 = 0;
  v29 = 0;
  v26 = nullptr;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  v11 = _qdf_mem_malloc(0x20u, "lim_send_sme_tdls_add_sta_rsp", 3852);
  if ( v11 )
  {
    v12 = v11;
    *(_BYTE *)(v11 + 10) = a2;
    *(_DWORD *)v11 = a6;
    if ( a3 )
      qdf_mem_copy((void *)(v11 + 4), a3, 6u);
    if ( a4 )
      v13 = 2;
    else
      v13 = 1;
    *(_DWORD *)(v12 + 16) = v13;
    *(_QWORD *)(v12 + 24) = *(_QWORD *)(a1 + 21552);
    v25 = v12;
    v26 = tgt_tdls_add_peer_rsp;
    v14 = scheduler_post_message_debug(
            0x35u,
            0,
            73,
            (unsigned __int16 *)&v24,
            0xF22u,
            (__int64)"lim_send_sme_tdls_add_sta_rsp");
    if ( v14 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: post msg fail, %d",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "lim_send_sme_tdls_add_sta_rsp",
        v14);
      _qdf_mem_free(v12);
    }
  }
  else
  {
    v14 = 2;
  }
  _ReadStatusReg(SP_EL0);
  return v14;
}
