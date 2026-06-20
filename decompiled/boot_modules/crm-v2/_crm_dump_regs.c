__int64 __fastcall crm_dump_regs(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v5; // w0
  unsigned int v6; // w26
  int v7; // w20
  int v8; // w25
  __int64 v9; // x3
  unsigned int v10; // w22
  int v11; // w25
  __int64 v12; // x26
  unsigned int v13; // w0
  __int64 v14; // x26
  unsigned int v15; // w0
  unsigned int v16; // w22
  __int64 v17; // x3
  unsigned int v18; // w25
  __int64 v19; // x26
  unsigned int v20; // w0
  __int64 v21; // x26
  unsigned int v22; // w0
  __int64 v23; // x26
  unsigned int v24; // w0
  __int64 v25; // x26
  unsigned int v26; // w0
  __int64 v27; // x26
  unsigned int v28; // w0
  __int64 v29; // x20
  unsigned int v30; // w0
  unsigned int v31; // w20
  __int64 v32; // x3
  __int64 v33; // x3
  unsigned int v34; // w25
  __int64 v35; // x26
  unsigned int v36; // w0
  __int64 v37; // x2
  __int64 v38; // x3
  unsigned int v39; // w25
  __int64 v40; // x26
  unsigned int v41; // w0
  __int64 v42; // x26
  unsigned int v43; // w0
  int v44; // w0
  unsigned int v45; // w25
  int v46; // w20
  int v47; // w24
  __int64 v48; // x3
  __int64 result; // x0
  unsigned int v50; // w22
  int v51; // w23
  __int64 v52; // x24
  unsigned int v53; // w0
  __int64 v54; // x24
  unsigned int v55; // w0
  __int64 v56; // x24
  unsigned int v57; // w0
  __int64 v58; // x24
  unsigned int v59; // w0
  __int64 v60; // x24
  unsigned int v61; // w0

  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 288) + 4LL) & 2) != 0 )
  {
    printk(&unk_B759, "crm_v2", a3, a4);
    v5 = vmalloc_to_page(*(_QWORD *)(a1 + 104));
    v6 = memstart_addr;
    v7 = v5;
    v8 = *(_DWORD *)(a1 + 104);
    printk(&unk_B4BD, "crm_v2", *(unsigned int *)(a1 + 112), v9);
    if ( *(_DWORD *)(a1 + 112) )
    {
      v10 = 0;
      v11 = (v8 & 0xFFF) + ((v7 + 0x40000000 + (v6 >> 12 << 6)) << 6);
      do
      {
        v12 = *(_DWORD *)(*(_QWORD *)(a1 + 120) + 8LL)
            + **(_DWORD **)(a1 + 120)
            + (*(_DWORD *)(*(_QWORD *)(a1 + 120) + 4LL) + **(_DWORD **)(a1 + 120)) * v10;
        v13 = readl_relaxed(*(_QWORD *)(a1 + 104) + v12);
        printk(&unk_B3B0, "crm_v2", (unsigned int)(v12 + v11), v13);
        v14 = *(_DWORD *)(*(_QWORD *)(a1 + 120) + 12LL)
            + **(_DWORD **)(a1 + 120)
            + (*(_DWORD *)(*(_QWORD *)(a1 + 120) + 4LL) + **(_DWORD **)(a1 + 120)) * v10;
        v15 = readl_relaxed(*(_QWORD *)(a1 + 104) + v14);
        printk(&unk_B3B0, "crm_v2", (unsigned int)(v14 + v11), v15);
        ++v10;
      }
      while ( v10 < *(_DWORD *)(a1 + 112) );
    }
  }
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 288) + 4LL) & 4) != 0 )
  {
    printk(&unk_B70A, "crm_v2", a3, a4);
    v16 = (*(_DWORD *)(a1 + 152) & 0xFFF)
        + (((unsigned int)vmalloc_to_page(*(_QWORD *)(a1 + 152)) + 0x40000000 + (memstart_addr >> 12 << 6)) << 6);
    printk(&unk_B58F, "crm_v2", *(unsigned int *)(a1 + 160), v17);
    if ( *(_DWORD *)(a1 + 160) )
    {
      v18 = 0;
      do
      {
        v19 = *(_DWORD *)(*(_QWORD *)(a1 + 168) + 8LL)
            + **(_DWORD **)(a1 + 168)
            + (*(_DWORD *)(*(_QWORD *)(a1 + 168) + 4LL) + **(_DWORD **)(a1 + 168)) * v18;
        v20 = readl_relaxed(*(_QWORD *)(a1 + 152) + v19);
        printk(&unk_B3B0, "crm_v2", (unsigned int)v19 + v16, v20);
        v21 = *(_DWORD *)(*(_QWORD *)(a1 + 168) + 12LL)
            + **(_DWORD **)(a1 + 168)
            + (*(_DWORD *)(*(_QWORD *)(a1 + 168) + 4LL) + **(_DWORD **)(a1 + 168)) * v18;
        v22 = readl_relaxed(*(_QWORD *)(a1 + 152) + v21);
        printk(&unk_B3B0, "crm_v2", (unsigned int)v21 + v16, v22);
        v23 = *(_DWORD *)(*(_QWORD *)(a1 + 168) + 16LL)
            + **(_DWORD **)(a1 + 168)
            + (*(_DWORD *)(*(_QWORD *)(a1 + 168) + 4LL) + **(_DWORD **)(a1 + 168)) * v18;
        v24 = readl_relaxed(*(_QWORD *)(a1 + 152) + v23);
        printk(&unk_B3B0, "crm_v2", (unsigned int)v23 + v16, v24);
        v25 = *(_DWORD *)(*(_QWORD *)(a1 + 168) + 20LL)
            + **(_DWORD **)(a1 + 168)
            + (*(_DWORD *)(*(_QWORD *)(a1 + 168) + 4LL) + **(_DWORD **)(a1 + 168)) * v18;
        v26 = readl_relaxed(*(_QWORD *)(a1 + 152) + v25);
        printk(&unk_B3B0, "crm_v2", (unsigned int)v25 + v16, v26);
        v27 = *(_DWORD *)(*(_QWORD *)(a1 + 168) + 24LL)
            + **(_DWORD **)(a1 + 168)
            + (*(_DWORD *)(*(_QWORD *)(a1 + 168) + 4LL) + **(_DWORD **)(a1 + 168)) * v18;
        v28 = readl_relaxed(*(_QWORD *)(a1 + 152) + v27);
        printk(&unk_B3B0, "crm_v2", (unsigned int)v27 + v16, v28);
        ++v18;
      }
      while ( v18 < *(_DWORD *)(a1 + 160) );
    }
    v29 = (unsigned int)(*(_DWORD *)(*(_QWORD *)(a1 + 168) + 28LL) + **(_DWORD **)(a1 + 168));
    v30 = readl_relaxed(*(_QWORD *)(a1 + 152) + v29);
    printk(&unk_B3B0, "crm_v2", (unsigned int)v29 + v16, v30);
  }
  printk(&unk_B865, "crm_v2", a3, a4);
  v31 = (*(_DWORD *)(a1 + 200) & 0xFFF)
      + (((unsigned int)vmalloc_to_page(*(_QWORD *)(a1 + 200)) + 0x40000000 + (memstart_addr >> 12 << 6)) << 6);
  printk(&unk_B565, "crm_v2", *(unsigned int *)(a1 + 208), v32);
  if ( *(_DWORD *)(a1 + 208) )
  {
    v34 = 0;
    do
    {
      v35 = *(_DWORD *)(*(_QWORD *)(a1 + 216) + 8LL)
          + **(_DWORD **)(a1 + 216)
          + (*(_DWORD *)(*(_QWORD *)(a1 + 216) + 12LL) + *(_DWORD *)(*(_QWORD *)(a1 + 216) + 4LL)) * v34;
      v36 = readl_relaxed(*(_QWORD *)(a1 + 200) + v35);
      printk(&unk_B3B0, "crm_v2", (unsigned int)v35 + v31, v36);
      ++v34;
    }
    while ( v34 < *(_DWORD *)(a1 + 208) );
  }
  printk(&unk_B5C2, "crm_v2", v31, v33);
  if ( *(_DWORD *)(a1 + 112) + *(_DWORD *)(a1 + 208) )
  {
    v39 = 0;
    do
    {
      v40 = *(_DWORD *)(*(_QWORD *)(a1 + 216) + 16LL)
          + **(_DWORD **)(a1 + 216)
          + (*(_DWORD *)(*(_QWORD *)(a1 + 216) + 20LL) + *(_DWORD *)(*(_QWORD *)(a1 + 216) + 4LL)) * v39;
      v41 = readl_relaxed(*(_QWORD *)(a1 + 200) + v40);
      printk(&unk_B3B0, "crm_v2", (unsigned int)v40 + v31, v41);
      v42 = *(_DWORD *)(*(_QWORD *)(a1 + 216) + 24LL)
          + **(_DWORD **)(a1 + 216)
          + (*(_DWORD *)(*(_QWORD *)(a1 + 216) + 28LL) + *(_DWORD *)(*(_QWORD *)(a1 + 216) + 4LL)) * v39;
      v43 = readl_relaxed(*(_QWORD *)(a1 + 200) + v42);
      printk(&unk_B3B0, "crm_v2", (unsigned int)v42 + v31, v43);
      ++v39;
    }
    while ( v39 < *(_DWORD *)(a1 + 112) + *(_DWORD *)(a1 + 208) );
  }
  printk(&unk_B6CC, "crm_v2", v37, v38);
  v44 = vmalloc_to_page(*(_QWORD *)(a1 + 248));
  v45 = memstart_addr;
  v46 = v44;
  v47 = *(_DWORD *)(a1 + 248);
  result = printk(&unk_B5D8, "crm_v2", *(unsigned int *)(a1 + 256), v48);
  if ( *(_DWORD *)(a1 + 256) )
  {
    v50 = 0;
    v51 = (v47 & 0xFFF) + ((v46 + 0x40000000 + (v45 >> 12 << 6)) << 6);
    do
    {
      v52 = *(_DWORD *)(*(_QWORD *)(a1 + 264) + 8LL)
          + **(_DWORD **)(a1 + 264)
          + (*(_DWORD *)(*(_QWORD *)(a1 + 264) + 4LL) + **(_DWORD **)(a1 + 264)) * v50;
      v53 = readl_relaxed(*(_QWORD *)(a1 + 248) + v52);
      printk(&unk_B3B0, "crm_v2", (unsigned int)(v52 + v51), v53);
      v54 = *(_DWORD *)(*(_QWORD *)(a1 + 264) + 12LL)
          + **(_DWORD **)(a1 + 264)
          + (*(_DWORD *)(*(_QWORD *)(a1 + 264) + 4LL) + **(_DWORD **)(a1 + 264)) * v50;
      v55 = readl_relaxed(*(_QWORD *)(a1 + 248) + v54);
      printk(&unk_B3B0, "crm_v2", (unsigned int)(v54 + v51), v55);
      v56 = *(_DWORD *)(*(_QWORD *)(a1 + 264) + 16LL)
          + **(_DWORD **)(a1 + 264)
          + (*(_DWORD *)(*(_QWORD *)(a1 + 264) + 4LL) + **(_DWORD **)(a1 + 264)) * v50;
      v57 = readl_relaxed(*(_QWORD *)(a1 + 248) + v56);
      printk(&unk_B3B0, "crm_v2", (unsigned int)(v56 + v51), v57);
      v58 = *(_DWORD *)(*(_QWORD *)(a1 + 264) + 20LL)
          + **(_DWORD **)(a1 + 264)
          + (*(_DWORD *)(*(_QWORD *)(a1 + 264) + 4LL) + **(_DWORD **)(a1 + 264)) * v50;
      v59 = readl_relaxed(*(_QWORD *)(a1 + 248) + v58);
      printk(&unk_B3B0, "crm_v2", (unsigned int)(v58 + v51), v59);
      v60 = *(_DWORD *)(*(_QWORD *)(a1 + 264) + 24LL)
          + **(_DWORD **)(a1 + 264)
          + (*(_DWORD *)(*(_QWORD *)(a1 + 264) + 4LL) + **(_DWORD **)(a1 + 264)) * v50;
      v61 = readl_relaxed(*(_QWORD *)(a1 + 248) + v60);
      result = printk(&unk_B3B0, "crm_v2", (unsigned int)(v60 + v51), v61);
      ++v50;
    }
    while ( v50 < *(_DWORD *)(a1 + 256) );
  }
  return result;
}
