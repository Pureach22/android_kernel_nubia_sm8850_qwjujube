__int64 __fastcall dp_rx_page_pool_init(__int64 a1, unsigned int a2)
{
  __int64 v4; // x8
  __int64 v5; // x19
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 result; // x0
  __int64 v15; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned __int64 v24; // x20
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned __int64 v33; // x8
  unsigned __int64 v34; // x9
  bool v35; // cf
  unsigned __int64 v36; // x10
  unsigned int v37; // w8
  __int16 v38; // w9
  unsigned int v39; // w10
  bool v40; // cc
  unsigned __int64 v41; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v42[2]; // [xsp+10h] [xbp-10h] BYREF

  v42[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 >= 5 )
    __break(0x5512u);
  if ( (wlan_cfg_get_dp_rx_buffer_recycle(*(_QWORD *)(a1 + 40)) & 1) != 0 )
  {
    v4 = a1 + 544LL * a2;
    v5 = v4 + 20224;
    *(_DWORD *)(v4 + 20512) = 0;
    *(_BYTE *)(v4 + 20472) = 0;
    if ( (unsigned int)_qdf_delayed_work_create(
                         (_QWORD *)(v4 + 20520),
                         (__int64)dp_rx_page_pool_inactive_work,
                         v4 + 20224) )
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: Failed to create work for inactive page pool list",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "dp_rx_page_pool_init");
LABEL_8:
      result = 1;
      goto LABEL_9;
    }
    *(_QWORD *)(v5 + 416) = v5 + 416;
    *(_QWORD *)(v5 + 424) = v5 + 416;
    v15 = *(_QWORD *)(a1 + 24);
    *(_QWORD *)(v5 + 432) = 0;
    v41 = 0;
    v42[0] = 0;
    if ( (unsigned int)pld_get_iova_info(*(_QWORD *)(v15 + 40), (__int64)v42, (__int64)&v41) )
    {
LABEL_7:
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: Failed to initialize ipa ref counters",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "dp_rx_page_pool_init");
      _qdf_delayed_work_destroy();
      goto LABEL_8;
    }
    v24 = v41 >> 12;
    dp_desc_multi_pages_mem_alloc(a1, 0x10u, v5 + 464, 4u, v41 >> 12, 0, 1, v16, v17, v18, v19, v20, v21, v22, v23);
    if ( !*(_WORD *)(v5 + 466) )
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: Failed to allocate memory for ipa map counters",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "dp_rx_pp_ipa_ref_cntrs_init");
      goto LABEL_7;
    }
    v33 = 0;
    do
    {
      v34 = 0;
      do
      {
        v35 = v34 >= 0xFFC;
        *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v5 + 480) + 8 * v33) + v34) = 0;
        v34 += 4LL;
      }
      while ( !v35 );
      ++v33;
    }
    while ( v33 < *(unsigned __int16 *)(v5 + 466) );
    v36 = v41;
    v37 = *(unsigned __int16 *)(v5 + 464);
    *(_QWORD *)(v5 + 504) = v42[0];
    *(_QWORD *)(v5 + 512) = v36;
    if ( v37 )
    {
      v38 = -1;
      v39 = v37;
      do
      {
        v40 = v39 > 1;
        ++v38;
        v39 >>= 1;
      }
      while ( v40 );
      if ( 1 << v38 == v37 )
        LOWORD(v37) = v38;
      else
        LOWORD(v37) = v38 + 1;
    }
    *(_WORD *)(v5 + 524) = v37;
    *(_DWORD *)(v5 + 520) = ~(-1 << v37);
    *(_BYTE *)(v5 + 526) = 1;
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: num_ref_cntrs %u idx_shift %d offset mask 0x%x",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "dp_rx_pp_ipa_ref_cntrs_init",
      (unsigned int)v24,
      (unsigned __int16)v37);
    result = 0;
    *(_BYTE *)(v5 + 440) = 1;
  }
  else
  {
    result = 0;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
