__int64 __fastcall msm_cvp_destroy(__int64 *a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  unsigned __int64 v4; // x8
  __int64 **v5; // x8
  __int64 *v6; // x9
  __int64 v7; // x0
  __int64 **v8; // x1
  void (__fastcall *v9)(_QWORD); // x8
  unsigned __int64 StatusReg; // x21
  __int64 **v11; // x8
  __int64 *v12; // x25
  __int64 v13; // x8
  __int64 **v14; // x9
  unsigned int v17; // w10
  unsigned int v24; // w10

  if ( a1 && (v1 = a1[16]) != 0 )
  {
    if ( *((_DWORD *)a1 + 34) == 4 )
    {
      cvp_dsp_del_sess(*((unsigned int *)a1 + 38), a1);
      a1[20] = 0;
    }
    mutex_lock(v1);
    mutex_lock(v1 + 48);
    v5 = (__int64 **)a1[1];
    if ( *v5 == a1 && (v6 = (__int64 *)*a1, *(__int64 **)(*a1 + 8) == a1) )
    {
      v6[1] = (__int64)v5;
      *v5 = v6;
    }
    else
    {
      _list_del_entry_valid_or_report(a1);
    }
    *a1 = 0xDEAD000000000100LL;
    a1[1] = 0xDEAD000000000122LL;
    _X9 = &nr_insts;
    __asm { PRFM            #0x11, [X9] }
    do
      v24 = __ldxr((unsigned int *)&nr_insts);
    while ( __stxr(v24 - 1, (unsigned int *)&nr_insts) );
    mutex_unlock(v1 + 48);
    mutex_unlock(v1);
    v7 = a1[1616];
    a1[73] = 0;
    *((_DWORD *)a1 + 148) = 0;
    kfree(v7);
    a1[1616] = 0;
    msm_cvp_debugfs_deinit_inst(a1);
    raw_spin_lock(a1 + 22);
    v8 = (__int64 **)a1[24];
    if ( v8 != (__int64 **)(a1 + 24) )
    {
      do
      {
        v12 = *v8;
        v11 = (__int64 **)v8[1];
        if ( *v11 == (__int64 *)v8 && (__int64 **)v12[1] == v8 )
        {
          v12[1] = (__int64)v11;
          *v11 = v12;
        }
        else
        {
          _list_del_entry_valid_or_report(v8);
          v8 = v14;
        }
        *v8 = (__int64 *)v8;
        v8[1] = (__int64 *)v8;
        v13 = cvp_driver;
        _X9 = (unsigned int *)(cvp_driver + 80);
        __asm { PRFM            #0x11, [X9] }
        do
          v17 = __ldxr(_X9);
        while ( __stxr(v17 - 1, _X9) );
        kmem_cache_free(*(_QWORD *)(v13 + 72));
        v8 = (__int64 **)v12;
      }
      while ( v12 != a1 + 24 );
    }
    *(__int64 *)((char *)a1 + 180) = 4;
    raw_spin_unlock(a1 + 22);
    _wake_up(a1 + 26, 3, 0, 0);
    a1[1915] = 0x300000004LL;
    v9 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(v1 + 272) + 8LL);
    if ( *((_DWORD *)v9 - 1) != -1787504020 )
      __break(0x8228u);
    v9(a1);
    StatusReg = _ReadStatusReg(SP_EL0);
    printk(&unk_947DC, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), a1 + 1924);
    a1[40] = 3735928559LL;
    if ( *((int *)a1 + 42) >= 1 )
    {
      if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
        printk(&unk_90E7F, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
      *(_DWORD *)(v1 + 1264) += *((_DWORD *)a1 + 42);
    }
    kfree(a1);
    result = 0;
    if ( (msm_cvp_debug & 0x2000) != 0 && !msm_cvp_debug_out )
    {
      printk(&unk_8474A, "sess", (unsigned int)nr_insts, *(unsigned int *)(cvp_driver + 80));
      return 0;
    }
  }
  else
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v4 = _ReadStatusReg(SP_EL0);
      printk(&unk_912BD, *(unsigned int *)(v4 + 1800), *(unsigned int *)(v4 + 1804), &unk_8E7CE);
      return 4294967274LL;
    }
  }
  return result;
}
