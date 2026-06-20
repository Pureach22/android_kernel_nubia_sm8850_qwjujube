__int64 __fastcall sde_encoder_helper_unregister_irq(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  __int64 v5; // x8
  __int64 v6; // x22
  _DWORD *v7; // x21
  int v8; // w0
  int v9; // w4
  int v10; // w0
  int v11; // w4
  int v12; // w4
  __int64 v13; // x8
  int v14; // w6
  int v15; // w4

  if ( a1 )
  {
    if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 512) + 136LL) + 56LL) + 5912LL) == 1 )
    {
      return 0;
    }
    else if ( a2 >= 0x18 )
    {
      __break(0x5512u);
      return sde_encoder_get_hw_resources();
    }
    else
    {
      v5 = a1 + 56LL * a2;
      v6 = v5 + 1000;
      if ( (*(_DWORD *)(v5 + 1020) & 0x80000000) != 0 )
      {
        printk(&unk_25365C, "sde_encoder_helper_unregister_irq");
        if ( *(_QWORD *)a1 )
          v15 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
        else
          v15 = -1;
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "sde_encoder_helper_unregister_irq",
          753,
          -1,
          v15,
          a2,
          *(_DWORD *)(v6 + 16),
          *(_DWORD *)(v6 + 20),
          173);
        return 0;
      }
      else
      {
        v7 = (_DWORD *)(v5 + 1020);
        v8 = sde_core_irq_disable();
        if ( v8 )
        {
          if ( *(_QWORD *)a1 )
            v9 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
          else
            v9 = -1;
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "sde_encoder_helper_unregister_irq",
            760,
            -1,
            v9,
            a2,
            *(_DWORD *)(v6 + 16),
            *(_DWORD *)(v6 + 20),
            v8);
        }
        v10 = sde_core_irq_unregister_callback(*(_QWORD *)(a1 + 512), *(unsigned int *)(v6 + 20), v6 + 24);
        if ( v10 )
        {
          if ( *(_QWORD *)a1 )
            v11 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
          else
            v11 = -1;
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "sde_encoder_helper_unregister_irq",
            766,
            -1,
            v11,
            a2,
            *(_DWORD *)(v6 + 16),
            *(_DWORD *)(v6 + 20),
            v10);
        }
        if ( *(_QWORD *)a1 )
          v12 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
        else
          v12 = -1;
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "sde_encoder_helper_unregister_irq",
          768,
          -1,
          v12,
          a2,
          *(_DWORD *)(v6 + 16),
          *(_DWORD *)(v6 + 20),
          239);
        if ( (_drm_debug & 4) != 0 )
        {
          v13 = *(_QWORD *)(a1 + 496);
          if ( v13 )
            v14 = *(_DWORD *)(v13 + 32) - 1;
          else
            v14 = -1;
          _drm_dev_dbg(
            0,
            0,
            0,
            "enc%d intf%d pp%d unregistered %d\n",
            *(_DWORD *)(*(_QWORD *)a1 + 24LL),
            *(_DWORD *)(a1 + 672) - 1,
            v14,
            *v7);
        }
        result = 0;
        *v7 = -22;
      }
    }
  }
  else
  {
    printk(&unk_26FCAB, "sde_encoder_helper_unregister_irq");
    return 4294967274LL;
  }
  return result;
}
