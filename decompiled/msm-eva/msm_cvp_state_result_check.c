__int64 __fastcall msm_cvp_state_result_check(__int64 a1, unsigned int a2, unsigned int a3)
{
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v5; // x9
  __int64 v6; // x19
  __int64 v7; // x0

  if ( !a2 )
    return a2;
  if ( a2 != -110 )
  {
    if ( *(_DWORD *)(a1 + 15256) )
    {
      a2 = -22;
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        printk(&unk_83D89, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
        return (unsigned int)-22;
      }
    }
    else
    {
      return 0;
    }
    return a2;
  }
  if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
  {
LABEL_5:
    if ( *(_DWORD *)(a1 + 328) != 9 )
      msm_cvp_comm_kill_session(a1);
    return (unsigned int)-110;
  }
  if ( a3 <= 0xA && *(_DWORD *)(a1 + 328) < 0xBu )
  {
    v5 = _ReadStatusReg(SP_EL0);
    v6 = a1;
    printk(&unk_83D4D, *(unsigned int *)(v5 + 1800), *(unsigned int *)(v5 + 1804), &unk_8E7CE);
    a1 = v6;
    goto LABEL_5;
  }
  __break(0x5512u);
  v7 = MEMORY[0x5D8318C]();
  return msm_cvp_comm_kill_session(v7);
}
