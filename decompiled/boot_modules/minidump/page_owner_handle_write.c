__int64 __fastcall page_owner_handle_write(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  __int64 v4; // x1
  _QWORD v6[2]; // [xsp+0h] [xbp-10h] BYREF

  v3 = a3;
  v6[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6[0] = 0;
  if ( (unsigned int)kstrtoul_from_user(a2, a3, 0, v6) )
  {
    if ( (unsigned int)__ratelimit(&page_owner_handle_write__rs, "page_owner_handle_write") )
      printk(&unk_113F15, v4);
    v3 = -22;
  }
  else if ( v6[0] )
  {
    if ( v6[0] <= (unsigned __int64)md_pageowner_dump_size >> 14 )
    {
      page_owner_handles_size = (_UNKNOWN *)(v6[0] << 10);
    }
    else if ( (unsigned int)__ratelimit(&page_owner_handle_write__rs_135, "page_owner_handle_write") )
    {
      printk(&unk_1133D1, v6[0]);
    }
  }
  _ReadStatusReg(SP_EL0);
  return v3;
}
