__int64 __fastcall msm_cvp_deinit_core(__int64 a1)
{
  unsigned __int64 StatusReg; // x19
  __int64 v3; // x21
  __int64 v4; // x3
  int v5; // w8
  __int64 result; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( a1 && (v3 = *(_QWORD *)(a1 + 128)) != 0 && *(_QWORD *)(v3 + 256) )
  {
    mutex_lock(*(_QWORD *)(a1 + 128));
    mutex_lock(a1 + 80);
    v4 = *(unsigned int *)(a1 + 328);
    v5 = (msm_cvp_debug_out == 0) & (BYTE1(msm_cvp_debug) >> 5);
    if ( (_DWORD)v4 == 9 )
    {
      if ( v5 )
        printk(&unk_8E12E, "sess", a1, 8);
    }
    else
    {
      if ( v5 )
        printk(&unk_89763, "sess", a1, v4);
      *(_DWORD *)(a1 + 328) = 8;
    }
    mutex_unlock(a1 + 80);
    mutex_unlock(v3);
    return 0;
  }
  else
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      printk(&unk_83D1E, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      return 4294967274LL;
    }
  }
  return result;
}
