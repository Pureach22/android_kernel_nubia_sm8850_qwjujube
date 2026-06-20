__int64 __fastcall cvp_dsp_suspend(char a1)
{
  __int64 v1; // x19
  __int64 *v2; // x20
  __int64 *v3; // x21
  unsigned int v4; // w19
  __int64 v5; // x3
  unsigned __int64 StatusReg; // x8
  __int64 v7; // x0
  int v8; // w20
  unsigned __int64 v9; // x8
  unsigned __int64 v10; // x8
  unsigned __int64 v12; // x8
  int v13; // [xsp+Ch] [xbp-A4h] BYREF
  __int64 v14; // [xsp+10h] [xbp-A0h]
  __int64 v15; // [xsp+18h] [xbp-98h]
  __int64 v16; // [xsp+20h] [xbp-90h]
  __int64 v17; // [xsp+28h] [xbp-88h]
  __int64 v18; // [xsp+30h] [xbp-80h]
  __int64 v19; // [xsp+38h] [xbp-78h]
  __int64 v20; // [xsp+40h] [xbp-70h]
  __int64 v21; // [xsp+48h] [xbp-68h]
  __int64 v22; // [xsp+50h] [xbp-60h]
  __int64 v23; // [xsp+58h] [xbp-58h]
  __int64 v24; // [xsp+60h] [xbp-50h]
  __int64 v25; // [xsp+68h] [xbp-48h]
  __int64 v26; // [xsp+70h] [xbp-40h]
  __int64 v27; // [xsp+78h] [xbp-38h] BYREF
  _DWORD v28[6]; // [xsp+80h] [xbp-30h] BYREF
  int v29; // [xsp+98h] [xbp-18h]
  _QWORD v30[2]; // [xsp+A0h] [xbp-10h] BYREF

  v30[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25 = 0;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  v17 = 0;
  v18 = 0;
  v15 = 0;
  v16 = 0;
  v14 = 0;
  if ( (a1 & 1) != 0 )
    goto LABEL_9;
  v1 = *(_QWORD *)(cvp_driver + 48);
  if ( !v1 )
    goto LABEL_9;
  mutex_lock(*(_QWORD *)(cvp_driver + 48));
  v2 = (__int64 *)(v1 + 280);
  v3 = (__int64 *)(v1 + 280);
  do
    v3 = (__int64 *)*v3;
  while ( v3 != v2 && *((_DWORD *)v3 + 34) != 4 );
  mutex_unlock(v1);
  if ( v3 == v2 || dword_6C668 == 4 )
  {
LABEL_9:
    v13 = 1;
    mutex_lock(&gfa_cv);
    if ( dword_6C668 != 3 )
      goto LABEL_34;
    v29 = 0;
    memset(v28, 0, sizeof(v28));
    v4 = cvp_dsp_send_cmd_sync(&v13, v28);
    if ( v4 )
    {
LABEL_11:
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        printk(&unk_94846, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      }
      goto LABEL_35;
    }
    if ( v28[1] != 3 )
    {
      if ( v28[1] != 2 )
      {
LABEL_31:
        v4 = 0;
        dword_6C668 = 4;
        if ( (msm_cvp_debug & 0x800) == 0 || msm_cvp_debug_out )
          goto LABEL_35;
        printk(&unk_85BCA, "dsp", (unsigned int)nr_maps, v5);
LABEL_34:
        v4 = 0;
LABEL_35:
        mutex_unlock(&gfa_cv);
        goto LABEL_36;
      }
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v12 = _ReadStatusReg(SP_EL0);
        printk(&unk_97328, *(unsigned int *)(v12 + 1800), *(unsigned int *)(v12 + 1804), &unk_8E7CE);
      }
      v7 = mutex_unlock(&gfa_cv);
      v8 = cvp_reinit_dsp(v7);
      mutex_lock(&gfa_cv);
      if ( !v8 )
      {
        v4 = cvp_dsp_send_cmd_sync(&v13, v28);
        if ( v4 )
          goto LABEL_11;
        if ( v28[1] != 3 )
        {
          if ( v28[1] == 2 )
          {
            if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
            {
              v10 = _ReadStatusReg(SP_EL0);
              printk(&unk_97328, *(unsigned int *)(v10 + 1800), *(unsigned int *)(v10 + 1804), &unk_8E7CE);
            }
            goto LABEL_20;
          }
          goto LABEL_31;
        }
      }
    }
LABEL_20:
    dword_6C668 = 0;
    v27 = 1073741832;
    v30[0] = 0x700000003LL;
    if ( byte_6C670 == 1 )
    {
      if ( (unsigned int)qcom_scm_assign_mem(qword_6C678, (unsigned int)dword_6C680, &v27, v30, 1) )
      {
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          v9 = _ReadStatusReg(SP_EL0);
          printk(&unk_8D550, *(unsigned int *)(v9 + 1800), *(unsigned int *)(v9 + 1804), &unk_8E7CE);
        }
      }
      else
      {
        qword_6C678 = 0;
        dword_6C680 = 0;
        byte_6C670 = 0;
      }
    }
    v4 = -524;
    goto LABEL_35;
  }
  v4 = -16;
LABEL_36:
  _ReadStatusReg(SP_EL0);
  return v4;
}
