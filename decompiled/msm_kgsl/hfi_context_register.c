__int64 __fastcall hfi_context_register(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  __int64 v5; // x22
  unsigned int asid; // w0
  unsigned int v7; // w9
  int v8; // w10
  __int64 v9; // x8
  __int64 (__fastcall *v10)(_QWORD); // x8
  __int64 v11; // x0
  __int64 v12; // x9
  __int64 v13; // x8
  int v14; // w0
  __int64 v15; // x9
  unsigned int v16; // w8
  __int64 v17; // x9
  __int64 v18; // x8
  unsigned int v19; // w0
  unsigned int v20; // w8
  _DWORD *v21; // x8
  int v22; // w9
  unsigned int v23; // w10
  int v24; // w9
  int v26; // [xsp+Ch] [xbp-34h] BYREF
  unsigned int v27; // [xsp+10h] [xbp-30h]
  __int128 v28; // [xsp+14h] [xbp-2Ch]
  __int64 v29; // [xsp+24h] [xbp-1Ch]
  __int64 v30; // [xsp+2Ch] [xbp-14h]
  int v31; // [xsp+34h] [xbp-Ch]
  __int64 v32; // [xsp+38h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_BYTE *)(a2 + 288) & 1) != 0 )
  {
    LODWORD(v2) = 0;
LABEL_22:
    _ReadStatusReg(SP_EL0);
    return (unsigned int)v2;
  }
  v5 = *(_QWORD *)(*(_QWORD *)(a2 + 24) + 64LL);
  asid = kgsl_mmu_pagetable_get_asid(v5);
  v2 = asid;
  if ( (asid & 0x80000000) != 0 )
    goto LABEL_24;
  v7 = *(_DWORD *)(a2 + 4);
  v8 = *(_DWORD *)(a2 + 200);
  v26 = 128;
  v27 = v7;
  LODWORD(v28) = v8 | 0x20;
  if ( v5 && (v9 = *(_QWORD *)(v5 + 96)) != 0 && (v10 = *(__int64 (__fastcall **)(_QWORD))(v9 + 48)) != nullptr )
  {
    if ( *((_DWORD *)v10 - 1) != 1831526433 )
      __break(0x8228u);
    v11 = v10(v5);
  }
  else
  {
    v11 = 0;
  }
  v12 = *(_QWORD *)(a2 + 24);
  *(_QWORD *)((char *)&v28 + 4) = v11 | (v2 << 48);
  v13 = *(_QWORD *)(v12 + 8);
  if ( v13 )
    LODWORD(v13) = *(_DWORD *)(v13 + 112);
  HIDWORD(v28) = v13;
  LODWORD(v29) = kgsl_mmu_pagetable_get_context_bank(v5, a2);
  v14 = a6xx_hfi_send_cmd_async(a1, &v26, 0x1Cu);
  if ( v14 )
  {
    LODWORD(v2) = v14;
LABEL_24:
    dev_err(
      *(_QWORD *)(a1 + 1544) + 16LL,
      "Unable to register context %u: %d\n",
      *(unsigned int *)(a2 + 4),
      (unsigned int)v2);
    goto LABEL_26;
  }
  v15 = *(_QWORD *)(a1 + 40);
  v31 = 0;
  v16 = *(_DWORD *)(a2 + 4);
  v30 = 0;
  v29 = 0;
  v17 = *(_QWORD *)(v15 + 24) + 40LL * v16;
  v26 = 134;
  v27 = v16;
  v18 = *(_QWORD *)(a2 + 272);
  *(_QWORD *)&v28 = v17;
  *((_QWORD *)&v28 + 1) = v17 + 8;
  if ( v18 )
    v29 = *(_QWORD *)(v18 + 32);
  v19 = a6xx_hfi_send_cmd_async(a1, &v26, 0x2Cu);
  if ( v19 )
  {
    LODWORD(v2) = v19;
    dev_err(
      *(_QWORD *)(a1 + 1544) + 16LL,
      "Unable to register context %u pointers: %d\n",
      *(unsigned int *)(a2 + 4),
      v19);
LABEL_26:
    if ( *(_BYTE *)(a1 + 13192) == 1 )
      adreno_scheduler_fault(a1, 32);
    goto LABEL_22;
  }
  *(_BYTE *)(a2 + 288) = 1;
  if ( !a2 || (*(_BYTE *)(a2 + 203) & 0x20) == 0 )
  {
    LODWORD(v2) = 0;
    v20 = *(_DWORD *)(a2 + 8) >> 2;
    if ( v20 >= 3 )
      v20 = 3;
    v21 = (_DWORD *)((char *)&a6xx_hfi_dqs + 12 * v20);
    v22 = v21[2];
    v23 = (unsigned int)(v22 + 1) % *v21;
    v24 = v22 + v21[1];
    v21[2] = v23;
    *(_DWORD *)(a2 + 292) = v24;
    goto LABEL_22;
  }
  __break(1u);
  return populate_ibs();
}
