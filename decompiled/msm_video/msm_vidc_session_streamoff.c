__int64 __fastcall msm_vidc_session_streamoff(__int64 a1, unsigned int a2)
{
  unsigned int v4; // w20
  __int64 v5; // x22
  int v6; // w0
  __int64 v7; // x4
  unsigned int v8; // w21
  __int64 v10; // x23
  __int64 v11; // x0
  __int64 v12; // x4
  __int64 v13; // x22
  _QWORD *v14; // x1
  _QWORD *v15; // x9
  _QWORD *v16; // x8
  _QWORD *v17; // x24
  __int64 *v18; // x9
  unsigned int v19; // w21
  __int64 v20; // x1

  if ( a2 )
  {
    if ( a2 != 1 )
    {
      if ( !a1 || (msm_vidc_debug & 1) == 0 )
        return 4294967274LL;
      printk(&unk_833BC, "err ", a1 + 340, "msm_vidc_session_streamoff", a2);
      return 4294967274LL;
    }
    v4 = 2;
    v5 = 1;
  }
  else
  {
    v5 = 0;
    v4 = 1;
  }
  v6 = venus_hfi_stop(a1, a2);
  if ( !v6 )
  {
    v10 = *(_QWORD *)(a1 + 320);
    if ( a1 && (msm_vidc_debug & 2) != 0 )
      printk(&unk_963F3, "high", a1 + 340, "msm_vidc_session_streamoff", a2);
    mutex_unlock(a1 + 16);
    v11 = _msecs_to_jiffies(*(unsigned int *)(v10 + 4352));
    if ( !(unsigned int)wait_for_completion_timeout(a1 + 32 * v5 + 37584, v11) )
    {
      if ( a1 && (msm_vidc_debug & 1) != 0 )
        printk(&unk_89061, "err ", a1 + 340, "msm_vidc_session_streamoff", a2);
      msm_vidc_inst_timeout(a1);
      mutex_lock(a1 + 16);
      v6 = -110;
      goto LABEL_6;
    }
    mutex_lock(a1 + 16);
    if ( a2 )
    {
      v13 = 2544;
    }
    else
    {
      if ( a1 && (msm_vidc_debug & 4) != 0 )
        printk(&unk_821B8, "low ", a1 + 340, "msm_vidc_flush_input_timer", v12);
      v14 = *(_QWORD **)(a1 + 4008);
      v13 = 2504;
      if ( v14 != (_QWORD *)(a1 + 4008) )
      {
        do
        {
          v17 = (_QWORD *)*v14;
          v16 = (_QWORD *)v14[1];
          if ( (_QWORD *)*v16 == v14 && (_QWORD *)v17[1] == v14 )
          {
            v17[1] = v16;
            *v16 = v17;
          }
          else
          {
            _list_del_entry_valid_or_report(v14);
            v14 = v15;
          }
          *v14 = v14;
          v14[1] = v14;
          msm_vidc_pool_free(a1);
          v14 = v17;
        }
        while ( v17 != (_QWORD *)(a1 + 4008) );
      }
    }
    v18 = *(__int64 **)(a1 + v13);
    if ( v18 != (__int64 *)(a1 + v13) )
    {
      v7 = 0;
      do
      {
        if ( *((_DWORD *)v18 + 6) == v4 )
          v7 = ((*((_DWORD *)v18 + 20) >> 3) & 1) + (unsigned int)v7;
        v18 = (__int64 *)*v18;
      }
      while ( v18 != (__int64 *)(a1 + v13) );
      if ( (_DWORD)v7 )
      {
        if ( a1 && (msm_vidc_debug & 1) != 0 )
          printk(&unk_84E2E, "err ", a1 + 340, "msm_vidc_session_streamoff", v7);
        v6 = -22;
        goto LABEL_6;
      }
    }
    if ( a1 && (msm_vidc_debug & 2) != 0 )
      printk(&unk_8362A, "high", a1 + 340, "msm_vidc_session_streamoff", a2);
    if ( a2 == 1 )
    {
      if ( (is_state(a1, 2) & 1) == 0 )
      {
        v19 = 1;
LABEL_58:
        if ( (is_state(a1, 3) & 1) != 0 )
          v20 = v19;
        else
          v20 = 5;
LABEL_61:
        v6 = msm_vidc_change_state(a1, v20, "msm_vidc_state_change_streamoff");
        if ( !v6 )
        {
          msm_vidc_flush_buffers(a1, v4);
          msm_vidc_flush_read_only_buffers(a1, v4);
          return 0;
        }
        goto LABEL_6;
      }
    }
    else if ( (is_state(a1, 1) & 1) == 0 )
    {
      v19 = 2;
      goto LABEL_58;
    }
    v20 = 0;
    goto LABEL_61;
  }
LABEL_6:
  v8 = v6;
  if ( *(_DWORD *)(a1 + 332) )
  {
    if ( a1 )
    {
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_83660, "err ", a1 + 340, "msm_vidc_kill_session", v7);
    }
    msm_vidc_session_close(a1);
    msm_vidc_change_state(a1, 5, "msm_vidc_kill_session");
  }
  else if ( a1 && (msm_vidc_debug & 1) != 0 )
  {
    printk(&unk_93064, "err ", a1 + 340, "msm_vidc_kill_session", v7);
  }
  msm_vidc_flush_buffers(a1, v4);
  msm_vidc_flush_read_only_buffers(a1, v4);
  return v8;
}
