__int64 __fastcall sde_format_validate_fmt(__int64 a1, _DWORD *a2, int *a3)
{
  int v4; // w0
  _DWORD *v5; // x20
  int v6; // t1
  const char *sde_format_ext; // x0
  void *v9; // x0

  if ( !a2 || !a3 )
  {
    v9 = &unk_22F38C;
    goto LABEL_12;
  }
  v4 = *a3;
  if ( !*a3 )
  {
LABEL_10:
    v9 = &unk_235F4D;
LABEL_12:
    printk(v9, "sde_format_validate_fmt");
    return 4294967274LL;
  }
  v5 = a3 + 4;
  while ( 1 )
  {
    sde_format_ext = sde_get_sde_format_ext(v4, *((_QWORD *)v5 - 1));
    if ( sde_format_ext )
    {
      if ( *(_DWORD *)sde_format_ext == *a2 && *((_DWORD *)sde_format_ext + 7) == a2[7] )
        return 0;
    }
    v6 = *v5;
    v5 += 4;
    v4 = v6;
    if ( !v6 )
      goto LABEL_10;
  }
}
