__int64 __fastcall dp_srng_alloc(_QWORD *a1, __int64 a2, unsigned int a3, unsigned int a4, char a5)
{
  __int64 v5; // x20
  int entrysize; // w25
  unsigned int v12; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w8
  __int64 v22; // x0
  _DWORD *v24; // x8
  __int64 v25; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x24
  const char *v35; // x4

  v5 = a1[141];
  entrysize = hal_srng_get_entrysize(v5, a3);
  v12 = hal_srng_max_entries(v5, a3);
  if ( !*(_QWORD *)(a2 + 8) )
  {
    *(_QWORD *)a2 = 0;
    if ( v12 >= a4 )
      v21 = a4;
    else
      v21 = v12;
    if ( !v12 )
      v21 = a4;
    *(_DWORD *)(a2 + 52) = v21;
    *(_BYTE *)(a2 + 44) = a5 & 1;
    *(_DWORD *)(a2 + 40) = v21 * entrysize;
    if ( (a5 & 1) != 0 )
    {
      v22 = qdf_aligned_malloc_fl(
              (unsigned int *)(a2 + 40),
              (__int64 *)(a2 + 8),
              (__int64 *)(a2 + 24),
              (__int64 *)(a2 + 32),
              0x20u,
              "dp_srng_alloc",
              0x9E5u);
      *(_QWORD *)(a2 + 16) = v22;
      if ( v22 )
      {
LABEL_10:
        qdf_mem_set(*(void **)(a2 + 8), *(unsigned int *)(a2 + 40), 0);
        return 0;
      }
      return 2;
    }
    v24 = *(_DWORD **)(a1[1] + 232LL);
    if ( v24 )
    {
      if ( *(v24 - 1) != -245911730 )
        __break(0x8228u);
      v25 = ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64, __int64, _QWORD))v24)(
              a2 + 40,
              a2 + 8,
              a2 + 24,
              a2 + 32,
              32,
              a3);
      if ( v25 )
      {
        v34 = v25;
        v35 = "pre-alloc";
        *(_BYTE *)(a2 + 76) = 1;
        goto LABEL_22;
      }
    }
    else
    {
      qdf_trace_msg(
        0x45u,
        3u,
        "%s: dp_prealloc_get_consistent is null!",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "dp_srng_aligned_mem_alloc_consistent");
    }
    v34 = qdf_aligned_mem_alloc_consistent_fl(
            a1[3],
            (unsigned int *)(a2 + 40),
            (__int64 *)(a2 + 8),
            (__int64 *)(a2 + 24),
            (__int64 *)(a2 + 32),
            0x20u,
            (__int64)"dp_srng_aligned_mem_alloc_consistent",
            0x5D6u);
    if ( *(_BYTE *)(a2 + 76) )
      v35 = "pre-alloc";
    else
      v35 = "dynamic-alloc";
LABEL_22:
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: %s memory %pK dp_srng %pK ring_type %d alloc_size %d num_entries %d",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "dp_srng_aligned_mem_alloc_consistent",
      v35,
      v34,
      a2,
      a3,
      *(_DWORD *)(a2 + 40),
      *(_DWORD *)(a2 + 52));
    *(_QWORD *)(a2 + 16) = v34;
    if ( v34 )
      goto LABEL_10;
    return 2;
  }
  qdf_trace_msg(
    0x7Cu,
    2u,
    "%s: %pK: Ring type: %d, is already allocated",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "dp_srng_alloc",
    a1,
    a3);
  return 0;
}
