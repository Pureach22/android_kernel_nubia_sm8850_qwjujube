__int64 __fastcall crm_dump_drv_regs(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  unsigned int v4; // w22
  const char *v5; // x2
  int v6; // w0
  unsigned int v7; // w20
  __int64 irq_data; // x21
  const char *v10; // x24
  const char *v11; // x3
  __int64 v12; // x3
  __int64 v13; // x27
  __int64 v14; // x20
  __int64 v15; // x21
  unsigned int v16; // w0
  __int64 v17; // x3
  int *v18; // x9
  int v19; // w8
  _DWORD *v20; // x9
  int v21; // w10
  int v22; // w11
  __int64 v23; // x20
  unsigned int v24; // w0
  __int64 v25; // x23
  __int64 v26; // x20
  const char *v27; // x8
  unsigned int v28; // w25
  const char *v29; // x26
  __int64 v30; // x21
  unsigned int v31; // w0
  int v32; // w28
  unsigned int v33; // w9
  const char *v34; // x27
  unsigned int v35; // w24
  __int64 v36; // x21
  unsigned int v37; // w0
  __int64 v38; // x3
  __int64 v39; // x21
  unsigned int v40; // w0
  __int64 v41; // x20
  __int64 v42; // x21
  unsigned int v43; // w0
  __int64 v44; // x3
  int *v45; // x9
  _BOOL4 v46; // w21
  __int64 v47; // x20
  unsigned int v48; // w0
  __int64 v49; // x23
  __int64 v50; // x20
  unsigned int v51; // w26
  __int64 v52; // x28
  const char *v53; // x8
  __int64 v54; // x23
  unsigned int v55; // w0
  int v56; // w25
  _DWORD *v57; // x8
  unsigned int v58; // w9
  unsigned int v59; // w23
  __int64 v60; // x20
  unsigned int v61; // w0
  __int64 v62; // [xsp+10h] [xbp-30h]
  __int64 v63; // [xsp+10h] [xbp-30h]
  const char *v64; // [xsp+18h] [xbp-28h]
  const char *v65; // [xsp+18h] [xbp-28h]
  __int64 v66; // [xsp+20h] [xbp-20h]
  __int64 v67; // [xsp+20h] [xbp-20h]
  _BYTE v69[4]; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v70; // [xsp+38h] [xbp-8h]

  v70 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 24);
  v69[0] = 0;
  v4 = ((unsigned int)vmalloc_to_page(v3) + (memstart_addr >> 12 << 6)) << 6;
  if ( *(_DWORD *)a1 )
    v5 = "SW";
  else
    v5 = "HW";
  printk(&unk_B84D, "crm_v2", v5, *(unsigned int *)(a1 + 32));
  raw_spin_lock(a1 + 172);
  if ( *(_DWORD *)a1 == 1 )
  {
    irq_data = irq_get_irq_data(*(unsigned int *)(a1 + 176));
    irq_get_irqchip_state(*(unsigned int *)(a1 + 176), 0, v69);
    v10 = "crm_v2";
    if ( v69[0] )
      v11 = "PENDING";
    else
      v11 = "NOT PENDING";
    printk(&unk_B904, "crm_v2", *(_QWORD *)(irq_data + 8), v11);
    v13 = 0;
    v62 = a1 + 48;
    while ( 1 )
    {
      if ( (((unsigned __int64)*(unsigned int *)(*(_QWORD *)(a2 + 288) + 4LL) >> v13) & 1) != 0 )
      {
        v25 = v62 + 40 * v13;
        if ( *(_DWORD *)(v25 + 12) )
        {
          v26 = v62 + 40 * v13;
          v27 = "BW_PT_VOTE_ND";
          if ( v13 == 1 )
            v27 = "BW_VOTE_ND";
          v28 = 0;
          if ( v13 )
            v29 = "node";
          else
            v29 = (const char *)&unk_B861;
          if ( !v13 )
            v27 = "PERF_OL_VCD";
          v64 = v27;
          v66 = v13;
          do
          {
            if ( *(_DWORD *)(v25 + 8) )
            {
              v32 = 3;
              do
              {
                v34 = v10;
                v35 = v32;
                if ( (unsigned int)(v32 - 3) >= 5 )
                {
                  v35 = 3;
                  __break(0x800u);
                }
                readl_relaxed(
                  *(_QWORD *)(a1 + 24)
                + **(_DWORD **)(v26 + 16)
                + *(_DWORD *)(*(_QWORD *)(v26 + 16) + 4LL) * *(_DWORD *)(a1 + 32)
                + *(_DWORD *)(*(_QWORD *)(v26 + 16) + 4LL * v35)
                + *(_DWORD *)(*(_QWORD *)(v26 + 16) + 8LL) * v28);
                v10 = v34;
                printk(&unk_B7BF, v34, *(unsigned int *)(a1 + 32), v29);
                v33 = v32 - 2;
                ++v32;
              }
              while ( v33 < *(_DWORD *)(v25 + 8) );
            }
            printk(&unk_B380, v10, *(unsigned int *)(a1 + 32), v64);
            v30 = **(_DWORD **)(v26 + 16)
                + *(_DWORD *)(*(_QWORD *)(v26 + 16) + 4LL) * *(_DWORD *)(a1 + 32)
                + *(_DWORD *)(*(_QWORD *)(v26 + 16) + 56LL)
                + *(_DWORD *)(*(_QWORD *)(v26 + 16) + 8LL) * v28;
            v31 = readl_relaxed(*(_QWORD *)(a1 + 24) + v30);
            printk(&unk_B3B0, v10, (unsigned int)v30 + v4, v31);
            v13 = v66;
            if ( !v66 )
            {
              printk(&unk_B7F3, v10, *(unsigned int *)(a1 + 32), v12);
              v36 = **(_DWORD **)(v26 + 16)
                  + *(_DWORD *)(*(_QWORD *)(v26 + 16) + 4LL) * *(_DWORD *)(a1 + 32)
                  + *(_DWORD *)(*(_QWORD *)(v26 + 16) + 36LL)
                  + *(_DWORD *)(*(_QWORD *)(v26 + 16) + 8LL) * v28;
              v37 = readl_relaxed(*(_QWORD *)(a1 + 24) + v36);
              printk(&unk_B3B0, v10, (unsigned int)v36 + v4, v37);
              printk(&unk_B3CA, v10, *(unsigned int *)(a1 + 32), v38);
              v39 = **(_DWORD **)(v26 + 16)
                  + *(_DWORD *)(*(_QWORD *)(v26 + 16) + 4LL) * *(_DWORD *)(a1 + 32)
                  + *(_DWORD *)(*(_QWORD *)(v26 + 16) + 48LL)
                  + *(_DWORD *)(*(_QWORD *)(v26 + 16) + 8LL) * v28;
              v40 = readl_relaxed(*(_QWORD *)(a1 + 24) + v39);
              printk(&unk_B3B0, v10, (unsigned int)v39 + v4, v40);
            }
            ++v28;
          }
          while ( v28 < *(_DWORD *)(v25 + 12) );
        }
        if ( (_DWORD)v13 == 2 )
        {
          printk(&unk_B65C, v10, *(unsigned int *)(a1 + 32), v12);
          v14 = v62 + 40 * v13;
          v15 = (unsigned int)(**(_DWORD **)(v14 + 16)
                             + *(_DWORD *)(*(_QWORD *)(v14 + 16) + 4LL) * *(_DWORD *)(a1 + 32)
                             + *(_DWORD *)(*(_QWORD *)(v14 + 16) + 36LL));
          v16 = readl_relaxed(*(_QWORD *)(a1 + 24) + v15);
          printk(&unk_B3B0, v10, (unsigned int)v15 + v4, v16);
          printk(&unk_B409, v10, *(unsigned int *)(a1 + 32), v17);
          v18 = *(int **)(v14 + 16);
          v19 = *(_DWORD *)(a1 + 32);
          v22 = *v18;
          v21 = v18[1];
          v20 = v18 + 13;
        }
        else
        {
          if ( (_DWORD)v13 != 1 )
            goto LABEL_16;
          printk(&unk_B8A7, v10, *(unsigned int *)(a1 + 32), v12);
          v41 = v62 + 40 * v13;
          v42 = (unsigned int)(**(_DWORD **)(v41 + 16)
                             + *(_DWORD *)(*(_QWORD *)(v41 + 16) + 4LL) * *(_DWORD *)(a1 + 32)
                             + *(_DWORD *)(*(_QWORD *)(v41 + 16) + 36LL));
          v43 = readl_relaxed(*(_QWORD *)(a1 + 24) + v42);
          printk(&unk_B3B0, v10, (unsigned int)v42 + v4, v43);
          printk(&unk_B6DC, v10, *(unsigned int *)(a1 + 32), v44);
          v45 = *(int **)(v41 + 16);
          v19 = *(_DWORD *)(a1 + 32);
          v22 = *v45;
          v21 = v45[1];
          v20 = v45 + 12;
        }
        v23 = (unsigned int)(v22 + v21 * v19 + *v20);
        v24 = readl_relaxed(*(_QWORD *)(a1 + 24) + v23);
        printk(&unk_B3B0, v10, (unsigned int)v23 + v4, v24);
      }
LABEL_16:
      if ( ++v13 == 3 )
        goto LABEL_59;
    }
  }
  if ( !*(_DWORD *)(a1 + 36) )
  {
LABEL_8:
    v7 = -16;
    goto LABEL_9;
  }
  v6 = readl_relaxed(
         *(_QWORD *)(a1 + 24)
       + (unsigned int)(*(_DWORD *)(*(_QWORD *)(a1 + 40) + 4LL)
                      + *(_DWORD *)(*(_QWORD *)(a1 + 40) + 12LL) * *(_DWORD *)(a1 + 32)));
  if ( v6 )
  {
    if ( (v6 & 3) == 0 )
      goto LABEL_8;
    v46 = (v6 & 1) == 0;
  }
  else
  {
    v46 = 0;
  }
  v47 = (unsigned int)(**(_DWORD **)(a1 + 40) + *(_DWORD *)(*(_QWORD *)(a1 + 40) + 12LL) * *(_DWORD *)(a1 + 32));
  v48 = readl_relaxed(*(_QWORD *)(a1 + 24) + v47);
  printk(&unk_B3B0, "crm_v2", (unsigned int)v47 + v4, v48);
  v49 = 0;
  v63 = a1 + 48;
  do
  {
    if ( (((unsigned __int64)*(unsigned int *)(*(_QWORD *)(a2 + 288) + 4LL) >> v49) & 1) != 0 )
    {
      v67 = v49;
      v50 = v63 + 40 * v49;
      if ( *(_DWORD *)(v50 + 12) )
      {
        v51 = 0;
        v52 = v63 + 40 * v49;
        v53 = "BW_PT_VOTE_ND";
        if ( v49 == 1 )
          v53 = "BW_VOTE_ND";
        if ( !v49 )
          v53 = "PERF_OL_VCD";
        v65 = v53;
        do
        {
          if ( *(_DWORD *)(v50 + 8) )
          {
            v56 = 3;
            do
            {
              v59 = v56;
              if ( (unsigned int)(v56 - 3) >= 5 )
              {
                v59 = 3;
                __break(0x800u);
              }
              v57 = *(_DWORD **)(v52 + 16);
              readl_relaxed(*(_QWORD *)(a1 + 24) + *v57
                                                 + v57[1] * *(_DWORD *)(a1 + 32)
                                                 + v57[v59]
                                                 + v57[8] * v46
                                                 + v57[2] * v51);
              printk(&unk_B71D, "crm_v2", *(unsigned int *)(a1 + 32), v46);
              v58 = v56 - 2;
              ++v56;
            }
            while ( v58 < *(_DWORD *)(v50 + 8) );
          }
          printk(&unk_B633, "crm_v2", *(unsigned int *)(a1 + 32), v65);
          v54 = **(_DWORD **)(v52 + 16)
              + *(_DWORD *)(*(_QWORD *)(v52 + 16) + 4LL) * *(_DWORD *)(a1 + 32)
              + *(_DWORD *)(*(_QWORD *)(v52 + 16) + 56LL)
              + *(_DWORD *)(*(_QWORD *)(v52 + 16) + 8LL) * v51;
          v55 = readl_relaxed(*(_QWORD *)(a1 + 24) + v54);
          printk(&unk_B3B0, "crm_v2", (unsigned int)v54 + v4, v55);
          ++v51;
        }
        while ( v51 < *(_DWORD *)(v50 + 12) );
      }
      v49 = v67;
      if ( !v67 )
      {
        v60 = (unsigned int)(**(_DWORD **)(a1 + 64)
                           + *(_DWORD *)(*(_QWORD *)(a1 + 64) + 4LL) * *(_DWORD *)(a1 + 32)
                           + *(_DWORD *)(*(_QWORD *)(a1 + 64) + 60LL));
        v61 = readl_relaxed(*(_QWORD *)(a1 + 24) + v60);
        printk(&unk_B3B0, "crm_v2", (unsigned int)v60 + v4, v61);
      }
    }
    ++v49;
  }
  while ( v49 != 3 );
LABEL_59:
  v7 = 0;
LABEL_9:
  raw_spin_unlock(a1 + 172);
  _ReadStatusReg(SP_EL0);
  return v7;
}
