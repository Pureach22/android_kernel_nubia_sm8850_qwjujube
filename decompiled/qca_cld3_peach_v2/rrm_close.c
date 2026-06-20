__int64 __fastcall rrm_close(__int64 a1)
{
  __int64 v1; // x24
  __int64 v2; // x25
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x27
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w22
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x23

  v1 = 0;
  v2 = a1 + 17488;
  do
  {
    v11 = v2 + 544 * v1;
    v12 = *(_QWORD *)(v11 + 64);
    if ( v12 )
    {
      _qdf_mem_free(v12);
      *(_QWORD *)(v11 + 64) = 0;
      *(_BYTE *)(v11 + 56) = 0;
    }
    if ( (unsigned int)qdf_mc_timer_get_current_state(v11 + 240) == 21 && (unsigned int)qdf_mc_timer_stop(v11 + 240) )
      qdf_trace_msg(0x34u, 2u, "%s: Timer stop fail", v13, v14, v15, v16, v17, v18, v19, v20, "rrm_close");
    v21 = qdf_mc_timer_destroy(v11 + 240);
    if ( v21 )
      qdf_trace_msg(0x34u, 2u, "%s: Fail to destroy timer", v22, v23, v24, v25, v26, v27, v28, v29, "rrm_close");
    csr_ll_lock(v11 + 144, v22, v23, v24, v25, v26, v27, v28, v29);
    while ( 1 )
    {
      v38 = csr_ll_remove_head(v11 + 144, 0, v30, v31, v32, v33, v34, v35, v36, v37);
      if ( !v38 )
        break;
      v47 = v38;
      _qdf_mem_free(*(_QWORD *)(v38 + 16));
      _qdf_mem_free(v47);
    }
    csr_ll_unlock(v11 + 144, v39, v40, v41, v42, v43, v44, v45, v46);
    csr_ll_close(v11 + 144, v3, v4, v5, v6, v7, v8, v9, v10);
    ++v1;
  }
  while ( v1 != 5 );
  return v21;
}
