unsigned __int64 __fastcall get_inst_from_dsp(__int64 a1, unsigned int a2)
{
  __int64 v2; // x20
  unsigned __int64 v3; // x19
  __int64 *v4; // x9
  unsigned __int64 StatusReg; // x8

  if ( (_DWORD)a1 )
  {
    v2 = *(_QWORD *)(cvp_driver + 48);
    if ( v2 )
    {
      v3 = a2 | (unsigned __int64)(a1 << 32);
      mutex_lock(*(_QWORD *)(cvp_driver + 48));
      v4 = (__int64 *)(v2 + 280);
      while ( 1 )
      {
        v4 = (__int64 *)*v4;
        if ( v4 == (__int64 *)(v2 + 280) )
          break;
        if ( *((_DWORD *)v4 + 34) == 4 && v4 == (__int64 *)v3 )
        {
          mutex_unlock(v2);
          return v3;
        }
      }
      mutex_unlock(v2);
    }
    return 0;
  }
  v3 = 0;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    printk(&unk_9353B, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    return 0;
  }
  return v3;
}
