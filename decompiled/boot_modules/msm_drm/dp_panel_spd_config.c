__int64 __fastcall dp_panel_spd_config(__int64 a1)
{
  void (*v1)(void); // x8
  __int64 v2; // x0
  unsigned __int64 StatusReg; // x19
  __int64 v5; // x0
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    if ( *(_DWORD *)(a1 + 912) >= 2u )
    {
      ipc_log_context = get_ipc_log_context(a1);
      ipc_log_string(
        ipc_log_context,
        "[e][%-4d]invalid stream id:%d\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        *(_DWORD *)(a1 + 912));
      printk(&unk_26EFE9, "dp_panel_spd_config");
      return 4294967274LL;
    }
    else
    {
      if ( (*(_BYTE *)(a1 + 873) & 1) != 0 )
      {
        *(_QWORD *)(*(_QWORD *)(a1 + 1216) + 16LL) = a1 + 1240;
        *(_QWORD *)(*(_QWORD *)(a1 + 1216) + 24LL) = a1 + 1248;
        *(_DWORD *)(*(_QWORD *)(a1 + 1216) + 204LL) = *(_DWORD *)(a1 + 912);
        v1 = *(void (**)(void))(*(_QWORD *)(a1 + 1216) + 632LL);
        if ( *((_DWORD *)v1 - 1) != 440525842 )
          __break(0x8228u);
        v1();
      }
      else
      {
        v2 = get_ipc_log_context(a1);
        StatusReg = _ReadStatusReg(SP_EL0);
        ipc_log_string(v2, "[d][%-4d]SPD Infoframe not enabled\n", *(_DWORD *)(StatusReg + 1800));
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]SPD Infoframe not enabled\n", *(_DWORD *)(StatusReg + 1800));
      }
      return 0;
    }
  }
  else
  {
    v5 = get_ipc_log_context(0);
    ipc_log_string(v5, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_panel_spd_config");
    return 4294967274LL;
  }
}
