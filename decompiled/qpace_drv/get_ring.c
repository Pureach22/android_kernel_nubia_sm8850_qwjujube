__int64 __fastcall get_ring(unsigned int a1)
{
  __int64 v2; // x20
  __int64 updated; // x0
  __int64 v4; // x20
  _QWORD *v5; // x20
  __int64 v6; // t1
  int v7; // w8

  v2 = tr_rings;
  updated = mutex_lock(&qpace_ref_lock);
  v4 = v2 + 32LL * (int)a1;
  v6 = *(_QWORD *)(v4 + 24);
  v5 = (_QWORD *)(v4 + 24);
  if ( v6 )
    goto LABEL_7;
  v7 = active_rings;
  if ( !active_rings )
  {
    pm_stay_awake(qpace_dev);
    updated = dev_pm_qos_update_request(&qos_req, 300);
    v7 = active_rings;
  }
  active_rings = v7 + 1;
  if ( a1 < 2 )
  {
    if ( (*((_BYTE *)&rings_inited_since_activation + (int)a1) & 1) == 0 )
    {
      *((_BYTE *)&rings_inited_since_activation + (int)a1) = 1;
      init_event_ring(a1, 1);
      init_transfer_ring(a1, 1);
    }
LABEL_7:
    ++*v5;
    return mutex_unlock(&qpace_ref_lock);
  }
  __break(0x5512u);
  return qpace_queue_compress(updated);
}
