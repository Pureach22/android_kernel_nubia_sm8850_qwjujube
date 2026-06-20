__int64 __fastcall cpu_mpam_set_by_schemata(__int64 result, char *s1, const char *a3)
{
  int v3; // w19
  __int64 v5; // x21
  __int64 i; // x23
  __int64 v7; // x25
  __int64 v8; // x9
  __int64 v9; // x28
  int v10; // w8
  int *v11; // x9
  int v12; // w19
  size_t v13; // x0
  unsigned __int64 v14; // x2
  char *v15; // x0
  const char *v16; // x25
  int v18; // [xsp+8h] [xbp-148h] BYREF
  __int64 v19; // [xsp+Ch] [xbp-144h]
  int v20; // [xsp+14h] [xbp-13Ch]
  __int64 v21; // [xsp+18h] [xbp-138h]
  int v22; // [xsp+20h] [xbp-130h]
  int v23; // [xsp+24h] [xbp-12Ch]
  char *stringp; // [xsp+28h] [xbp-128h] BYREF
  char *v25; // [xsp+30h] [xbp-120h] BYREF
  int v26; // [xsp+3Ch] [xbp-114h] BYREF
  _QWORD v27[34]; // [xsp+40h] [xbp-110h] BYREF

  v27[32] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = mpam_msc_cnt;
  if ( mpam_msc_cnt >= 1 )
  {
    v5 = result;
    for ( i = 0; i < v3; ++i )
    {
      v7 = mpam_mscs;
      if ( s1 )
      {
        result = strcmp(s1, *(const char **)(mpam_mscs + 16 * i + 8));
        if ( (_DWORD)result )
          continue;
      }
      v8 = *(_QWORD *)(v5 + 144);
      v9 = *(unsigned int *)(v7 + 16 * i);
      v10 = *(_DWORD *)(v5 + 136);
      v26 = 0;
      v11 = (int *)(v8 + 16 * v9);
      memset(v27, 0, 256);
      stringp = (char *)v27;
      v22 = v9;
      v18 = v10 + 16;
      LODWORD(v19) = v11[1];
      v12 = *v11;
      HIDWORD(v19) = *v11;
      v20 = v11[2];
      v23 = v11[3];
      v21 = 6;
      v13 = strnlen(a3, 0x100u);
      if ( v13 == -1 )
      {
        _fortify_panic(2, -1, 0);
LABEL_35:
        _fortify_panic(7, 256, v14);
      }
      if ( v13 == 256 )
        v14 = 256;
      else
        v14 = v13 + 1;
      if ( v14 >= 0x101 )
        goto LABEL_35;
      sized_strscpy(v27, a3);
      while ( 1 )
      {
        v25 = strsep(&stringp, ",");
        if ( !v25 )
          break;
        v15 = strsep(&v25, "=");
        if ( v15 )
        {
          v16 = v15;
          if ( v25 )
          {
            if ( (kstrtouint(v25, 0, &v26) & 0x80000000) != 0 )
            {
              printk(&unk_809A);
            }
            else if ( !strcmp("cmax", v16) )
            {
              LODWORD(v19) = v26;
            }
            else if ( !strcmp("cpbm", v16) )
            {
              v12 = v26;
              HIDWORD(v19) = v26;
            }
            else if ( !strcmp("prio", v16) )
            {
              v20 = v26;
            }
            else if ( !strcmp("slc_partid", v16) )
            {
              v23 = v26;
            }
          }
        }
      }
      if ( !v12 )
        v19 = 0x100000000LL;
      result = qcom_mpam_set_cache_partition(&v18);
      if ( (_DWORD)result )
      {
        result = printk(&unk_7FAE);
      }
      else
      {
        *(_DWORD *)(*(_QWORD *)(v5 + 144) + 16 * v9 + 4) = v19;
        *(_DWORD *)(*(_QWORD *)(v5 + 144) + 16 * v9 + 8) = v20;
        *(_DWORD *)(*(_QWORD *)(v5 + 144) + 16 * v9 + 12) = v23;
        if ( v12 )
          *(_DWORD *)(*(_QWORD *)(v5 + 144) + 16 * v9) = HIDWORD(v19);
        else
          *(_DWORD *)(*(_QWORD *)(v5 + 144) + 16 * v9) = 0;
      }
      v3 = mpam_msc_cnt;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
