__int64 __fastcall gpi_reset_chan(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  __int64 v9; // x20
  _QWORD *v10; // x23
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x1
  __int64 v14; // x6
  unsigned int v15; // w21
  __int64 v16; // x8
  __int64 v17; // x1
  __int64 v18; // x2
  __int64 v19; // x3
  __int64 v20; // x4
  __int64 v21; // x5
  __int64 v22; // x6
  __int64 v23; // x1
  __int64 v24; // x9
  __int64 *v25; // x10
  __int64 *v26; // x11
  __int64 v27; // x9
  __int64 *v28; // x10
  __int64 *v29; // x11
  __int64 v30; // x9
  __int64 *v31; // x10
  __int64 *v32; // x11
  __int64 v33; // x9
  __int64 *v34; // x10
  __int64 *v35; // x11
  __int64 v36; // x9
  __int64 *v37; // x10
  __int64 *v38; // x11
  __int64 v40; // [xsp+8h] [xbp-18h] BYREF
  __int64 *v41; // [xsp+10h] [xbp-10h]
  __int64 v42; // [xsp+18h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 280);
  v10 = *(_QWORD **)(a1 + 352);
  v40 = (__int64)&v40;
  v41 = &v40;
  if ( *(_DWORD *)(v9 + 1068) >= 3u )
  {
    printk(&unk_123DE, v9 + 1076, *(unsigned int *)(a1 + 256), "gpi_reset_chan", a5, a6, a7);
    v11 = *(_QWORD *)(v9 + 1056);
    if ( !v11 )
      goto LABEL_5;
  }
  else
  {
    v11 = *(_QWORD *)(v9 + 1056);
    if ( !v11 )
      goto LABEL_5;
  }
  if ( *(_DWORD *)(v9 + 1064) >= 3u )
    ipc_log_string(v11, "ch:%u %s: Enter\n", *(_DWORD *)(a1 + 256), "gpi_reset_chan");
LABEL_5:
  v12 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))gpi_send_cmd)(v9, a1, a2);
  v15 = v12;
  if ( !(_DWORD)v12 )
  {
    v16 = v10[4];
    v10[5] = v16;
    v10[6] = v16;
    __dmb(0xAu);
    raw_write_lock_irq(v9 + 948);
    gpi_mark_stale_events(a1, v17, v18, v19, v20, v21, v22);
    v23 = raw_spin_lock_irqsave(a1 + 160);
    v24 = *(_QWORD *)(a1 + 168);
    if ( v24 != a1 + 168 )
    {
      v25 = v41;
      v26 = *(__int64 **)(a1 + 176);
      *(_QWORD *)(v24 + 8) = v41;
      *v25 = v24;
      *v26 = (__int64)&v40;
      v41 = v26;
      *(_QWORD *)(a1 + 168) = a1 + 168;
      *(_QWORD *)(a1 + 176) = a1 + 168;
    }
    v27 = *(_QWORD *)(a1 + 184);
    if ( v27 != a1 + 184 )
    {
      v28 = v41;
      v29 = *(__int64 **)(a1 + 192);
      *(_QWORD *)(v27 + 8) = v41;
      *v28 = v27;
      *v29 = (__int64)&v40;
      v41 = v29;
      *(_QWORD *)(a1 + 184) = a1 + 184;
      *(_QWORD *)(a1 + 192) = a1 + 184;
    }
    v30 = *(_QWORD *)(a1 + 200);
    if ( v30 != a1 + 200 )
    {
      v31 = v41;
      v32 = *(__int64 **)(a1 + 208);
      *(_QWORD *)(v30 + 8) = v41;
      *v31 = v30;
      *v32 = (__int64)&v40;
      v41 = v32;
      *(_QWORD *)(a1 + 200) = a1 + 200;
      *(_QWORD *)(a1 + 208) = a1 + 200;
    }
    v33 = *(_QWORD *)(a1 + 216);
    if ( v33 != a1 + 216 )
    {
      v34 = v41;
      v35 = *(__int64 **)(a1 + 224);
      *(_QWORD *)(v33 + 8) = v41;
      *v34 = v33;
      *v35 = (__int64)&v40;
      v41 = v35;
      *(_QWORD *)(a1 + 216) = a1 + 216;
      *(_QWORD *)(a1 + 224) = a1 + 216;
    }
    v36 = *(_QWORD *)(a1 + 232);
    if ( v36 != a1 + 232 )
    {
      v37 = v41;
      v38 = *(__int64 **)(a1 + 240);
      *(_QWORD *)(v36 + 8) = v41;
      *v37 = v36;
      *v38 = (__int64)&v40;
      v41 = v38;
      *(_QWORD *)(a1 + 232) = a1 + 232;
      *(_QWORD *)(a1 + 240) = a1 + 232;
    }
    raw_spin_unlock_irqrestore(a1 + 160, v23);
    raw_write_unlock_irq(v9 + 948);
    vchan_dma_desc_free_list(a1, &v40);
    goto LABEL_22;
  }
  if ( *(_DWORD *)(v9 + 1068) >= 2u )
  {
    if ( a2 > 0xC )
      goto LABEL_28;
    printk(
      &unk_147A5,
      v9 + 1076,
      *(unsigned int *)(a1 + 256),
      "gpi_reset_chan",
      gpi_cmd_str[a2],
      (unsigned int)v12,
      v14);
    v12 = *(_QWORD *)(v9 + 1056);
    if ( !v12 )
      goto LABEL_22;
  }
  else
  {
    v12 = *(_QWORD *)(v9 + 1056);
    if ( !v12 )
    {
LABEL_22:
      _ReadStatusReg(SP_EL0);
      return v15;
    }
  }
  if ( *(_DWORD *)(v9 + 1064) < 2u )
    goto LABEL_22;
  if ( a2 <= 0xC )
  {
    ipc_log_string(
      v12,
      "ch:%u %s: Error with cmd:%s ret:%d\n",
      *(_DWORD *)(a1 + 256),
      "gpi_reset_chan",
      gpi_cmd_str[a2],
      v15);
    goto LABEL_22;
  }
LABEL_28:
  __break(1u);
  return gpi_alloc_chan(v12, v13);
}
