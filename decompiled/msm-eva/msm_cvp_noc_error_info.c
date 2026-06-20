__int64 __fastcall msm_cvp_noc_error_info(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 *v4; // x9
  int v5; // w6
  unsigned int v6; // w8
  void (__fastcall *v7)(_QWORD); // x10
  __int64 v8; // x21
  __int64 v9; // x0
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v11; // x8
  __int64 v12; // x21
  __int64 v13; // x19

  if ( !a1 || (v4 = *(__int64 **)(a1 + 256)) == nullptr )
  {
    v6 = -22;
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_8E1BE, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
      return (unsigned int)-22;
    }
    return v6;
  }
  v5 = *(_DWORD *)(a1 + 1252);
  v6 = 0;
  if ( !v5 || v5 == msm_cvp_noc_error_info_last_fault_count )
    return v6;
  msm_cvp_noc_error_info_last_fault_count = *(_DWORD *)(a1 + 1252);
  if ( (msm_cvp_debug & 1) == 0
    || msm_cvp_debug_out
    || (v11 = _ReadStatusReg(SP_EL0),
        v12 = a1,
        printk(&unk_86F7A, *(unsigned int *)(v11 + 1800), *(unsigned int *)(v11 + 1804), &unk_8E7CE),
        v4 = *(__int64 **)(v12 + 256),
        a1 = v12,
        v4) )
  {
    v7 = (void (__fastcall *)(_QWORD))v4[21];
    if ( v7 )
    {
      v8 = a1;
      v9 = *v4;
      if ( *((_DWORD *)v7 - 1) != -1066802076 )
        __break(0x822Au);
      v7(v9);
      a1 = v8;
    }
  }
  if ( *(_DWORD *)(a1 + 1252) < *(_DWORD *)(a1 + 856) )
    return 0;
  if ( (msm_cvp_debug & 4) != 0 && !msm_cvp_debug_out )
  {
    v13 = a1;
    printk(&unk_8852D, "info", (unsigned int)msm_cvp_smmu_fault_recovery, a4);
    a1 = v13;
    if ( msm_cvp_smmu_fault_recovery )
      goto LABEL_15;
  }
  else if ( msm_cvp_smmu_fault_recovery )
  {
LABEL_15:
    v6 = 0;
    *(_BYTE *)(a1 + 1044) = 1;
    return v6;
  }
  if ( (*(_BYTE *)(a1 + 1044) & 1) != 0 )
    return 0;
  __break(0x800u);
  return msm_cvp_comm_session_clean();
}
