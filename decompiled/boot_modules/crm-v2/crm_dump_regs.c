__int64 __fastcall crm_dump_regs(char *s1)
{
  const char *v2; // x21
  __int64 v3; // x1
  __int64 v4; // x2
  __int64 v5; // x3
  unsigned __int64 v6; // x8

  v2 = (const char *)&crm_dev_list;
  do
  {
    v2 = *(const char **)v2;
    if ( v2 == (const char *)&crm_dev_list )
      return 4294967274LL;
  }
  while ( strcmp(s1, v2 - 272) );
  v6 = *((_QWORD *)v2 + 3);
  if ( v6 > 0xFFFFFFFFFFFFF000LL )
    return 4294967274LL;
  crm_dump_regs(*(_QWORD *)(v6 + 152), v3, v4, v5);
  return 0;
}
