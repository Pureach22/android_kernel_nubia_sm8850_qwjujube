__int64 __fastcall dp_tx_init_bank_profiles(_QWORD *a1)
{
  _QWORD *v2; // x21
  __int64 (*v3)(void); // x8
  char v4; // w8
  unsigned __int8 v5; // w8
  unsigned int v6; // w20
  __int64 v7; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x9
  __int64 v25; // x10
  char v26; // w0
  __int64 v27; // x20
  void (*v28)(void); // x8
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int v38; // w19
  __int64 v40; // x0
  unsigned int v46; // w9

  v2 = a1 + 2560;
  v3 = *(__int64 (**)(void))(*(_QWORD *)(a1[141] + 74392LL) + 1144LL);
  if ( !v3 )
    goto LABEL_19;
  if ( *((_DWORD *)v3 - 1) != 799902358 )
    __break(0x8228u);
  v4 = v3();
  if ( (v4 & 0xFE) == 0 )
    v4 = 1;
  v5 = v4 - 1;
  v6 = v5;
  if ( !v5 )
  {
LABEL_19:
    v40 = printk(
            &unk_AAA255,
            "expr",
            "__dp_assert_always_internal",
            "/proc/self/cwd/vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_internal.h");
    dump_stack(v40);
    v6 = 0;
    v5 = 0;
  }
  *((_BYTE *)v2 + 2048) = v5;
  v7 = _qdf_mem_malloc(12LL * v5, "dp_tx_init_bank_profiles", 2007);
  a1[2825] = v7;
  if ( v7 )
  {
    qdf_mutex_create((__int64)(a1 + 2817));
    if ( v6 )
    {
      v24 = 0;
      do
      {
        *(_BYTE *)(a1[2825] + v24) = 0;
        v25 = a1[2825] + v24;
        v24 += 12;
        *(_DWORD *)(v25 + 4) = 0;
      }
      while ( 12LL * v6 != v24 );
    }
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: initialized %u bank profiles",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "dp_tx_init_bank_profiles",
      *((unsigned __int8 *)v2 + 2048));
    if ( (wlan_cfg_is_ipa_enabled(a1[5]) & 1) != 0 )
    {
      v26 = wlan_cfg_pkt_type(a1[5]);
      v27 = *((unsigned __int8 *)v2 + 2048) - 1LL;
      *(_BYTE *)(a1[2825] + 12 * v27) = 1;
      *(_DWORD *)(a1[2825] + 12 * v27 + 8) = (2 * (v26 & 3)) | 0xC00;
      v28 = *(void (**)(void))(*(_QWORD *)(a1[141] + 74392LL) + 1808LL);
      if ( *((_DWORD *)v28 - 1) != -2046187666 )
        __break(0x8228u);
      v28();
      _X8 = (unsigned int *)(a1[2825] + 12 * v27 + 4);
      __asm { PRFM            #0x11, [X8] }
      do
        v46 = __ldxr(_X8);
      while ( __stxr(v46 + 1, _X8) );
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: IPA bank at slot %d config:0x%x",
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        "dp_tx_init_ipa_bank_profile",
        (unsigned int)v27,
        *(unsigned int *)(a1[2825] + 12LL * (int)v27 + 8));
    }
    else
    {
      LOBYTE(v27) = -1;
    }
    v38 = 0;
    *((_BYTE *)v2 + 3008) = v27;
  }
  else
  {
    v38 = 2;
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: unable to allocate memory for DP TX Profiles!",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "dp_tx_init_bank_profiles");
  }
  return v38;
}
