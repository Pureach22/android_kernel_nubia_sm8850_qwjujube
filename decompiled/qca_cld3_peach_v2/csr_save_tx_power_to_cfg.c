__int64 __fastcall csr_save_tx_power_to_cfg(__int64 a1, __int64 a2, int a3)
{
  __int64 result; // x0
  char *v7; // x19
  __int64 v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x1
  unsigned int v18; // w24
  unsigned int v19; // w23
  char *v20; // x26
  unsigned int v21; // w8
  int v22; // w9
  __int64 v23; // x4
  __int64 v24; // x8
  size_t v25; // x2
  void *v26; // x0
  __int64 v27; // x8

  result = _qdf_mem_malloc(0x320u, "csr_save_tx_power_to_cfg", 525);
  if ( !result )
    return result;
  v7 = (char *)result;
  csr_ll_lock(a2);
  v8 = csr_ll_peek_head(a2, 0);
  if ( !v8 )
  {
    v19 = 0;
    goto LABEL_17;
  }
  v17 = v8;
  v18 = 0;
  v19 = 0;
  v20 = v7;
  while ( *(_BYTE *)(v17 + 22) != 5 )
  {
    if ( v18 + 8 * *(unsigned __int8 *)(v17 + 20) > 0x31F )
    {
      v23 = *(unsigned int *)(v17 + 16);
      goto LABEL_16;
    }
    if ( *(_BYTE *)(v17 + 20) )
    {
      v21 = 0;
      do
      {
        v22 = *(_DWORD *)(v17 + 16);
        v20[4] = 1;
        ++v21;
        v18 += 8;
        *(_DWORD *)v20 = v22;
        v20[5] = *(_BYTE *)(v17 + 21);
        v20 += 8;
      }
      while ( v21 < *(unsigned __int8 *)(v17 + 20) );
      v19 += v21;
    }
LABEL_6:
    v17 = csr_ll_next(a2);
    if ( !v17 )
      goto LABEL_17;
  }
  if ( v18 < 0x318 )
  {
    v18 += 8;
    ++v19;
    *(_DWORD *)v20 = *(_DWORD *)(v17 + 16);
    v20[4] = *(_BYTE *)(v17 + 20);
    v20[5] = *(_BYTE *)(v17 + 21);
    v20 += 8;
    goto LABEL_6;
  }
  v23 = *(unsigned int *)(v17 + 16);
LABEL_16:
  qdf_trace_msg(
    0x34u,
    2u,
    "%s: Buffer overflow, start freq %d, num %d, offset %d",
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    "csr_save_tx_power_to_cfg",
    v23);
LABEL_17:
  csr_ll_unlock(a2);
  if ( a3 == 2 )
  {
    *(_QWORD *)(*(_QWORD *)(a1 + 8) + 3920LL) = 8LL * v19;
    v27 = *(_QWORD *)(a1 + 8);
    v25 = *(_QWORD *)(v27 + 3920);
    if ( v25 >= 0x101 )
    {
      *(_QWORD *)(v27 + 3920) = 256;
      v27 = *(_QWORD *)(a1 + 8);
      v25 = *(_QWORD *)(v27 + 3920);
    }
    v26 = (void *)(v27 + 3928);
LABEL_25:
    qdf_mem_copy(v26, v7, v25);
  }
  else if ( a3 == 1 )
  {
    *(_QWORD *)(*(_QWORD *)(a1 + 8) + 3776LL) = 8LL * v19;
    v24 = *(_QWORD *)(a1 + 8);
    v25 = *(_QWORD *)(v24 + 3776);
    if ( v25 >= 0x81 )
    {
      *(_QWORD *)(v24 + 3776) = 128;
      v24 = *(_QWORD *)(a1 + 8);
      v25 = *(_QWORD *)(v24 + 3776);
    }
    v26 = (void *)(v24 + 3784);
    goto LABEL_25;
  }
  return _qdf_mem_free((__int64)v7);
}
