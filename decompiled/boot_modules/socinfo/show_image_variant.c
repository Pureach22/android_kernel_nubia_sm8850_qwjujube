__int64 __fastcall show_image_variant(__int64 a1)
{
  __int64 v1; // x2
  const char *v2; // x2
  int v3; // t1

  v1 = *(_QWORD *)(a1 + 128);
  v3 = *(unsigned __int8 *)(v1 + 75);
  v2 = (const char *)(v1 + 75);
  if ( v3 )
    seq_printf(a1, "%s\n", v2);
  return 0;
}
