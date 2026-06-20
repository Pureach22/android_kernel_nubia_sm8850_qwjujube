__int64 __fastcall sysfs_show_read(__int64 a1, __int64 a2, char *a3)
{
  const char *v4; // x20
  unsigned __int64 v5; // x21
  char *v6; // x23
  int v7; // w0
  int v8; // w19
  unsigned __int64 StatusReg; // x21
  __int64 v11; // x22

  v4 = (const char *)_kmalloc_cache_noprof(_wake_up, 3520, 1024);
  if ( !v4 )
    return -12;
  while ( byte_29BB24 )
  {
    v5 = 0;
    v6 = (char *)v4;
    while ( v5 != 64 )
    {
      v7 = snprintf(v6, 0x14u, "rbuf[%02d]=%02x ", v5, *((unsigned __int8 *)&zte_lcd_reg_debug + v5 + 5));
      ++v5;
      v6 += v7;
      if ( (v5 & 7) == 0 )
        *(_WORD *)v6++ = 10;
      if ( v5 >= (unsigned __int8)byte_29BB24 )
        goto LABEL_8;
    }
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v11 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &sysfs_show_read__alloc_tag;
    v4 = (const char *)_kmalloc_cache_noprof(_wake_up, 3520, 1024);
    *(_QWORD *)(StatusReg + 80) = v11;
    if ( !v4 )
      return -12;
  }
LABEL_8:
  v8 = snprintf(a3, 0x1000u, "read back:\n%s\n", v4);
  kfree(v4);
  return v8;
}
