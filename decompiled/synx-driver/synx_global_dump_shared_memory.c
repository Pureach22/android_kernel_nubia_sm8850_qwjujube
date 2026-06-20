__int64 __fastcall synx_global_dump_shared_memory(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  __int64 i; // x19
  __int64 v7; // x4
  __int64 v8; // x5
  __int64 result; // x0
  __int64 v10; // x5
  __int64 v11; // x8
  __int64 v12; // x0
  unsigned int v13; // w19
  __int64 v14; // x4
  __int64 v15; // x5
  __int64 v16; // x8
  __int64 v17; // x0
  unsigned int v18; // w20
  __int64 v19; // x3
  __int64 v20; // x4
  _QWORD v21[2]; // [xsp+0h] [xbp-10h] BYREF

  v21[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21[0] = 0;
  if ( !synx_gmem_2 )
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_267BF, &unk_29207, "synx_global_dump_shared_memory", 131, a5, a6);
    result = 4294967274LL;
    goto LABEL_43;
  }
  for ( i = 0; i != 10; ++i )
  {
    if ( (get_ipclite_feature(4) & 1) != 0 )
    {
      result = ipclite_global_spin_lock_timeout((unsigned int)i, 500, v21);
      if ( (_DWORD)result )
        goto LABEL_37;
      if ( (synx_debug & 0x10) != 0 )
        goto LABEL_16;
    }
    else
    {
      if ( !synx_hwlock )
      {
        if ( (synx_debug & 1) != 0 )
        {
          printk(&unk_2AE54, &unk_29207, "synx_gmem_lock", 54, v7, v8);
          result = 4294967274LL;
          if ( (synx_debug & 1) == 0 )
            goto LABEL_43;
        }
        else
        {
          result = 4294967274LL;
LABEL_37:
          if ( (synx_debug & 1) == 0 )
            goto LABEL_43;
        }
        v18 = result;
        v19 = 140;
        v20 = (unsigned int)i;
        goto LABEL_48;
      }
      result = _hwspin_lock_timeout(synx_hwlock, 500, 1, v21);
      if ( (_DWORD)result )
        goto LABEL_37;
      *(_WORD *)(synx_gmem_2 + 12) = 0;
      if ( (synx_debug & 0x10) != 0 )
LABEL_16:
        printk(
          &unk_2B218,
          "verb",
          "synx_global_dump_shared_memory",
          145,
          "synx_global_dump_shared_memory",
          (unsigned int)i);
    }
    if ( (get_ipclite_feature(4) & 1) != 0 )
    {
      ipclite_global_spin_unlock((unsigned int)i, v21);
    }
    else
    {
      v11 = synx_gmem_2;
      if ( *(_WORD *)(synx_gmem_2 + 12) && (synx_debug & 2) != 0 )
      {
        printk(&unk_29DF8, "warn", "synx_gmem_lock_owner_clear", 42, *(unsigned __int16 *)(synx_gmem_2 + 12), v10);
        v11 = synx_gmem_2;
      }
      v12 = synx_hwlock;
      *(_WORD *)(v11 + 12) = 8;
      _hwspin_unlock(v12, 1, v21);
    }
  }
  v13 = 0;
  while ( 1 )
  {
    if ( (get_ipclite_feature(4) & 1) != 0 )
    {
      result = ipclite_global_spin_lock_timeout((unsigned __int8)v13, 500, v21);
      if ( (_DWORD)result )
        goto LABEL_42;
      if ( (synx_debug & 0x10) != 0 )
        goto LABEL_34;
      goto LABEL_26;
    }
    if ( !synx_hwlock )
      break;
    result = _hwspin_lock_timeout(synx_hwlock, 500, 1, v21);
    if ( (_DWORD)result )
      goto LABEL_42;
    *(_WORD *)(synx_gmem_2 + 12) = 0;
    if ( (synx_debug & 0x10) != 0 )
LABEL_34:
      printk(&unk_2A09F, "verb", "synx_global_dump_shared_memory", 161, "synx_global_dump_shared_memory", v13);
LABEL_26:
    synx_global_print_data(synx_gmem_2 + glcoredata_size * v13, "synx_global_dump_shared_memory");
    if ( (get_ipclite_feature(4) & 1) != 0 )
    {
      ipclite_global_spin_unlock((unsigned __int8)v13, v21);
    }
    else
    {
      v16 = synx_gmem_2;
      if ( *(_WORD *)(synx_gmem_2 + 12) && (synx_debug & 2) != 0 )
      {
        printk(&unk_29DF8, "warn", "synx_gmem_lock_owner_clear", 42, *(unsigned __int16 *)(synx_gmem_2 + 12), v15);
        v16 = synx_gmem_2;
      }
      v17 = synx_hwlock;
      *(_WORD *)(v16 + 12) = 8;
      _hwspin_unlock(v17, 1, v21);
    }
    if ( ++v13 == 320 )
    {
      result = 0;
      goto LABEL_43;
    }
  }
  if ( (synx_debug & 1) == 0 )
  {
    result = 4294967274LL;
LABEL_42:
    if ( (synx_debug & 1) == 0 )
      goto LABEL_43;
    goto LABEL_47;
  }
  printk(&unk_2AE54, &unk_29207, "synx_gmem_lock", 54, v14, v8);
  result = 4294967274LL;
  if ( (synx_debug & 1) == 0 )
    goto LABEL_43;
LABEL_47:
  v18 = result;
  v19 = 157;
  v20 = v13;
LABEL_48:
  printk(&unk_29CCD, &unk_29207, "synx_global_dump_shared_memory", v19, v20, v8);
  result = v18;
LABEL_43:
  _ReadStatusReg(SP_EL0);
  return result;
}
