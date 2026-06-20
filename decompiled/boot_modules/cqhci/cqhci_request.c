__int64 __fastcall cqhci_request(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  int v7; // w24
  __int64 *v8; // x20
  __int64 v9; // x8
  void (__fastcall *v10)(_QWORD); // x9
  _DWORD *v11; // x8
  __int64 (__fastcall *v12)(__int64 *, __int64); // x8
  __int64 v13; // x2
  __int64 v14; // x3
  void (__fastcall *v15)(_QWORD); // x8
  _DWORD *v16; // x8
  unsigned int v17; // w9
  unsigned int v18; // w10
  int v19; // w9
  __int64 v20; // x12
  unsigned __int64 *v21; // x8
  unsigned __int64 v22; // x9
  unsigned __int64 v23; // x9
  __int64 v24; // x26
  int v25; // w23
  __int64 v26; // x3
  unsigned int v27; // w0
  __int64 v28; // x3
  unsigned int v29; // w22
  __int64 v30; // x0
  __int64 v31; // x27
  __int64 v32; // x2
  _DWORD *v33; // x8
  int v34; // w9
  __int64 v35; // x8
  __int64 v36; // x23
  _QWORD *v37; // x22
  int v38; // w25
  int v39; // w26
  __int64 v40; // x8
  _DWORD *v41; // x9
  __int64 v42; // x22
  __int64 v43; // x8
  __int64 v44; // x3
  __int64 v45; // x9
  unsigned int v46; // w0
  _DWORD *v47; // x8
  void (__fastcall *v48)(__int64 *, __int64); // x8
  __int64 v50; // x1
  __int64 v51; // x8
  __int64 v52; // x1
  __int64 v53; // x3
  __int64 v54; // x4
  __int64 v55; // x1
  __int64 v56; // x1
  _QWORD v57[2]; // [xsp+0h] [xbp-10h] BYREF

  v57[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_QWORD *)(a2 + 8) )
    v7 = 31;
  else
    v7 = *(_DWORD *)(a2 + 124);
  v8 = *(__int64 **)(a1 + 1464);
  if ( (v8[7] & 1) == 0 )
  {
    v50 = *(_QWORD *)(a1 + 120);
    if ( !v50 )
      v50 = *(_QWORD *)(a1 + 8);
    printk(&unk_9E34, v50, a3, a4, a5);
    v29 = -22;
    goto LABEL_62;
  }
  if ( (*((_BYTE *)v8 + 59) & 1) == 0 )
    _cqhci_enable(*(_QWORD *)(a1 + 1464));
  if ( (*(_BYTE *)(a1 + 1477) & 1) == 0 )
  {
    v9 = *v8;
    v10 = *(void (__fastcall **)(_QWORD))(*v8 + 48);
    if ( v10 )
    {
      if ( *((_DWORD *)v10 - 1) != -452870896 )
        __break(0x8229u);
      v10(a1);
      v9 = *v8;
    }
    v11 = *(_DWORD **)(v9 + 8);
    if ( v11 )
    {
      if ( *(v11 - 1) != -1433747670 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64 *, _QWORD, __int64))v11)(v8, 0, 12);
    }
    else
    {
      writel_relaxed(0, (unsigned int *)(v8[1] + 12));
    }
    *(_BYTE *)(a1 + 1477) = 1;
    v12 = *(__int64 (__fastcall **)(__int64 *, __int64))(*v8 + 16);
    if ( v12 )
    {
      if ( *((_DWORD *)v12 - 1) != 1427797680 )
        __break(0x8228u);
      if ( (v12(v8, 12) & 1) == 0 )
        goto LABEL_16;
    }
    else if ( (readl_relaxed((unsigned int *)(v8[1] + 12)) & 1) == 0 )
    {
LABEL_16:
      v15 = *(void (__fastcall **)(_QWORD))(*v8 + 24);
      if ( v15 )
      {
        if ( *((_DWORD *)v15 - 1) != -452870896 )
          __break(0x8228u);
        v15(a1);
      }
      goto LABEL_20;
    }
    v56 = *(_QWORD *)(a1 + 120);
    if ( !v56 )
      v56 = *(_QWORD *)(a1 + 8);
    printk(&unk_9D01, v56, v13, v14, a5);
    goto LABEL_16;
  }
LABEL_20:
  v16 = *(_DWORD **)(a2 + 16);
  if ( !v16 )
  {
    v36 = *(_QWORD *)(a1 + 1464);
    v37 = (_QWORD *)(*(_QWORD *)(v36 + 80)
                   + *(unsigned __int8 *)(v36 + 88) * (unsigned __int64)*(unsigned __int8 *)(v36 + 44));
    v38 = (*(_DWORD *)(*(_QWORD *)(a2 + 8) + 24LL) & 1) << 22;
    v39 = ((int)(*(_DWORD *)(*(_QWORD *)(a2 + 8) + 24LL) << 31) >> 31) & 0x1800000;
    memset(v37, 0, *(unsigned __int8 *)(v36 + 89));
    v40 = (v38 & 0xFFC0FFFF | ((**(_DWORD **)(a2 + 8) & 0x3F) << 16) | v39) ^ 0x40402F;
    v57[0] = v40;
    v41 = *(_DWORD **)(*(_QWORD *)v36 + 40LL);
    if ( v41 )
    {
      if ( *(v41 - 1) != -58384199 )
        __break(0x8229u);
      ((void (__fastcall *)(__int64, __int64, _QWORD *))v41)(a1, a2, v57);
      v40 = v57[0];
    }
    *v37 |= v40;
    *(_QWORD *)((char *)v37 + 4) = *(unsigned int *)(*(_QWORD *)(a2 + 8) + 4LL);
    goto LABEL_50;
  }
  v17 = v16[6];
  v18 = (v17 >> 8) & 0x40
      | (v17 >> 2) & 0x800
      | (((v17 >> 9) & 1) << 12) & 0xFFFF1FFF
      | (((v17 >> 11) & 1) << 13) & 0xFFFF3FFF
      | (((v17 >> 10) & 1) << 14) & 0xFFFF7FFF
      | (((v17 >> 12) & 1) << 15);
  v19 = v16[3];
  v20 = (unsigned int)v16[4];
  v21 = (unsigned __int64 *)(v8[10] + *((unsigned __int8 *)v8 + 88) * (unsigned __int64)(unsigned __int8)v7);
  *v21 = v18 | (v19 << 16) | 0x2F | (unsigned __int64)(v20 << 32);
  if ( (v8[6] & 1) != 0 )
  {
    v22 = *(_QWORD *)(a2 + 128);
    if ( v22 )
    {
      v23 = *(_QWORD *)(v22 + 8);
      if ( HIDWORD(v23) )
      {
        __break(0x800u);
        v23 = *(_QWORD *)(*(_QWORD *)(a2 + 128) + 8LL);
      }
      v22 = v23 | ((unsigned __int64)*(unsigned int *)(a2 + 136) << 32) | 0x800000000000LL;
    }
    v21[1] = v22;
  }
  v24 = *(_QWORD *)(a2 + 16);
  if ( v24 )
  {
    v25 = *((unsigned __int8 *)v8 + 32);
    if ( (*(_DWORD *)(v24 + 24) & 0x100) != 0 )
      v26 = 1;
    else
      v26 = 2;
    v27 = dma_map_sg_attrs(**(_QWORD **)(a2 + 112), *(_QWORD *)(v24 + 56), *(unsigned int *)(v24 + 48), v26, 0);
    if ( v27 )
    {
      v29 = v27;
      if ( (v27 & 0x80000000) == 0 )
      {
        v30 = *(_QWORD *)(v24 + 56);
        v57[0] = v8[12] + (unsigned __int8)v7 * *((unsigned __int8 *)v8 + 104) * *(unsigned __int16 *)(v8[2] + 1016);
        do
        {
          v32 = *(_QWORD *)(v30 + 16);
          v33 = *(_DWORD **)(*v8 + 80);
          if ( v33 )
          {
            v31 = v30;
            if ( *(v33 - 1) != -1462619262 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64 *, _QWORD *))v33)(v8, v57);
            v30 = v31;
          }
          else
          {
            if ( v29 == 1 )
              v34 = 35;
            else
              v34 = 33;
            v35 = v57[0];
            *(_DWORD *)v57[0] = v34 | (*(_DWORD *)(v30 + 24) << 16);
            if ( v25 )
              *(_QWORD *)(v35 + 4) = v32;
            else
              *(_DWORD *)(v35 + 4) = v32;
          }
          v57[0] += *((unsigned __int8 *)v8 + 104);
          v30 = sg_next(v30);
          --v29;
        }
        while ( v29 );
LABEL_50:
        v42 = raw_spin_lock_irqsave(v8 + 3);
        if ( (*((_BYTE *)v8 + 61) & 1) != 0 )
        {
          raw_spin_unlock_irqrestore(v8 + 3, v42);
          v43 = *(_QWORD *)(a2 + 16);
          if ( v43 )
          {
            if ( (*(_DWORD *)(v43 + 24) & 0x200) != 0 )
              v44 = 2;
            else
              v44 = 1;
            dma_unmap_sg_attrs(*(_QWORD *)a1, *(_QWORD *)(v43 + 56), *(unsigned int *)(v43 + 48), v44, 0);
          }
          v29 = -16;
        }
        else
        {
          v45 = 16LL * v7;
          *(_QWORD *)(v8[23] + v45) = a2;
          *(_DWORD *)(v8[23] + v45 + 8) = 0;
          v46 = 1 << v7;
          ++*((_DWORD *)v8 + 10);
          __dsb(0xEu);
          v47 = *(_DWORD **)(*v8 + 8);
          if ( v47 )
          {
            if ( *(v47 - 1) != -1433747670 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64 *, _QWORD, __int64))v47)(v8, v46, 40);
          }
          else
          {
            writel_relaxed(v46, (unsigned int *)(v8[1] + 40));
          }
          v48 = *(void (__fastcall **)(__int64 *, __int64))(*v8 + 16);
          if ( v48 )
          {
            if ( *((_DWORD *)v48 - 1) != 1427797680 )
              __break(0x8228u);
            v48(v8, 40);
          }
          else
          {
            readl_relaxed((unsigned int *)(v8[1] + 40));
          }
          raw_spin_unlock_irqrestore(v8 + 3, v42);
          v29 = 0;
        }
        goto LABEL_62;
      }
    }
    else
    {
      printk(&unk_A2FD, "cqhci_dma_map", *(unsigned int *)(v24 + 48), v28, a5);
      v29 = -12;
    }
  }
  else
  {
    v29 = -22;
  }
  v51 = *(_QWORD *)(a2 + 112);
  v52 = *(_QWORD *)(v51 + 120);
  if ( !v52 )
    v52 = *(_QWORD *)(v51 + 8);
  printk(&unk_9E4E, v52, "cqhci_prep_tran_desc", v29, a5);
  v55 = *(_QWORD *)(a1 + 120);
  if ( !v55 )
    v55 = *(_QWORD *)(a1 + 8);
  printk(&unk_9F3E, v55, v29, v53, v54);
LABEL_62:
  _ReadStatusReg(SP_EL0);
  return v29;
}
