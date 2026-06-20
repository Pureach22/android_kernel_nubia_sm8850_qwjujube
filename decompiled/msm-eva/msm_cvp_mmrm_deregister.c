__int64 __fastcall msm_cvp_mmrm_deregister(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x8
  unsigned __int64 v4; // x25
  unsigned __int64 StatusReg; // x26
  unsigned __int64 v6; // x8
  unsigned __int64 v7; // x8
  unsigned __int64 v8; // x8
  unsigned int v9; // w20

  if ( a1 )
  {
    result = *(_QWORD *)(a1 + 2400);
    if ( result )
    {
      v3 = *(_QWORD *)(a1 + 2208);
      v4 = *(_QWORD *)(v3 + 280);
      if ( v4 < v4 + 32LL * *(unsigned int *)(v3 + 288) )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        do
        {
          if ( *(_BYTE *)(v4 + 28) == 1
            && (_clk_is_enabled(*(_QWORD *)(v4 + 16)) & 1) != 0
            && (unsigned int)msm_cvp_mmrm_set_value_in_range(a1, 0, 0)
            && (msm_cvp_debug & 1) != 0
            && !msm_cvp_debug_out )
          {
            printk(&unk_83C20, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
          }
          v4 += 32LL;
        }
        while ( v4 < *(_QWORD *)(*(_QWORD *)(a1 + 2208) + 280LL)
                   + 32 * (unsigned __int64)*(unsigned int *)(*(_QWORD *)(a1 + 2208) + 288LL) );
        result = *(_QWORD *)(a1 + 2400);
      }
      result = mmrm_client_deregister(result);
      if ( (_DWORD)result && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v8 = _ReadStatusReg(SP_EL0);
        v9 = result;
        printk(&unk_951CB, *(unsigned int *)(v8 + 1800), *(unsigned int *)(v8 + 1804), &unk_8E7CE);
        result = v9;
      }
      *(_QWORD *)(a1 + 2400) = 0;
    }
    else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v7 = _ReadStatusReg(SP_EL0);
      printk(&unk_93D15, *(unsigned int *)(v7 + 1800), *(unsigned int *)(v7 + 1804), &unk_8E7CE);
      return 0;
    }
  }
  else
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v6 = _ReadStatusReg(SP_EL0);
      printk(&unk_8A1B1, *(unsigned int *)(v6 + 1800), *(unsigned int *)(v6 + 1804), &unk_8E7CE);
      return 4294967274LL;
    }
  }
  return result;
}
