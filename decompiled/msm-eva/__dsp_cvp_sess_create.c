unsigned int *__fastcall _dsp_cvp_sess_create(__int64 a1)
{
  int v2; // w23
  unsigned int *v3; // x19
  __int64 *fastrpc_node_with_handle; // x0
  __int64 *v5; // x19
  unsigned int *result; // x0
  int v7; // w8
  unsigned __int64 v8; // x8
  __int64 v9; // x2
  __int64 v10; // x3
  unsigned int *v11; // x20
  __int64 v12; // x0
  __int64 *v13; // x22
  int v14; // w8
  unsigned __int64 v15; // x8
  __int64 v16; // x1
  __int64 v17; // x2
  void *v18; // x0
  unsigned __int64 v19; // x8
  unsigned __int64 v20; // x8
  unsigned __int64 v21; // x10
  unsigned __int64 v22; // x8
  unsigned __int64 v23; // x8
  unsigned int *v24; // x20
  unsigned __int64 StatusReg; // x10
  int v26; // w10
  __int64 v27; // x11
  int v28; // w8
  int v29; // w2
  __int64 v30; // x28
  __int64 *v31; // x2
  __int64 **v32; // x0
  __int64 **v33; // x1
  __int64 v34; // x3
  unsigned __int64 v35; // x8
  unsigned __int64 v36; // x8
  unsigned __int64 v37; // x8
  __int64 *v38; // x8
  char v40; // w8
  __int64 *v41; // x8
  __int64 (__fastcall *v42)(_QWORD); // x9
  __int64 v43; // x0
  unsigned __int64 v44; // x8
  unsigned int v47; // w10
  int v52; // w8
  unsigned int v55; // w10
  unsigned int v56; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v57; // [xsp+8h] [xbp-8h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = HIDWORD(qword_6C7A8);
  *(_DWORD *)(a1 + 4) = 0;
  if ( v2 )
  {
    v3 = (unsigned int *)&dword_6C9F0;
  }
  else
  {
    v3 = (unsigned int *)&off_6C7E0;
    if ( (msm_cvp_debug & 0x800) != 0 && !msm_cvp_debug_out )
    {
      v3 = (unsigned int *)&off_6C7E0;
      printk(&unk_88665, "dsp", "__dsp_cvp_sess_create", (unsigned int)dword_6C7C0);
    }
  }
  fastrpc_node_with_handle = cvp_get_fastrpc_node_with_handle(*v3);
  if ( fastrpc_node_with_handle )
  {
    v5 = fastrpc_node_with_handle;
    result = (unsigned int *)fastrpc_node_with_handle[32];
    if ( !result )
    {
      if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        result = (unsigned int *)printk(
                                   &unk_973A4,
                                   *(unsigned int *)(StatusReg + 1800),
                                   *(unsigned int *)(StatusReg + 1804),
                                   "warn");
      }
      goto LABEL_21;
    }
    v56 = 0;
    result = (unsigned int *)fastrpc_driver_invoke(result, 3, &v56);
    if ( (_DWORD)result )
    {
      v7 = msm_cvp_debug_out;
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v23 = _ReadStatusReg(SP_EL0);
        v24 = result;
        printk(&unk_8CB7C, *(unsigned int *)(v23 + 1800), *(unsigned int *)(v23 + 1804), &unk_8E7CE);
        v7 = msm_cvp_debug_out;
        result = v24;
        if ( (msm_cvp_debug & 1) == 0 )
          goto LABEL_21;
      }
      else if ( (msm_cvp_debug & 1) == 0 )
      {
        goto LABEL_21;
      }
      if ( !v7 )
      {
        v8 = _ReadStatusReg(SP_EL0);
        result = (unsigned int *)printk(
                                   &unk_85BF5,
                                   *(unsigned int *)(v8 + 1800),
                                   *(unsigned int *)(v8 + 1804),
                                   &unk_8E7CE);
      }
LABEL_21:
      if ( *((int *)v5 + 7) < 1 )
        goto LABEL_22;
      goto LABEL_96;
    }
    result = (unsigned int *)find_get_pid(v56);
    if ( !result )
    {
      if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
      {
        v19 = _ReadStatusReg(SP_EL0);
        result = (unsigned int *)printk(
                                   &unk_886A6,
                                   *(unsigned int *)(v19 + 1800),
                                   *(unsigned int *)(v19 + 1804),
                                   "warn");
      }
      goto LABEL_21;
    }
    if ( (msm_cvp_debug & 0x800) != 0 && !msm_cvp_debug_out )
      printk(&unk_96838, "dsp", "__dsp_cvp_sess_create", result);
    result = (unsigned int *)get_pid_task();
    if ( !result )
    {
      if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
      {
        v20 = _ReadStatusReg(SP_EL0);
        result = (unsigned int *)printk(
                                   &unk_91B32,
                                   *(unsigned int *)(v20 + 1800),
                                   *(unsigned int *)(v20 + 1804),
                                   "warn");
      }
      goto LABEL_21;
    }
    v11 = result;
    v12 = msm_cvp_open(4, (__int64)result, v9, v10);
    if ( !v12 )
    {
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v22 = _ReadStatusReg(SP_EL0);
        printk(&unk_91B61, *(unsigned int *)(v22 + 1800), *(unsigned int *)(v22 + 1804), &unk_8E7CE);
      }
LABEL_83:
      result = v11 + 16;
      __asm { PRFM            #0x11, [X0] }
      do
        v52 = __ldxr(result);
      while ( __stlxr(v52 - 1, result) );
      if ( v52 == 1 )
      {
        __dmb(9u);
        result = (unsigned int *)_put_task_struct(v11);
      }
      else if ( v52 <= 0 )
      {
        result = (unsigned int *)refcount_warn_saturate(result, 3);
      }
      goto LABEL_21;
    }
    v13 = (__int64 *)v12;
    v14 = (int)off_6C7E0;
    *(_QWORD *)(v12 + 144) = v5;
    *(_DWORD *)(v12 + 152) = v14;
    if ( v2 )
    {
      if ( (unsigned int)dword_6CCC8 > 0x40 )
      {
        if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
          goto LABEL_73;
        v15 = _ReadStatusReg(SP_EL0);
        v16 = *(unsigned int *)(v15 + 1800);
        v17 = *(unsigned int *)(v15 + 1804);
        v18 = &unk_91675;
LABEL_72:
        printk(v18, v16, v17, &unk_8E7CE);
LABEL_73:
        mutex_lock(v5 + 39);
        v38 = (__int64 *)v5[37];
        if ( v38 )
        {
          while ( v38 != v5 + 37 && *v38 )
          {
            _ZF = v38 - 2 == v13;
            v38 = (__int64 *)*v38;
            if ( _ZF )
            {
              list_del_0(v13 + 2);
              --*((_DWORD *)v5 + 5);
              msm_cvp_close((__int64)v13);
              goto LABEL_82;
            }
          }
        }
        if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
        {
          v44 = _ReadStatusReg(SP_EL0);
          printk(&unk_95DA4, *(unsigned int *)(v44 + 1800), *(unsigned int *)(v44 + 1804), "warn");
        }
LABEL_82:
        mutex_unlock(v5 + 39);
        goto LABEL_83;
      }
      if ( dword_6CCC8 )
      {
        v29 = 0;
        while ( 1 )
        {
          v30 = v29;
          result = (unsigned int *)msm_cvp_set_sysprop_sess((__int64)v13, (int *)&gfa_cv + 2 * v29 + 447, v29);
          if ( (_DWORD)result )
            break;
          v29 = v30 + 1;
          if ( (int)v30 + 1 >= (unsigned int)dword_6CCC8 )
            goto LABEL_50;
        }
        if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
          goto LABEL_73;
        if ( (unsigned __int64)(8 * v30 - 861) < 0xFFFFFFFFFFFFF5A7LL )
        {
          __break(1u);
LABEL_96:
          _X8 = (unsigned int *)v5 + 7;
          __asm { PRFM            #0x11, [X8] }
          do
            v47 = __ldxr(_X8);
          while ( __stxr(v47 - 1, _X8) );
          goto LABEL_22;
        }
        v37 = _ReadStatusReg(SP_EL0);
        v17 = *(unsigned int *)(v37 + 1804);
        v16 = *(unsigned int *)(v37 + 1800);
        v18 = &unk_83AE8;
        goto LABEL_72;
      }
    }
    else
    {
      v26 = dword_6C7C0;
      v27 = qword_6C7C8;
      v28 = dword_6C7D0;
      *(_DWORD *)(v12 + 14832) = dword_6C7C4;
      *(_DWORD *)(v12 + 14844) = v28;
      *(_DWORD *)(v12 + 14828) = v26;
      *(_QWORD *)(v12 + 14836) = v27;
      *(_DWORD *)(v12 + 14848) = 8;
    }
LABEL_50:
    mutex_lock(v5 + 39);
    v31 = v5 + 37;
    v32 = (__int64 **)(v13 + 2);
    v33 = (__int64 **)v5[38];
    if ( v13 + 2 == v5 + 37 || v33 == v32 || *v33 != v31 )
    {
      _list_add_valid_or_report(v32, v33, v31);
    }
    else
    {
      v5[38] = (__int64)v32;
      v13[2] = (__int64)v31;
      v13[3] = (__int64)v33;
      *v33 = (__int64 *)v32;
    }
    ++*((_DWORD *)v5 + 5);
    mutex_unlock(v5 + 39);
    if ( (msm_cvp_debug & 0x800) != 0 && !msm_cvp_debug_out )
      printk(&unk_8FB33, "dsp", v13, v5);
    if ( (unsigned int)msm_cvp_session_create((__int64)v13) )
    {
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v35 = _ReadStatusReg(SP_EL0);
        printk(&unk_87069, *(unsigned int *)(v35 + 1800), *(unsigned int *)(v35 + 1804), &unk_8E7CE);
      }
      goto LABEL_73;
    }
    if ( (msm_cvp_debug & 0x800) != 0 && !msm_cvp_debug_out )
      printk(&unk_83EA5, "dsp", "__dsp_cvp_sess_create", v34);
    result = (unsigned int *)msm_cvp_get_session_info((__int64)v13, (_DWORD *)(a1 + 32));
    if ( (_DWORD)result )
    {
      if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
        goto LABEL_73;
      v36 = _ReadStatusReg(SP_EL0);
      v16 = *(unsigned int *)(v36 + 1800);
      v17 = *(unsigned int *)(v36 + 1804);
      v18 = &unk_848D7;
      goto LABEL_72;
    }
    *(_QWORD *)(a1 + 56) = v13;
    if ( *((int *)v5 + 7) >= 1 )
    {
      _X8 = (unsigned int *)v5 + 7;
      __asm { PRFM            #0x11, [X8] }
      do
        v55 = __ldxr(_X8);
      while ( __stxr(v55 - 1, _X8) );
    }
    v40 = BYTE1(msm_cvp_debug);
    v13[20] = (__int64)v11;
    if ( (v40 & 8) != 0 && !msm_cvp_debug_out )
      result = (unsigned int *)printk(&unk_831EE, "dsp", "__dsp_cvp_sess_create", *(unsigned int *)(a1 + 32));
    v41 = *(__int64 **)(v13[16] + 256);
    if ( v41 )
    {
      v42 = (__int64 (__fastcall *)(_QWORD))v41[23];
      if ( v42 )
      {
        v43 = *v41;
        if ( *((_DWORD *)v42 - 1) != -1066802076 )
          __break(0x8229u);
        result = (unsigned int *)v42(v43);
      }
    }
  }
  else
  {
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      v21 = _ReadStatusReg(SP_EL0);
      printk(&unk_84897, *(unsigned int *)(v21 + 1800), *(unsigned int *)(v21 + 1804), "warn");
    }
    result = (unsigned int *)((__int64 (__fastcall *)(_QWORD, _QWORD))eva_fastrpc_driver_unregister)(
                               (unsigned int)off_6C7E0,
                               0);
    *(_DWORD *)(a1 + 4) = -1;
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
