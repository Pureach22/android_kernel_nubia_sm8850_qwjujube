__int64 sub_657C10()
{
  __asm { LDTR            Q20, [X10,#0x20] }
  return dp_mon_desc_pool_free();
}
