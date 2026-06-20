__int64 cleanup_module()
{
  void (__fastcall *v0)(__int64); // x8
  __int64 v1; // x0
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 result; // x0
  __int64 v7; // [xsp+8h] [xbp-28h] BYREF
  int v8; // [xsp+10h] [xbp-20h]
  __int64 v9; // [xsp+18h] [xbp-18h] BYREF
  int v10; // [xsp+20h] [xbp-10h]
  __int64 v11; // [xsp+28h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 0;
  v7 = 0;
  printk(&unk_C310);
  if ( byte_A488 == 1 )
  {
    set_qos_latency(0x7FFFFFFF);
    dword_A490 = 0x7FFFFFFF;
  }
  if ( qword_A480 )
    thermal_cooling_device_unregister();
  if ( qword_A478 )
    thermal_cooling_device_unregister();
  if ( byte_A3D8 == 1 )
  {
    mutex_lock(&unk_A3A8);
    complete_all(&dword_A3F0);
    complete_all(&dword_A410);
    mutex_unlock(&unk_A3A8);
    v0 = (void (__fastcall *)(__int64))off_A4E0;
    qword_A4E8 = (__int64)off_A4E0;
    if ( (unsigned int)dword_A43C <= 7 )
    {
      if ( off_A4E0 )
      {
        if ( *((_DWORD *)off_A4E0 - 1) != 1995188558 )
          __break(0x8228u);
        v0(8);
      }
    }
  }
  if ( gcdsprm[0] && byte_A3D8 == 1 )
  {
    if ( dword_A3DC )
    {
      v7 = 6;
      v1 = *(_QWORD *)(qword_A350 + 968);
      v8 = 12;
      rpmsg_send(v1, &v7, 12);
      dword_A3DC = 0;
    }
    if ( dword_A434 )
    {
      v7 = 8;
      v2 = *(_QWORD *)(qword_A350 + 968);
      v8 = 12;
      rpmsg_send(v2, &v7, 12);
      dword_A434 = 0;
    }
    if ( dword_A3E0 )
    {
      v7 = 11;
      v3 = *(_QWORD *)(qword_A350 + 968);
      v8 = 12;
      rpmsg_send(v3, &v7, 12);
      dword_A3E0 = 0;
    }
  }
  complete_all(&dword_B310);
  if ( dword_A470 )
  {
    v10 = 0;
    v9 = 0;
    mutex_lock(&unk_A440);
    if ( qword_A350 )
    {
      if ( gcdsprm[0] )
      {
        v5 = *(_QWORD *)(qword_A350 + 968);
        LODWORD(v9) = 10;
        HIDWORD(v9) = (unsigned __int16)dword_A474;
        v10 = 12;
        if ( !(unsigned int)rpmsg_send(v5, &v9, 12) )
          dword_A470 = 0;
      }
    }
    mutex_unlock(&unk_A440);
    dword_A470 = 0;
  }
  else if ( dword_A474 )
  {
    v10 = 0;
    v9 = 0;
    mutex_lock(&unk_A440);
    if ( qword_A350 )
    {
      if ( gcdsprm[0] )
      {
        v4 = *(_QWORD *)(qword_A350 + 968);
        LODWORD(v9) = 10;
        WORD2(v9) = 0;
        HIWORD(v9) = dword_A470;
        v10 = 12;
        if ( !(unsigned int)rpmsg_send(v4, &v9, 12) )
          dword_A474 = 0;
      }
    }
    mutex_unlock(&unk_A440);
    dword_A474 = 0;
  }
  if ( byte_A489 == 1 )
  {
    unregister_rpmsg_driver(&cdsprm_rpmsg_client);
    qword_A350 = 0;
    gcdsprm[0] = 0;
  }
  if ( qword_A2B8 )
    kthread_stop(qword_A2B8);
  if ( qword_A2C0 )
    destroy_workqueue(qword_A2C0);
  if ( (_DWORD)qword_A494 )
    platform_driver_unregister(&cdsp_rm);
  if ( HIDWORD(qword_A494) )
    platform_driver_unregister(&hvx_rm);
  debugfs_remove(qword_A4A0);
  remove_proc_entry("dcvs_clients", 0);
  printk(&unk_B9F9);
  byte_A489 = 0;
  qword_A494 = 0;
  qword_A478 = 0;
  qword_A480 = 0;
  qword_A4A0 = 0;
  qword_A4A8 = 0;
  qword_A4B0 = 0;
  qword_A4B8 = 0;
  qword_A4C0 = 0;
  result = printk(&unk_C57A);
  _ReadStatusReg(SP_EL0);
  return result;
}
