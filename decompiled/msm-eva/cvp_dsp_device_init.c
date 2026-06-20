__int64 cvp_dsp_device_init()
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  unsigned int v2; // w19
  unsigned __int64 v3; // x0
  __int64 v4; // x19
  unsigned __int64 v5; // x8
  char format[14]; // [xsp+8h] [xbp-28h] BYREF
  __int16 v7; // [xsp+16h] [xbp-1Ah]
  _QWORD v8[3]; // [xsp+18h] [xbp-18h] BYREF

  v8[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8[0] = 0;
  v8[1] = 0;
  strcpy(format, "qcom,fastcv0");
  format[13] = 0;
  v7 = 0;
  _mutex_init(&gfa_cv, "&me->tx_lock", &cvp_dsp_device_init___key);
  _mutex_init(&unk_6C600, "&me->rx_lock", &cvp_dsp_device_init___key_92);
  dword_6C668 = 0;
  byte_6C670 = 0;
  dword_6C688 = 0;
  _init_swait_queue_head(&unk_6C690, "&x->wait", &init_completion___key_1);
  dword_6C6A8 = 0;
  _init_swait_queue_head(&unk_6C6B0, "&x->wait", &init_completion___key_1);
  dword_6C6C8 = 0;
  _init_swait_queue_head(&unk_6C6D0, "&x->wait", &init_completion___key_1);
  dword_6C6E8 = 0;
  _init_swait_queue_head(&unk_6C6F0, "&x->wait", &init_completion___key_1);
  dword_6C708 = 0;
  _init_swait_queue_head(&unk_6C710, "&x->wait", &init_completion___key_1);
  dword_6C728 = 0;
  _init_swait_queue_head(&unk_6C730, "&x->wait", &init_completion___key_1);
  dword_6C748 = 0;
  _init_swait_queue_head(&unk_6C750, "&x->wait", &init_completion___key_1);
  dword_6C768 = 0;
  _init_swait_queue_head(&unk_6C770, "&x->wait", &init_completion___key_1);
  dword_6C788 = 0;
  _init_swait_queue_head(&unk_6C790, "&x->wait", &init_completion___key_1);
  dword_6C7B4 = -1159857458;
  dword_6C9D8 = -1159857458;
  LODWORD(qword_6C7A8) = -1159857458;
  LODWORD(qword_6CF10) = -1159857458;
  _mutex_init(&unk_6CF58, "&mlist->lock", &INIT_MSM_CVP_LIST___key_0);
  qword_6CF48 = (__int64)&qword_6CF48;
  qword_6CF50 = (__int64)&qword_6CF48;
  _mutex_init(&unk_6C630, "&me->driver_name_lock", &cvp_dsp_device_init___key_94);
  dword_6CF88 = 1;
  snprintf(byte_6CF8C, 0x10u, format);
  format[11] = 49;
  dword_6CF9C = 1;
  snprintf(byte_6CFA0, 0x10u, format);
  format[11] = 50;
  dword_6CFB0 = 1;
  snprintf(byte_6CFB4, 0x10u, format);
  format[11] = 51;
  dword_6CFC4 = 1;
  snprintf(byte_6CFC8, 0x10u, format);
  format[11] = 52;
  dword_6CFD8 = 1;
  snprintf(byte_6CFDC, 0x10u, format);
  format[11] = 53;
  dword_6CFEC = 1;
  snprintf(byte_6CFF0, 0x10u, format);
  format[11] = 54;
  dword_6D000 = 1;
  snprintf(byte_6D004, 0x10u, format);
  format[11] = 55;
  dword_6D014 = 1;
  snprintf(byte_6D018, 0x10u, format);
  result = _register_rpmsg_driver(&cvp_dsp_rpmsg_client, &_this_module);
  if ( (_DWORD)result )
  {
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      v2 = result;
      printk(&unk_870F8, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      result = v2;
    }
  }
  else
  {
    strcpy((char *)v8, "cvp-dsp-thread");
    mutex_lock(&gfa_cv);
    if ( !dword_6C668 )
      dword_6C668 = 1;
    mutex_unlock(&gfa_cv);
    v3 = kthread_create_on_node(cvp_dsp_thread, &gfa_cv, 0xFFFFFFFFLL, v8);
    v4 = v3;
    if ( v3 <= 0xFFFFFFFFFFFFF000LL )
      wake_up_process(v3);
    qword_6CF30 = v4;
    if ( v4 )
    {
      result = 0;
    }
    else
    {
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v5 = _ReadStatusReg(SP_EL0);
        printk(&unk_877E9, *(unsigned int *)(v5 + 1800), *(unsigned int *)(v5 + 1804), &unk_8E7CE);
      }
      result = 4294967286LL;
      dword_6C668 = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
