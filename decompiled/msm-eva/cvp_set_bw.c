__int64 __fastcall cvp_set_bw(_QWORD *a1, __int64 a2)
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  unsigned int v4; // w20

  if ( !a1[13] )
    return 4294967274LL;
  if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
    printk(&unk_8EDDF, &unk_8DA84, *a1, a2);
  result = icc_set_bw();
  if ( (_DWORD)result && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v4 = result;
    printk(&unk_84DBF, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    return v4;
  }
  return result;
}
