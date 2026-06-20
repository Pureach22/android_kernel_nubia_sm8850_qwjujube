__int64 __fastcall hfi_context_register_0(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  __int64 v5; // x22
  unsigned int asid; // w0
  _QWORD *v7; // x23
  int v8; // w0
  _DWORD *v9; // x9
  int v10; // w9
  __int64 v11; // x8
  __int64 (__fastcall *v12)(_QWORD); // x8
  __int64 v13; // x0
  int v14; // w9
  int v15; // w0
  __int64 v16; // x9
  unsigned int v17; // w8
  __int64 v18; // x9
  __int64 v19; // x8
  unsigned int v20; // w0
  __int64 v21; // x0
  __int64 v22; // x1
  __int64 v23; // x2
  __int64 v24; // x9
  __int64 v25; // x9
  _DWORD *v26; // x8
  unsigned __int64 v27; // x10
  int v28; // w9
  unsigned int v29; // w10
  int v30; // w9
  int v32; // [xsp+Ch] [xbp-34h] BYREF
  unsigned int v33; // [xsp+10h] [xbp-30h]
  __int128 v34; // [xsp+14h] [xbp-2Ch]
  __int64 v35; // [xsp+24h] [xbp-1Ch]
  __int64 v36; // [xsp+2Ch] [xbp-14h]
  int v37; // [xsp+34h] [xbp-Ch]
  __int64 v38; // [xsp+38h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_BYTE *)(a2 + 288) & 1) != 0 )
  {
    LODWORD(v2) = 0;
LABEL_42:
    _ReadStatusReg(SP_EL0);
    return (unsigned int)v2;
  }
  v5 = *(_QWORD *)(*(_QWORD *)(a2 + 24) + 64LL);
  asid = kgsl_mmu_pagetable_get_asid(v5);
  v2 = asid;
  if ( (asid & 0x80000000) != 0 )
    goto LABEL_46;
  v32 = 128;
  if ( (adreno_hwsched_context_queue_enabled(a1) & 1) != 0 )
  {
    if ( (*(_QWORD *)(a1 + 22496) & 0x10) != 0 && !*(_DWORD *)(a2 + 2032) )
    {
      v7 = (_QWORD *)(a2 + 1848);
      v8 = gmu_core_alloc_kernel_block(a1, a2 + 1848, 4096, 4, 35);
      if ( v8 )
        goto LABEL_45;
    }
    if ( !*(_DWORD *)(a2 + 1824) )
    {
      v7 = (_QWORD *)(a2 + 1640);
      v8 = gmu_core_alloc_kernel_block(a1, a2 + 1640, 4096, 4, 35);
      if ( !v8 )
      {
        v9 = *(_DWORD **)(a2 + 1648);
        v9[1] = *(_DWORD *)(a2 + 1824) + 48;
        v9[2] = (unsigned __int64)(*(_QWORD *)(a2 + 1680) + 0x3FFFFFFD0LL) >> 2;
        v9[7] = *(_DWORD *)(a2 + 2032);
        v9[8] = *(_QWORD *)(a2 + 1888);
        goto LABEL_11;
      }
LABEL_45:
      LODWORD(v2) = v8;
      v7[24] = 0;
      v7[25] = 0;
      v7[22] = 0;
      v7[23] = 0;
      v7[20] = 0;
      v7[21] = 0;
      v7[18] = 0;
      v7[19] = 0;
      v7[16] = 0;
      v7[17] = 0;
      v7[14] = 0;
      v7[15] = 0;
      v7[12] = 0;
      v7[13] = 0;
      v7[10] = 0;
      v7[11] = 0;
      v7[8] = 0;
      v7[9] = 0;
      v7[6] = 0;
      v7[7] = 0;
      v7[4] = 0;
      v7[5] = 0;
      v7[2] = 0;
      v7[3] = 0;
      *v7 = 0;
      v7[1] = 0;
      goto LABEL_46;
    }
  }
LABEL_11:
  v10 = *(_DWORD *)(a2 + 200) | 0x20;
  v33 = *(_DWORD *)(a2 + 4);
  LODWORD(v34) = v10;
  if ( v5 && (v11 = *(_QWORD *)(v5 + 96)) != 0 && (v12 = *(__int64 (__fastcall **)(_QWORD))(v11 + 48)) != nullptr )
  {
    if ( *((_DWORD *)v12 - 1) != 1831526433 )
      __break(0x8228u);
    v13 = v12(v5);
  }
  else
  {
    v13 = 0;
  }
  v14 = *(_DWORD *)(a2 + 4);
  *(_QWORD *)((char *)&v34 + 4) = v13 | (v2 << 48);
  HIDWORD(v34) = v14;
  LODWORD(v35) = kgsl_mmu_pagetable_get_context_bank(v5, a2);
  v15 = gen7_hfi_send_cmd_async(a1, &v32, 0x1Cu);
  if ( v15 )
  {
    LODWORD(v2) = v15;
LABEL_46:
    dev_err(
      *(_QWORD *)(a1 + 1544) + 16LL,
      "Unable to register context %u: %d\n",
      *(unsigned int *)(a2 + 4),
      (unsigned int)v2);
LABEL_47:
    if ( *(_BYTE *)(a1 + 13192) == 1 )
      gen7_hwsched_fault(a1, 32);
    goto LABEL_42;
  }
  v16 = *(_QWORD *)(a1 + 40);
  v37 = 0;
  v17 = *(_DWORD *)(a2 + 4);
  v36 = 0;
  v35 = 0;
  v18 = *(_QWORD *)(v16 + 24) + 40LL * v17;
  v32 = 134;
  v33 = v17;
  v19 = *(_QWORD *)(a2 + 272);
  *(_QWORD *)&v34 = v18;
  *((_QWORD *)&v34 + 1) = v18 + 8;
  if ( v19 )
    v35 = *(_QWORD *)(v19 + 32);
  if ( (adreno_hwsched_context_queue_enabled(a1) & 1) != 0 )
    HIDWORD(v36) = *(_DWORD *)(a2 + 1824);
  v20 = gen7_hfi_send_cmd_async(a1, &v32, 0x2Cu);
  if ( v20 )
  {
    LODWORD(v2) = v20;
    dev_err(
      *(_QWORD *)(a1 + 1544) + 16LL,
      "Unable to register context %u pointers: %d\n",
      *(unsigned int *)(a2 + 4),
      v20);
    goto LABEL_47;
  }
  *(_BYTE *)(a2 + 288) = 1;
  v21 = adreno_hwsched_context_queue_enabled(a1);
  if ( (v21 & 1) != 0 )
  {
    LODWORD(v2) = 0;
    *(_DWORD *)(a2 + 292) = -1;
    goto LABEL_42;
  }
  if ( a2 && (*(_BYTE *)(a2 + 203) & 0x20) != 0 )
  {
    v24 = 4;
  }
  else
  {
    LODWORD(v24) = *(_DWORD *)(a2 + 8) >> 2;
    if ( (unsigned int)v24 >= 3 )
      v24 = 3;
    else
      v24 = (unsigned int)v24;
  }
  v25 = 12 * v24;
  v26 = (_DWORD *)((char *)&gen7_hfi_dqs_lpac + v25);
  if ( *(_BYTE *)(a1 + 20440) )
    v27 = 60;
  else
    v27 = 48;
  if ( !*(_BYTE *)(a1 + 20440) )
    v26 = (_DWORD *)((char *)&gen7_hfi_dqs + v25);
  if ( v27 > v25 + 4 && v27 > v25 + 8 && v27 > v25 + 4 && v27 > v25 + 8 )
  {
    v28 = v26[2];
    LODWORD(v2) = 0;
    v29 = (unsigned int)(v28 + 1) % *v26;
    v30 = v28 + v26[1];
    v26[2] = v29;
    *(_DWORD *)(a2 + 292) = v30;
    goto LABEL_42;
  }
  __break(1u);
  return process_hw_fence_queue(v21, v22, v23);
}
