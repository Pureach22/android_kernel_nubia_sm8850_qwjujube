__int64 __fastcall gsi_dump_evt(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  __int64 v3; // x19
  char *v6; // x0
  char *v7; // x0
  void (*v8)(void); // x8
  __int64 v9; // x0
  void (__fastcall *v10)(_QWORD); // x8
  __int64 v11; // x8
  __int64 v12; // x22
  int v13; // w23
  char *stringp; // [xsp+8h] [xbp-18h] BYREF
  int v15; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v16; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+18h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 > 0xFFF )
    goto LABEL_2;
  v3 = a3;
  v16 = 0;
  v15 = 0;
  _check_object_size(dbg_buff, a3, 0);
  if ( ((__int64 (__fastcall *)(__int64, __int64))inline_copy_from_user)(a2, v3) )
  {
    v3 = -14;
    goto LABEL_5;
  }
  dbg_buff[v3] = 0;
  stringp = dbg_buff;
  v6 = strsep(&stringp, " ");
  if ( !v6
    || (unsigned int)kstrtouint(v6, 0, &v16)
    || (v7 = strsep(&stringp, " ")) == nullptr
    || (unsigned int)kstrtouint(v7, 0, &v15) )
  {
LABEL_2:
    v3 = -22;
  }
  else if ( v16 >= *(_DWORD *)(gsi_ctx + 28612) )
  {
    printk(&unk_2D057, "gsi_dump_evt", 70);
    v3 = -22;
  }
  else
  {
    v8 = *(void (**)(void))(gsi_ctx + 152);
    if ( *((_DWORD *)v8 - 1) != -440107680 )
      __break(0x8228u);
    v8();
    gsihal_read_reg_nk(12, *(unsigned int *)(gsi_ctx + 20), v16);
    printk(&unk_2D593, "gsi_dump_evt", 78);
    gsihal_read_reg_nk(37, *(unsigned int *)(gsi_ctx + 20), v16);
    printk(&unk_2A8C4, "gsi_dump_evt", 81);
    gsihal_read_reg_nk(38, *(unsigned int *)(gsi_ctx + 20), v16);
    printk(&unk_2CCA0, "gsi_dump_evt", 84);
    gsihal_read_reg_nk(39, *(unsigned int *)(gsi_ctx + 20), v16);
    printk(&unk_2B7C1, "gsi_dump_evt", 87);
    gsihal_read_reg_nk(71, *(unsigned int *)(gsi_ctx + 20), v16);
    printk(&unk_2BFA9, "gsi_dump_evt", 90);
    gsihal_read_reg_nk(72, *(unsigned int *)(gsi_ctx + 20), v16);
    printk(&unk_2A793, "gsi_dump_evt", 93);
    gsihal_read_reg_nk(73, *(unsigned int *)(gsi_ctx + 20), v16);
    printk(&unk_2B3AA, "gsi_dump_evt", 96);
    gsihal_read_reg_nk(74, *(unsigned int *)(gsi_ctx + 20), v16);
    printk(&unk_2D1E5, "gsi_dump_evt", 99);
    gsihal_read_reg_nk(40, *(unsigned int *)(gsi_ctx + 20), v16);
    printk(&unk_2D5AD, "gsi_dump_evt", 102);
    gsihal_read_reg_nk(41, *(unsigned int *)(gsi_ctx + 20), v16);
    printk(&unk_2BBB4, "gsi_dump_evt", 105);
    gsihal_read_reg_nk(42, *(unsigned int *)(gsi_ctx + 20), v16);
    printk(&unk_2BFC3, "gsi_dump_evt", 108);
    gsihal_read_reg_nk(43, *(unsigned int *)(gsi_ctx + 20), v16);
    printk(&unk_2BDCD, "gsi_dump_evt", 111);
    gsihal_read_reg_nk(44, *(unsigned int *)(gsi_ctx + 20), v16);
    printk(&unk_2AE07, "gsi_dump_evt", 114);
    gsihal_read_reg_nk(45, *(unsigned int *)(gsi_ctx + 20), v16);
    printk(&unk_2E05D, "gsi_dump_evt", 117);
    gsihal_read_reg_nk(48, *(unsigned int *)(gsi_ctx + 20), v16);
    printk(&unk_2B7DB, "gsi_dump_evt", 120);
    gsihal_read_reg_nk(49, *(unsigned int *)(gsi_ctx + 20), v16);
    v9 = printk(&unk_2AF67, "gsi_dump_evt", 123);
    v10 = *(void (__fastcall **)(_QWORD))(gsi_ctx + 160);
    if ( *((_DWORD *)v10 - 1) != -440107680 )
      __break(0x8228u);
    v10(v9);
    if ( v15 )
    {
      if ( v16 > 0x1F )
      {
        __break(0x5512u);
        JUMPOUT(0x25D78);
      }
      v11 = gsi_ctx + 328LL * v16;
      if ( *(_QWORD *)(v11 + 18352) )
      {
        v12 = v11 + 18328;
        if ( *(_DWORD *)(v11 + 18340) >= 0x10u )
        {
          v13 = 0;
          do
          {
            printk(&unk_2A8DE, "gsi_dump_evt", 141);
            ++v13;
          }
          while ( (unsigned int)(unsigned __int16)v13 < *(_DWORD *)(v12 + 12) >> 4 );
        }
      }
      else
      {
        printk(&unk_2C801, "gsi_dump_evt", 143);
      }
    }
  }
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return v3;
}
