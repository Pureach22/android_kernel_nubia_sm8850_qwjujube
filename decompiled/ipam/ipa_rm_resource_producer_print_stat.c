__int64 __fastcall ipa_rm_resource_producer_print_stat(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 result; // x0
  const char *v7; // x0
  int v8; // w22
  int v9; // w0
  __int64 v10; // x8
  int v11; // w22
  int v12; // w0
  __int64 v13; // x1
  int v14; // w27
  signed int i; // w22
  unsigned int *resource; // x0
  unsigned int *v17; // x28
  const char *v18; // x0
  int v19; // w24
  int v20; // w0
  __int64 v21; // x8

  result = 4294967274LL;
  if ( a2 && (a3 & 0x80000000) == 0 )
  {
    v7 = ipa_rm_resource_str(*(_DWORD *)a1);
    v8 = scnprintf(a2, a3, v7);
    v9 = scnprintf(a2 + v8, (int)(a3 - v8), "[%d, ", *(_DWORD *)(a1 + 12));
    v10 = *(unsigned int *)(a1 + 20);
    if ( (unsigned int)v10 > 3 )
    {
      return 0xFFFFFFFFLL;
    }
    else
    {
      v11 = v9 + v8;
      v12 = scnprintf(a2 + v11, (int)(a3 - v11), off_1F6058[v10]);
      v13 = *(_QWORD *)(a1 + 24);
      v14 = v12 + v11;
      if ( *(int *)(v13 + 8) >= 1 )
      {
        for ( i = 0; i < *(_DWORD *)(v13 + 8); ++i )
        {
          resource = (unsigned int *)ipa_rm_peers_list_get_resource(i, v13);
          if ( resource )
          {
            v17 = resource;
            v18 = ipa_rm_resource_str(*resource);
            v19 = scnprintf(a2 + v14, (int)(a3 - v14), v18) + v14;
            v20 = scnprintf(a2 + v19, (int)(a3 - v19), "[%d, ", v17[3]);
            v21 = v17[5];
            if ( (unsigned int)v21 > 3 )
              return 0xFFFFFFFFLL;
            v14 = scnprintf(a2 + v20 + v19, (int)(a3 - (v20 + v19)), off_1F6078[v21]) + v20 + v19;
          }
          v13 = *(_QWORD *)(a1 + 24);
        }
      }
      return (unsigned int)scnprintf(a2 + v14, (int)(a3 - v14), "\n") + v14;
    }
  }
  return result;
}
