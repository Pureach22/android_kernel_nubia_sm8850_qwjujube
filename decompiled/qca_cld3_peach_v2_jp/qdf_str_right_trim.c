size_t __fastcall qdf_str_right_trim(const char *a1)
{
  size_t result; // x0
  unsigned __int64 v3; // x10
  unsigned __int8 *v4; // x9

  result = strlen(a1);
  v3 = (unsigned __int64)&a1[result - 1];
  do
  {
    v4 = (unsigned __int8 *)v3;
    if ( v3 < (unsigned __int64)a1 )
      break;
    --v3;
  }
  while ( (*((_BYTE *)&ctype + *v4) & 0x20) != 0 );
  v4[1] = 0;
  return result;
}
