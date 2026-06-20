__int64 __fastcall msm_vidc_memory_alloc_map_ext(__int64 a1, __int64 a2)
{
  __int64 v3; // x24
  const char *v4; // x20
  unsigned __int64 v5; // x0
  unsigned __int64 v6; // x0
  char v7; // w8
  __int64 v8; // x4
  __int64 result; // x0
  void *v10; // x0
  int v11; // w9
  char v12; // w8
  int v13; // w20
  char v14; // w0
  void *v15; // x0
  unsigned __int64 context_bank_for_region; // x0
  __int64 *v17; // x2
  unsigned __int64 v18; // x0
  __int64 v19; // x4
  unsigned __int64 v20; // x20
  __int64 v21; // x0
  unsigned __int64 v22; // x8
  unsigned __int64 v23; // x0
  __int64 v24; // x9
  int v25; // w22
  __int64 v26; // x8
  void (__fastcall *v27)(__int64, __int64, unsigned __int64); // x8
  __int64 v28; // x1

  _ReadStatusReg(SP_EL0);
  if ( a2 )
  {
    if ( (*(_BYTE *)(a2 + 28) & 1) == 0 )
      goto LABEL_3;
    v8 = *(unsigned int *)(a2 + 20);
    switch ( (_DWORD)v8 )
    {
      case 0x40:
        v3 = a1;
        v4 = "qcom,secure-pixel";
        goto LABEL_4;
      case 0x20:
LABEL_3:
        v3 = a1;
        v4 = "qcom,system";
LABEL_4:
        v5 = dma_heap_find(v4);
        if ( !v5 || v5 >= 0xFFFFFFFFFFFFF001LL )
        {
          if ( (msm_vidc_debug & 1) != 0 )
            printk(&unk_7FB21, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_memory_alloc_ext");
          goto LABEL_24;
        }
        v6 = dma_heap_buffer_alloc();
        *(_QWORD *)(a2 + 32) = v6;
        if ( !v6 || v6 >= 0xFFFFFFFFFFFFF001LL )
        {
          if ( (msm_vidc_debug & 1) != 0 )
            printk(&unk_94B80, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_memory_alloc_ext");
          *(_QWORD *)(a2 + 32) = 0;
          goto LABEL_24;
        }
        v7 = *(_BYTE *)(a2 + 28);
        if ( (v7 & 1) != 0 && *(_DWORD *)(a2 + 16) == 7 )
        {
          if ( (unsigned int)mem_buf_lend() )
          {
            if ( (msm_vidc_debug & 1) != 0 )
              printk(&unk_93DB8, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_memory_alloc_ext");
LABEL_24:
            msm_vidc_memory_free_ext(a2);
            goto LABEL_25;
          }
          v7 = *(_BYTE *)(a2 + 28);
          v6 = *(_QWORD *)(a2 + 32);
        }
        if ( (v7 & 2) != 0 )
        {
          dma_buf_begin_cpu_access(v6, 0);
          if ( (unsigned int)dma_buf_vmap_unlocked(*(_QWORD *)(a2 + 32), a2 + 40) )
          {
            if ( (msm_vidc_debug & 1) != 0 )
              printk(&unk_9000D, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_memory_alloc_ext");
            goto LABEL_24;
          }
          *(_QWORD *)(a2 + 56) = *(_QWORD *)(a2 + 40);
        }
        if ( (msm_vidc_debug & 2) != 0 )
        {
          buf_name(*(_DWORD *)(a2 + 16));
          printk(&unk_89347, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_memory_alloc_ext");
        }
        buf_name(*(_DWORD *)(a2 + 16));
        v11 = *(_DWORD *)(a2 + 80);
        if ( v11 )
          goto LABEL_42;
        v13 = *(_DWORD *)(a2 + 20) & 0xE;
        v14 = mem_buf_dma_buf_exclusive_owner(*(_QWORD *)(a2 + 32));
        if ( v13 )
        {
          if ( (v14 & 1) == 0 )
          {
            if ( (msm_vidc_debug & 1) != 0 )
            {
              v15 = &unk_876EA;
LABEL_52:
              printk(v15, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_memory_map_ext");
              goto LABEL_85;
            }
            goto LABEL_85;
          }
        }
        else if ( (v14 & 1) != 0 )
        {
          if ( (msm_vidc_debug & 1) != 0 )
          {
            v15 = &unk_8AA92;
            goto LABEL_52;
          }
LABEL_85:
          if ( (msm_vidc_debug & 1) == 0 )
            goto LABEL_26;
          v10 = &unk_926CA;
          goto LABEL_32;
        }
        context_bank_for_region = msm_vidc_get_context_bank_for_region(v3, *(_DWORD *)(a2 + 20));
        if ( !context_bank_for_region || (v17 = *(__int64 **)(context_bank_for_region + 24)) == nullptr )
        {
          if ( (msm_vidc_debug & 1) != 0 )
            printk(&unk_8B6CC, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_memory_map_ext");
          goto LABEL_85;
        }
        v18 = msm_vidc_dma_buf_attach_ext(v3, *(_QWORD *)(a2 + 32), v17, (*(_BYTE *)(a2 + 28) & 4) != 0);
        v20 = v18;
        if ( !v18 || v18 >= 0xFFFFFFFFFFFFF001LL )
        {
          if ( v18 )
            v25 = v18;
          else
            v25 = -12;
          if ( (msm_vidc_debug & 1) != 0 )
          {
            printk(&unk_8B772, "err ", 0xFFFFFFFFLL, "codec", v19);
            goto LABEL_85;
          }
          goto LABEL_84;
        }
        v21 = v3;
        if ( v3 )
        {
          v22 = *(_QWORD *)(v3 + 6568);
          if ( v22 )
          {
            v22 = *(_QWORD *)(v22 + 40);
            if ( v22 )
            {
              if ( *(_DWORD *)(v22 - 4) != 1483727994 )
                __break(0x8228u);
              v23 = ((__int64 (__fastcall *)(__int64, unsigned __int64))v22)(v3, v20);
              v22 = v23;
              if ( v23 && v23 < 0xFFFFFFFFFFFFF001LL )
              {
                v24 = *(_QWORD *)(*(_QWORD *)v23 + 16LL);
                *(_QWORD *)(a2 + 88) = v23;
                *(_QWORD *)(a2 + 96) = v20;
                *(_QWORD *)(a2 + 64) = v24;
                v11 = *(_DWORD *)(a2 + 80);
LABEL_42:
                v12 = msm_vidc_debug;
                *(_DWORD *)(a2 + 80) = v11 + 1;
                if ( (v12 & 4) != 0 )
                {
                  buf_name(*(_DWORD *)(a2 + 16));
                  printk(&unk_806EB, "low ", 0xFFFFFFFFLL, "codec", "msm_vidc_memory_map_ext");
                }
                goto LABEL_44;
              }
              v21 = v3;
            }
          }
        }
        else
        {
          v22 = 0;
        }
        if ( v22 )
          v25 = v22;
        else
          v25 = -12;
        if ( (msm_vidc_debug & 1) != 0 )
        {
          printk(&unk_96513, "err ", 0xFFFFFFFFLL, "codec", v19);
          v21 = v3;
          if ( !v3 )
            goto LABEL_84;
        }
        else if ( !v21 )
        {
          goto LABEL_84;
        }
        v26 = *(_QWORD *)(v21 + 6568);
        if ( v26 )
        {
          v27 = *(void (__fastcall **)(__int64, __int64, unsigned __int64))(v26 + 32);
          if ( v27 )
          {
            v28 = *(_QWORD *)(a2 + 32);
            if ( *((_DWORD *)v27 - 1) != 248590048 )
              __break(0x8228u);
            v27(v21, v28, v20);
          }
        }
LABEL_84:
        if ( !v25 )
        {
LABEL_44:
          result = 0;
          goto LABEL_27;
        }
        goto LABEL_85;
      case 0x10:
        v3 = a1;
        v4 = "qcom,secure-non-pixel";
        goto LABEL_4;
    }
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_931A9, "err ", 0xFFFFFFFFLL, "codec", v8);
  }
  else if ( (msm_vidc_debug & 1) != 0 )
  {
    printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_memory_alloc_ext");
  }
LABEL_25:
  if ( (msm_vidc_debug & 1) != 0 )
  {
    v10 = &unk_8FFD9;
LABEL_32:
    printk(v10, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_memory_alloc_map_ext");
  }
LABEL_26:
  result = 4294967274LL;
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
