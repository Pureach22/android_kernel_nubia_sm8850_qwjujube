__int64 msm_audio_ion_crash_handler()
{
  __int64 v0; // x24
  __int64 v1; // x22
  __int64 v2; // x21
  __int64 *v3; // x19
  __int64 *v4; // x9
  __int64 *v5; // x10
  __int64 *v6; // x0
  __int64 **v7; // x8
  __int64 result; // x0
  __int64 v9; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v10[2]; // [xsp+10h] [xbp-10h] BYREF

  v10[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (msm_audio_ion_fd_list_init & 1) != 0 )
  {
    mutex_lock(&msm_audio_ion_fd_list);
    v0 = qword_7690;
    if ( (__int64 *)qword_7690 != &qword_7690 )
    {
      do
      {
        if ( v0 != 48 )
        {
          v1 = *(_QWORD *)(v0 - 24);
          v2 = *(_QWORD *)(*(_QWORD *)(v0 - 8) + 152LL);
          if ( *(_BYTE *)(v0 + 16) == 1 )
          {
            v9 = 0x2000400000LL;
            v10[0] = 0x700000003LL;
            if ( *(_BYTE *)(v0 + 16) == 1 )
            {
              if ( (qcom_scm_assign_mem(*(_QWORD *)(v0 - 16), *(_QWORD *)(v0 - 32), &v9, v10, 1) & 0x80000000) != 0 )
                printk(&unk_77C6, "msm_audio_hyp_unassign");
              *(_BYTE *)(v0 + 16) = 0;
            }
          }
          if ( v1 )
            msm_audio_ion_free(v1, v2);
        }
        v0 = *(_QWORD *)v0;
      }
      while ( (__int64 *)v0 != &qword_7690 );
      v3 = (__int64 *)qword_7690;
      while ( v3 != &qword_7690 )
      {
        v4 = v3;
        v3 = (__int64 *)*v3;
        if ( v4 )
        {
          v6 = v4 - 6;
          if ( v4 != &qword_30 )
          {
            v7 = (__int64 **)v4[1];
            if ( *v7 == v4 && (__int64 *)v3[1] == v4 )
            {
              v3[1] = (__int64)v7;
              *v7 = v3;
            }
            else
            {
              _list_del_entry_valid_or_report(v4);
              v6 = v5;
            }
            *v4 = 0xDEAD000000000100LL;
            v4[1] = 0xDEAD000000000122LL;
            kfree(v6);
          }
        }
      }
    }
    result = mutex_unlock(&msm_audio_ion_fd_list);
  }
  else
  {
    result = printk(&unk_7AF9, "msm_audio_ion_crash_handler");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
