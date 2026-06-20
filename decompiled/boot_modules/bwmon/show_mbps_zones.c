__int64 __fastcall show_mbps_zones(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v5; // w0
  int v6; // w3
  __int64 v7; // x21
  int v8; // w0
  int v9; // w3
  int v10; // w0
  int v11; // w3
  int v12; // w0
  int v13; // w3
  int v14; // w0
  int v15; // w3
  int v16; // w0
  int v17; // w3
  int v18; // w0
  int v19; // w3
  int v20; // w0
  int v21; // w3
  int v22; // w0
  int v23; // w3

  v5 = scnprintf(a3, 4096, "%u ", *(_DWORD *)(a1 - 188));
  v6 = *(_DWORD *)(a1 - 184);
  LODWORD(v7) = v5;
  if ( v6 )
  {
    v8 = scnprintf(a3 + v5, 4096LL - v5, "%u ", v6);
    v9 = *(_DWORD *)(a1 - 180);
    v7 = (unsigned int)(v8 + v7);
    if ( v9 )
    {
      v10 = scnprintf(a3 + v7, 4096 - v7, "%u ", v9);
      v11 = *(_DWORD *)(a1 - 176);
      v7 = (unsigned int)(v10 + v7);
      if ( v11 )
      {
        v12 = scnprintf(a3 + v7, 4096 - v7, "%u ", v11);
        v13 = *(_DWORD *)(a1 - 172);
        v7 = (unsigned int)(v12 + v7);
        if ( v13 )
        {
          v14 = scnprintf(a3 + v7, 4096 - v7, "%u ", v13);
          v15 = *(_DWORD *)(a1 - 168);
          v7 = (unsigned int)(v14 + v7);
          if ( v15 )
          {
            v16 = scnprintf(a3 + v7, 4096 - v7, "%u ", v15);
            v17 = *(_DWORD *)(a1 - 164);
            v7 = (unsigned int)(v16 + v7);
            if ( v17 )
            {
              v18 = scnprintf(a3 + v7, 4096 - v7, "%u ", v17);
              v19 = *(_DWORD *)(a1 - 160);
              v7 = (unsigned int)(v18 + v7);
              if ( v19 )
              {
                v20 = scnprintf(a3 + v7, 4096 - v7, "%u ", v19);
                v21 = *(_DWORD *)(a1 - 156);
                v7 = (unsigned int)(v20 + v7);
                if ( v21 )
                {
                  v22 = scnprintf(a3 + v7, 4096 - v7, "%u ", v21);
                  v23 = *(_DWORD *)(a1 - 152);
                  v7 = (unsigned int)(v22 + v7);
                  if ( v23 )
                    LODWORD(v7) = scnprintf(a3 + v7, 4096 - v7, "%u ", v23) + v7;
                }
              }
            }
          }
        }
      }
    }
  }
  return (unsigned int)scnprintf(a3 + (unsigned int)v7, 4096LL - (unsigned int)v7, "\n") + (unsigned int)v7;
}
