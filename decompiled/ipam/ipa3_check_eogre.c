__int64 __fastcall ipa3_check_eogre(_QWORD *a1, unsigned __int8 *a2, unsigned __int8 *a3)
{
  int v6; // w22
  int v7; // w0
  bool v13; // w8
  __int64 v14; // x22
  __int64 v15; // x0
  __int64 result; // x0
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v25; // x0
  _QWORD v26[16]; // [xsp+0h] [xbp-90h] BYREF
  int v27; // [xsp+80h] [xbp-10h]
  __int64 v28; // [xsp+88h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 || !a3 )
  {
    printk(&unk_3B5D28, "ipa3_check_eogre");
    v17 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v18 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v18 )
      {
        ipc_log_string(
          v18,
          "ipa %s:%d NULL ptr: eogre_info(%pK) and/or send2uC(%pK) and/or send2ipacm(%pK)\n",
          "ipa3_check_eogre",
          14321,
          a1,
          a2,
          a3);
        v17 = ipa3_ctx;
      }
      v19 = *(_QWORD *)(v17 + 34160);
      if ( v19 )
      {
        ipc_log_string(
          v19,
          "ipa %s:%d NULL ptr: eogre_info(%pK) and/or send2uC(%pK) and/or send2ipacm(%pK)\n",
          "ipa3_check_eogre",
          14321,
          a1,
          a2,
          a3);
        result = 4294967291LL;
        goto LABEL_33;
      }
    }
    goto LABEL_49;
  }
  v27 = 0;
  memset(v26, 0, sizeof(v26));
  v6 = bcmp((const void *)(ipa3_ctx + 51108), v26, 0x84u);
  v7 = bcmp(a1, v26, 0x84u);
  *a3 = 0;
  *a2 = 0;
  if ( !v6 )
  {
    if ( v7 )
    {
      *a3 = 1;
      *a2 = 1;
      goto LABEL_27;
    }
    printk(&unk_3B3107, "ipa3_check_eogre");
    v23 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v24 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v24 )
      {
        ipc_log_string(
          v24,
          "ipa %s:%d Attempting to disable EoGRE. EoGRE is already disabled. No work needs to be done.\n",
          "ipa3_check_eogre",
          14347);
        v23 = ipa3_ctx;
      }
      v25 = *(_QWORD *)(v23 + 34160);
      if ( v25 )
      {
        ipc_log_string(
          v25,
          "ipa %s:%d Attempting to disable EoGRE. EoGRE is already disabled. No work needs to be done.\n",
          "ipa3_check_eogre",
          14347);
        result = 4294967291LL;
        goto LABEL_33;
      }
    }
LABEL_49:
    result = 4294967291LL;
    goto LABEL_33;
  }
  if ( v7 )
  {
    printk(&unk_3F334A, "ipa3_check_eogre");
    v20 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v21 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v21 )
      {
        ipc_log_string(
          v21,
          "ipa %s:%d EoGRE is already enabled for iptype(%d). No work needs to be done.\n",
          "ipa3_check_eogre",
          14360,
          *(_DWORD *)(ipa3_ctx + 51108));
        v20 = ipa3_ctx;
      }
      v22 = *(_QWORD *)(v20 + 34160);
      if ( v22 )
        ipc_log_string(
          v22,
          "ipa %s:%d EoGRE is already enabled for iptype(%d). No work needs to be done.\n",
          "ipa3_check_eogre",
          14360,
          *(_DWORD *)(v20 + 51108));
    }
    goto LABEL_49;
  }
  *a2 = bcmp((const void *)(ipa3_ctx + 51156), a1 + 6, 0x52u) != 0;
  v13 = *(_QWORD *)(ipa3_ctx + 51108) != *a1
     || *(_QWORD *)(ipa3_ctx + 51116) != a1[1]
     || *(_QWORD *)(ipa3_ctx + 51124) != a1[2]
     || *(_QWORD *)(ipa3_ctx + 51132) != a1[3]
     || *(_QWORD *)(ipa3_ctx + 51140) != a1[4]
     || *(_QWORD *)(ipa3_ctx + 51148) != a1[5];
  *a3 = v13;
LABEL_27:
  v14 = ipa3_ctx;
  memcpy((void *)(ipa3_ctx + 51108), a1, 0x84u);
  if ( !v14 )
  {
LABEL_32:
    result = 0;
    goto LABEL_33;
  }
  v15 = *(_QWORD *)(v14 + 34152);
  if ( v15 )
  {
    ipc_log_string(v15, "ipa %s:%d send2uC(%u) send2ipacm(%u)\n", "ipa3_check_eogre", 14383, *a2, *a3);
    v14 = ipa3_ctx;
  }
  result = *(_QWORD *)(v14 + 34160);
  if ( result )
  {
    ipc_log_string(result, "ipa %s:%d send2uC(%u) send2ipacm(%u)\n", "ipa3_check_eogre", 14383, *a2, *a3);
    goto LABEL_32;
  }
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
