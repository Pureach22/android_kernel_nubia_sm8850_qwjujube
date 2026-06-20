__int64 __fastcall dp_catalog_ctrl_channel_dealloc(__int64 a1, unsigned int a2, unsigned int a3, int a4)
{
  int v5; // w23
  __int64 v7; // x21
  __int64 v9; // x22
  __int64 v10; // x0
  unsigned __int64 StatusReg; // x28
  _DWORD *v12; // x9
  unsigned int v13; // w25
  unsigned int v14; // w0
  _DWORD *v15; // x8
  unsigned int v16; // w27
  __int64 v17; // x0
  unsigned int v18; // w26
  unsigned int v19; // w8
  __int64 v20; // x11
  bool v21; // cc
  __int64 v22; // x10
  int v23; // w11
  int v24; // w10
  __int64 v25; // x0
  _DWORD *v26; // x8
  _DWORD *v27; // x8
  __int64 v29; // x0
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
      return printk(&unk_24B551, "dp_catalog_ctrl_channel_dealloc");
    }
    else
    {
      v7 = *(_QWORD *)(a1 - 208);
      v9 = a1 - 232;
      v10 = get_ipc_log_context(a1);
      StatusReg = _ReadStatusReg(SP_EL0);
      ipc_log_string(
        v10,
        "[d][%-4d]dealloc ch %d, start_slot %d, tot_slot %d\n",
        *(_DWORD *)(StatusReg + 1800),
        a2,
        a3,
        v5);
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(
          0,
          0,
          0,
          "[msm-dp-debug][%-4d]dealloc ch %d, start_slot %d, tot_slot %d\n",
          *(_DWORD *)(StatusReg + 1800),
          a2,
          a3,
          v5);
      v12 = *(_DWORD **)(a1 - 112);
      v13 = (8 * (a2 == 1)) | 0x404;
      if ( *(v12 - 1) != -1879227436 )
        __break(0x8229u);
      v14 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v12)(v9, v7, v13);
      v15 = *(_DWORD **)(a1 - 112);
      v16 = v14;
      if ( *(v15 - 1) != -1879227436 )
        __break(0x8228u);
      v17 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v15)(v9, v7, 8 * (unsigned int)(a2 == 1) + 1032);
      v18 = v17;
      if ( v5 )
      {
        v19 = a3 - 1;
        do
        {
          v20 = 1LL << v19;
          v21 = v19 > 0x20;
          v22 = 1LL << ((unsigned __int8)v19++ - 33);
          v23 = v16 & ~(_DWORD)v20;
          v24 = v18 & ~(_DWORD)v22;
          if ( v21 )
            v18 = v24;
          else
            v16 = v23;
          --v5;
        }
        while ( v5 );
      }
      v25 = get_ipc_log_context(v17);
      ipc_log_string(
        v25,
        "[d][%-4d]dealloc ch:%d slot_reg_1:%d, slot_reg_2:%d\n",
        *(_DWORD *)(StatusReg + 1800),
        a2,
        v16,
        v18);
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(
          0,
          0,
          0,
          "[msm-dp-debug][%-4d]dealloc ch:%d slot_reg_1:%d, slot_reg_2:%d\n",
          *(_DWORD *)(StatusReg + 1800),
          a2,
          v16,
          v18);
      v26 = *(_DWORD **)(a1 - 104);
      if ( *(v26 - 1) != -626862723 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v26)(v9, v7, v13, v16);
      v27 = *(_DWORD **)(a1 - 104);
      if ( *(v27 - 1) != -626862723 )
        __break(0x8228u);
      return ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v27)(
               v9,
               v7,
               8 * (unsigned int)(a2 == 1) + 1032,
               v18);
    }
  }
  else
  {
    v29 = get_ipc_log_context(a1);
    ipc_log_string(v29, "[e][%-4d]invalid input. ch %d\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), a2);
    return printk(&unk_22627D, "dp_catalog_ctrl_channel_dealloc");
  }
}
