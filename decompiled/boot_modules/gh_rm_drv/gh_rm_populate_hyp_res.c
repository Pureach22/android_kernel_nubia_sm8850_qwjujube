unsigned __int64 __fastcall gh_rm_populate_hyp_res(__int64 a1, __int64 a2)
{
  unsigned int v2; // w20
  unsigned __int64 result; // x0
  unsigned __int64 v4; // x19
  unsigned __int64 v5; // x21
  unsigned int irq; // w22
  unsigned __int64 v7; // x8
  unsigned __int64 v8; // x24
  __int64 v9; // x0
  bool v10; // zf
  __int64 v11; // x2
  __int64 v12; // x23
  unsigned int v13; // w24
  void *v14; // x8
  unsigned int v15; // w0
  __int64 v16; // x23
  unsigned __int8 *v17; // x21
  int v18; // w2
  __int64 v19; // x0
  bool v20; // zf
  __int64 v21; // x2
  __int64 v22; // x24
  __int64 v23; // x28
  __int64 v24; // x26
  unsigned int v25; // w27
  int v26; // w0
  __int64 (__fastcall *v27)(__int64, __int64, __int64); // x8
  void *v28; // x8
  __int64 v29; // x2
  __int64 v30; // x3
  __int64 v31; // x6
  __int64 v32; // x25
  unsigned int v33; // w24
  __int64 v34; // x27
  unsigned __int64 v35; // x23
  __int64 v36; // x19
  __int64 v37; // x26
  int v38; // w28
  __int64 v39; // x0
  __int64 v40; // x1
  __int64 v41; // x2
  void *v42; // x8
  __int64 v43; // x25
  int v44; // w28
  void (__fastcall *v45)(_QWORD, __int64); // x8
  __int64 v46; // x24
  unsigned int v47; // w21
  unsigned __int64 v48; // x25
  unsigned int v49; // w2
  __int64 v50; // x0
  __int64 (__fastcall *v51)(_QWORD, unsigned int *); // x8
  void *v52; // x8
  __int64 v53; // x1
  unsigned int v54; // w0
  unsigned __int64 v55; // x23
  __int64 (__fastcall *v56)(_QWORD, __int64, __int64, unsigned int *); // x8
  __int64 v57; // x2
  __int64 v58; // x1
  void *v59; // x8
  unsigned int v61; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v62; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v63; // [xsp+18h] [xbp-8h]

  v2 = a1;
  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v61 = 0;
  result = gh_rm_vm_get_hyp_res(a1, &v61);
  v4 = result;
  if ( !result || result > 0xFFFFFFFFFFFFF000LL )
  {
    result = (unsigned int)result;
    goto LABEL_93;
  }
  if ( !v61 )
  {
    irq = 0;
    goto LABEL_87;
  }
  v5 = 0;
  irq = 0;
  do
  {
    v8 = v4 + 44 * v5;
    if ( *(_BYTE *)v8 == 4 )
    {
      v9 = *(unsigned int *)(v8 + 24);
      if ( *(_QWORD *)(v8 + 20) )
        v10 = (_DWORD)v9 == -1;
      else
        v10 = 1;
      if ( v10 )
      {
        irq = 0;
      }
      else
      {
        if ( gh_rm_intc )
          v11 = gh_rm_intc + 24;
        else
          v11 = 0;
        irq = gh_get_irq(v9, 1, v11);
        if ( (irq & 0x80000000) != 0 )
          goto LABEL_91;
      }
      if ( gh_vcpu_affinity_set_fn )
      {
        v12 = *(_QWORD *)(v8 + 12);
        v13 = *(_DWORD *)(v8 + 8);
        do
        {
          v14 = gh_vcpu_affinity_set_fn;
          if ( *((_DWORD *)gh_vcpu_affinity_set_fn - 1) != 1896416865 )
            __break(0x8228u);
          v15 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64, _QWORD))v14)(v2, v13, v12, irq);
        }
        while ( v15 == -11 );
        irq = v15;
        if ( (v15 & 0x80000000) != 0 )
          goto LABEL_91;
      }
      else if ( !(unsigned int)gh_put_irq(irq) )
      {
        gh_rm_vm_irq_release(*(unsigned int *)(v8 + 20));
      }
    }
    v7 = v61;
    ++v5;
  }
  while ( v5 < v61 );
  if ( !v61 )
  {
LABEL_87:
    v45 = (void (__fastcall *)(_QWORD, __int64))gh_all_res_populated_fn;
    if ( gh_all_res_populated_fn )
    {
      if ( *((_DWORD *)gh_all_res_populated_fn - 1) != -1620602384 )
        __break(0x8228u);
      v45(v2, 1);
    }
LABEL_91:
    kfree(v4);
    goto LABEL_92;
  }
  v16 = 0;
  while ( 1 )
  {
    v17 = (unsigned __int8 *)(v4 + 44 * v16);
    v18 = *v17;
    if ( (v18 & 0xFE) == 2 )
    {
      if ( *((_DWORD *)v17 + 2) < 0x101u )
        goto LABEL_31;
    }
    else if ( (unsigned int)v18 <= 1 && *((_DWORD *)v17 + 2) < 0x100u )
    {
      goto LABEL_31;
    }
    v19 = *((unsigned int *)v17 + 6);
    if ( *(_QWORD *)(v17 + 20) )
      v20 = (_DWORD)v19 == -1;
    else
      v20 = 1;
    if ( v20 )
    {
      irq = 0;
    }
    else
    {
      if ( gh_rm_intc )
        v21 = gh_rm_intc + 24;
      else
        v21 = 0;
      irq = gh_get_irq(v19, 1, v21);
      if ( (irq & 0x80000000) != 0 )
        goto LABEL_91;
      v18 = *v17;
    }
    v22 = *(_QWORD *)(v17 + 12);
    v23 = *(_QWORD *)(v17 + 28);
    v24 = *(_QWORD *)(v17 + 36);
    v25 = *((_DWORD *)v17 + 2);
    if ( v18 <= 3 )
    {
LABEL_49:
      if ( v18 > 1 )
        v26 = gh_msgq_populate_cap_info(v25, v22, v18 != 2, irq);
      else
        v26 = gh_dbl_populate_cap_info(v25, v22);
      goto LABEL_52;
    }
    if ( v18 <= 5 )
    {
      if ( v18 != 4 )
      {
        v27 = (__int64 (__fastcall *)(__int64, __int64, __int64))gh_vpm_grp_set_fn;
        if ( gh_vpm_grp_set_fn )
        {
LABEL_72:
          v39 = v2;
          v40 = v22;
          v41 = irq;
          if ( *((_DWORD *)v27 - 1) != -2121477506 )
            __break(0x8228u);
LABEL_74:
          v26 = v27(v39, v40, v41);
          goto LABEL_52;
        }
      }
      goto LABEL_30;
    }
    if ( v18 != 6 )
      break;
    mutex_lock(&gh_virtio_mmio_fn_lock);
    v42 = gh_virtio_mmio_fn;
    if ( gh_virtio_mmio_fn )
    {
      if ( *((_DWORD *)gh_virtio_mmio_fn - 1) != 1250511663 )
        __break(0x8228u);
      v43 = v23;
      v44 = ((__int64 (__fastcall *)(_QWORD, __int64, _QWORD, __int64, _QWORD, __int64, __int64))v42)(
              v2,
              a2,
              v25,
              v22,
              irq,
              v23,
              v24);
      mutex_unlock(&gh_virtio_mmio_fn_lock);
      v26 = v44;
      v23 = v43;
LABEL_52:
      while ( v26 == -11 )
      {
        v18 = *v17;
        if ( (unsigned int)v18 <= 3 )
          goto LABEL_49;
        if ( *v17 > 5u )
        {
          if ( v18 == 6 )
          {
            mutex_lock(&gh_virtio_mmio_fn_lock);
            v28 = gh_virtio_mmio_fn;
            if ( gh_virtio_mmio_fn )
            {
              v29 = v25;
              v30 = v22;
              v31 = v24;
              if ( *((_DWORD *)gh_virtio_mmio_fn - 1) != 1250511663 )
                __break(0x8228u);
              v32 = v22;
              v33 = v25;
              v34 = v16;
              v35 = v4;
              v36 = v24;
              v37 = v23;
              v38 = ((__int64 (__fastcall *)(_QWORD, __int64, __int64, __int64, _QWORD, __int64, __int64))v28)(
                      v2,
                      a2,
                      v29,
                      v30,
                      irq,
                      v23,
                      v31);
              mutex_unlock(&gh_virtio_mmio_fn_lock);
              v26 = v38;
              v23 = v37;
              v24 = v36;
              v4 = v35;
              v16 = v34;
              v25 = v33;
              v22 = v32;
            }
            else
            {
              mutex_unlock(&gh_virtio_mmio_fn_lock);
              v26 = -11;
            }
          }
          else
          {
            if ( v18 != 8 )
              goto LABEL_94;
            v27 = (__int64 (__fastcall *)(__int64, __int64, __int64))gh_wdog_manage_fn;
            if ( gh_wdog_manage_fn )
              goto LABEL_78;
            v26 = -11;
          }
        }
        else if ( v18 == 4 )
        {
          v26 = -11;
        }
        else
        {
          if ( v18 != 5 )
            goto LABEL_94;
          v27 = (__int64 (__fastcall *)(__int64, __int64, __int64))gh_vpm_grp_set_fn;
          if ( gh_vpm_grp_set_fn )
            goto LABEL_72;
          v26 = -11;
        }
      }
      irq = v26;
      if ( v26 < 0 )
        goto LABEL_95;
    }
    else
    {
      mutex_unlock(&gh_virtio_mmio_fn_lock);
    }
LABEL_30:
    v7 = v61;
LABEL_31:
    if ( ++v16 >= v7 )
      goto LABEL_87;
  }
  if ( v18 == 8 )
  {
    v27 = (__int64 (__fastcall *)(__int64, __int64, __int64))gh_wdog_manage_fn;
    if ( gh_wdog_manage_fn )
    {
LABEL_78:
      v39 = v2;
      v40 = v22;
      v41 = 1;
      if ( *((_DWORD *)v27 - 1) != -1132193203 )
        __break(0x8228u);
      goto LABEL_74;
    }
    goto LABEL_30;
  }
LABEL_94:
  printk(&unk_12696, "gh_rm_populate_hyp_res");
  v26 = -22;
LABEL_95:
  v46 = v61;
  irq = v26;
  v47 = 0;
  v62 = -1;
  if ( !(_DWORD)v16 )
  {
LABEL_124:
    if ( (_DWORD)v46 )
    {
      v55 = v4 + 12;
      do
      {
        if ( *(_BYTE *)(v55 - 12) == 4 )
        {
          v56 = (__int64 (__fastcall *)(_QWORD, __int64, __int64, unsigned int *))gh_vcpu_affinity_reset_fn;
          if ( gh_vcpu_affinity_reset_fn )
          {
            v57 = *(_QWORD *)v55;
            v58 = *(unsigned int *)(v55 - 4);
            if ( *((_DWORD *)gh_vcpu_affinity_reset_fn - 1) != 1949169083 )
              __break(0x8228u);
            v47 = v56(v2, v58, v57, &v62);
            if ( (v47 & 0x80000000) != 0 )
              goto LABEL_142;
            if ( (v62 & 0x80000000) == 0 && !(unsigned int)gh_put_irq(v62) )
              gh_rm_vm_irq_release(*(unsigned int *)(v55 + 8));
          }
        }
        --v46;
        v55 += 44LL;
      }
      while ( v46 );
    }
    v59 = gh_all_res_populated_fn;
    if ( gh_all_res_populated_fn )
    {
      if ( *((_DWORD *)gh_all_res_populated_fn - 1) != -1620602384 )
        __break(0x8228u);
      ((void (__fastcall *)(_QWORD, _QWORD))v59)(v2, 0);
    }
    kfree(v4);
    if ( (v47 & 0x80000000) != 0 )
      goto LABEL_143;
    goto LABEL_92;
  }
  v48 = v4 + 12;
  while ( 2 )
  {
    v49 = *(unsigned __int8 *)(v48 - 12);
    if ( (v49 & 0xFE) == 2 )
    {
      v50 = *(unsigned int *)(v48 - 4);
      if ( (unsigned int)v50 >= 0x101 )
        goto LABEL_103;
LABEL_97:
      --v16;
      v48 += 44LL;
      if ( !v16 )
        goto LABEL_124;
      continue;
    }
    break;
  }
  v50 = *(unsigned int *)(v48 - 4);
  if ( v49 <= 1 && (unsigned int)v50 < 0x100 )
    goto LABEL_97;
LABEL_103:
  if ( *(unsigned __int8 *)(v48 - 12) <= 3u )
  {
    if ( *(unsigned __int8 *)(v48 - 12) > 1u )
      v54 = gh_msgq_reset_cap_info(v50, v49 != 2, &v62);
    else
      v54 = gh_dbl_reset_cap_info(v50, *(_BYTE *)(v48 - 12) != 0, &v62);
    goto LABEL_119;
  }
  if ( *(unsigned __int8 *)(v48 - 12) <= 5u )
  {
    if ( v49 != 4 )
    {
      v51 = (__int64 (__fastcall *)(_QWORD, unsigned int *))gh_vpm_grp_reset_fn;
      if ( gh_vpm_grp_reset_fn )
      {
        if ( *((_DWORD *)gh_vpm_grp_reset_fn - 1) != 699811233 )
          __break(0x8228u);
        v54 = v51(v2, &v62);
        goto LABEL_119;
      }
    }
    goto LABEL_120;
  }
  if ( v49 == 6 )
    goto LABEL_120;
  if ( v49 == 8 )
  {
    v52 = gh_wdog_manage_fn;
    if ( gh_wdog_manage_fn )
    {
      v53 = *(_QWORD *)v48;
      if ( *((_DWORD *)gh_wdog_manage_fn - 1) != -1132193203 )
        __break(0x8228u);
      v54 = ((__int64 (__fastcall *)(_QWORD, __int64, _QWORD))v52)(v2, v53, 0);
LABEL_119:
      v47 = v54;
    }
LABEL_120:
    if ( (v47 & 0x80000000) != 0 )
      goto LABEL_142;
    if ( (v62 & 0x80000000) == 0 && !(unsigned int)gh_put_irq(v62) )
      gh_rm_vm_irq_release(*(unsigned int *)(v48 + 8));
    goto LABEL_97;
  }
  printk(&unk_12696, "gh_rm_unpopulate_target_hyp_res");
  v47 = -22;
LABEL_142:
  kfree(v4);
LABEL_143:
  printk(&unk_137DD, v47);
LABEL_92:
  result = irq;
LABEL_93:
  _ReadStatusReg(SP_EL0);
  return result;
}
