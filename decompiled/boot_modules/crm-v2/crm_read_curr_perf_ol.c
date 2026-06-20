__int64 __fastcall crm_read_curr_perf_ol(char *s1, unsigned int a2, _DWORD *a3)
{
  const char *v6; // x23
  unsigned __int64 v7; // x8
  __int64 v8; // x8

  v6 = (const char *)&crm_dev_list;
  while ( 1 )
  {
    v6 = *(const char **)v6;
    if ( v6 == (const char *)&crm_dev_list )
      break;
    if ( !strcmp(s1, v6 - 272) )
    {
      v7 = *((_QWORD *)v6 + 3);
      if ( v7 <= 0xFFFFFFFFFFFFF000LL )
      {
        v8 = *(_QWORD *)(v7 + 152);
        if ( *(_DWORD *)(v8 + 208) > a2 )
        {
          *a3 = readl_relaxed(
                  *(_QWORD *)(v8 + 200)
                + *(_DWORD *)(*(_QWORD *)(v8 + 216) + 16LL)
                + **(_DWORD **)(v8 + 216)
                + (*(_DWORD *)(*(_QWORD *)(v8 + 216) + 20LL) + *(_DWORD *)(*(_QWORD *)(v8 + 216) + 4LL)) * a2)
              & 7;
          return 0;
        }
      }
      return 4294967274LL;
    }
  }
  return 4294967274LL;
}
