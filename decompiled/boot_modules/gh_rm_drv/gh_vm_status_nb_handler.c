__int64 __fastcall gh_vm_status_nb_handler(__int64 a1, __int64 a2, unsigned __int16 *a3)
{
  unsigned int v5; // [xsp+4h] [xbp-2Ch] BYREF
  _QWORD v6[5]; // [xsp+8h] [xbp-28h] BYREF

  v6[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v6, 0, 32);
  v5 = 0;
  switch ( a2 )
  {
    case 5LL:
      if ( (gh_rm_get_vm_name(*a3, &v5) & 0x80000000) != 0 )
        goto LABEL_12;
      if ( (gh_rm_get_vminfo(v5, v6) & 0x80000000) != 0 )
        printk(&unk_135CE, v5);
      else
        ((void (__fastcall *)(_QWORD))gh_wait_for_vm_cleanup)(v5);
      break;
    case 4LL:
      gh_reset_vm_prop_table_entry(*a3);
      break;
    case 1LL:
      if ( (gh_rm_get_vm_id_info(*a3) & 0x80000000) != 0 )
      {
        printk(&unk_1212A, *a3);
        break;
      }
      if ( (gh_rm_get_vm_name(*a3, &v5) & 0x80000000) == 0 )
      {
        ((void (__fastcall *)(_QWORD))gh_wait_for_vm_setup)(v5);
        break;
      }
LABEL_12:
      printk(&unk_12816, *a3);
      break;
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
