__int64 __fastcall adreno_drawctxt_create(__int64 **a1, int *a2)
{
  __int64 *v2; // x19
  int v3; // w9
  int v4; // w10
  unsigned int v5; // w20
  unsigned __int64 v6; // x9
  bool v7; // cf
  char v8; // w9
  __int64 result; // x0
  _DWORD *v12; // x0
  _DWORD *v13; // x20
  int v14; // w8
  int v15; // w0
  int v16; // w21
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x8
  _DWORD *v20; // x8
  int v21; // w21
  __int64 v22; // x0
  __int64 v23; // x9
  __int64 v24; // x8
  unsigned __int64 v25; // x8
  unsigned __int64 v26; // x19
  __int64 v27; // x0

  v2 = *a1;
  v3 = *a2;
  if ( (*(_BYTE *)((*a1)[1783] + 32) & 4) != 0 || *((_BYTE *)*a1 + 20443) == 1 )
    v4 = 2146958042;
  else
    v4 = 1912077018;
  v5 = v3 & v4;
  if ( (~(v3 & v4) & 0x12) == 0 )
  {
    if ( v2 == (__int64 *)-56LL || *((_BYTE *)v2 + 96) != 1 )
    {
      v8 = 0;
      if ( (v5 & 0x20000) == 0 )
        goto LABEL_23;
    }
    else
    {
      v6 = v2[10];
      if ( v6 )
        v7 = v6 >= 0xFFFFFFFFFFFFF001LL;
      else
        v7 = 1;
      v8 = !v7;
      if ( (v5 & 0x20000) == 0 )
        goto LABEL_23;
    }
    if ( (v8 & 1) == 0 )
    {
      if ( (adreno_drawctxt_create___print_once_7 & 1) == 0 )
      {
        v27 = *v2;
        adreno_drawctxt_create___print_once_7 = 1;
        dev_err(v27, "Secure context not supported\n");
        return -95;
      }
      return -95;
    }
LABEL_23:
    if ( (v5 & 0x20000000) == 0 )
      goto LABEL_24;
    if ( ((*a1)[2555] & 1) != 0 )
    {
      if ( (v5 & 0x20000) == 0 )
      {
LABEL_24:
        v12 = (_DWORD *)_kmalloc_cache_noprof(socinfo_get_partinfo_vulkan_id, 3520, 2104);
        if ( !v12 )
          return -12;
        v12[98] = 0;
        v12[50] = v5 | 0x40;
        v12[100] = (v5 >> 20) & 0x1F;
        v12[101] = 0;
        v13 = v12;
        _init_waitqueue_head(v12 + 360, "&drawctxt->wq", &adreno_drawctxt_create___key);
        _init_waitqueue_head(v13 + 366, "&drawctxt->waiting", &adreno_drawctxt_create___key_17);
        _init_waitqueue_head(v13 + 372, "&drawctxt->timeout", &adreno_drawctxt_create___key_19);
        v14 = v13[50];
        if ( (v14 & 0xF000) == 0 )
        {
          v14 |= 0x8000u;
          v13[50] = v14;
        }
        v13[2] = (unsigned __int16)v14 >> 12;
        v15 = kgsl_context_init(a1);
        if ( v15 )
        {
          v16 = v15;
          kfree(v13);
          return v16;
        }
        else
        {
          kgsl_sharedmem_writel(v2[5], 40LL * (unsigned int)v13[1], 0);
          kgsl_sharedmem_writel(v2[5], 40LL * (unsigned int)v13[1] + 8, 0);
          adreno_context_debugfs_init(v2, v13);
          result = (__int64)v13;
          *((_QWORD *)v13 + 202) = v13 + 404;
          *((_QWORD *)v13 + 203) = v13 + 404;
          *((_QWORD *)v13 + 257) = v13 + 514;
          *((_QWORD *)v13 + 258) = v13 + 514;
          *((_QWORD *)v13 + 259) = v13 + 518;
          *((_QWORD *)v13 + 260) = v13 + 518;
          v19 = v2[2612];
          if ( !v19 )
            goto LABEL_43;
          v20 = *(_DWORD **)(v19 + 24);
          if ( !v20 )
            goto LABEL_43;
          if ( *(v20 - 1) != -1079776868 )
            __break(0x8228u);
          v21 = ((__int64 (__fastcall *)(__int64 *, _DWORD *))v20)(v2, v13);
          result = (__int64)v13;
          if ( v21 )
          {
            if ( (unsigned int)__ratelimit(&adreno_drawctxt_create__rs, "adreno_drawctxt_create") )
              dev_err(*v2, "Context initialization failed ret:%d\n", v21);
            kgsl_context_detach(v13);
            return v21;
          }
          else
          {
LABEL_43:
            v23 = *(_QWORD *)(result + 40);
            v24 = *(_QWORD *)(v23 + 14264);
            if ( ((*(_BYTE *)(v24 + 32) & 4) != 0 || *(_BYTE *)(v23 + 20443) == 1)
              && *(_DWORD *)v24 >= 0x258u
              && ((v25 = *(unsigned int *)(result + 200), (v25 & 0x20000000) != 0) || *(_DWORD *)(result + 8) >= 4u)
              && (v26 = gpumem_alloc_entry(
                          *(_QWORD *)(result + 16),
                          196608,
                          ((*(_QWORD *)_ReadStatusReg(SP_EL0) << 10) | (v25 >> 14)) & 0x100000008LL),
                  result = (__int64)v13,
                  *((_QWORD *)v13 + 34) = v26,
                  v26 >= 0xFFFFFFFFFFFFF001LL) )
            {
              *((_QWORD *)v13 + 34) = 0;
              kgsl_context_detach(v13);
              return (int)v26;
            }
            else
            {
              *a2 = *(_DWORD *)(result + 200);
            }
          }
        }
        return result;
      }
      if ( (adreno_drawctxt_create___print_once_11 & 1) == 0 )
      {
        v17 = *v2;
        adreno_drawctxt_create___print_once_11 = 1;
        dev_err(v17, "LPAC secure context not supported\n");
        return -95;
      }
    }
    else if ( (adreno_drawctxt_create___print_once_9 & 1) == 0 )
    {
      v18 = *v2;
      adreno_drawctxt_create___print_once_9 = 1;
      dev_err(v18, "LPAC context not supported\n");
      return -95;
    }
    return -95;
  }
  if ( (adreno_drawctxt_create___print_once & 1) == 0 )
  {
    v22 = *v2;
    adreno_drawctxt_create___print_once = 1;
    dev_err(v22, "legacy context switch not supported\n");
  }
  return -22;
}
