__int64 sub_5EA40C()
{
  __asm { LDTR            Q20, [X10,#0x20] }
  return dp_mon_desc_pool_free();
}
