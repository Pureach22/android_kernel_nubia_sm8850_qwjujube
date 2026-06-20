__int64 __fastcall hfi_populate_virtq_res_mem(unsigned int a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x19
  __int64 v6; // x25
  __int64 v7; // x8
  __int64 v8; // x9
  __int64 v9; // x8
  __int64 v10; // x27
  __int64 v11; // x28
  unsigned int *v12; // x20
  int v13; // w0
  int v14; // w8
  __int64 v16; // x20
  __int64 v17; // x3
  __int64 v18; // x4

  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( a1 < 4 )
      goto LABEL_3;
  }
  else
  {
    v5 = a1;
    v16 = a2;
    printk(&unk_1E83A, "hfi_populate_virtq_res_mem", 424, a4, a5);
    a1 = v5;
    a2 = v16;
    if ( (unsigned int)v5 < 4 )
    {
LABEL_3:
      v7 = a2 + 176LL * a1;
      v6 = *(_QWORD *)(v7 + 104);
      v5 = *(_QWORD *)(v7 + 112);
      if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
        goto LABEL_4;
      goto LABEL_32;
    }
  }
LABEL_31:
  __break(0x5512u);
LABEL_32:
  printk(&unk_1E83A, "hfi_populate_vq_hdrs", 384, a4, a5);
LABEL_4:
  v8 = *(_QWORD *)(v6 + 72);
  v9 = *(unsigned int *)(v6 + 48);
  *(_QWORD *)v8 = *(unsigned int *)(v5 + 12);
  *(_DWORD *)(v8 + 8) = v9;
  if ( (_DWORD)v9 )
  {
    v10 = 0;
    v5 = 0;
    v11 = 112 * v9;
    v12 = (unsigned int *)(*(_QWORD *)(v6 + 72) + 20LL);
    do
    {
      if ( v10 == 448 )
        goto LABEL_31;
      *(v12 - 2) = *(_DWORD *)(v6 + v10 + 104);
      *(v12 - 1) = *(_DWORD *)(v6 + v10 + 112);
      *v12 = *(_DWORD *)(v6 + v10 + 108);
      v13 = *(_DWORD *)(v6 + v10 + 120) + *(_DWORD *)(v6 + v10 + 116);
      v12[1] = v13;
      v12[2] = *(_QWORD *)(v6 + v10 + 152);
      v12[3] = *(_DWORD *)(v6 + v10 + 156);
      v12[4] = 4096;
      v12[5] = get_queue_size_req(v13);
      v14 = msm_hfi_core_debug_level;
      if ( (~msm_hfi_core_debug_level & 0x10008) != 0
        || (printk(&unk_1C437, "_dbg_dump_virtq_header", 358, (unsigned int)v5, v12 - 2),
            v14 = msm_hfi_core_debug_level,
            (~msm_hfi_core_debug_level & 0x10008) != 0) )
      {
        if ( (~v14 & 0x10008) != 0 )
          goto LABEL_10;
      }
      else
      {
        printk(&unk_19963, "_dbg_dump_virtq_header", 359, *(v12 - 2), a5);
        v14 = msm_hfi_core_debug_level;
        if ( (~msm_hfi_core_debug_level & 0x10008) != 0 )
        {
LABEL_10:
          if ( (~v14 & 0x10008) != 0 )
            goto LABEL_11;
          goto LABEL_21;
        }
      }
      printk(&unk_1D6C6, "_dbg_dump_virtq_header", 360, *(v12 - 1), a5);
      v14 = msm_hfi_core_debug_level;
      if ( (~msm_hfi_core_debug_level & 0x10008) != 0 )
      {
LABEL_11:
        if ( (~v14 & 0x10008) != 0 )
          goto LABEL_12;
        goto LABEL_22;
      }
LABEL_21:
      printk(&unk_1C988, "_dbg_dump_virtq_header", 361, *v12, a5);
      v14 = msm_hfi_core_debug_level;
      if ( (~msm_hfi_core_debug_level & 0x10008) != 0 )
      {
LABEL_12:
        if ( (~v14 & 0x10008) != 0 )
          goto LABEL_13;
        goto LABEL_23;
      }
LABEL_22:
      printk(&unk_19D8D, "_dbg_dump_virtq_header", 362, v12[1], a5);
      v14 = msm_hfi_core_debug_level;
      if ( (~msm_hfi_core_debug_level & 0x10008) != 0 )
      {
LABEL_13:
        if ( (~v14 & 0x10008) != 0 )
          goto LABEL_14;
        goto LABEL_24;
      }
LABEL_23:
      printk(&unk_1F567, "_dbg_dump_virtq_header", 363, v12[3], a5);
      v14 = msm_hfi_core_debug_level;
      if ( (~msm_hfi_core_debug_level & 0x10008) != 0 )
      {
LABEL_14:
        if ( (~v14 & 0x10008) != 0 )
          goto LABEL_15;
        goto LABEL_25;
      }
LABEL_24:
      printk(&unk_1F567, "_dbg_dump_virtq_header", 364, v12[2], a5);
      v14 = msm_hfi_core_debug_level;
      if ( (~msm_hfi_core_debug_level & 0x10008) != 0 )
      {
LABEL_15:
        if ( (~v14 & 0x10008) == 0 )
          goto LABEL_26;
        goto LABEL_16;
      }
LABEL_25:
      printk(&unk_1B1BD, "_dbg_dump_virtq_header", 365, v12[4], a5);
      v14 = msm_hfi_core_debug_level;
      if ( (~msm_hfi_core_debug_level & 0x10008) == 0 )
      {
LABEL_26:
        printk(&unk_1A360, "_dbg_dump_virtq_header", 366, v12[5], a5);
        if ( (~msm_hfi_core_debug_level & 0x10008) != 0 )
          goto LABEL_6;
LABEL_17:
        printk(&unk_1BC4D, "_dbg_dump_virtq_header", 367, (unsigned int)v5, a5);
        goto LABEL_6;
      }
LABEL_16:
      if ( (~v14 & 0x10008) == 0 )
        goto LABEL_17;
LABEL_6:
      v10 += 112;
      v5 = (unsigned int)(v5 + 1);
      v12 += 16;
    }
    while ( v11 != v10 );
  }
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    printk(&unk_1C28B, "hfi_populate_vq_hdrs", 415, a4, a5);
    if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
      printk(&unk_1C28B, "hfi_populate_virtq_res_mem", 432, v17, v18);
  }
  return 0;
}
