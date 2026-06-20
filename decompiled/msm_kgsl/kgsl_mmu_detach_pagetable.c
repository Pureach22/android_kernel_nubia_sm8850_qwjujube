__int64 __fastcall kgsl_mmu_detach_pagetable(_QWORD *a1)
{
  __int64 v2; // x9
  _QWORD *v3; // x8
  _QWORD *v4; // x10
  _QWORD *v5; // x11
  __int64 v6; // x0
  __int64 result; // x0

  v2 = raw_spin_lock_irqsave(&unk_3A838);
  v4 = a1 + 1;
  v3 = (_QWORD *)a1[1];
  if ( v3 != a1 + 1 )
  {
    v5 = (_QWORD *)a1[2];
    if ( (_QWORD *)*v5 == v4 && (_QWORD *)v3[1] == v4 )
    {
      v3[1] = v5;
      *v5 = v3;
    }
    else
    {
      _list_del_entry_valid_or_report(a1 + 1);
    }
    a1[1] = a1 + 1;
    a1[2] = v4;
  }
  raw_spin_unlock_irqrestore(&unk_3A838, v2);
  v6 = a1[4];
  if ( v6 )
  {
    sysfs_remove_group(v6, &pagetable_attr_group);
    v6 = a1[4];
  }
  result = kobject_put(v6);
  a1[4] = 0;
  return result;
}
