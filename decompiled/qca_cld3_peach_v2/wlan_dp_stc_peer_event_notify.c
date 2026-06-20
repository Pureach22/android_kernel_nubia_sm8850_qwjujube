__int64 __fastcall wlan_dp_stc_peer_event_notify(
        __int64 a1,
        unsigned int a2,
        unsigned __int16 a3,
        char a4,
        const void *a5)
{
  __int64 v9; // x24
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 result; // x0
  __int64 v19; // x23
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  char v28; // w8
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x10
  __int64 v38; // x8
  __int64 v39; // x9
  __int64 v40; // x0
  unsigned __int64 v47; // x13
  __int64 v48; // x8
  __int64 v49; // x9

  v9 = *(_QWORD *)(dp_get_context() + 2936);
  if ( !v9 )
    return 11;
  if ( a3 > 0x3Fu )
    return 4;
  v19 = v9 + 96LL * a3;
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: STC: notify for peer %d, event %d, valid %d",
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    "wlan_dp_stc_peer_event_notify",
    a3,
    a2,
    *(unsigned __int8 *)(v19 + 262));
  if ( !a2 )
  {
    v28 = 0;
LABEL_13:
    if ( !*(_BYTE *)(v19 + 262) )
    {
      *(_BYTE *)(v19 + 263) = v28;
      *(_BYTE *)(v19 + 264) = a4;
      *(_WORD *)(v19 + 266) = a3;
      qdf_mem_copy((void *)(v19 + 256), a5, 6u);
      result = 0;
      *(_BYTE *)(v19 + 262) = 1;
      return result;
    }
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: STC: Peer map notify for active peer",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "wlan_dp_stc_peer_event_notify");
LABEL_19:
    v40 = printk(
            &unk_AAA255,
            "0",
            "wlan_dp_stc_peer_event_notify",
            "../vendor/qcom/opensource/wlan/qcacld-3.0/components/dp/core/src/wlan_dp_stc.c");
    dump_stack(v40);
    return 8;
  }
  if ( a2 != 2 )
  {
    result = 0;
    if ( a2 != 1 )
      return result;
    v28 = 1;
    goto LABEL_13;
  }
  if ( !*(_BYTE *)(v19 + 262) )
  {
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: STC: Peer unmap notify for inactive peer",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "wlan_dp_stc_peer_event_notify");
    goto LABEL_19;
  }
  if ( (unsigned int)qdf_mem_cmp((const void *)(v19 + 256), a5, 6u) )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: STC: peer unmap notify: mac addr mismatch",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "wlan_dp_stc_peer_event_notify");
    return 4;
  }
  else
  {
    *(_BYTE *)(v19 + 262) = 0;
    v37 = *(_QWORD *)(v9 + 6424);
    v38 = 0;
    v39 = *(_QWORD *)(v9 + 6400);
    do
    {
      if ( *(_DWORD *)(v37 + v38 + 100) == 2 && *(unsigned __int16 *)(v37 + v38 + 14) == a3 )
      {
        _X12 = (unsigned __int64 *)(v37 + v38 + 88);
        __asm { PRFM            #0x11, [X12] }
        do
          v47 = __ldxr(_X12);
        while ( __stxr(v47 | 4, _X12) );
      }
      v38 += 128;
    }
    while ( v38 != 0x8000 );
    v48 = v39 + 32;
    v49 = 128;
    do
    {
      if ( *(_DWORD *)(v48 - 16) )
      {
        if ( *(unsigned __int16 *)(v48 + 14) == a3 )
          *(_DWORD *)v48 |= 0x100u;
      }
      result = 0;
      --v49;
      v48 += 1872;
    }
    while ( v49 );
  }
  return result;
}
