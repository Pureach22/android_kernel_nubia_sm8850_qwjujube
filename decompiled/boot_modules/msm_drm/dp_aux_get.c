__int64 __fastcall dp_aux_get(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, int a7)
{
  __int64 v14; // x0
  __int64 v15; // x21
  __int64 result; // x0

  if ( a2 && a3 )
  {
    v14 = devm_kmalloc(a1, 1848, 3520);
    if ( v14 )
    {
      v15 = v14;
      *(_DWORD *)(v14 + 200) = 0;
      _init_swait_queue_head(v14 + 208, "&x->wait", &init_completion___key_1);
      *(_BYTE *)(v15 + 1810) = 0;
      _mutex_init(v15 + 152, "&aux->mutex", &dp_aux_get___key);
      *(_QWORD *)(v15 + 128) = a2;
      *(_QWORD *)(v15 + 136) = a3 + 464;
      *(_DWORD *)(v15 + 1836) = -1;
      *(_QWORD *)(v15 + 56) = dp_aux_isr;
      *(_QWORD *)(v15 + 64) = dp_aux_init;
      result = v15 + 8;
      *(_QWORD *)(v15 + 40) = dp_aux_register;
      *(_QWORD *)(v15 + 48) = dp_aux_deregister;
      *(_QWORD *)v15 = a1;
      *(_QWORD *)(v15 + 72) = dp_aux_deinit;
      *(_QWORD *)(v15 + 80) = dp_aux_reconfig;
      *(_QWORD *)(v15 + 144) = a4;
      *(_QWORD *)(v15 + 1792) = a5;
      *(_DWORD *)(v15 + 1828) = 0;
      *(_QWORD *)(v15 + 88) = dp_aux_abort_transaction;
      *(_QWORD *)(v15 + 96) = dp_aux_set_sim_mode;
      *(_QWORD *)(v15 + 24) = a6;
      if ( a7 == 2 )
      {
        *(_QWORD *)(v15 + 104) = dp_aux_configure_wcd_switch;
        *(_QWORD *)(v15 + 112) = &wcd_usbss_reg_notifier;
        *(_QWORD *)(v15 + 120) = &wcd_usbss_unreg_notifier;
      }
    }
    else
    {
      return -12;
    }
  }
  else
  {
    _ReadStatusReg(SP_EL0);
    printk(&unk_275B6D, "dp_aux_get");
    return -19;
  }
  return result;
}
