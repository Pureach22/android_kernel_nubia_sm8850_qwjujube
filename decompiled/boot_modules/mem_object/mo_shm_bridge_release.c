__int64 __fastcall mo_shm_bridge_release(_QWORD *a1)
{
  __int64 v2; // x1
  void (__fastcall *v3)(_QWORD); // x8
  __int64 v4; // x0
  _QWORD *v5; // x8
  _QWORD *v6; // x0
  __int64 v7; // x9

  if ( a1[21] )
    qtee_shmbridge_deregister();
  v2 = a1[13];
  a1[21] = 0;
  if ( v2 )
    dma_buf_unmap_attachment_unlocked(a1[12], v2, 0);
  if ( a1[12] )
    dma_buf_detach(a1[11]);
  v3 = (void (__fastcall *)(_QWORD))a1[28];
  a1[12] = 0;
  a1[13] = 0;
  if ( v3 )
  {
    v4 = a1[27];
    if ( *((_DWORD *)v3 - 1) != 251140989 )
      __break(0x8228u);
    v3(v4);
  }
  if ( a1[11] )
    dma_buf_put();
  mutex_lock(&mo_list_mutex);
  v5 = (_QWORD *)a1[26];
  v6 = a1 + 25;
  if ( (_QWORD *)*v5 == a1 + 25 && (v7 = *v6, *(_QWORD **)(*v6 + 8LL) == v6) )
  {
    *(_QWORD *)(v7 + 8) = v5;
    *v5 = v7;
  }
  else
  {
    _list_del_entry_valid_or_report();
  }
  a1[25] = 0xDEAD000000000100LL;
  a1[26] = 0xDEAD000000000122LL;
  mutex_unlock(&mo_list_mutex);
  printk(&unk_6EDD, "mo_shm_bridge_release");
  return kfree(a1);
}
