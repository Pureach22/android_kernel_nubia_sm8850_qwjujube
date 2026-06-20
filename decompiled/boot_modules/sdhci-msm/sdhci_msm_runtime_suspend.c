__int64 __fastcall sdhci_msm_runtime_suspend(__int64 a1)
{
  __int64 v1; // x24
  __int64 v2; // x19
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 *v5; // x25
  __int64 v6; // x26
  unsigned int v7; // w19
  __int64 v8; // x8
  __int64 v9; // x23
  __int64 v10; // x0
  char v11; // w8
  __int64 v12; // x8
  unsigned __int64 v13; // x20
  int updated; // w0
  unsigned __int64 v15; // x8
  bool v16; // cf
  __int64 v17; // x19
  __int64 v18; // x0

  v1 = *(_QWORD *)(a1 + 152);
  v2 = *(_QWORD *)(v1 + 1872);
  v3 = raw_spin_lock_irqsave(v1 + 792);
  *(_BYTE *)(v1 + 827) = 1;
  raw_spin_unlock_irqrestore(v1 + 792, v3);
  v4 = *(_QWORD *)(v1 + 2160);
  if ( v4 && *(_BYTE *)(v1 + 2168) == 1 )
    ipc_log_string(v4, "%s: Enter\n", "sdhci_msm_runtime_suspend");
  if ( v2 )
  {
    v5 = *(__int64 **)(v1 + 1872);
    if ( v5 )
    {
      if ( *((_DWORD *)v5 + 2) )
      {
        v6 = *v5;
        v7 = 0;
        do
        {
          if ( *(_BYTE *)(v6 + 40) != 1 )
            break;
          v8 = *(_QWORD *)(v6 + 32);
          v9 = *(_QWORD *)(v6 + 16);
          v10 = *(_QWORD *)(v8 + 752);
          if ( v10 && *(_BYTE *)(v8 + 760) == 1 )
            ipc_log_string(
              v10,
              "%s: mask: 0x%lx type: %d vote: %u\n",
              "sdhci_msm_update_qos_constraints",
              *(_QWORD *)v6,
              2,
              0x7FFFFFFF);
          v11 = 0;
          while ( 1 )
          {
            v12 = -1LL << v11;
            v13 = (unsigned int)v12 & *(_DWORD *)v6;
            if ( ((unsigned int)v12 & *(_DWORD *)v6) == 0 )
            {
LABEL_17:
              *(_BYTE *)(v6 + 24) = 0;
              *(_BYTE *)(v6 + 41) = 1;
              goto LABEL_18;
            }
            updated = dev_pm_qos_update_request(v9, 0x7FFFFFFF);
            if ( updated < 0 )
              break;
            v9 += 80;
            v15 = __clz(__rbit64(v13));
            v16 = v15 >= 0x1F;
            v11 = v15 + 1;
            if ( v16 )
              goto LABEL_17;
          }
          dev_err(*(_QWORD *)(v1 + 1408) + 16LL, "Failed (%d) removing qos vote(%d)\n", updated, v7);
LABEL_18:
          ++v7;
          v6 += 48;
        }
        while ( v7 < *((_DWORD *)v5 + 2) );
      }
    }
  }
  v17 = *(_QWORD *)(v1 + 1864);
  v18 = _msecs_to_jiffies(*(unsigned int *)(v1 + 2000));
  queue_delayed_work_on(32, v17, v1 + 1760, v18);
  if ( (*(_BYTE *)(*(_QWORD *)(v1 + 1536) + 1003LL) & 8) != 0 )
    return qcom_ice_suspend(*(_QWORD *)(v1 + 1512));
  else
    return 0;
}
