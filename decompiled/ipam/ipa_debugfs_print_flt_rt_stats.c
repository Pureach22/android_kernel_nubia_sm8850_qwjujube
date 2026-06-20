__int64 __fastcall ipa_debugfs_print_flt_rt_stats(__int64 a1, const char *a2, __int64 a3, __int64 a4)
{
  __int64 v7; // x22
  __int64 v8; // x0
  int flt_rt_stats; // w0
  int v10; // w23
  __int64 v12; // x19
  int v13; // w23
  unsigned __int64 StatusReg; // x19
  __int64 v15; // x20
  __int64 (__fastcall *v16)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD); // x0
  const char *v17; // [xsp+8h] [xbp-18h]
  __int64 v18; // [xsp+10h] [xbp-10h]
  __int64 v19; // [xsp+18h] [xbp-8h]

  v7 = _kmalloc_cache_noprof(of_property_read_variable_u32_array, 3520, 24);
  if ( v7 )
  {
    while ( 1 )
    {
      *(_BYTE *)(v7 + 2) = 0;
      *(_WORD *)v7 = 8193;
      *(_DWORD *)(v7 + 4) = 16;
      v8 = _kmalloc_cache_noprof(scnprintf, 3520, 512);
      *(_QWORD *)(v7 + 16) = v8;
      if ( !v8 )
        break;
      mutex_lock(ipa3_ctx + 29472);
      flt_rt_stats = ipa_get_flt_rt_stats((unsigned __int8 *)v7);
      if ( flt_rt_stats )
      {
        v10 = flt_rt_stats;
        mutex_unlock(ipa3_ctx + 29472);
        kfree(*(_QWORD *)(v7 + 16));
        kfree(v7);
        return v10;
      }
      v17 = a2;
      v18 = a3;
      v12 = 0;
      a3 = 0;
      v19 = a4;
      v13 = 1;
      a2 = "num_pkts: %d\n";
      a4 = 4096;
      while ( (unsigned int)a3 <= 0x1000 )
      {
        a3 = (unsigned int)scnprintf(
                             (char *)&dbg_buff_1 + (unsigned int)a3,
                             (unsigned int)(4096 - a3),
                             "cnt_id: %d\n",
                             v13)
           + (unsigned int)a3;
        if ( (unsigned int)a3 > 0x1000 )
          break;
        a3 = (unsigned int)scnprintf(
                             (char *)&dbg_buff_1 + (unsigned int)a3,
                             (unsigned int)(4096 - a3),
                             "num_pkts: %d\n",
                             *(_DWORD *)(*(_QWORD *)(v7 + 16) + v12))
           + (unsigned int)a3;
        if ( (unsigned int)a3 > 0x1000 )
          break;
        a3 = (unsigned int)scnprintf(
                             (char *)&dbg_buff_1 + (unsigned int)a3,
                             (unsigned int)(4096 - a3),
                             "num_pkts_hash: %d\n",
                             *(_DWORD *)(*(_QWORD *)(v7 + 16) + v12 + 4))
           + (unsigned int)a3;
        if ( (unsigned int)a3 > 0x1000 )
          break;
        a3 = (unsigned int)scnprintf(
                             (char *)&dbg_buff_1 + (unsigned int)a3,
                             (unsigned int)(4096 - a3),
                             "num_bytes: %lld\n",
                             *(_QWORD *)(*(_QWORD *)(v7 + 16) + v12 + 8))
           + (unsigned int)a3;
        if ( (unsigned int)a3 > 0x1000 )
          break;
        v12 += 16;
        a3 = (unsigned int)scnprintf((char *)&dbg_buff_1 + (unsigned int)a3, (unsigned int)(4096 - a3), "\n")
           + (unsigned int)a3;
        ++v13;
        if ( v12 == 512 )
        {
          mutex_unlock(ipa3_ctx + 29472);
          kfree(*(_QWORD *)(v7 + 16));
          kfree(v7);
          return simple_read_from_buffer(v17, v18, v19, &dbg_buff_1, (int)a3);
        }
      }
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v15 = *(_QWORD *)(StatusReg + 80);
      v16 = of_property_read_variable_u32_array;
      *(_QWORD *)(StatusReg + 80) = &ipa_debugfs_print_flt_rt_stats__alloc_tag;
      v7 = _kmalloc_cache_noprof(v16, 3520, 24);
      *(_QWORD *)(StatusReg + 80) = v15;
      if ( !v7 )
        return -12;
    }
    kfree(v7);
  }
  return -12;
}
