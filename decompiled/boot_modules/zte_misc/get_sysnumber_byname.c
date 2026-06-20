__int64 __fastcall get_sysnumber_byname(char *s2)
{
  __int64 i; // x20
  const char *v3; // x0

  for ( i = 0; i != 256; i += 16 )
  {
    v3 = *(const char **)((char *)&zte_gpios + i + 8);
    if ( v3 && !strcmp(v3, s2) )
      return *(unsigned int *)((char *)&zte_gpios + i);
  }
  return 0;
}
