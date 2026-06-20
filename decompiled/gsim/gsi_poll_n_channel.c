__int64 __fastcall gsi_poll_n_channel(unsigned __int64 a1, char *a2, __int64 a3, int *a4, unsigned __int64 a5)
{
  __int64 v5; // x10
  unsigned int v7; // w21
  char *v8; // x20
  unsigned int v9; // w23
  __int64 v10; // x25
  __int64 v11; // x4
  __int64 v12; // x25
  unsigned int v13; // t1
  __int64 v14; // x9
  __int64 v15; // x0
  __int64 v16; // x8
  __int64 v17; // x22
  _DWORD *v18; // x9
  __int64 v19; // x1
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x8
  unsigned __int64 v23; // x9
  unsigned int ch_reg_idx; // w24
  __int64 v25; // x0
  __int64 v26; // x1
  __int64 v27; // x2
  __int64 (*v28)(void); // x8
  __int64 v29; // x0
  __int64 v30; // x8
  unsigned __int64 v31; // x9
  unsigned __int64 v33; // x11
  unsigned __int64 v34; // x12
  unsigned __int64 v35; // x9
  bool v36; // cc
  unsigned int v37; // w9
  unsigned int v38; // w8
  __int64 v39; // x21
  __int64 v40; // x0
  __int64 v41; // x1
  __int64 v42; // x2

  if ( !gsi_ctx )
  {
    printk(&unk_2DEB9, "gsi_poll_n_channel", 4460);
    return 4294967288LL;
  }
  v7 = a3;
  v8 = a2;
  if ( (int)a3 < 1 || !a4 || !a2 || *(unsigned int *)(gsi_ctx + 28608) <= a1 )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d bad params chan_hdl=%lu notify=%pK\n", "gsi_poll_n_channel", 4467, a1, a2);
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d actual_num=%pK expected_num=%d\n", "gsi_poll_n_channel", 4469, a4, v7);
    return 4294967290LL;
  }
  if ( a1 >= 0x25 )
  {
    __break(0x5512u);
LABEL_41:
    dev_err(*(_QWORD *)(v5 + 8), "%s:%d address = 0x%llx not in range\n", "gsi_get_complete_num", 660, a5);
    __break(0x800u);
LABEL_42:
    dev_err(*(_QWORD *)(v5 + 8), "%s:%d address = 0x%llx not in range\n", "gsi_get_complete_num", 665, v35);
    __break(0x800u);
    return gsi_process_evt_re(v40, v41, v42);
  }
  v9 = *(_DWORD *)(gsi_ctx + 20);
  v10 = gsi_ctx + 448 * a1;
  v13 = *(_DWORD *)(v10 + 184);
  v12 = v10 + 184;
  v11 = v13;
  if ( v13 != 2 && (_DWORD)v11 != 5 )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d op not supported for protocol %u\n", "gsi_poll_n_channel", 4478);
    return 4294967289LL;
  }
  if ( !*(_DWORD *)(v12 + 120) )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d bad state %d\n", "gsi_poll_n_channel", 4484);
    return 4294967289LL;
  }
  v14 = *(_QWORD *)(v12 + 208);
  if ( !v14 )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d no event ring associated chan_hdl=%lu\n", "gsi_poll_n_channel", 4489, a1);
    return 4294967289LL;
  }
  v15 = raw_spin_lock_irqsave(v14 + 136, a2, a3, a4, v11);
  v16 = *(_QWORD *)(v12 + 208);
  v17 = v15;
  a5 = *(_QWORD *)(v16 + 184);
  if ( *(_QWORD *)(v16 + 168) == a5 )
  {
    v18 = *(_DWORD **)(v16 + 120);
    v19 = *(unsigned __int8 *)(v16 + 132);
    v20 = *(_QWORD *)(v12 + 208);
    if ( *(v18 - 1) != -1228272253 )
      __break(0x8229u);
    v21 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v18)(v20, v19, v9);
    v22 = *(_QWORD *)(v12 + 208);
    v23 = v21 | ((unsigned __int64)*(unsigned int *)(v22 + 172) << 32);
    *(_QWORD *)(v22 + 168) = v23;
    v16 = *(_QWORD *)(v12 + 208);
    a5 = *(_QWORD *)(v16 + 184);
    if ( v23 == a5 )
    {
      if ( *(_DWORD *)(gsi_ctx + 16) < 0xAu )
      {
        v26 = v9;
        v27 = 0;
        v25 = 20;
      }
      else
      {
        ch_reg_idx = gsihal_get_ch_reg_idx(*(unsigned __int8 *)(v16 + 132));
        gsihal_get_ch_reg_mask(*(unsigned __int8 *)(*(_QWORD *)(v12 + 208) + 132LL));
        v25 = 133;
        v26 = v9;
        v27 = ch_reg_idx;
      }
      gsihal_write_reg_nk(v25, v26, v27);
      __dmb(2u);
      v28 = *(__int64 (**)(void))(*(_QWORD *)(v12 + 208) + 120LL);
      if ( *((_DWORD *)v28 - 1) != -1228272253 )
        __break(0x8228u);
      v29 = v28();
      v30 = *(_QWORD *)(v12 + 208);
      v31 = v29 | ((unsigned __int64)*(unsigned int *)(v30 + 172) << 32);
      *(_QWORD *)(v30 + 168) = v31;
      v16 = *(_QWORD *)(v12 + 208);
      a5 = *(_QWORD *)(v16 + 184);
      if ( v31 == a5 )
      {
        raw_spin_unlock_irqrestore(v16 + 136, v17);
        ++*(_QWORD *)(v12 + 384);
        return 9;
      }
    }
  }
  v33 = *(_QWORD *)(v16 + 152);
  v5 = gsi_ctx;
  if ( v33 > a5 )
    goto LABEL_41;
  v34 = *(_QWORD *)(v16 + 200);
  if ( v34 <= a5 )
    goto LABEL_41;
  v35 = *(_QWORD *)(v16 + 168);
  if ( v33 > v35 || v34 <= v35 )
    goto LABEL_42;
  v36 = v35 > a5;
  v37 = v35 - a5;
  if ( !v36 )
    v37 += *(_DWORD *)(v16 + 192);
  v38 = (unsigned __int16)(v37 / *(unsigned __int8 *)(v16 + 196));
  if ( v38 >= v7 )
    v38 = v7;
  *a4 = v38;
  if ( v38 )
  {
    v39 = 0;
    do
    {
      gsi_process_evt_re(*(_QWORD *)(v12 + 208), v8, 0);
      ++v39;
      v8 += 24;
    }
    while ( v39 < *a4 );
  }
  raw_spin_unlock_irqrestore(*(_QWORD *)(v12 + 208) + 136LL, v17);
  ++*(_QWORD *)(v12 + 376);
  return 0;
}
