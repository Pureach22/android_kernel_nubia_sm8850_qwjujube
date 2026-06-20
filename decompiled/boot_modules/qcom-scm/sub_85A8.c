__int64 sub_85A8()
{
  __asm { PRFM            #0x17, [X17,#0x1F78] }
  return _scm_smc_call();
}
