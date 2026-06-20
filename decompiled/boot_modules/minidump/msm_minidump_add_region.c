__int64 __fastcall msm_minidump_add_region(__int64 a1)
{
  __int64 v1; // x20
  __int64 *v2; // x21
  size_t v4; // x0
  __int64 v5; // x1
  unsigned __int8 v6; // w9
  __int64 (__fastcall *v7)(_QWORD); // x8
  __int64 v9; // x0
  __int64 v10; // x9
  __int64 *v11; // x1
  __int64 v12; // x8
  __int64 v13; // x9
  unsigned int v14; // w19

  if ( !a1 )
    return 4294967274LL;
  v4 = strnlen((const char *)a1, 0xDu);
  if ( v4 >= 0xE )
  {
    v4 = _fortify_panic(2, 13, v4 + 1);
    goto LABEL_23;
  }
  if ( v4 == 13 )
  {
LABEL_23:
    v9 = _fortify_panic(4, 13, v4 + 1);
    goto LABEL_24;
  }
  if ( !*(_QWORD *)(a1 + 24) || (*(_BYTE *)(a1 + 40) & 3) != 0 )
  {
    printk_deferred("Invalid entry details\n");
    return 4294967274LL;
  }
  if ( !md_core_0 || (v6 = atomic_load((unsigned __int8 *)&md_init_done), (v6 & 1) == 0) )
  {
    printk(&unk_112CBF, v5);
    v2 = &md_mod_info_seq_buf;
    v1 = raw_spin_lock_irqsave(&mdt_lock);
    if ( (unsigned int)md_num_regions >= 0xC9 )
    {
      printk_deferred("Maximum entries reached\n");
    }
    else
    {
      v9 = _kmalloc_cache_noprof(per_cpu_ptr_to_phys, 2336, 64);
      if ( v9 )
      {
        v10 = *(_QWORD *)(a1 + 8);
        v11 = (__int64 *)off_230;
        *(_QWORD *)(v9 + 16) = *(_QWORD *)a1;
        *(_QWORD *)(v9 + 24) = v10;
        v12 = *(_QWORD *)(a1 + 40);
        *(_QWORD *)(v9 + 48) = *(_QWORD *)(a1 + 32);
        *(_QWORD *)(v9 + 56) = v12;
        v13 = *(_QWORD *)(a1 + 24);
        *(_QWORD *)(v9 + 32) = *(_QWORD *)(a1 + 16);
        *(_QWORD *)(v9 + 40) = v13;
        if ( v11 != (__int64 *)v9 && (_UNKNOWN **)*v11 == &pending_list )
        {
          off_230 = (_UNKNOWN **)v9;
          *(_QWORD *)v9 = &pending_list;
          *(_QWORD *)(v9 + 8) = v11;
          *v11 = v9;
LABEL_19:
          v14 = *((_DWORD *)v2 + 6);
          *((_DWORD *)v2 + 6) = v14 + 1;
          raw_spin_unlock_irqrestore(&mdt_lock, v1);
          return v14;
        }
LABEL_24:
        _list_add_valid_or_report(v9);
        goto LABEL_19;
      }
    }
    raw_spin_unlock_irqrestore(&mdt_lock, v1);
    return 4294967284LL;
  }
  v7 = *(__int64 (__fastcall **)(_QWORD))(md_core_0 + 32);
  if ( *((_DWORD *)v7 - 1) != -1087585291 )
    __break(0x8228u);
  return v7(a1);
}
