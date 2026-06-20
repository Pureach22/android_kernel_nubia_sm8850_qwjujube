__int64 __fastcall dp_aux_deregister(__int64 a1)
{
  if ( a1 )
    return drm_dp_aux_unregister(a1 + 224);
  _ReadStatusReg(SP_EL0);
  return printk(&unk_275B6D, "dp_aux_deregister");
}
