__int64 __fastcall sde_hw_rc_check_mask(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  int v8; // w3
  __int64 v9; // x19
  __int64 result; // x0
  unsigned int v11; // w3
  unsigned int v12; // w19
  char v13; // [xsp+0h] [xbp+0h]

  if ( !a1 || !a2 )
  {
    printk(&unk_26FEB0, "sde_hw_rc_check_mask");
    return 4294967274LL;
  }
  v8 = *(_DWORD *)(a2 + 8);
  if ( v8 != 21856 )
  {
    if ( !v8 && !*(_QWORD *)a2 )
    {
      if ( (_drm_debug & 4) != 0 )
      {
        v9 = a1;
        _drm_dev_dbg(0, 0, 0, "RC feature disabled, skip mask checks\n");
        a1 = v9;
      }
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "sde_hw_rc_check_mask",
        372,
        -1,
        *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 536LL),
        -1059143953,
        a7,
        a8,
        v13);
      return 0;
    }
LABEL_15:
    printk(&unk_247077, "sde_hw_rc_check_mask");
    return 4294967274LL;
  }
  if ( !*(_QWORD *)a2 )
    goto LABEL_15;
  v11 = *(_DWORD *)(a2 + 28);
  if ( v11 <= 4 && ((1 << v11) & 0x16) != 0 )
  {
    result = sde_hw_rc_check_mask_cfg();
    if ( (_DWORD)result )
    {
      v12 = result;
      printk(&unk_254AA4, "sde_hw_rc_check_mask");
      return v12;
    }
  }
  else
  {
    printk(&unk_216F2A, "sde_hw_rc_check_mask");
    return 4294967274LL;
  }
  return result;
}
