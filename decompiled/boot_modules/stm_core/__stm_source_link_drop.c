__int64 __fastcall _stm_source_link_drop(_QWORD *a1, __int64 a2)
{
  __int64 v4; // x21
  unsigned int v5; // w22
  __int64 v6; // x0
  _QWORD *v7; // x8
  _QWORD *v8; // x9
  __int64 v9; // x10
  void (*v10)(void); // x8
  void (*v11)(void); // x8

  raw_spin_lock(a2 + 1040);
  raw_spin_lock(a1 + 115);
  v4 = a1[116];
  if ( v4 == a2 )
  {
    v6 = stm_output_free(a1[116], a1 + 119);
    v7 = (_QWORD *)a1[118];
    v8 = a1 + 117;
    if ( (_QWORD *)*v7 == a1 + 117 && (v9 = *v8, *(_QWORD **)(*v8 + 8LL) == v8) )
    {
      *(_QWORD *)(v9 + 8) = v7;
      *v7 = v9;
    }
    else
    {
      v6 = _list_del_entry_valid_or_report(a1 + 117);
    }
    a1[117] = a1 + 117;
    a1[118] = v8;
    *(_QWORD *)(v4 + 520) = ktime_get_mono_fast_ns(v6);
    _pm_runtime_suspend(v4, 13);
    module_put(*(_QWORD *)(v4 + 912));
    put_device(v4);
    v5 = 0;
    a1[116] = 0;
  }
  else
  {
    v5 = -11;
  }
  raw_spin_unlock(a1 + 115);
  raw_spin_unlock(a2 + 1040);
  if ( v4 == a2 )
  {
    v10 = *(void (**)(void))(a1[114] + 40LL);
    if ( v10 )
    {
      if ( *((_DWORD *)v10 - 1) != -1512452641 )
        __break(0x8228u);
      v10();
    }
    v11 = *(void (**)(void))(*(_QWORD *)(a2 + 984) + 64LL);
    if ( v11 )
    {
      if ( *((_DWORD *)v11 - 1) != -1885626148 )
        __break(0x8228u);
      v11();
    }
  }
  return v5;
}
