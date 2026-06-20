__int64 __fastcall _prepare_pc(__int64 a1)
{
  __int64 v2; // x8
  __int64 (__fastcall *v3)(_QWORD); // x8
  __int64 result; // x0
  unsigned int v5; // w19
  void *v6; // x0
  unsigned __int64 StatusReg; // x8
  _QWORD v8[2]; // [xsp+0h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 2416);
  v8[0] = 0;
  if ( !v2 )
    goto LABEL_9;
  v3 = *(__int64 (__fastcall **)(_QWORD))(v2 + 8);
  if ( !v3 )
    goto LABEL_9;
  if ( *((_DWORD *)v3 - 1) != -2065584446 )
    __break(0x8228u);
  result = v3(v8);
  if ( (_DWORD)result )
  {
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v5 = result;
      v6 = &unk_8B120;
      StatusReg = _ReadStatusReg(SP_EL0);
LABEL_14:
      printk(v6, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      result = v5;
    }
  }
  else
  {
LABEL_9:
    result = _iface_cmdq_write(a1, v8);
    if ( (_DWORD)result )
    {
      result = 4294967257LL;
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v5 = -39;
        v6 = &unk_9091C;
        StatusReg = _ReadStatusReg(SP_EL0);
        goto LABEL_14;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
