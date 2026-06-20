__int64 __fastcall tcs_tx_done(__int64 a1, __int64 a2)
{
  unsigned int v3; // w0
  char v4; // w8
  __int64 v5; // x22
  __int64 v6; // x21
  unsigned __int64 v7; // x27
  unsigned __int64 v8; // x8
  unsigned __int64 v9; // x23
  __int64 v10; // x24
  __int64 v11; // x8
  __int64 v12; // x8
  __int64 v13; // x8
  unsigned int v14; // w9
  __int64 v15; // x25
  char v16; // w26
  int v17; // w8
  int *v18; // x9
  __int64 v19; // x26
  int v20; // w0
  int v21; // w8
  int v22; // w27
  unsigned int v23; // w28
  int v24; // w20
  int v25; // w9
  int v26; // w9
  unsigned int v27; // w27
  int v28; // w20
  int v29; // w9
  int *v30; // x11
  int v31; // w10
  int *v32; // x11
  int v33; // w10
  __int64 v34; // x20
  int v35; // w0
  unsigned __int64 v42; // x9
  unsigned __int64 v44; // [xsp+10h] [xbp-10h]

  v3 = readl_relaxed((unsigned int *)(*(_QWORD *)(a2 + 32) + *(unsigned int *)(*(_QWORD *)(a2 + 1664) + 20LL)));
  v4 = 0;
  v5 = 0;
  v6 = a2 + 440;
  v7 = v3;
  _ReadStatusReg(SP_EL0);
  v44 = v3;
  while ( 1 )
  {
    v8 = (-1LL << v4) & v7;
    if ( !v8 )
      return 1;
    v9 = __clz(__rbit64(v8));
    v10 = 1LL << v9;
    if ( (*(_BYTE *)(a2 + 768) & 1) == 0 )
      goto LABEL_53;
    v11 = 128;
    if ( !*(_DWORD *)(a2 + 588) )
      v11 = 64;
    v12 = v6 + v11;
    if ( ((unsigned int)v10 & *(_DWORD *)(v12 + 12)) != 0 )
    {
      v5 = 0;
    }
    else
    {
LABEL_53:
      if ( *(_BYTE *)(a2 + 1104) != 1 )
        goto LABEL_18;
      v13 = 128;
      if ( !*(_DWORD *)(a2 + 924) )
        v13 = 64;
      v12 = a2 + 776 + v13;
      if ( ((unsigned int)v10 & *(_DWORD *)(v12 + 12)) == 0 )
        goto LABEL_18;
      v5 = 1;
    }
    v14 = v9 - *(_DWORD *)(v12 + 16);
    if ( v14 >= 3 )
      break;
    v15 = *(_QWORD *)(v12 + 8LL * v14 + 32);
    if ( v15 )
    {
      ipc_log_string(*(_QWORD *)(a2 + 1672), "IRQ response: m=%d", v9);
      if ( *(_DWORD *)(v6 + 336LL * (unsigned int)v5 + 148) )
      {
        v16 = 0;
      }
      else
      {
        v17 = *(_DWORD *)(a2 + 40);
        v18 = *(int **)(a2 + 1664);
        if ( !v17 )
          v17 = *v18;
        v19 = v18[8];
        v20 = readl_relaxed((unsigned int *)(*(_QWORD *)(a2 + 32) + v19 + (unsigned int)(v17 * v9)));
        v21 = *(_DWORD *)(a2 + 40);
        v22 = v20;
        if ( !v21 )
          v21 = **(_DWORD **)(a2 + 1664);
        v23 = v20 & 0xFEFFFFFF;
        writel(v20 & 0xFEFFFFFF, (unsigned int *)(*(_QWORD *)(a2 + 32) + v19 + (unsigned int)(v21 * v9)));
        v24 = 1000000;
        while ( 1 )
        {
          v25 = *(_DWORD *)(a2 + 40);
          if ( !v25 )
            v25 = **(_DWORD **)(a2 + 1664);
          if ( (unsigned int)readl((unsigned int *)(*(_QWORD *)(a2 + 32) + v19 + (unsigned int)(v25 * v9))) == v23 )
            break;
          _const_udelay(4295);
          if ( !--v24 )
          {
            printk(&unk_D944, "qcom_rpmh", a2, v23, (unsigned int)v9, (unsigned int)v19);
            break;
          }
        }
        v26 = *(_DWORD *)(a2 + 40);
        if ( !v26 )
          v26 = **(_DWORD **)(a2 + 1664);
        v27 = v22 & 0xFEFEFFFF;
        writel(v27, (unsigned int *)(*(_QWORD *)(a2 + 32) + v19 + (unsigned int)(v26 * v9)));
        v28 = 1000000;
        while ( 1 )
        {
          v29 = *(_DWORD *)(a2 + 40);
          if ( !v29 )
            v29 = **(_DWORD **)(a2 + 1664);
          if ( (unsigned int)readl((unsigned int *)(*(_QWORD *)(a2 + 32) + v19 + (unsigned int)(v29 * v9))) == v27 )
            break;
          _const_udelay(4295);
          if ( !--v28 )
          {
            printk(&unk_D944, "qcom_rpmh", a2, v27, (unsigned int)v9, (unsigned int)v19);
            break;
          }
        }
        v7 = v44;
        v16 = 0;
      }
      goto LABEL_38;
    }
LABEL_18:
    v15 = 0;
    __break(0x800u);
    v16 = 1;
LABEL_38:
    v30 = *(int **)(a2 + 1664);
    v31 = *(_DWORD *)(a2 + 40);
    if ( !v31 )
      v31 = *v30;
    writel_relaxed(0, (unsigned int *)(*(_QWORD *)(a2 + 32) + v30[10] + (unsigned int)(v31 * v9)));
    v32 = *(int **)(a2 + 1664);
    v33 = *(_DWORD *)(a2 + 40);
    if ( !v33 )
      v33 = *v32;
    writel_relaxed(0, (unsigned int *)(*(_QWORD *)(a2 + 32) + v32[7] + (unsigned int)(v33 * v9)));
    writel_relaxed(v10, (unsigned int *)(*(_QWORD *)(a2 + 32) + *(unsigned int *)(*(_QWORD *)(a2 + 1664) + 24LL)));
    raw_spin_lock(a2 + 1120);
    _X8 = (unsigned __int64 *)(a2 + 1112);
    __asm { PRFM            #0x11, [X8] }
    do
      v42 = __ldxr(_X8);
    while ( __stxr(v42 & ~v10, _X8) );
    if ( !*(_DWORD *)(v6 + 336 * v5 + 148) )
    {
      v34 = *(unsigned int *)(*(_QWORD *)(a2 + 1664) + 16LL);
      v35 = readl_relaxed((unsigned int *)(*(_QWORD *)(a2 + 32) + v34));
      writel_relaxed(v35 & ~(_DWORD)v10, (unsigned int *)(*(_QWORD *)(a2 + 32) + v34));
    }
    raw_spin_unlock(a2 + 1120);
    _wake_up(a2 + 1128, 3, 1, 0);
    if ( (v16 & 1) == 0 )
      rpmh_tx_done(v15);
    v4 = v9 + 1;
    if ( v9 >= 0x1F )
      return 1;
  }
  __break(0x5512u);
  _WriteStatusReg(ARM64_SYSREG(3, 2, 7, 10, 1), v7);
  return rpmh_rsc_pd_callback();
}
