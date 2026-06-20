__int64 __fastcall cvp_clean_fence_queue(__int64 a1)
{
  int v2; // w20
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 *v5; // x20
  void (__fastcall *v6)(__int64, __int64, __int64 *, __int64); // x8
  void (__fastcall *v7)(__int64, __int64 *); // x8
  __int64 *v8; // x21
  __int64 **v9; // x8
  __int64 *v10; // x9
  __int64 *i; // x20
  void (__fastcall *v12)(__int64, __int64, __int64 *, __int64); // x8

  mutex_lock(a1 + 15272);
  *(_DWORD *)(a1 + 15324) = 1;
  mutex_unlock(a1 + 15272);
  v2 = 101;
  while ( *(_DWORD *)(a1 + 15384) )
  {
    usleep_range_state(100, 200, 2);
    if ( !--v2 )
    {
      result = 4294967186LL;
      if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        printk(&unk_8C765, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
        return 4294967186LL;
      }
      return result;
    }
  }
  mutex_lock(a1 + 15272);
  v5 = *(__int64 **)(a1 + 15328);
  if ( v5 != (__int64 *)(a1 + 15328) )
  {
    do
    {
      v8 = (__int64 *)*v5;
      if ( (msm_cvp_debug & 0x80) != 0 && !msm_cvp_debug_out )
        printk(
          &unk_902DD,
          "synx",
          "cvp_clean_fence_queue",
          (unsigned int)(*(_DWORD *)(a1 + 324) ^ *(_DWORD *)(a1 + 320)));
      if ( *((_DWORD *)v5 + 7) != -1329939778 )
      {
        v9 = (__int64 **)v5[1];
        if ( *v9 == v5 && (v10 = (__int64 *)*v5, *(__int64 **)(*v5 + 8) == v5) )
        {
          v10[1] = (__int64)v9;
          *v9 = v10;
        }
        else
        {
          _list_del_entry_valid_or_report(v5);
        }
        *v5 = (__int64)v5;
        v5[1] = (__int64)v5;
        msm_cvp_unmap_frame(a1, *(_QWORD *)(v5[38] + 32));
        v6 = *(void (__fastcall **)(__int64, __int64, __int64 *, __int64))(*(_QWORD *)(*(_QWORD *)(a1 + 128) + 272LL)
                                                                         + 40LL);
        if ( *((_DWORD *)v6 - 1) != 1180956429 )
          __break(0x8228u);
        v6(a1, 2, v5, 4);
        v7 = *(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)(*(_QWORD *)(a1 + 128) + 272LL) + 16LL);
        if ( *((_DWORD *)v7 - 1) != -746362046 )
          __break(0x8228u);
        v7(a1, v5);
        kfree(v5[38]);
        v5[38] = 0;
        kfree(v5);
      }
      v5 = v8;
    }
    while ( v8 != (__int64 *)(a1 + 15328) );
  }
  for ( i = *(__int64 **)(a1 + 15368); i != (__int64 *)(a1 + 15368); i = (__int64 *)*i )
  {
    if ( (msm_cvp_debug & 0x80) != 0 && !msm_cvp_debug_out )
      printk(&unk_8AA05, "synx", "cvp_clean_fence_queue", (unsigned int)(*(_DWORD *)(a1 + 324) ^ *(_DWORD *)(a1 + 320)));
    if ( *((_DWORD *)i + 7) != -1329939778 )
    {
      v12 = *(void (__fastcall **)(__int64, __int64, __int64 *, __int64))(*(_QWORD *)(*(_QWORD *)(a1 + 128) + 272LL)
                                                                        + 40LL);
      if ( *((_DWORD *)v12 - 1) != 1180956429 )
        __break(0x8228u);
      v12(a1, 1, i, 4);
    }
  }
  mutex_unlock(a1 + 15272);
  return 0;
}
