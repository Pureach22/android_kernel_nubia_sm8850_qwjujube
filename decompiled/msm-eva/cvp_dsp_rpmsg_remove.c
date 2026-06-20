__int64 cvp_dsp_rpmsg_remove()
{
  int v0; // w8
  int v1; // w23
  unsigned __int64 v2; // x8
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v5; // x8
  unsigned __int64 v6; // x8
  __int64 v7; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v8[2]; // [xsp+10h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    printk(&unk_8A368, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
  }
  mutex_lock(&unk_6C600);
  if ( (_DWORD)qword_6C7A8 != -1159857458 )
  {
    v0 = -99;
    do
    {
      v1 = v0;
      mutex_unlock(&unk_6C600);
      usleep_range_state(1000, 5000, 2);
      mutex_lock(&unk_6C600);
      if ( !v1 )
        break;
      v0 = v1 + 1;
    }
    while ( (_DWORD)qword_6C7A8 != -1159857458 );
    if ( !v1 && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v6 = _ReadStatusReg(SP_EL0);
      printk(&unk_8E4EF, *(unsigned int *)(v6 + 1800), *(unsigned int *)(v6 + 1804), &unk_8E7CE);
    }
  }
  mutex_lock(&gfa_cv);
  v7 = 1073741832;
  v8[0] = 0x700000003LL;
  if ( byte_6C670 == 1 )
  {
    if ( (unsigned int)qcom_scm_assign_mem(qword_6C678, (unsigned int)dword_6C680, &v7, v8, 1) )
    {
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v2 = _ReadStatusReg(SP_EL0);
        printk(&unk_8D550, *(unsigned int *)(v2 + 1800), *(unsigned int *)(v2 + 1804), &unk_8E7CE);
      }
    }
    else
    {
      qword_6C678 = 0;
      dword_6C680 = 0;
      byte_6C670 = 0;
    }
  }
  qword_6C660 = 0;
  dword_6C668 = 1;
  mutex_unlock(&gfa_cv);
  mutex_unlock(&unk_6C600);
  usleep_range_state(20000, 50000, 2);
  result = cvp_remove_dsp_sessions();
  if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
  {
    v5 = _ReadStatusReg(SP_EL0);
    result = printk(&unk_82B6B, *(unsigned int *)(v5 + 1800), *(unsigned int *)(v5 + 1804), "warn");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
