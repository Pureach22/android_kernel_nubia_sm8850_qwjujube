__int64 __fastcall mhi_misc_register_controller(__int64 a1)
{
  __int64 v1; // x21
  __int64 v3; // x19
  __int64 v4; // x22
  _QWORD *v5; // x23
  __int64 v6; // x1
  __int64 *v7; // x1
  __int64 v8; // x0
  __int64 v9; // x0

  v1 = *(_QWORD *)(a1 + 16);
  v3 = _kmalloc_cache_noprof(_kmalloc_noprof, &print_fmt_mhi_intvec_states[1192], 168);
  if ( v3 )
  {
    v4 = *(_QWORD *)(a1 + 8);
    v5 = *(_QWORD **)(a1 + 16);
    if ( v4 == 200 )
    {
      v6 = v5[1];
    }
    else
    {
      dev_set_name(
        v5 + 5,
        "mhi_%04x_%02u.%02u.%02u",
        *(unsigned __int16 *)(v4 - 138),
        *(_DWORD *)(*(_QWORD *)(v4 - 184) + 252LL),
        *(unsigned __int8 *)(*(_QWORD *)(v4 - 184) + 248LL),
        (unsigned __int8)*(_DWORD *)(v4 - 144) >> 3);
      v6 = v5[19];
      if ( !v6 )
        v6 = v5[5];
      v5[1] = v6;
      *(_DWORD *)(v3 + 88) = (*(unsigned __int16 *)(v4 - 138) << 16)
                           | ((*(_DWORD *)(*(_QWORD *)(v4 - 184) + 252LL) & 0xF) << 12)
                           | (16 * *(unsigned __int8 *)(*(_QWORD *)(v4 - 184) + 248LL))
                           | (*(_DWORD *)(v4 - 144) >> 3) & 0xF;
    }
    *(_QWORD *)(v3 + 32) = ipc_log_context_create(100, v6, 0);
    *(_QWORD *)(v3 + 16) = a1;
    mutex_lock(&unk_21020);
    v7 = (__int64 *)qword_21018;
    if ( (__int64 *)v3 == &mhi_bus || qword_21018 == v3 || *(__int64 **)qword_21018 != &mhi_bus )
    {
      _list_add_valid_or_report(v3, qword_21018);
    }
    else
    {
      qword_21018 = v3;
      *(_QWORD *)v3 = &mhi_bus;
      *(_QWORD *)(v3 + 8) = v7;
      *v7 = v3;
    }
    mutex_unlock(&unk_21020);
    *(_QWORD *)(v1 + 192) = v3;
    v8 = alloc_workqueue("mhi_offload_wq", 131090, 1);
    *(_QWORD *)(v3 + 112) = v8;
    if ( v8 )
    {
      *(_QWORD *)(v3 + 120) = 0xFFFFFFFE00000LL;
      *(_QWORD *)(v3 + 128) = v3 + 128;
      *(_QWORD *)(v3 + 136) = v3 + 128;
      *(_QWORD *)(v3 + 144) = mhi_reg_write_work;
      v9 = _kmalloc_cache_noprof(trace_event_buffer_reserve, &print_fmt_mhi_intvec_states[1192], 0x2000);
      *(_QWORD *)(v3 + 152) = v9;
      if ( v9 )
      {
        *(_DWORD *)(v3 + 160) = -1;
        return 0;
      }
      destroy_workqueue(*(_QWORD *)(v3 + 112));
    }
    else
    {
      dev_err(*(_QWORD *)(a1 + 8), "Failed to allocate offload workqueue\n");
    }
    ipc_log_context_destroy(*(_QWORD *)(v3 + 32));
  }
  return 4294967284LL;
}
