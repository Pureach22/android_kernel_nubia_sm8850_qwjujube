__int64 __fastcall sme_close(__int64 a1)
{
  unsigned int v2; // w20
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  unsigned int v11; // w0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w21
  unsigned int v21; // w0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30; // w21
  unsigned int v31; // w0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned int v40; // w21
  __int64 v41; // x0
  unsigned __int64 v42; // x21
  unsigned int v43; // w0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 result; // x0

  if ( !a1 )
    return 16;
  if ( !(unsigned int)qdf_mutex_acquire(a1 + 12848) )
  {
    *(_QWORD *)(a1 + 13056) = 0;
    qdf_mutex_release(a1 + 12848);
  }
  v2 = csr_close(a1);
  if ( v2 )
    qdf_trace_msg(0x34u, 2u, "%s: csr_close failed with status: %d", v3, v4, v5, v6, v7, v8, v9, v10, "sme_close", v2);
  v11 = sme_qos_close(a1);
  if ( v11 )
  {
    v20 = v11;
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Qos close failed with status: %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "sme_close",
      v11);
    v2 = v20;
  }
  v21 = sme_ps_close(a1);
  if ( v21 )
  {
    v30 = v21;
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: sme_ps_close failed status: %d",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "sme_close",
      v21);
    v2 = v30;
  }
  v31 = rrm_close(a1);
  if ( v31 )
  {
    v40 = v31;
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: RRM close failed with status: %d",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "sme_close",
      v31);
    v2 = v40;
  }
  csr_ll_close(a1 + 12928);
  if ( !(unsigned int)qdf_mutex_acquire(a1 + 12848) )
  {
    v41 = *(_QWORD *)(a1 + 12920);
    if ( v41 )
    {
      if ( *(_DWORD *)(a1 + 12912) )
      {
        v42 = 0;
        do
          _qdf_mem_free(*(_QWORD *)(*(_QWORD *)(a1 + 12920) + 8 * v42++));
        while ( v42 < *(unsigned int *)(a1 + 12912) );
        v41 = *(_QWORD *)(a1 + 12920);
      }
      _qdf_mem_free(v41);
      *(_QWORD *)(a1 + 12920) = 0;
    }
    v43 = qdf_mutex_release(a1 + 12848);
    if ( v43 )
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Failed to release the lock status: %d",
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        "free_sme_cmd_list",
        v43);
  }
  if ( (unsigned int)qdf_mutex_destroy(a1 + 12848) )
    result = 16;
  else
    result = v2;
  *(_DWORD *)(a1 + 12840) = 0;
  return result;
}
