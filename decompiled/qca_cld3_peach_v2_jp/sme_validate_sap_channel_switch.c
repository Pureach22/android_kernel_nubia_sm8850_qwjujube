bool __fastcall sme_validate_sap_channel_switch(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5)
{
  __int64 v5; // x29
  __int64 v6; // x30
  __int64 v8; // x24
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int16 v22; // w19
  __int64 v23; // [xsp+8h] [xbp-48h]

  if ( (unsigned __int8)a5 > 5u )
    return 0;
  v23 = v6;
  v8 = *(_QWORD *)(a1 + 17224) + 96LL * (unsigned __int8)a5;
  if ( !v8 )
    return 0;
  *(_BYTE *)(v8 + 60) = 1;
  if ( (unsigned int)qdf_mutex_acquire(a1 + 12776) )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: sme_acquire_global_lock error!",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "sme_validate_sap_channel_switch",
      v5,
      v23);
    *(_BYTE *)(v8 + 60) = 0;
    return 0;
  }
  else
  {
    v22 = csr_check_concurrent_channel_overlap(a1, a2, a3, a4, a5);
    qdf_mutex_release(a1 + 12776);
    *(_BYTE *)(v8 + 60) = 0;
    return v22 == 0;
  }
}
