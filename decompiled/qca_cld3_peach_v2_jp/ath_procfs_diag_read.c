__int64 __fastcall ath_procfs_diag_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, unsigned int *a4)
{
  __int64 v5; // x0
  unsigned __int64 v6; // x23
  unsigned int (*v7)(void); // x8
  unsigned __int64 v12; // x24
  __int64 v13; // x22
  __int64 v14; // x0
  __int64 v15; // x21
  __int64 target_info_handle; // x0
  int v17; // w4
  unsigned int v18; // w4
  int v19; // w23
  __int64 v20; // x23
  const void *v21; // x0
  const void *v22; // x21
  __int64 v23; // x0
  int v24; // w8
  int v25; // w8
  __int64 v26; // x8
  int v27; // w22
  unsigned int v28; // w8
  unsigned int v29; // w24
  unsigned int v30; // w22
  int mem; // w0
  __int64 v32; // x1
  unsigned __int64 v33; // x8
  unsigned __int64 v34; // x9
  __int64 v35; // x0
  unsigned __int64 v36; // x9
  unsigned __int64 v42; // x8
  unsigned __int64 v43; // x8
  unsigned __int64 v45; // x9
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v47; // x9
  unsigned __int64 v48; // x9
  unsigned __int64 v50; // x8
  unsigned __int64 v51; // x8
  unsigned __int64 v53; // x9

  v5 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 696LL);
  if ( !v5 )
    return -22;
  v6 = *(_QWORD *)a4;
  v7 = *(unsigned int (**)(void))(v5 + 392);
  if ( *((_DWORD *)v7 - 1) != -174160978 )
    __break(0x8228u);
  if ( v7() | v6 & 3 )
    return -22;
  v12 = v6 >> 60;
  qdf_trace_msg(
    61,
    8,
    "%s: rd cnt %zu offset 0x%x op_type %d type %d pos %llx",
    "ath_procfs_diag_read",
    a3,
    v6,
    v6 >> 60,
    (unsigned __int8)(v6 >> 52),
    *(_QWORD *)a4);
  if ( (v6 >> 60) - 1 < 2 )
  {
    v13 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 696LL);
    if ( v13 )
    {
      v14 = _qdf_mem_malloc(a3, "ath_procfs_diag_read_ext", 358);
      if ( v14 )
      {
        v15 = v14;
        target_info_handle = hif_get_target_info_handle(v13);
        v17 = *(_DWORD *)(v13 + 72);
        if ( v17 != 6 && v17 )
        {
          qdf_trace_msg(61, 2, "%s: Unrecognized bus type %d", "ath_procfs_diag_read_ext");
        }
        else
        {
          v18 = *(_DWORD *)(target_info_handle + 4);
          if ( v18 <= 0x2B && ((1LL << v18) & 0xD6488800000LL) != 0 )
          {
            if ( (_DWORD)v12 == 2 )
            {
              v19 = -5;
            }
            else
            {
              v26 = *(_QWORD *)(v13 + 576);
              v27 = a3;
              v19 = pld_athdiag_read(
                      *(_QWORD *)(v26 + 40),
                      (unsigned int)v6,
                      (unsigned __int8)(v6 >> 52),
                      (unsigned int)a3,
                      v15);
              if ( !v19 )
              {
                if ( a3 >> 31 )
                {
                  __break(0x800u);
                }
                else
                {
                  _check_object_size(v15, a3, 1);
                  StatusReg = _ReadStatusReg(SP_EL0);
                  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v47 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
                    v47 = a2 & ((__int64)(a2 << 8) >> 8);
                  if ( 0x8000000000LL - a3 >= v47 )
                  {
                    v48 = _ReadStatusReg(DAIF);
                    __asm { MSR             DAIFSet, #3 }
                    v50 = *(_QWORD *)(StatusReg + 8);
                    _WriteStatusReg(
                      TTBR1_EL1,
                      v50 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
                    _WriteStatusReg(TTBR0_EL1, v50);
                    __isb(0xFu);
                    _WriteStatusReg(DAIF, v48);
                    a3 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL, v15, a3);
                    v51 = _ReadStatusReg(DAIF);
                    __asm { MSR             DAIFSet, #3 }
                    v53 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
                    _WriteStatusReg(TTBR0_EL1, v53 - 4096);
                    _WriteStatusReg(TTBR1_EL1, v53);
                    __isb(0xFu);
                    _WriteStatusReg(DAIF, v51);
                  }
                  if ( !a3 )
                    goto LABEL_33;
                }
                qdf_trace_msg(61, 2, "%s: copy_to_user error in /proc/%s", "ath_procfs_diag_read_ext", "athdiagpfs");
                v27 = -14;
LABEL_33:
                _qdf_mem_free(v15);
                return v27;
              }
            }
LABEL_32:
            qdf_trace_msg(61, 2, "%s: fail to read from target %d", "ath_procfs_diag_read_ext", v19);
            v27 = v19;
            goto LABEL_33;
          }
          qdf_trace_msg(61, 2, "%s: Unrecognized target type %d", "ath_procfs_diag_read_ext");
        }
        v19 = -22;
        goto LABEL_32;
      }
      return -12;
    }
    return -22;
  }
  if ( (_DWORD)v12 )
  {
    qdf_trace_msg(61, 2, "%s: Unrecognized op type %d", "ath_procfs_diag_read", v12);
    return -22;
  }
  v20 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 696LL);
  v21 = (const void *)_qdf_mem_malloc(a3, "ath_procfs_diag_read_legacy", 101);
  if ( !v21 )
    return -12;
  v22 = v21;
  qdf_trace_msg(
    61,
    8,
    "%s: rd buff 0x%pK cnt %zu offset 0x%x buf 0x%pK",
    "ath_procfs_diag_read_legacy",
    v21,
    a3,
    *a4,
    (const void *)a2);
  v23 = hif_get_target_info_handle(v20);
  v24 = *(_DWORD *)(v20 + 72);
  if ( v24 > 4 )
  {
    if ( v24 == 5 )
    {
      if ( *(_DWORD *)(v23 + 4) == 22 )
        goto LABEL_36;
    }
    else if ( v24 == 6 )
    {
      v25 = *(_DWORD *)(v23 + 4);
      if ( v25 == 28 || v25 == 40 )
        goto LABEL_36;
    }
  }
  else
  {
    if ( v24 )
    {
      if ( v24 != 2 )
        goto LABEL_38;
LABEL_36:
      v29 = *a4;
      v30 = HIBYTE(*a4);
      qdf_trace_msg(
        61,
        8,
        "%s: offset 0x%x memtype 0x%x, datalen %zu",
        "ath_procfs_diag_read_legacy",
        v29 & 0xFFFFFF,
        v30,
        a3);
      mem = pld_athdiag_read(*(_QWORD *)(*(_QWORD *)(v20 + 576) + 40LL), v29 & 0xFFFFFF, v30, (unsigned int)a3, v22);
      goto LABEL_42;
    }
    v28 = *(_DWORD *)(v23 + 4);
    if ( v28 <= 0x2B && ((1LL << v28) & 0xEBFEFF00000LL) != 0 )
      goto LABEL_36;
  }
LABEL_38:
  v32 = *a4;
  if ( a3 != 4 || (v32 & 3) != 0 )
    mem = hif_diag_read_mem(v20, v32, v22, (unsigned int)a3);
  else
    mem = hif_diag_read_access(v20);
LABEL_42:
  if ( mem )
  {
    _qdf_mem_free(v22);
    return -5;
  }
  else
  {
    if ( a3 >> 31 )
    {
      __break(0x800u);
    }
    else
    {
      _check_object_size(v22, a3, 1);
      v33 = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(v33 + 70) & 0x20) != 0 || (v34 = a2, (*(_QWORD *)v33 & 0x4000000) != 0) )
        v34 = a2 & ((__int64)(a2 << 8) >> 8);
      v35 = a3;
      if ( 0x8000000000LL - a3 >= v34 )
      {
        v36 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v42 = *(_QWORD *)(v33 + 8);
        _WriteStatusReg(TTBR1_EL1, v42 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v42);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v36);
        v35 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL, v22, a3);
        v43 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v45 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v45 - 4096);
        _WriteStatusReg(TTBR1_EL1, v45);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v43);
      }
      if ( !v35 )
      {
        _qdf_mem_free(v22);
        return a3;
      }
    }
    _qdf_mem_free(v22);
    qdf_trace_msg(61, 2, "%s: copy_to_user error in /proc/%s", "ath_procfs_diag_read_legacy", "athdiagpfs");
    return -14;
  }
}
