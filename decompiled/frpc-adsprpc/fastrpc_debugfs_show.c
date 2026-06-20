__int64 __fastcall fastrpc_debugfs_show(__int64 a1)
{
  __int64 v1; // x26
  unsigned int v2; // w8
  unsigned int v5; // w19
  unsigned int v11; // w9
  __int64 v12; // x22
  __int64 v13; // x22
  __int64 v14; // x22
  __int64 v15; // x0
  __int64 v16; // x8
  __int64 v17; // x1
  __int64 *v18; // x27
  __int64 *v19; // x21
  __int64 v20; // x0
  __int64 v21; // x8
  __int64 v22; // x19
  __int64 v23; // x8
  __int64 v24; // x8
  __int64 v25; // x8
  _QWORD *i; // x19
  __int64 *v27; // x26
  __int64 *j; // x27
  __int64 *v29; // t1
  __int64 v30; // x27
  __int64 *v31; // x28
  __int64 *v32; // x1
  __int64 *v33; // x1
  __int64 *v35; // x21
  __int64 *v36; // x21
  __int64 v37; // [xsp+8h] [xbp-8h]
  __int64 *v38; // [xsp+8h] [xbp-8h]

  v1 = *(_QWORD *)(a1 + 128);
  if ( v1 )
  {
    v2 = *(_DWORD *)(v1 + 664);
    _X0 = (unsigned int *)(v1 + 664);
    if ( v2 )
    {
      do
      {
        __asm { PRFM            #0x11, [X0] }
        do
          v11 = __ldxr(_X0);
        while ( v11 == v2 && __stxr(v2 + 1, _X0) );
        v5 = v2;
        if ( v11 == v2 )
          break;
        v5 = 0;
        v2 = v11;
      }
      while ( v11 );
    }
    else
    {
      v5 = 0;
    }
    if ( (((v5 + 1) | v5) & 0x80000000) != 0 )
    {
      refcount_warn_saturate(_X0, 0);
      if ( !v5 )
        return 0;
    }
    else if ( !v5 )
    {
      return 0;
    }
    seq_printf(a1, "%s %12s %d\n", "tgid", ":", *(_DWORD *)(v1 + 240));
    seq_printf(a1, "%s %7s %d\n", "tgid_frpc", ":", *(_DWORD *)(v1 + 244));
    seq_printf(a1, "%s %3s %d\n", "is_secure_dev", ":", *(unsigned __int8 *)(v1 + 304));
    seq_printf(a1, "%s %3s %d\n", "num_pers_hdrs", ":", *(_DWORD *)(v1 + 276));
    seq_printf(a1, "%s %2s %d\n", "num_cached_buf", ":", *(_DWORD *)(v1 + 272));
    seq_printf(a1, "%s %5s %d\n", "wake_enable", ":", *(_DWORD *)(v1 + 300));
    seq_printf(a1, "%s %2s %d\n", "is_unsigned_pd", ":", *(unsigned __int8 *)(v1 + 306));
    seq_printf(a1, "%s %7s %d\n", "sessionid", ":", *(_DWORD *)(v1 + 284));
    seq_printf(a1, "%s %9s %d\n", "pd_type", ":", *(_DWORD *)(v1 + 268));
    seq_printf(a1, "%s %9s %d\n", "profile", ":", *(_DWORD *)(v1 + 280));
    if ( *(_QWORD *)(v1 + 128) )
    {
      seq_printf(a1, "\n=============== Channel Context ===============\n");
      print_ctx_info(a1, *(_QWORD *)(v1 + 128));
    }
    if ( *(_QWORD *)(v1 + 136) )
    {
      seq_printf(a1, "\n=============== Session Context ===============\n");
      ((void (__fastcall *)(__int64, _QWORD))print_sctx_info)(a1, *(_QWORD *)(v1 + 136));
    }
    if ( *(_QWORD *)(v1 + 144) )
    {
      seq_printf(a1, "\n=============== Secure Session Context ===============\n");
      ((void (__fastcall *)(__int64, _QWORD))print_sctx_info)(a1, *(_QWORD *)(v1 + 144));
    }
    raw_spin_lock(v1 + 320);
    if ( *(_QWORD *)(v1 + 160) )
    {
      seq_printf(a1, "\n=============== Init Mem ===============\n");
      v12 = *(_QWORD *)(v1 + 160);
      seq_printf(a1, "\n %s %2s 0x%p", "virt", ":", *(const void **)(v12 + 48));
      seq_printf(a1, "\n %s %2s 0x%llx", "phys", ":", *(_QWORD *)(v12 + 64));
      seq_printf(a1, "\n %s %2s 0x%lx", "raddr", ":", *(_QWORD *)(v12 + 144));
      seq_printf(a1, "\n %s %2s 0x%x", "type", ":", *(_DWORD *)(v12 + 56));
      seq_printf(a1, "\n %s %2s 0x%llx", "size", ":", *(_QWORD *)(v12 + 72));
      seq_printf(a1, "\n %s %s %d", "in_use", ":", *(unsigned __int8 *)(v12 + 152));
    }
    if ( *(_QWORD *)(v1 + 168) )
    {
      seq_printf(a1, "\n=============== Persistent Header Buf ===============\n");
      v13 = *(_QWORD *)(v1 + 168);
      seq_printf(a1, "\n %s %2s 0x%p", "virt", ":", *(const void **)(v13 + 48));
      seq_printf(a1, "\n %s %2s 0x%llx", "phys", ":", *(_QWORD *)(v13 + 64));
      seq_printf(a1, "\n %s %2s 0x%lx", "raddr", ":", *(_QWORD *)(v13 + 144));
      seq_printf(a1, "\n %s %2s 0x%x", "type", ":", *(_DWORD *)(v13 + 56));
      seq_printf(a1, "\n %s %2s 0x%llx", "size", ":", *(_QWORD *)(v13 + 72));
      seq_printf(a1, "\n %s %s %d", "in_use", ":", *(unsigned __int8 *)(v13 + 152));
    }
    if ( *(_QWORD *)(v1 + 192) )
    {
      seq_printf(a1, "\n=============== Pre-allocated Header Buf ===============\n");
      v14 = *(_QWORD *)(v1 + 192);
      seq_printf(a1, "\n %s %2s 0x%p", "virt", ":", *(const void **)(v14 + 48));
      seq_printf(a1, "\n %s %2s 0x%llx", "phys", ":", *(_QWORD *)(v14 + 64));
      seq_printf(a1, "\n %s %2s 0x%lx", "raddr", ":", *(_QWORD *)(v14 + 144));
      seq_printf(a1, "\n %s %2s 0x%x", "type", ":", *(_DWORD *)(v14 + 56));
      seq_printf(a1, "\n %s %2s 0x%llx", "size", ":", *(_QWORD *)(v14 + 72));
      seq_printf(a1, "\n %s %s %d", "in_use", ":", *(unsigned __int8 *)(v14 + 152));
    }
    raw_spin_unlock(v1 + 320);
    seq_printf(a1, "\n=============== Global Maps ===============\n");
    v15 = raw_spin_lock_irqsave(*(_QWORD *)(v1 + 128) + 51600LL);
    v16 = *(_QWORD *)(v1 + 128);
    v17 = v15;
    v18 = *(__int64 **)(v16 + 52744);
    if ( v18 != (__int64 *)(v16 + 52744) )
    {
      v37 = v15;
      do
      {
        v19 = (__int64 *)*v18;
        seq_printf(a1, "\n %s %2s 0x%p", "virt", ":", (const void *)v18[6]);
        seq_printf(a1, "\n %s %2s 0x%llx", "phys", ":", v18[8]);
        seq_printf(a1, "\n %s %2s 0x%lx", "raddr", ":", v18[18]);
        seq_printf(a1, "\n %s %2s 0x%x", "type", ":", *((_DWORD *)v18 + 14));
        seq_printf(a1, "\n %s %2s 0x%llx", "size", ":", v18[9]);
        seq_printf(a1, "\n %s %s %d", "in_use", ":", *((unsigned __int8 *)v18 + 152));
        v16 = *(_QWORD *)(v1 + 128);
        v18 = v19;
      }
      while ( v19 != (__int64 *)(v16 + 52744) );
      v17 = v37;
    }
    raw_spin_unlock_irqrestore(v16 + 51600, v17);
    seq_printf(a1, "\n=============== DSP Signal Status ===============\n");
    v20 = raw_spin_lock_irqsave(v1 + 324);
    v21 = *(_QWORD *)(v1 + 504);
    v22 = v20;
    if ( v21 )
      seq_printf(a1, "%d : %d ", 0, *(_DWORD *)(v21 + 32));
    v23 = *(_QWORD *)(v1 + 512);
    if ( v23 )
      seq_printf(a1, "%d : %d ", 1, *(_DWORD *)(v23 + 32));
    v24 = *(_QWORD *)(v1 + 520);
    if ( v24 )
      seq_printf(a1, "%d : %d ", 2, *(_DWORD *)(v24 + 32));
    v25 = *(_QWORD *)(v1 + 528);
    if ( v25 )
      seq_printf(a1, "%d : %d ", 3, *(_DWORD *)(v25 + 32));
    raw_spin_unlock_irqrestore(v1 + 324, v22);
    seq_printf(a1, "\n=============== User space maps ===============\n");
    raw_spin_lock(v1 + 320);
    for ( i = *(_QWORD **)(v1 + 16); i != (_QWORD *)(v1 + 16); i = (_QWORD *)*i )
    {
      if ( i )
        print_map_info(a1, (__int64)i);
    }
    seq_printf(a1, "\n=============== Kernel maps ===============\n");
    v38 = (__int64 *)v1;
    v29 = *(__int64 **)(v1 + 64);
    v27 = (__int64 *)(v1 + 64);
    for ( j = v29; j != v27; j = (__int64 *)*j )
    {
      if ( j )
      {
        seq_printf(a1, "\n %s %2s 0x%p", "virt", ":", (const void *)j[6]);
        seq_printf(a1, "\n %s %2s 0x%llx", "phys", ":", j[8]);
        seq_printf(a1, "\n %s %2s 0x%lx", "raddr", ":", j[18]);
        seq_printf(a1, "\n %s %2s 0x%x", "type", ":", *((_DWORD *)j + 14));
        seq_printf(a1, "\n %s %2s 0x%llx", "size", ":", j[9]);
        seq_printf(a1, "\n %s %s %d", "in_use", ":", *((unsigned __int8 *)j + 152));
      }
    }
    seq_printf(a1, "\n=============== Cached Bufs ===============\n");
    v30 = v38[10];
    if ( (__int64 *)v30 != v38 + 10 )
    {
      do
      {
        v31 = *(__int64 **)v30;
        if ( v30 )
        {
          seq_printf(a1, "\n %s %2s 0x%p", "virt", ":", *(const void **)(v30 + 48));
          seq_printf(a1, "\n %s %2s 0x%llx", "phys", ":", *(_QWORD *)(v30 + 64));
          seq_printf(a1, "\n %s %2s 0x%lx", "raddr", ":", *(_QWORD *)(v30 + 144));
          seq_printf(a1, "\n %s %2s 0x%x", "type", ":", *(_DWORD *)(v30 + 56));
          seq_printf(a1, "\n %s %2s 0x%llx", "size", ":", *(_QWORD *)(v30 + 72));
          seq_printf(a1, "\n %s %s %d", "in_use", ":", *(unsigned __int8 *)(v30 + 152));
        }
        v30 = (__int64)v31;
      }
      while ( v31 != v38 + 10 );
    }
    seq_printf(a1, "\n=============== Pending contexts ===============\n");
    v32 = (__int64 *)v38[4];
    if ( v32 != v38 + 4 )
    {
      do
      {
        v35 = (__int64 *)*v32;
        if ( v32 )
          print_ictx_info(a1, (__int64)v32);
        v32 = v35;
      }
      while ( v35 != v38 + 4 );
    }
    seq_printf(a1, "\n=============== Interrupted contexts ===============\n");
    v33 = (__int64 *)v38[6];
    if ( v33 != v38 + 6 )
    {
      do
      {
        v36 = (__int64 *)*v33;
        if ( v33 )
          print_ictx_info(a1, (__int64)v33);
        v33 = v36;
      }
      while ( v36 != v38 + 6 );
    }
    raw_spin_unlock(v38 + 40);
    fastrpc_file_put(v38, 0);
  }
  return 0;
}
