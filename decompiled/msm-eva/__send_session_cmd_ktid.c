__int64 __fastcall _send_session_cmd_ktid(_QWORD *a1)
{
  __int64 v1; // x5
  _QWORD *v2; // x8
  __int64 v3; // x8
  __int64 (__fastcall *v4)(_QWORD); // x8
  unsigned int v6; // w0
  unsigned int v7; // w8
  unsigned __int64 v9; // x8
  unsigned __int64 StatusReg; // x9
  unsigned int v11; // w19
  _QWORD v12[9]; // [xsp+8h] [xbp-48h] BYREF

  v12[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = a1[4];
  memset(v12, 0, 64);
  if ( v1 )
  {
    v2 = (_QWORD *)v1;
    do
    {
      v2 = (_QWORD *)*v2;
      if ( v2 == (_QWORD *)v1 )
        goto LABEL_15;
    }
    while ( v2 != a1 );
    v3 = *(_QWORD *)(v1 + 2416);
    if ( !v3 || (v4 = *(__int64 (__fastcall **)(_QWORD))(v3 + 104)) == nullptr )
    {
LABEL_12:
      if ( (unsigned int)_iface_cmdq_write(v1, (unsigned int *)v12) )
        v7 = -39;
      else
        v7 = 0;
      goto LABEL_18;
    }
    if ( *((_DWORD *)v4 - 1) != -606762188 )
      __break(0x8228u);
    v6 = v4(v12);
    if ( v6 == -1 )
    {
      v7 = 0;
      goto LABEL_18;
    }
    v7 = v6;
    if ( !v6 )
    {
      v1 = a1[4];
      goto LABEL_12;
    }
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      v11 = v6;
      printk(&unk_82E9F, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      v7 = v11;
    }
  }
  else
  {
LABEL_15:
    v7 = -104;
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      v9 = _ReadStatusReg(SP_EL0);
      printk(&unk_963E0, *(unsigned int *)(v9 + 1800), *(unsigned int *)(v9 + 1804), "warn");
      v7 = -104;
    }
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return v7;
}
