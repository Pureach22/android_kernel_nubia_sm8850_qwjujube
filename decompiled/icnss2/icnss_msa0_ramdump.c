__int64 __fastcall icnss_msa0_ramdump(__int64 a1)
{
  unsigned __int64 v2; // x20
  __int64 result; // x0
  __int64 v4; // x9
  __int64 v5; // x10
  __int64 v6; // x1
  _QWORD *v7; // x8
  _QWORD **v8; // x9
  const char *v9; // x19
  int v10; // w20
  _QWORD *v11; // [xsp+0h] [xbp-40h] BYREF
  _QWORD *v12; // [xsp+8h] [xbp-38h]
  _QWORD **v13; // [xsp+10h] [xbp-30h] BYREF
  _QWORD **v14; // [xsp+18h] [xbp-28h]
  __int64 v15; // [xsp+20h] [xbp-20h]
  __int64 v16; // [xsp+28h] [xbp-18h]
  __int64 v17; // [xsp+30h] [xbp-10h]
  __int64 v18; // [xsp+38h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 2928);
  result = dump_enabled(a1);
  if ( (result & 1) == 0 )
  {
    v9 = "%sicnss2: Dump collection is not enabled\n";
    printk("%sicnss2: Dump collection is not enabled\n", byte_13289B);
LABEL_12:
    result = ipc_log_string(icnss_ipc_log_context, v9, &unk_12DBF3);
    goto LABEL_9;
  }
  if ( !v2 || v2 > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_9;
  v11 = &v11;
  v12 = &v11;
  v4 = *(_QWORD *)(a1 + 1824);
  v5 = *(unsigned int *)(a1 + 1816);
  v14 = &v11;
  v15 = 0;
  v16 = v4;
  v17 = v5;
  v12 = &v13;
  v13 = &v11;
  v11 = &v13;
  v6 = *(_QWORD *)(v2 + 40);
  if ( !v6 )
  {
    v9 = "%sicnss2: Created Dump Device not found\n";
    printk("%sicnss2: Created Dump Device not found\n", byte_130B32);
    goto LABEL_12;
  }
  result = qcom_dump(&v11, v6);
  if ( (_DWORD)result )
  {
    v10 = result;
    printk("%sicnss2: Failed to dump msa0, err = %d\n", byte_130B32, result);
    result = ipc_log_string(
               icnss_ipc_log_context,
               "%sicnss2: Failed to dump msa0, err = %d\n",
               (const char *)&unk_12DBF3,
               v10);
  }
  else
  {
    v7 = v14;
    if ( *v14 == &v13 && (v8 = v13, v13[1] == &v13) )
    {
      v13[1] = v14;
      *v7 = v8;
    }
    else
    {
      result = _list_del_entry_valid_or_report(&v13);
    }
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
