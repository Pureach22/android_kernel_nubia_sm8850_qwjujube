__int64 __fastcall iris_hfi_flush_debug_queue(__int64 a1)
{
  __int64 v2; // x8
  unsigned int (__fastcall *v3)(_QWORD); // x8
  unsigned __int64 v4; // x8
  unsigned int v5; // w20
  unsigned __int64 v6; // x8
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v8; // x8
  unsigned __int64 v9; // x8
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x8
  __int64 v13; // x8
  void (__fastcall *v14)(_QWORD); // x8
  unsigned __int64 v16; // x8
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x8

  if ( a1 )
  {
    mutex_lock(a1 + 80);
    if ( (*(_BYTE *)(a1 + 72) & 1) == 0 )
    {
      v5 = -22;
      if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        printk(&unk_8A7F1, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
      }
      goto LABEL_48;
    }
    if ( (*(_BYTE *)(a1 + 73) & 1) != 0 )
    {
LABEL_47:
      _flush_debug_queue((_QWORD *)a1, nullptr);
      v5 = 0;
LABEL_48:
      mutex_unlock(a1 + 80);
      return v5;
    }
    _read_register(a1, 0xC0010u);
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v8 = _ReadStatusReg(SP_EL0);
      printk(&unk_8A81D, *(unsigned int *)(v8 + 1800), *(unsigned int *)(v8 + 1804), &unk_8E7CE);
    }
    _read_register(a1, 0xA004Cu);
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v9 = _ReadStatusReg(SP_EL0);
      printk(&unk_8BC6E, *(unsigned int *)(v9 + 1800), *(unsigned int *)(v9 + 1804), &unk_8E7CE);
    }
    _read_register(a1, 0xB000Cu);
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v10 = _ReadStatusReg(SP_EL0);
      printk(&unk_82F09, *(unsigned int *)(v10 + 1800), *(unsigned int *)(v10 + 1804), &unk_8E7CE);
    }
    _read_register(a1, 0xA0150u);
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v11 = _ReadStatusReg(SP_EL0);
      printk(&unk_96449, *(unsigned int *)(v11 + 1800), *(unsigned int *)(v11 + 1804), &unk_8E7CE);
    }
    _read_register(a1, 0xA0018u);
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v12 = _ReadStatusReg(SP_EL0);
      printk(&unk_94391, *(unsigned int *)(v12 + 1800), *(unsigned int *)(v12 + 1804), &unk_8E7CE);
      v2 = *(_QWORD *)(a1 + 2512);
      if ( !v2 )
        goto LABEL_33;
    }
    else
    {
      v2 = *(_QWORD *)(a1 + 2512);
      if ( !v2 )
        goto LABEL_33;
    }
    v3 = *(unsigned int (__fastcall **)(_QWORD))(v2 + 56);
    if ( v3 )
    {
      if ( *((_DWORD *)v3 - 1) != -1303076162 )
        __break(0x8228u);
      if ( v3(a1) )
      {
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          v4 = _ReadStatusReg(SP_EL0);
          printk(&unk_93B26, *(unsigned int *)(v4 + 1800), *(unsigned int *)(v4 + 1804), &unk_8E7CE);
        }
        goto LABEL_47;
      }
    }
LABEL_33:
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v16 = _ReadStatusReg(SP_EL0);
      printk(&unk_943C4, *(unsigned int *)(v16 + 1800), *(unsigned int *)(v16 + 1804), &unk_8E7CE);
    }
    _read_register(a1, 0xB0050u);
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v17 = _ReadStatusReg(SP_EL0);
      printk(&unk_88C0E, *(unsigned int *)(v17 + 1800), *(unsigned int *)(v17 + 1804), &unk_8E7CE);
    }
    _read_register(a1, 0xB0088u);
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v18 = _ReadStatusReg(SP_EL0);
      printk(&unk_825C4, *(unsigned int *)(v18 + 1800), *(unsigned int *)(v18 + 1804), &unk_8E7CE);
      v13 = *(_QWORD *)(a1 + 2512);
      if ( v13 )
      {
LABEL_42:
        v14 = *(void (__fastcall **)(_QWORD))(v13 + 88);
        if ( v14 )
        {
          if ( *((_DWORD *)v14 - 1) != -639316779 )
            __break(0x8228u);
          v14(a1);
        }
      }
    }
    else
    {
      v13 = *(_QWORD *)(a1 + 2512);
      if ( v13 )
        goto LABEL_42;
    }
    *(_BYTE *)(a1 + 73) = 1;
    goto LABEL_47;
  }
  v5 = -22;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v6 = _ReadStatusReg(SP_EL0);
    printk(&unk_861CC, *(unsigned int *)(v6 + 1800), *(unsigned int *)(v6 + 1804), &unk_8E7CE);
  }
  return v5;
}
