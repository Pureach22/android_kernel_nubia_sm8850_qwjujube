__int64 __fastcall dp_catalog_ctrl_channel_alloc(__int64 a1, unsigned int a2, unsigned int a3, int a4)
{
  int v5; // w22
  __int64 v7; // x21
  __int64 v9; // x0
  unsigned __int64 StatusReg; // x27
  __int64 v11; // x0
  unsigned int v12; // w23
  unsigned int v13; // w26
  unsigned int v14; // w9
  __int64 v15; // x12
  bool v16; // cc
  __int64 v17; // x11
  unsigned int v18; // w12
  unsigned int v19; // w11
  int v20; // w22
  __int64 v21; // x0
  _DWORD *v22; // x8
  _DWORD *v23; // x8
  __int64 v25; // x0
  __int64 ipc_log_context; // x0

  if ( a1 && a2 < 2 )
  {
    v5 = a4;
    if ( a3 > 0x40 || a4 + a3 >= 0x41 )
    {
      ipc_log_context = get_ipc_log_context(a1);
      ipc_log_string(
        ipc_log_context,
        "[e][%-4d]invalid slots start %d, tot %d\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        a3,
        v5);
      return printk(&unk_24B551, "dp_catalog_ctrl_channel_alloc");
    }
    else
    {
      v7 = *(_QWORD *)(a1 - 208);
      v9 = get_ipc_log_context(a1);
      StatusReg = _ReadStatusReg(SP_EL0);
      v11 = ipc_log_string(
              v9,
              "[d][%-4d]ch %d, start_slot %d, tot_slot %d\n",
              *(_DWORD *)(StatusReg + 1800),
              a2,
              a3,
              v5);
      if ( (_drm_debug & 4) != 0 )
        v11 = _drm_dev_dbg(
                0,
                0,
                0,
                "[msm-dp-debug][%-4d]ch %d, start_slot %d, tot_slot %d\n",
                *(_DWORD *)(StatusReg + 1800),
                a2,
                a3,
                v5);
      v12 = 0;
      v13 = 0;
      if ( a3 && v5 )
      {
        v13 = 0;
        v12 = 0;
        v14 = a3 - 1;
        do
        {
          v15 = 1LL << v14;
          v16 = v14 > 0x1F;
          v17 = 1LL << ((unsigned __int8)v14++ - 32);
          v18 = v13 | v15;
          v19 = v12 | v17;
          if ( v16 )
            v12 = v19;
          else
            v13 = v18;
          --v5;
        }
        while ( v5 );
      }
      v20 = 8 * (a2 == 1);
      v21 = get_ipc_log_context(v11);
      ipc_log_string(v21, "[d][%-4d]ch:%d slot_reg_1:%d, slot_reg_2:%d\n", *(_DWORD *)(StatusReg + 1800), a2, v13, v12);
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(
          0,
          0,
          0,
          "[msm-dp-debug][%-4d]ch:%d slot_reg_1:%d, slot_reg_2:%d\n",
          *(_DWORD *)(StatusReg + 1800),
          a2,
          v13,
          v12);
      v22 = *(_DWORD **)(a1 - 104);
      if ( *(v22 - 1) != -626862723 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v22)(a1 - 232, v7, v20 | 0x404u, v13);
      v23 = *(_DWORD **)(a1 - 104);
      if ( *(v23 - 1) != -626862723 )
        __break(0x8228u);
      return ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v23)(
               a1 - 232,
               v7,
               (unsigned int)(v20 + 1032),
               v12);
    }
  }
  else
  {
    v25 = get_ipc_log_context(a1);
    ipc_log_string(v25, "[e][%-4d]invalid input. ch %d\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), a2);
    return printk(&unk_22627D, "dp_catalog_ctrl_channel_alloc");
  }
}
