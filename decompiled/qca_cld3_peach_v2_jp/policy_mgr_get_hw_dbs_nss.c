__int64 __fastcall policy_mgr_get_hw_dbs_nss(__int64 a1, int *a2)
{
  __int64 context; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned int v12; // w8
  unsigned int v13; // w9
  unsigned int v14; // w10
  __int64 v15; // x13
  unsigned int v16; // w16
  unsigned int v17; // w17
  unsigned int v18; // w13
  unsigned int v19; // w14
  unsigned int v20; // w15
  int v21; // w13
  int v22; // w14

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    a2[2] = 0;
    v12 = *(_DWORD *)(context + 1184);
    if ( v12 )
    {
      v13 = 0;
      v12 = 0;
      v14 = 0;
      do
      {
        v15 = *(_QWORD *)(*(_QWORD *)(context + 1192) + 8LL * (int)v14);
        if ( !(v15 & 0xA0 | v13) )
        {
          v13 = ((unsigned int)v15 >> 3) & 3;
          a2[2] = v13;
        }
        if ( (v15 & 0x80) != 0 )
        {
          v16 = ((unsigned int)v15 >> 20) & 0xF;
          v17 = WORD1(v15) & 0xF;
          v18 = (int)v15 >> 28 >= (unsigned int)(BYTE3(v15) & 0xF) ? BYTE3(v15) & 0xF : (int)v15 >> 28;
          v19 = v16 >= v17 ? v17 : v16;
          v20 = v18 <= v19 ? v19 : v18;
          if ( v12 < v20 )
          {
            if ( v20 == 2 )
              v12 = 2;
            else
              v12 = 1;
            if ( v18 == 2 )
              v21 = 2;
            else
              v21 = 1;
            if ( v19 == 2 )
              v22 = 2;
            else
              v22 = 1;
            *a2 = v21;
            a2[1] = v22;
          }
        }
        ++v14;
      }
      while ( v14 < *(_DWORD *)(context + 1184) );
    }
  }
  else
  {
    qdf_trace_msg(0x4Fu, 2u, "%s: Invalid Context", v4, v5, v6, v7, v8, v9, v10, v11, "policy_mgr_get_hw_dbs_nss");
    return 0;
  }
  return v12;
}
