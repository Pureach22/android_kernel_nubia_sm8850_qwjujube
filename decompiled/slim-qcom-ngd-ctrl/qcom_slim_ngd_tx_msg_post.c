__int64 __fastcall qcom_slim_ngd_tx_msg_post(__int64 a1, __int64 a2, char a3)
{
  __int64 v6; // x0
  __int64 v7; // x8
  int v8; // w9
  unsigned int v9; // w10
  _QWORD *v10; // x10
  __int64 v11; // x20
  unsigned int v12; // w21
  __int64 *v13; // x27
  __int64 v14; // x23
  __int64 v15; // x28
  int v16; // w8
  __int64 v17; // x22
  __int64 v18; // x1
  int v19; // w8
  __int64 v20; // x23
  _DWORD *v21; // x8
  __int64 v22; // x0
  __int64 (*v23)(void); // x8
  void (*v24)(void); // x8
  unsigned int v25; // w21
  _QWORD v27[2]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v28; // [xsp+18h] [xbp-18h]
  __int64 v29; // [xsp+20h] [xbp-10h]
  __int64 v30; // [xsp+28h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = raw_spin_lock_irqsave(a1 + 5144);
  v7 = *(_QWORD *)(a1 + 5416);
  v8 = a2 - v7;
  v9 = ((int)a2 - (int)v7) / 40;
  if ( v9 >= 0x1F )
    __break(0x5512u);
  v10 = (_QWORD *)(a1 + 48LL * v9);
  v11 = v6;
  v12 = (a3 + 3) & 0xFC;
  v13 = v10 + 430;
  v10[434] = *(_QWORD *)(a1 + 5400) + v8;
  v10[435] = v7 + v8;
  v10[431] = a1;
  if ( v12 )
  {
    v14 = 0;
    if ( v12 >> 2 <= 1 )
      v15 = 1;
    else
      v15 = v12 >> 2;
    do
    {
      _slimbus_dbg();
      v16 = *(_DWORD *)(a1 + 5476);
      if ( v16 >= 3 )
      {
        ipc_log_string(*(_QWORD *)(a1 + 5488), "BAM TX len = %d buf[%d]:0x%x\n", v12, v14, *(_DWORD *)(a2 + 4 * v14));
        v16 = *(_DWORD *)(a1 + 5476);
      }
      if ( !v16 )
        ipc_log_string(*(_QWORD *)(a1 + 5496), "BAM TX len = %d buf[%d]:0x%x\n", v12, v14, *(_DWORD *)(a2 + 4 * v14));
      ++v14;
    }
    while ( v15 != v14 );
  }
  v17 = *(_QWORD *)(a1 + 1992);
  if ( !v17 )
  {
    _slimbus_dbg();
    v19 = *(_DWORD *)(a1 + 5476);
    if ( v19 >= 2 )
    {
      printk(&unk_D296, v18);
      ipc_log_string(*(_QWORD *)(a1 + 5488), " tx channel not available\n");
      if ( *(_DWORD *)(a1 + 5476) )
        goto LABEL_15;
    }
    else if ( v19 )
    {
LABEL_15:
      v17 = *(_QWORD *)(a1 + 1992);
      goto LABEL_16;
    }
    ipc_log_string(*(_QWORD *)(a1 + 5496), " tx channel not available\n");
    goto LABEL_15;
  }
LABEL_16:
  v20 = v13[4];
  v28 = 0;
  v29 = 0;
  v27[0] = 0;
  v27[1] = 0;
  sg_init_table(v27, 1);
  v28 = v20;
  LODWORD(v29) = v12;
  if ( !v17 || !*(_QWORD *)v17 || (v21 = *(_DWORD **)(*(_QWORD *)v17 + 272LL)) == nullptr )
  {
    *v13 = 0;
LABEL_28:
    dev_err(*(_QWORD *)(a1 + 1968), "unable to prepare channel\n");
    v25 = -22;
    goto LABEL_29;
  }
  if ( *(v21 - 1) != -1221891457 )
    __break(0x8228u);
  v22 = ((__int64 (__fastcall *)(__int64, _QWORD *, __int64, __int64, __int64, _QWORD))v21)(v17, v27, 1, 1, 1, 0);
  *v13 = v22;
  if ( !v22 )
    goto LABEL_28;
  *(_QWORD *)(v22 + 40) = qcom_slim_ngd_tx_msg_dma_cb;
  *(_QWORD *)(*v13 + 56) = v13;
  v23 = *(__int64 (**)(void))(*v13 + 24);
  if ( *((_DWORD *)v23 - 1) != 1188179853 )
    __break(0x8228u);
  *(_DWORD *)*v13 = v23();
  v24 = *(void (**)(void))(**(_QWORD **)(a1 + 1992) + 360LL);
  if ( *((_DWORD *)v24 - 1) != 905352215 )
    __break(0x8228u);
  v24();
  v25 = 0;
LABEL_29:
  raw_spin_unlock_irqrestore(a1 + 5144, v11);
  _ReadStatusReg(SP_EL0);
  return v25;
}
