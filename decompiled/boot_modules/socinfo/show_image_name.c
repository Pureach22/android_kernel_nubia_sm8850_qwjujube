__int64 __fastcall show_image_name(__int64 a1)
{
  const char *v1; // x2

  v1 = *(const char **)(a1 + 128);
  if ( *v1 )
    seq_printf(a1, "%s\n", v1);
  return 0;
}
