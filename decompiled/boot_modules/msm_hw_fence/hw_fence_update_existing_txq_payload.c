__int64 __fastcall hw_fence_update_existing_txq_payload(__int64 a1, unsigned int *a2, __int64 a3, int a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x8
  __int64 v7; // x10
  unsigned int v8; // w21
  bool v9; // zf
  int v10; // w9
  __int64 v11; // x11
  unsigned int v12; // w6
  __int64 v13; // x9
  unsigned int v14; // w19
  unsigned int v15; // w23
  unsigned int v16; // w5
  __int64 result; // x0
  unsigned int *v18; // x20
  __int64 v19; // x19
  unsigned int *v20; // x20
  __int64 v21; // x22
  int v22; // w25
  __int64 v23; // x26
  __int64 v24; // x4
  __int64 *v25; // x22
  __int64 v26; // x20
  unsigned int v27; // w21
  __int64 v28; // x4
  __int64 *v29; // x23
  __int64 v30; // x13
  __int64 v31; // x14
  __int64 v32; // x9
  __int64 v33; // x7
  __int64 v34; // x10
  __int64 v35; // x11
  __int64 v36; // x12
  __int64 v37; // x15
  __int64 v38; // x16
  __int64 v39; // x9
  unsigned int *v40; // x20
  __int64 v41; // x26
  int v42; // w27
  __int64 v43; // x28
  int v44; // w28
  __int64 v45; // x27
  unsigned int *v46; // x22
  unsigned int *v47; // [xsp+8h] [xbp-38h]
  __int64 v48; // [xsp+10h] [xbp-30h]
  __int64 v49; // [xsp+18h] [xbp-28h]
  __int64 v50; // [xsp+20h] [xbp-20h]
  __int64 v51; // [xsp+28h] [xbp-18h]
  __int64 v52; // [xsp+30h] [xbp-10h]

  _ReadStatusReg(SP_EL0);
  v6 = *((_QWORD *)a2 + 7);
  if ( !v6 )
  {
    v18 = a2;
    v19 = v5;
    printk(&unk_28147, "_get_update_queue_params", 371, v5, a5);
    printk(&unk_2ADAB, "hw_fence_update_existing_txq_payload", 591, v19, *v18);
    result = 4294967274LL;
    goto LABEL_34;
  }
  v7 = 48;
  v8 = a2[12];
  v9 = *(_BYTE *)(a1 + 33520) == 0;
  v10 = *((unsigned __int8 *)a2 + 80);
  __dsb(0xFu);
  if ( v9 )
  {
    v11 = 52;
  }
  else
  {
    v7 = 64;
    v11 = 128;
  }
  v12 = a2[19];
  v9 = v10 == 0;
  v13 = 28;
  v14 = *(_DWORD *)(v6 + v7);
  if ( v9 )
    v13 = v11;
  v15 = *(_DWORD *)(v6 + v13);
  if ( v12
    && ((v16 = a2[18], v12 != 1) || v16)
    && (v14 = (v14 - v16) * v12, v15 = (v15 - v16) * v12, (~msm_hw_fence_debug_level & 0x10010) == 0) )
  {
    v20 = a2;
    v21 = a3;
    v22 = a4;
    v23 = v5;
    printk(&unk_2B381, "_translate_queue_indexes_custom_to_default", 268, v14, v15);
    v5 = v23;
    a4 = v22;
    a2 = v20;
    a3 = v21;
    if ( v14 == v15 )
      goto LABEL_13;
  }
  else if ( v14 == v15 )
  {
LABEL_13:
    if ( (~msm_hw_fence_debug_level & 0x10010) == 0 )
      printk(&unk_22648, "hw_fence_update_existing_txq_payload", 606, a3, a5);
    result = 4294967274LL;
    goto LABEL_34;
  }
  v24 = *((_QWORD *)a2 + 5);
  v25 = (__int64 *)(v24 + 4LL * v14);
  if ( (~msm_hw_fence_debug_level & 0x10010) == 0 )
  {
    v40 = a2;
    v41 = a3;
    v42 = a4;
    v43 = v5;
    printk(&unk_2549E, "hw_fence_update_existing_txq_payload", 613, *a2, v24);
    v5 = v43;
    a4 = v42;
    a2 = v40;
    a3 = v41;
  }
  if ( v25[3] == a3 )
  {
    *((_DWORD *)v25 + 12) = a4;
  }
  else
  {
    v26 = a3;
    if ( v14 + 16 >= v8 >> 2 )
      v27 = 0;
    else
      v27 = v14 + 16;
    if ( v27 == v15 )
    {
      printk(&unk_26A9F, "hw_fence_update_existing_txq_payload", 627, v5, a3);
      result = 4294967274LL;
      goto LABEL_34;
    }
    v28 = *((_QWORD *)a2 + 5);
    v29 = (__int64 *)(v28 + 4LL * v27);
    if ( (~msm_hw_fence_debug_level & 0x10010) == 0 )
    {
      v47 = a2;
      v44 = a4;
      v45 = v5;
      printk(&unk_2549E, "hw_fence_update_existing_txq_payload", 635, *a2, v28);
      a2 = v47;
      v5 = v45;
      a4 = v44;
    }
    if ( v29[3] != v26 )
    {
      printk(&unk_2ADE4, "hw_fence_update_existing_txq_payload", 639, v5, v26);
      result = 4294967274LL;
      goto LABEL_34;
    }
    v31 = v29[4];
    v30 = v29[5];
    v52 = v25[7];
    v50 = v25[5];
    v51 = v25[6];
    v32 = v29[7];
    v48 = v25[3];
    v49 = v25[4];
    v25[6] = v29[6];
    v33 = v25[1];
    v34 = v25[2];
    v35 = *v29;
    v36 = v29[1];
    v37 = v29[2];
    v38 = v29[3];
    v25[7] = v32;
    v39 = *v25;
    v25[4] = v31;
    v25[5] = v30;
    *v25 = v35;
    v25[1] = v36;
    v25[2] = v37;
    v25[3] = v38;
    *((_DWORD *)v25 + 12) = a4;
    *v29 = v39;
    v29[1] = v33;
    v29[2] = v34;
    v29[3] = v48;
    v29[6] = v51;
    v29[7] = v52;
    v29[4] = v49;
    v29[5] = v50;
    if ( (~msm_hw_fence_debug_level & 0x10002) == 0 )
    {
      v46 = a2;
      printk(&unk_25A80, "hw_fence_update_existing_txq_payload", 651, *a2, v14);
      a2 = v46;
    }
  }
  __dsb(0xEu);
  if ( (~msm_hw_fence_debug_level & 0x10002) == 0 )
    printk(&unk_24F3D, "hw_fence_update_existing_txq_payload", 658, *a2, v14);
  result = 0;
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return result;
}
