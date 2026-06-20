_QWORD *__fastcall cam_ife_csid_ver2_free_res(_QWORD *a1)
{
  _QWORD *v1; // x19
  __int64 v2; // x21
  __int64 v3; // x8
  int v4; // w22
  _QWORD *v5; // x0
  _QWORD *v6; // x0
  _QWORD *v7; // x0
  _QWORD *v8; // x0
  _QWORD *v9; // x0
  _QWORD *v10; // x0
  unsigned int v11; // w8
  unsigned __int64 v12; // x21
  _QWORD *v13; // x23
  __int64 v14; // x22
  _QWORD *v15; // x0
  _QWORD *v16; // x0
  _QWORD *v17; // x0
  _QWORD *v18; // x0
  _QWORD *v19; // x0
  _QWORD *result; // x0

  v1 = a1;
  v2 = *(_QWORD *)a1[3892];
  v3 = *(_QWORD *)(v2 + 120);
  v4 = *(_DWORD *)(v3 + 496);
  if ( v4 )
  {
    v5 = (_QWORD *)a1[136];
    if ( (mem_trace_en & 1) != 0 )
      a1 = cam_mem_trace_free(v5, 0);
    else
      a1 = (_QWORD *)kvfree(v5);
    v1[136] = 0;
    if ( v4 != 1 )
    {
      v6 = (_QWORD *)v1[155];
      a1 = (mem_trace_en & 1) != 0 ? cam_mem_trace_free(v6, 0) : (_QWORD *)kvfree(v6);
      v1[155] = 0;
      if ( v4 != 2 )
      {
        v7 = (_QWORD *)v1[174];
        a1 = (mem_trace_en & 1) != 0 ? cam_mem_trace_free(v7, 0) : (_QWORD *)kvfree(v7);
        v1[174] = 0;
        if ( v4 != 3 )
        {
          v8 = (_QWORD *)v1[193];
          a1 = (mem_trace_en & 1) != 0 ? cam_mem_trace_free(v8, 0) : (_QWORD *)kvfree(v8);
          v1[193] = 0;
          if ( v4 != 4 )
          {
            v9 = (_QWORD *)v1[212];
            a1 = (mem_trace_en & 1) != 0 ? cam_mem_trace_free(v9, 0) : (_QWORD *)kvfree(v9);
            v1[212] = 0;
            if ( v4 != 5 )
            {
              v10 = (_QWORD *)v1[231];
              a1 = (mem_trace_en & 1) != 0 ? cam_mem_trace_free(v10, 0) : (_QWORD *)kvfree(v10);
              v1[231] = 0;
              if ( v4 != 6 )
              {
LABEL_47:
                __break(0x5512u);
                return (_QWORD *)cam_ife_csid_ver2_reset_irq_top_half(a1);
              }
            }
          }
        }
      }
    }
    v3 = *(_QWORD *)(v2 + 120);
  }
  v11 = *(_DWORD *)(v3 + 500);
  if ( v11 )
  {
    v12 = 0;
    v13 = v1 + 3;
    v14 = 152LL * v11;
    while ( v12 != 1976 )
    {
      v15 = (_QWORD *)v13[v12 / 8];
      if ( mem_trace_en == 1 )
        a1 = cam_mem_trace_free(v15, 0);
      else
        a1 = (_QWORD *)kvfree(v15);
      v13[v12 / 8] = 0;
      v12 += 152LL;
      if ( v14 == v12 )
        goto LABEL_34;
    }
    goto LABEL_47;
  }
LABEL_34:
  v16 = (_QWORD *)v1[98];
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v16, 0);
  else
    kvfree(v16);
  v1[98] = 0;
  v17 = (_QWORD *)v1[193];
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v17, 0);
  else
    kvfree(v17);
  v1[193] = 0;
  v18 = (_QWORD *)v1[212];
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v18, 0);
  else
    kvfree(v18);
  v1[212] = 0;
  v19 = (_QWORD *)v1[117];
  if ( mem_trace_en == 1 )
    result = cam_mem_trace_free(v19, 0);
  else
    result = (_QWORD *)kvfree(v19);
  v1[117] = 0;
  return result;
}
