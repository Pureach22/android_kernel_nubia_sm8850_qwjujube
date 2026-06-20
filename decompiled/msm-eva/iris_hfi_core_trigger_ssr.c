__int64 __fastcall iris_hfi_core_trigger_ssr(__int64 a1, unsigned int a2)
{
  __int64 v4; // x8
  _DWORD *v5; // x8
  unsigned int v6; // w0
  unsigned int v7; // w20
  unsigned __int64 StatusReg; // x8
  __int64 result; // x0
  unsigned __int64 v10; // x8
  __int64 v11; // [xsp+8h] [xbp-18h] BYREF
  int v12; // [xsp+10h] [xbp-10h]
  __int64 v13; // [xsp+18h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = 0;
  v11 = 0;
  if ( a1 )
  {
    if ( (unsigned int)mutex_trylock(a1 + 80) )
    {
      v4 = *(_QWORD *)(a1 + 2416);
      if ( !v4 )
        goto LABEL_23;
      v5 = *(_DWORD **)(v4 + 80);
      if ( !v5 )
        goto LABEL_23;
      if ( *(v5 - 1) != -1622986047 )
        __break(0x8228u);
      v6 = ((__int64 (__fastcall *)(_QWORD, __int64 *))v5)(a2, &v11);
      if ( v6 )
      {
        if ( (msm_cvp_debug & 1) != 0 )
        {
          v7 = v6;
          if ( !msm_cvp_debug_out )
          {
            StatusReg = _ReadStatusReg(SP_EL0);
            printk(&unk_8EA26, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
          }
        }
        else
        {
          v7 = v6;
        }
      }
      else
      {
LABEL_23:
        if ( (unsigned int)_iface_cmdq_write(a1, (unsigned int *)&v11) )
          v7 = -39;
        else
          v7 = 0;
      }
      mutex_unlock(a1 + 80);
      result = v7;
    }
    else
    {
      result = 4294967285LL;
    }
  }
  else
  {
    result = 4294967277LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v10 = _ReadStatusReg(SP_EL0);
      printk(&unk_8A7C9, *(unsigned int *)(v10 + 1800), *(unsigned int *)(v10 + 1804), &unk_8E7CE);
      result = 4294967277LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
