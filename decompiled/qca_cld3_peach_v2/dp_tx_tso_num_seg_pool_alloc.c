__int64 __fastcall dp_tx_tso_num_seg_pool_alloc(
        _WORD *a1,
        char a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  int v22; // w22
  unsigned int v23; // w23
  unsigned int v25; // w20
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7

  if ( !a2 )
    return 0;
  a1[2665] = 0;
  dp_desc_multi_pages_mem_alloc(
    (__int64)a1,
    6u,
    (__int64)(a1 + 2672),
    0x10u,
    a3,
    0,
    1,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11);
  v22 = (unsigned __int16)a1[2673];
  if ( !a1[2673] )
  {
    v23 = 0;
    v25 = 0;
    goto LABEL_24;
  }
  if ( a2 == 1 )
    return 0;
  a1[2701] = 0;
  v23 = 1;
  dp_desc_multi_pages_mem_alloc(
    (__int64)a1,
    6u,
    (__int64)(a1 + 2708),
    0x10u,
    a3,
    0,
    1,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21);
  if ( !a1[2709] )
  {
    v25 = 1;
    goto LABEL_24;
  }
  if ( a2 == 2 )
    return 0;
  a1[2737] = 0;
  dp_desc_multi_pages_mem_alloc(
    (__int64)a1,
    6u,
    (__int64)(a1 + 2744),
    0x10u,
    a3,
    0,
    1,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21);
  if ( !a1[2745] )
  {
    v23 = 2;
    v25 = 2;
    goto LABEL_24;
  }
  if ( a2 == 3 )
    return 0;
  a1[2773] = 0;
  dp_desc_multi_pages_mem_alloc(
    (__int64)a1,
    6u,
    (__int64)(a1 + 2780),
    0x10u,
    a3,
    0,
    1,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21);
  if ( !a1[2781] )
  {
    v23 = 3;
    v25 = 3;
    goto LABEL_24;
  }
  if ( a2 == 4 )
    return 0;
  a1[2809] = 0;
  dp_desc_multi_pages_mem_alloc(
    (__int64)a1,
    6u,
    (__int64)(a1 + 2816),
    0x10u,
    a3,
    0,
    1,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21);
  if ( !a1[2817] )
  {
    v23 = 4;
    v25 = 4;
    goto LABEL_24;
  }
  if ( a2 == 5 )
    return 0;
  a1[2845] = 0;
  dp_desc_multi_pages_mem_alloc(
    (__int64)a1,
    6u,
    (__int64)(a1 + 2852),
    0x10u,
    a3,
    0,
    1,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21);
  if ( !a1[2853] )
  {
    v23 = 5;
    v25 = 5;
    goto LABEL_24;
  }
  if ( a2 == 6 )
    return 0;
  a1[2881] = 0;
  v23 = 6;
  dp_desc_multi_pages_mem_alloc(
    (__int64)a1,
    6u,
    (__int64)(a1 + 2888),
    0x10u,
    a3,
    0,
    1,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21);
  if ( a1[2889] )
  {
    if ( a2 != 7 )
    {
      __break(0x5512u);
      JUMPOUT(0x5A448C4);
    }
    return 0;
  }
  v25 = 6;
LABEL_24:
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: Multi page alloc fail, tso_num_seg_pool",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "dp_tx_tso_num_seg_pool_alloc_by_id");
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: failed to allocate TSO num seg pool %d",
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    "dp_tx_tso_num_seg_pool_alloc",
    v25);
  if ( v22 )
  {
    do
    {
      dp_desc_multi_pages_mem_free((__int64)a1, 6u, &a1[36 * v23 + 2672], 0, 1, v34, v35, v36, v37, v38, v39, v40, v41);
      --v25;
    }
    while ( v25 );
  }
  return 2;
}
