__int64 __fastcall dp_get_peer_param(int a1, int a2, int a3, int a4, _WORD *a5)
{
  __int64 v7; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x8
  __int64 v17; // x9
  unsigned int v18; // w19
  __int64 v19; // x20

  v7 = dp_peer_find_hash_find(a1, a3);
  if ( v7 )
  {
    v16 = *(_QWORD *)v7;
    if ( !*(_QWORD *)v7 )
    {
      v18 = 16;
LABEL_11:
      dp_peer_unref_delete(v7, 7u, v8, v9, v10, v11, v12, v13, v14, v15);
      return v18;
    }
    if ( a4 == 7 )
    {
      v17 = 16;
    }
    else
    {
      if ( a4 != 8 )
      {
LABEL_10:
        v18 = 0;
        goto LABEL_11;
      }
      v17 = 32;
    }
    v19 = v7;
    *a5 = *(_WORD *)(v7 + 16);
    qdf_mem_copy(a5 + 4, (const void *)(v16 + v17), 0x10u);
    v7 = v19;
    goto LABEL_10;
  }
  return 4;
}
