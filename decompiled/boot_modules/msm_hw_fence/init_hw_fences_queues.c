__int64 __fastcall init_hw_fences_queues(__int64 a1, unsigned int a2, _QWORD *a3, __int64 a4, int a5, unsigned int a6)
{
  __int64 v6; // x30
  __int64 v7; // x19
  int v13; // w22
  unsigned int v14; // w23
  int v15; // w28
  unsigned int v16; // w20
  __int64 v17; // x8
  int v18; // w9
  int v19; // w10
  unsigned int v20; // w13
  int v21; // w14
  int v22; // w11
  char v23; // w8
  __int64 v24; // x3
  __int64 v25; // x4
  __int64 v26; // x8
  _DWORD *v27; // x27
  int v28; // w8
  int v29; // w8
  bool v30; // zf
  int v31; // w8
  int v32; // w9
  char v33; // w16
  const char *v34; // x4
  _DWORD *v35; // x23
  __int64 v36; // x8
  __int64 v37; // x10
  __int64 v38; // x7
  __int64 v39; // x6
  int v40; // w25
  unsigned int v41; // w19
  __int64 v42; // x8
  __int64 v43; // x9
  int v44; // w8
  int v45; // w8
  __int64 result; // x0
  __int64 v47; // x20
  const char *v48; // x3
  __int64 v49; // x25
  __int64 v50; // x21
  _DWORD *v51; // x23
  __int64 v52; // x24
  __int64 v53; // x8
  __int64 v54; // x10
  __int64 v55; // x9
  const char *v56; // x3
  __int64 v57; // x19
  __int64 v58; // x25
  const char *v59; // [xsp+18h] [xbp-38h]
  __int64 v60; // [xsp+20h] [xbp-30h]
  __int64 v61; // [xsp+20h] [xbp-30h]
  __int64 v62; // [xsp+2Ch] [xbp-24h]
  unsigned int v63; // [xsp+34h] [xbp-1Ch] BYREF
  __int64 v64; // [xsp+38h] [xbp-18h] BYREF
  _QWORD v65[2]; // [xsp+40h] [xbp-10h] BYREF

  v7 = a6;
  v65[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v64 = 0;
  v65[0] = 0;
  v63 = 0;
  if ( (~msm_hw_fence_debug_level & 0x10008) == 0 )
  {
    v47 = v6;
    printk(&unk_297A6, "init_hw_fences_queues", 115, a2, a6);
    v6 = v47;
  }
  v60 = v6;
  if ( a2 == 3 )
  {
    if ( *(_DWORD *)(a1 + 60) <= (unsigned int)v7 || (v17 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 16LL * (int)v7)) == 0 )
    {
      printk(&unk_21259, "init_hw_fences_queues", 126, v6, (unsigned int)v7);
      result = 4294967274LL;
      goto LABEL_51;
    }
    v14 = *(_DWORD *)(v17 + 28);
    if ( *(_BYTE *)(a1 + 33520) )
      v18 = 64;
    else
      v18 = 24;
    if ( *(_BYTE *)(a1 + 33520) )
      v19 = 192;
    else
      v19 = 56;
    v21 = *(_DWORD *)(v17 + 40);
    v20 = *(_DWORD *)(v17 + 44);
    v22 = *(_DWORD *)(v17 + 24);
    v16 = *(_DWORD *)(v17 + 32) + v14 + v18 + v19 * a5;
    v23 = *(_BYTE *)(v17 + 48);
    v13 = v22 << 6;
    if ( v20 <= 1 )
      v15 = 1;
    else
      v15 = v20;
    LODWORD(v62) = v21;
    BYTE4(v62) = v23;
  }
  else
  {
    if ( a2 )
    {
      printk(&unk_2452B, "init_hw_fences_queues", 142, v6, a2);
      result = 4294967274LL;
      goto LABEL_51;
    }
    v13 = *(_DWORD *)(a1 + 28);
    v14 = 0;
    v62 = 0;
    v15 = 1;
    if ( *(_BYTE *)(a1 + 33520) )
      v16 = 448;
    else
      v16 = 136;
  }
  if ( (unsigned int)hw_fence_utils_reserve_mem(a1, a2, &v64, v65, &v63, (unsigned int)v7) )
  {
    printk(&unk_297DB, "init_hw_fences_queues", 149, v60, a2);
    result = 4294967284LL;
    goto LABEL_51;
  }
  if ( (~msm_hw_fence_debug_level & 0x10008) == 0 )
    printk(&unk_23AA7, "init_hw_fences_queues", 152, v64, v65[0]);
  v26 = v64;
  v27 = (_DWORD *)v65[0];
  v61 = v7;
  a3[2] = v63;
  a3[3] = 0;
  *a3 = v27;
  a3[1] = v26;
  if ( (~msm_hw_fence_debug_level & 0x10008) == 0 )
  {
    printk(&unk_278A8, "init_hw_fences_queues", 161, v16, v14);
    v27 = (_DWORD *)v65[0];
  }
  *v27 = 0;
  v27[1] = v63;
  if ( *(_BYTE *)(a1 + 33520) )
    v28 = 64;
  else
    v28 = 24;
  v27[2] = v28 + v14;
  v29 = *(unsigned __int8 *)(a1 + 33520);
  v27[5] = a5;
  v30 = v29 == 0;
  v31 = msm_hw_fence_debug_level;
  if ( v30 )
    v32 = 56;
  else
    v32 = 192;
  v27[3] = v32;
  v27[4] = a5;
  if ( (~v31 & 0x10008) == 0 )
  {
    printk(&unk_25F98, "init_hw_fences_queues", 179, v24, v25);
    if ( a5 < 1 )
      goto LABEL_50;
LABEL_33:
    v33 = BYTE4(v62);
    if ( (v62 & 0x100000000LL) != 0 )
      v34 = "wr_idx=tx_wm";
    else
      v34 = "wr_idx";
    v35 = (_DWORD *)(v65[0] + (unsigned int)v27[2]);
    if ( (~msm_hw_fence_debug_level & 0x10008) == 0 )
    {
      v59 = v34;
      printk(&unk_27902, "init_hw_fences_queues", 183, 0, v34);
      v34 = v59;
      v33 = BYTE4(v62);
    }
    v36 = v64;
    v37 = v65[0];
    v35[3] = v13;
    v35[4] = 64;
    v38 = v36 + v16;
    v39 = v37 + v16;
    v35[1] = v38;
    v35[2] = 1;
    LODWORD(v36) = *(unsigned __int8 *)(a1 + 33520);
    v40 = v62;
    v41 = v15;
    v30 = (_DWORD)v36 == 0;
    v42 = 13;
    if ( v30 )
    {
      v43 = 12;
    }
    else
    {
      v42 = 32;
      v43 = 16;
    }
    if ( (_DWORD)v62 && !v35[v42] )
    {
      if ( (v33 & 1) != 0 )
        v35[7] = v62;
      v35[v43] = v62;
      v35[v42] = v62;
      if ( (~msm_hw_fence_debug_level & 0x10008) == 0 )
      {
        v57 = v38;
        v58 = v37 + v16;
        printk(&unk_2129F, "init_hw_fences_queues", 214, v61, v34);
        v39 = v58;
        v40 = v62;
        v38 = v57;
        v41 = v15;
      }
    }
    __dsb(0xEu);
    *(_QWORD *)a4 = v39;
    v44 = msm_hw_fence_debug_level;
    *(_QWORD *)(a4 + 16) = v35;
    *(_QWORD *)(a4 + 24) = v38;
    *(_DWORD *)(a4 + 8) = v13;
    if ( (~v44 & 0x10008) == 0 )
    {
      if ( v35[2] == 1 )
        v48 = "TX_QUEUE";
      else
        v48 = "RX_QUEUE";
      printk(&unk_2279B, "init_hw_fences_queues", 228, v48, v61);
    }
    v45 = msm_hw_fence_debug_level;
    *(_BYTE *)(a4 + 40) = BYTE4(v62) & 1;
    *(_DWORD *)(a4 + 32) = v40;
    *(_DWORD *)(a4 + 36) = v41;
    if ( (~v45 & 0x10008) != 0 )
    {
      if ( a5 == 1 )
        goto LABEL_50;
    }
    else
    {
      printk(&unk_23FF8, "init_hw_fences_queues", 240, *(unsigned int *)(a4 + 32), v41);
      v45 = msm_hw_fence_debug_level;
      if ( a5 == 1 )
        goto LABEL_50;
    }
    v49 = (unsigned int)a5;
    v50 = a4 + 88;
    v51 = (_DWORD *)((char *)v35 + (unsigned int)v27[3]);
    v52 = 1;
    do
    {
      if ( (~v45 & 0x10008) == 0 )
        printk(&unk_27902, "init_hw_fences_queues", 183, (unsigned int)v52, v34);
      v53 = v64;
      v54 = v65[0];
      v55 = v13 + v16;
      v51[3] = v13;
      v51[4] = 64;
      v51[1] = v53 + v55;
      v51[2] = 2;
      __dsb(0xEu);
      *(_QWORD *)(v50 - 40) = v54 + v55;
      *(_QWORD *)(v50 - 24) = v51;
      *(_QWORD *)(v50 - 16) = v53 + v55;
      *(_DWORD *)(v50 - 32) = v13;
      if ( (~msm_hw_fence_debug_level & 0x10008) == 0 )
      {
        if ( v51[2] == 1 )
          v56 = "TX_QUEUE";
        else
          v56 = "RX_QUEUE";
        printk(&unk_2279B, "init_hw_fences_queues", 228, v56, v61);
      }
      *(_DWORD *)(v50 - 4) = 1;
      v45 = msm_hw_fence_debug_level;
      if ( (~msm_hw_fence_debug_level & 0x10008) == 0 )
      {
        printk(&unk_23FF8, "init_hw_fences_queues", 240, *(unsigned int *)(v50 - 8), 1);
        v45 = msm_hw_fence_debug_level;
      }
      ++v52;
      v50 += 48;
      v16 += v13;
      v51 = (_DWORD *)((char *)v51 + (unsigned int)v27[3]);
    }
    while ( v49 != v52 );
    goto LABEL_50;
  }
  if ( a5 >= 1 )
    goto LABEL_33;
LABEL_50:
  result = 0;
LABEL_51:
  _ReadStatusReg(SP_EL0);
  return result;
}
