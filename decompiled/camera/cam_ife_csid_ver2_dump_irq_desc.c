__int64 __fastcall cam_ife_csid_ver2_dump_irq_desc(__int64 a1, __int64 a2)
{
  unsigned int v2; // w21
  __int64 v4; // x22
  int v5; // w20
  unsigned int v6; // w23
  __int64 v7; // x9
  __int64 v9; // x0
  __int64 v10; // x1
  int v11; // w23
  __int64 v12; // x24
  unsigned __int64 v13; // x25
  __int64 v14; // x8
  int v15; // w3
  unsigned __int64 v16; // x21
  int v17; // w23
  __int64 v18; // x24
  const char **v19; // x8
  int v20; // w3
  int v21; // w23
  __int64 v22; // x24
  unsigned __int64 v23; // x25
  __int64 v24; // x8
  int v25; // w3
  unsigned __int64 v26; // x21
  int v27; // w23
  __int64 v28; // x24
  const char **v29; // x8
  int v30; // w3

  v2 = *(_DWORD *)(a2 + 8);
  v4 = **(_QWORD **)(a1 + 31136);
  v5 = scnprintf(*(_QWORD *)(a2 + 32), 1500, "Printing executable IRQ for hw_type: CSID reg_unit: %d\n", v2);
  if ( v2 > 0xF )
  {
    scnprintf(*(_QWORD *)(a2 + 32) + v5, 1500 - v5, "Invalid reg_unit %d\n", *(_DWORD *)(a2 + 8));
    return 4294967274LL;
  }
  if ( ((1 << v2) & 0xCFFC) != 0 )
  {
    if ( *(_DWORD *)(v4 + 608) )
    {
      v6 = 0;
      do
      {
        v7 = *(_QWORD *)(v4 + 584) + 40LL * (int)v6++;
        v5 += scnprintf(
                *(_QWORD *)(a2 + 32) + v5,
                1500 - v5,
                "%#12x : %s - %s\n",
                *(_DWORD *)v7,
                *(const char **)(v7 + 8),
                *(const char **)(v7 + 16));
      }
      while ( v6 < *(_DWORD *)(v4 + 608) );
    }
    return 0;
  }
  if ( ((1 << v2) & 0x1001) != 0 )
  {
    v9 = scnprintf(*(_QWORD *)(a2 + 32) + v5, 1500 - v5, "TOP_IRQ_STATUS_REG[%d]:\n", 0);
    v11 = v9 + v5;
    if ( **(_DWORD **)(v4 + 592) )
    {
      v12 = 0;
      v13 = 0;
      while ( v13 != 32 )
      {
        v14 = *(_QWORD *)(v4 + 560);
        v15 = *(_DWORD *)(v14 + v12);
        if ( v15 )
        {
          v9 = scnprintf(
                 *(_QWORD *)(a2 + 32) + v11,
                 1500 - v11,
                 "%#12x : %s - %s\n",
                 v15,
                 *(const char **)(v14 + v12 + 8),
                 *(const char **)(v14 + v12 + 16));
          ++v13;
          v11 += v9;
          v12 += 40;
          if ( v13 < **(unsigned int **)(v4 + 592) )
            continue;
        }
        goto LABEL_14;
      }
      goto LABEL_32;
    }
LABEL_14:
    v9 = scnprintf(*(_QWORD *)(a2 + 32) + v11, 1500 - v11, "TOP_IRQ_STATUS_REG[%d]:\n", 1);
    if ( *(_DWORD *)(*(_QWORD *)(v4 + 592) + 4LL) )
    {
      v16 = 0;
      v17 = v9 + v11;
      v18 = 1296;
      while ( v16 != 32 )
      {
        v19 = (const char **)(*(_QWORD *)(v4 + 560) + v18);
        v20 = *((_DWORD *)v19 - 4);
        if ( v20 )
        {
          v9 = scnprintf(*(_QWORD *)(a2 + 32) + v17, 1500 - v17, "%#12x : %s - %s\n", v20, *(v19 - 1), *v19);
          ++v16;
          v17 += v9;
          v18 += 40;
          if ( v16 < *(unsigned int *)(*(_QWORD *)(v4 + 592) + 4LL) )
            continue;
        }
        return 0;
      }
LABEL_32:
      __break(0x5512u);
      return cam_ife_csid_ver2_get_primary_sof_timer_reg_addr(v9, v10);
    }
  }
  else
  {
    v9 = scnprintf(*(_QWORD *)(a2 + 32) + v5, 1500 - v5, "RX_IRQ_STATUS_REG[%d]:\n", 0);
    v21 = v9 + v5;
    if ( **(_DWORD **)(v4 + 600) )
    {
      v22 = 0;
      v23 = 0;
      while ( v23 != 32 )
      {
        v24 = *(_QWORD *)(v4 + 568);
        v25 = *(_DWORD *)(v24 + v22);
        if ( v25 )
        {
          v9 = scnprintf(
                 *(_QWORD *)(a2 + 32) + v21,
                 1500 - v21,
                 "%#12x : %s - %s\n",
                 v25,
                 *(const char **)(v24 + v22 + 8),
                 *(const char **)(v24 + v22 + 16));
          ++v23;
          v21 += v9;
          v22 += 40;
          if ( v23 < **(unsigned int **)(v4 + 600) )
            continue;
        }
        goto LABEL_25;
      }
      goto LABEL_32;
    }
LABEL_25:
    v9 = scnprintf(*(_QWORD *)(a2 + 32) + v21, 1500 - v21, "RX_IRQ_STATUS_REG[%d]:\n", 1);
    if ( *(_DWORD *)(*(_QWORD *)(v4 + 600) + 4LL) )
    {
      v26 = 0;
      v27 = v9 + v21;
      v28 = 1296;
      while ( v26 != 32 )
      {
        v29 = (const char **)(*(_QWORD *)(v4 + 568) + v28);
        v30 = *((_DWORD *)v29 - 4);
        if ( v30 )
        {
          v9 = scnprintf(*(_QWORD *)(a2 + 32) + v27, 1500 - v27, "%#12x : %s - %s\n", v30, *(v29 - 1), *v29);
          ++v26;
          v27 += v9;
          v28 += 40;
          if ( v26 < *(unsigned int *)(*(_QWORD *)(v4 + 600) + 4LL) )
            continue;
        }
        return 0;
      }
      goto LABEL_32;
    }
  }
  return 0;
}
