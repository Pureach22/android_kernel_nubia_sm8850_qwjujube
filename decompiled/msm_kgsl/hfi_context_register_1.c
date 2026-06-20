__int64 __fastcall hfi_context_register_1(__int64 a1, __int64 a2)
{
  __int64 v2; // x25
  _BYTE *v4; // x24
  __int64 v6; // x22
  unsigned int asid; // w0
  __int64 v8; // x21
  _QWORD *v9; // x23
  int v10; // w0
  _DWORD *v11; // x9
  int v12; // w9
  __int64 v13; // x8
  __int64 (__fastcall *v14)(_QWORD); // x8
  __int64 v15; // x0
  int v16; // w9
  int v17; // w0
  __int64 v18; // x0
  unsigned __int64 v19; // x9
  int v20; // w8
  unsigned int v21; // w8
  __int64 v22; // x10
  __int64 v23; // x9
  __int64 v24; // x9
  unsigned __int64 v25; // x11
  __int64 v26; // x8
  unsigned int v27; // w0
  __int64 v29; // [xsp+8h] [xbp-38h] BYREF
  _BYTE v30[24]; // [xsp+10h] [xbp-30h]
  int v31; // [xsp+28h] [xbp-18h]
  int v32; // [xsp+2Ch] [xbp-14h]
  int v33; // [xsp+30h] [xbp-10h]
  __int64 v34; // [xsp+38h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_BYTE *)(a2 + 288) & 1) != 0 )
  {
LABEL_30:
    LODWORD(v8) = 0;
    goto LABEL_31;
  }
  v2 = *(_QWORD *)(a2 + 24);
  v4 = (_BYTE *)(a1 + 13192);
  *(_QWORD *)&v30[12] = 0;
  v6 = *(_QWORD *)(v2 + 64);
  *(_QWORD *)&v30[4] = 0;
  asid = kgsl_mmu_pagetable_get_asid(v6);
  v8 = asid;
  if ( (asid & 0x80000000) != 0 )
    goto LABEL_35;
  LODWORD(v29) = 128;
  if ( (*(_QWORD *)(a1 + 22496) & 0x10) != 0 && !*(_DWORD *)(a2 + 2032) )
  {
    v9 = (_QWORD *)(a2 + 1848);
    v10 = gmu_core_alloc_kernel_block(a1, a2 + 1848, 4096, 4, 35);
    if ( v10 )
      goto LABEL_34;
  }
  if ( !*(_DWORD *)(a2 + 1824) )
  {
    v9 = (_QWORD *)(a2 + 1640);
    v10 = gmu_core_alloc_kernel_block(a1, a2 + 1640, 4096, 4, 35);
    if ( !v10 )
    {
      v11 = *(_DWORD **)(a2 + 1648);
      v11[1] = *(_DWORD *)(a2 + 1824) + 48;
      v11[2] = (unsigned __int64)(*(_QWORD *)(a2 + 1680) + 0x3FFFFFFD0LL) >> 2;
      v11[7] = *(_DWORD *)(a2 + 2032);
      v11[8] = *(_QWORD *)(a2 + 1888);
      goto LABEL_9;
    }
LABEL_34:
    LODWORD(v8) = v10;
    v9[24] = 0;
    v9[25] = 0;
    v9[22] = 0;
    v9[23] = 0;
    v9[20] = 0;
    v9[21] = 0;
    v9[18] = 0;
    v9[19] = 0;
    v9[16] = 0;
    v9[17] = 0;
    v9[14] = 0;
    v9[15] = 0;
    v9[12] = 0;
    v9[13] = 0;
    v9[10] = 0;
    v9[11] = 0;
    v9[8] = 0;
    v9[9] = 0;
    v9[6] = 0;
    v9[7] = 0;
    v9[4] = 0;
    v9[5] = 0;
    v9[2] = 0;
    v9[3] = 0;
    *v9 = 0;
    v9[1] = 0;
    goto LABEL_35;
  }
LABEL_9:
  v12 = *(_DWORD *)(a2 + 200) | 0x20;
  HIDWORD(v29) = *(_DWORD *)(a2 + 4);
  *(_DWORD *)v30 = v12;
  if ( v6 && (v13 = *(_QWORD *)(v6 + 96)) != 0 && (v14 = *(__int64 (__fastcall **)(_QWORD))(v13 + 48)) != nullptr )
  {
    if ( *((_DWORD *)v14 - 1) != 1831526433 )
      __break(0x8228u);
    v15 = v14(v6);
  }
  else
  {
    v15 = 0;
  }
  v16 = *(_DWORD *)(a2 + 4);
  *(_QWORD *)&v30[4] = v15 | (v8 << 48);
  *(_DWORD *)&v30[12] = v16;
  *(_DWORD *)&v30[16] = kgsl_mmu_pagetable_get_context_bank(v6, a2);
  v17 = gen8_hfi_send_cmd_async(a1, (int *)&v29, 0x1Cu);
  if ( v17 )
  {
    LODWORD(v8) = v17;
LABEL_35:
    dev_err(
      *(_QWORD *)(a1 + 1544) + 16LL,
      "Unable to register context %u: %d\n",
      *(unsigned int *)(a2 + 4),
      (unsigned int)v8);
    goto LABEL_36;
  }
  if ( *(_BYTE *)(a1 + 24528) == 1 && *(_BYTE *)(v2 + 689) == 1 && *(_BYTE *)(v2 + 688) == 1 )
  {
    v18 = to_gen8_gmu(a1);
    v19 = *(_QWORD *)(v2 + 736);
    v20 = *(_DWORD *)(v2 + 880);
    if ( (*(_QWORD *)(v18 + 1040) & 2) != 0 )
    {
      v29 = 201;
      *(_DWORD *)v30 = 2;
      *(_DWORD *)&v30[4] = v20 + (v19 >> 1);
      *(_DWORD *)&v30[8] = v20;
      if ( !(unsigned int)gen8_hfi_send_cmd_async(a1, (int *)&v29, 0x14u) )
        *(_WORD *)(v2 + 688) = 257;
    }
  }
  v21 = *(_DWORD *)(a2 + 4);
  v22 = *(_QWORD *)(a2 + 24);
  v23 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 24LL);
  LODWORD(v29) = 134;
  HIDWORD(v29) = v21;
  v24 = v23 + 40LL * v21;
  v25 = *(_QWORD *)(v22 + 736);
  LODWORD(v22) = *(_DWORD *)(v22 + 880);
  v26 = *(_QWORD *)(a2 + 272);
  *(_QWORD *)v30 = v24;
  *(_OWORD *)&v30[8] = (unsigned __int64)(v24 + 8);
  v31 = 1;
  v33 = v22 + (v25 >> 1);
  if ( v26 )
    *(_QWORD *)&v30[16] = *(_QWORD *)(v26 + 32);
  v32 = *(_DWORD *)(a2 + 1824);
  v27 = gen8_hfi_send_cmd_async(a1, (int *)&v29, 0x2Cu);
  if ( !v27 )
  {
    *(_BYTE *)(a2 + 288) = 1;
    *(_DWORD *)(a2 + 292) = -1;
    if ( (v4[1040] & 1) == 0 && *(_DWORD *)(a2 + 208) && (*(_BYTE *)(a2 + 201) & 8) != 0 )
      gen8_hwsched_set_pwrconstraint(a1, *(_DWORD *)(a2 + 4));
    goto LABEL_30;
  }
  LODWORD(v8) = v27;
  dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "Unable to register context %u pointers: %d\n", *(unsigned int *)(a2 + 4), v27);
LABEL_36:
  if ( *v4 == 1 )
    gen8_hwsched_fault(a1, 32);
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v8;
}
