void *iris_hfi_wd_work_handler()
{
  void *result; // x0
  __int64 v1; // x8
  __int64 v2; // x19
  __int64 v3; // x8
  void (__fastcall *v4)(_QWORD); // x8
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v6; // x8
  _DWORD v7[190]; // [xsp+0h] [xbp-300h] BYREF
  __int64 v8; // [xsp+2F8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = memset(v7, 0, sizeof(v7));
  v1 = *(_QWORD *)(cvp_driver + 48);
  if ( !v1 )
    goto LABEL_11;
  if ( msm_cvp_hw_wd_recovery )
  {
    v2 = **(_QWORD **)(v1 + 256);
    if ( ((unsigned __int8)msm_cvp_debug & (msm_cvp_debug_out == 0)) != 0 )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_94CF7, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      if ( v2 )
        goto LABEL_5;
    }
    else if ( v2 )
    {
LABEL_5:
      v3 = *(_QWORD *)(v2 + 2512);
      if ( v3 )
      {
        v4 = *(void (__fastcall **)(_QWORD))(v3 + 72);
        if ( v4 )
        {
          if ( *((_DWORD *)v4 - 1) != -639316779 )
            __break(0x8228u);
          v4(v2);
        }
      }
    }
    v7[0] = 0;
    handle_sys_error(8, v7);
    result = (void *)enable_irq(*(unsigned int *)(*(_QWORD *)(v2 + 2168) + 4LL));
LABEL_11:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( ((unsigned __int8)msm_cvp_debug & (msm_cvp_debug_out == 0)) != 0 )
  {
    v6 = _ReadStatusReg(SP_EL0);
    result = (void *)printk(&unk_957D5, *(unsigned int *)(v6 + 1800), *(unsigned int *)(v6 + 1804), &unk_8E7CE);
  }
  __break(0x800u);
  return (void *)_unvote_buses(result);
}
