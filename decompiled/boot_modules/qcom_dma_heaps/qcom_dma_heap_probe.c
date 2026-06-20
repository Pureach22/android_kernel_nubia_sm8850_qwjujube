__int64 __fastcall qcom_dma_heap_probe(__int64 a1)
{
  int *v2; // x0
  int *v3; // x19
  __int64 v4; // x25
  __int64 v5; // x26
  int v6; // w24
  __int64 v7; // x27
  int v8; // w2

  qcom_system_heap_create("qcom,system", "system", 0);
  qcom_secure_system_heap_create("qcom,secure-pixel", 0, 0x80000);
  qcom_secure_system_heap_create("qcom,secure-non-pixel", 0, 0x100000);
  v2 = (int *)parse_heap_dt(a1);
  v3 = v2;
  if ( v2 && (unsigned __int64)v2 <= 0xFFFFFFFFFFFFF000LL )
  {
    if ( *v2 >= 1 )
    {
      v4 = 0;
      v5 = 0;
      v6 = 0;
      while ( 1 )
      {
        v7 = *((_QWORD *)v3 + 1);
        v8 = *(_DWORD *)(v7 + v4);
        if ( v8 > 1 )
        {
          if ( v8 != 2 )
          {
            if ( v8 == 3 )
            {
              v6 = -22;
              goto LABEL_16;
            }
LABEL_13:
            printk(&unk_DB77, "qcom_dma_heap_probe");
            if ( !v6 )
              goto LABEL_18;
            goto LABEL_16;
          }
          v6 = qcom_add_cma_heap(v7 + v4);
          if ( !v6 )
          {
LABEL_18:
            printk(&unk_D8FF, "qcom_dma_heap_probe");
            goto LABEL_19;
          }
        }
        else
        {
          if ( v8 )
          {
            if ( v8 == 1 )
            {
              v6 = qcom_carveout_heap_create(v7 + v4);
              if ( !v6 )
                goto LABEL_18;
              goto LABEL_16;
            }
            goto LABEL_13;
          }
          v6 = qcom_secure_carveout_heap_create(v7 + v4);
          if ( !v6 )
            goto LABEL_18;
        }
LABEL_16:
        printk(&unk_E02C, "qcom_dma_heap_probe");
LABEL_19:
        ++v5;
        v4 += 56;
        if ( v5 >= *v3 )
          goto LABEL_22;
      }
    }
    v6 = 0;
LABEL_22:
    free_pdata(v3);
    LODWORD(v3) = v6;
    dma_buf_cached_fops = -22;
  }
  return (unsigned int)v3;
}
