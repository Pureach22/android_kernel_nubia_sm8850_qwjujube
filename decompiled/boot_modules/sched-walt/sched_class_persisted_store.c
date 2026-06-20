__int64 __fastcall sched_class_persisted_store(int a1, int a2, char *src, __int64 a4)
{
  int v4; // w28
  unsigned int v5; // w21
  int *v6; // x22
  int v7; // w1
  int v8; // w8
  char *v9; // x0
  const char *v10; // x25
  unsigned __int8 *v11; // x0
  __int64 v12; // x1
  int v13; // w8
  int v14; // w9
  int v15; // t1
  unsigned __int8 *v16; // x0
  int v17; // w8
  int v18; // w9
  int v19; // t1
  int *v20; // x23
  char *v21; // x0
  char *v22; // x25
  int v23; // w22
  int *v24; // x20
  unsigned __int8 *v25; // x0
  int v26; // w8
  int v27; // w9
  int v28; // t1
  unsigned __int8 *v29; // x0
  int v30; // w8
  int v31; // w9
  int v32; // t1
  unsigned int v33; // w11
  unsigned __int8 *v34; // x10
  int v35; // w11
  int v36; // t1
  unsigned int v37; // w2
  unsigned int v38; // w11
  unsigned __int8 *v39; // x10
  int v40; // w11
  int v41; // t1
  unsigned int v42; // w2
  int v43; // w8
  int v44; // w8
  int v45; // w10
  unsigned __int8 *v46; // x11
  int v47; // w10
  int v48; // t1
  int v49; // w20
  int v50; // w11
  unsigned __int8 *v51; // x10
  int v52; // w11
  int v53; // t1
  void *v54; // x0
  bool v55; // zf
  char v56; // w8
  char v57; // w8
  char v59; // w8
  __int64 v60; // [xsp+0h] [xbp-430h]
  char *v62; // [xsp+10h] [xbp-420h] BYREF
  char *stringp; // [xsp+18h] [xbp-418h] BYREF
  char dest[1024]; // [xsp+20h] [xbp-410h] BYREF
  __int64 v65; // [xsp+420h] [xbp-10h]

  v65 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  dest[1023] = 0;
  v62 = nullptr;
  stringp = nullptr;
  strncpy(dest, src, 0x3FFu);
  printk(&unk_6724B);
  if ( !strchr(dest, 64) )
    goto LABEL_121;
  stringp = dest;
  mutex_lock(&scp_data_lock);
  v60 = qword_6A598;
  v62 = strsep(&stringp, "@");
  if ( !v62 )
  {
LABEL_3:
    v62 = nullptr;
    stringp = nullptr;
    goto LABEL_121;
  }
  v4 = 0;
  v5 = 0;
  v6 = &scp_udata;
  while ( 1 )
  {
    v9 = (char *)skip_spaces();
    v10 = v9;
    v62 = v9;
    if ( !v4 )
    {
      v11 = (unsigned __int8 *)strnlen(v9, 8u);
      if ( v11 == (unsigned __int8 *)-1LL )
        goto LABEL_126;
      if ( (unsigned int)((_DWORD)v11 - 9) < 0xFFFFFFF8 )
        goto LABEL_121;
      if ( v10
        && ((v16 = (unsigned __int8 *)strim(v10), v17 = *v16, v17 != 45) && v17 != 43
          ? (v18 = *v16)
          : (v19 = v16[1], ++v16, v18 = v19),
            (unsigned int)(v18 - 48) <= 9) )
      {
        v45 = 0;
        v46 = v16 + 1;
        do
        {
          v47 = v18 + 10 * v45;
          v48 = *v46++;
          v18 = v48;
          v45 = v47 - 48;
        }
        while ( (unsigned int)(v48 - 48) < 0xA );
        if ( v17 == 45 )
          v7 = -v45;
        else
          v7 = v45;
        if ( scp_udata && v45 )
        {
          v49 = v7;
          printk(&unk_63D80);
          memset(v6, 0, 0x110u);
          v7 = v49;
          _ksymtab_walt_unset_cpus_taken[(_QWORD)v6] = sched_nbia_class_persisted_debug != 0;
          *(_QWORD *)((char *)&unk_F8 + (_QWORD)v6) = v60;
        }
      }
      else
      {
        v7 = 0;
      }
      v8 = _ksymtab_walt_unset_cpus_taken[(_QWORD)v6];
      *v6 = v7;
      if ( v8 == 1 )
        printk(&unk_6549B);
      goto LABEL_8;
    }
    if ( !scp_udata )
    {
      if ( byte_6A5A8 == 1 )
        printk(&unk_64A68);
LABEL_110:
      memset(v6, 0, 0x110u);
      v55 = sched_nbia_class_persisted_debug == 0;
      *(_QWORD *)((char *)&unk_F8 + (_QWORD)v6) = v60;
      v56 = !v55;
      _ksymtab_walt_unset_cpus_taken[(_QWORD)v6] = v56;
      goto LABEL_121;
    }
    v11 = (unsigned __int8 *)strnlen(v9, 6u);
    if ( v4 != 1 )
      break;
    if ( v11 == (unsigned __int8 *)-1LL )
      goto LABEL_126;
    if ( (unsigned int)((_DWORD)v11 - 7) <= 0xFFFFFFF9 )
      goto LABEL_110;
    if ( v10 )
    {
      v11 = (unsigned __int8 *)strim(v10);
      v13 = *v11;
      if ( v13 == 45 || v13 == 43 )
      {
        v15 = *++v11;
        v14 = v15;
      }
      else
      {
        v14 = *v11;
      }
      if ( (unsigned int)(v14 - 48) > 9 )
      {
        v50 = 0;
      }
      else
      {
        v50 = 0;
        v51 = v11 + 1;
        do
        {
          v52 = v14 + 10 * v50;
          v53 = *v51++;
          v14 = v53;
          v50 = v52 - 48;
        }
        while ( (unsigned int)(v53 - 48) < 0xA );
      }
      if ( v13 == 45 )
        v44 = -v50;
      else
        v44 = v50;
    }
    else
    {
      v44 = 0;
    }
    dword_6A4A4 = v44;
    qword_6A5A0 = sched_clock(v11, v12);
    if ( byte_6A5A8 == 1 )
      printk(&unk_620D4);
    if ( dword_6A4A4 >= 11 )
    {
      memset(v6, 0, 0x110u);
      v55 = sched_nbia_class_persisted_debug == 0;
      *(_QWORD *)((char *)&unk_F8 + (_QWORD)v6) = v60;
      v59 = !v55;
      _ksymtab_walt_unset_cpus_taken[(_QWORD)v6] = v59;
      printk(&unk_6405A);
      goto LABEL_121;
    }
LABEL_8:
    ++v4;
    v62 = strsep(&stringp, "@");
    if ( !v62 )
      goto LABEL_3;
  }
  if ( v11 == (unsigned __int8 *)-1LL )
  {
LABEL_126:
    _fortify_panic(2, -1, v11 + 1);
LABEL_127:
    __break(0x5512u);
  }
  if ( !(_DWORD)v11 )
    goto LABEL_110;
  if ( (int)v5 >= dword_6A4A4 || !strchr(v10, 58) )
    goto LABEL_8;
  v20 = v6;
  if ( byte_6A5A8 == 1 )
    printk(&unk_65FE3);
  v21 = strsep(&v62, ":");
  if ( !v21 )
  {
LABEL_78:
    if ( byte_6A5A8 == 1 )
    {
      if ( v5 > 9 )
        goto LABEL_127;
      printk(&unk_6479C);
    }
    ++v5;
    v6 = v20;
    goto LABEL_8;
  }
  v22 = v21;
  v23 = 0;
  v24 = &v20[6 * v5];
  while ( 2 )
  {
    v11 = (unsigned __int8 *)strnlen(v22, 6u);
    if ( v11 == (unsigned __int8 *)-1LL )
      goto LABEL_126;
    if ( !(_DWORD)v11 )
    {
      memset(v20, 0, 0x110u);
      *(_QWORD *)((char *)&unk_F8 + (_QWORD)v20) = v60;
      goto LABEL_121;
    }
    if ( v23 == 2 )
    {
      v29 = (unsigned __int8 *)strim(v22);
      v30 = *v29;
      if ( v30 == 45 || v30 == 43 )
      {
        v32 = *++v29;
        v31 = v32;
      }
      else
      {
        v31 = *v29;
      }
      if ( (unsigned int)(v31 - 48) > 9 )
      {
        v38 = 0;
      }
      else
      {
        v38 = 0;
        v39 = v29 + 1;
        do
        {
          v40 = v31 + 10 * v38;
          v41 = *v39++;
          v31 = v41;
          v38 = v40 - 48;
        }
        while ( (unsigned int)(v41 - 48) < 0xA );
      }
      if ( v30 == 45 )
        v42 = -v38;
      else
        v42 = v38;
      if ( v5 > 9 )
        goto LABEL_127;
      v43 = (unsigned __int8)byte_6A5A8;
      v24[7] = v42;
      if ( v43 == 1 )
      {
        printk(&unk_61314);
        v42 = v24[7];
        if ( v42 > 0x8C )
          goto LABEL_106;
      }
      else if ( v42 > 0x8C )
      {
        goto LABEL_106;
      }
      if ( v42 >= 0x64 && v24[6] )
      {
LABEL_106:
        if ( byte_6A5A8 != 1 )
          goto LABEL_117;
        v54 = &unk_61D3A;
        goto LABEL_116;
      }
      goto LABEL_33;
    }
    if ( v23 != 1 )
    {
      if ( !v23 )
      {
        if ( v5 >= 0xA )
          goto LABEL_127;
        strncpy((char *)v24 + 8, v22, 0x10u);
        if ( byte_6A5A8 == 1 )
          printk(&unk_612B1);
      }
LABEL_33:
      ++v23;
      v22 = strsep(&v62, ":");
      if ( !v22 )
        goto LABEL_78;
      continue;
    }
    break;
  }
  v25 = (unsigned __int8 *)strim(v22);
  v26 = *v25;
  if ( v26 == 45 || v26 == 43 )
  {
    v28 = *++v25;
    v27 = v28;
  }
  else
  {
    v27 = *v25;
  }
  if ( (unsigned int)(v27 - 48) > 9 )
  {
    v33 = 0;
  }
  else
  {
    v33 = 0;
    v34 = v25 + 1;
    do
    {
      v35 = v27 + 10 * v33;
      v36 = *v34++;
      v27 = v36;
      v33 = v35 - 48;
    }
    while ( (unsigned int)(v36 - 48) < 0xA );
  }
  if ( v26 == 45 )
    v37 = -v33;
  else
    v37 = v33;
  if ( v5 > 9 )
    goto LABEL_127;
  v24[6] = v37;
  if ( byte_6A5A8 == 1 )
  {
    printk(&unk_612DE);
    v37 = v24[6];
  }
  if ( v37 < 3 )
    goto LABEL_33;
  if ( byte_6A5A8 != 1 )
    goto LABEL_117;
  v54 = &unk_615D5;
LABEL_116:
  printk(v54);
LABEL_117:
  memset(v20, 0, 0x110u);
  v55 = sched_nbia_class_persisted_debug == 0;
  *(_QWORD *)((char *)&unk_F8 + (_QWORD)v20) = v60;
  v57 = !v55;
  _ksymtab_walt_unset_cpus_taken[(_QWORD)v20] = v57;
LABEL_121:
  mutex_unlock(&scp_data_lock);
  printk(&unk_64AA1);
  _ReadStatusReg(SP_EL0);
  return a4;
}
