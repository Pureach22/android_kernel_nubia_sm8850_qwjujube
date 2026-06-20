__int64 __fastcall stm_source_link_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned int lock; // w0
  __int64 v8; // x24
  unsigned int v9; // w23
  int v10; // w25
  __int64 device; // x0
  _QWORD *v12; // x21
  _QWORD *v13; // x22
  _QWORD *v14; // x2
  _QWORD *v15; // x1
  __int64 v16; // x0
  __int64 v17; // x24
  int policy; // w23
  __int64 v19; // x1
  __int64 v20; // x2
  __int64 v21; // x3
  __int64 v22; // x0
  __int64 (__fastcall *v23)(__int64, __int64, __int64, __int64); // x8
  __int64 v24; // x1
  __int64 v25; // x2
  int v26; // w0
  _QWORD *v27; // x8
  __int64 v28; // x9
  __int64 v30; // x0
  void (__fastcall *v31)(__int64, __int64, __int64, __int64); // x8
  _QWORD v32[4]; // [xsp+0h] [xbp-20h] BYREF

  v32[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  while ( 1 )
  {
    lock = _srcu_read_lock(&stm_source_srcu);
    v8 = *(_QWORD *)(a1 + 928);
    v9 = lock;
    if ( !v8 )
      break;
    mutex_lock(v8 + 992);
    v10 = _stm_source_link_drop((_QWORD *)a1, v8);
    mutex_unlock(v8 + 992);
    _srcu_read_unlock(&stm_source_srcu, v9);
    if ( v10 != -11 )
      goto LABEL_6;
  }
  _srcu_read_unlock(&stm_source_srcu, lock);
LABEL_6:
  if ( !stm_core_up || (device = class_find_device(&stm_class, 0, a3, &device_match_name)) == 0 )
  {
    a4 = -22;
    goto LABEL_27;
  }
  v12 = (_QWORD *)device;
  if ( (try_module_get(*(_QWORD *)(device + 912)) & 1) == 0 )
  {
    put_device(v12);
    a4 = -22;
    goto LABEL_27;
  }
  _pm_runtime_resume(v12, 5);
  v32[2] = 0;
  v32[0] = 0;
  v32[1] = "default";
  mutex_lock(v12 + 124);
  raw_spin_lock(v12 + 130);
  raw_spin_lock(a1 + 920);
  atomic_store((unsigned __int64)v12, (unsigned __int64 *)(a1 + 928));
  v13 = (_QWORD *)(a1 + 936);
  v14 = v12 + 131;
  v15 = (_QWORD *)v12[132];
  if ( (_QWORD *)(a1 + 936) == v12 + 131 || v15 == v13 || (_QWORD *)*v15 != v14 )
  {
    _list_add_valid_or_report(a1 + 936);
  }
  else
  {
    v12[132] = v13;
    *(_QWORD *)(a1 + 936) = v14;
    *(_QWORD *)(a1 + 944) = v15;
    *v15 = v13;
  }
  raw_spin_unlock(a1 + 920);
  raw_spin_unlock(v12 + 130);
  mutex_unlock(v12 + 124);
  v16 = kstrdup(**(_QWORD **)(a1 + 912), 3264);
  v32[0] = v16;
  if ( !v16 )
  {
    policy = -12;
LABEL_23:
    mutex_lock(v12 + 124);
    raw_spin_lock(v12 + 130);
    raw_spin_lock(a1 + 920);
    *(_QWORD *)(a1 + 928) = 0;
    v27 = *(_QWORD **)(a1 + 944);
    if ( (_QWORD *)*v27 == v13 && (v28 = *v13, *(_QWORD **)(*v13 + 8LL) == v13) )
    {
      *(_QWORD *)(v28 + 8) = v27;
      *v27 = v28;
    }
    else
    {
      _list_del_entry_valid_or_report(a1 + 936);
    }
    *(_QWORD *)(a1 + 936) = a1 + 936;
    *(_QWORD *)(a1 + 944) = v13;
    raw_spin_unlock(a1 + 920);
    raw_spin_unlock(v12 + 130);
    mutex_unlock(v12 + 124);
    _pm_runtime_suspend(v12, 13);
    module_put(v12[114]);
    put_device(v12);
    a4 = policy;
    goto LABEL_27;
  }
  v17 = v16;
  policy = stm_assign_first_policy((__int64)v12, (_DWORD *)(a1 + 952), v32, *(_DWORD *)(*(_QWORD *)(a1 + 912) + 20LL));
  kfree(v17);
  if ( policy )
    goto LABEL_23;
  v22 = v12[123];
  v23 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(v22 + 56);
  if ( v23 )
  {
    v24 = *(unsigned int *)(a1 + 956);
    v25 = *(unsigned int *)(a1 + 960);
    if ( *((_DWORD *)v23 - 1) != 220482162 )
      __break(0x8228u);
    v26 = v23(v22, v24, v25, v21);
    if ( v26 )
    {
      policy = v26;
      stm_output_free((__int64)v12, (_DWORD *)(a1 + 952));
      goto LABEL_23;
    }
  }
  v30 = *(_QWORD *)(a1 + 912);
  v31 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v30 + 32);
  if ( v31 )
  {
    if ( *((_DWORD *)v31 - 1) != -1036693964 )
      __break(0x8228u);
    v31(v30, v19, v20, v21);
  }
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return a4;
}
