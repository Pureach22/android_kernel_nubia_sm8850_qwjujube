int *__fastcall dsi_ctrl_disable_status_interrupt(int *result, unsigned int a2)
{
  int *v3; // x22
  unsigned int *v4; // x19
  __int64 v5; // x0
  int v6; // w9
  __int64 v7; // x20
  int v8; // w9
  __int64 v9; // x8
  unsigned int v10; // w1
  void (__fastcall *v11)(_QWORD); // x8

  if ( result && a2 <= 0xA )
  {
    v3 = result + 417;
    v4 = (unsigned int *)result;
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "dsi_ctrl_disable_status_interrupt",
      3210,
      2,
      result[2],
      4369,
      a2,
      result[415],
      result[416]);
    v5 = raw_spin_lock_irqsave(v4 + 414);
    v6 = v3[a2];
    v7 = v5;
    if ( v6 )
    {
      v8 = v6 - 1;
      v3[a2] = v8;
      if ( !v8 )
      {
        v9 = v4[402];
        v10 = v4[416] & ~(unsigned int)(1LL << a2);
        v4[416] = v10;
        if ( (unsigned int)v9 > 2 )
        {
          __break(0x5512u);
          JUMPOUT(0x1D286C);
        }
        v11 = *(void (__fastcall **)(_QWORD))&v4[2 * v9 + 216];
        if ( v11 )
        {
          if ( *((_DWORD *)v11 - 1) != -200804075 )
            __break(0x8228u);
          v11(v4 + 24);
          v10 = v4[416];
        }
        if ( !v10 && v4[415] != -1 )
          disable_irq_nosync();
      }
    }
    return (int *)raw_spin_unlock_irqrestore(v4 + 414, v7);
  }
  return result;
}
