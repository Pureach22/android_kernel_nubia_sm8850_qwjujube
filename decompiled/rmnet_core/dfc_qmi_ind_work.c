__int64 __fastcall dfc_qmi_ind_work(__int64 result)
{
  __int64 *v1; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x20
  __int64 v4; // x9
  _QWORD *v5; // x21
  _QWORD *v6; // x22
  _QWORD *v7; // x8
  __int64 v8; // x10
  __int64 v9; // x0
  int v10; // w8
  __int64 v11; // x0

  v1 = (__int64 *)(result - 376);
  if ( result != 376 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v3 = result;
    *(_DWORD *)(StatusReg + 16) += 512;
    v4 = raw_spin_lock_irqsave(result + 48);
    v6 = (_QWORD *)(v3 + 32);
    v5 = *(_QWORD **)(v3 + 32);
    if ( v5 != (_QWORD *)(v3 + 32) && v5 )
    {
      do
      {
        v7 = (_QWORD *)v5[1];
        if ( (_QWORD *)*v7 == v5 && (v8 = *v5, *(_QWORD **)(*v5 + 8LL) == v5) )
        {
          *(_QWORD *)(v8 + 8) = v7;
          *v7 = v8;
        }
        else
        {
          _list_del_entry_valid_or_report(v5);
        }
        *v5 = 0xDEAD000000000100LL;
        v5[1] = 0xDEAD000000000122LL;
        raw_spin_unlock_irqrestore(v3 + 48, v4);
        if ( !*(_DWORD *)(v3 + 56) )
        {
          v10 = *((unsigned __int16 *)v5 + 8);
          if ( v10 == 36 )
          {
            ((void (__fastcall *)(__int64 *, char *))dfc_handle_tx_link_status_ind)(v1, (char *)v5 + 20);
          }
          else if ( v10 == 34 )
          {
            dfc_do_burst_flow_control(v1, (_BYTE *)v5 + 20, 0);
          }
        }
        kfree(v5);
        v9 = raw_spin_lock_irqsave(v3 + 48);
        v5 = (_QWORD *)*v6;
        v4 = v9;
      }
      while ( (_QWORD *)*v6 != v6 && v5 );
    }
    v11 = raw_spin_unlock_irqrestore(v3 + 48, v4);
    local_bh_enable(v11);
    return qmi_rmnet_set_dl_msg_active(*v1);
  }
  return result;
}
