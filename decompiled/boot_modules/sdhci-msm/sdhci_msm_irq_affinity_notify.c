__int64 __fastcall sdhci_msm_irq_affinity_notify(__int64 result, _DWORD *a2)
{
  __int64 *v2; // x25
  __int64 v3; // x19
  __int64 v4; // x10
  int v5; // w9
  int v6; // w8
  __int64 v7; // x26
  unsigned int v8; // w20
  __int64 v9; // x8
  __int64 v10; // x24
  __int64 v11; // x0
  char v12; // w8
  __int64 v13; // x8
  unsigned __int64 v14; // x27
  unsigned __int64 v15; // x8
  bool v16; // cf
  __int64 v17; // x1
  __int64 v18; // [xsp+8h] [xbp-8h]

  v2 = *(__int64 **)(result - 8);
  if ( v2 )
  {
    v3 = result;
    v4 = *(_QWORD *)(result - 472);
    v5 = __clz(__rbit64((unsigned int)*a2));
    v6 = *a2 ? v5 : 32;
    *((_DWORD *)v2 + 3) = v6;
    if ( *(_DWORD *)(v4 + 516) != 2 )
    {
      if ( *((_DWORD *)v2 + 2) )
      {
        v7 = *v2;
        v8 = 0;
        v18 = result - 344;
        do
        {
          v9 = *(_QWORD *)(v7 + 32);
          v10 = *(_QWORD *)(v7 + 16);
          v11 = *(_QWORD *)(v9 + 752);
          if ( v11 && *(_BYTE *)(v9 + 760) == 1 )
            ipc_log_string(
              v11,
              "%s: mask: 0x%lx type: %d vote: %u\n",
              "sdhci_msm_update_qos_constraints",
              *(_QWORD *)v7,
              2,
              0x7FFFFFFF);
          v12 = 0;
          while ( 1 )
          {
            v13 = -1LL << v12;
            v14 = (unsigned int)v13 & *(_DWORD *)v7;
            if ( ((unsigned int)v13 & *(_DWORD *)v7) == 0 )
            {
LABEL_16:
              *(_BYTE *)(v7 + 24) = 0;
              *(_BYTE *)(v7 + 41) = 1;
              goto LABEL_17;
            }
            if ( (dev_pm_qos_update_request(v10, 0x7FFFFFFF) & 0x80000000) != 0 )
              break;
            v10 += 80;
            v15 = __clz(__rbit64(v14));
            v16 = v15 >= 0x1F;
            v12 = v15 + 1;
            if ( v16 )
              goto LABEL_16;
          }
          v17 = *(_QWORD *)(*(_QWORD *)v18 + 120LL);
          if ( !v17 )
            v17 = *(_QWORD *)(*(_QWORD *)v18 + 8LL);
          printk(&unk_10F90, v17);
LABEL_17:
          ++v8;
          v7 += 48;
        }
        while ( v8 < *((_DWORD *)v2 + 2) );
      }
      return sdhci_msm_vote_pmqos(*(_QWORD *)(v3 - 344), *(unsigned int *)(*(_QWORD *)(v3 - 8) + 12LL));
    }
  }
  return result;
}
