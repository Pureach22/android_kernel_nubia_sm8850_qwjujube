__int64 __fastcall msm_cvp_vm_init_reg_and_irq(__int64 a1, unsigned __int64 *a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  __int64 v7; // x13
  unsigned __int64 v8; // x9
  unsigned __int64 v9; // x12
  unsigned __int64 v10; // x8
  __int64 v11; // x14
  unsigned __int64 v12; // x10
  unsigned __int64 v13; // x11
  unsigned __int64 v14; // x13
  unsigned __int64 StatusReg; // x8
  void *v16; // x0
  bool v17; // w14
  __int64 v18; // x21
  int v19; // w9
  unsigned __int64 v20; // x1
  unsigned __int64 v21; // x10
  __int64 v22; // x2
  __int64 v23; // x0
  __int64 v24; // x0
  int v25; // w5
  __int64 v26; // x0
  unsigned __int64 v27; // x1
  __int64 v28; // x0
  int v29; // w5
  int v30; // w0
  int v31; // w0
  int v32; // w8
  unsigned int v33; // w19
  unsigned __int64 v34; // x8
  unsigned __int64 v35; // x8
  unsigned __int64 v36; // x8
  unsigned __int64 v37; // x9
  int v38; // w19
  int v39; // w19
  unsigned __int64 v40; // x8
  unsigned __int64 v41; // x8

  if ( dword_199A4 == 2 )
    return 0;
  if ( a1 )
  {
    v7 = *(_QWORD *)(a1 + 2168);
    if ( v7 )
    {
      if ( *(_DWORD *)v7 == *((_DWORD *)a2 + 36) )
      {
        v8 = *a2;
        v9 = a2[1];
        v10 = *(_QWORD *)(v7 + 8);
        v11 = *((unsigned int *)a2 + 8);
        v12 = v10 + 10485760;
        if ( v10 <= *a2 && v12 > v8 )
          goto LABEL_13;
        if ( (v13 = v8 + 10485760, v10 >= v8) && v10 < v13
          || (v14 = *(_QWORD *)(v7 + 16), v14 <= v9) && v14 + v11 > v9
          || (v14 < v9 + v11 ? (v17 = v14 >= v9) : (v17 = 0),
              v14 == v9 || v17 || v10 <= v8 && v12 >= v13 || v10 >= v8 && v13 >= v12) )
        {
LABEL_13:
          result = 4294967279LL;
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            StatusReg = _ReadStatusReg(SP_EL0);
            printk(&unk_960AB, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
            return 4294967279LL;
          }
          return result;
        }
      }
      if ( (msm_cvp_debug & 4) != 0 && !msm_cvp_debug_out )
      {
        v16 = &unk_89265;
        goto LABEL_31;
      }
    }
  }
  else if ( (msm_cvp_debug & 4) != 0 && !msm_cvp_debug_out )
  {
    v16 = &unk_96156;
LABEL_31:
    printk(v16, "info", a3, a4);
  }
  v18 = _kmalloc_cache_noprof(_kmem_cache_create_args, 3520, 48);
  if ( !v18 )
  {
    result = 4294967284LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v41 = _ReadStatusReg(SP_EL0);
      printk(&unk_960DF, *(unsigned int *)(v41 + 1800), *(unsigned int *)(v41 + 1804), &unk_8E7CE);
      return 4294967284LL;
    }
    return result;
  }
  v19 = *((_DWORD *)a2 + 37);
  v21 = *a2;
  v20 = a2[1];
  v22 = *((unsigned int *)a2 + 8);
  v23 = a2[32] + 16;
  *(_DWORD *)v18 = *((_DWORD *)a2 + 36);
  *(_DWORD *)(v18 + 4) = v19;
  *(_QWORD *)(v18 + 8) = v21;
  v24 = devm_ioremap(v23, v20, v22);
  v25 = *((_DWORD *)a2 + 8);
  *(_QWORD *)(v18 + 16) = v24;
  *(_DWORD *)(v18 + 40) = v25;
  if ( !v24 )
  {
    v32 = -22;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v34 = _ReadStatusReg(SP_EL0);
      printk(&unk_96BDB, *(unsigned int *)(v34 + 1800), *(unsigned int *)(v34 + 1804), &unk_8E7CE);
      v32 = -22;
    }
    goto LABEL_50;
  }
  v26 = devm_ioremap(a2[32] + 16, 32768000, 786432);
  *(_QWORD *)(v18 + 32) = v26;
  if ( v26 || (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
  {
    v27 = a2[3];
    if ( !v27 )
      goto LABEL_42;
  }
  else
  {
    v35 = _ReadStatusReg(SP_EL0);
    printk(&unk_82C70, *(unsigned int *)(v35 + 1800), *(unsigned int *)(v35 + 1804), &unk_8E7CE);
    v27 = a2[3];
    if ( !v27 )
      goto LABEL_42;
  }
  v28 = devm_ioremap(a2[32] + 16, v27, *((unsigned int *)a2 + 10));
  v29 = *((_DWORD *)a2 + 10);
  *(_QWORD *)(v18 + 24) = v28;
  *(_DWORD *)(v18 + 44) = v29;
  if ( !v28 && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v36 = _ReadStatusReg(SP_EL0);
    printk(&unk_9768A, *(unsigned int *)(v36 + 1800), *(unsigned int *)(v36 + 1804), &unk_8E7CE);
  }
LABEL_42:
  *(_QWORD *)(a1 + 2168) = v18;
  v30 = request_threaded_irq(*((unsigned int *)a2 + 36), cvp_hfi_isr, iris_hfi_core_work_handler, 4, "msm_cvp", a1);
  if ( v30 )
  {
    v32 = v30;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v37 = _ReadStatusReg(SP_EL0);
      v38 = v30;
      printk(&unk_889B2, *(unsigned int *)(v37 + 1800), *(unsigned int *)(v37 + 1804), &unk_8E7CE);
      v32 = v38;
    }
    goto LABEL_50;
  }
  v31 = request_threaded_irq(*((unsigned int *)a2 + 37), iris_hfi_isr_wd, 0, 2097156, "msm_cvp", a1);
  if ( v31 )
  {
    v39 = v31;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v40 = _ReadStatusReg(SP_EL0);
      printk(&unk_8F1E5, *(unsigned int *)(v40 + 1800), *(unsigned int *)(v40 + 1804), &unk_8E7CE);
    }
    v32 = v39;
LABEL_50:
    v33 = v32;
    kfree(v18);
    return v33;
  }
  disable_irq_nosync(*((unsigned int *)a2 + 36));
  result = 0;
  if ( (msm_cvp_debug & 4) != 0 && !msm_cvp_debug_out )
  {
    printk(&unk_96108, "info", a2, a2 + 1);
    return 0;
  }
  return result;
}
