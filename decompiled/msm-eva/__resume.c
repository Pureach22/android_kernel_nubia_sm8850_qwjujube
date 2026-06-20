__int64 __fastcall _resume(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  unsigned __int64 v5; // x8
  int v6; // w8
  __int64 v7; // x19
  unsigned __int64 StatusReg; // x8
  unsigned int v9; // w19
  unsigned int v10; // w0
  int v11; // w9
  __int64 v12; // x8
  unsigned int v13; // w20
  unsigned __int64 v14; // x8
  __int64 v15; // x19
  unsigned int v16; // w20
  unsigned int v17; // w0
  unsigned __int64 v18; // x8
  unsigned int v19; // w19
  __int64 v20; // x0
  __int64 v21; // x2
  __int64 v22; // x3
  unsigned __int64 v23; // x8
  unsigned __int64 v24; // x8

  if ( a1 )
  {
    if ( (*(_BYTE *)(a1 + 72) & 1) != 0 )
    {
LABEL_3:
      if ( *(_DWORD *)(a1 + 28) != 17829890 )
        *(_DWORD *)(a1 + 2496) = 0;
      return 0;
    }
    v6 = (msm_cvp_debug_out == 0) & (BYTE1(msm_cvp_debug) >> 2);
    if ( *(_DWORD *)(a1 + 2408) == 1 )
    {
      if ( v6 )
        printk(&unk_8DA12, &unk_8DA84, a3, a4);
      return 4294967274LL;
    }
    if ( v6 )
    {
      v15 = a1;
      printk(&unk_9208D, &unk_8DA84, a3, a4);
      a1 = v15;
    }
    v7 = a1;
    result = _iris_power_on();
    if ( (_DWORD)result )
    {
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        v9 = result;
        printk(&unk_8BA7D, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
        result = v9;
      }
      goto LABEL_35;
    }
    _setup_ucregion_memory_map(v7);
    v10 = qcom_scm_set_remote_state(1, 26);
    if ( (msm_cvp_debug & 0x100) != 0 && !msm_cvp_debug_out )
    {
      v16 = v10;
      printk(&unk_82354, "core", 1, v10);
      v10 = v16;
      if ( v16 )
        goto LABEL_22;
    }
    else if ( v10 )
    {
LABEL_22:
      v11 = msm_cvp_debug_out;
      v12 = v7;
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v23 = _ReadStatusReg(SP_EL0);
        v13 = v10;
        printk(&unk_86A4F, *(unsigned int *)(v23 + 1800), *(unsigned int *)(v23 + 1804), &unk_8E7CE);
        v11 = msm_cvp_debug_out;
        v12 = v7;
        if ( (msm_cvp_debug & 1) == 0 )
          goto LABEL_34;
      }
      else
      {
        v13 = v10;
        if ( (msm_cvp_debug & 1) == 0 )
          goto LABEL_34;
      }
      if ( !v11 )
      {
        v14 = _ReadStatusReg(SP_EL0);
        printk(&unk_84CE5, *(unsigned int *)(v14 + 1800), *(unsigned int *)(v14 + 1804), &unk_8E7CE);
LABEL_33:
        v12 = v7;
      }
LABEL_34:
      power_off_iris2(v12);
      result = v13;
LABEL_35:
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v18 = _ReadStatusReg(SP_EL0);
        v19 = result;
        printk(&unk_8CEAA, *(unsigned int *)(v18 + 1800), *(unsigned int *)(v18 + 1804), &unk_8E7CE);
        return v19;
      }
      return result;
    }
    v17 = _boot_firmware(v7);
    if ( !v17 )
    {
      _set_threshold_registers(v7);
      if ( *(_DWORD *)(v7 + 2696) && *(_QWORD *)(*(_QWORD *)(v7 + 2208) + 400LL) )
        cvp_pm_qos_update(v7, 1);
      _sys_set_debug(v7, (unsigned int)msm_cvp_fw_debug);
      _enable_subcaches(v7);
      v20 = _set_subcaches(v7);
      _dsp_resume(v20);
      a1 = v7;
      if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
      {
        printk(&unk_8B070, &unk_8DA84, v21, v22);
        a1 = v7;
      }
      goto LABEL_3;
    }
    v13 = v17;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v24 = _ReadStatusReg(SP_EL0);
      printk(&unk_96CCB, *(unsigned int *)(v24 + 1800), *(unsigned int *)(v24 + 1804), &unk_8E7CE);
    }
    _tzbsp_set_cvp_state(0);
    goto LABEL_33;
  }
  result = 4294967274LL;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v5 = _ReadStatusReg(SP_EL0);
    printk(&unk_837CA, *(unsigned int *)(v5 + 1800), *(unsigned int *)(v5 + 1804), &unk_8E7CE);
    return 4294967274LL;
  }
  return result;
}
