__int64 __fastcall walt_update_tg_pointer(__int64 a1)
{
  const char *v2; // x20

  v2 = *(const char **)(*(_QWORD *)(*(_QWORD *)a1 + 264LL) + 16LL);
  if ( !strcmp(v2, "top-app") )
    return walt_init_topapp_tg(a1);
  if ( !strcmp(v2, "foreground") )
    return walt_init_foreground_tg(a1);
  if ( !strcmp(v2, "background") )
    return walt_init_background_tg(a1);
  return walt_init_tg(a1);
}
