__int64 __fastcall change_cvp_inst_state(__int64 result, unsigned int a2)
{
  __int64 v2; // x19
  __int64 v4; // x3
  int v5; // w8
  unsigned __int64 StatusReg; // x8

  if ( result )
  {
    v2 = result;
    mutex_lock(result + 80);
    v4 = *(unsigned int *)(v2 + 328);
    v5 = (msm_cvp_debug_out == 0) & (BYTE1(msm_cvp_debug) >> 5);
    if ( (_DWORD)v4 == 9 )
    {
      if ( v5 )
        printk(&unk_8E12E, "sess", v2, a2);
    }
    else
    {
      if ( v5 )
        printk(&unk_89763, "sess", v2, v4);
      *(_DWORD *)(v2 + 328) = a2;
    }
    return mutex_unlock(v2 + 80);
  }
  else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    return printk(&unk_8E100, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
  }
  return result;
}
