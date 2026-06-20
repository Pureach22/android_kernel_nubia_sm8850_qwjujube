__int64 __fastcall hfi_ipc_core_cb(__int64 a1, unsigned int a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x8
  _DWORD *v7; // x9
  _DWORD *v8; // x9
  __int64 v9; // x0
  __int64 v10; // x1
  unsigned int v12; // w21
  unsigned int v13; // w22
  __int64 v14; // x23

  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( a2 > 3 )
    {
LABEL_23:
      printk(&unk_1C4D8, "hfi_ipc_core_cb", 30, v5, a2);
      return 4294967274LL;
    }
  }
  else
  {
    v12 = a2;
    v13 = a3;
    v14 = v5;
    printk(&unk_1E83A, "hfi_ipc_core_cb", 25, a4, a5);
    v5 = v14;
    a3 = v13;
    a2 = v12;
    if ( v12 > 3 )
      goto LABEL_23;
  }
  if ( !drv_data )
    goto LABEL_23;
  if ( (_DWORD)a3 == 2 )
  {
    power_notification(a2, drv_data, a3, a4, a5);
  }
  else if ( (_DWORD)a3 == 1 )
  {
    v6 = drv_data + 176LL * a2 + 16;
    if ( a2 != 3
      && (hfi_core_loop_back_mode_enable == 1 && (v7 = *(_DWORD **)(drv_data + 176LL * a2 + 168)) != nullptr && !*v7
       || (v7 = *(_DWORD **)(drv_data + 176LL * a2 + 176)) != nullptr && !*v7) )
    {
      *v7 = 1;
      _wake_up(*(_QWORD *)(v6 + 168), 3, 0, 0);
    }
    else if ( drv_data + 176LL * a2 != -16 )
    {
      v8 = *(_DWORD **)(drv_data + 176LL * a2 + 40);
      if ( v8 )
      {
        v9 = *(_QWORD *)(drv_data + 176LL * a2 + 32);
        v10 = *(_QWORD *)(drv_data + 176LL * a2 + 48);
        if ( *(v8 - 1) != -95297426 )
          __break(0x8229u);
        ((void (__fastcall *)(__int64, __int64, _QWORD))v8)(v9, v10, 0);
      }
    }
  }
  else
  {
    printk(&unk_1B05A, "hfi_ipc_core_cb", 67, v5, (unsigned int)a3);
  }
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    printk(&unk_1C28B, "hfi_ipc_core_cb", 71, a4, a5);
  return 0;
}
