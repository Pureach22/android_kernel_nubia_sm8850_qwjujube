__int64 __fastcall wlan_crypto_psoc_obj_create_handler(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x19
  unsigned int v4; // w0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int v13; // w20
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  _QWORD *v23; // x0
  __int64 v24; // x8
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7

  v2 = _qdf_mem_malloc(0x58u, "wlan_crypto_psoc_obj_create_handler", 496);
  if ( v2 )
  {
    v3 = v2;
    v4 = wlan_objmgr_psoc_component_obj_attach(a1, 14, v2, 0);
    if ( v4 )
    {
      v13 = v4;
      _qdf_mem_free(v3);
      qdf_trace_msg(
        0x1Cu,
        2u,
        "%s: failed to attach crypto psoc priv object",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "wlan_crypto_psoc_obj_create_handler");
      return v13;
    }
    qdf_trace_msg(0x1Cu, 4u, "%s: crypto log value %d ", v5, v6, v7, v8, v9, v10, v11, v12, "crypto_log2_ceil", 16);
    *(_QWORD *)(v3 + 72) = 0x40000000FLL;
    v23 = (_QWORD *)_qdf_mem_malloc(0x100u, "wlan_crypto_hash_init", 79);
    *(_QWORD *)(v3 + 80) = v23;
    if ( v23 )
    {
      *v23 = 0;
      v24 = *(_QWORD *)(v3 + 80);
      *(_QWORD *)(v24 + 8) = v24;
      *(_QWORD *)(v24 + 16) = 0;
      *(_QWORD *)(*(_QWORD *)(v3 + 80) + 24LL) = *(_QWORD *)(v3 + 80) + 16LL;
      *(_QWORD *)(*(_QWORD *)(v3 + 80) + 32LL) = 0;
      *(_QWORD *)(*(_QWORD *)(v3 + 80) + 40LL) = *(_QWORD *)(v3 + 80) + 32LL;
      *(_QWORD *)(*(_QWORD *)(v3 + 80) + 48LL) = 0;
      *(_QWORD *)(*(_QWORD *)(v3 + 80) + 56LL) = *(_QWORD *)(v3 + 80) + 48LL;
      *(_QWORD *)(*(_QWORD *)(v3 + 80) + 64LL) = 0;
      *(_QWORD *)(*(_QWORD *)(v3 + 80) + 72LL) = *(_QWORD *)(v3 + 80) + 64LL;
      *(_QWORD *)(*(_QWORD *)(v3 + 80) + 80LL) = 0;
      *(_QWORD *)(*(_QWORD *)(v3 + 80) + 88LL) = *(_QWORD *)(v3 + 80) + 80LL;
      *(_QWORD *)(*(_QWORD *)(v3 + 80) + 96LL) = 0;
      *(_QWORD *)(*(_QWORD *)(v3 + 80) + 104LL) = *(_QWORD *)(v3 + 80) + 96LL;
      *(_QWORD *)(*(_QWORD *)(v3 + 80) + 112LL) = 0;
      *(_QWORD *)(*(_QWORD *)(v3 + 80) + 120LL) = *(_QWORD *)(v3 + 80) + 112LL;
      *(_QWORD *)(*(_QWORD *)(v3 + 80) + 128LL) = 0;
      *(_QWORD *)(*(_QWORD *)(v3 + 80) + 136LL) = *(_QWORD *)(v3 + 80) + 128LL;
      *(_QWORD *)(*(_QWORD *)(v3 + 80) + 144LL) = 0;
      *(_QWORD *)(*(_QWORD *)(v3 + 80) + 152LL) = *(_QWORD *)(v3 + 80) + 144LL;
      *(_QWORD *)(*(_QWORD *)(v3 + 80) + 160LL) = 0;
      *(_QWORD *)(*(_QWORD *)(v3 + 80) + 168LL) = *(_QWORD *)(v3 + 80) + 160LL;
      *(_QWORD *)(*(_QWORD *)(v3 + 80) + 176LL) = 0;
      *(_QWORD *)(*(_QWORD *)(v3 + 80) + 184LL) = *(_QWORD *)(v3 + 80) + 176LL;
      *(_QWORD *)(*(_QWORD *)(v3 + 80) + 192LL) = 0;
      *(_QWORD *)(*(_QWORD *)(v3 + 80) + 200LL) = *(_QWORD *)(v3 + 80) + 192LL;
      *(_QWORD *)(*(_QWORD *)(v3 + 80) + 208LL) = 0;
      *(_QWORD *)(*(_QWORD *)(v3 + 80) + 216LL) = *(_QWORD *)(v3 + 80) + 208LL;
      *(_QWORD *)(*(_QWORD *)(v3 + 80) + 224LL) = 0;
      *(_QWORD *)(*(_QWORD *)(v3 + 80) + 232LL) = *(_QWORD *)(v3 + 80) + 224LL;
      *(_QWORD *)(*(_QWORD *)(v3 + 80) + 240LL) = 0;
      *(_QWORD *)(*(_QWORD *)(v3 + 80) + 248LL) = *(_QWORD *)(v3 + 80) + 240LL;
      qdf_mutex_create(v3);
      return 0;
    }
    wlan_objmgr_psoc_component_obj_detach(a1, 14, v3);
    _qdf_mem_free(v3);
    qdf_trace_msg(
      0x1Cu,
      2u,
      "%s: failed to hash init",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "wlan_crypto_psoc_obj_create_handler");
  }
  return 2;
}
