__int64 __fastcall peer_assoc_add_mlo_params(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  char v11; // w8
  int v12; // w9
  int v13; // w8
  int v14; // w8
  int v15; // w8
  int v16; // w8
  int v17; // w5
  unsigned int v18; // w5
  int v19; // w8
  int v20; // w9
  int v21; // w10
  int v22; // w11
  int v23; // w12
  int v24; // w13
  int v25; // w14
  int v26; // w15
  unsigned int v27; // w5
  unsigned int v28; // w5
  unsigned int v29; // w5
  unsigned int v30; // w5
  int v31; // w16

  *(_DWORD *)(a1 + 8) = 0;
  *(_QWORD *)a1 = 0x3D0004000120044LL;
  v11 = *(_DWORD *)(a2 + 584);
  *(_DWORD *)(a1 + 8) = *(_DWORD *)(a2 + 584) & 1;
  v12 = *(_DWORD *)(a2 + 584) & 2 | v11 & 1;
  *(_DWORD *)(a1 + 8) = v12;
  v13 = *(_DWORD *)(a2 + 584) & 4 | v12;
  *(_DWORD *)(a1 + 8) = v13;
  v14 = *(_DWORD *)(a2 + 584) & 8 | v13;
  *(_DWORD *)(a1 + 8) = v14;
  v15 = *(_DWORD *)(a2 + 584) & 0x10 | v14;
  *(_DWORD *)(a1 + 8) = v15;
  v16 = (*(_DWORD *)(a2 + 584) >> 1) & 0x400 | v15;
  *(_DWORD *)(a1 + 8) = v16;
  v17 = v16 | *(_DWORD *)(a2 + 584) & 0x40;
  *(_DWORD *)(a1 + 8) = v17;
  v18 = v17 & 0xFFFFFF7F | (((*(_DWORD *)(a2 + 584) >> 5) & 1) << 7);
  *(_DWORD *)(a1 + 8) = v18;
  *(_DWORD *)(a1 + 12) = *(_DWORD *)(a2 + 588);
  *(_DWORD *)(a1 + 16) = *(unsigned __int16 *)(a2 + 592);
  *(_DWORD *)(a1 + 20) = *(_DWORD *)(a2 + 596);
  *(_DWORD *)(a1 + 24) = *(_DWORD *)(a2 + 600);
  v19 = *(_DWORD *)(a2 + 604);
  *(_DWORD *)(a1 + 28) = v19;
  v20 = *(_DWORD *)(a2 + 616);
  *(_DWORD *)(a1 + 32) = v20;
  v21 = *(unsigned __int16 *)(a2 + 610);
  *(_DWORD *)(a1 + 36) = v21;
  v22 = *(unsigned __int16 *)(a2 + 608);
  *(_DWORD *)(a1 + 40) = v22;
  v23 = *(unsigned __int16 *)(a2 + 620);
  *(_DWORD *)(a1 + 44) = v23;
  v24 = *(unsigned __int16 *)(a2 + 622);
  *(_DWORD *)(a1 + 48) = v24;
  v25 = *(unsigned __int16 *)(a2 + 624);
  *(_DWORD *)(a1 + 52) = v25;
  v26 = *(unsigned __int16 *)(a2 + 626);
  *(_DWORD *)(a1 + 56) = v26;
  v27 = v18 & 0xFFFFF7FF | (((*(_DWORD *)(a2 + 584) >> 9) & 1) << 11);
  *(_DWORD *)(a1 + 8) = v27;
  v28 = v27 & 0xFFFFEFFF | (((*(_DWORD *)(a2 + 584) >> 10) & 1) << 12);
  *(_DWORD *)(a1 + 8) = v28;
  v29 = v28 & 0xFFFFDFFF | (((*(_DWORD *)(a2 + 584) >> 12) & 1) << 13);
  *(_DWORD *)(a1 + 8) = v29;
  v30 = v29 & 0xFFFFFEFF | (((*(_DWORD *)(a2 + 584) >> 13) & 1) << 8);
  *(_DWORD *)(a1 + 8) = v30;
  v31 = *(_DWORD *)(a2 + 628);
  *(_DWORD *)(a1 + 60) = v31;
  *(_DWORD *)(a1 + 64) = *(unsigned __int8 *)(a2 + 694);
  if ( (*(_BYTE *)(a2 + 585) & 0x40) != 0 )
  {
    *(_DWORD *)(a1 + 8) = v30 & 0xFFEFFFFF;
    v30 = v30 & 0xFFEFFFFF | (((*(_DWORD *)(a2 + 584) >> 15) & 1) << 20);
    *(_DWORD *)(a1 + 8) = v30;
  }
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: emlsr_support %d mlo_flags 0x%x logical_link_index %d mld_peer_id %d ieee_link_id %d emlsr_trans_timeout_us %d e"
    "mlsr_trans_delay_us %d emlsr_padding_delay_us %d msd_dur_subfield %d msd_ofdm_ed_thr %d msd_max_num_txops %d max_num"
    "_simultaneous_links %d nstr_bitmap_present %d nstr_bitmap_size %d mlo_link_switch %d mlo_link_add %d nstr_indication"
    "_bitmap 0x%x single link emlsr %d MLD addr %02x:%02x:%02x:**:**:%02x",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "peer_assoc_add_mlo_params",
    (v30 >> 6) & 1,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    (v30 >> 11) & 1,
    (v30 >> 12) & 1,
    (v30 >> 13) & 1,
    (v30 >> 8) & 1,
    v31,
    v30 >> 20,
    *(unsigned __int8 *)(a2 + 588),
    *(unsigned __int8 *)(a2 + 589),
    *(unsigned __int8 *)(a2 + 590),
    *(unsigned __int8 *)(a2 + 593));
  return a1 + 72;
}
