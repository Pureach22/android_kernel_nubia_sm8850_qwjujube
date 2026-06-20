__int64 __fastcall ipa3_read_table(__int64 a1, __int64 a2, _DWORD *a3, unsigned int *a4, unsigned int a5)
{
  int v8; // w24
  __int64 v10; // x8
  unsigned int v11; // w21
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 result; // x0
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x1
  void *v18; // x23
  __int64 v19; // x0
  __int64 v20; // x19
  const char *v21; // x0
  __int64 v22; // x19
  const char *v23; // x0
  int v24; // w28
  void *v25; // x0
  __int64 v26; // x8
  __int64 v27; // x24
  const char *v28; // x0
  __int64 v29; // x24
  const char *v30; // x0
  __int64 v31; // x8
  __int64 v32; // x24
  const char *v33; // x0
  __int64 v34; // x24
  const char *v35; // x0
  _BYTE v36[4]; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v37[4]; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v38[2]; // [xsp+10h] [xbp-10h] BYREF

  v8 = a2;
  v38[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = ipa3_ctx;
  v11 = *a4;
  v38[0] = 0;
  v37[0] = 0;
  v36[0] = 0;
  if ( ipa3_ctx )
  {
    v12 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v12 )
    {
      ipc_log_string(v12, "ipa %s:%d In\n", "ipa3_read_table", 2259);
      v10 = ipa3_ctx;
    }
    v13 = *(_QWORD *)(v10 + 34160);
    if ( v13 )
      ipc_log_string(v13, "ipa %s:%d In\n", "ipa3_read_table", 2259);
  }
  if ( !a1 )
  {
    result = printk(&unk_3A3149, a2);
LABEL_8:
    v15 = ipa3_ctx;
    goto LABEL_9;
  }
  if ( (unsigned int)ipahal_nat_entry_size(a5, v38) )
  {
    ipahal_nat_type_str(a5);
    result = printk(&unk_3A315B, "ipa3_read_table");
    v15 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_26;
    v20 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v20 )
    {
      v21 = (const char *)ipahal_nat_type_str(a5);
      result = ipc_log_string(v20, "ipa %s:%d Failed to retrieve size of %s entry\n", "ipa3_read_table", 2270, v21);
      v15 = ipa3_ctx;
    }
    v22 = *(_QWORD *)(v15 + 34160);
    if ( !v22 )
      goto LABEL_9;
    v23 = (const char *)ipahal_nat_type_str(a5);
    result = ipc_log_string(v22, "ipa %s:%d Failed to retrieve size of %s entry\n", "ipa3_read_table", 2270, v23);
    goto LABEL_8;
  }
  v18 = (void *)_kmalloc_cache_noprof(raw_spin_unlock_irqrestore, 3520, 1000);
  if ( v18 )
  {
    if ( v8 )
    {
      v24 = 0;
      do
      {
        if ( (unsigned int)ipahal_nat_is_entry_zeroed(a5, a1, v37) )
        {
          ipahal_nat_type_str(a5);
          printk(&unk_3FAF16, "ipa3_read_table");
          v31 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v32 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v32 )
            {
              v33 = (const char *)ipahal_nat_type_str(a5);
              ipc_log_string(v32, "ipa %s:%d Undefined if %s entry is zero\n", "ipa3_read_table", 2290, v33);
              v31 = ipa3_ctx;
            }
            v34 = *(_QWORD *)(v31 + 34160);
            if ( v34 )
            {
              v35 = (const char *)ipahal_nat_type_str(a5);
              ipc_log_string(v34, "ipa %s:%d Undefined if %s entry is zero\n", "ipa3_read_table", 2290, v35);
            }
          }
          goto LABEL_50;
        }
        if ( (v37[0] & 1) == 0 )
        {
          if ( (unsigned int)ipahal_nat_is_entry_valid(a5, a1, v36) )
          {
            ipahal_nat_type_str(a5);
            printk(&unk_3A318C, "ipa3_read_table");
            v26 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v27 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v27 )
              {
                v28 = (const char *)ipahal_nat_type_str(a5);
                ipc_log_string(v27, "ipa %s:%d Undefined if %s entry is valid\n", "ipa3_read_table", 2302, v28);
                v26 = ipa3_ctx;
              }
              v29 = *(_QWORD *)(v26 + 34160);
              if ( v29 )
              {
                v30 = (const char *)ipahal_nat_type_str(a5);
                ipc_log_string(v29, "ipa %s:%d Undefined if %s entry is valid\n", "ipa3_read_table", 2302, v30);
              }
            }
            goto LABEL_50;
          }
          v24 += v36[0];
          if ( v36[0] )
            v25 = &unk_3AF533;
          else
            v25 = &unk_3FDB99;
          printk(v25, v11);
          ipahal_nat_stringify_entry(a5, a1, v18, 1000);
          printk(&unk_3E0ACE, v18);
          memset(v18, 0, 0x3E8u);
        }
        --v8;
        ++v11;
        a1 += v38[0];
      }
      while ( v8 );
      if ( !v24 )
        goto LABEL_28;
      printk(&unk_3C36C1, v17);
    }
    else
    {
LABEL_28:
      printk(&unk_3AC7A6, v17);
      v24 = 0;
    }
LABEL_50:
    result = kfree(v18);
    *a4 = v11;
    *a3 += v24;
    goto LABEL_8;
  }
  result = printk(&unk_3A98CA, "ipa3_read_table");
  v15 = ipa3_ctx;
  if ( !ipa3_ctx )
    goto LABEL_26;
  v19 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v19 )
  {
    ipc_log_string(v19, "ipa %s:%d Out of memory\n", "ipa3_read_table", 2277);
    v15 = ipa3_ctx;
  }
  result = *(_QWORD *)(v15 + 34160);
  if ( result )
  {
    result = ipc_log_string(result, "ipa %s:%d Out of memory\n", "ipa3_read_table", 2277);
    goto LABEL_8;
  }
LABEL_9:
  if ( v15 )
  {
    v16 = *(_QWORD *)(v15 + 34152);
    if ( v16 )
    {
      ipc_log_string(v16, "ipa %s:%d Out\n", "ipa3_read_table", 2331);
      v15 = ipa3_ctx;
    }
    result = *(_QWORD *)(v15 + 34160);
    if ( result )
      result = ipc_log_string(result, "ipa %s:%d Out\n", "ipa3_read_table", 2331);
  }
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
