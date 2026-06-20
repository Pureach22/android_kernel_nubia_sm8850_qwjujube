__int64 __fastcall qmi_rmnet_pm_notify_cb(__int64 a1, __int64 a2)
{
  __int64 qmi_pt; // x0
  __int64 v3; // x8
  char v4; // w21
  __int64 v5; // x19
  unsigned int v6; // w20
  _UNKNOWN **i; // x21
  void (__fastcall *v8)(_QWORD); // x8
  __int64 lock; // x0
  void *v11; // x0
  unsigned __int64 v18; // x10
  unsigned __int8 v19[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19[0] = 0;
  if ( a2 == 4 )
  {
    lock = _rcu_read_lock();
    if ( qmi_info_ptr )
    {
      _X8 = (unsigned __int64 *)(qmi_info_ptr + 64);
      __asm { PRFM            #0x11, [X8] }
      do
        v18 = __ldxr(_X8);
      while ( __stxr(v18 & 0xFFFFFFFFFFFFFFFELL, _X8) );
      goto LABEL_21;
    }
    v11 = &unk_2CBF8;
LABEL_29:
    lock = printk(v11, "qmi_rmnet_pm_notify_cb");
LABEL_21:
    _rcu_read_unlock(lock);
    goto LABEL_22;
  }
  if ( a2 != 3 )
    goto LABEL_22;
  if ( rmnet_work && (rmnet_work_quit & 1) == 0 && rmnet_work_inited == 1 )
    cancel_delayed_work_sync(rmnet_work);
  qmi_pt = _rcu_read_lock();
  v3 = qmi_info_ptr;
  if ( !qmi_info_ptr )
  {
    v11 = &unk_2D805;
    goto LABEL_29;
  }
  v4 = *(_BYTE *)(qmi_info_ptr + 72);
  v5 = *(_QWORD *)(qmi_info_ptr + 80);
  if ( (v4 & 1) == 0 )
  {
    *(_BYTE *)(qmi_info_ptr + 74) = 1;
    *(_BYTE *)(v3 + 72) = 1;
    rmnet_module_hook_aps_data_inactive();
    __dmb(0xBu);
    v19[0] = 32;
    ps_bearer_id = 0;
    qword_2FD6A = 0;
    qword_2FD72 = 0;
    qword_2FD7A = 0;
    rmnet_prepare_ps_bearers(v5, v19, (__int64)&ps_bearer_id);
    v6 = v19[0];
    if ( dfc_qmap )
    {
      qmi_pt = dfc_qmap_set_powersave(1, v19[0], &ps_bearer_id);
    }
    else
    {
      qmi_pt = rmnet_get_qmi_pt(v5);
      if ( qmi_pt )
      {
        qmi_pt = *(_QWORD *)(qmi_pt + 8);
        if ( qmi_pt )
        {
          qmi_pt = wda_set_powersave_mode(qmi_pt, 1, v6, &ps_bearer_id);
          if ( (qmi_pt & 0x80000000) != 0 )
            qmi_pt = printk(&unk_2CD5B, "qmi_rmnet_set_powersave_mode");
        }
      }
    }
  }
  _rcu_read_unlock(qmi_pt);
  if ( v5 && (unsigned int)rmnet_get_powersave_notif(v5) && (v4 & 1) == 0 )
  {
    printk(&unk_2D58E, "qmi_rmnet_pm_notify_cb");
    rmnet_mem_cb(0, 0);
    for ( i = (_UNKNOWN **)ps_list; i != &ps_list; i = (_UNKNOWN **)*i )
    {
      v8 = (void (__fastcall *)(_QWORD))*(i - 2);
      if ( *((_DWORD *)v8 - 1) != 251140989 )
        __break(0x8228u);
      v8(v5);
    }
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return 0;
}
