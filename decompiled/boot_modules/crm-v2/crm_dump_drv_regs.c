__int64 __fastcall crm_dump_drv_regs(char *s1, int a2)
{
  const char *v4; // x22
  unsigned __int64 v5; // x8
  __int64 v6; // x1
  __int64 v7; // x8
  __int64 i; // x0

  v4 = (const char *)&crm_dev_list;
  while ( 1 )
  {
    v4 = *(const char **)v4;
    if ( v4 == (const char *)&crm_dev_list )
      break;
    if ( !strcmp(s1, v4 - 272) )
    {
      v5 = *((_QWORD *)v4 + 3);
      if ( v5 <= 0xFFFFFFFFFFFFF000LL )
      {
        if ( v5 )
        {
          v6 = *(_QWORD *)(v5 + 152);
          v7 = *(unsigned int *)(v6 + 48);
          if ( (int)v7 >= 1 )
          {
            for ( i = *(_QWORD *)(v6 + 40); *(_DWORD *)(i + 32) != a2; i += 192 )
            {
              if ( !--v7 )
                return 4294967274LL;
            }
            if ( i )
              return crm_dump_drv_regs(i, v6);
          }
        }
      }
      return 4294967274LL;
    }
  }
  return 4294967274LL;
}
