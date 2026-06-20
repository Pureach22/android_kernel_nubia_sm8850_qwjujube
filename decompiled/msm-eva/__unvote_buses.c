__int64 __fastcall _unvote_buses(__int64 a1)
{
  __int64 v2; // x8
  __int64 result; // x0
  unsigned __int64 v4; // x20
  unsigned __int64 StatusReg; // x8
  unsigned int v6; // w19

  kfree(*(_QWORD *)(a1 + 56));
  v2 = *(_QWORD *)(a1 + 2208);
  *(_QWORD *)(a1 + 56) = 0;
  *(_DWORD *)(a1 + 64) = 0;
  result = 0;
  v4 = *(_QWORD *)(v2 + 296);
  if ( v4 < v4 + 120LL * *(unsigned int *)(v2 + 304) )
  {
    while ( 1 )
    {
      result = cvp_set_bw(v4, 0);
      if ( (_DWORD)result )
        break;
      v4 += 120LL;
      if ( v4 >= *(_QWORD *)(*(_QWORD *)(a1 + 2208) + 296LL)
               + 120 * (unsigned __int64)*(unsigned int *)(*(_QWORD *)(a1 + 2208) + 304LL) )
        return 0;
    }
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      v6 = result;
      printk(&unk_94DAC, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      return v6;
    }
  }
  return result;
}
