__int64 __fastcall show_max_low_power_cluster_freqs(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x21
  int v6; // w3
  int v7; // w3
  int v8; // w3
  int v9; // w3
  int v10; // w0
  int v11; // w3
  int v12; // w0
  int v13; // w3
  int v14; // w0
  int v15; // w3

  LODWORD(v5) = scnprintf(a3, 4096, "%u ", *(_DWORD *)(a1 - 276));
  v6 = *(_DWORD *)(a1 - 272);
  if ( v6 )
  {
    v5 = (unsigned int)scnprintf(a3 + (unsigned int)v5, 4096LL - (unsigned int)v5, "%u ", v6) + (unsigned int)v5;
    v7 = *(_DWORD *)(a1 - 268);
    if ( v7 )
    {
      v5 = (unsigned int)scnprintf(a3 + v5, 4096 - v5, "%u ", v7) + (unsigned int)v5;
      v8 = *(_DWORD *)(a1 - 264);
      if ( v8 )
      {
        v5 = (unsigned int)scnprintf(a3 + v5, 4096 - v5, "%u ", v8) + (unsigned int)v5;
        v9 = *(_DWORD *)(a1 - 260);
        if ( v9 )
        {
          v10 = scnprintf(a3 + v5, 4096 - v5, "%u ", v9);
          v11 = *(_DWORD *)(a1 - 256);
          v5 = (unsigned int)(v10 + v5);
          if ( v11 )
          {
            v12 = scnprintf(a3 + v5, 4096 - v5, "%u ", v11);
            v13 = *(_DWORD *)(a1 - 252);
            v5 = (unsigned int)(v12 + v5);
            if ( v13 )
            {
              v14 = scnprintf(a3 + v5, 4096 - v5, "%u ", v13);
              v15 = *(_DWORD *)(a1 - 248);
              v5 = (unsigned int)(v14 + v5);
              if ( v15 )
                LODWORD(v5) = scnprintf(a3 + v5, 4096 - v5, "%u ", v15) + v5;
            }
          }
        }
      }
    }
  }
  return (unsigned int)scnprintf(a3 + (unsigned int)v5, 4096LL - (unsigned int)v5, "\n") + (unsigned int)v5;
}
