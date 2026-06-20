__int64 __fastcall _core_release_resource(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 (__fastcall *v4)(_QWORD); // x8
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  unsigned int v7; // w19
  unsigned __int64 v8; // x8
  _QWORD v9[12]; // [xsp+0h] [xbp-70h] BYREF
  int v10; // [xsp+60h] [xbp-10h]
  __int64 v11; // [xsp+68h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = 0;
  memset(v9, 0, sizeof(v9));
  if ( a2 )
  {
    v2 = *(_QWORD *)(a1 + 2416);
    if ( !v2 )
      goto LABEL_19;
    v4 = *(__int64 (__fastcall **)(_QWORD))(v2 + 56);
    if ( !v4 )
      goto LABEL_19;
    if ( *((_DWORD *)v4 - 1) != -109492491 )
      __break(0x8228u);
    result = v4(v9);
    if ( (_DWORD)result )
    {
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        v7 = result;
        printk(&unk_8B15A, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
        result = v7;
      }
    }
    else
    {
LABEL_19:
      if ( (unsigned int)_iface_cmdq_write(a1, (unsigned int *)v9) )
        result = 4294967257LL;
      else
        result = 0;
    }
  }
  else
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v8 = _ReadStatusReg(SP_EL0);
      printk(&unk_9095F, *(unsigned int *)(v8 + 1800), *(unsigned int *)(v8 + 1804), &unk_8E7CE);
      result = 4294967274LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
