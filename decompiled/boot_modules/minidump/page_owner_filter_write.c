__int64 __fastcall page_owner_filter_write(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  __int64 v4; // x1
  void *v5; // x0
  _QWORD v7[2]; // [xsp+0h] [xbp-10h] BYREF

  v3 = a3;
  v7[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7[0] = 0;
  if ( (unsigned int)kstrtoul_from_user(a2, a3, 0, v7) )
  {
    if ( (unsigned int)__ratelimit(&page_owner_filter_write__rs, "page_owner_filter_write") )
    {
      v5 = &unk_11390B;
LABEL_8:
      printk(v5, v4);
      goto LABEL_9;
    }
    goto LABEL_9;
  }
  if ( v7[0] >= 0x10u )
  {
    if ( (unsigned int)__ratelimit(&page_owner_filter_write__rs_130, "page_owner_filter_write") )
    {
      v5 = &unk_113DB5;
      goto LABEL_8;
    }
LABEL_9:
    v3 = -22;
    goto LABEL_10;
  }
  page_owner_filter = v7[0];
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return v3;
}
