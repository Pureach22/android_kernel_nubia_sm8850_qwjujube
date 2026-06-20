__int64 __fastcall slab_owner_dump_size_write(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  __int64 v4; // x1
  __int64 v6[2]; // [xsp+0h] [xbp-10h] BYREF

  v3 = a3;
  v6[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6[0] = 0;
  if ( (unsigned int)kstrtoull_from_user(a2, a3, 0, v6) )
  {
    if ( (unsigned int)__ratelimit(&slab_owner_dump_size_write__rs, "slab_owner_dump_size_write") )
      printk(&unk_112A01, v4);
    v3 = -22;
  }
  else
  {
    update_dump_size((__int64)"SLABOWNER", v6[0], &md_slabowner_dump_addr, &md_slabowner_dump_size);
  }
  _ReadStatusReg(SP_EL0);
  return v3;
}
