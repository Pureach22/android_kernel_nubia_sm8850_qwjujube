__int64 __fastcall _dsp_cvp_sess_stop(__int64 a1)
{
  char v2; // w8
  __int64 result; // x0
  __int64 v4; // x20
  int v5; // w22
  unsigned __int64 v6; // x8
  __int64 v7; // x3
  unsigned __int64 v8; // x8
  unsigned __int64 StatusReg; // x8

  v2 = BYTE1(msm_cvp_debug);
  *(_DWORD *)(a1 + 4) = 0;
  if ( (v2 & 8) != 0 && !msm_cvp_debug_out )
    printk(&unk_90EDF, "dsp", "__dsp_cvp_sess_stop", (unsigned int)dword_6C7D4);
  result = get_inst_from_dsp((unsigned int)dword_6C7DC, dword_6C7D8);
  v4 = result;
  if ( !result || (result = is_cvp_inst_valid(result), (result & 1) == 0) )
  {
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      result = printk(&unk_86629, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    }
    goto LABEL_13;
  }
  raw_spin_lock(v4 + 176);
  v5 = *(_DWORD *)(v4 + 180);
  result = raw_spin_unlock(v4 + 176);
  if ( v5 == 3 )
  {
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      v6 = _ReadStatusReg(SP_EL0);
      return printk(&unk_85C3F, *(unsigned int *)(v6 + 1800), *(unsigned int *)(v6 + 1804), "warn");
    }
    return result;
  }
  result = msm_cvp_session_stop(v4, 0);
  if ( (_DWORD)result )
  {
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v8 = _ReadStatusReg(SP_EL0);
      result = printk(&unk_82AAD, *(unsigned int *)(v8 + 1800), *(unsigned int *)(v8 + 1804), &unk_8E7CE);
    }
LABEL_13:
    *(_DWORD *)(a1 + 4) = -1;
    return result;
  }
  if ( (msm_cvp_debug & 0x800) != 0 && !msm_cvp_debug_out )
    return printk(&unk_87B89, "dsp", "__dsp_cvp_sess_stop", v7);
  return result;
}
