__int64 cvp_dsp_shutdown()
{
  unsigned int v0; // w0
  unsigned int v1; // w19
  unsigned __int64 v2; // x8
  unsigned __int64 StatusReg; // x8
  int v5; // [xsp+Ch] [xbp-A4h] BYREF
  __int64 v6; // [xsp+10h] [xbp-A0h]
  __int64 v7; // [xsp+18h] [xbp-98h]
  __int64 v8; // [xsp+20h] [xbp-90h]
  __int64 v9; // [xsp+28h] [xbp-88h]
  __int64 v10; // [xsp+30h] [xbp-80h]
  __int64 v11; // [xsp+38h] [xbp-78h]
  __int64 v12; // [xsp+40h] [xbp-70h]
  __int64 v13; // [xsp+48h] [xbp-68h]
  __int64 v14; // [xsp+50h] [xbp-60h]
  __int64 v15; // [xsp+58h] [xbp-58h]
  __int64 v16; // [xsp+60h] [xbp-50h]
  __int64 v17; // [xsp+68h] [xbp-48h]
  __int64 v18; // [xsp+70h] [xbp-40h]
  __int64 v19; // [xsp+78h] [xbp-38h] BYREF
  _BYTE v20[28]; // [xsp+84h] [xbp-2Ch] BYREF
  _QWORD v21[2]; // [xsp+A0h] [xbp-10h] BYREF

  v21[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 0;
  v18 = 0;
  v15 = 0;
  v16 = 0;
  v13 = 0;
  v14 = 0;
  v11 = 0;
  v12 = 0;
  v9 = 0;
  v10 = 0;
  v7 = 0;
  v8 = 0;
  v6 = 0;
  v5 = 3;
  mutex_lock(&gfa_cv);
  if ( !dword_6C668 )
    goto LABEL_16;
  dword_6C668 = 5;
  v0 = cvp_dsp_send_cmd_sync(&v5, (__int64)v20);
  if ( !v0 )
  {
    v19 = 1073741832;
    v21[0] = 0x700000003LL;
    if ( byte_6C670 == 1 )
    {
      v1 = qcom_scm_assign_mem(qword_6C678, (unsigned int)dword_6C680, &v19, v21, 1);
      if ( v1 )
      {
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          goto LABEL_10;
        goto LABEL_17;
      }
LABEL_18:
      qword_6C678 = 0;
      dword_6C680 = 0;
      byte_6C670 = 0;
      goto LABEL_17;
    }
LABEL_16:
    v1 = 0;
    goto LABEL_17;
  }
  v1 = v0;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    printk(&unk_97362, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
  }
  v19 = 1073741832;
  v21[0] = 0x700000003LL;
  if ( byte_6C670 != 1 )
    goto LABEL_17;
  if ( !(unsigned int)qcom_scm_assign_mem(qword_6C678, (unsigned int)dword_6C680, &v19, v21, 1) )
    goto LABEL_18;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
LABEL_10:
    v2 = _ReadStatusReg(SP_EL0);
    printk(&unk_8D550, *(unsigned int *)(v2 + 1800), *(unsigned int *)(v2 + 1804), &unk_8E7CE);
  }
LABEL_17:
  mutex_unlock(&gfa_cv);
  _ReadStatusReg(SP_EL0);
  return v1;
}
