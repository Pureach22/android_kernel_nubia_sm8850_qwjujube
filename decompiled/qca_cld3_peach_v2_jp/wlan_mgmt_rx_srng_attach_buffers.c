__int64 __fastcall wlan_mgmt_rx_srng_attach_buffers(__int64 a1)
{
  unsigned int v2; // w22
  __int64 v3; // x20
  int v4; // w23
  unsigned int v5; // w0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  int v14; // w8
  bool v15; // nf
  int v16; // w9
  int v17; // w8
  int v18; // w9
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  int v27; // w24
  __int64 v28; // x0
  __int64 v29; // x9
  __int64 v30; // x1
  __int64 v31; // x2
  _DWORD *v32; // x8
  __int64 v33; // x8
  unsigned int v34; // w9
  __int64 v35; // x10
  unsigned int v36; // w21
  __int64 i; // x20
  __int64 v38; // x8
  __int64 v39; // x0
  __int64 v40; // x8
  __int64 v42; // [xsp+0h] [xbp-10h] BYREF
  __int64 v43; // [xsp+8h] [xbp-8h]

  v2 = 0;
  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 72);
  v4 = *(_DWORD *)(a1 + 92);
  v42 = 0;
  while ( 1 )
  {
    v5 = wlan_mgmt_rx_srng_alloc_buf(a1, v2, &v42);
    if ( v5 )
      break;
    ++v2;
    v14 = *(_DWORD *)(a1 + 92) + 1;
    v16 = -v14;
    v15 = -v14 < 0;
    v17 = v14 & 0x7F;
    v18 = v16 & 0x7F;
    if ( !v15 )
      v17 = -v18;
    *(_DWORD *)(a1 + 92) = v17;
    if ( v2 == 127 )
    {
      hal_srng_access_start_5(*(_QWORD *)(a1 + 24), v3, v6, v7, v8, v9, v10, v11, v12, v13);
      v27 = 127;
      do
      {
        v33 = *(unsigned int *)(v3 + 120);
        v34 = (unsigned int)(*(_DWORD *)(v3 + 44) + v33) % *(_DWORD *)(v3 + 36);
        if ( v34 == *(_DWORD *)(v3 + 136)
          || (v35 = *(_QWORD *)(v3 + 16),
              *(_DWORD *)(v3 + 120) = v34,
              *(_DWORD *)(v3 + 124) = v34,
              (v28 = v35 + 4 * v33) == 0) )
        {
          qdf_trace_msg(
            0xA5u,
            2u,
            "%s: Failure to get mgmt refill entry",
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            "wlan_mgmt_rx_srng_attach_buffers",
            v42,
            v43);
          v28 = 0;
        }
        v29 = *(_QWORD *)(a1 + 80) + 24LL * v4;
        v30 = *(_QWORD *)(v29 + 8);
        v31 = *(unsigned __int8 *)(v29 + 16);
        v32 = *(_DWORD **)(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 74392LL) + 1472LL);
        if ( *(v32 - 1) != -1494657337 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v32)(v28, v30, v31, 0);
        if ( v4 + 1 <= 0 )
          v4 = -(-(v4 + 1) & 0x7F);
        else
          v4 = (v4 + 1) & 0x7F;
        --v27;
      }
      while ( v27 );
      if ( v3 )
      {
        if ( (*(_DWORD *)(v3 + 76) & 0x80000000) != 0 )
        {
          **(_DWORD **)(v3 + 144) = *(_DWORD *)(v3 + 120);
          v40 = *(_QWORD *)(v3 + 88);
          if ( (v40 & 1) != 0 )
            goto LABEL_29;
LABEL_25:
          raw_spin_unlock(v3 + 80);
        }
        else
        {
          hal_delayed_reg_write(
            *(_QWORD *)(a1 + 24),
            (unsigned __int8 *)v3,
            *(_QWORD *)(v3 + 144),
            *(_DWORD *)(v3 + 120));
          v40 = *(_QWORD *)(v3 + 88);
          if ( (v40 & 1) == 0 )
            goto LABEL_25;
LABEL_29:
          *(_QWORD *)(v3 + 88) = v40 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v3 + 80);
        }
      }
      else
      {
        qdf_trace_msg(
          0x38u,
          2u,
          "%s: Error: Invalid hal_ring\n",
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          "hal_srng_access_end");
      }
      v36 = 0;
      goto LABEL_27;
    }
  }
  v36 = v5;
  for ( i = 0; i != 3072; i += 24 )
  {
    v38 = *(_QWORD *)(a1 + 80) + i;
    if ( *(_BYTE *)(v38 + 17) == 1 )
    {
      _qdf_nbuf_unmap_single(*(_QWORD *)(a1 + 16), *(_QWORD *)v38, 2);
      v39 = *(_QWORD *)(*(_QWORD *)(a1 + 80) + i);
      if ( v39 )
        _qdf_nbuf_free(v39);
    }
  }
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return v36;
}
