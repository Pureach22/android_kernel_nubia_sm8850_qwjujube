__int64 __fastcall kgsl_mmu_pagetable_add(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  __int64 v4; // x2
  __int64 *v5; // x8
  __int64 v6; // x9
  int v7; // w3
  __int64 result; // x0
  char s[8]; // [xsp+8h] [xbp-18h] BYREF
  __int64 v10; // [xsp+10h] [xbp-10h]
  __int64 v11; // [xsp+18h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = raw_spin_lock_irqsave(&unk_3A838);
  v4 = qword_3A828;
  v5 = (__int64 *)(a2 + 8);
  v6 = v3;
  if ( qword_3A828 == a2 + 8 || v5 == &qword_3A828 || *(__int64 **)(qword_3A828 + 8) != &qword_3A828 )
  {
    _list_add_valid_or_report(a2 + 8, &qword_3A828);
  }
  else
  {
    *(_QWORD *)(qword_3A828 + 8) = v5;
    *(_QWORD *)(a2 + 8) = v4;
    *(_QWORD *)(a2 + 16) = &qword_3A828;
    qword_3A828 = a2 + 8;
  }
  raw_spin_unlock_irqrestore(&unk_3A838, v6);
  v7 = *(_DWORD *)(a2 + 24);
  *(_QWORD *)s = 0;
  v10 = 0;
  snprintf(s, 0x10u, "%d", v7);
  result = kobject_create_and_add(s, qword_3A7E8);
  *(_QWORD *)(a2 + 32) = result;
  if ( !result )
    goto LABEL_9;
  result = sysfs_create_group(result, &pagetable_attr_group);
  if ( (_DWORD)result )
  {
    result = *(_QWORD *)(a2 + 32);
    if ( result )
      result = kobject_put(result);
LABEL_9:
    *(_QWORD *)(a2 + 32) = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
