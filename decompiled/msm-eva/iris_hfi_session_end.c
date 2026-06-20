__int64 __fastcall iris_hfi_session_end(__int64 a1)
{
  __int64 v1; // x22
  __int64 v3; // x21
  __int64 v4; // x0
  unsigned int *v5; // x20
  __int64 v6; // x8
  unsigned int (__fastcall *v7)(__int64, __int64); // x8
  void *v8; // x0
  unsigned __int64 StatusReg; // x8
  __int64 result; // x0
  unsigned __int64 v11; // x8
  __int64 v12; // x1
  __int64 v13; // x2
  void *v14; // x0
  unsigned __int64 v15; // x8
  unsigned int v16; // w19

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 32);
    if ( v1 )
    {
      mutex_lock(v1 + 80);
      if ( msm_cvp_fw_coverage != 1 )
      {
LABEL_24:
        v16 = _send_session_cmd(a1, 17829898);
        mutex_unlock(v1 + 80);
        return v16;
      }
      v3 = *(_QWORD *)(a1 + 32);
      v4 = _kmalloc_cache_noprof(printk, 3520, 20);
      v5 = (unsigned int *)v4;
      if ( !v3 )
        goto LABEL_22;
      v6 = *(_QWORD *)(v3 + 2416);
      if ( !v6 )
        goto LABEL_22;
      v7 = *(unsigned int (__fastcall **)(__int64, __int64))(v6 + 40);
      if ( !v7 )
        goto LABEL_22;
      if ( *((_DWORD *)v7 - 1) != 1706540593 )
        __break(0x8228u);
      if ( v7(v4, 1) )
      {
        if ( (msm_cvp_debug & 2) == 0 || msm_cvp_debug_out )
          goto LABEL_23;
        v8 = &unk_8BC32;
        StatusReg = _ReadStatusReg(SP_EL0);
      }
      else
      {
LABEL_22:
        if ( !(unsigned int)_iface_cmdq_write(v3, v5) || (msm_cvp_debug & 2) == 0 || msm_cvp_debug_out )
          goto LABEL_23;
        v8 = &unk_839CE;
        StatusReg = _ReadStatusReg(SP_EL0);
      }
      printk(v8, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
LABEL_23:
      kfree(v5);
      goto LABEL_24;
    }
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v15 = _ReadStatusReg(SP_EL0);
      v12 = *(unsigned int *)(v15 + 1800);
      v13 = *(unsigned int *)(v15 + 1804);
      v14 = &unk_843B9;
      goto LABEL_19;
    }
  }
  else
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v11 = _ReadStatusReg(SP_EL0);
      v12 = *(unsigned int *)(v11 + 1800);
      v13 = *(unsigned int *)(v11 + 1804);
      v14 = &unk_9434F;
LABEL_19:
      printk(v14, v12, v13, &unk_8E7CE);
      return 4294967274LL;
    }
  }
  return result;
}
