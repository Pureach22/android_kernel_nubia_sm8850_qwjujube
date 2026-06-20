__int64 __fastcall iris_hfi_session_init(_QWORD *a1, __int64 a2, _QWORD *a3)
{
  __int64 v6; // x0
  _QWORD *v7; // x21
  char v8; // w8
  _QWORD *v9; // x1
  __int64 v10; // x8
  int v11; // w23
  unsigned int v12; // w9
  unsigned __int64 v13; // x8
  unsigned __int64 v14; // x9
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  unsigned int v17; // w9
  unsigned __int64 v18; // x8
  unsigned __int64 v19; // x9
  __int64 v20; // x0
  unsigned int *v21; // x22
  __int64 v22; // x8
  void (__fastcall *v23)(__int64, bool); // x8
  int v24; // w23
  __int64 v25; // x8
  _DWORD *v26; // x8
  unsigned __int64 v27; // x8
  unsigned __int64 v28; // x8
  unsigned __int64 v29; // x8
  unsigned __int64 v30; // x8
  _QWORD v31[5]; // [xsp+8h] [xbp-28h] BYREF

  v31[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v31, 0, 32);
  if ( !a1 || !a3 )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_8F418, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
LABEL_52:
      result = 4294967274LL;
      goto LABEL_53;
    }
    goto LABEL_53;
  }
  mutex_lock(a1 + 10);
  v6 = _kmalloc_cache_noprof(_kmem_cache_create_args, 3520, 40);
  v7 = (_QWORD *)v6;
  if ( !v6 )
  {
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v30 = _ReadStatusReg(SP_EL0);
      printk(&unk_94316, *(unsigned int *)(v30 + 1800), *(unsigned int *)(v30 + 1804), &unk_8E7CE);
    }
    goto LABEL_51;
  }
  *(_QWORD *)(v6 + 16) = a2;
  v8 = BYTE1(msm_cvp_debug);
  *(_QWORD *)(v6 + 32) = a1;
  if ( (v8 & 0x20) != 0 && !msm_cvp_debug_out )
    printk(&unk_94E8B, "sess", "iris_hfi_session_init", a2);
  v9 = (_QWORD *)a1[1];
  if ( v7 == a1 || v9 == v7 || (_QWORD *)*v9 != a1 )
  {
    _list_add_valid_or_report(v7, v9, a1);
  }
  else
  {
    a1[1] = v7;
    *v7 = a1;
    v7[1] = v9;
    *v9 = v7;
  }
  if ( (unsigned int)_sys_set_debug((__int64)a1, msm_cvp_fw_debug) && (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
  {
    v28 = _ReadStatusReg(SP_EL0);
    printk(&unk_963A8, *(unsigned int *)(v28 + 1800), *(unsigned int *)(v28 + 1804), "warn");
  }
  v10 = a1[276];
  v11 = msm_cvp_fw_low_power_mode;
  if ( *(_DWORD *)(v10 + 464) )
  {
    v12 = *(_DWORD *)(v10 + 480);
    v13 = *(_QWORD *)(v10 + 472);
    v14 = v13 + 24LL * v12;
    if ( v13 >= v14 )
      goto LABEL_35;
    while ( (*(_BYTE *)(v13 + 8) & 1) == 0 )
    {
      v13 += 24LL;
      if ( v13 >= v14 )
        goto LABEL_35;
    }
  }
  else
  {
    v17 = *(_DWORD *)(v10 + 272);
    v18 = *(_QWORD *)(v10 + 264);
    v19 = v18 + 24LL * v17;
    if ( v18 >= v19 )
      goto LABEL_35;
    while ( *(_BYTE *)(v18 + 8) != 1 )
    {
      v18 += 24LL;
      if ( v18 >= v19 )
        goto LABEL_35;
    }
  }
  v20 = _kmalloc_cache_noprof(printk, 3520, 20);
  v21 = (unsigned int *)v20;
  v22 = a1[302];
  if ( v22 )
  {
    v23 = *(void (__fastcall **)(__int64, bool))(v22 + 16);
    if ( v23 )
    {
      if ( *((_DWORD *)v23 - 1) != 1706540593 )
        __break(0x8228u);
      v23(v20, v11 != 0);
    }
  }
  v24 = _iface_cmdq_write((__int64)a1, v21);
  kfree(v21);
  if ( v24 && (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
  {
    v29 = _ReadStatusReg(SP_EL0);
    printk(&unk_92FFB, *(unsigned int *)(v29 + 1800), *(unsigned int *)(v29 + 1804), "warn");
    v25 = a1[302];
    if ( v25 )
      goto LABEL_36;
    goto LABEL_44;
  }
LABEL_35:
  v25 = a1[302];
  if ( v25 )
  {
LABEL_36:
    v26 = *(_DWORD **)(v25 + 88);
    if ( v26 )
    {
      if ( *(v26 - 1) != -910718902 )
        __break(0x8228u);
      if ( ((unsigned int (__fastcall *)(_QWORD *, _QWORD *))v26)(v31, v7) )
      {
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          v27 = _ReadStatusReg(SP_EL0);
          printk(&unk_92FBC, *(unsigned int *)(v27 + 1800), *(unsigned int *)(v27 + 1804), &unk_8E7CE);
        }
        goto LABEL_45;
      }
    }
  }
LABEL_44:
  *a3 = v7;
  if ( (unsigned int)_iface_cmdq_write((__int64)a1, (unsigned int *)v31) )
  {
LABEL_45:
    _session_clean(v7);
LABEL_51:
    *a3 = 0;
    mutex_unlock(a1 + 10);
    goto LABEL_52;
  }
  mutex_unlock(a1 + 10);
  result = 0;
LABEL_53:
  _ReadStatusReg(SP_EL0);
  return result;
}
