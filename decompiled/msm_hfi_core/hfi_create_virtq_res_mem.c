__int64 __fastcall hfi_create_virtq_res_mem(unsigned int a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 *v5; // x19
  __int64 *v6; // x22
  __int64 *v7; // x26
  const char *v8; // x30
  const char *v9; // x23
  __int64 v11; // x26
  int v12; // w8
  int v13; // w9
  const char *v14; // x19
  unsigned int v15; // w20
  __int64 v16; // x21
  unsigned int v17; // w0
  int v18; // w8
  __int64 v19; // x19
  __int64 *v20; // x27
  __int64 v21; // x28
  unsigned __int64 v22; // x21
  unsigned int v23; // w0
  __int64 *v24; // x8
  __int64 v25; // x10
  __int64 v26; // x11
  int v28; // w8
  unsigned __int64 v29; // x21
  unsigned int v30; // w0
  __int64 v31; // x3
  __int64 v32; // x4
  const char *v33; // x30
  unsigned int v34; // w19
  void *v35; // x0
  __int64 v36; // x2
  const char *v37; // [xsp+8h] [xbp-8h]

  v9 = v8;
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( a1 >= 4 )
      goto LABEL_16;
  }
  else
  {
    v5 = (__int64 *)a1;
    printk(&unk_1E83A, "hfi_create_virtq_res_mem", 268, a4, a5);
    a1 = (unsigned int)v5;
    if ( (unsigned int)v5 >= 4 )
      goto LABEL_16;
  }
  v11 = a2 + 176LL * a1;
  v6 = *(__int64 **)(v11 + 104);
  v5 = *(__int64 **)(v11 + 112);
  v7 = (__int64 *)(v11 + 104);
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    goto LABEL_17;
  v12 = *((_DWORD *)v5 + 7);
  if ( !v12 )
    goto LABEL_18;
LABEL_5:
  a5 = *((unsigned int *)v5 + 8);
  if ( (unsigned int)(a5 - 1) < 3 )
  {
    v13 = dword_1FB98[(unsigned int)(a5 - 1)];
    if ( v12 == 1 )
      goto LABEL_19;
    a5 = *((unsigned int *)v5 + 14);
    if ( (unsigned int)(a5 - 1) <= 2 )
    {
      v13 += dword_1FB98[(unsigned int)(a5 - 1)];
      if ( v12 == 2 )
        goto LABEL_19;
      a5 = *((unsigned int *)v5 + 20);
      if ( (unsigned int)(a5 - 1) <= 2 )
      {
        v13 += dword_1FB98[(unsigned int)(a5 - 1)];
        if ( v12 != 3 )
        {
          a5 = *((unsigned int *)v5 + 26);
          if ( (unsigned int)(a5 - 1) <= 2 )
          {
            if ( v12 == 4 )
            {
              v13 += dword_1FB98[(unsigned int)(a5 - 1)];
              goto LABEL_19;
            }
            goto LABEL_16;
          }
          goto LABEL_14;
        }
        while ( 1 )
        {
LABEL_19:
          *((_DWORD *)v6 + 12) = v12;
          *((_DWORD *)v6 + 13) = v13;
          v16 = *((unsigned int *)v5 + 7);
          v6[12] += (v16 << 6) + 12;
          v17 = allocate_and_map(a2, v6 + 8);
          if ( v17 )
          {
            v15 = v17;
            v14 = v9;
            goto LABEL_33;
          }
          v18 = msm_hfi_core_debug_level;
          if ( (~msm_hfi_core_debug_level & 0x10008) == 0 )
          {
            printk(&unk_1C915, "hfi_create_vq_hdrs", 176, (unsigned int)v16, v6[8]);
            v18 = msm_hfi_core_debug_level;
          }
          *((_DWORD *)v6 + 14) = v16;
          if ( (~v18 & 0x10001) == 0 )
          {
            printk(&unk_1C28B, "hfi_create_vq_hdrs", 180, a4, a5);
            v18 = msm_hfi_core_debug_level;
          }
          v20 = (__int64 *)*v7;
          v19 = v7[1];
          v37 = v9;
          if ( (~v18 & 0x10001) != 0 )
          {
            if ( *((_DWORD *)v20 + 12) )
              goto LABEL_26;
          }
          else
          {
            printk(&unk_1E83A, "hfi_create_vq_buff_descs", 196, a4, a5);
            if ( *((_DWORD *)v20 + 12) )
            {
LABEL_26:
              v21 = 0;
              v22 = 0;
              v5 = (__int64 *)(v19 + 44);
              v9 = "hfi_create_vq_buff_descs";
              while ( v21 != 56 )
              {
                v6 = &v20[v21];
                get_queue_size_req(*(_DWORD *)v5 + *((_DWORD *)v5 - 1));
                v23 = allocate_and_map(a2, &v20[v21 + 17]);
                if ( v23 )
                {
                  v33 = v37;
                  v34 = v23;
                  v35 = &unk_1BC04;
                  v36 = 278;
LABEL_52:
                  printk(v35, "hfi_create_virtq_res_mem", v36, v33, a5);
                  return v34;
                }
                *((_DWORD *)v6 + 26) = v22;
                v24 = &v20[v21];
                v26 = *(__int64 *)((char *)v5 - 4);
                v25 = *(__int64 *)((char *)v5 + 4);
                *(__int64 *)((char *)v24 + 108) = *(__int64 *)((char *)v5 - 12);
                *(__int64 *)((char *)v24 + 124) = v25;
                *(__int64 *)((char *)v24 + 116) = v26;
                if ( (~msm_hfi_core_debug_level & 0x10008) == 0 )
                  printk(&unk_19127, "hfi_create_vq_buff_descs", 218, (unsigned int)v22, v6[17]);
                ++v22;
                v5 += 3;
                v21 += 14;
                if ( v22 >= *((unsigned int *)v20 + 12) )
                  goto LABEL_35;
              }
              goto LABEL_16;
            }
          }
LABEL_35:
          v28 = msm_hfi_core_debug_level;
          if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
          {
            printk(&unk_1C28B, "hfi_create_vq_buff_descs", 223, a4, a5);
            v28 = msm_hfi_core_debug_level;
          }
          v7 = (__int64 *)*v7;
          if ( (~v28 & 0x10001) != 0 )
          {
            if ( !*((_DWORD *)v7 + 12) )
              goto LABEL_46;
          }
          else
          {
            printk(&unk_1E83A, "hfi_create_vq_buffers", 238, a4, a5);
            if ( !*((_DWORD *)v7 + 12) )
            {
LABEL_46:
              if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
              {
                printk(&unk_1C28B, "hfi_create_vq_buffers", 259, a4, a5);
                if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
                  printk(&unk_1C28B, "hfi_create_virtq_res_mem", 288, v31, v32);
              }
              return 0;
            }
          }
          v29 = 0;
          v6 = (__int64 *)&unk_1D96A;
          v5 = v7 + 26;
          v9 = "hfi_create_vq_buffers";
          while ( v29 != 4 )
          {
            v30 = allocate_and_map(a2, v5 - 4);
            if ( v30 )
            {
              v33 = v37;
              v34 = v30;
              v35 = &unk_1D926;
              v36 = 284;
              goto LABEL_52;
            }
            if ( (~msm_hfi_core_debug_level & 0x10008) == 0 )
              printk(&unk_1D96A, "hfi_create_vq_buffers", 256, (unsigned int)v29, *(v5 - 4));
            ++v29;
            v5 += 14;
            if ( v29 >= *((unsigned int *)v7 + 12) )
              goto LABEL_46;
          }
LABEL_16:
          __break(0x5512u);
LABEL_17:
          printk(&unk_1E83A, "hfi_create_vq_hdrs", 143, a4, a5);
          v12 = *((_DWORD *)v5 + 7);
          if ( v12 )
            goto LABEL_5;
LABEL_18:
          v13 = 0;
        }
      }
    }
  }
LABEL_14:
  v14 = v9;
  printk(&unk_1AB3A, "hfi_create_vq_hdrs", 157, v9, a5);
  v15 = -22;
LABEL_33:
  printk(&unk_1C08C, "hfi_create_virtq_res_mem", 272, v14, a5);
  return v15;
}
