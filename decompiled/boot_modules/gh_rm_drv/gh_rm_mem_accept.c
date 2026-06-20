unsigned __int64 __fastcall gh_rm_mem_accept(
        int a1,
        unsigned int a2,
        unsigned __int8 a3,
        int a4,
        int a5,
        unsigned int *a6,
        unsigned int *a7,
        unsigned __int16 *a8,
        __int16 a9)
{
  __int64 *v9; // x20
  unsigned __int64 result; // x0
  char v11; // w22
  int v12; // w19
  __int64 v13; // x9
  unsigned int v14; // w8
  __int64 v15; // x10
  int v16; // w28
  char v17; // w27
  unsigned __int8 v18; // w23
  int v19; // w21
  unsigned int *v20; // x26
  unsigned __int16 *v21; // x25
  unsigned int *v22; // x24
  unsigned __int16 *v23; // x5
  unsigned int *v24; // x2
  int v25; // w8
  unsigned int *v26; // x3
  char v27; // w9
  unsigned __int64 v28; // x19
  int v29; // w12
  unsigned int *v30; // x13
  unsigned __int64 v31; // x19
  unsigned __int64 v32; // x8
  bool v33; // w23
  __int64 *v34; // x0
  int v35; // w21
  unsigned __int16 *v36; // x25
  _DWORD *v37; // x8
  __int64 v38; // x3
  __int64 *v39; // x0
  __int64 *v40; // x2
  unsigned __int16 *v41; // x10
  int v42; // w0
  __int64 v44; // x0
  unsigned __int64 v45; // x21
  __int64 v46; // x0
  __int64 *v47; // x22
  _DWORD *v48; // x24
  char *v49; // x23
  unsigned __int64 v50; // x26
  size_t v51; // x2
  size_t v52; // x1
  __int64 *v53; // x27
  __int64 **v54; // x8
  __int64 v55; // x9
  __int64 *v56; // x10
  __int64 v57; // x0
  int v58; // w9
  __int64 **v59; // x22
  unsigned __int64 v60; // x21
  __int64 **v61; // x8
  __int64 *v62; // x24
  __int64 *v63; // x0
  int v64; // w22
  __int64 v65; // x0
  unsigned __int64 StatusReg; // x24
  unsigned __int8 v67; // w25
  unsigned int v68; // w23
  unsigned int *v69; // x22
  unsigned __int16 *v70; // x21
  unsigned int *v71; // x19
  __int64 v72; // x26
  __int64 (__fastcall *v73)(__int64, _QWORD, _QWORD, _QWORD, unsigned int *, unsigned int *, unsigned __int16 *, int *, int, int); // x8
  __int64 v74; // x0
  __int64 v75; // t1
  __int64 v76; // x8
  __int64 v77; // x20
  __int64 **v78; // x21
  __int64 **v79; // x8
  __int64 *v80; // x24
  __int64 *v81; // x0
  int v82; // [xsp+0h] [xbp-50h]
  int v83; // [xsp+8h] [xbp-48h]
  unsigned int v84; // [xsp+20h] [xbp-30h]
  __int64 v85; // [xsp+28h] [xbp-28h]
  unsigned int v86; // [xsp+28h] [xbp-28h]
  unsigned __int64 v87; // [xsp+30h] [xbp-20h] BYREF
  unsigned __int16 *v88; // [xsp+38h] [xbp-18h] BYREF
  int v89; // [xsp+40h] [xbp-10h] BYREF
  unsigned __int16 v90; // [xsp+44h] [xbp-Ch] BYREF
  __int64 v91; // [xsp+48h] [xbp-8h]

  LOWORD(v9) = a9;
  v91 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v89 = a1;
  v87 = 0;
  v88 = nullptr;
  while ( 1 )
  {
    result = -22;
    if ( (unsigned __int8)a2 > 1u )
      goto LABEL_5;
    if ( a3 > 2u )
      goto LABEL_5;
    v11 = a4;
    if ( (a4 & 0x7FFFFF48) != 0 )
      goto LABEL_5;
    v12 = v89;
    if ( a7 )
    {
      if ( *a7 > 0x200 )
        goto LABEL_5;
    }
    if ( (a4 & 2) == 0 )
    {
      v13 = 0;
      v14 = 0;
      goto LABEL_21;
    }
    if ( a6 && (v14 = *a6) != 0 )
    {
      if ( !a8 )
      {
        v13 = 0;
        goto LABEL_21;
      }
      LODWORD(v13) = *a8;
    }
    else
    {
      if ( !a8 )
        goto LABEL_5;
      LODWORD(v13) = *a8;
      if ( !*a8 )
        goto LABEL_5;
      v14 = a6 ? *a6 : 0;
    }
    v13 = (unsigned int)v13;
LABEL_21:
    if ( a7 )
      v15 = *a7;
    else
      v15 = 0;
    v16 = a4;
    v17 = a2;
    v18 = a3;
    v19 = a5;
    v20 = a6;
    v21 = a8;
    v22 = a7;
    v85 = 4 * (v13 + v14) + 16 * v15;
    result = _kmalloc_noprof(v85 + 24, 3520);
    if ( !result )
    {
      result = -12;
      goto LABEL_5;
    }
    if ( result > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_5;
    v23 = v21;
    v24 = v20;
    v25 = v19;
    *(_DWORD *)result = v12;
    *(_BYTE *)(result + 4) = v17;
    *(_BYTE *)(result + 5) = v18;
    *(_BYTE *)(result + 6) = v16;
    if ( v16 < 0 )
    {
      v27 = 0;
      v26 = v22;
    }
    else
    {
      v26 = v22;
      v27 = 0;
      if ( v17 != 1 && v18 != 2 )
      {
        v28 = result;
        v90 = 0;
        if ( (unsigned int)gh_rm_get_this_vmid(&v90) )
        {
          _warn_printk("gh_rm_get_this_vmid failed\n");
          __break(0x800u);
          v27 = 32;
          v26 = v22;
          result = v28;
          v23 = v21;
          v24 = v20;
          v25 = v19;
        }
        else if ( v20 )
        {
          v24 = v20;
          v26 = v22;
          result = v28;
          v23 = v21;
          v25 = v19;
          if ( *v20 )
          {
            v29 = 0;
            while ( 1 )
            {
              v30 = &v20[v29 + 1];
              if ( *(unsigned __int16 *)v30 == v90 && (*((_BYTE *)v30 + 2) & 2) == 0 )
                break;
              if ( *v20 == ++v29 )
                goto LABEL_38;
            }
            v27 = 0;
          }
          else
          {
LABEL_38:
            v27 = 32;
          }
        }
        else
        {
          _warn_printk("Policy requires gh_rm_mem_accept to be called with acl_desc\n");
          v24 = nullptr;
          __break(0x800u);
          v27 = 32;
          v26 = v22;
          result = v28;
          v23 = v21;
          v25 = v19;
        }
      }
    }
    *(_BYTE *)(result + 6) |= v27;
    if ( (v11 & 4) != 0 )
      *(_DWORD *)(result + 8) = v25;
    v31 = result;
    gh_rm_populate_mem_request((char *)result, 1358954513, v24, v26, (__int16)v9, v23);
    v32 = v11 & 0x10 | (unsigned __int64)v22;
    v33 = v32 != 0;
    if ( !v32 )
      *(_BYTE *)(v31 + 6) &= ~0x80u;
    v34 = (__int64 *)_kmalloc_cache_noprof(delayed_work_timer_fn, 3520, 24);
    v9 = v34;
    if ( !v34 )
    {
      v77 = -12;
LABEL_124:
      kfree(v31);
      result = v77;
      goto LABEL_5;
    }
    *v34 = (__int64)v34;
    v34[1] = (__int64)v34;
    v35 = gunyah_rm_call(rm, 1358954513, v31, v85 + 24, &v88, &v87);
    if ( v35 )
    {
      printk(&unk_12082, "gh_rm_mem_accept");
      v64 = v35;
LABEL_116:
      v78 = (__int64 **)*v9;
      if ( (__int64 *)*v9 != v9 )
      {
        do
        {
          v80 = *v78;
          v79 = (__int64 **)v78[1];
          if ( *v79 == (__int64 *)v78 && (__int64 **)v80[1] == v78 )
          {
            v80[1] = (__int64)v79;
            *v79 = v80;
          }
          else
          {
            _list_del_entry_valid_or_report(v78);
          }
          v81 = v78[2];
          *v78 = (__int64 *)0xDEAD000000000100LL;
          v78[1] = (__int64 *)0xDEAD000000000122LL;
          kfree(v81);
          kfree(v78);
          v78 = (__int64 **)v80;
        }
        while ( v80 != v9 );
      }
      kfree(v9);
      v77 = v64;
      goto LABEL_124;
    }
    _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v36 = v88;
      v37 = v22;
      if ( v22 )
        v38 = 0;
      else
        v38 = v87 >= 4 ? (16LL * *v88) | 4 : 4LL;
      if ( v38 != v87 )
        break;
      if ( !v87 )
        goto LABEL_66;
      if ( __CFADD__(*((_DWORD *)v9 + 4), *v88) )
      {
        printk(&unk_1252C, "gh_sgl_fragment_append");
LABEL_99:
        kfree(v88);
        v64 = -12;
LABEL_115:
        gh_rm_mem_release(v89, 0);
        goto LABEL_116;
      }
      v39 = (__int64 *)_kmalloc_cache_noprof(delayed_work_timer_fn, 3520, 24);
      if ( !v39 )
        goto LABEL_99;
      v40 = (__int64 *)*v9;
      v39[2] = (__int64)v36;
      if ( (__int64 *)v40[1] != v9 || v39 == v9 || v40 == v39 )
      {
        _list_add_valid_or_report();
      }
      else
      {
        v40[1] = (__int64)v39;
        *v39 = (__int64)v40;
        v39[1] = (__int64)v9;
        *v9 = (__int64)v39;
      }
      v37 = v22;
      v41 = v88;
      *((_DWORD *)v9 + 4) += *v36;
      if ( (v41[1] & 1) == 0 )
        goto LABEL_66;
      v42 = gunyah_rm_call(rm, 1358954513, v31, v85 + 24, &v88, &v87);
      if ( v42 )
        goto LABEL_61;
    }
    printk(&unk_12265, "gh_rm_mem_accept_check_resp");
    if ( !v87 )
    {
      v64 = -22;
      goto LABEL_115;
    }
    kfree(v88);
    v37 = v22;
LABEL_66:
    if ( (v11 & 0x80) == 0 || v33 )
    {
      if ( v37 )
        goto LABEL_90;
    }
    else
    {
      v44 = rm;
      *(_BYTE *)(v31 + 6) |= 0x80u;
      v42 = gunyah_rm_call(v44, 1358954513, v31, v85 + 24, &v88, &v87);
      if ( v42 )
      {
LABEL_61:
        v64 = v42;
        printk(&unk_12082, "gh_rm_mem_accept");
        goto LABEL_115;
      }
      if ( v87 )
        kfree(v88);
    }
    v45 = (16LL * *((unsigned int *)v9 + 4)) | 6;
    v46 = _kvmalloc_node_noprof(v45, 0, 3264, 0xFFFFFFFFLL);
    if ( !v46 )
    {
      v64 = -12;
      goto LABEL_115;
    }
    v47 = (__int64 *)*v9;
    v48 = (_DWORD *)v46;
    if ( (__int64 *)*v9 == v9 )
      break;
    v49 = (char *)(v46 + 6);
    v50 = 6;
    while ( 1 )
    {
      v51 = 16LL * *(unsigned __int16 *)v47[2];
      v52 = v45 >= v50 ? v45 - v50 : 0LL;
      if ( v52 < v51 )
        break;
      v53 = (__int64 *)*v47;
      memcpy(v49, (const void *)(v47[2] + 4), v51);
      v54 = (__int64 **)v47[1];
      v55 = *(unsigned __int16 *)v47[2];
      if ( *v54 == v47 && (v56 = (__int64 *)*v47, *(__int64 **)(*v47 + 8) == v47) )
      {
        v56[1] = (__int64)v54;
        *v54 = v56;
      }
      else
      {
        _list_del_entry_valid_or_report(v47);
      }
      v57 = v47[2];
      *v47 = 0xDEAD000000000100LL;
      v47[1] = 0xDEAD000000000122LL;
      v50 += 16 * v55;
      v49 += 16 * v55;
      kfree(v57);
      kfree(v47);
      v47 = v53;
      if ( v53 == v9 )
        goto LABEL_88;
    }
    v65 = _fortify_panic(17, v52);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      v86 = a4;
      v67 = a3;
      v68 = a5;
      v84 = a2;
      v69 = a6;
      v70 = a8;
      v71 = a7;
      ++*(_DWORD *)(StatusReg + 16);
      v72 = qword_14320;
      if ( qword_14320 )
      {
        do
        {
          v73 = *(__int64 (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, unsigned int *, unsigned int *, unsigned __int16 *, int *, int, int))v72;
          v74 = *(_QWORD *)(v72 + 8);
          LOBYTE(v83) = v67;
          LOWORD(v82) = (_WORD)v9;
          if ( *(_DWORD *)(*(_QWORD *)v72 - 4LL) != 1140098178 )
            __break(0x8228u);
          v65 = v73(v74, v84, v86, v68, v69, v71, v70, &v89, v82, v83);
          v75 = *(_QWORD *)(v72 + 24);
          v72 += 24;
        }
        while ( v75 );
      }
      v76 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v76;
      LOBYTE(a2) = v84;
      a4 = v86;
      if ( !v76 || (a7 = v71, a8 = v70, a6 = v69, a5 = v68, a3 = v67, !*(_QWORD *)(StatusReg + 16)) )
      {
        preempt_schedule_notrace(v65, v84);
        a4 = v86;
        LOBYTE(a2) = v84;
        a3 = v67;
        a5 = v68;
        a6 = v69;
        a8 = v70;
        a7 = v71;
      }
    }
  }
LABEL_88:
  v58 = *((_DWORD *)v9 + 4);
  v37 = v48;
  *((_DWORD *)v9 + 4) = 0;
  *v48 = v58;
  if ( (unsigned __int64)v48 >= 0xFFFFFFFFFFFFF001LL )
  {
    v64 = (int)v48;
    goto LABEL_115;
  }
LABEL_90:
  v59 = (__int64 **)*v9;
  v60 = (unsigned __int64)v37;
  if ( (__int64 *)*v9 != v9 )
  {
    do
    {
      v62 = *v59;
      v61 = (__int64 **)v59[1];
      if ( *v61 == (__int64 *)v59 && (__int64 **)v62[1] == v59 )
      {
        v62[1] = (__int64)v61;
        *v61 = v62;
      }
      else
      {
        _list_del_entry_valid_or_report(v59);
      }
      v63 = v59[2];
      *v59 = (__int64 *)0xDEAD000000000100LL;
      v59[1] = (__int64 *)0xDEAD000000000122LL;
      kfree(v63);
      kfree(v59);
      v59 = (__int64 **)v62;
    }
    while ( v62 != v9 );
  }
  kfree(v9);
  kfree(v31);
  result = v60;
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
