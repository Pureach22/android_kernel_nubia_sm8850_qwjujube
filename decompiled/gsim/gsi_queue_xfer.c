__int64 __fastcall gsi_queue_xfer(unsigned __int64 a1, __int64 a2, __int64 *a3, __int64 a4)
{
  __int64 *v4; // x25
  unsigned __int16 v5; // w24
  unsigned int v7; // w21
  char v8; // w22
  __int64 v9; // x9
  __int64 v10; // x23
  __int64 v11; // x4
  __int64 v12; // x8
  int v13; // w27
  __int64 v14; // x19
  __int64 v15; // x20
  __int64 v16; // x1
  unsigned __int64 v17; // x9
  unsigned __int64 v19; // x8
  unsigned int v20; // w11
  unsigned __int64 v21; // x10
  unsigned int v22; // w9
  unsigned int v23; // w10
  __int16 v24; // w8
  __int16 v25; // w9
  unsigned __int16 v26; // w27
  __int64 v27; // x26
  __int64 v28; // x28
  __int64 v29; // x27
  __int64 v30; // x10
  __int64 v31; // x8
  __int64 v32; // x8
  __int64 v33; // x9
  __int64 v34; // x2
  __int64 v35; // x2

  if ( !gsi_ctx )
  {
    printk(&unk_2DEB9, "gsi_queue_xfer", 4319);
    return 4294967288LL;
  }
  v4 = a3;
  v5 = a2;
  v7 = (unsigned __int16)a2;
  if ( *(unsigned int *)(gsi_ctx + 28608) <= a1 || (v8 = a4, (_WORD)a2) && !a3 )
  {
    dev_err(
      *(_QWORD *)(gsi_ctx + 8),
      "%s:%d bad params chan_hdl=%lu num_xfers=%u xfer=%pK\n",
      "gsi_queue_xfer",
      4325,
      a1,
      (unsigned __int16)a2,
      a3);
    return 4294967290LL;
  }
  if ( a1 >= 0x24 )
  {
    __break(0x5512u);
    JUMPOUT(0x214E4);
  }
  v9 = gsi_ctx + 448 * a1;
  if ( !*(_DWORD *)(v9 + 304) )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d bad state %d\n", "gsi_queue_xfer", 4332);
    return 4294967289LL;
  }
  v10 = v9 + 184;
  v11 = *(unsigned int *)(v9 + 184);
  if ( (_DWORD)v11 != 2 && (_DWORD)v11 != 5 )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d op not supported for protocol %u\n", "gsi_queue_xfer", 4341);
    return 4294967289LL;
  }
  v12 = *(_QWORD *)(v9 + 392);
  v13 = (unsigned __int16)a2;
  if ( v12 )
    v14 = v12 + 136;
  else
    v14 = v9 + 312;
  v15 = raw_spin_lock_irqsave(v14, a2, a3, a4, v11);
  if ( !v13 )
  {
LABEL_50:
    if ( (v8 & 1) != 0 )
    {
      __dsb(0xEu);
      v32 = *(_QWORD *)(v10 + 208);
      if ( v32 && !*(_DWORD *)(v10 + 4) )
      {
        v33 = gsi_ctx;
        v34 = *(unsigned __int8 *)(v32 + 132);
        *(_QWORD *)(v32 + 160) = *(_QWORD *)(v32 + 176);
        gsihal_write_reg_nk(17, *(unsigned int *)(v33 + 20), v34);
      }
      v35 = *(unsigned __int8 *)(v10 + 8);
      *(_QWORD *)(v10 + 152) = *(_QWORD *)(v10 + 168);
      gsihal_write_reg_nk(18, *(unsigned int *)(gsi_ctx + 20), v35);
    }
    raw_spin_unlock_irqrestore(v14, v15);
    return 0;
  }
  if ( *(_DWORD *)v10 == 5 )
    goto LABEL_37;
  v16 = *(unsigned int *)(gsi_ctx + 20);
  if ( *(_DWORD *)v10 != 2 )
  {
    __break(0x800u);
    if ( *(_QWORD *)(v10 + 208) )
      goto LABEL_16;
LABEL_23:
    v17 = (unsigned int)gsihal_read_reg_nk(66, v16, *(unsigned __int8 *)(v10 + 8))
        | ((unsigned __int64)*(unsigned int *)(v10 + 164) << 32);
    *(_QWORD *)(v10 + 160) = v17;
    goto LABEL_24;
  }
  if ( !*(_QWORD *)(v10 + 208) )
    goto LABEL_23;
LABEL_16:
  v17 = *(_QWORD *)(v10 + 176);
LABEL_24:
  v19 = *(_QWORD *)(v10 + 144);
  if ( v19 > v17 || *(_QWORD *)(v10 + 192) <= v17 )
  {
    __break(0x800u);
    v19 = *(_QWORD *)(v10 + 144);
  }
  v20 = *(unsigned __int8 *)(v10 + 188);
  v21 = *(_QWORD *)(v10 + 168);
  v22 = ((int)v17 - (int)v19) / v20;
  if ( v19 > v21 || *(_QWORD *)(v10 + 192) <= v21 )
  {
    __break(0x800u);
    v19 = *(_QWORD *)(v10 + 144);
    v20 = *(unsigned __int8 *)(v10 + 188);
  }
  v23 = ((int)v21 - (int)v19) / v20;
  v24 = *(_WORD *)(v10 + 190);
  if ( (unsigned __int16)v23 >= (unsigned int)(unsigned __int16)v22 )
    v25 = v22 - v23;
  else
    v25 = v22 - v23 + ~v24;
  v26 = v25 + v24;
  if ( (unsigned __int16)(v25 + v24) < (unsigned int)v5 )
  {
    if ( (unsigned int)__ratelimit(&gsi_queue_xfer__rs, "gsi_queue_xfer") )
      dev_err(
        *(_QWORD *)(gsi_ctx + 8),
        "%s:%d chan_hdl=%lu num_xfers=%u free=%u\n",
        "gsi_queue_xfer",
        4364,
        a1,
        v7,
        v26);
    raw_spin_unlock_irqrestore(v14, v15);
    return 4294967294LL;
  }
LABEL_37:
  v27 = *(_QWORD *)(v10 + 168);
  v28 = 0;
  if ( v7 <= 1 )
    v29 = 1;
  else
    v29 = v7;
  while ( *(_DWORD *)v10 == 5 )
  {
    if ( (unsigned int)_gsi_populate_gci_tre(v10, v4) )
      goto LABEL_47;
LABEL_45:
    v30 = *(_QWORD *)(v10 + 192);
    v31 = *(_QWORD *)(v10 + 168) + *(unsigned __int8 *)(v10 + 188);
    *(_QWORD *)(v10 + 168) = v31;
    if ( v31 == v30 )
      *(_QWORD *)(v10 + 168) = *(_QWORD *)(v10 + 144);
    ++v28;
    v4 += 3;
    if ( v29 == v28 )
      goto LABEL_48;
  }
  if ( !(unsigned int)_gsi_populate_tre(v10, v4) )
    goto LABEL_45;
LABEL_47:
  LODWORD(v29) = v28;
LABEL_48:
  if ( (_DWORD)v29 == v7 )
  {
    *(_QWORD *)(v10 + 328) += v5;
    goto LABEL_50;
  }
  *(_QWORD *)(v10 + 168) = v27;
  raw_spin_unlock_irqrestore(v14, v15);
  return 4294967290LL;
}
