__int64 __fastcall elf_strtbl_add(char *src, __int64 a2, char a3, __int64 *a4)
{
  __int64 v5; // x8
  unsigned int v6; // w9
  __int64 v7; // x10
  unsigned int v8; // w8
  unsigned __int64 v10; // x8
  __int64 v11; // x8
  __int64 v12; // x21
  __int64 result; // x0
  __int64 v14; // x8

  if ( a3 == 1 )
    v5 = 50;
  else
    v5 = 62;
  v6 = 64;
  v7 = 52;
  v8 = *(unsigned __int16 *)(a2 + v5);
  if ( a3 == 1 )
    v6 = 40;
  else
    v7 = 64;
  v10 = a2 + v7 + v6 * (unsigned __int64)v8;
  if ( a3 == 1 )
  {
    v11 = *(unsigned int *)(v10 + 16);
    if ( a4 )
      goto LABEL_9;
  }
  else
  {
    v11 = *(_QWORD *)(v10 + 24);
    if ( a4 )
    {
LABEL_9:
      v12 = *a4;
      result = 0;
      if ( !src )
        return result;
      goto LABEL_13;
    }
  }
  v12 = 0;
  result = 0;
  if ( !src )
    return result;
LABEL_13:
  v14 = a2 + v11;
  if ( v14 )
  {
    strcpy((char *)(v14 + v12), src);
    if ( a4 )
      *a4 = v12 + strlen(src) + 1;
    return (unsigned int)v12;
  }
  return result;
}
