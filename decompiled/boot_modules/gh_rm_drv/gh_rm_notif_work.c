__int64 __fastcall gh_rm_notif_work(__int64 a1)
{
  _QWORD *v2; // x19
  unsigned __int16 *v3; // x21
  __int64 v4; // x0
  __int64 result; // x0
  unsigned int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = (_QWORD *)(a1 - 16);
  srcu_notifier_call_chain(&gh_rm_notifier, *(_QWORD *)(a1 - 16), *(_QWORD *)(a1 - 8));
  if ( *v2 == 1443889160 )
  {
    v3 = (unsigned __int16 *)v2[1];
    v4 = *v3;
    if ( (unsigned int)v4 <= 0x3F && *((_BYTE *)v3 + 4) == 2 )
    {
      v6 = 0;
      if ( (gh_rm_get_vm_name(v4, &v6) & 0x80000000) != 0 )
        printk(&unk_12816, *v3);
      else
        ((void (__fastcall *)(_QWORD))gh_complete_vm_setup)(v6);
    }
  }
  vfree(*(_QWORD *)(a1 - 8));
  result = kfree(v2);
  _ReadStatusReg(SP_EL0);
  return result;
}
