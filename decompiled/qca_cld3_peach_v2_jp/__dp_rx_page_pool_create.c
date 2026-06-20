__int64 __fastcall _dp_rx_page_pool_create(
        __int64 a1,
        unsigned int a2,
        unsigned __int64 a3,
        _QWORD *a4,
        __int64 *a5,
        _BYTE *a6)
{
  unsigned __int64 v9; // x8
  unsigned __int64 v10; // x23
  unsigned __int64 v11; // x8
  __int64 v12; // x1
  _DWORD *v13; // x8
  _QWORD *v14; // x0
  __int64 v15; // x19
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x22
  __int64 v25; // x27
  __int64 v26; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x28
  unsigned int v36; // w25
  __int64 v37; // x26
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  int v46; // w25
  __int64 v47; // x1
  int v52; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v53; // [xsp+28h] [xbp-8h]

  v9 = 0x8000;
  v10 = a2;
  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  for ( *a4 = 0x8000; ; *a4 = 0x4000 )
  {
    while ( 1 )
    {
      v11 = v9 / a3;
      if ( v10 % v11 )
        v12 = v10 / v11 + 1;
      else
        v12 = v10 / v11;
      *a5 = v12;
      v13 = *(_DWORD **)(*(_QWORD *)(a1 + 8) + 264LL);
      if ( v13 )
      {
        if ( *(v13 - 1) != 1104720864 )
          __break(0x8228u);
        v14 = (_QWORD *)((__int64 (__fastcall *)(_QWORD, _QWORD))v13)(0, a2);
        if ( v14 )
        {
          v15 = v14[1];
          if ( v15 )
          {
            if ( v14[3] == *a5 && v14[4] == *a4 )
            {
              *a6 = 1;
              goto LABEL_33;
            }
          }
        }
      }
      v15 = _qdf_page_pool_create(*(_QWORD *)(a1 + 24));
      if ( !v15 )
      {
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: Failed to create page pool",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "__dp_rx_page_pool_create");
        goto LABEL_33;
      }
      v24 = *a5;
      v25 = *a4;
      v52 = 0;
      v26 = _qdf_mem_malloc(8LL * (unsigned int)v24, "dp_rx_page_pool_check_pages_availability", 481);
      if ( v26 )
      {
        v35 = v26;
        if ( !(_DWORD)v24 )
        {
          _qdf_mem_free(v26);
          goto LABEL_33;
        }
        v36 = 0;
        while ( 1 )
        {
          v37 = _qdf_page_pool_alloc_frag(v15, &v52, v25);
          *(_QWORD *)(v35 + 8LL * (int)v36) = v37;
          if ( !v37 )
            break;
          if ( (_DWORD)v24 == ++v36 )
            goto LABEL_22;
        }
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: page alloc failed for idx:%u",
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          "dp_rx_page_pool_check_pages_availability",
          v36);
LABEL_22:
        v46 = 0;
        do
        {
          v47 = *(_QWORD *)(v35 + 8LL * v46);
          if ( v47 )
            _qdf_page_pool_put_page(v15, v47, 0);
          ++v46;
        }
        while ( (_DWORD)v24 != v46 );
        _qdf_mem_free(v35);
        if ( v37 )
          goto LABEL_33;
      }
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: page pool resources not available for page_size:%zu",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "__dp_rx_page_pool_create",
        *a4);
      _qdf_page_pool_destroy(v15);
      if ( *a4 != 0x4000 )
        break;
      v9 = 4096;
      *a4 = 4096;
    }
    if ( *a4 != 0x8000 )
      break;
    v9 = 0x4000;
  }
  v15 = 0;
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return v15;
}
