__int64 __fastcall dp_tx_tso_desc_pool_alloc(
        __int64 a1,
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
  int v22; // w24
  char v23; // w25
  char v24; // w28
  char v25; // w27
  char v26; // w26
  unsigned int v27; // w22
  unsigned int v28; // w4
  char v29; // w21
  char v31; // w20
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7

  if ( !a2 )
    return 0;
  *(_WORD *)(a1 + 4850) = 0;
  dp_desc_multi_pages_mem_alloc(a1, 5u, a1 + 4864, 0x100u, a3, 0, 1, a4, a5, a6, a7, a8, a9, a10, a11);
  v22 = *(unsigned __int16 *)(a1 + 4866);
  if ( !*(_WORD *)(a1 + 4866) )
  {
    v23 = 0;
    v24 = 0;
    v25 = 0;
    v26 = 0;
    v31 = 0;
    v29 = 0;
    v27 = 0;
    goto LABEL_24;
  }
  if ( a2 == 1 )
    return 0;
  *(_WORD *)(a1 + 4922) = 0;
  v23 = 1;
  dp_desc_multi_pages_mem_alloc(a1, 5u, a1 + 4936, 0x100u, a3, 0, 1, v14, v15, v16, v17, v18, v19, v20, v21);
  if ( !*(_WORD *)(a1 + 4938) )
  {
    v24 = 0;
    v25 = 0;
    v26 = 0;
    v31 = 0;
    v29 = 0;
    v27 = 1;
    goto LABEL_24;
  }
  if ( a2 == 2 )
    return 0;
  *(_WORD *)(a1 + 4994) = 0;
  v24 = 1;
  dp_desc_multi_pages_mem_alloc(a1, 5u, a1 + 5008, 0x100u, a3, 0, 1, v14, v15, v16, v17, v18, v19, v20, v21);
  if ( !*(_WORD *)(a1 + 5010) )
  {
    v23 = 0;
    v25 = 0;
    v26 = 0;
    v31 = 0;
    v29 = 0;
    v27 = 2;
    goto LABEL_24;
  }
  if ( a2 == 3 )
    return 0;
  *(_WORD *)(a1 + 5066) = 0;
  v25 = 1;
  dp_desc_multi_pages_mem_alloc(a1, 5u, a1 + 5080, 0x100u, a3, 0, 1, v14, v15, v16, v17, v18, v19, v20, v21);
  if ( !*(_WORD *)(a1 + 5082) )
  {
    v23 = 0;
    v24 = 0;
    v26 = 0;
    v31 = 0;
    v29 = 0;
    v27 = 3;
    goto LABEL_24;
  }
  if ( a2 == 4 )
    return 0;
  *(_WORD *)(a1 + 5138) = 0;
  v26 = 1;
  dp_desc_multi_pages_mem_alloc(a1, 5u, a1 + 5152, 0x100u, a3, 0, 1, v14, v15, v16, v17, v18, v19, v20, v21);
  if ( !*(_WORD *)(a1 + 5154) )
  {
    v23 = 0;
    v24 = 0;
    v25 = 0;
    v31 = 0;
    v29 = 0;
    v27 = 4;
    goto LABEL_24;
  }
  if ( a2 == 5 )
    return 0;
  *(_WORD *)(a1 + 5210) = 0;
  v27 = 5;
  dp_desc_multi_pages_mem_alloc(a1, 5u, a1 + 5224, 0x100u, a3, 0, 1, v14, v15, v16, v17, v18, v19, v20, v21);
  if ( !*(_WORD *)(a1 + 5226) )
  {
    v23 = 0;
    v24 = 0;
    v25 = 0;
    v26 = 0;
    v29 = 0;
    v31 = 1;
    goto LABEL_24;
  }
  if ( a2 == 6 )
    return 0;
  v28 = a3;
  *(_WORD *)(a1 + 5282) = 0;
  v29 = 1;
  dp_desc_multi_pages_mem_alloc(a1, 5u, a1 + 5296, 0x100u, v28, 0, 1, v14, v15, v16, v17, v18, v19, v20, v21);
  if ( *(_WORD *)(a1 + 5298) )
  {
    if ( a2 != 7 )
    {
      __break(0x5512u);
      JUMPOUT(0x59DC2B0);
    }
    return 0;
  }
  v23 = 0;
  v24 = 0;
  v25 = 0;
  v26 = 0;
  v31 = 0;
  v27 = 6;
LABEL_24:
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: Multi page alloc fail, tx desc",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "dp_tx_tso_desc_pool_alloc_by_id");
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: failed to allocate TSO desc pool %d",
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    "dp_tx_tso_desc_pool_alloc",
    v27);
  if ( v22 )
  {
    dp_desc_multi_pages_mem_free(a1, 5u, (_BYTE *)(a1 + 4864), 0, 1, v40, v41, v42, v43, v44, v45, v46, v47);
    if ( (v23 & 1) == 0 )
    {
      dp_desc_multi_pages_mem_free(a1, 5u, (_BYTE *)(a1 + 4936), 0, 1, v48, v49, v50, v51, v52, v53, v54, v55);
      if ( (v24 & 1) == 0 )
      {
        dp_desc_multi_pages_mem_free(a1, 5u, (_BYTE *)(a1 + 5008), 0, 1, v56, v57, v58, v59, v60, v61, v62, v63);
        if ( (v25 & 1) == 0 )
        {
          dp_desc_multi_pages_mem_free(a1, 5u, (_BYTE *)(a1 + 5080), 0, 1, v64, v65, v66, v67, v68, v69, v70, v71);
          if ( (v26 & 1) == 0 )
          {
            dp_desc_multi_pages_mem_free(a1, 5u, (_BYTE *)(a1 + 5152), 0, 1, v72, v73, v74, v75, v76, v77, v78, v79);
            if ( (v31 & 1) == 0 )
            {
              dp_desc_multi_pages_mem_free(a1, 5u, (_BYTE *)(a1 + 5224), 0, 1, v80, v81, v82, v83, v84, v85, v86, v87);
              if ( (v29 & 1) == 0 )
                dp_desc_multi_pages_mem_free(a1, 5u, (_BYTE *)(a1 + 5296), 0, 1, v88, v89, v90, v91, v92, v93, v94, v95);
            }
          }
        }
      }
    }
  }
  return 2;
}
