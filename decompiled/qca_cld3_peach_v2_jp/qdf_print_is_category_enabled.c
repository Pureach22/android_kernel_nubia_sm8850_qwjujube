__int64 __fastcall qdf_print_is_category_enabled(unsigned int a1, unsigned int a2, __int64 a3, __int64 a4)
{
  char *v4; // x8
  __int64 v5; // x2
  void *v7; // x0

  if ( a1 >= 0x20 )
  {
    v5 = a1;
    v7 = &unk_999B93;
LABEL_10:
    printk(v7, "qdf_print_get_category_verbose", v5, a4);
    return 0;
  }
  v4 = (char *)&print_ctrl_obj + 392 * a1;
  if ( (v4[384] & 1) == 0 )
  {
    printk(&unk_9134FE, "qdf_print_get_category_verbose", a3, a4);
    return 0;
  }
  v5 = a2;
  if ( a2 >= 0xA7 )
  {
    v7 = &unk_91E391;
    goto LABEL_10;
  }
  if ( (392LL * a1 + 2 * (unsigned __int64)a2 + 32) >> 8 <= 0x30 )
    return *(unsigned __int16 *)&v4[2 * a2 + 32] != 0;
  __break(1u);
  return QDF_PRINT_INFO();
}
