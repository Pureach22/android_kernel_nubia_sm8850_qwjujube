__int64 __fastcall _dsp_cvp_set_session_name(__int64 a1)
{
  char v2; // w8
  __int64 result; // x0
  __int64 v4; // x20
  unsigned __int64 StatusReg; // x8

  v2 = BYTE1(msm_cvp_debug);
  *(_DWORD *)(a1 + 4) = 0;
  if ( (v2 & 8) != 0 && !msm_cvp_debug_out )
    printk(&unk_90EDF, "dsp", "__dsp_cvp_set_session_name", (unsigned int)dword_6C7D4);
  result = get_inst_from_dsp((unsigned int)dword_6C7DC, dword_6C7D8);
  v4 = result;
  if ( result )
  {
    result = is_cvp_inst_valid(result);
    if ( (result & 1) != 0 )
      return (__int64)memcpy((void *)(v4 + 14996), &unk_6C8BC, 0x100u);
  }
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    result = printk(&unk_86629, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
  }
  *(_DWORD *)(a1 + 4) = -1;
  return result;
}
