__int64 __fastcall msm_geni_serial_port_setup(__int64 a1)
{
  __int64 v2; // x21
  unsigned __int64 v3; // x20
  unsigned int v4; // w8
  __int64 v5; // x9
  int v6; // w8
  __int64 v7; // x9
  __int64 v8; // x8
  __int64 v9; // x8
  unsigned __int64 v10; // x21
  __int64 v11; // x0
  __int64 v12; // x0
  unsigned __int64 v13; // x9
  int v14; // w22
  bool v15; // cc
  __int64 v16; // x8
  unsigned __int64 v17; // x21
  unsigned __int64 v18; // x9
  int v19; // w22
  __int64 v20; // x8
  unsigned __int64 v21; // x21
  unsigned __int64 v22; // x9
  int v23; // w22
  unsigned int v24; // w0
  __int64 v25; // x0
  unsigned __int64 v26; // x0
  __int64 v27; // x21
  __int64 result; // x0
  __int64 v29; // x0
  _QWORD v30[2]; // [xsp+0h] [xbp-10h] BYREF

  v30[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 968);
  v30[0] = 0;
  if ( v2 )
  {
    if ( *(_DWORD *)(a1 + 916) )
    {
      v3 = sched_clock(a1);
      ipc_log_string(v2, "%s:start at %llu nsec(%llu usec)\n", "msm_geni_serial_port_setup", v3, v3 / 0x3E8);
    }
    else
    {
      v3 = 0;
    }
  }
  else
  {
    v3 = -22;
  }
  v4 = *(_DWORD *)(a1 + 560);
  v5 = *(_QWORD *)(a1 + 264);
  *(_DWORD *)(a1 + 572) = v4 - 2;
  if ( v5 && *(_DWORD *)(a1 + 316) == *(__int16 *)(v5 + 74) )
    v6 = 2;
  else
    v6 = v4 >> 1;
  v7 = *(_QWORD *)(a1 + 16);
  *(_DWORD *)(a1 + 568) = v6;
  *(_DWORD *)(a1 + 564) = 2;
  writel_relaxed(0xA0u, (unsigned int *)(v7 + 660));
  if ( *(_BYTE *)(a1 + 1136) == 1 )
  {
    *(_DWORD *)(a1 + 584) = 3;
    goto LABEL_54;
  }
  v8 = *(_QWORD *)(a1 + 264);
  if ( !v8 || *(_DWORD *)(a1 + 316) != *(__int16 *)(v8 + 74) )
  {
    *(_DWORD *)(a1 + 584) = 2;
    geni_se_config_packing(a1 + 712, 8, 4, 0, 1, 0);
    geni_se_config_packing(a1 + 712, 8, 4, 0, 0, 1);
    writel_relaxed(0x431Cu, (unsigned int *)(*(_QWORD *)(a1 + 16) + 576LL));
    if ( *(_QWORD *)(a1 + 608) )
    {
      if ( *(_QWORD *)(a1 + 824) )
        goto LABEL_54;
      v11 = *(_QWORD *)(a1 + 624);
      if ( !v11 )
      {
        *(_QWORD *)(a1 + 872) = 0;
        *(_QWORD *)(a1 + 824) = -22;
        goto LABEL_54;
      }
      v30[0] = -1;
      v12 = dma_alloc_attrs(v11, 2048, v30, 3264, 0);
      *(_QWORD *)(a1 + 824) = v12;
      if ( v12 )
      {
        *(_QWORD *)(a1 + 872) = v30[0];
        goto LABEL_54;
      }
    }
LABEL_65:
    result = 4294967284LL;
    goto LABEL_66;
  }
  *(_DWORD *)(a1 + 584) = 1;
  msm_serial_try_disable_interrupts(a1);
  if ( !*(_QWORD *)(a1 + 520) || (v9 = *(_QWORD *)(a1 + 264)) != 0 && *(_DWORD *)(a1 + 316) == *(__int16 *)(v9 + 74) )
  {
    v10 = 1000;
  }
  else
  {
    LODWORD(v13) = *(_DWORD *)(a1 + 1000);
    if ( (_DWORD)v13 )
      v13 = (unsigned int)v13;
    else
      v13 = 115200;
    v10 = ((1000000
          * (unsigned __int64)(unsigned int)(*(_DWORD *)(a1 + 556) * *(_DWORD *)(a1 + 552))
          / v13
          * (unsigned __int128)0x199999999999999AuLL) >> 64)
        + 50;
  }
  v14 = 1;
  while ( (readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 1552LL)) & 1) == 0 )
  {
    _const_udelay(42950);
    v15 = v10 > v14++;
    if ( !v15 )
    {
      writel_relaxed(4u, (unsigned int *)(*(_QWORD *)(a1 + 16) + 1540LL));
      if ( !*(_QWORD *)(a1 + 520)
        || (v16 = *(_QWORD *)(a1 + 264)) != 0 && *(_DWORD *)(a1 + 316) == *(__int16 *)(v16 + 74) )
      {
        v17 = 1000;
      }
      else
      {
        LODWORD(v18) = *(_DWORD *)(a1 + 1000);
        if ( (_DWORD)v18 )
          v18 = (unsigned int)v18;
        else
          v18 = 115200;
        v17 = ((1000000
              * (unsigned __int64)(unsigned int)(*(_DWORD *)(a1 + 556) * *(_DWORD *)(a1 + 552))
              / v18
              * (unsigned __int128)0x199999999999999AuLL) >> 64)
            + 50;
      }
      v19 = 1;
      while ( (readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 1552LL)) & 0x10) == 0 )
      {
        _const_udelay(42950);
        v15 = v17 > v19++;
        if ( !v15 )
        {
          writel_relaxed(2u, (unsigned int *)(*(_QWORD *)(a1 + 16) + 1540LL));
          if ( !*(_QWORD *)(a1 + 520)
            || (v20 = *(_QWORD *)(a1 + 264)) != 0 && *(_DWORD *)(a1 + 316) == *(__int16 *)(v20 + 74) )
          {
            v21 = 1000;
          }
          else
          {
            LODWORD(v22) = *(_DWORD *)(a1 + 1000);
            if ( (_DWORD)v22 )
              v22 = (unsigned int)v22;
            else
              v22 = 115200;
            v21 = ((1000000
                  * (unsigned __int64)(unsigned int)(*(_DWORD *)(a1 + 556) * *(_DWORD *)(a1 + 552))
                  / v22
                  * (unsigned __int128)0x199999999999999AuLL) >> 64)
                + 50;
          }
          v23 = 1;
          do
          {
            if ( (readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 1552LL)) & 0x20) != 0 )
              break;
            _const_udelay(42950);
            v15 = v21 > v23++;
          }
          while ( v15 );
          goto LABEL_53;
        }
      }
      break;
    }
  }
LABEL_53:
  v24 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 1552LL));
  writel_relaxed(v24, (unsigned int *)(*(_QWORD *)(a1 + 16) + 1560LL));
  msm_geni_serial_enable_interrupts(a1);
  geni_se_config_packing(a1 + 712, 8, 1, 0, 1, 0);
  geni_se_config_packing(a1 + 712, 8, 4, 0, 0, 1);
LABEL_54:
  geni_se_init(a1 + 712, *(unsigned int *)(a1 + 568), *(unsigned int *)(a1 + 572));
  geni_se_select_mode(a1 + 712, *(unsigned int *)(a1 + 584));
  if ( *(_BYTE *)(a1 + 2000) != 1 )
    goto LABEL_58;
  v25 = *(_QWORD *)(a1 + 624);
  if ( !v25 )
  {
    *(_QWORD *)(a1 + 2008) = -22;
LABEL_64:
    ipc_log_string(*(_QWORD *)(a1 + 960), "Error failed to allocate memory\n");
    _ftrace_dbg(*(_QWORD *)(a1 + 344), "Error failed to allocate memory\n");
    goto LABEL_65;
  }
  *(_QWORD *)(a1 + 2024) = -1;
  v26 = dma_alloc_attrs(v25, 4112, a1 + 2024, 3264, 0);
  *(_QWORD *)(a1 + 2008) = v26;
  if ( !v26 || v26 >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_64;
LABEL_58:
  *(_BYTE *)(a1 + 600) = 1;
  __dsb(0xFu);
  v27 = *(_QWORD *)(a1 + 968);
  if ( !v27 )
  {
LABEL_62:
    result = 0;
    goto LABEL_66;
  }
  result = 0;
  if ( v3 && *(_DWORD *)(a1 + 916) )
  {
    v29 = sched_clock(0);
    ipc_log_string(v27, "%s:took %llu nsec(%llu usec)\n", "msm_geni_serial_port_setup", v29 - v3, (v29 - v3) / 0x3E8);
    goto LABEL_62;
  }
LABEL_66:
  _ReadStatusReg(SP_EL0);
  return result;
}
