__int64 __fastcall bam_dma_terminate_all(__int64 a1)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 *v5; // x9
  __int64 *v6; // x21
  __int64 v7; // x20
  __int64 *v8; // x10
  unsigned __int64 v9; // x11
  __int64 *v10; // x2
  __int64 *v11; // x0
  __int64 *v12; // x12
  __int64 **v15; // x8
  __int64 *v16; // x13
  __int64 v17; // x9
  __int64 *v18; // x10
  __int64 *v19; // x11
  __int64 v20; // x9
  __int64 *v21; // x10
  __int64 *v22; // x11
  __int64 v23; // x9
  __int64 *v24; // x10
  __int64 *v25; // x11
  __int64 v26; // x9
  __int64 *v27; // x10
  __int64 *v28; // x11
  __int64 v29; // x9
  __int64 *v30; // x10
  __int64 *v31; // x11
  __int64 v33; // [xsp+8h] [xbp-18h] BYREF
  __int64 *v34; // [xsp+10h] [xbp-10h]
  __int64 v35; // [xsp+18h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 256);
  v33 = (__int64)&v33;
  v34 = &v33;
  v3 = *(_QWORD *)(v2 + 536);
  if ( v3 )
  {
    ipc_log_string(v3, "%s chan id:%d\n", "bam_dma_terminate_all", *(_DWORD *)(a1 + 264));
    v2 = *(_QWORD *)(a1 + 256);
  }
  _ftrace_dbg(*(_QWORD *)(v2 + 8), "%s chan id:%d\n");
  v4 = raw_spin_lock_irqsave(a1 + 160);
  v5 = *(__int64 **)(a1 + 376);
  v6 = (__int64 *)(a1 + 376);
  v7 = v4;
  if ( v5 != (__int64 *)(a1 + 376) )
  {
    bam_chan_init_hw(a1, *((unsigned int *)v5 + 4));
    v5 = *(__int64 **)(a1 + 376);
  }
  if ( v5 != v6 )
  {
    v8 = (__int64 *)(a1 + 200);
    v9 = 0xDEAD000000000100LL;
    do
    {
      v10 = (__int64 *)*v8;
      v11 = v5 - 5;
      v12 = (__int64 *)*v5;
      if ( *(__int64 **)(*v8 + 8) != v8 || v11 == v8 || v10 == v11 )
      {
        _list_add_valid_or_report(v11, v8);
      }
      else
      {
        v10[1] = (__int64)v11;
        *(v5 - 5) = (__int64)v10;
        *(v5 - 4) = (__int64)v8;
        *v8 = (__int64)v11;
      }
      v15 = (__int64 **)v5[1];
      if ( *v15 == v5 && (v16 = (__int64 *)*v5, *(__int64 **)(*v5 + 8) == v5) )
      {
        v16[1] = (__int64)v15;
        *v15 = v16;
      }
      else
      {
        _list_del_entry_valid_or_report(v5);
      }
      *v5 = v9;
      v5[1] = v9 + 34;
      v5 = v12;
    }
    while ( v12 != v6 );
  }
  v17 = *(_QWORD *)(a1 + 168);
  if ( v17 != a1 + 168 )
  {
    v18 = v34;
    v19 = *(__int64 **)(a1 + 176);
    *(_QWORD *)(v17 + 8) = v34;
    *v18 = v17;
    *v19 = (__int64)&v33;
    v34 = v19;
    *(_QWORD *)(a1 + 168) = a1 + 168;
    *(_QWORD *)(a1 + 176) = a1 + 168;
  }
  v20 = *(_QWORD *)(a1 + 184);
  if ( v20 != a1 + 184 )
  {
    v21 = v34;
    v22 = *(__int64 **)(a1 + 192);
    *(_QWORD *)(v20 + 8) = v34;
    *v21 = v20;
    *v22 = (__int64)&v33;
    v34 = v22;
    *(_QWORD *)(a1 + 184) = a1 + 184;
    *(_QWORD *)(a1 + 192) = a1 + 184;
  }
  v23 = *(_QWORD *)(a1 + 200);
  if ( v23 != a1 + 200 )
  {
    v24 = v34;
    v25 = *(__int64 **)(a1 + 208);
    *(_QWORD *)(v23 + 8) = v34;
    *v24 = v23;
    *v25 = (__int64)&v33;
    v34 = v25;
    *(_QWORD *)(a1 + 200) = a1 + 200;
    *(_QWORD *)(a1 + 208) = a1 + 200;
  }
  v26 = *(_QWORD *)(a1 + 216);
  if ( v26 != a1 + 216 )
  {
    v27 = v34;
    v28 = *(__int64 **)(a1 + 224);
    *(_QWORD *)(v26 + 8) = v34;
    *v27 = v26;
    *v28 = (__int64)&v33;
    v34 = v28;
    *(_QWORD *)(a1 + 216) = a1 + 216;
    *(_QWORD *)(a1 + 224) = a1 + 216;
  }
  v29 = *(_QWORD *)(a1 + 232);
  if ( v29 != a1 + 232 )
  {
    v30 = v34;
    v31 = *(__int64 **)(a1 + 240);
    *(_QWORD *)(v29 + 8) = v34;
    *v30 = v29;
    *v31 = (__int64)&v33;
    v34 = v31;
    *(_QWORD *)(a1 + 232) = a1 + 232;
    *(_QWORD *)(a1 + 240) = a1 + 232;
  }
  raw_spin_unlock_irqrestore(a1 + 160, v7);
  vchan_dma_desc_free_list(a1, &v33);
  _ReadStatusReg(SP_EL0);
  return 0;
}
