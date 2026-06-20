size_t __fastcall tp_game_partition_write(__int64 a1, unsigned __int64 a2, size_t a3)
{
  __int64 v5; // x20
  __int64 v6; // x2
  void *v7; // x0
  void (__fastcall *v8)(__int64, char *); // x8
  char s[1024]; // [xsp+8h] [xbp-408h] BYREF
  __int64 v11; // [xsp+408h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = tpd_cdev;
  printk(&unk_39237, "tp_game_partition_write", 1024);
  if ( a3 >= 0x401 )
  {
    v7 = &unk_3924C;
LABEL_8:
    printk(v7, "tp_game_partition_write", v6);
    a3 = -22;
    goto LABEL_9;
  }
  memset(s, 0, sizeof(s));
  _check_object_size(s, a3, 0);
  if ( inline_copy_from_user((__int64)s, a2, a3) )
  {
    v7 = &unk_35311;
    goto LABEL_8;
  }
  v8 = *(void (__fastcall **)(__int64, char *))(v5 + 3480);
  if ( *((_DWORD *)v8 - 1) != 1693605810 )
    __break(0x8228u);
  v8(v5, s);
  snprintf((char *)(v5 + 65), 0x400u, "%s\n", s);
  printk(&unk_318B2, "tp_game_partition_write", v5 + 65);
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return a3;
}
