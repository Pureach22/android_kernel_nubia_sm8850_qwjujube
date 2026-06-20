const char **__fastcall _hwmon_device_register(__int64 a1, char *s, _QWORD *a3, _QWORD *a4, __int64 a5)
{
  const char *v7; // x28
  const char **result; // x0
  __int64 v10; // x24
  const char **v11; // x25
  int v12; // w9
  __int64 v13; // x10
  unsigned int v14; // w8
  __int64 v15; // x0
  __int64 *v16; // x8
  __int64 v17; // x21
  int v18; // w20
  int v19; // w22
  int v20; // w23
  __int64 v22; // x0
  unsigned __int64 v23; // x22
  __int64 *v24; // x12
  unsigned int **v25; // x8
  unsigned int *v26; // x15
  int v27; // w13
  int v28; // w9
  const char *v29; // x14
  __int64 v30; // x10
  unsigned int v31; // w23
  __int64 v32; // x11
  unsigned int v33; // w3
  unsigned int v34; // w9
  const char *v35; // x20
  _BOOL4 v36; // w25
  __int64 (__fastcall *v37)(_QWORD *, _QWORD, _QWORD); // x8
  __int16 v38; // w0
  __int16 v39; // w21
  unsigned __int64 v40; // x22
  __int64 v42; // x3
  __int64 (__fastcall *v43)(); // x8
  __int64 v44; // x10
  __int64 v45; // x10
  const char *v47; // x19
  int v48; // w23
  int v49; // w20
  __int64 v50; // x21
  __int64 v51; // x8
  char *v52; // x8
  __int64 v53; // x8
  int v54; // w9
  int string; // w0
  __int64 v56; // x0
  const char *v57; // x8
  int v58; // w0
  __int64 v59; // x8
  int v60; // w20
  int v61; // w0
  __int64 v62; // x0
  int v63; // w20
  __int64 v64; // x21
  unsigned __int64 StatusReg; // x19
  __int64 v66; // x20
  const char *v67; // [xsp+10h] [xbp-90h]
  __int64 v68; // [xsp+18h] [xbp-88h]
  _QWORD *v69; // [xsp+20h] [xbp-80h]
  const char **v70; // [xsp+28h] [xbp-78h]
  __int64 v71; // [xsp+30h] [xbp-70h]
  __int64 *v72; // [xsp+38h] [xbp-68h]
  int v73; // [xsp+44h] [xbp-5Ch]
  unsigned __int64 v74; // [xsp+48h] [xbp-58h]
  unsigned __int64 v75; // [xsp+50h] [xbp-50h]
  unsigned int v77; // [xsp+64h] [xbp-3Ch]
  unsigned int *v78; // [xsp+68h] [xbp-38h]
  __int64 v79; // [xsp+70h] [xbp-30h]
  unsigned __int64 v80; // [xsp+78h] [xbp-28h]
  char *v81; // [xsp+80h] [xbp-20h]
  __int64 v82; // [xsp+88h] [xbp-18h]
  _QWORD v83[2]; // [xsp+90h] [xbp-10h] BYREF

  v7 = s;
  v83[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v83[0] = 0;
  if ( s && (!*s || strpbrk(s, "-* \t\n")) )
    dev_warn(a1, "hwmon: '%s' is not a valid name attribute, please fix\n", v7);
  LODWORD(result) = ida_alloc_range(&hwmon_ida, 0, 0xFFFFFFFFLL, 3264);
  v10 = (unsigned int)result;
  if ( ((unsigned int)result & 0x80000000) != 0 )
  {
    result = (const char **)(int)result;
    goto LABEL_148;
  }
  v11 = (const char **)_kmalloc_cache_noprof(device_register, 3520, 1000);
  if ( !v11 )
  {
LABEL_146:
    LODWORD(v23) = -12;
    goto LABEL_147;
  }
  while ( 2 )
  {
    if ( !a4 )
      goto LABEL_113;
    if ( a5 && *(_QWORD *)a5 )
    {
      v12 = 2;
      do
      {
        v13 = *(_QWORD *)(a5 + 8LL * (v12 - 1));
        v14 = ++v12;
      }
      while ( v13 );
    }
    else
    {
      v14 = 2;
    }
    if ( (v14 & 0x80000000) != 0 )
    {
      v11[124] = nullptr;
      goto LABEL_138;
    }
    v15 = _kmalloc_noprof(8LL * v14, 3520);
    v11[124] = (const char *)v15;
    if ( !v15 )
      goto LABEL_138;
    v16 = (__int64 *)a4[1];
    v17 = *v16;
    if ( !*v16 )
      goto LABEL_90;
    v72 = (__int64 *)a5;
    v18 = 0;
    LODWORD(a5) = 0;
    do
    {
      if ( **(_DWORD **)(v17 + 8) )
      {
        v19 = 0;
        v20 = 1;
        do
          v19 += _sw_hweight32();
        while ( *(_DWORD *)(*(_QWORD *)(v17 + 8) + 4LL * v20++) );
        v16 = (__int64 *)a4[1];
      }
      else
      {
        v19 = 0;
      }
      ++v18;
      a5 = (unsigned int)(v19 + a5);
      v17 = v16[v18];
    }
    while ( v17 );
    if ( !(_DWORD)a5 )
    {
LABEL_90:
      LODWORD(v23) = -22;
      v47 = v11[122];
      if ( v47 )
        goto LABEL_140;
      goto LABEL_144;
    }
    if ( (int)a5 + 1 < 0
      || (v80 = 8LL * (unsigned int)(a5 + 1), v22 = _kmalloc_noprof(v80, 3520), v23 = v22, v24 = v72, !v22) )
    {
      LODWORD(v23) = -12;
      v47 = v11[122];
      if ( v47 )
        goto LABEL_140;
      goto LABEL_144;
    }
    v25 = (unsigned int **)a4[1];
    v26 = *v25;
    if ( !*v25 )
      goto LABEL_107;
    v27 = 0;
    v28 = 0;
    _ReadStatusReg(SP_EL0);
    v67 = v7;
    v70 = v11;
    v71 = v10;
    v68 = a1;
    v69 = a4;
    v74 = v22;
    while ( 2 )
    {
      v30 = *v26;
      if ( (unsigned int)v30 > 9 )
      {
        LODWORD(v29) = -22;
        goto LABEL_97;
      }
      v31 = **((_DWORD **)v26 + 1);
      v79 = v28;
      if ( !v31 )
      {
        v23 = v74;
        LODWORD(v29) = 0;
        goto LABEL_30;
      }
      v32 = *a4;
      v29 = nullptr;
      a4 = a3;
      v33 = 0;
      v73 = v27;
      v78 = v26;
      v75 = v74 + 8LL * v28;
      v81 = _templates[v30];
      v82 = v32;
      v34 = _templates_size[v30];
      v77 = v34;
      while ( 1 )
      {
        a5 = __clz(__rbit32(v31));
        if ( (unsigned int)a5 >= v34 )
          goto LABEL_36;
        v35 = *(const char **)&v81[8 * (unsigned int)a5];
        if ( !v35 )
          goto LABEL_36;
        v10 = *v26;
        if ( (_DWORD)a5 == 21 && (_DWORD)v10 == 1
          || (_DWORD)a5 == 10 && (v10 & 0xFFFFFFFE) == 2
          || (_DWORD)a5 == 22 && (_DWORD)v10 == 4
          || (_DWORD)a5 == 2 && (unsigned int)(v10 - 5) < 2 )
        {
          v7 = v29;
          v36 = 1;
        }
        else
        {
          v7 = v29;
          v36 = (_DWORD)a5 == 2 && (_DWORD)v10 == 7;
        }
        a1 = v33;
        v37 = *(__int64 (__fastcall **)(_QWORD *, _QWORD, _QWORD))v82;
        if ( *(_DWORD *)(*(_QWORD *)v82 - 4LL) != 575386056 )
          __break(0x8228u);
        v38 = v37(a4, (unsigned int)v10, (unsigned int)a5);
        if ( v38 )
          break;
        v26 = v78;
        v29 = v7;
        v33 = a1;
LABEL_35:
        v34 = v77;
LABEL_36:
        v31 &= ~(1 << a5);
        if ( !v31 )
        {
          v31 = *(_DWORD *)(*((_QWORD *)v26 + 1) + 4LL * (int)++v33);
          if ( !v31 )
            goto LABEL_88;
        }
      }
      v39 = v38;
      if ( (v38 & 0x124) != 0 )
      {
        if ( v36 )
        {
          if ( !*(_QWORD *)(v82 + 16) )
            goto LABEL_86;
        }
        else if ( !*(_QWORD *)(v82 + 8) )
        {
          goto LABEL_86;
        }
      }
      if ( (v38 & 0x92) == 0 || *(_QWORD *)(v82 + 24) )
      {
        v40 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 88);
        if ( !v40 )
        {
          LODWORD(v40) = -12;
          goto LABEL_87;
        }
        if ( (_DWORD)v10 )
        {
          if ( (_DWORD)v10 == 9 || (_DWORD)v10 == 2 )
            v42 = (unsigned int)a1;
          else
            v42 = (unsigned int)(a1 + 1);
          scnprintf(v40 + 52, 32, v35, v42);
          v35 = (const char *)(v40 + 52);
          a4 = a3;
        }
        v33 = a1;
        v43 = hwmon_attr_show;
        if ( v36 )
          v43 = hwmon_attr_show_string;
        *(_DWORD *)(v40 + 40) = v10;
        *(_DWORD *)(v40 + 44) = a5;
        *(_QWORD *)(v40 + 16) = v43;
        *(_DWORD *)(v40 + 48) = a1;
        *(_QWORD *)(v40 + 24) = hwmon_attr_store;
        *(_QWORD *)(v40 + 32) = v82;
        *(_QWORD *)v40 = v35;
        *(_WORD *)(v40 + 8) = v39;
        if ( v40 > 0xFFFFFFFFFFFFF000LL )
          goto LABEL_87;
        v44 = (int)v7 + v79;
        if ( v44 < 0 )
          goto LABEL_145;
        if ( v80 < 8 * v44 )
          goto LABEL_145;
        if ( v80 - 8 * v44 < 8 )
          goto LABEL_145;
        v26 = v78;
        v45 = v79 + (int)v7;
        if ( v45 < 0 || v80 < 8 * v45 || v80 - 8 * v45 < 8 )
          goto LABEL_145;
        v29 = (const char *)(unsigned int)((_DWORD)v7 + 1);
        *(_QWORD *)(v75 + 8LL * (int)v7) = v40;
        goto LABEL_35;
      }
LABEL_86:
      LODWORD(v40) = -22;
LABEL_87:
      LODWORD(v29) = v40;
LABEL_88:
      v11 = v70;
      v10 = v71;
      v7 = v67;
      a1 = v68;
      if ( ((unsigned int)v29 & 0x80000000) == 0 )
      {
        a4 = v69;
        v24 = v72;
        v23 = v74;
        v27 = v73;
        v25 = (unsigned int **)v69[1];
LABEL_30:
        v26 = v25[++v27];
        v28 = (_DWORD)v29 + v79;
        if ( !v26 )
          goto LABEL_107;
        continue;
      }
      break;
    }
    a4 = v69;
    v23 = v74;
LABEL_97:
    if ( v80 < 8 )
    {
LABEL_145:
      __break(1u);
      v64 = a5;
      StatusReg = _ReadStatusReg(SP_EL0);
      v66 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
      v11 = (const char **)_kmalloc_cache_noprof(device_register, 3520, 1000);
      *(_QWORD *)(StatusReg + 80) = v66;
      a5 = v64;
      if ( !v11 )
        goto LABEL_146;
      continue;
    }
    break;
  }
  v48 = (int)v29;
  if ( *(_QWORD *)v23 )
  {
    a5 = 0x100000000LL;
    v49 = 1;
    v50 = 0x100000000LL;
    do
    {
      ((void (*)(void))kfree)();
      if ( v49 < 0 )
        goto LABEL_145;
      if ( v80 < v50 >> 29 )
        goto LABEL_145;
      if ( v80 - (v50 >> 29) < 8 )
        goto LABEL_145;
      v51 = v49 & 0x7FFFFFFF;
      if ( v80 < 8 * v51 || v80 - 8 * v51 < 8 )
        goto LABEL_145;
      ++v49;
      v50 += 0x100000000LL;
    }
    while ( *(_QWORD *)(v23 + 8 * v51) );
  }
  kfree(v23);
  v24 = v72;
  v23 = v48;
LABEL_107:
  if ( v23 >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_139;
  v52 = (char *)v11[124];
  v11[122] = (const char *)v23;
  *(_QWORD *)v52 = v11 + 119;
  if ( v24 )
  {
    v53 = *v24;
    if ( *v24 )
    {
      v54 = 1;
      do
      {
        *(_QWORD *)&v11[124][8 * v54] = v53;
        v53 = v24[v54++];
      }
      while ( v53 );
    }
  }
  a5 = (__int64)v11[124];
LABEL_113:
  v11[102] = (const char *)a5;
  if ( a1 )
  {
    if ( (device_property_present(a1, "label") & 1) != 0 )
    {
      string = device_property_read_string(a1, "label", v83);
      if ( string < 0 )
      {
        LODWORD(v23) = string;
        v47 = v11[122];
        if ( v47 )
          goto LABEL_140;
      }
      else
      {
        v56 = kstrdup(v83[0], 3264);
        v11[1] = (const char *)v56;
        if ( v56 )
          goto LABEL_117;
LABEL_138:
        LODWORD(v23) = -12;
LABEL_139:
        v47 = v11[122];
        if ( v47 )
        {
LABEL_140:
          v62 = *(_QWORD *)v47;
          if ( *(_QWORD *)v47 )
          {
            v63 = 1;
            do
            {
              kfree(v62);
              v62 = *(_QWORD *)&v47[8 * v63++];
            }
            while ( v62 );
          }
          kfree(v47);
        }
      }
LABEL_144:
      kfree(v11[124]);
      kfree(v11[1]);
      kfree(v11);
LABEL_147:
      ida_free(&hwmon_ida, (unsigned int)v10);
      result = (const char **)(int)v23;
      goto LABEL_148;
    }
LABEL_117:
    *v11 = v7;
    v11[101] = (const char *)&hwmon_class;
    v11[14] = (const char *)a1;
    while ( 1 )
    {
      v57 = *(const char **)(a1 + 744);
      if ( v57 )
        break;
      a1 = *(_QWORD *)(a1 + 96);
      if ( !a1 )
      {
        v57 = nullptr;
        break;
      }
    }
  }
  else
  {
    v57 = nullptr;
    *v11 = v7;
    v11[101] = (const char *)&hwmon_class;
    v11[14] = nullptr;
  }
  v11[95] = v57;
  v11[116] = (const char *)a4;
  v11[21] = (const char *)a3;
  dev_set_name(v11 + 2, "hwmon%d", v10);
  v58 = device_register(v11 + 2);
  if ( v58 )
  {
    LODWORD(v23) = v58;
    put_device(v11 + 2);
    goto LABEL_147;
  }
  result = v11 + 2;
  v11[117] = (const char *)(v11 + 117);
  v11[118] = (const char *)(v11 + 117);
  if ( a4 )
  {
    if ( v11[95] )
    {
      if ( *(_QWORD *)(*a4 + 8LL) )
      {
        v59 = *(_QWORD *)a4[1];
        if ( !*(_DWORD *)v59 )
        {
          v60 = **(_DWORD **)(v59 + 8);
          if ( (v60 & 0x10) == 0
            || (LODWORD(v23) = hwmon_thermal_register_sensors(v11 + 2), result = v11 + 2, !(_DWORD)v23) )
          {
            if ( (v60 & 0x2000) == 0 )
              goto LABEL_148;
            v61 = hwmon_pec_register(result);
            if ( !v61 )
            {
              result = v11 + 2;
              goto LABEL_148;
            }
            LODWORD(v23) = v61;
            result = v11 + 2;
          }
          device_unregister(result);
          goto LABEL_147;
        }
      }
    }
  }
LABEL_148:
  _ReadStatusReg(SP_EL0);
  return result;
}
