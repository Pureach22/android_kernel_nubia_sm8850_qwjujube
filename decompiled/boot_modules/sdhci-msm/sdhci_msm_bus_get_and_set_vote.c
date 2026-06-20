__int64 __fastcall sdhci_msm_bus_get_and_set_vote(__int64 result, unsigned int a2)
{
  __int64 v2; // x19
  __int64 v3; // x8
  int v4; // w9
  int v5; // w20
  __int64 v6; // x21
  unsigned int *v7; // x23
  _BOOL4 v8; // w22
  _BOOL4 v9; // w8
  __int64 v10; // x8
  __int64 v11; // x1

  v2 = *(_QWORD *)(result + 1648);
  if ( v2 )
  {
    v3 = result;
    result = *(_QWORD *)(v2 + 40);
    if ( result || *(_QWORD *)(v2 + 48) )
    {
      v4 = *(_DWORD *)(v2 + 32);
      if ( v4 )
      {
        v5 = 0;
        while ( *(_DWORD *)(*(_QWORD *)(v2 + 24) + 4LL * v5) < a2 )
        {
          if ( v4 == ++v5 )
          {
            v5 = v4 - 1;
            break;
          }
        }
      }
      else
      {
        v5 = -1;
      }
      if ( *(_DWORD *)(v2 + 56) != v5 )
      {
        v6 = *(_QWORD *)(*(_QWORD *)(v3 + 1408) + 168LL);
        v7 = *(unsigned int **)(*(_QWORD *)(v2 + 16) + 16LL * v5 + 8);
        if ( result )
        {
          v8 = icc_set_bw(result, *v7, v7[2]) != 0;
          result = *(_QWORD *)(v2 + 48);
          if ( result )
          {
LABEL_13:
            result = icc_set_bw(result, v7[4], v7[6]);
            v9 = result != 0;
            goto LABEL_16;
          }
        }
        else
        {
          v8 = 0;
          result = *(_QWORD *)(v2 + 48);
          if ( result )
            goto LABEL_13;
        }
        v9 = 0;
LABEL_16:
        if ( v8 || v9 )
        {
          v10 = *(_QWORD *)(v6 + 72);
          v11 = *(_QWORD *)(v10 + 120);
          if ( !v11 )
            v11 = *(_QWORD *)(v10 + 8);
          return printk(&unk_10407, v11);
        }
        else
        {
          *(_DWORD *)(v2 + 56) = v5;
        }
      }
    }
  }
  return result;
}
