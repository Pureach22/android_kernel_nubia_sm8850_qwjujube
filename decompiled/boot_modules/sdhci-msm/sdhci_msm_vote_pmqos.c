__int64 __fastcall sdhci_msm_vote_pmqos(__int64 result, unsigned int a2)
{
  __int64 *v2; // x20
  __int64 v4; // x21
  int v5; // w9
  int v6; // w8
  __int64 *v7; // x11
  __int64 v8; // t1
  __int64 v9; // x21
  unsigned int v10; // w19
  __int64 v11; // x8
  __int64 v12; // x20
  char v13; // w8
  __int64 v14; // x8
  unsigned __int64 v15; // x23
  unsigned __int64 v16; // x8
  bool v17; // cf

  if ( (a2 & 0x80000000) == 0 )
  {
    v2 = *(__int64 **)(result + 3664);
    v4 = *v2;
    result = _sw_hweight64(_cpu_possible_mask);
    if ( (unsigned int)result >= a2 )
    {
      v5 = *((_DWORD *)v2 + 2);
      if ( v5 )
      {
        v6 = 0;
        v7 = (__int64 *)(v4 + (((unsigned __int64)a2 >> 3) & 0x1FFFFFF8));
        while ( 1 )
        {
          v8 = *v7;
          v7 += 6;
          if ( (v8 & (1LL << a2)) != 0 )
            break;
          if ( v5 == ++v6 )
            return result;
        }
        v9 = *v2 + 48LL * v6;
        if ( v9 )
        {
          if ( (*(_BYTE *)(v9 + 24) & 1) == 0 )
          {
            v10 = **(_DWORD **)(v9 + 8);
            if ( v10 != *(unsigned __int8 *)(v9 + 41) )
            {
              v11 = *(_QWORD *)(v9 + 32);
              v12 = *(_QWORD *)(v9 + 16);
              result = *(_QWORD *)(v11 + 752);
              if ( result )
              {
                if ( *(_BYTE *)(v11 + 760) == 1 )
                  result = ipc_log_string(
                             result,
                             "%s: mask: 0x%lx type: %d vote: %u\n",
                             "sdhci_msm_update_qos_constraints",
                             *(_QWORD *)v9,
                             0,
                             v10);
              }
              v13 = 0;
              while ( 1 )
              {
                v14 = -1LL << v13;
                v15 = (unsigned int)v14 & *(_DWORD *)v9;
                if ( ((unsigned int)v14 & *(_DWORD *)v9) == 0 )
                {
LABEL_19:
                  *(_BYTE *)(v9 + 24) = 1;
                  *(_BYTE *)(v9 + 41) = v10 != 0;
                  return result;
                }
                result = dev_pm_qos_update_request(v12, v10);
                if ( (result & 0x80000000) != 0 )
                  return dev_err(**(_QWORD **)(v9 + 32) + 16LL, "%s: update qos - failed\n", "sdhci_msm_vote_pmqos");
                v12 += 80;
                v16 = __clz(__rbit64(v15));
                v17 = v16 >= 0x1F;
                v13 = v16 + 1;
                if ( v17 )
                  goto LABEL_19;
              }
            }
          }
        }
      }
    }
  }
  return result;
}
