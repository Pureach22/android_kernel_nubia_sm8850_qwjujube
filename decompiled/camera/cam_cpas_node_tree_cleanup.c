__int64 __fastcall cam_cpas_node_tree_cleanup(__int64 a1, _QWORD *a2)
{
  __int64 v3; // x20
  _QWORD *v4; // x22
  __int64 v5; // x8
  _QWORD *v6; // x0
  _QWORD *v7; // x0
  int v8; // w9
  _QWORD *v9; // x0

  v3 = 0;
  v4 = a2 + 45;
  do
  {
    v5 = v4[v3];
    if ( v5 )
    {
      v6 = *(_QWORD **)(v5 + 48);
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v6, 0);
      else
        kvfree(v6);
      v7 = *(_QWORD **)(v4[v3] + 8LL);
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v7, 0);
      else
        kvfree(v7);
      v8 = (unsigned __int8)mem_trace_en;
      *(_QWORD *)(v4[v3] + 48LL) = 0;
      *(_QWORD *)(v4[v3] + 8LL) = 0;
      v9 = (_QWORD *)v4[v3];
      if ( v8 == 1 )
        cam_mem_trace_free(v9, 0);
      else
        kvfree(v9);
      v4[v3] = 0;
    }
    ++v3;
  }
  while ( v3 != 63 );
  if ( a2[109] )
    a2[109] = 0;
  if ( a2[110] )
    a2[110] = 0;
  if ( a2[111] )
    a2[111] = 0;
  if ( a2[112] )
    a2[112] = 0;
  if ( a2[108] )
    a2[108] = 0;
  return 0;
}
