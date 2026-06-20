__int64 __fastcall qcom_dcvs_register_voter(const char *a1, unsigned int a2, unsigned int a3)
{
  __int64 result; // x0
  __int64 v5; // x8
  __int64 v6; // x21
  const char *v8; // x20
  const char *v9; // x22
  unsigned int v10; // w19
  const char **v11; // x0
  char *v12; // x8
  char *v13; // x1

  result = 4294967274LL;
  if ( a1 && a2 <= 4 && a3 <= 2 )
  {
    if ( *(_BYTE *)(dcvs_data + 144) == 1 )
    {
      if ( dcvs_data
        && (v5 = *(_QWORD *)(dcvs_data + 8LL * a2 + 96)) != 0
        && (v6 = *(_QWORD *)(v5 + 8LL * a3 + 144)) != 0 )
      {
        mutex_lock(v6 + 72);
        if ( a3 == 1 && *(_DWORD *)(v6 + 64) )
        {
LABEL_13:
          v10 = -22;
        }
        else
        {
          v8 = (const char *)(v6 + 48);
          v9 = (const char *)(v6 + 48);
          while ( 1 )
          {
            v9 = *(const char **)v9;
            if ( v9 == v8 )
              break;
            if ( !strcmp(*((const char **)v9 - 3), a1) )
              goto LABEL_13;
          }
          v11 = (const char **)_kmalloc_cache_noprof(of_property_read_variable_u32_array, 3520, 40);
          if ( v11 )
          {
            *v11 = a1;
            v12 = (char *)(v11 + 3);
            v13 = *(char **)(v6 + 56);
            if ( v11 + 3 == (const char **)v8 || v13 == v12 || *(const char **)v13 != v8 )
            {
              _list_add_valid_or_report(v11 + 3, v13, v6 + 48);
            }
            else
            {
              *(_QWORD *)(v6 + 56) = v12;
              v11[3] = v8;
              v11[4] = v13;
              *(_QWORD *)v13 = v12;
            }
            v10 = 0;
            ++*(_DWORD *)(v6 + 64);
          }
          else
          {
            v10 = -12;
          }
        }
        mutex_unlock(v6 + 72);
        return v10;
      }
      else
      {
        return 4294967277LL;
      }
    }
    else
    {
      return 4294966779LL;
    }
  }
  return result;
}
