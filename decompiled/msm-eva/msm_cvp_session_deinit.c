__int64 __fastcall msm_cvp_session_deinit(__int64 a1)
{
  __int64 v1; // x19
  __int64 result; // x0
  unsigned __int64 v3; // x8
  __int64 v4; // x19
  unsigned __int64 StatusReg; // x8

  if ( a1 && *(_QWORD *)(a1 + 128) )
  {
    if ( (msm_cvp_debug & 0x2000) != 0 && !msm_cvp_debug_out )
    {
      v4 = a1;
      printk(&unk_8DE2C, "sess", "msm_cvp_session_deinit", a1);
      a1 = v4;
      if ( *(_QWORD *)(v4 + 320) )
      {
LABEL_6:
        v1 = a1;
        if ( (unsigned int)msm_cvp_comm_try_state(a1, 7) && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          StatusReg = _ReadStatusReg(SP_EL0);
          printk(&unk_86D52, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
        }
        return msm_cvp_session_deinit_buffers(v1);
      }
    }
    else if ( *(_QWORD *)(a1 + 320) )
    {
      goto LABEL_6;
    }
    return 0;
  }
  result = 4294967274LL;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v3 = _ReadStatusReg(SP_EL0);
    printk(&unk_912BD, *(unsigned int *)(v3 + 1800), *(unsigned int *)(v3 + 1804), &unk_8E7CE);
    return 4294967274LL;
  }
  return result;
}
