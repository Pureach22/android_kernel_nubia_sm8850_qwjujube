__int64 __fastcall server_ioctl(__int64 a1, int a2, unsigned __int64 a3)
{
  __int64 v3; // x27
  __int64 result; // x0
  int v6; // w20
  _QWORD *i; // x19
  unsigned int v9; // w8
  unsigned int v10; // w20
  unsigned int v15; // w9
  int v16; // w20
  size_t v17; // x22
  __int64 v18; // x24
  unsigned __int64 v19; // x23
  __int64 v20; // x19
  __int64 v21; // x24
  unsigned __int64 v22; // x0
  _QWORD **v23; // x26
  unsigned __int64 StatusReg; // x25
  unsigned int *v25; // x19
  _QWORD *v26; // x20
  unsigned int v28; // w8
  unsigned int v29; // w19
  unsigned int v31; // w9
  int v32; // w20
  __int64 v33; // x9
  __int64 v34; // x20
  _DWORD *v35; // x21
  int v36; // w10
  unsigned __int64 v37; // x13
  __int64 v38; // x9
  int v39; // w28
  unsigned __int64 v40; // x22
  int v41; // w8
  _DWORD *v42; // x27
  unsigned __int64 v43; // x23
  _QWORD *v44; // x8
  unsigned __int64 v45; // x19
  unsigned __int64 v46; // x25
  __int64 v47; // x24
  unsigned __int64 v48; // x8
  unsigned __int64 v49; // x8
  unsigned __int64 v51; // x9
  unsigned __int64 v52; // x8
  unsigned __int64 v54; // x9
  int v55; // w23
  __int64 v56; // x9
  int v57; // w11
  _DWORD *v58; // x19
  int v59; // w22
  int v60; // w10
  __int64 v61; // x9
  _QWORD *v62; // x12
  __int64 v63; // x9
  __int16 v66; // w9
  int v67; // w10
  __int64 v68; // x11
  int v69; // w10
  int v70; // w8
  unsigned __int64 v71; // x23
  __int64 v72; // x24
  unsigned __int64 v73; // x19
  unsigned __int64 v74; // x8
  unsigned __int64 v75; // x8
  unsigned __int64 v77; // x9
  unsigned __int64 v78; // x8
  unsigned __int64 v80; // x9
  unsigned int **v81; // x8
  unsigned int *v82; // x9
  __int64 v83; // x10
  unsigned __int64 v84; // x8
  unsigned __int64 v87; // x10
  unsigned int **v88; // x8
  unsigned int *v89; // x9
  __int64 v90; // x10
  char v91; // w8
  unsigned __int64 v92; // x8
  unsigned __int64 v93; // x8
  unsigned __int64 v95; // x9
  unsigned __int64 v96; // x8
  unsigned __int64 v98; // x9
  unsigned __int64 v99; // [xsp+0h] [xbp-90h]
  __int64 v100; // [xsp+8h] [xbp-88h]
  unsigned int *v101; // [xsp+18h] [xbp-78h]
  unsigned __int64 v102; // [xsp+20h] [xbp-70h]
  __int64 v103; // [xsp+28h] [xbp-68h] BYREF
  __int64 v104; // [xsp+30h] [xbp-60h]
  __int64 v105; // [xsp+38h] [xbp-58h]
  __int64 v106; // [xsp+40h] [xbp-50h]
  __int64 v107; // [xsp+48h] [xbp-48h]
  __int64 v108; // [xsp+50h] [xbp-40h]
  unsigned __int64 v109; // [xsp+58h] [xbp-38h]
  _QWORD v110[3]; // [xsp+60h] [xbp-30h] BYREF
  _QWORD v111[3]; // [xsp+78h] [xbp-18h] BYREF

  v111[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 != -1070032894 )
  {
    result = -515;
    goto LABEL_5;
  }
  v3 = *(_QWORD *)(a1 + 32);
  v108 = 0;
  v109 = 0;
  v106 = 0;
  v107 = 0;
  v104 = 0;
  v105 = 0;
  v103 = 0;
  if ( inline_copy_from_user((__int64)&v103, a3, 0x38u) )
    goto LABEL_3;
  if ( HIDWORD(v105) != 24 )
  {
    result = -22;
    goto LABEL_5;
  }
  v99 = a3;
  v100 = v3;
  if ( !(_DWORD)v103 )
    goto LABEL_54;
  v6 = v106;
  if ( !v106 )
    goto LABEL_54;
  mutex_lock(&si_mutex);
  for ( i = *(_QWORD **)(v3 + 24); ; i = (_QWORD *)*i )
  {
    if ( i == (_QWORD *)(v3 + 24) )
      goto LABEL_53;
    if ( (!v6 || *((_DWORD *)i - 13) == v6) && *((_DWORD *)i - 5) == 2 )
      break;
  }
  _X21 = (unsigned int *)(i - 7);
  if ( i == qword_38 )
    goto LABEL_53;
  v9 = *_X21;
  if ( *_X21 )
  {
    do
    {
      __asm { PRFM            #0x11, [X21] }
      do
        v15 = __ldxr(_X21);
      while ( v15 == v9 && __stxr(v9 + 1, _X21) );
      v10 = v9;
      if ( v15 == v9 )
        break;
      v10 = 0;
      v9 = v15;
    }
    while ( v15 );
  }
  else
  {
    v10 = 0;
  }
  if ( (((v10 + 1) | v10) & 0x80000000) != 0 )
  {
    refcount_warn_saturate(i - 7, 0);
    if ( v10 )
      goto LABEL_29;
LABEL_53:
    mutex_unlock(&si_mutex);
    goto LABEL_54;
  }
  if ( !v10 )
    goto LABEL_53;
LABEL_29:
  mutex_unlock(&si_mutex);
  v16 = HIDWORD(v103);
  if ( !HIDWORD(v103) )
  {
    v17 = *(i - 2);
    if ( v17 >> 31 )
    {
      __break(0x800u);
      v16 = -14;
    }
    else
    {
      v18 = *(i - 1);
      v19 = v109;
      _check_object_size(v18, *(i - 2), 0);
      if ( inline_copy_from_user(v18, v19, v17) )
      {
        v16 = -14;
      }
      else if ( (unsigned int)marshal_out_cb_req(*(i - 4), *(i - 1)) )
      {
        v16 = -22;
      }
      else
      {
        v16 = 0;
      }
    }
  }
  *((_DWORD *)i - 6) = v16;
  mutex_lock(&si_mutex);
  if ( *((_DWORD *)i - 5) == 2 )
  {
    *((_DWORD *)i - 5) = 3;
    mutex_unlock(&si_mutex);
    complete(i + 2);
  }
  else
  {
    mutex_unlock(&si_mutex);
    if ( !v16 )
    {
      v20 = *(i - 4);
      while ( 1 )
      {
        v21 = v20 + 24LL * v16;
        if ( *(_DWORD *)v21 == 4 )
        {
          v22 = *(_QWORD *)(v21 + 8);
          if ( v22 >= 2 && *(_DWORD *)(v22 + 12) == 2 && *(__int64 (__fastcall ***)())(v22 + 24) == &cbo_sio_ops )
          {
            *(_DWORD *)(v22 + 88) = 0;
            v22 = *(_QWORD *)(v21 + 8);
          }
          if ( v22 < 2 || *(_DWORD *)(v22 + 12) != 1 )
          {
            put_si_object(v22);
            v22 = *(_QWORD *)(v21 + 8);
          }
          put_si_object(v22);
        }
        else if ( !*(_DWORD *)v21 )
        {
          break;
        }
        ++v16;
      }
    }
  }
  put_txn(_X21);
LABEL_54:
  v23 = (_QWORD **)(v3 + 24);
  StatusReg = _ReadStatusReg(SP_EL0);
  v102 = StatusReg;
  while ( 2 )
  {
    v110[0] = 0;
    v110[1] = StatusReg;
    v110[2] = &woken_wake_function;
    v111[0] = v111;
    v111[1] = v111;
    add_wait_queue(v3 + 40, v110);
    while ( 1 )
    {
      if ( (*(_QWORD *)StatusReg & 0x40) != 0 || (*(_QWORD *)StatusReg & 1) != 0 )
      {
        v32 = 0;
        _X22 = nullptr;
        goto LABEL_83;
      }
      mutex_lock(&si_mutex);
      v26 = *v23;
      if ( *v23 == v23 )
        goto LABEL_58;
      while ( *((_DWORD *)v26 - 5) != 1 )
      {
        v26 = (_QWORD *)*v26;
        if ( v26 == v23 )
          goto LABEL_58;
      }
      _X22 = (unsigned int *)(v26 - 7);
      if ( v26 == qword_38 )
        goto LABEL_58;
      v28 = *_X22;
      if ( *_X22 )
      {
        do
        {
          __asm { PRFM            #0x11, [X22] }
          do
            v31 = __ldxr(_X22);
          while ( v31 == v28 && __stxr(v28 + 1, _X22) );
          v29 = v28;
          if ( v31 == v28 )
            break;
          v29 = 0;
          v28 = v31;
        }
        while ( v31 );
      }
      else
      {
        v29 = 0;
      }
      if ( (((v29 + 1) | v29) & 0x80000000) != 0 )
        break;
      if ( v29 )
        goto LABEL_79;
LABEL_58:
      mutex_unlock(&si_mutex);
      wait_woken(v110, 1, 0x7FFFFFFFFFFFFFFFLL);
    }
    refcount_warn_saturate(v26 - 7, 0);
    if ( !v29 )
      goto LABEL_58;
LABEL_79:
    if ( *((_DWORD *)v26 - 5) == 1 )
      *((_DWORD *)v26 - 5) = 2;
    mutex_unlock(&si_mutex);
    v32 = 1;
LABEL_83:
    remove_wait_queue(v3 + 40, v110);
    if ( !v32 )
    {
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v84 = v99, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v84 = v99 & ((__int64)(v99 << 8) >> 8);
      if ( v84 <= 0x7FFFFFFFFCLL )
      {
        _X9 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v87 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v87 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v87);
        __isb(0xFu);
        _WriteStatusReg(DAIF, _X9);
        LODWORD(_X9) = 0;
        __asm { STTR            W9, [X8] }
        uaccess_ttbr0_disable();
        result = -512;
        goto LABEL_5;
      }
      goto LABEL_3;
    }
    v33 = *((_QWORD *)_X22 + 5);
    v34 = *((_QWORD *)_X22 + 6);
    v101 = _X22;
    v107 = *((_QWORD *)_X22 + 1);
    LODWORD(v104) = *((_QWORD *)_X22 + 2);
    v106 = _X22[1];
    v35 = *((_DWORD **)_X22 + 3);
    v36 = *v35;
    v37 = (v109 + v33 + 7) & 0xFFFFFFFFFFFFFFF8LL;
    if ( *v35 == 1 )
    {
      v38 = 0;
      v39 = 0;
      v40 = 0;
      v41 = 0;
      v42 = v35;
      do
      {
        if ( v41 )
        {
          v41 = -1;
        }
        else
        {
          v44 = (_QWORD *)(v34 + 24 * v38);
          v45 = v37 + v40;
          v46 = v37;
          *v44 = v37 + v40;
          v43 = *((_QWORD *)v42 + 2);
          v44[1] = v43;
          if ( v43 >> 31 )
          {
            __break(0x800u);
            v43 = 1;
          }
          else
          {
            v47 = *((_QWORD *)v42 + 1);
            _check_object_size(v47, v43, 1);
            if ( (*(_BYTE *)(v102 + 70) & 0x20) != 0 || (v48 = v45, (*(_QWORD *)v102 & 0x4000000) != 0) )
              v48 = v45 & ((__int64)(v45 << 8) >> 8);
            if ( 0x8000000000LL - v43 >= v48 )
            {
              v49 = _ReadStatusReg(DAIF);
              __asm { MSR             DAIFSet, #3 }
              v51 = *(_QWORD *)(v102 + 8);
              _WriteStatusReg(TTBR1_EL1, v51 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
              _WriteStatusReg(TTBR0_EL1, v51);
              __isb(0xFu);
              _WriteStatusReg(DAIF, v49);
              v43 = _arch_copy_to_user(v45 & 0xFF7FFFFFFFFFFFFFLL, v47, v43);
              v52 = _ReadStatusReg(DAIF);
              __asm { MSR             DAIFSet, #3 }
              v54 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
              _WriteStatusReg(TTBR0_EL1, v54 - 4096);
              _WriteStatusReg(TTBR1_EL1, v54);
              __isb(0xFu);
              _WriteStatusReg(DAIF, v52);
            }
          }
          v37 = v46;
          if ( v43 )
            v41 = -1;
          else
            v41 = 0;
          v40 = (v40 + *((_QWORD *)v42 + 2) + 7) & 0xFFFFFFFFFFFFFFF8LL;
        }
        v42 = &v35[6 * ++v39];
        v38 = v39;
        v36 = *v42;
      }
      while ( *v42 == 1 );
      v3 = v100;
    }
    else
    {
      v41 = 0;
      v40 = 0;
      v39 = 0;
    }
    v55 = v39;
    v56 = v39;
    v57 = v39;
    if ( v36 == 2 )
    {
      do
      {
        if ( !v41 )
        {
          v61 = 6 * v56;
          v62 = (_QWORD *)(v34 + v61 * 4);
          *v62 = v37 + v40;
          v63 = *(_QWORD *)&v35[v61 + 4];
          v62[1] = v63;
          v40 = (v40 + v63 + 7) & 0xFFFFFFFFFFFFFFF8LL;
        }
        v60 = v35[6 * ++v57];
        v56 = v57;
      }
      while ( v60 == 2 );
      v55 = v57;
      if ( v60 != 3 )
        goto LABEL_123;
LABEL_104:
      v58 = &v35[6 * (int)v56];
      v59 = v55;
      do
      {
        v110[0] = 0;
        if ( v41 )
        {
          *(_QWORD *)(v34 + 24 * v56) = -1;
          put_si_object(*((_QWORD *)v58 + 1));
          v41 = -1;
        }
        else
        {
          if ( (unsigned int)get_u_handle_from_si_object(*((_QWORD *)v58 + 1), v34 + 24 * v56, v110) )
          {
            put_si_object(*((_QWORD *)v58 + 1));
            v41 = -1;
          }
          else
          {
            v41 = 0;
          }
          if ( v110[0] != v3 && v110[0] != 0 && v3 != 0 )
            v41 = -1;
        }
        v58 = &v35[6 * ++v59];
        v56 = v59;
      }
      while ( *v58 == 3 );
    }
    else
    {
      if ( v36 == 3 )
        goto LABEL_104;
LABEL_123:
      v59 = v55;
    }
    v66 = -4096;
    v67 = v59;
    do
    {
      v68 = 6LL * v67++;
      v66 += 4096;
    }
    while ( v35[v68] == 4 );
    if ( v41 )
      goto LABEL_134;
    v69 = v39 & 0xF | (16 * (((_BYTE)v55 - (_BYTE)v39) & 0xF));
    v70 = (unsigned __int8)(v59 - v55);
    v71 = *((_QWORD *)v101 + 5);
    HIDWORD(v104) = v69 & 0xFFFFF0FF | ((v70 & 0xF) << 8) | v66 & 0xF000;
    if ( v71 >> 31 )
    {
      __break(0x800u);
      if ( v106 )
        goto LABEL_55;
LABEL_135:
      mutex_lock(&si_mutex);
      v25 = v101;
      StatusReg = v102;
      if ( v101[9] )
      {
        v81 = *((unsigned int ***)v101 + 8);
        v82 = v101 + 14;
        if ( *v81 == v101 + 14 && (v83 = *(_QWORD *)v82, *(unsigned int **)(*(_QWORD *)v82 + 8LL) == v82) )
        {
          *(_QWORD *)(v83 + 8) = v81;
          *v81 = (unsigned int *)v83;
        }
        else
        {
          _list_del_entry_valid_or_report(v101 + 14);
        }
        *((_QWORD *)v101 + 7) = v101 + 14;
        *((_QWORD *)v101 + 8) = v82;
      }
      mutex_unlock(&si_mutex);
      put_txn(v101);
LABEL_56:
      put_txn(v25);
      continue;
    }
    break;
  }
  v72 = *((_QWORD *)v101 + 6);
  v73 = v109;
  _check_object_size(v72, v71, 1);
  if ( (*(_BYTE *)(v102 + 70) & 0x20) != 0 || (v74 = v73, (*(_QWORD *)v102 & 0x4000000) != 0) )
    v74 = v73 & ((__int64)(v73 << 8) >> 8);
  if ( 0x8000000000LL - v71 >= v74 )
  {
    v75 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v77 = *(_QWORD *)(v102 + 8);
    _WriteStatusReg(TTBR1_EL1, v77 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v77);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v75);
    v71 = _arch_copy_to_user(v73 & 0xFF7FFFFFFFFFFFFFLL, v72, v71);
    v78 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v80 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v80 - 4096);
    _WriteStatusReg(TTBR1_EL1, v80);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v78);
  }
  if ( v71 )
  {
LABEL_134:
    if ( !v106 )
      goto LABEL_135;
LABEL_55:
    v25 = v101;
    complete(v101 + 18);
    StatusReg = v102;
    goto LABEL_56;
  }
  if ( !v106 )
  {
    mutex_lock(&si_mutex);
    if ( v101[9] )
    {
      v88 = *((unsigned int ***)v101 + 8);
      v89 = v101 + 14;
      if ( *v88 == v101 + 14 && (v90 = *(_QWORD *)v89, *(unsigned int **)(*(_QWORD *)v89 + 8LL) == v89) )
      {
        *(_QWORD *)(v90 + 8) = v88;
        *v88 = (unsigned int *)v90;
      }
      else
      {
        _list_del_entry_valid_or_report(v101 + 14);
      }
      *((_QWORD *)v101 + 7) = v101 + 14;
      *((_QWORD *)v101 + 8) = v89;
    }
    mutex_unlock(&si_mutex);
    put_txn(v101);
  }
  put_txn(v101);
  v91 = *(_BYTE *)(v102 + 70);
  LODWORD(v103) = 0;
  if ( (v91 & 0x20) != 0 || (v92 = v99, (*(_QWORD *)v102 & 0x4000000) != 0) )
    v92 = v99 & ((__int64)(v99 << 8) >> 8);
  if ( v92 > 0x7FFFFFFFC8LL )
    goto LABEL_3;
  v93 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v95 = *(_QWORD *)(v102 + 8);
  _WriteStatusReg(TTBR1_EL1, v95 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v95);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v93);
  result = _arch_copy_to_user(v99 & 0xFF7FFFFFFFFFFFFFLL, &v103, 56);
  v96 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v98 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v98 - 4096);
  _WriteStatusReg(TTBR1_EL1, v98);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v96);
  if ( result )
LABEL_3:
    result = -14;
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
