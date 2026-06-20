__int64 __fastcall msm_cvp_cleanup_instance(__int64 a1)
{
  __int64 *inst_validate; // x0
  __int64 v3; // x1
  __int64 v4; // x2
  __int64 v5; // x3
  unsigned int *v6; // x20
  unsigned int v7; // w21
  __int64 result; // x0
  _QWORD **v9; // x22
  int v10; // w20
  __int64 v11; // x8
  _BOOL4 v12; // w21
  int v13; // w20
  _QWORD **v14; // x8
  _QWORD *v16; // x25
  char v17; // w8
  int v18; // w9
  unsigned __int64 v19; // x26
  unsigned __int64 v20; // x8
  void (__fastcall *v21)(_QWORD); // x8
  __int64 v22; // x2
  __int64 v23; // x3
  __int64 v24; // x9
  __int64 *v25; // x8
  void (__fastcall *v26)(_QWORD); // x9
  __int64 v27; // x0
  unsigned __int64 StatusReg; // x8

  inst_validate = cvp_get_inst_validate(*(_QWORD *)(a1 + 128), (__int64 *)a1);
  if ( inst_validate )
  {
    v6 = (unsigned int *)inst_validate;
    v7 = msm_cvp_session_flush_stop(a1);
    cvp_put_inst(v6);
    result = v7;
    if ( v7 )
      return result;
    v9 = (_QWORD **)(a1 + 664);
    v10 = *(_DWORD *)(*(_QWORD *)(a1 + 128) + 1024LL);
    mutex_lock(a1 + 680);
    v11 = *(_QWORD *)(a1 + 664);
    v12 = v11 != a1 + 664;
    if ( v11 != a1 + 664 )
    {
      v13 = v10 >> 1;
      if ( v13 >= 1 )
      {
        do
        {
          mutex_unlock(a1 + 680);
          usleep_range_state(1000, 2000, 2);
          msm_cvp_clean_sess_queue(a1, a1 + 232);
          msm_cvp_clean_sess_queue(a1, a1 + 176);
          mutex_lock(a1 + 680);
          v14 = *(_QWORD ***)(a1 + 664);
          v12 = v14 != v9;
          if ( v14 == v9 )
            break;
        }
        while ( (unsigned int)v13-- > 1 );
      }
    }
    mutex_unlock(a1 + 680);
    if ( v12 )
    {
      if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        printk(&unk_90598, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
      }
      mutex_lock(a1 + 680);
      v16 = *v9;
      if ( *v9 != v9 )
      {
        v17 = msm_cvp_debug;
        v18 = msm_cvp_debug_out;
        v19 = _ReadStatusReg(SP_EL0);
        do
        {
          if ( (v17 & 2) != 0 && !v18 )
          {
            printk(&unk_93465, *(unsigned int *)(v19 + 1800), *(unsigned int *)(v19 + 1804), "warn");
            v17 = msm_cvp_debug;
            v18 = msm_cvp_debug_out;
          }
          v16 = (_QWORD *)*v16;
        }
        while ( v16 != v9 );
      }
      mutex_unlock(a1 + 680);
      v21 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 128) + 272LL) + 48LL);
      if ( *((_DWORD *)v21 - 1) != -1841792102 )
        __break(0x8228u);
      v21(a1);
    }
  }
  else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v20 = _ReadStatusReg(SP_EL0);
    printk(&unk_8FA47, *(unsigned int *)(v20 + 1800), *(unsigned int *)(v20 + 1804), &unk_8E7CE);
  }
  if ( (unsigned int)cvp_release_arp_buffers(a1, v3, v4, v5)
    && (msm_cvp_debug & 2) != 0
    && !msm_cvp_debug_out
    && (unsigned int)__ratelimit(&msm_cvp_cleanup_instance__rs, "msm_cvp_cleanup_instance") )
  {
    printk(&unk_91A9B, "warn", v22, v23);
  }
  v24 = *(_QWORD *)(a1 + 128);
  *(_DWORD *)(a1 + 15408) = 0x7FFFFFFF;
  v25 = *(__int64 **)(v24 + 256);
  if ( v25 )
  {
    v26 = (void (__fastcall *)(_QWORD))v25[23];
    if ( v26 )
    {
      v27 = *v25;
      if ( *((_DWORD *)v26 - 1) != -1066802076 )
        __break(0x8229u);
      v26(v27);
    }
  }
  return 0;
}
