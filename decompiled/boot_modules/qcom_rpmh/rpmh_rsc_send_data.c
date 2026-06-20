__int64 __fastcall rpmh_rsc_send_data(__int64 a1, unsigned int *a2, unsigned int a3)
{
  _DWORD *v3; // x19
  __int64 v4; // x20
  _DWORD *v5; // x21
  unsigned int v6; // w22
  __int64 v7; // x24
  __int64 v8; // x25
  __int64 v9; // x26
  __int64 v10; // x8
  __int64 v12; // x0
  unsigned int v13; // w0
  unsigned int v14; // w8
  int *v15; // x10
  int v16; // w9
  __int64 v17; // x23
  int v18; // w27
  int v19; // w28
  int v20; // w8
  int *v21; // x10
  int v22; // w9
  __int64 v23; // x23
  int v24; // w8
  __int64 v25; // x21
  __int64 v26; // x0
  unsigned __int64 v33; // x9
  unsigned __int64 v36; // x9
  _QWORD v37[6]; // [xsp+0h] [xbp-30h] BYREF

  v37[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *a2;
  if ( (unsigned int)v10 > 2 )
  {
    LODWORD(v5) = -22;
    goto LABEL_10;
  }
  if ( a3 >= 2 )
    goto LABEL_43;
  v3 = a2;
  v4 = a1;
  v5 = (_DWORD *)(a1 + 336LL * a3 + 440 + (v10 << 6));
  if ( (_DWORD)v10 == 2 && !v5[5] )
    v5 = (_DWORD *)(a1 + 336LL * a3 + 504);
  if ( (unsigned __int64)v5 >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_10;
  raw_spin_lock_irq(a1 + 1120);
  if ( *(_BYTE *)(v4 + 60) == 1 )
  {
    raw_spin_unlock_irq(v4 + 1120);
    LODWORD(v5) = -16;
    goto LABEL_10;
  }
  v6 = claim_tcs_for_req(v4, v5, v3);
  if ( (v6 & 0x80000000) != 0 )
  {
    memset(v37, 0, 40);
    init_wait_entry(v37, 0);
    prepare_to_wait_event(v4 + 1128, v37, 2);
    v6 = claim_tcs_for_req(v4, v5, v3);
    if ( (v6 & 0x80000000) != 0 )
    {
      do
      {
        v12 = raw_spin_unlock_irq(v4 + 1120);
        schedule(v12);
        raw_spin_lock_irq(v4 + 1120);
        prepare_to_wait_event(v4 + 1128, v37, 2);
        v13 = claim_tcs_for_req(v4, v5, v3);
      }
      while ( (v13 & 0x80000000) != 0 );
      v6 = v13;
    }
    finish_wait(v4 + 1128, v37);
  }
  v14 = v6 - v5[4];
  if ( v14 >= 3 )
  {
LABEL_43:
    __break(0x5512u);
  }
  else
  {
    v8 = v6 >> 6;
    v7 = 1LL << v6;
    v9 = v4 + 1112;
    *(_QWORD *)&v5[2 * v14 + 8] = v3;
  }
  _X8 = (unsigned __int64 *)(v9 + 8 * v8);
  __asm { PRFM            #0x11, [X8] }
  do
    v33 = __ldxr(_X8);
  while ( __stxr(v33 | v7, _X8) );
  v15 = *(int **)(v4 + 1664);
  v16 = *(_DWORD *)(v4 + 40);
  v17 = v15[10];
  if ( !v16 )
    v16 = *v15;
  v18 = 1000000;
  writel(0, *(_QWORD *)(v4 + 32) + v17 + v16 * v6);
  v19 = 1000000;
  while ( 1 )
  {
    v20 = *(_DWORD *)(v4 + 40);
    if ( !v20 )
      v20 = **(_DWORD **)(v4 + 1664);
    if ( !(unsigned int)readl(*(_QWORD *)(v4 + 32) + v17 + v20 * v6) )
      break;
    _const_udelay(4295);
    if ( !--v19 )
    {
      printk(&unk_D944, "qcom_rpmh", v4, 0, v6, (unsigned int)v17);
      break;
    }
  }
  v21 = *(int **)(v4 + 1664);
  v22 = *(_DWORD *)(v4 + 40);
  v23 = v21[7];
  if ( !v22 )
    v22 = *v21;
  writel(0, *(_QWORD *)(v4 + 32) + v23 + v22 * v6);
  while ( 1 )
  {
    v24 = *(_DWORD *)(v4 + 40);
    if ( !v24 )
      v24 = **(_DWORD **)(v4 + 1664);
    if ( !(unsigned int)readl(*(_QWORD *)(v4 + 32) + v23 + v24 * v6) )
      break;
    _const_udelay(4295);
    if ( !--v18 )
    {
      printk(&unk_D944, "qcom_rpmh", v4, 0, v6, (unsigned int)v23);
      break;
    }
  }
  if ( v3[1] || *v3 == 2 && v5[2] != 2 )
  {
    v25 = *(unsigned int *)(*(_QWORD *)(v4 + 1664) + 16LL);
    v26 = (unsigned int)readl_relaxed((unsigned int *)(*(_QWORD *)(v4 + 32) + v25)) | (unsigned int)(1LL << v6);
  }
  else
  {
    v25 = *(unsigned int *)(*(_QWORD *)(v4 + 1664) + 16LL);
    v26 = (unsigned int)readl_relaxed((unsigned int *)(*(_QWORD *)(v4 + 32) + v25)) & ~(unsigned int)(1LL << v6);
  }
  writel_relaxed(v26, *(_QWORD *)(v4 + 32) + v25);
  _tcs_buffer_write(v4, v6, 0, v3);
  _tcs_set_trigger(v4, v6, 1);
  ipc_log_string(*(_QWORD *)(v4 + 1672), "TCS trigger: m=%d wait_for_compl=%u", v6, v3[1]);
  if ( !v3[1] )
  {
    _X8 = (unsigned __int64 *)(v9 + 8 * v8);
    __asm { PRFM            #0x11, [X8] }
    do
      v36 = __ldxr(_X8);
    while ( __stxr(v36 & ~v7, _X8) );
  }
  raw_spin_unlock_irq(v4 + 1120);
  if ( !v3[1] )
    _wake_up(v4 + 1128, 3, 1, 0);
  LODWORD(v5) = 0;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v5;
}
