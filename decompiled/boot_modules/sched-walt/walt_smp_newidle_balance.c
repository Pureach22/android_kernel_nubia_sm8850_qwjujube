__int64 walt_smp_newidle_balance()
{
  __int64 v0; // x8
  __int64 v1; // x8
  char *v2; // x19
  void *v3; // x8
  __int64 result; // x0
  __int64 v5; // [xsp+0h] [xbp-20h] BYREF
  _QWORD v6[3]; // [xsp+8h] [xbp-18h] BYREF

  v6[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v0 = *(unsigned int *)(_ReadStatusReg(SP_EL0) + 40);
  if ( (unsigned int)v0 >= 0x20 )
    __break(0x5512u);
  v1 = *((_QWORD *)&_per_cpu_offset + v0);
  v6[0] = 0;
  v6[1] = 0;
  v2 = (char *)&runqueues + v1;
  HIDWORD(v5) = 0;
  raw_spin_rq_lock_nested((char *)&runqueues + v1, 0);
  v3 = *((void **)v2 + 444);
  *((_DWORD *)v2 + 848) &= 3u;
  if ( v3 && v3 != &balance_push_callback && (rq_pin_lock___already_done_2 & 1) == 0 )
  {
    rq_pin_lock___already_done_2 = 1;
    _warn_printk("rq->balance_callback && rq->balance_callback != &balance_push_callback");
    __break(0x800u);
  }
  update_rq_clock(v2);
  walt_newidle_balance(v2, v6, (char *)&v5 + 4, &v5, 1);
  resched_curr(v2);
  result = raw_spin_rq_unlock(v2);
  _ReadStatusReg(SP_EL0);
  return result;
}
