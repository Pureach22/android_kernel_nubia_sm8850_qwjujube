__int64 __fastcall msm_cvp_get_session_info(__int64 a1, _DWORD *a2)
{
  __int64 v3; // x0
  __int64 inst_validate; // x0
  __int64 v6; // x3
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v9; // x19

  if ( a1 && a2 && (v3 = *(_QWORD *)(a1 + 128)) != 0 )
  {
    inst_validate = cvp_get_inst_validate(v3, a1);
    if ( inst_validate )
    {
      v6 = (unsigned int)(*(_DWORD *)(a1 + 324) ^ *(_DWORD *)(a1 + 320));
      *a2 = v6;
      if ( (msm_cvp_debug & 0x2000) != 0 && !msm_cvp_debug_out )
      {
        v9 = inst_validate;
        printk(&unk_95A95, "sess", "msm_cvp_get_session_info", v6);
        inst_validate = v9;
      }
      cvp_put_inst(inst_validate);
      return 0;
    }
    else
    {
      return 4294967192LL;
    }
  }
  else
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_912BD, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      return 4294967274LL;
    }
  }
  return result;
}
