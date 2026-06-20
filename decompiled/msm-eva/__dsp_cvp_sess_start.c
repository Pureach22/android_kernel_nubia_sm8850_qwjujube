__int64 __fastcall _dsp_cvp_sess_start(__int64 a1)
{
  char v2; // w8
  __int64 result; // x0
  __int64 v4; // x20
  int v5; // w22
  unsigned __int64 v6; // x8
  __int64 v7; // x3
  unsigned __int64 v8; // x8
  __int64 v9; // x1
  __int64 v10; // x2
  void *v11; // x0
  unsigned __int64 StatusReg; // x8

  v2 = BYTE1(msm_cvp_debug);
  *(_DWORD *)(a1 + 4) = 0;
  if ( (v2 & 8) != 0 && !msm_cvp_debug_out )
    printk(&unk_90EDF, "dsp", "__dsp_cvp_sess_start", (unsigned int)dword_6C7D4);
  result = get_inst_from_dsp((unsigned int)dword_6C7DC, dword_6C7D8);
  v4 = result;
  if ( !result || (result = is_cvp_inst_valid(result), (result & 1) == 0) )
  {
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      goto LABEL_12;
    StatusReg = _ReadStatusReg(SP_EL0);
    v9 = *(unsigned int *)(StatusReg + 1800);
    v10 = *(unsigned int *)(StatusReg + 1804);
    v11 = &unk_86629;
    goto LABEL_22;
  }
  raw_spin_lock(v4 + 176);
  v5 = *(_DWORD *)(v4 + 180);
  result = raw_spin_unlock(v4 + 176);
  if ( v5 == 2 )
  {
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      v6 = _ReadStatusReg(SP_EL0);
      return printk(&unk_94883, *(unsigned int *)(v6 + 1800), *(unsigned int *)(v6 + 1804), "warn");
    }
    return result;
  }
  result = msm_cvp_session_start(v4);
  if ( (_DWORD)result )
  {
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      goto LABEL_12;
    v8 = _ReadStatusReg(SP_EL0);
    v9 = *(unsigned int *)(v8 + 1800);
    v10 = *(unsigned int *)(v8 + 1804);
    v11 = &unk_927B4;
LABEL_22:
    result = printk(v11, v9, v10, &unk_8E7CE);
LABEL_12:
    *(_DWORD *)(a1 + 4) = -1;
    return result;
  }
  if ( (msm_cvp_debug & 0x800) != 0 && !msm_cvp_debug_out )
    return printk(&unk_97479, "dsp", "__dsp_cvp_sess_start", v7);
  return result;
}
