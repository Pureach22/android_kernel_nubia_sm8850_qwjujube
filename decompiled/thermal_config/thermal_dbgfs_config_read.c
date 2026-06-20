__int64 __fastcall thermal_dbgfs_config_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, __int64 a4)
{
  unsigned __int64 zone_by_name; // x23
  _DWORD *v8; // x22
  int v9; // w25
  int v10; // w20
  const char *v11; // x5
  int v12; // w20
  int v13; // w0
  int v14; // w20
  int v15; // w0
  int v16; // w0
  __int64 v17; // x4
  int v18; // w8
  size_t v19; // x27
  const char *v20; // x25
  unsigned __int64 v21; // x24
  __int64 v22; // x21
  unsigned int v23; // w19
  int v24; // w20
  bool v25; // w19
  int v26; // w20
  size_t v28; // x0
  int v29; // w20
  unsigned __int64 v30; // x3
  __int64 v31; // x8
  unsigned __int64 v32; // x20
  int v33; // w9
  unsigned __int64 v34; // x10
  _QWORD *v35; // x12
  __int64 v36; // x13
  int v37; // w19
  int v38; // w10
  __int64 v39; // x20
  int v40; // w21
  unsigned __int64 v41; // x20
  char v42; // w9
  char v43; // w8
  _QWORD *v44; // x27
  _QWORD *v45; // x28
  _QWORD *v46; // t1
  __int64 v47; // x10
  __int64 v48; // x22
  __int64 v49; // x1
  __int64 v50; // x24
  const char *v51; // x2
  const char *v52; // x19
  const char *v53; // x2
  int v54; // w0
  const char *v55; // x0
  size_t v56; // x0
  __int64 v57; // x19
  __int64 v58; // x24
  size_t v59; // x0
  int v60; // w8
  __int64 v61; // x19
  __int64 v62; // x24
  size_t v63; // x0
  int v64; // w8
  unsigned __int64 v65; // x19
  __int64 v66; // x20
  unsigned __int64 StatusReg; // x19
  __int64 v68; // x20
  size_t v69; // [xsp+0h] [xbp-90h]
  size_t v70; // [xsp+8h] [xbp-88h]
  unsigned __int64 v71; // [xsp+10h] [xbp-80h]
  size_t maxlen; // [xsp+18h] [xbp-78h]
  unsigned int v73; // [xsp+20h] [xbp-70h]
  unsigned int v74; // [xsp+20h] [xbp-70h]
  __int64 v75; // [xsp+28h] [xbp-68h]
  _DWORD *v76; // [xsp+30h] [xbp-60h]
  unsigned __int64 v77; // [xsp+38h] [xbp-58h]
  unsigned __int64 v78; // [xsp+40h] [xbp-50h]
  unsigned __int64 v79; // [xsp+48h] [xbp-48h]
  unsigned __int64 v80; // [xsp+50h] [xbp-40h]
  size_t v81; // [xsp+58h] [xbp-38h]
  int v82; // [xsp+60h] [xbp-30h]
  const char *v83; // [xsp+68h] [xbp-28h]
  const char *v84; // [xsp+70h] [xbp-20h]
  const char *v85; // [xsp+78h] [xbp-18h]
  int v86; // [xsp+8Ch] [xbp-4h]

  zone_by_name = thermal_zone_get_zone_by_name(&tzone_sensor_name);
  if ( zone_by_name >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_6FA1, "thermal_config", "thermal_dbgfs_config_read", &tzone_sensor_name, (unsigned int)zone_by_name);
    return (int)zone_by_name;
  }
  v8 = (_DWORD *)_kmalloc_cache_noprof(debugfs_create_dir, 3520, 4096);
  if ( !v8 )
    return -12;
  while ( 2 )
  {
    v78 = a2;
    v9 = scnprintf(v8, 4096, "%*s%s\n", -15, "sensor", (const char *)(zone_by_name + 4));
    v10 = scnprintf((char *)v8 + v9, 4096LL - v9, "%*s%s\n", -15, "algo_type", **(const char ***)(zone_by_name + 1216))
        + v9;
    if ( *(_DWORD *)(zone_by_name + 1040) )
      v11 = "enabled";
    else
      v11 = "disabled";
    v12 = scnprintf((char *)v8 + v10, 4096LL - v10, "%*s%s\n", -15, "mode", v11) + v10;
    v13 = jiffies_to_msecs(*(_QWORD *)(zone_by_name + 1072));
    v14 = scnprintf((char *)v8 + v12, 4096LL - v12, "%*s%d\n", -15, "polling_delay", v13) + v12;
    v15 = jiffies_to_msecs(*(_QWORD *)(zone_by_name + 1064));
    v16 = scnprintf((char *)v8 + v14, 4096LL - v14, "%*s%d\n", -15, "passive_delay", v15);
    v18 = *(_DWORD *)(zone_by_name + 1056);
    a2 = (unsigned int)(v16 + v14);
    if ( v18 )
    {
      v19 = 11 * v18;
      v20 = (const char *)_kmalloc_noprof(v19, 3520);
      while ( 1 )
      {
        v77 = a3;
        v79 = zone_by_name;
        a3 = _kmalloc_noprof(v19, 3520);
        if ( !a3 || !v20 )
        {
          kfree(v20);
          v55 = (const char *)a3;
          goto LABEL_114;
        }
        v76 = v8;
        if ( *(int *)(zone_by_name + 1056) < 1 )
          break;
        v21 = a2;
        zone_by_name = a4;
        v22 = 0;
        v23 = 0;
        v24 = 0;
        v8 = (_DWORD *)(v79 + 1444);
        while ( 1 )
        {
          v23 += scnprintf(&v20[v23], v19 - v23, "%d ", *(v8 - 1));
          if ( (v23 & 0x80000000) != 0 )
            break;
          v24 += scnprintf(a3 + (unsigned int)v24, v19 - (unsigned int)v24, "%d ", *v8);
          if ( v24 < 0 )
          {
            v23 = v24;
            break;
          }
          ++v22;
          v8 += 58;
          if ( v22 >= *(int *)(v79 + 1056) )
          {
            a2 = v21;
            v25 = v24 == 0;
            goto LABEL_19;
          }
        }
        v8 = v76;
        LODWORD(a2) = v21;
LABEL_39:
        kfree(v20);
        kfree(a3);
        if ( (v23 & 0x80000000) != 0 )
          goto LABEL_116;
        if ( (a2 & 0x80000000) != 0 )
        {
          v23 = a2;
          goto LABEL_116;
        }
        v73 = a2;
        a2 = v79;
        mutex_lock(v79 + 1248);
        v31 = *(int *)(v79 + 1056);
        v32 = v77;
        if ( (int)v31 < 1 )
          goto LABEL_74;
        v33 = 0;
        v34 = v79 + 1440;
        v80 = v79 + 1440;
        do
        {
          v35 = *(_QWORD **)(v34 + 208);
          while ( v35 != (_QWORD *)(v34 + 208) )
          {
            v36 = *(v35 - 20);
            v35 = (_QWORD *)*v35;
            if ( v36 )
              ++v33;
          }
          v34 += 232LL;
        }
        while ( 0x34F72C234F72C235LL * ((__int64)(v34 - v80) >> 3) < v31 );
        if ( !v33 )
        {
LABEL_74:
          mutex_unlock(v79 + 1248);
          v23 = v73;
          if ( (v73 & 0x80000000) != 0 )
            goto LABEL_116;
          goto LABEL_75;
        }
        v37 = 20 * (v33 + v31);
        v82 = v37;
        v85 = (const char *)_kmalloc_noprof(v37, 3520);
        v84 = (const char *)_kmalloc_noprof(v37, 3520);
        maxlen = v37;
        v83 = (const char *)_kmalloc_noprof(v37, 3520);
        if ( !v85 || !v84 || !v83 )
        {
          mutex_unlock(v79 + 1248);
          kfree(v85);
          kfree(v84);
          v55 = v83;
LABEL_114:
          kfree(v55);
          goto LABEL_115;
        }
        v38 = *(_DWORD *)(v79 + 1056);
        v69 = v37;
        v70 = v37;
        v71 = zone_by_name;
        if ( v38 >= 1 )
        {
          v39 = 0;
          v40 = 0;
          a3 = 0;
          zone_by_name = 0;
          do
          {
            if ( v38 < 1 )
              goto LABEL_54;
            v19 = v79 + 1440;
            v75 = v39;
            v41 = v80 + 232 * v39;
            v42 = 1;
            v43 = 1;
            v86 = v40;
            do
            {
              v81 = v19;
              v46 = *(_QWORD **)(v19 + 208);
              v44 = (_QWORD *)(v19 + 208);
              v45 = v46;
              if ( v46 != v44 )
              {
                do
                {
                  v47 = *(v45 - 20);
                  if ( v47 && *(v45 - 19) == v41 )
                  {
                    v48 = v37 - (int)a3;
                    v49 = v37 - v86;
                    v50 = v37 - (int)zone_by_name;
                    if ( (v43 & 1) != 0 )
                      v51 = " %s";
                    else
                      v51 = "+%s";
                    if ( (v43 & 1) != 0 )
                      v52 = " %ld";
                    else
                      v52 = "+%ld";
                    v86 += scnprintf(&v85[v86], v49, v51, *(_QWORD *)(v47 + 8));
                    a3 = (unsigned int)scnprintf(&v84[(int)a3], v48, v52, *(v45 - 17)) + (unsigned int)a3;
                    v53 = v52;
                    v37 = v82;
                    v54 = scnprintf(&v83[(int)zone_by_name], v50, v53, *(v45 - 16));
                    v43 = 0;
                    v42 = 0;
                    zone_by_name = (unsigned int)(v54 + zone_by_name);
                  }
                  v45 = (_QWORD *)*v45;
                }
                while ( v45 != v44 );
                v38 = *(_DWORD *)(v79 + 1056);
              }
              v19 = v81 + 232;
            }
            while ( 0x34F72C234F72C235LL * ((__int64)(v81 + 232 - v80) >> 3) < v38 );
            v39 = v75;
            v40 = v86;
            if ( (v42 & 1) != 0 )
            {
LABEL_54:
              v40 += scnprintf(&v85[v40], v37 - v40, " %s", "-");
              a3 = (unsigned int)scnprintf(&v84[(int)a3], v37 - (int)a3, " %s", "-") + (unsigned int)a3;
              zone_by_name = (unsigned int)scnprintf(&v83[(int)zone_by_name], v37 - (int)zone_by_name, " %s", "-")
                           + (unsigned int)zone_by_name;
              v38 = *(_DWORD *)(v79 + 1056);
            }
            ++v39;
          }
          while ( v39 < v38 );
        }
        a2 = v79;
        v56 = mutex_unlock(v79 + 1248);
        a4 = 4096LL - v73;
        if ( (int)v73 >= (int)a4 )
        {
          v8 = v76;
          v32 = v77;
          v64 = -22;
          goto LABEL_97;
        }
        v32 = v77;
        v8 = (_DWORD *)maxlen;
        if ( !maxlen )
          goto LABEL_105;
        v56 = strnlen(v85, maxlen);
        if ( v56 > maxlen )
          goto LABEL_106;
        if ( v56 >= maxlen )
          goto LABEL_107;
        if ( v56 >= (int)a4
          || (v56 = scnprintf((char *)v76 + v73, a4, "%*s%s\n", -14, "device", v85),
              v57 = (int)(v56 + v73),
              v58 = 4096 - v57,
              (int)(v56 + v73) >= 4096 - (int)v57) )
        {
          v64 = -22;
          v8 = v76;
LABEL_97:
          zone_by_name = v71;
LABEL_98:
          v74 = v64;
          kfree(v85);
          kfree(v84);
          kfree(v83);
          v23 = v74;
          if ( (v74 & 0x80000000) != 0 )
            goto LABEL_116;
LABEL_75:
          if ( v23 < 0x1000 )
          {
            *((_BYTE *)v8 + v23) = 0;
            v23 = simple_read_from_buffer(v78, v32, zone_by_name, v8, v23);
            goto LABEL_116;
          }
          v30 = a2 + 4;
LABEL_35:
          printk(&unk_6F39, "thermal_config", "thermal_dbgfs_config_read", v30, v17);
LABEL_115:
          v23 = -12;
LABEL_116:
          kfree(v8);
          return (int)v23;
        }
        zone_by_name = v71;
        v8 = (_DWORD *)v69;
        if ( !v69 )
          goto LABEL_105;
        v59 = strnlen(v84, v69);
        v8 = v76;
        if ( v59 > v69 )
          goto LABEL_108;
        if ( v59 >= v69 )
          goto LABEL_109;
        if ( v59 >= (int)v58 )
          goto LABEL_102;
        v56 = scnprintf((char *)v76 + v57, v58, "%*s%s\n", -14, "upper_limit", v84);
        v60 = v56 + v57;
        v61 = v60;
        v62 = 4096LL - v60;
        if ( v60 >= (int)v62 )
          goto LABEL_102;
        if ( !v70 )
          goto LABEL_105;
        v63 = strnlen(v83, v70);
        if ( v63 > v70 )
        {
          v63 = _fortify_panic(2, v70, v63 + 1);
        }
        else if ( v63 < v70 )
        {
          if ( v63 >= (int)v62 )
LABEL_102:
            v64 = -22;
          else
            v64 = scnprintf((char *)v76 + v61, v62, "%*s%s\n", -14, "lower_limit", v83) + v61;
          goto LABEL_98;
        }
        _fortify_panic(4, v70, v63 + 1);
        StatusReg = _ReadStatusReg(SP_EL0);
        v68 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &fetch_and_populate_trips__alloc_tag;
        v20 = (const char *)_kmalloc_noprof(v19, 3520);
        *(_QWORD *)(StatusReg + 80) = v68;
      }
      zone_by_name = a4;
      v25 = 1;
LABEL_19:
      a4 = 4096LL - (int)a2;
      if ( (int)a2 >= (int)a4 )
        goto LABEL_25;
      v28 = strnlen(v20, v19);
      if ( v28 > v19 )
        goto LABEL_103;
      if ( v28 >= v19 )
        goto LABEL_104;
      if ( v28 >= (int)a4 )
      {
LABEL_25:
        v8 = v76;
        v23 = -22;
        goto LABEL_39;
      }
      v29 = scnprintf((char *)v76 + (int)a2, 4096LL - (int)a2, "%*s%s\n", -15, "set_temp", v20) + a2;
      if ( v25 )
      {
        v23 = 0;
      }
      else
      {
        if ( v29 < 4096 - v29 )
        {
          v28 = strnlen((const char *)a3, v19);
          if ( v28 > v19 )
          {
LABEL_103:
            v28 = _fortify_panic(2, v19, v28 + 1);
LABEL_104:
            v56 = _fortify_panic(4, v19, v28 + 1);
LABEL_105:
            __break(1u);
LABEL_106:
            v56 = _fortify_panic(2, v8, v56 + 1);
LABEL_107:
            v59 = _fortify_panic(4, v8, v56 + 1);
LABEL_108:
            v59 = _fortify_panic(2, v69, v59 + 1);
LABEL_109:
            _fortify_panic(4, v69, v59 + 1);
            v65 = _ReadStatusReg(SP_EL0);
            v66 = *(_QWORD *)(v65 + 80);
            *(_QWORD *)(v65 + 80) = &_start_alloc_tags;
            v8 = (_DWORD *)_kmalloc_cache_noprof(debugfs_create_dir, 3520, 4096);
            *(_QWORD *)(v65 + 80) = v66;
            if ( v8 )
              continue;
            return -12;
          }
          v8 = v76;
          if ( v28 >= v19 )
            goto LABEL_104;
          if ( v28 < 4096 - v29 )
          {
            v23 = 0;
            LODWORD(a2) = scnprintf((char *)v76 + v29, 4096LL - v29, "%*s%s\n", -15, "clr_temp", (const char *)a3) + v29;
            goto LABEL_39;
          }
          v23 = -22;
          goto LABEL_38;
        }
        v23 = -22;
      }
      v8 = v76;
LABEL_38:
      LODWORD(a2) = v29;
      goto LABEL_39;
    }
    break;
  }
  if ( (unsigned int)a2 >= 0x1000 )
  {
    v30 = zone_by_name + 4;
    goto LABEL_35;
  }
  *((_BYTE *)v8 + a2) = 0;
  v26 = simple_read_from_buffer(v78, a3, a4, v8, a2);
  kfree(v8);
  return v26;
}
