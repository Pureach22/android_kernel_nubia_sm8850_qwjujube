__int64 __fastcall rmnet_shs_wq_pause(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 lock; // x0
  __int64 result; // x0
  __int64 v10; // [xsp+0h] [xbp-80h] BYREF
  __int64 v11; // [xsp+8h] [xbp-78h]
  __int64 v12; // [xsp+10h] [xbp-70h]
  __int64 v13; // [xsp+18h] [xbp-68h]
  __int64 v14; // [xsp+20h] [xbp-60h]
  __int64 v15; // [xsp+28h] [xbp-58h]
  __int64 v16; // [xsp+30h] [xbp-50h]
  __int64 v17; // [xsp+38h] [xbp-48h]
  __int64 v18; // [xsp+40h] [xbp-40h]
  __int64 v19; // [xsp+48h] [xbp-38h]
  __int64 v20; // [xsp+50h] [xbp-30h]
  __int64 v21; // [xsp+58h] [xbp-28h]
  __int64 v22; // [xsp+60h] [xbp-20h]
  __int64 v23; // [xsp+68h] [xbp-18h]
  __int64 v24; // [xsp+70h] [xbp-10h]
  __int64 v25; // [xsp+78h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  ++rmnet_shs_pause_count;
  v17 = 0;
  v18 = 0;
  v15 = 0;
  v16 = 0;
  v13 = 0;
  v14 = 0;
  v11 = 0;
  v12 = 0;
  v10 = 0;
  if ( rmnet_shs_wq )
  {
    a1 = rmnet_shs_delayed_wq;
    if ( rmnet_shs_delayed_wq )
      a1 = cancel_delayed_work_sync(
             rmnet_shs_delayed_wq,
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17);
  }
  qword_19670 = 0;
  qword_19678 = 0;
  rmnet_shs_cpu_rx_filter_flows = 0;
  qword_19668 = 0;
  lock = _rcu_read_lock(a1);
  if ( BYTE2(dword_19499) != 1 && (rmnet_shs_halt_mask & 2) == 0 )
  {
    LOBYTE(dword_19499) = 1;
    lock = rmnet_shs_switch_enable();
    ++qword_1A258;
  }
  _rcu_read_unlock(lock);
  rmnet_shs_create_pause_msg_resp(0, &v10);
  result = rmnet_shs_genl_msg_direct_send_to_userspace(&v10);
  _ReadStatusReg(SP_EL0);
  return result;
}
