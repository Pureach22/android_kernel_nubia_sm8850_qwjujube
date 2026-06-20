size_t __fastcall ipa3_write_nat_table_move(__int64 a1, int a2, unsigned __int64 a3)
{
  size_t v3; // x19
  char *v6; // x0
  __int64 v7; // x1
  void *v8; // x0
  _BOOL4 v9; // w20
  _BOOL4 *v10; // x0
  __int64 v11; // x1
  void *v12; // x0
  _BOOL4 *v13; // x20
  __int64 v14; // x1
  int v15; // [xsp+4h] [xbp-1Ch] BYREF
  char *stringp; // [xsp+8h] [xbp-18h] BYREF
  _BOOL4 v17; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+18h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 > 0x1000 || (v3 = a3, v17 = 0, _check_object_size(dbg_buff, a3, 0), inline_copy_from_user_0(a2, v3)) )
  {
    v3 = -14;
  }
  else
  {
    dbg_buff[v3] = 0;
    stringp = dbg_buff;
    v6 = strsep(&stringp, " ");
    if ( v6 && !(unsigned int)kstrtouint(v6, 0, &v17) )
    {
      if ( v17 )
        v8 = &unk_3F1E1A;
      else
        v8 = &unk_3EC112;
      v9 = !v17;
      printk(v8, v7);
      v17 = v9;
      v10 = (_BOOL4 *)_kmalloc_cache_noprof(sg_next, 3520, 4);
      if ( v10 )
      {
        v13 = v10;
        v15 = 262195;
        *v10 = v17;
        ipa3_disable_move_nat_resp();
        printk(&unk_3A993E, v14);
        __dsb(0xEu);
        if ( (unsigned int)ipa_send_msg(&v15, v13, ipa3_nat_move_free_cb) )
          printk(&unk_3EC124, v11);
        v12 = &unk_3C09E0;
      }
      else
      {
        v12 = &unk_3E6166;
        v3 = 14;
      }
      printk(v12, v11);
    }
    else
    {
      v3 = -22;
    }
  }
  _ReadStatusReg(SP_EL0);
  return v3;
}
