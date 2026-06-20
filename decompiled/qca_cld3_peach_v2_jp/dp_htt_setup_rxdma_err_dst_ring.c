__int64 __fastcall dp_htt_setup_rxdma_err_dst_ring(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v3; // x29
  __int64 v4; // x30
  int v5; // w19
  __int64 v6; // x20
  __int64 (__fastcall *v7)(__int64, __int64); // x8
  __int64 v8; // x21
  int v9; // w22
  int v10; // w8
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // [xsp+8h] [xbp-28h]

  if ( (unsigned int)a3 >= 2 )
  {
    __break(0x5512u);
    return dp_vdev_get_default_reo_hash(result, a2, a3);
  }
  else
  {
    v27 = v4;
    v5 = a3;
    v6 = result + 80LL * (unsigned int)a3;
    if ( *(_QWORD *)(v6 + 320) )
    {
      v7 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(result + 8) + 200LL);
      if ( !v7 )
        return htt_srng_setup(*(_QWORD *)(result + 48), a2, *(_QWORD *)(v6 + 320), 15);
      v8 = result;
      v9 = a2;
      if ( *((_DWORD *)v7 - 1) != 1696218653 )
        __break(0x8228u);
      v10 = v7(result, a2);
      LODWORD(a2) = v9;
      result = v8;
      if ( v10 == 4 && v5 == 1 && (*(_BYTE *)(v8 + 20045) & 1) == 0 )
      {
        *(_BYTE *)(*(_QWORD *)(v8 + 40) + 804LL) = 1;
        dp_srng_free(v8, v8 + 400, v11, v12, v13, v14, v15, v16, v17, v18);
        return qdf_trace_msg(
                 0x45u,
                 5u,
                 "%s: 2nd dest ring setup not supported, skip setup lmac %d",
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 v26,
                 "dp_pdev_srng_skip_rxdma_dst_ring_setup",
                 1,
                 v3,
                 v27);
      }
      else
      {
        return htt_srng_setup(*(_QWORD *)(result + 48), a2, *(_QWORD *)(v6 + 320), 15);
      }
    }
  }
  return result;
}
