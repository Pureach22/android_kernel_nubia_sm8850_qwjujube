__int64 __fastcall memstat_show(__int64 a1, const char **a2, __int64 a3)
{
  const char *v3; // x20
  __int64 v5; // x3
  __int64 *v6; // x8

  v3 = *a2;
  if ( !strcmp(*a2, "vmalloc") )
  {
    v6 = &qword_3A8A8;
LABEL_22:
    v5 = *v6;
    return (int)scnprintf(a3, 4096, "%llu\n", v5);
  }
  if ( !strcmp(v3, "vmalloc_max") )
  {
    v6 = &qword_3A8B0;
    goto LABEL_22;
  }
  if ( !strcmp(v3, "page_alloc") )
  {
    v6 = &qword_3A8B8;
    goto LABEL_22;
  }
  if ( !strcmp(v3, "page_alloc_max") )
  {
    v6 = &qword_3A8C0;
    goto LABEL_22;
  }
  if ( !strcmp(v3, "coherent") )
  {
    v6 = &qword_3A8C8;
    goto LABEL_22;
  }
  if ( !strcmp(v3, "coherent_max") )
  {
    v6 = &qword_3A8D0;
    goto LABEL_22;
  }
  if ( !strcmp(v3, "secure") )
  {
    v6 = &qword_3A8D8;
    goto LABEL_22;
  }
  if ( !strcmp(v3, "secure_max") )
  {
    v6 = &qword_3A8E0;
    goto LABEL_22;
  }
  if ( !strcmp(v3, "mapped") )
  {
    v6 = &qword_3A8E8;
    goto LABEL_22;
  }
  if ( !strcmp(v3, "mapped_max") )
  {
    v6 = &qword_3A8F0;
    goto LABEL_22;
  }
  v5 = 0;
  return (int)scnprintf(a3, 4096, "%llu\n", v5);
}
