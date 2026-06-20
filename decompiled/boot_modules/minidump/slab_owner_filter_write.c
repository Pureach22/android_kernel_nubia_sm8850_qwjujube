__int64 __fastcall slab_owner_filter_write(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  __int64 v4; // x1
  __int64 v5; // x10
  unsigned int v6; // w8
  int v7; // w2
  _QWORD v9[2]; // [xsp+0h] [xbp-10h] BYREF

  v3 = a3;
  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9[0] = 0;
  if ( (unsigned int)kstrtoul_from_user(a2, a3, 0, v9) )
  {
    if ( (unsigned int)__ratelimit(&slab_owner_filter_write__rs, "slab_owner_filter_write") )
      printk(&unk_11390B, v4);
    v3 = -22;
  }
  else if ( v9[0] )
  {
    v5 = 1;
    v6 = 0;
    v7 = 1;
    while ( 1 )
    {
      if ( (v9[0] & v5) != 0 )
      {
        if ( v6 > 0xD )
          __break(0x5512u);
        if ( !kmalloc_caches[v6] )
          break;
      }
      v7 *= 2;
      ++v6;
      v5 = v7;
      if ( v9[0] < (unsigned __int64)v7 )
        goto LABEL_12;
    }
    printk(&unk_112B4F, v9[0]);
    v3 = -22;
  }
  else
  {
LABEL_12:
    slab_owner_filter = v9[0];
  }
  _ReadStatusReg(SP_EL0);
  return v3;
}
