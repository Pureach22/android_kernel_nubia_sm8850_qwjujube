__int64 __fastcall ipa_pm_exceptions_stat(__int64 a1, unsigned int a2)
{
  int v2; // w26
  __int64 v5; // x0
  __int64 v6; // x22
  __int64 v7; // x21
  __int64 v8; // x28
  __int64 v9; // x0
  __int64 v10; // x1

  v2 = -22;
  if ( !a1 || (a2 & 0x80000000) != 0 )
    return (unsigned int)v2;
  v2 = scnprintf(a1, a2, "\n");
  v5 = mutex_lock(ipa_pm_ctx + 1152);
  v6 = ipa_pm_ctx;
  if ( *(int *)(ipa_pm_ctx + 1116) < 1 )
  {
LABEL_17:
    mutex_unlock(v6 + 1152);
    return (unsigned int)v2;
  }
  v7 = 0;
  v8 = 680;
  while ( v8 != 1256 )
  {
    v9 = a1 + v2;
    v10 = (int)(a2 - v2);
    if ( v6 + v8 == 92 )
    {
      v5 = scnprintf(v9, v10, "Exception %d is NULL\n\n", v7);
    }
    else
    {
      v2 += scnprintf(
              v9,
              v10,
              "Exception %d: %s\nPending: %d Bitmask: %X %X Threshold: [",
              v7,
              (const char *)(v6 + v8 - 92),
              *(_DWORD *)(v6 + v8 - 28),
              *(_DWORD *)(v6 + v8 - 24),
              *(_DWORD *)(v6 + v8 - 20));
      if ( *(int *)(ipa_pm_ctx + 1112) >= 1 )
      {
        v2 += scnprintf(a1 + v2, (int)(a2 - v2), "%d, ", *(_DWORD *)(v6 + v8 - 16));
        if ( *(int *)(ipa_pm_ctx + 1112) >= 2 )
        {
          v2 += scnprintf(a1 + v2, (int)(a2 - v2), "%d, ", *(_DWORD *)(v6 + v8 - 12));
          if ( *(int *)(ipa_pm_ctx + 1112) >= 3 )
          {
            v2 += scnprintf(a1 + v2, (int)(a2 - v2), "%d, ", *(_DWORD *)(v6 + v8 - 8));
            if ( *(int *)(ipa_pm_ctx + 1112) >= 4 )
            {
              v2 += scnprintf(a1 + v2, (int)(a2 - v2), "%d, ", *(_DWORD *)(v6 + v8 - 4));
              if ( *(int *)(ipa_pm_ctx + 1112) >= 5 )
              {
                v5 = scnprintf(a1 + v2, (int)(a2 - v2), "%d, ", *(_DWORD *)(v6 + v8));
                if ( *(int *)(ipa_pm_ctx + 1112) > 5 )
                  break;
                v2 += v5;
              }
            }
          }
        }
      }
      v5 = scnprintf(a1 + v2, (int)(a2 - v2), "\b\b]\n\n");
    }
    v6 = ipa_pm_ctx;
    ++v7;
    v2 += v5;
    v8 += 96;
    if ( v7 >= *(int *)(ipa_pm_ctx + 1116) )
      goto LABEL_17;
  }
  __break(0x5512u);
  return ipa_pm_get_scaling_bw_levels(v5);
}
