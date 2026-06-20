__int64 __fastcall gsi_write_evt_ring_scratch(unsigned __int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned int v4; // w19
  __int64 v5; // x9
  __int64 v6; // x23
  __int64 v7; // x4

  if ( !gsi_ctx )
  {
    printk(&unk_2DEB9, "gsi_write_evt_ring_scratch", 2387);
    return 4294967288LL;
  }
  v4 = a1;
  if ( *(unsigned int *)(gsi_ctx + 28612) <= a1 )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d bad params evt_ring_hdl=%lu\n", "gsi_write_evt_ring_scratch", 2392, a1);
    return 4294967290LL;
  }
  if ( a1 >= 0x20 )
  {
LABEL_11:
    __break(0x5512u);
    return gsi_dealloc_evt_ring();
  }
  v5 = gsi_ctx + 328 * a1;
  v6 = v5 + 18328;
  v7 = *(unsigned int *)(v5 + 18456);
  if ( (_DWORD)v7 != 1 )
  {
    if ( a1 != 31 )
    {
      dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d bad state %d\n", "gsi_write_evt_ring_scratch", 2400, v7);
      return 4294967289LL;
    }
    goto LABEL_11;
  }
  mutex_lock(v5 + 18536, a2, a3, a4, v7);
  *(_QWORD *)(v6 + 312) = a2;
  gsihal_write_reg_nk(48, *(unsigned int *)(gsi_ctx + 20), v4);
  gsihal_write_reg_nk(49, *(unsigned int *)(gsi_ctx + 20), v4);
  mutex_unlock(v6 + 208);
  return 0;
}
