__int64 __fastcall syna_dev_set_up_input_device(__int64 a1)
{
  __int64 v1; // x2
  __int64 v3; // x8
  int v4; // w9
  __int64 v5; // x2
  __int64 v6; // x0
  unsigned int *v7; // x21
  __int64 v8; // x2
  __int64 device; // x0
  __int64 v10; // x2
  __int64 v11; // x20
  __int64 v12; // x8
  unsigned int v13; // w0
  __int64 v14; // x2
  unsigned int *v15; // x0
  __int64 v16; // x2
  __int64 v18; // x2
  unsigned int v19; // w21
  unsigned __int64 v26; // x9
  unsigned __int64 v29; // x9
  unsigned __int64 v32; // x9
  unsigned __int64 v35; // x9
  unsigned __int64 v38; // x9
  unsigned __int64 v41; // x9
  unsigned __int64 v44; // x9

  v1 = *(unsigned __int8 *)(*(_QWORD *)a1 + 9LL);
  if ( (_DWORD)v1 != 1 )
  {
    printk(&unk_32EDC, "syna_dev_set_up_input_device", v1);
    return 0;
  }
  syna_dev_free_input_events(a1);
  v3 = *(_QWORD *)a1;
  v4 = *(_DWORD *)(*(_QWORD *)a1 + 16LL);
  if ( !v4 && !*(_DWORD *)(v3 + 20) )
    return 0;
  if ( *(_DWORD *)(a1 + 952) == v4 && *(_DWORD *)(a1 + 956) == *(_DWORD *)(v3 + 20) )
  {
    v5 = *(unsigned int *)(a1 + 960);
    if ( (_DWORD)v5 == *(_DWORD *)(v3 + 24) )
    {
      if ( (unsigned int)v5 < 0xB )
        printk(&unk_3CB57, "syna_dev_check_input_params", v5);
      else
        printk(&unk_3BE7D, "syna_dev_check_input_params", v5);
      return 0;
    }
  }
  mutex_lock(a1 + 632);
  v6 = *(_QWORD *)(a1 + 944);
  if ( v6 )
  {
    v6 = input_unregister_device();
    *(_QWORD *)(a1 + 944) = 0;
  }
  v7 = *(unsigned int **)a1;
  if ( syna_request_managed_device(v6) )
  {
    device = devm_input_allocate_device();
    if ( device )
    {
      v11 = device;
      *(_QWORD *)device = "synaptics_tcm_touch";
      *(_QWORD *)(device + 8) = "synaptics_tcm/touch_input";
      *(_DWORD *)(device + 28) = 65537;
      v12 = *(_QWORD *)(*(_QWORD *)(a1 + 8) + 112LL);
      *(_QWORD *)(device + 712) = a1;
      *(_QWORD *)(device + 656) = v12;
      _X8 = (unsigned __int64 *)(device + 40);
      __asm { PRFM            #0x11, [X8] }
      do
        v26 = __ldxr(_X8);
      while ( __stxr(v26 | 1, _X8) );
      _X8 = (unsigned __int64 *)(device + 40);
      __asm { PRFM            #0x11, [X8] }
      do
        v29 = __ldxr(_X8);
      while ( __stxr(v29 | 2, _X8) );
      _X8 = (unsigned __int64 *)(device + 40);
      __asm { PRFM            #0x11, [X8] }
      do
        v32 = __ldxr(_X8);
      while ( __stxr(v32 | 8, _X8) );
      _X8 = (unsigned __int64 *)(device + 88);
      __asm { PRFM            #0x11, [X8] }
      do
        v35 = __ldxr(_X8);
      while ( __stxr(v35 | 0x400, _X8) );
      _X8 = (unsigned __int64 *)(device + 88);
      __asm { PRFM            #0x11, [X8] }
      do
        v38 = __ldxr(_X8);
      while ( __stxr(v38 | 0x20, _X8) );
      _X8 = (unsigned __int64 *)(device + 32);
      __asm { PRFM            #0x11, [X8] }
      do
        v41 = __ldxr(_X8);
      while ( __stxr(v41 | 2, _X8) );
      _X8 = (unsigned __int64 *)(device + 64);
      __asm { PRFM            #0x11, [X8] }
      do
        v44 = __ldxr(_X8);
      while ( __stxr(v44 | 0x8000, _X8) );
      input_set_capability(device, 1, 143);
      input_set_abs_params(v11, 53, 0, v7[4], 0, 0);
      input_set_abs_params(v11, 54, 0, v7[5], 0, 0);
      input_mt_init_slots(v11, v7[6], 2);
      input_set_abs_params(v11, 48, 0, 255, 0, 0);
      input_set_abs_params(v11, 49, 0, 255, 0, 0);
      *(_DWORD *)(a1 + 952) = v7[4];
      *(_DWORD *)(a1 + 956) = v7[5];
      *(_DWORD *)(a1 + 960) = v7[6];
      v13 = input_register_device(v11);
      if ( (v13 & 0x80000000) == 0 )
      {
        v15 = *(unsigned int **)a1;
        *(_QWORD *)(a1 + 944) = v11;
        if ( (syna_tcm_set_report_dispatcher(v15, 17, syna_dev_process_touch_report, a1) & 0x80000000) != 0 )
          printk(&unk_35F92, "syna_dev_set_up_input_device", v16);
        mutex_unlock(a1 + 632);
        return 0;
      }
      v19 = v13;
      printk(&unk_375F8, "syna_dev_create_input_device", v14);
      input_free_device(v11);
    }
    else
    {
      printk(&unk_375CB, "syna_dev_create_input_device", v10);
      v19 = -19;
    }
  }
  else
  {
    printk(&unk_3BE43, "syna_dev_create_input_device", v8);
    v19 = -22;
  }
  printk(&unk_3C485, "syna_dev_set_up_input_device", v18);
  mutex_unlock(a1 + 632);
  return v19;
}
