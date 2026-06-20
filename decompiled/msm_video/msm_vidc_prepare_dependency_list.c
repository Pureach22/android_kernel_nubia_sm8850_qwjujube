__int64 __fastcall msm_vidc_prepare_dependency_list(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x21
  unsigned int v7; // w20
  __int64 v9; // x20
  unsigned int *v10; // x24
  __int64 v11; // x8
  _BYTE *v12; // x8
  __int64 v13; // x26
  __int64 v14; // x0
  _QWORD *v15; // x2
  __int64 v16; // x8
  __int64 v17; // x0
  _QWORD *v18; // x2
  int v19; // w11
  _QWORD **v20; // x9
  _QWORD *v21; // x10
  _QWORD **v22; // x12
  _QWORD *v23; // x13
  unsigned int v24; // w14
  _QWORD **v25; // x15
  int v26; // w24
  unsigned int v27; // w9
  int v28; // w0
  _QWORD *v29; // x8
  _QWORD *v30; // x25
  __int64 v31; // x0
  unsigned __int64 v32; // x17
  unsigned __int64 v33; // x8
  bool v34; // w16
  bool v35; // cc
  __int64 v36; // x0
  _QWORD *v37; // x2
  __int64 v38; // x8
  _QWORD *v39; // x1
  __int64 v40; // x8
  __int64 v41; // x20
  _QWORD *v42; // x8
  _QWORD *v43; // x8
  _QWORD *v44; // x0
  _QWORD *v45; // x26
  _QWORD *v46; // x8
  _QWORD *v47; // x9
  _QWORD *v48; // x9
  _QWORD *v49; // x27
  __int64 v50; // x0
  _QWORD *v51; // x0
  _QWORD *v52; // x26
  _QWORD *v53; // x8
  _QWORD *v54; // x9
  _QWORD *v55; // x9
  _QWORD *v56; // x27
  __int64 v57; // x0
  _QWORD *v58; // [xsp+10h] [xbp-1C0h] BYREF
  _QWORD *v59; // [xsp+18h] [xbp-1B8h]
  _QWORD *v60; // [xsp+20h] [xbp-1B0h] BYREF
  _QWORD **v61; // [xsp+28h] [xbp-1A8h]
  _QWORD v62[25]; // [xsp+30h] [xbp-1A0h] BYREF
  _QWORD v63[27]; // [xsp+F8h] [xbp-D8h] BYREF

  v5 = a1 + 4024;
  v63[25] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_QWORD *)(a1 + 4024) != a1 + 4024 )
  {
    if ( a1 && (msm_vidc_debug & 2) != 0 )
      printk(&unk_8E271, "high", a1 + 340, "msm_vidc_prepare_dependency_list", a5);
    v7 = 0;
    goto LABEL_6;
  }
  v60 = &v60;
  v61 = &v60;
  v9 = 1;
  v58 = &v58;
  v10 = (unsigned int *)(a1 + 4488);
  v59 = &v58;
  memset(v63, 0, 197);
  _ReadStatusReg(SP_EL0);
  memset(v62, 0, 197);
  while ( 1 )
  {
    v13 = *v10;
    if ( (unsigned int)(v13 - 197) < 0xFFFFFF3C || !*(_DWORD *)(a1 + 4320 + 168LL * (unsigned int)v13) )
      goto LABEL_12;
    if ( v9 != v13 )
    {
      if ( a1 && (msm_vidc_debug & 1) != 0 )
      {
        v41 = cap_name((unsigned int)v9);
        cap_name(*v10);
        printk(&unk_8669B, "err ", a1 + 340, "msm_vidc_prepare_dependency_list", v41);
      }
      goto LABEL_81;
    }
    if ( !v10[13] )
      break;
    if ( (*((_BYTE *)v62 + v9) & 1) != 0 )
      goto LABEL_12;
    v14 = vzalloc_noprof(24);
    if ( !v14 )
      goto LABEL_30;
    *(_QWORD *)v14 = v14;
    *(_QWORD *)(v14 + 8) = v14;
    v15 = v58;
    *(_DWORD *)(v14 + 16) = v13;
    if ( v15 == (_QWORD *)v14 || (_QWORD **)v15[1] != &v58 )
    {
      ((void (*)(void))_list_add_valid_or_report)();
    }
    else
    {
      v15[1] = v14;
      *(_QWORD *)v14 = v15;
      *(_QWORD *)(v14 + 8) = &v58;
      v58 = (_QWORD *)v14;
    }
    v16 = *v10;
    if ( (unsigned int)v16 > 0xC4 )
    {
LABEL_102:
      __break(1u);
LABEL_103:
      __break(0x5512u);
    }
    v12 = (char *)v62 + v16;
LABEL_11:
    *v12 = 1;
LABEL_12:
    ++v9;
    v10 += 42;
    if ( v9 == 197 )
    {
      v19 = -1;
      v20 = &v58;
      do
      {
        v20 = (_QWORD **)*v20;
        ++v19;
      }
      while ( v20 != &v58 );
      v21 = v58;
      v22 = &v58;
      if ( v58 != &v58 )
      {
        v23 = v62;
        v24 = 168;
        v25 = &v60;
        v26 = v19;
        v27 = v19;
        do
        {
          v30 = (_QWORD *)*v21;
          v29 = (_QWORD *)v21[1];
          if ( (_QWORD *)*v29 == v21 && (_QWORD *)v30[1] == v21 )
          {
            v30[1] = v29;
            *v29 = v30;
          }
          else
          {
            _list_del_entry_valid_or_report(v21);
          }
          *v21 = v21;
          v21[1] = v21;
          v31 = *((unsigned int *)v21 + 4);
          if ( (unsigned int)v31 > 0xC4 )
            goto LABEL_103;
          v32 = a1 + 4372 + (unsigned int)v31 * (unsigned __int64)v24;
          v33 = 0;
          v34 = 0;
          --v26;
          *((_BYTE *)v23 + v31) = 0;
          do
          {
            v36 = *(unsigned int *)(v32 + 4 * v33);
            if ( (_DWORD)v36 )
            {
              if ( (unsigned int)v36 > 0xC4 )
                goto LABEL_102;
              if ( *((_BYTE *)v63 + v36) != 1 )
                break;
            }
            v35 = v33++ > 0x17;
            v34 = v35;
          }
          while ( v33 != 25 );
          if ( v34 )
          {
            v37 = v60;
            if ( (_QWORD **)v60[1] != v25 || v21 == v25 || v60 == v21 )
            {
              _list_add_valid_or_report(v21);
            }
            else
            {
              v60[1] = v21;
              *v21 = v37;
              v21[1] = v25;
              v60 = v21;
            }
            v38 = *((unsigned int *)v21 + 4);
            if ( (unsigned int)v38 > 0xC4 )
              goto LABEL_103;
            *((_BYTE *)v63 + v38) = 1;
            --v19;
            if ( v26 )
              goto LABEL_37;
          }
          else
          {
            v39 = v59;
            if ( v21 == v22 || v59 == v21 || (_QWORD **)*v59 != v22 )
            {
              _list_add_valid_or_report(v21);
            }
            else
            {
              v59 = v21;
              *v21 = v22;
              v21[1] = v39;
              *v39 = v21;
            }
            v40 = *((unsigned int *)v21 + 4);
            if ( (unsigned int)v40 > 0xC4 )
              goto LABEL_103;
            *((_BYTE *)v23 + v40) = 1;
            if ( v26 )
            {
LABEL_37:
              v28 = v27;
              goto LABEL_38;
            }
          }
          v28 = v19;
          v26 = v19;
          if ( v27 == v19 )
          {
            if ( a1 && (msm_vidc_debug & 1) != 0 )
              printk(&unk_882B7, "err ", a1 + 340, "msm_vidc_prepare_dependency_list", v27);
            goto LABEL_81;
          }
LABEL_38:
          v21 = v30;
          v27 = v28;
        }
        while ( v30 != v22 );
      }
      if ( v58 == v22 )
      {
        v42 = v60;
        v7 = 0;
        *(_QWORD *)(a1 + 4024) = v60;
        v42[1] = v5;
        v43 = v61;
        *(_QWORD *)(a1 + 4032) = v61;
        *v43 = v5;
        v60 = &v60;
        v61 = &v60;
        goto LABEL_6;
      }
      if ( a1 && (msm_vidc_debug & 1) != 0 )
        printk(&unk_81006, "err ", a1 + 340, "msm_vidc_prepare_dependency_list", a5);
LABEL_81:
      v7 = -22;
      goto LABEL_82;
    }
  }
  if ( (*((_BYTE *)v63 + v9) & 1) != 0 )
    goto LABEL_12;
  v17 = vzalloc_noprof(24);
  if ( v17 )
  {
    *(_QWORD *)v17 = v17;
    *(_QWORD *)(v17 + 8) = v17;
    v18 = v60;
    *(_DWORD *)(v17 + 16) = v13;
    if ( v18 == (_QWORD *)v17 || (_QWORD **)v18[1] != &v60 )
    {
      ((void (*)(void))_list_add_valid_or_report)();
    }
    else
    {
      v18[1] = v17;
      *(_QWORD *)v17 = v18;
      *(_QWORD *)(v17 + 8) = &v60;
      v60 = (_QWORD *)v17;
    }
    v11 = *v10;
    if ( (unsigned int)v11 > 0xC4 )
      goto LABEL_102;
    v12 = (char *)v63 + v11;
    goto LABEL_11;
  }
LABEL_30:
  if ( (msm_vidc_debug & 1) != 0 )
    printk(&unk_8C985, "err ", 0xFFFFFFFFLL, "codec", "add_node_list");
  v7 = -12;
LABEL_82:
  v44 = v58;
  if ( v58 != &v58 )
  {
    do
    {
      v45 = (_QWORD *)*v44;
      if ( a1 && (msm_vidc_debug & 1) != 0 )
      {
        v49 = v44;
        v50 = cap_name(*((unsigned int *)v44 + 4));
        printk(&unk_8A5D1, "err ", a1 + 340, "msm_vidc_prepare_dependency_list", v50);
        v44 = v49;
      }
      v46 = (_QWORD *)v44[1];
      if ( (_QWORD *)*v46 == v44 && (v47 = (_QWORD *)*v44, *(_QWORD **)(*v44 + 8LL) == v44) )
      {
        v47[1] = v46;
        *v46 = v47;
      }
      else
      {
        _list_del_entry_valid_or_report(v44);
        v44 = v48;
      }
      *v44 = v44;
      v44[1] = v44;
      vfree(v44);
      v44 = v45;
    }
    while ( v45 != &v58 );
  }
  v51 = v60;
  if ( v60 != &v60 )
  {
    do
    {
      v52 = (_QWORD *)*v51;
      if ( a1 && (msm_vidc_debug & 1) != 0 )
      {
        v56 = v51;
        v57 = cap_name(*((unsigned int *)v51 + 4));
        printk(&unk_94669, "err ", a1 + 340, "msm_vidc_prepare_dependency_list", v57);
        v51 = v56;
      }
      v53 = (_QWORD *)v51[1];
      if ( (_QWORD *)*v53 == v51 && (v54 = (_QWORD *)*v51, *(_QWORD **)(*v51 + 8LL) == v51) )
      {
        v54[1] = v53;
        *v53 = v54;
      }
      else
      {
        _list_del_entry_valid_or_report(v51);
        v51 = v55;
      }
      *v51 = v51;
      v51[1] = v51;
      vfree(v51);
      v51 = v52;
    }
    while ( v52 != &v60 );
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return v7;
}
