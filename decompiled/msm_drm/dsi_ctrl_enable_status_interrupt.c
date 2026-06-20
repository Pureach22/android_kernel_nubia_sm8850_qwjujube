int *__fastcall dsi_ctrl_enable_status_interrupt(int *result, unsigned int a2, __int64 *a3)
{
  int v4; // w7
  unsigned int *v5; // x19
  int *v6; // x24
  __int64 v8; // x0
  int v9; // w1
  __int64 v11; // x22
  unsigned int v12; // w8
  __int64 v13; // x9
  __int64 (__fastcall *v14)(_QWORD); // x8
  __int64 v15; // x8
  void (__fastcall *v16)(unsigned int *, __int64); // x8
  __int64 v17; // x1
  __int64 v18; // x10
  unsigned int *v19; // x8
  __int64 v20; // x11

  if ( !result )
    return result;
  if ( a2 > 0xA )
    return result;
  v4 = result[415];
  v5 = (unsigned int *)result;
  if ( v4 == -1 )
    return result;
  v6 = result + 417;
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dsi_ctrl_enable_status_interrupt",
    3172,
    -1,
    result[2],
    4369,
    a2,
    v4,
    result[416]);
  v8 = raw_spin_lock_irqsave(v5 + 414);
  v11 = v8;
  if ( !v6[a2] )
  {
    v12 = v5[416];
    if ( !v12 )
    {
      LODWORD(v8) = enable_irq(v5[415]);
      v12 = v5[416];
    }
    v13 = v5[402];
    v9 = v12 | (1LL << a2);
    v5[416] = v9;
    if ( (unsigned int)v13 > 2 )
      goto LABEL_22;
    v14 = *(__int64 (__fastcall **)(_QWORD))&v5[2 * v13 + 216];
    if ( v14 )
    {
      if ( *((_DWORD *)v14 - 1) != -200804075 )
        __break(0x8228u);
      LODWORD(v8) = v14(v5 + 24);
    }
  }
  if ( !a2 )
  {
    v15 = v5[402];
    if ( (unsigned int)v15 <= 2 )
    {
      v16 = *(void (__fastcall **)(unsigned int *, __int64))&v5[2 * v15 + 216];
      if ( v16 )
      {
        v17 = v5[416];
        if ( *((_DWORD *)v16 - 1) != -200804075 )
          __break(0x8228u);
        v16(v5 + 24, v17);
      }
      goto LABEL_18;
    }
LABEL_22:
    __break(0x5512u);
    __asm { LDTR            B0, [X13,#-0xF1] }
    return (int *)dsi_ctrl_disable_status_interrupt(v8, v9);
  }
LABEL_18:
  ++v6[a2];
  if ( a3 )
  {
    v18 = a3[1];
    v19 = &v5[6 * a2];
    v20 = *a3;
    *((_QWORD *)v19 + 216) = a3[2];
    *((_QWORD *)v19 + 215) = v18;
    *((_QWORD *)v19 + 214) = v20;
  }
  return (int *)raw_spin_unlock_irqrestore(v5 + 414, v11);
}
