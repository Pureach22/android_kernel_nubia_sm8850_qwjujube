__int64 __fastcall dp_rx_mon_refill_buf_ring_2_0(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x19
  int v10; // w8
  __int64 v11; // x21
  __int64 v12; // x20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w3
  unsigned int v22; // w9
  unsigned int v23; // w8
  int v24; // w22
  int v25; // w23
  unsigned int *v26; // x2
  __int64 v27; // x8
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int v36; // w8
  _QWORD *v38; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v39[2]; // [xsp+10h] [xbp-10h] BYREF

  v39[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 16);
  v10 = *(_DWORD *)(a1 + 108);
  v38 = nullptr;
  v39[0] = 0;
  v11 = *(_QWORD *)(v9 + 20056);
  v12 = *(_QWORD *)(v9 + 480);
  *(_DWORD *)(a1 + 108) = v10 + 1;
  ++*(_DWORD *)(v11 + 848);
  hal_srng_access_start_4(*(_QWORD *)(v9 + 1128), v12, a2, a3, a4, a5, a6, a7, a8, a9);
  v21 = *(_DWORD *)(v12 + 120);
  v22 = **(_DWORD **)(v12 + 128);
  v23 = v22 - v21;
  *(_DWORD *)(v12 + 136) = v22;
  if ( v22 <= v21 )
    v23 += *(_DWORD *)(v12 + 36);
  v24 = *(_DWORD *)(v9 + 532);
  v25 = v23 / *(_DWORD *)(v12 + 44) - 1;
  if ( !v12 )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: Error: Invalid hal_ring\n",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "hal_srng_access_end");
    goto LABEL_7;
  }
  v26 = *(unsigned int **)(v12 + 144);
  if ( (*(_DWORD *)(v12 + 76) & 0x80000000) != 0 )
  {
    *v26 = v21;
    v27 = *(_QWORD *)(v12 + 88);
    if ( (v27 & 1) == 0 )
      goto LABEL_6;
LABEL_12:
    *(_QWORD *)(v12 + 88) = v27 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v12 + 80);
    goto LABEL_7;
  }
  hal_delayed_reg_write(*(_QWORD *)(v9 + 1128), (unsigned __int8 *)v12, (__int64)v26, v21);
  v27 = *(_QWORD *)(v12 + 88);
  if ( (v27 & 1) != 0 )
    goto LABEL_12;
LABEL_6:
  raw_spin_unlock(v12 + 80);
LABEL_7:
  if ( v25 )
  {
    v36 = *(unsigned __int16 *)(v11 + 840);
    if ( v36 > v24 - v25 )
      dp_mon_buffers_replenish(
        (__int64 *)v9,
        (_QWORD *)(v9 + 480),
        v11 + 768,
        v36 - (v24 - v25),
        v39,
        &v38,
        nullptr,
        16,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35);
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
