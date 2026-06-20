__int64 __fastcall msm_cvp_unmap_buf_wncc(__int64 a1, _DWORD *a2)
{
  __int64 result; // x0
  unsigned __int64 v3; // x9
  __int64 v4; // x2
  void *v5; // x0
  __int64 v6; // x1
  unsigned __int64 v7; // x8
  int v8; // w20
  unsigned __int64 v9; // x8
  unsigned __int64 StatusReg; // x8
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x23
  int *v16; // x9
  int v17; // w9
  __int64 v18; // x19
  _DWORD *v19; // x1
  unsigned __int64 v20; // x20
  int v21; // w8
  int v22; // w8
  __int64 v23; // x1
  unsigned int v24; // w0
  unsigned int v25; // w20
  unsigned __int64 v26; // x8
  unsigned __int64 v27; // x8
  unsigned __int64 v28; // x8
  __int64 v29; // x0
  __int64 v30; // x8
  int v31; // w9
  unsigned __int64 v32; // x8

  if ( !a1 || !a2 || !*(_QWORD *)(a1 + 128) )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      v6 = *(unsigned int *)(StatusReg + 1800);
      v4 = *(unsigned int *)(StatusReg + 1804);
      v5 = &unk_8B4A1;
      goto LABEL_19;
    }
    return result;
  }
  if ( *(_QWORD *)(a1 + 320) )
  {
    if ( *a2 )
    {
      result = 4294967274LL;
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v3 = _ReadStatusReg(SP_EL0);
        v4 = *(unsigned int *)(v3 + 1804);
        v5 = &unk_94526;
        v6 = *(unsigned int *)(v3 + 1800);
LABEL_19:
        printk(v5, v6, v4, &unk_8E7CE);
        return 4294967274LL;
      }
      return result;
    }
    v8 = a2[7];
    if ( (unsigned int)(v8 - 2401) < 0xFFFFF6A0 )
    {
      result = 4294967274LL;
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v9 = _ReadStatusReg(SP_EL0);
        v6 = *(unsigned int *)(v9 + 1800);
        v4 = *(unsigned int *)(v9 + 1804);
        v5 = &unk_8A02C;
        goto LABEL_19;
      }
      return result;
    }
    v13 = mutex_lock(a1 + 616);
    v14 = a1;
    if ( *(_DWORD *)(a1 + 12920) )
    {
      v15 = (unsigned int)(v8 - 1);
      v16 = (int *)(*(_QWORD *)(a1 + 12928) + 12LL * (unsigned int)v15);
      if ( v16[1] )
      {
        v17 = *v16;
        v18 = a1 + 600;
        a2[2] = v17;
        while ( 1 )
        {
          v18 = *(_QWORD *)v18;
          if ( v18 == a1 + 600 )
            break;
          if ( *(_DWORD *)(v18 + 16) == v17 )
          {
            v19 = *(_DWORD **)(v18 + 56);
            if ( v19[16] )
            {
              v20 = *(_QWORD *)(a1 + 6824);
              if ( v20 > 0x28 )
              {
                __break(0x5512u);
                return wncc_print_cvpwnccbufs_table(v13);
              }
              memcpy((void *)(a1 + 152 * v20 + 6840), v19, 0x98u);
              v21 = *(_DWORD *)(a1 + 6832);
              v22 = (unsigned int)(v21 + 1) < 8 ? v21 + 1 : 8;
              *(_DWORD *)(a1 + 6832) = v22;
              *(_QWORD *)(a1 + 6824) = ((_BYTE)v20 + 1) & 7;
              v23 = *(_QWORD *)(v18 + 56);
              if ( *(_DWORD *)(v23 + 64) )
              {
                v24 = msm_cvp_unmap_smem(a1, v23, (__int64)"unmap wncc");
                if ( v24 )
                {
                  if ( (msm_cvp_debug & 1) != 0 )
                  {
                    v25 = v24;
                    if ( !msm_cvp_debug_out )
                    {
                      v26 = _ReadStatusReg(SP_EL0);
                      printk(&unk_86E2C, *(unsigned int *)(v26 + 1800), *(unsigned int *)(v26 + 1804), &unk_8E7CE);
                    }
                  }
                  else
                  {
                    v25 = v24;
                  }
                  goto LABEL_51;
                }
                msm_cvp_smem_put_dma_buf(*(_QWORD *)(*(_QWORD *)(v18 + 56) + 48LL));
              }
            }
            v25 = 0;
LABEL_51:
            list_del(v18);
            v30 = a1;
            *(_DWORD *)(*(_QWORD *)(a1 + 12928) + 12 * v15) = 0;
            *(_DWORD *)(*(_QWORD *)(a1 + 12928) + 12 * v15 + 4) = 0;
            *(_DWORD *)(*(_QWORD *)(a1 + 12928) + 12 * v15 + 8) = 0;
            v31 = *(_DWORD *)(a1 + 12920) - 1;
            *(_DWORD *)(a1 + 12920) = v31;
            if ( !v31 )
            {
              kfree(*(_QWORD *)(a1 + 12928));
              v30 = a1;
              *(_QWORD *)(a1 + 12928) = 0;
            }
            mutex_unlock(v30 + 616);
            cvp_kmem_cache_free(cvp_driver + 120, *(_QWORD *)(v18 + 56));
            cvp_kmem_cache_free(cvp_driver + 104, v18);
            return v25;
          }
        }
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          v32 = _ReadStatusReg(SP_EL0);
          printk(&unk_87889, *(unsigned int *)(v32 + 1800), *(unsigned int *)(v32 + 1804), &unk_8E7CE);
        }
        print_client_buffer(1, (__int64)"msm_cvp_unmap_buf_wncc", a1, (__int64)a2);
        wncc_print_cvpwnccbufs_table(a1);
        v29 = a1 + 616;
        goto LABEL_48;
      }
      if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      {
LABEL_43:
        v29 = v14 + 616;
LABEL_48:
        mutex_unlock(v29);
        return 4294967274LL;
      }
      v28 = _ReadStatusReg(SP_EL0);
      printk(&unk_87889, *(unsigned int *)(v28 + 1800), *(unsigned int *)(v28 + 1804), &unk_8E7CE);
    }
    else
    {
      if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
        goto LABEL_43;
      v27 = _ReadStatusReg(SP_EL0);
      printk(&unk_94564, *(unsigned int *)(v27 + 1800), *(unsigned int *)(v27 + 1804), &unk_8E7CE);
    }
    v14 = a1;
    goto LABEL_43;
  }
  result = 4294967274LL;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v7 = _ReadStatusReg(SP_EL0);
    v6 = *(unsigned int *)(v7 + 1800);
    v4 = *(unsigned int *)(v7 + 1804);
    v5 = &unk_8D1CE;
    goto LABEL_19;
  }
  return result;
}
