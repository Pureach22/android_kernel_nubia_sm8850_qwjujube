void __fastcall gsi_set_max_elem_dp_stats(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  char *v5; // x0
  char *v6; // x0
  __int64 v7; // x2
  char *stringp; // [xsp+8h] [xbp-18h] BYREF
  int v9; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v10; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+18h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = 0;
  v9 = 0;
  stringp = nullptr;
  if ( a3 > 0xFFF )
    goto LABEL_19;
  _check_object_size(dbg_buff, a3, 0);
  if ( ((__int64 (__fastcall *)(__int64, unsigned __int64))inline_copy_from_user)(a2, a3) )
    goto LABEL_19;
  dbg_buff[a3] = 0;
  stringp = dbg_buff;
  v5 = strsep(&stringp, " ");
  if ( v5 )
  {
    if ( (unsigned int)kstrtouint(v5, 0, &v10) )
    {
      v7 = 381;
    }
    else
    {
      v6 = strsep(&stringp, " ");
      if ( !v6 )
      {
        if ( !(unsigned int)kstrtouint(dbg_buff, 0, &v10) && v10 < *(_DWORD *)(gsi_ctx + 28608) )
        {
          if ( v10 <= 0x23 )
          {
            printk(&unk_2B600, v10, *(unsigned __int16 *)(gsi_ctx + 448LL * v10 + 216));
LABEL_23:
            JUMPOUT(0x26980);
          }
LABEL_21:
          __break(0x5512u);
          JUMPOUT(0x269B8);
        }
LABEL_19:
        printk(&unk_2CCBA, "gsi_set_max_elem_dp_stats", 413);
        JUMPOUT(0x26970);
      }
      if ( !(unsigned int)kstrtouint(v6, 0, &v9) )
      {
        if ( v10 < *(_DWORD *)(gsi_ctx + 28608) )
        {
          if ( v10 <= 0x23 )
          {
            *(_WORD *)(gsi_ctx + 448LL * v10 + 216) = v9;
            goto LABEL_23;
          }
          goto LABEL_21;
        }
        printk(&unk_2E077, "gsi_set_max_elem_dp_stats", 404);
        goto LABEL_19;
      }
      v7 = 397;
    }
  }
  else
  {
    v7 = 376;
  }
  printk(&unk_2C011, "gsi_set_max_elem_dp_stats", v7);
  goto LABEL_19;
}
