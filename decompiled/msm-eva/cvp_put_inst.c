unsigned int *__fastcall cvp_put_inst(unsigned int *result)
{
  unsigned int *v1; // x4
  unsigned __int64 StatusReg; // x8
  int v8; // w8

  v1 = result;
  if ( result && result[3706] )
  {
    result += 3706;
    __asm { PRFM            #0x11, [X0] }
    do
      v8 = __ldxr(result);
    while ( __stlxr(v8 - 1, result) );
    if ( v8 == 1 )
    {
      __dmb(9u);
      return (unsigned int *)msm_cvp_destroy(v1);
    }
    else if ( v8 <= 0 )
    {
      return (unsigned int *)refcount_warn_saturate();
    }
  }
  else
  {
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      result = (unsigned int *)printk(
                                 &unk_93304,
                                 *(unsigned int *)(StatusReg + 1800),
                                 *(unsigned int *)(StatusReg + 1804),
                                 &unk_8E7CE);
    }
    __break(0x800u);
  }
  return result;
}
