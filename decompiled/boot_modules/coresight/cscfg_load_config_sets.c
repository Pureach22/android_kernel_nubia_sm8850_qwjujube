__int64 __fastcall cscfg_load_config_sets(__int64 **a1, const char ***a2, char *a3)
{
  _QWORD *v6; // x25
  unsigned int v7; // w20
  const char **v8; // x22
  int v9; // w26
  const char ***v10; // x27
  _QWORD *v11; // x28
  const char *v12; // x23
  _QWORD *i; // x23
  unsigned int feat_csdev; // w0
  __int64 v15; // x2
  char *v16; // x1
  char *v17; // x0
  const char **v18; // x8
  __int64 **v19; // x26
  __int64 *v20; // x22
  int v21; // w28
  __int64 **v22; // x27
  _QWORD *v23; // x23
  __int64 v24; // x28
  __int64 v25; // x27
  __int64 v26; // x26
  const char *v27; // x23
  _QWORD *v28; // x20
  _QWORD *v29; // x20
  unsigned int v30; // w0
  _QWORD *v31; // x0
  _QWORD *v32; // x2
  _QWORD *v33; // x1
  _QWORD *v34; // x2
  char *v35; // x1
  __int64 v36; // x9
  __int64 v37; // x8
  __int64 *v38; // x0
  int v39; // w20
  int v40; // w0
  __int64 *v41; // x0
  int v42; // w20
  __int64 *v43; // x8
  int v44; // w10
  int v45; // w20
  _QWORD *v46; // x9
  _QWORD *v47; // x21
  int v48; // w8
  _QWORD *j; // x21
  _QWORD *v50; // x10
  __int64 v51; // x9
  char **v52; // x8
  __int64 v53; // x9
  const char ***v55; // [xsp+0h] [xbp-20h]
  int v56; // [xsp+Ch] [xbp-14h]
  __int64 **v57; // [xsp+10h] [xbp-10h]
  __int64 **v58; // [xsp+18h] [xbp-8h]

  mutex_lock(&cscfg_mutex);
  v6 = (_QWORD *)cscfg_mgr;
  if ( !*(_DWORD *)(cscfg_mgr + 1176) )
  {
    v58 = a1;
    *(_DWORD *)(cscfg_mgr + 1176) = 1;
    if ( a2 )
    {
      v8 = *a2;
      if ( *a2 )
      {
        v9 = 0;
        v10 = a2;
        do
        {
          v11 = v6 + 116;
          while ( 1 )
          {
            v11 = (_QWORD *)*v11;
            if ( v11 == v6 + 116 )
              break;
            v12 = *v8;
            if ( !strcmp((const char *)*(v11 - 2), *v8) )
            {
              v7 = -17;
LABEL_80:
              printk(&unk_12952, v12);
              goto LABEL_95;
            }
          }
          for ( i = (_QWORD *)v6[114]; i != v6 + 114; i = (_QWORD *)*i )
          {
            if ( ((_DWORD)v8[4] & *(_DWORD *)(i - 2)) != 0 )
            {
              feat_csdev = cscfg_load_feat_csdev(*(i - 3), v8, i - 1);
              if ( feat_csdev )
              {
                v7 = feat_csdev;
                v12 = **v10;
                goto LABEL_80;
              }
              v6 = (_QWORD *)cscfg_mgr;
            }
          }
          v15 = v6[116];
          v16 = (char *)(v6 + 116);
          v17 = (char *)(v8 + 2);
          if ( *(_QWORD **)(v15 + 8) != v6 + 116 || v17 == v16 || (char *)v15 == v17 )
          {
            _list_add_valid_or_report(v17, v16);
            v6 = (_QWORD *)cscfg_mgr;
          }
          else
          {
            *(_QWORD *)(v15 + 8) = v17;
            v8[2] = (const char *)v15;
            v8[3] = v16;
            *(_QWORD *)v16 = v17;
          }
          v18 = *v10;
          v10 = &a2[++v9];
          v18[8] = a3;
          v8 = *v10;
        }
        while ( *v10 );
      }
    }
    v19 = a1;
    if ( a1 )
    {
      v20 = *a1;
      if ( *a1 )
      {
        v21 = 0;
        v22 = a1;
        v55 = a2;
        do
        {
          v23 = v6 + 118;
          while ( 1 )
          {
            v23 = (_QWORD *)*v23;
            if ( v23 == v6 + 118 )
              break;
            if ( !strcmp((const char *)*(v23 - 2), (const char *)*v20) )
            {
              v7 = -17;
LABEL_71:
              printk(&unk_12590, **v22);
              goto LABEL_95;
            }
          }
          v56 = v21;
          v24 = *((unsigned int *)v20 + 8);
          v57 = v22;
          if ( (int)v24 >= 1 )
          {
            v25 = v20[5];
            v26 = 0;
            while ( 2 )
            {
              v27 = *(const char **)(v25 + 8 * v26);
              v28 = v6 + 116;
              do
              {
                v28 = (_QWORD *)*v28;
                if ( v28 == v6 + 116 )
                {
                  v22 = v57;
                  v7 = -22;
                  goto LABEL_71;
                }
              }
              while ( strcmp((const char *)*(v28 - 2), v27) );
              if ( ++v26 != v24 )
                continue;
              break;
            }
          }
          v19 = v58;
          a2 = v55;
          v29 = v6 + 114;
          v22 = v57;
          while ( 1 )
          {
            v29 = (_QWORD *)*v29;
            if ( v29 == (_QWORD *)(cscfg_mgr + 912) )
              break;
            v30 = cscfg_add_csdev_cfg(*(v29 - 3), v20);
            if ( v30 )
              goto LABEL_98;
          }
          v30 = etm_perf_add_symlink_cscfg(cscfg_mgr, v20);
          if ( v30 )
          {
LABEL_98:
            v7 = v30;
            goto LABEL_71;
          }
          v6 = (_QWORD *)cscfg_mgr;
          v31 = v20 + 2;
          v32 = *(_QWORD **)(cscfg_mgr + 944);
          v33 = (_QWORD *)(cscfg_mgr + 944);
          if ( v32[1] != cscfg_mgr + 944 || v31 == v33 || v32 == v31 )
          {
            _list_add_valid_or_report(v31, v33);
            v6 = (_QWORD *)cscfg_mgr;
          }
          else
          {
            v32[1] = v31;
            v20[2] = (__int64)v32;
            v20[3] = (__int64)v33;
            *v33 = v31;
          }
          *((_DWORD *)v20 + 18) = 0;
          v21 = v56 + 1;
          (*v57)[10] = (__int64)a3;
          v22 = &v58[v56 + 1];
          *((_BYTE *)*v57 + 96) = 0;
          v20 = *v22;
        }
        while ( *v22 );
      }
    }
    v34 = v6 + 120;
    v35 = (char *)v6[121];
    if ( v6 + 120 == (_QWORD *)a3 || v35 == a3 || *(_QWORD **)v35 != v34 )
    {
      _list_add_valid_or_report(a3, v35);
    }
    else
    {
      v6[121] = a3;
      *(_QWORD *)a3 = v34;
      *((_QWORD *)a3 + 1) = v35;
      *(_QWORD *)v35 = a3;
    }
    v36 = *(_QWORD *)(cscfg_mgr + 960);
    if ( v36 == cscfg_mgr + 960 || v36 != *(_QWORD *)(cscfg_mgr + 968) )
    {
      v37 = *((_QWORD *)a3 + 1);
      if ( *(_DWORD *)(v37 + 16) == 1 && (try_module_get(*(_QWORD *)(v37 + 24)) & 1) == 0 )
      {
        v48 = -22;
        goto LABEL_91;
      }
    }
    mutex_unlock(&cscfg_mutex);
    if ( a2 )
    {
      v38 = (__int64 *)*a2;
      if ( *a2 )
      {
        v39 = 1;
        do
        {
          v40 = cscfg_configfs_add_feature(v38);
          if ( v40 )
            goto LABEL_72;
          v38 = (__int64 *)a2[v39++];
        }
        while ( v38 );
      }
    }
    if ( v19 )
    {
      v41 = *v19;
      if ( *v19 )
      {
        v42 = 1;
        while ( 1 )
        {
          v40 = cscfg_configfs_add_config(v41);
          if ( v40 )
            break;
          v41 = v19[v42++];
          if ( !v41 )
            goto LABEL_66;
        }
LABEL_72:
        v45 = v40;
        mutex_lock(&cscfg_mutex);
        v46 = (_QWORD *)cscfg_mgr;
        v47 = *(_QWORD **)(cscfg_mgr + 944);
        if ( v47 == (_QWORD *)(cscfg_mgr + 944) )
        {
          v48 = v45;
        }
        else
        {
          v48 = v45;
          do
          {
            if ( (char *)v47[8] == a3 )
            {
              cscfg_configfs_del_config((__int64)(v47 - 2));
              v46 = (_QWORD *)cscfg_mgr;
              v48 = v45;
            }
            v47 = (_QWORD *)*v47;
          }
          while ( v47 != v46 + 118 );
        }
        for ( j = (_QWORD *)v46[116]; j != v46 + 116; j = (_QWORD *)*j )
        {
          if ( (char *)j[6] == a3 )
          {
            cscfg_configfs_del_feature((__int64)(j - 2));
            v46 = (_QWORD *)cscfg_mgr;
            v48 = v45;
          }
        }
        v50 = (_QWORD *)v46[120];
        if ( v50 == v46 + 120 || v50 != (_QWORD *)v46[121] )
        {
          v51 = *((_QWORD *)a3 + 1);
          if ( *(_DWORD *)(v51 + 16) == 1 )
          {
            module_put(*(_QWORD *)(v51 + 24));
            v48 = v45;
          }
        }
LABEL_91:
        v7 = v48;
        v52 = *((char ***)a3 + 1);
        if ( *v52 == a3 && (v53 = *(_QWORD *)a3, *(char **)(*(_QWORD *)a3 + 8LL) == a3) )
        {
          *(_QWORD *)(v53 + 8) = v52;
          *v52 = (char *)v53;
        }
        else
        {
          _list_del_entry_valid_or_report(a3);
        }
        *(_QWORD *)a3 = 0xDEAD000000000100LL;
        *((_QWORD *)a3 + 1) = 0xDEAD000000000122LL;
LABEL_95:
        cscfg_unload_owned_cfgs_feats(a3);
        goto LABEL_96;
      }
LABEL_66:
      mutex_lock(&cscfg_mutex);
      v43 = *v19;
      if ( *v19 )
      {
        v44 = 1;
        do
        {
          *((_BYTE *)v43 + 96) = 1;
          v43 = v19[v44++];
        }
        while ( v43 );
      }
      v7 = 0;
    }
    else
    {
      mutex_lock(&cscfg_mutex);
      v7 = 0;
    }
LABEL_96:
    *(_DWORD *)(cscfg_mgr + 1176) = 0;
    goto LABEL_97;
  }
  v7 = -16;
LABEL_97:
  mutex_unlock(&cscfg_mutex);
  return v7;
}
