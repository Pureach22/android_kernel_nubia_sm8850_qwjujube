_QWORD *__fastcall _cam_isp_ctx_free_mem_hw_entries(_QWORD *result)
{
  _QWORD **v1; // x8
  _QWORD *v2; // x19
  _QWORD *v3; // x0
  _QWORD *v4; // x0
  _QWORD *v5; // x0
  _QWORD *v6; // x0
  _QWORD *v7; // x0
  _QWORD *v8; // x0
  _QWORD *v9; // x0
  _QWORD *v10; // x0
  _QWORD *v11; // x0
  _QWORD **v12; // x8
  _QWORD *v13; // x0
  _QWORD *v14; // x0
  _QWORD *v15; // x0
  _QWORD *v16; // x0
  _QWORD *v17; // x0
  _QWORD *v18; // x0
  _QWORD *v19; // x0
  _QWORD *v20; // x0
  _QWORD *v21; // x0
  _QWORD **v22; // x8
  _QWORD *v23; // x0
  _QWORD *v24; // x0
  _QWORD *v25; // x0
  _QWORD *v26; // x0
  _QWORD *v27; // x0
  _QWORD *v28; // x0
  _QWORD *v29; // x0
  _QWORD *v30; // x0
  _QWORD *v31; // x0
  _QWORD *v32; // x21
  _QWORD *v33; // x0
  _QWORD *v34; // x0
  _QWORD *v35; // x0
  _QWORD *v36; // x0
  _QWORD *v37; // x0
  _QWORD *v38; // x0
  _QWORD *v39; // x0
  _QWORD *v40; // x0
  __int64 i; // x23
  __int64 v42; // x26
  int *v43; // x27
  _QWORD *v44; // x19
  int v45; // w28
  int v46; // w22
  _QWORD *v47; // x25
  _QWORD *v48; // x0
  _QWORD *v49; // x25
  _QWORD *v50; // t1
  _QWORD *v51; // x19
  int v52; // w27
  int j; // w22
  _QWORD *v54; // x25
  _QWORD *v55; // x0
  _QWORD *v56; // x25
  _QWORD *v57; // t1

  v1 = (_QWORD **)result[62];
  v2 = result;
  if ( v1 )
  {
    v3 = *v1;
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v3, 0);
    else
      kvfree(v3);
    *(_QWORD *)v2[62] = 0;
    v4 = *(_QWORD **)(v2[62] + 8LL);
    if ( (mem_trace_en & 1) != 0 )
      cam_mem_trace_free(v4, 0);
    else
      kvfree(v4);
    *(_QWORD *)(v2[62] + 8LL) = 0;
    v5 = *(_QWORD **)(v2[62] + 16LL);
    if ( (mem_trace_en & 1) != 0 )
      cam_mem_trace_free(v5, 0);
    else
      kvfree(v5);
    *(_QWORD *)(v2[62] + 16LL) = 0;
    v6 = *(_QWORD **)(v2[62] + 24LL);
    if ( (mem_trace_en & 1) != 0 )
      cam_mem_trace_free(v6, 0);
    else
      kvfree(v6);
    *(_QWORD *)(v2[62] + 24LL) = 0;
    v7 = *(_QWORD **)(v2[62] + 32LL);
    if ( (mem_trace_en & 1) != 0 )
      cam_mem_trace_free(v7, 0);
    else
      kvfree(v7);
    *(_QWORD *)(v2[62] + 32LL) = 0;
    v8 = *(_QWORD **)(v2[62] + 40LL);
    if ( (mem_trace_en & 1) != 0 )
      cam_mem_trace_free(v8, 0);
    else
      kvfree(v8);
    *(_QWORD *)(v2[62] + 40LL) = 0;
    v9 = *(_QWORD **)(v2[62] + 48LL);
    if ( (mem_trace_en & 1) != 0 )
      cam_mem_trace_free(v9, 0);
    else
      kvfree(v9);
    *(_QWORD *)(v2[62] + 48LL) = 0;
    v10 = *(_QWORD **)(v2[62] + 56LL);
    if ( (mem_trace_en & 1) != 0 )
      cam_mem_trace_free(v10, 0);
    else
      kvfree(v10);
    *(_QWORD *)(v2[62] + 56LL) = 0;
    v11 = (_QWORD *)v2[62];
    if ( mem_trace_en == 1 )
      result = cam_mem_trace_free(v11, 0);
    else
      result = (_QWORD *)kvfree(v11);
    v2[62] = 0;
  }
  v12 = (_QWORD **)v2[61];
  if ( v12 )
  {
    v13 = *v12;
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v13, 0);
    else
      kvfree(v13);
    *(_QWORD *)v2[61] = 0;
    v14 = *(_QWORD **)(v2[61] + 8LL);
    if ( (mem_trace_en & 1) != 0 )
      cam_mem_trace_free(v14, 0);
    else
      kvfree(v14);
    *(_QWORD *)(v2[61] + 8LL) = 0;
    v15 = *(_QWORD **)(v2[61] + 16LL);
    if ( (mem_trace_en & 1) != 0 )
      cam_mem_trace_free(v15, 0);
    else
      kvfree(v15);
    *(_QWORD *)(v2[61] + 16LL) = 0;
    v16 = *(_QWORD **)(v2[61] + 24LL);
    if ( (mem_trace_en & 1) != 0 )
      cam_mem_trace_free(v16, 0);
    else
      kvfree(v16);
    *(_QWORD *)(v2[61] + 24LL) = 0;
    v17 = *(_QWORD **)(v2[61] + 32LL);
    if ( (mem_trace_en & 1) != 0 )
      cam_mem_trace_free(v17, 0);
    else
      kvfree(v17);
    *(_QWORD *)(v2[61] + 32LL) = 0;
    v18 = *(_QWORD **)(v2[61] + 40LL);
    if ( (mem_trace_en & 1) != 0 )
      cam_mem_trace_free(v18, 0);
    else
      kvfree(v18);
    *(_QWORD *)(v2[61] + 40LL) = 0;
    v19 = *(_QWORD **)(v2[61] + 48LL);
    if ( (mem_trace_en & 1) != 0 )
      cam_mem_trace_free(v19, 0);
    else
      kvfree(v19);
    *(_QWORD *)(v2[61] + 48LL) = 0;
    v20 = *(_QWORD **)(v2[61] + 56LL);
    if ( (mem_trace_en & 1) != 0 )
      cam_mem_trace_free(v20, 0);
    else
      kvfree(v20);
    *(_QWORD *)(v2[61] + 56LL) = 0;
    v21 = (_QWORD *)v2[61];
    if ( mem_trace_en == 1 )
      result = cam_mem_trace_free(v21, 0);
    else
      result = (_QWORD *)kvfree(v21);
    v2[61] = 0;
  }
  v22 = (_QWORD **)v2[60];
  if ( v22 )
  {
    v23 = *v22;
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v23, 0);
    else
      kvfree(v23);
    *(_QWORD *)v2[60] = 0;
    v24 = *(_QWORD **)(v2[60] + 8LL);
    if ( (mem_trace_en & 1) != 0 )
      cam_mem_trace_free(v24, 0);
    else
      kvfree(v24);
    *(_QWORD *)(v2[60] + 8LL) = 0;
    v25 = *(_QWORD **)(v2[60] + 16LL);
    if ( (mem_trace_en & 1) != 0 )
      cam_mem_trace_free(v25, 0);
    else
      kvfree(v25);
    *(_QWORD *)(v2[60] + 16LL) = 0;
    v26 = *(_QWORD **)(v2[60] + 24LL);
    if ( (mem_trace_en & 1) != 0 )
      cam_mem_trace_free(v26, 0);
    else
      kvfree(v26);
    *(_QWORD *)(v2[60] + 24LL) = 0;
    v27 = *(_QWORD **)(v2[60] + 32LL);
    if ( (mem_trace_en & 1) != 0 )
      cam_mem_trace_free(v27, 0);
    else
      kvfree(v27);
    *(_QWORD *)(v2[60] + 32LL) = 0;
    v28 = *(_QWORD **)(v2[60] + 40LL);
    if ( (mem_trace_en & 1) != 0 )
      cam_mem_trace_free(v28, 0);
    else
      kvfree(v28);
    *(_QWORD *)(v2[60] + 40LL) = 0;
    v29 = *(_QWORD **)(v2[60] + 48LL);
    if ( (mem_trace_en & 1) != 0 )
      cam_mem_trace_free(v29, 0);
    else
      kvfree(v29);
    *(_QWORD *)(v2[60] + 48LL) = 0;
    v30 = *(_QWORD **)(v2[60] + 56LL);
    if ( (mem_trace_en & 1) != 0 )
      cam_mem_trace_free(v30, 0);
    else
      kvfree(v30);
    *(_QWORD *)(v2[60] + 56LL) = 0;
    v31 = (_QWORD *)v2[60];
    if ( mem_trace_en == 1 )
      result = cam_mem_trace_free(v31, 0);
    else
      result = (_QWORD *)kvfree(v31);
    v2[60] = 0;
  }
  v32 = (_QWORD *)v2[32];
  if ( v32 )
  {
    v33 = (_QWORD *)v32[158];
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v33, 0);
    else
      kvfree(v33);
    v32[158] = 0;
    v34 = (_QWORD *)v32[722];
    if ( (mem_trace_en & 1) != 0 )
      cam_mem_trace_free(v34, 0);
    else
      kvfree(v34);
    v32[722] = 0;
    v35 = (_QWORD *)v32[1286];
    if ( (mem_trace_en & 1) != 0 )
      cam_mem_trace_free(v35, 0);
    else
      kvfree(v35);
    v32[1286] = 0;
    v36 = (_QWORD *)v32[1850];
    if ( (mem_trace_en & 1) != 0 )
      cam_mem_trace_free(v36, 0);
    else
      kvfree(v36);
    v32[1850] = 0;
    v37 = (_QWORD *)v32[2414];
    if ( (mem_trace_en & 1) != 0 )
      cam_mem_trace_free(v37, 0);
    else
      kvfree(v37);
    v32[2414] = 0;
    v38 = (_QWORD *)v32[2978];
    if ( (mem_trace_en & 1) != 0 )
      cam_mem_trace_free(v38, 0);
    else
      kvfree(v38);
    v32[2978] = 0;
    v39 = (_QWORD *)v32[3542];
    if ( (mem_trace_en & 1) != 0 )
      cam_mem_trace_free(v39, 0);
    else
      kvfree(v39);
    v32[3542] = 0;
    v40 = (_QWORD *)v32[4106];
    if ( (mem_trace_en & 1) != 0 )
      result = cam_mem_trace_free(v40, 0);
    else
      result = (_QWORD *)kvfree(v40);
    v32[4106] = 0;
    *((_DWORD *)v2 + 119) = 0;
    *(_QWORD *)((char *)v2 + 468) = 0;
    if ( v32[5713] )
    {
      for ( i = 0; i != 8; ++i )
      {
        v42 = (__int64)&v32[564 * i + 150];
        v43 = (int *)v32[5713];
        v44 = *(_QWORD **)(v42 + 4432);
        if ( v44 )
        {
          v45 = *v43;
          if ( *v43 )
          {
            v46 = 0;
            do
            {
              v47 = &v44[2 * v46];
              v50 = (_QWORD *)v47[1];
              v49 = v47 + 1;
              v48 = v50;
              if ( mem_trace_en == 1 )
                cam_mem_trace_free(v48, 0);
              else
                kvfree(v48);
              ++v46;
              *v49 = 0;
            }
            while ( v45 != v46 );
            v44 = *(_QWORD **)(v42 + 4432);
          }
          if ( mem_trace_en == 1 )
            result = cam_mem_trace_free(v44, 0);
          else
            result = (_QWORD *)kvfree(v44);
          *(_QWORD *)(v42 + 4432) = 0;
        }
        v51 = *(_QWORD **)(v42 + 4400);
        if ( v51 )
        {
          v52 = v43[1];
          if ( v52 )
          {
            for ( j = 0; j != v52; ++j )
            {
              v54 = &v51[2 * j];
              v57 = (_QWORD *)v54[1];
              v56 = v54 + 1;
              v55 = v57;
              if ( mem_trace_en == 1 )
                cam_mem_trace_free(v55, 0);
              else
                kvfree(v55);
              *v56 = 0;
            }
            v51 = *(_QWORD **)(v42 + 4400);
          }
          if ( mem_trace_en == 1 )
            result = cam_mem_trace_free(v51, 0);
          else
            result = (_QWORD *)kvfree(v51);
          *(_QWORD *)(v42 + 4400) = 0;
        }
      }
    }
  }
  else
  {
    *((_DWORD *)v2 + 119) = 0;
    *(_QWORD *)((char *)v2 + 468) = 0;
  }
  return result;
}
