void __fastcall dsi_bridge_pre_enable(__int64 a1)
{
  __int64 v1; // x21
  __int64 v2; // x9
  __int64 v3; // x8
  int v5; // w0
  __int64 v6; // x9
  __int64 v7; // x8
  __int64 StatusReg; // x19
  __int64 v9; // x8
  _QWORD *v10; // x21
  __int64 v11; // x0
  __int64 (__fastcall *v12)(_QWORD); // x8
  int v13; // w0
  __int64 (__fastcall *v14)(_QWORD); // x8
  __int64 v15; // x0
  int v16; // w0
  void (__fastcall *v17)(_QWORD); // x8
  __int64 v18; // x0
  int v19; // w0
  __int64 v20; // x0
  __int64 v21; // x10
  __int64 v22; // [xsp+18h] [xbp+18h]

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 304);
    if ( v1 && (v2 = *(_QWORD *)(v1 + 264)) != 0 )
    {
      v3 = *(_QWORD *)(a1 + 304);
      if ( (*(_BYTE *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 112) + 80LL) + 2008LL) + 10LL) & 4) != 0 )
      {
        *(_DWORD *)(v2 + 1968) = 0;
        v3 = *(_QWORD *)(a1 + 304);
      }
      v5 = dsi_display_set_mode(v3, a1 + 312, 0);
      if ( v5 )
      {
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: [%d] failed to perform a mode set, rc=%d\n",
          *(_DWORD *)(a1 + 296),
          v5);
      }
      else
      {
        v6 = a1;
        if ( (*(_BYTE *)(a1 + 468) & 0x31) != 0 )
        {
          _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%d] seamless pre-enable\n", *(_DWORD *)(a1 + 296));
        }
        else
        {
          v7 = *(_QWORD *)(v1 + 168);
          StatusReg = _ReadStatusReg(SP_EL0);
          v9 = *(unsigned int *)(v7 + 1608);
          while ( (unsigned int)v9 >= 3 )
          {
            __break(0x5512u);
            if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                             + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
                & 1) != 0 )
            {
              ++*(_DWORD *)(StatusReg + 16);
              v22 = v9;
              v20 = _traceiter_tracing_mark_write(0, 0x42u, StatusReg, (__int64)"dsi_display_prepare", 0);
              v9 = v22;
              v21 = *(_QWORD *)(StatusReg + 16) - 1LL;
              *(_DWORD *)(StatusReg + 16) = v21;
              if ( !v21 || (v6 = a1, !*(_QWORD *)(StatusReg + 16)) )
              {
                preempt_schedule_notrace(v20);
                v9 = v22;
                v6 = a1;
              }
            }
          }
          v10 = (_QWORD *)(v1 + 8 * v9);
          v11 = *(_QWORD *)(v6 + 304);
          v12 = (__int64 (__fastcall *)(_QWORD))v10[216];
          if ( *((_DWORD *)v12 - 1) != 2041732229 )
            __break(0x8228u);
          v13 = v12(v11);
          if ( v13 )
          {
            drm_dev_printk(
              0,
              &unk_248D72,
              "*ERROR* [msm-dsi-error]: [%d] DSI display prepare failed, rc=%d\n",
              *(_DWORD *)(a1 + 296),
              v13);
          }
          else
          {
            trace_tracing_mark_write_0(69, StatusReg, "dsi_display_prepare");
            trace_tracing_mark_write_0(66, StatusReg, "dsi_display_enable");
            v14 = (__int64 (__fastcall *)(_QWORD))v10[219];
            v15 = *(_QWORD *)(a1 + 304);
            if ( *((_DWORD *)v14 - 1) != 2041732229 )
              __break(0x8228u);
            v16 = v14(v15);
            if ( v16 )
            {
              drm_dev_printk(
                0,
                &unk_248D72,
                "*ERROR* [msm-dsi-error]: [%d] DSI display enable failed, rc=%d\n",
                *(_DWORD *)(a1 + 296),
                v16);
              v17 = (void (__fastcall *)(_QWORD))v10[231];
              v18 = *(_QWORD *)(a1 + 304);
              if ( *((_DWORD *)v17 - 1) != 2041732229 )
                __break(0x8228u);
              v17(v18);
            }
            trace_tracing_mark_write_0(69, StatusReg, "dsi_display_enable");
            v19 = dsi_display_splash_res_cleanup(*(_QWORD *)(a1 + 304));
            if ( v19 )
              drm_dev_printk(
                0,
                &unk_248D72,
                "*ERROR* [msm-dsi-error]: Continuous splash pipeline cleanup failed, rc=%d\n",
                v19);
          }
        }
      }
    }
    else
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Incorrect bridge details\n");
    }
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
  }
}
