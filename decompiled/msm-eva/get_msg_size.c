__int64 __fastcall get_msg_size(__int64 a1)
{
  __int64 v1; // x8
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8

  v1 = *(_QWORD *)(cvp_driver + 48);
  if ( !v1 )
    return 0;
  if ( **(_QWORD **)(v1 + 256) )
  {
    if ( *(_DWORD *)(a1 + 4) == 35655684 )
      return 60;
    else
      return 68;
  }
  else
  {
    result = 0;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_89BB3, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      return 0;
    }
  }
  return result;
}
