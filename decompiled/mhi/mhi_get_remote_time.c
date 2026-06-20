__int64 __fastcall mhi_get_remote_time(__int64 a1, int a2, __int64 a3)
{
  __int64 v3; // x19
  __int64 v4; // x23
  __int64 v5; // x21
  unsigned int sync; // w0
  void (__fastcall *v10)(_QWORD); // x8
  const char *v11; // x3
  const char *v12; // x4
  const char *v13; // x5
  __int64 v14; // x8
  __int64 v15; // x20
  const char *v16; // x0
  int v17; // w8
  const char *v18; // x4
  __int64 v20; // x0
  _QWORD *v21; // x20
  void (__fastcall *v22)(_QWORD); // x8
  int v23; // w8
  __int64 (__fastcall *v24)(_QWORD); // x9
  int v25; // w8
  int v26; // w0
  unsigned __int64 StatusReg; // x22
  __int64 (__fastcall *v33)(__int64); // x8
  __int64 v34; // x0
  __int64 v36; // x8
  void (__fastcall *v37)(_QWORD); // x8
  __int64 v38; // x8
  __int64 v39; // x2
  _QWORD *v40; // x1
  int v41; // w24
  __int64 v42; // x25
  void (__fastcall *v43)(_QWORD); // x8
  unsigned int v44; // w19

  v3 = *(_QWORD *)(a1 + 16);
  v4 = *(_QWORD *)(v3 + 16);
  v5 = *(_QWORD *)(*(_QWORD *)(v4 + 192) + 104LL);
  if ( !v5 || !*(_QWORD *)(v5 + 32) )
    return 4294967274LL;
  mutex_lock(v5 + 128);
  sync = mhi_device_get_sync(*(_QWORD *)(v3 + 16));
  if ( !sync )
  {
    v10 = *(void (__fastcall **)(_QWORD))(v3 + 512);
    if ( *((_DWORD *)v10 - 1) != -700558418 )
      __break(0x8228u);
    v10(v3);
    v14 = *(_QWORD *)(*(_QWORD *)(v3 + 16) + 192LL);
    if ( !v14 || *(_DWORD *)(v14 + 24) > 1u )
    {
LABEL_30:
      v20 = _kmalloc_cache_noprof(
              raw_read_lock_bh,
              &print_fmt_mhi_intvec_states[8],
              _ksymtab_mhi_controller_set_base,
              v11,
              v12,
              v13);
      v21 = (_QWORD *)v20;
      if ( v20 )
      {
        *(_DWORD *)(v20 + 16) = a2;
        *(_QWORD *)(v20 + 32) = a1;
        *(_QWORD *)(v20 + 40) = a3;
        if ( *(_BYTE *)(v5 + 64) == 1 )
        {
          v22 = *(void (__fastcall **)(_QWORD))(v3 + 528);
          if ( *((_DWORD *)v22 - 1) != -2145957670 )
            __break(0x8228u);
          v22(v3);
          mhi_device_put(*(_QWORD *)(v3 + 16));
LABEL_51:
          raw_spin_lock(v5 + 104);
          v39 = v5 + 112;
          v40 = *(_QWORD **)(v5 + 120);
          if ( v21 == (_QWORD *)(v5 + 112) || v40 == v21 || *v40 != v39 )
          {
            _list_add_valid_or_report(v21, v40);
          }
          else
          {
            *(_QWORD *)(v5 + 120) = v21;
            *v21 = v39;
            v21[1] = v40;
            *v40 = v21;
          }
          raw_spin_unlock(v5 + 104);
          sync = 0;
          goto LABEL_66;
        }
        v23 = *(_DWORD *)(v5 + 40);
        v24 = *(__int64 (__fastcall **)(_QWORD))(v5 + 8);
        if ( v23 == -2 )
          v25 = 0;
        else
          v25 = v23 + 1;
        *(_DWORD *)(v5 + 40) = v25;
        if ( *((_DWORD *)v24 - 1) != -700558418 )
          __break(0x8229u);
        v26 = v24(v3);
        if ( !v26 )
        {
          StatusReg = _ReadStatusReg(SP_EL0);
          ++*(_DWORD *)(StatusReg + 16);
          __asm { MSR             DAIFSet, #3 }
          v33 = *(__int64 (__fastcall **)(__int64))v5;
          if ( *(_DWORD *)(*(_QWORD *)v5 - 4LL) != 2083580006 )
            __break(0x8228u);
          *(_QWORD *)(v5 + 48) = v33(v3);
          v34 = mhi_write_reg(v3);
          __dsb(0xEu);
          __asm { MSR             DAIFClr, #3 }
          v36 = *(_QWORD *)(StatusReg + 16) - 1LL;
          *(_DWORD *)(StatusReg + 16) = v36;
          if ( !v36 || !*(_QWORD *)(StatusReg + 16) )
            preempt_schedule(v34);
          v37 = *(void (__fastcall **)(_QWORD))(v5 + 16);
          if ( *((_DWORD *)v37 - 1) != -700558418 )
            __break(0x8228u);
          v37(v3);
          v38 = *(_QWORD *)(*(_QWORD *)(v3 + 16) + 192LL);
          if ( v38 && !*(_DWORD *)(v38 + 24) )
            ipc_log_string(
              *(_QWORD *)(v38 + 32),
              "[D][%s] time DB request with seq:0x%x\n",
              "mhi_get_remote_time",
              *(_DWORD *)(v5 + 40));
          *(_BYTE *)(v5 + 64) = 1;
          *(_DWORD *)(v5 + 72) = 0;
          _init_swait_queue_head(v5 + 80, "&x->wait", &init_completion___key_0);
          goto LABEL_51;
        }
        v41 = v26;
        v42 = *(_QWORD *)(*(_QWORD *)(v3 + 16) + 192LL);
        dev_err(
          v4 + 40,
          "[E][%s] LPM disable request failed for %s!\n",
          "mhi_get_remote_time",
          *(const char **)(a1 + 8));
        if ( v42 && *(_DWORD *)(v42 + 24) <= 2u )
          ipc_log_string(
            *(_QWORD *)(v42 + 32),
            "[E][%s] LPM disable request failed for %s!\n",
            "mhi_get_remote_time",
            *(const char **)(a1 + 8));
        kfree(v21);
      }
      else
      {
        v41 = -12;
      }
      v43 = *(void (__fastcall **)(_QWORD))(v3 + 528);
      if ( *((_DWORD *)v43 - 1) != -2145957670 )
        __break(0x8228u);
      v43(v3);
      mhi_device_put(*(_QWORD *)(v3 + 16));
      sync = v41;
      goto LABEL_66;
    }
    v15 = *(_QWORD *)(v14 + 32);
    v16 = to_mhi_pm_state_str(*(_DWORD *)(v3 + 336));
    v17 = *(_DWORD *)(v3 + 348);
    if ( v17 <= 3 )
    {
      if ( v17 > 1 )
      {
        if ( v17 == 2 )
          v18 = "M0";
        else
          v18 = "M1";
        goto LABEL_29;
      }
      if ( !v17 )
      {
        v18 = "RESET";
        goto LABEL_29;
      }
      if ( v17 == 1 )
      {
        v18 = "READY";
        goto LABEL_29;
      }
    }
    else
    {
      if ( v17 <= 5 )
      {
        if ( v17 == 4 )
          v18 = "M2";
        else
          v18 = "M3";
        goto LABEL_29;
      }
      switch ( v17 )
      {
        case 6:
          v18 = "M3_FAST";
          goto LABEL_29;
        case 7:
          v18 = "BHI";
          goto LABEL_29;
        case 255:
          v18 = "SYS ERROR";
LABEL_29:
          ipc_log_string(v15, "[I][%s] Enter with pm_state:%s MHI_STATE:%s\n", "mhi_get_remote_time", v16, v18);
          goto LABEL_30;
      }
    }
    v18 = "Unknown state";
    goto LABEL_29;
  }
LABEL_66:
  v44 = sync;
  mutex_unlock(v5 + 128);
  return v44;
}
