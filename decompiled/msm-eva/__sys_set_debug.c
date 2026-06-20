__int64 __fastcall _sys_set_debug(__int64 a1, unsigned int a2)
{
  __int64 v4; // x0
  __int64 v5; // x19
  __int64 v6; // x8
  _DWORD *v7; // x8
  unsigned int v8; // w20
  unsigned __int64 StatusReg; // x8

  v4 = _kmalloc_cache_noprof(printk, 3520, 24);
  v5 = v4;
  v6 = *(_QWORD *)(a1 + 2416);
  if ( !v6 )
    goto LABEL_15;
  v7 = *(_DWORD **)(v6 + 32);
  if ( !v7 )
    goto LABEL_15;
  if ( *(v7 - 1) != 1706540593 )
    __break(0x8228u);
  if ( ((unsigned int (__fastcall *)(__int64, _QWORD))v7)(v4, a2) )
  {
    v8 = -39;
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_92EB0, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
    }
  }
  else
  {
LABEL_15:
    if ( (unsigned int)_iface_cmdq_write(a1, v5) )
      v8 = -39;
    else
      v8 = 0;
  }
  kfree(v5);
  return v8;
}
