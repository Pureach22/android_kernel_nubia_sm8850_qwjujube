_QWORD *__fastcall _process_sys_error(_QWORD *result)
{
  unsigned int *v1; // x8
  int v2; // w20
  unsigned int *v3; // x19
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v5; // x8

  v1 = (unsigned int *)result[84];
  if ( v1 )
  {
    v2 = *v1;
    if ( *v1 <= 0x100000 )
    {
      v3 = v1 + 1;
      result = memchr(v1 + 1, 0, *v1);
      if ( !result )
        *((_BYTE *)v3 + (unsigned int)(v2 - 1)) = 0;
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        return (_QWORD *)printk(
                           &unk_88164,
                           *(unsigned int *)(StatusReg + 1800),
                           *(unsigned int *)(StatusReg + 1804),
                           &unk_8E7CE);
      }
    }
  }
  else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v5 = _ReadStatusReg(SP_EL0);
    return (_QWORD *)printk(&unk_8425E, *(unsigned int *)(v5 + 1800), *(unsigned int *)(v5 + 1804), &unk_8E7CE);
  }
  return result;
}
