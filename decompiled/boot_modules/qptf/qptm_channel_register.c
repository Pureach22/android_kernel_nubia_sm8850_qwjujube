__int64 __fastcall qptm_channel_register(__int64 a1, int a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  __int64 v7; // x21
  __int64 v8; // x8
  int v10; // w9
  __int64 v11; // x22
  __int64 v12; // x10
  int v13; // w0
  int v14; // w25
  unsigned int v15; // w26
  unsigned int v16; // w0
  unsigned __int64 v17; // x19
  __int64 v18; // x0
  void *v19; // x2
  void *v20; // x0
  int v21; // w0
  __int64 v22; // x2
  __int64 v23; // x3
  unsigned int v24; // w22
  _UNKNOWN **v25; // x8
  _QWORD *v26; // x8
  __int64 v27; // x0
  const char *v28; // x21
  __int64 v29; // x20
  size_t v30; // x0
  unsigned __int64 v31; // x2
  void *v32; // x2
  void *v33; // x0
  unsigned int v34; // w23
  char v35; // w20
  _QWORD *v36; // x21
  __int64 v37; // x20
  unsigned int v38; // w27
  void *v39; // x0
  int v40; // w25
  _UNKNOWN **v41; // x27
  __int64 v42; // x2
  _UNKNOWN **v43; // x0
  _QWORD *v44; // x9
  __int64 v45; // x8
  __int64 v46; // x8
  __int64 v47; // x9
  __int64 v48; // x10
  __int64 v49; // x11
  __int64 v50; // x9
  __int64 v51; // x10
  _QWORD *v52; // x8
  __int64 v53; // x9
  unsigned int v54; // w0
  unsigned int v55; // w19
  __int64 v56; // x0
  __int64 v58; // [xsp+8h] [xbp-68h]
  __int64 v59; // [xsp+10h] [xbp-60h]
  _QWORD *v60; // [xsp+10h] [xbp-60h]
  __int64 v61; // [xsp+18h] [xbp-58h] BYREF
  __int64 v62; // [xsp+20h] [xbp-50h]
  __int64 v63; // [xsp+28h] [xbp-48h]
  __int64 v64; // [xsp+30h] [xbp-40h]
  __int64 v65; // [xsp+38h] [xbp-38h]
  __int64 v66; // [xsp+40h] [xbp-30h]
  __int64 v67; // [xsp+48h] [xbp-28h]
  __int64 v68; // [xsp+50h] [xbp-20h]
  __int64 v69; // [xsp+58h] [xbp-18h]
  __int64 v70; // [xsp+60h] [xbp-10h]
  __int64 v71; // [xsp+68h] [xbp-8h]

  result = -22;
  v71 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 >= 0x10000 || !a3 )
    goto LABEL_29;
  v69 = 0;
  v70 = 0;
  v7 = *(_QWORD *)(a1 + 744);
  v8 = qh;
  v67 = 0;
  v68 = 0;
  v65 = 0;
  v66 = 0;
  v63 = 0;
  v64 = 0;
  v61 = 0;
  v62 = 0;
  v10 = *(_DWORD *)qh;
  if ( *(int *)qh < 1 )
  {
    v17 = -19;
    goto LABEL_27;
  }
  v11 = 0;
  v59 = a1;
  while ( 1 )
  {
    v12 = *(_QWORD *)(v8 + 16) + (v11 << 6);
    if ( *(_DWORD *)v12 == 1 )
      break;
LABEL_6:
    if ( ++v11 >= v10 )
    {
      v17 = -19;
      goto LABEL_45;
    }
  }
  v13 = of_count_phandle_with_args(*(_QWORD *)(v12 + 56), "power-channels", "#powerzone-cells");
  if ( v13 < 1 )
  {
    v17 = -22;
LABEL_45:
    a1 = v59;
    if ( v17 == -19 )
      goto LABEL_28;
    goto LABEL_46;
  }
  v14 = v13;
  v15 = 0;
  while ( 1 )
  {
    v16 = _of_parse_phandle_with_args(
            *(_QWORD *)(*(_QWORD *)(qh + 16) + (v11 << 6) + 56),
            "power-channels",
            "#powerzone-cells",
            0xFFFFFFFFLL,
            v15,
            &v61);
    if ( (v16 & 0x80000000) != 0 )
      break;
    if ( v61 == v7 && HIDWORD(v62) == a2 )
    {
      v17 = *(_QWORD *)(*(_QWORD *)(qh + 16) + (v11 << 6) + 56);
      goto LABEL_15;
    }
    if ( v14 == ++v15 )
    {
      v8 = qh;
      v10 = *(_DWORD *)qh;
      goto LABEL_6;
    }
  }
  v38 = v16;
  printk(&unk_80D9, "of_powerzone_find", *(_QWORD *)(*(_QWORD *)(qh + 16) + (v11 << 6) + 56), v16);
  v17 = (int)v38;
LABEL_15:
  a1 = v59;
  if ( v17 >= 0xFFFFFFFFFFFFF001LL )
  {
LABEL_27:
    if ( v17 == -19 )
    {
LABEL_28:
      result = -19;
      goto LABEL_29;
    }
LABEL_46:
    printk(&unk_7FC7, "qptm_channel_register", *(_QWORD *)(a1 + 744), (unsigned int)a2);
    result = v17;
    goto LABEL_29;
  }
  v18 = devm_kmalloc(v59, 128, 3520);
  if ( v18 )
  {
    *(_WORD *)(v18 + 24) = a2;
    *(_QWORD *)(v18 + 8) = v17;
    *(_QWORD *)(v18 + 16) = a3;
    *(_QWORD *)(v18 + 120) = a4;
    v58 = v18;
    _mutex_init(v18 + 72, "&pz->lock", &qptm_channel_register___key);
    mutex_lock(&powerzone_list_lock);
    v19 = powerzone_list;
    v20 = (void *)(v58 + 32);
    if ( *(_UNKNOWN ***)((char *)&unk_8 + (_QWORD)powerzone_list) != &powerzone_list || powerzone_list == v20 )
    {
      _list_add_valid_or_report(v20, &powerzone_list);
    }
    else
    {
      *(_QWORD *)((char *)&unk_8 + (_QWORD)powerzone_list) = v20;
      *(_QWORD *)(v58 + 32) = v19;
      *(_QWORD *)(v58 + 40) = &powerzone_list;
      powerzone_list = (_UNKNOWN *)(v58 + 32);
    }
    mutex_unlock(&powerzone_list_lock);
    v69 = 0;
    v70 = 0;
    v67 = 0;
    v68 = 0;
    v65 = 0;
    v66 = 0;
    v63 = 0;
    v64 = 0;
    v61 = 0;
    v62 = 0;
    v21 = of_count_phandle_with_args(v17, "power-channels", "#powerzone-cells");
    if ( v21 < 1 )
    {
      v39 = &unk_8130;
LABEL_79:
      printk(v39, "create_qptm", v22, v23);
LABEL_80:
      v37 = -22;
      goto LABEL_81;
    }
    v24 = v21;
    v25 = &qptm_list;
    do
    {
      v25 = (_UNKNOWN **)*v25;
      if ( v25 == &qptm_list )
        goto LABEL_30;
    }
    while ( *(v25 - 4) != (_UNKNOWN *)v17 );
    v26 = v25 - 148;
    if ( v26 )
    {
      v60 = v26;
      goto LABEL_40;
    }
LABEL_30:
    v27 = devm_kmalloc(v59, 1264, 3520);
    if ( !v27 )
    {
      v37 = -12;
      goto LABEL_81;
    }
    v28 = *(const char **)v17;
    v29 = v27;
    v30 = strnlen(*(const char **)v17, 0x20u);
    if ( v30 == -1 )
    {
      _fortify_panic(2, -1, 0);
    }
    else
    {
      if ( v30 == 32 )
        v31 = 32;
      else
        v31 = v30 + 1;
      if ( v31 < 0x21 )
      {
        sized_strscpy(v29 + 1120, v28);
        *(_DWORD *)(v29 + 1160) = v24;
        *(_QWORD *)(v29 + 1152) = v17;
        _mutex_init(v29 + 1200, "&qptm->lock", &create_qptm___key);
        *(_QWORD *)(v29 + 1168) = v29 + 1168;
        *(_QWORD *)(v29 + 1176) = v29 + 1168;
        mutex_lock(&qptm_list_lock);
        v32 = qptm_list;
        v33 = (void *)(v29 + 1184);
        if ( *(_UNKNOWN ***)((char *)&unk_8 + (_QWORD)qptm_list) != &qptm_list || qptm_list == v33 )
        {
          _list_add_valid_or_report(v33, &qptm_list);
        }
        else
        {
          *(_QWORD *)((char *)&unk_8 + (_QWORD)qptm_list) = v33;
          *(_QWORD *)(v29 + 1184) = v32;
          *(_QWORD *)(v29 + 1192) = &qptm_list;
          qptm_list = (_UNKNOWN *)(v29 + 1184);
        }
        v60 = (_QWORD *)v29;
        mutex_unlock(&qptm_list_lock);
LABEL_40:
        v34 = 0;
        v35 = 0;
        v36 = v60 + 146;
        while ( 2 )
        {
          if ( (_of_parse_phandle_with_args(v17, "power-channels", "#powerzone-cells", 0xFFFFFFFFLL, v34, &v61)
              & 0x80000000) != 0 )
          {
            v39 = &unk_838C;
            goto LABEL_79;
          }
          if ( (int)v62 <= 0 )
          {
            v39 = &unk_81EB;
            goto LABEL_79;
          }
          v40 = HIDWORD(v62);
          mutex_lock(&powerzone_list_lock);
          v41 = &powerzone_list;
          while ( 1 )
          {
            v41 = (_UNKNOWN **)*v41;
            if ( v41 == &powerzone_list )
              break;
            if ( v40 == *((unsigned __int16 *)v41 - 4) )
            {
              if ( ((_BYTE)v41[2] & 1) == 0 )
              {
                mutex_lock(v60 + 150);
                v42 = *v36;
                v43 = v41 + 3;
                if ( *(_QWORD **)(*v36 + 8LL) != v36 || v43 == v36 || (_UNKNOWN **)v42 == v43 )
                {
                  _list_add_valid_or_report(v43, v36);
                }
                else
                {
                  *(_QWORD *)(v42 + 8) = v43;
                  v41[3] = (_UNKNOWN *)v42;
                  v41[4] = v36;
                  *v36 = v43;
                }
                mutex_unlock(v60 + 150);
                *((_BYTE *)v41 + 16) = 1;
              }
              mutex_unlock(&powerzone_list_lock);
              goto LABEL_52;
            }
          }
          mutex_unlock(&powerzone_list_lock);
          if ( (v35 & 1) == 0 )
            goto LABEL_80;
LABEL_52:
          ++v34;
          v35 = 1;
          if ( v34 != v24 )
            continue;
          break;
        }
        v44 = v60 + 146;
        v45 = v24 + 1LL;
        do
        {
          v44 = (_QWORD *)*v44;
          --v45;
        }
        while ( v44 != v36 );
        result = v58;
        v37 = (__int64)v60;
        if ( v45 )
          goto LABEL_82;
        v46 = qh;
        v47 = *(unsigned int *)qh;
        if ( (int)v47 < 1 )
          goto LABEL_82;
        v48 = *(_QWORD *)(qh + 16);
        v49 = v47 << 6;
        v50 = 0;
        while ( *(_QWORD *)(v48 + v50 + 56) != v17 )
        {
          v50 += 64;
          if ( v49 == v50 )
            goto LABEL_82;
        }
        *(_QWORD *)(v48 + v50 + 48) = v60;
        v60[137] = v60 + 137;
        v60[138] = v60 + 137;
        v60[135] = v60 + 135;
        v60[136] = v60 + 135;
        v60[139] = qptm_ops;
        v51 = *(_QWORD *)(v46 + 16);
        v52 = (_QWORD *)(v46 + 24);
        v53 = *(_QWORD *)(v51 + v50 + 40);
        if ( v53 )
          v52 = (_QWORD *)(v53 + 48);
        v54 = qptm_register(*(_QWORD *)v17, v60, *v52);
        if ( v54 )
        {
          v55 = v54;
          printk(&unk_8015, "create_qptm", v60 + 140, v54);
          v37 = (int)v55;
        }
LABEL_81:
        result = v58;
LABEL_82:
        *(_QWORD *)result = v37;
        goto LABEL_29;
      }
    }
    v56 = _fortify_panic(7, 32, v31);
    return qptm_channel_unregister(v56);
  }
  result = -12;
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
