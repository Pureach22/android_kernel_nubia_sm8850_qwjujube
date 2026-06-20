__int64 __fastcall cvp_dsp_send_cmd_sync(_DWORD *a1, __int64 a2)
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  unsigned int v6; // w20
  __int64 v7; // x8
  unsigned __int64 v8; // x8

  if ( (msm_cvp_debug & 0x800) != 0 && !msm_cvp_debug_out )
    printk(&unk_852BB, "dsp", "cvp_dsp_send_cmd_sync", (unsigned int)*a1);
  LODWORD(qword_6CF10) = *a1;
  result = cvp_dsp_send_cmd(a1);
  if ( (_DWORD)result )
  {
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      v6 = result;
      printk(&unk_8E3C9, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      result = v6;
    }
LABEL_14:
    *(_DWORD *)(a2 + 4) = HIDWORD(qword_6CF10);
    *(_DWORD *)(a2 + 8) = qword_6CF18;
    LODWORD(qword_6CF10) = -1159857458;
    return result;
  }
  v7 = (unsigned int)*a1;
  if ( (unsigned int)v7 < 0xA )
  {
    if ( wait_for_completion_timeout((char *)&gfa_cv + 32 * v7 + 184, 150) )
    {
      result = 0;
    }
    else
    {
      result = 4294967186LL;
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v8 = _ReadStatusReg(SP_EL0);
        printk(&unk_92803, *(unsigned int *)(v8 + 1800), *(unsigned int *)(v8 + 1804), &unk_8E7CE);
        result = 4294967186LL;
      }
    }
    goto LABEL_14;
  }
  __break(0x5512u);
  return get_debug_level_str_1();
}
