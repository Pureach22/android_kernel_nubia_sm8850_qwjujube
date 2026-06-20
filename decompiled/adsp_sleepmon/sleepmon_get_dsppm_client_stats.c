__int64 sleepmon_get_dsppm_client_stats()
{
  unsigned int v0; // w19
  __int64 v1; // x0
  __int64 v3; // [xsp+8h] [xbp-18h] BYREF
  __int64 v4; // [xsp+10h] [xbp-10h]
  __int64 v5; // [xsp+18h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = 0;
  v4 = 0;
  mutex_lock(&unk_B140);
  v0 = -22;
  if ( qword_A680 )
  {
    if ( dword_A678 )
    {
      v1 = *(_QWORD *)(qword_A680 + 968);
      v3 = 0x200000010LL;
      v4 = 0x100000002LL;
      v0 = rpmsg_send(v1, &v3, 16);
      if ( v0 )
        printk(&unk_9902);
    }
  }
  mutex_unlock(&unk_B140);
  _ReadStatusReg(SP_EL0);
  return v0;
}
