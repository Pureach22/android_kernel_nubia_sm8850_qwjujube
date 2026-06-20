__int64 __fastcall gh_rm_status_nb_handler(__int64 a1, __int64 a2, unsigned __int16 *a3)
{
  __int64 v3; // x1
  int v5; // w8
  unsigned __int16 *v6; // x19
  void *v8; // x0
  unsigned int v9; // [xsp+4h] [xbp-2Ch] BYREF
  _QWORD v10[2]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v11; // [xsp+18h] [xbp-18h]
  __int64 v12; // [xsp+20h] [xbp-10h]
  __int64 v13; // [xsp+28h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = 0;
  v12 = 0;
  v10[0] = 0;
  v10[1] = 0;
  if ( a2 != 1443889160 )
    goto LABEL_3;
  v3 = *a3;
  if ( (unsigned int)v3 > 0x3F )
    goto LABEL_3;
  v5 = *((unsigned __int8 *)a3 + 4);
  v9 = 0;
  if ( v5 != 9 )
  {
    if ( v5 == 3 )
    {
      printk(&unk_12B3F, v3);
      goto LABEL_3;
    }
    if ( v5 != 2 )
    {
      v8 = &unk_12EDA;
      goto LABEL_17;
    }
    v6 = a3;
    printk(&unk_12298, v3);
    if ( (gh_rm_get_vm_id_info(*v6) & 0x80000000) != 0 )
    {
      v3 = *v6;
      v8 = &unk_1212A;
      goto LABEL_17;
    }
    if ( (gh_rm_get_vm_name(*v6, &v9) & 0x80000000) == 0 )
    {
      if ( (gh_rm_get_vminfo(v9, v10) & 0x80000000) != 0 )
        printk(&unk_135CE, v9);
      if ( (gh_rm_populate_hyp_res(*v6, v11) & 0x80000000) != 0 )
        printk(&unk_12E48, *v6);
      goto LABEL_3;
    }
LABEL_15:
    v3 = *v6;
    v8 = &unk_12816;
LABEL_17:
    printk(v8, v3);
    goto LABEL_3;
  }
  printk(&unk_1261A, v3);
  v6 = a3;
  if ( (gh_rm_get_vm_name(*a3, &v9) & 0x80000000) != 0 )
    goto LABEL_15;
  if ( (gh_rm_get_vminfo(v9, v10) & 0x80000000) != 0 )
    printk(&unk_135CE, v9);
  printk(&unk_135F5, *a3);
  if ( (gh_rm_unpopulate_hyp_res(*a3) & 0x80000000) != 0 )
    printk(&unk_1334C, *a3);
  ((void (__fastcall *)(_QWORD))gh_complete_vm_cleanup)(v9);
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return 0;
}
