// positive sp value has been detected, the output may be wrong!
__int64 __fastcall gsi_get_ring_len(__int64 a1)
{
  int v1; // w13
  __int64 v2; // x19

  if ( (unsigned int)a1 < 0x24 )
    return *(unsigned int *)(gsi_ctx + 448LL * (unsigned int)a1 + 368);
  __break(0x5512u);
  if ( (v1 & 0x1000000) == 0 )
    JUMPOUT(0x24BF8);
  printk(a1, v2, 414);
  _ReadStatusReg(SP_EL0);
  return -22;
}
