__int64 cvp_reinit_dsp()
{
  __int64 v0; // x8
  __int64 *v1; // x8
  __int64 v2; // x21
  unsigned int v3; // w19
  __int64 v4; // x3
  __int64 v5; // x20
  __int64 v6; // x21
  unsigned int v7; // w0
  int v8; // w8
  unsigned __int64 v9; // x8
  __int64 v10; // x1
  __int64 v11; // x2
  void *v12; // x0
  const char *v13; // x3
  unsigned __int64 v14; // x8
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x8
  unsigned int v19; // w0
  unsigned __int64 v20; // x8
  unsigned __int64 v21; // x8
  unsigned __int64 v22; // x8
  __int64 v23; // [xsp+0h] [xbp-40h] BYREF
  _QWORD v24[3]; // [xsp+8h] [xbp-38h] BYREF
  int v25; // [xsp+20h] [xbp-20h]
  _QWORD v26[3]; // [xsp+28h] [xbp-18h] BYREF

  v26[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v0 = *(_QWORD *)(cvp_driver + 48);
  if ( v0 && (v1 = *(__int64 **)(v0 + 256)) != nullptr )
  {
    v2 = *v1;
    if ( !*v1 )
    {
      v3 = -22;
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        printk(&unk_89BB3, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      }
      goto LABEL_19;
    }
    v3 = cvp_dsp_shutdown();
    if ( !v3 )
    {
      cvp_remove_dsp_sessions();
      if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
      {
        v18 = _ReadStatusReg(SP_EL0);
        printk(&unk_9689C, *(unsigned int *)(v18 + 1800), *(unsigned int *)(v18 + 1804), "warn");
      }
      mutex_lock(&gfa_cv);
      if ( !*(_QWORD *)(v2 + 320) )
      {
        v3 = -22;
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          v17 = _ReadStatusReg(SP_EL0);
          printk(&unk_8A304, *(unsigned int *)(v17 + 1800), *(unsigned int *)(v17 + 1804), &unk_8E7CE);
        }
        goto LABEL_47;
      }
      v5 = *(_QWORD *)(v2 + 408);
      if ( v5 && (v6 = *(unsigned int *)(v2 + 416), (_DWORD)v6) )
      {
        v23 = 8;
        v26[0] = 0x700000003LL;
        v26[1] = 0x70000001ELL;
        if ( (byte_6C670 & 1) == 0 )
        {
          v7 = qcom_scm_assign_mem(v5, v6, &v23, v26, 2);
          if ( v7 )
          {
            v8 = msm_cvp_debug_out;
            v3 = v7;
            if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
            {
              v21 = _ReadStatusReg(SP_EL0);
              printk(&unk_8D550, *(unsigned int *)(v21 + 1800), *(unsigned int *)(v21 + 1804), &unk_8E7CE);
              v8 = msm_cvp_debug_out;
              if ( (msm_cvp_debug & 1) == 0 )
                goto LABEL_47;
            }
            else if ( (msm_cvp_debug & 1) == 0 )
            {
              goto LABEL_47;
            }
            if ( !v8 )
            {
              v9 = _ReadStatusReg(SP_EL0);
              v10 = *(unsigned int *)(v9 + 1800);
              v11 = *(unsigned int *)(v9 + 1804);
              v12 = &unk_8AD34;
              v13 = (const char *)&unk_8E7CE;
LABEL_42:
              printk(v12, v10, v11, v13);
            }
LABEL_47:
            mutex_unlock(&gfa_cv);
            goto LABEL_19;
          }
          qword_6C678 = v5;
          dword_6C680 = v6;
          byte_6C670 = 1;
        }
        v25 = 0;
        memset(v24, 0, sizeof(v24));
        v19 = cvp_dsp_send_cmd_hfi_queue(v5, (unsigned int)v6, v24);
        if ( v19 )
        {
          v3 = v19;
          if ( (msm_cvp_debug & 2) == 0 || msm_cvp_debug_out )
            goto LABEL_47;
          v20 = _ReadStatusReg(SP_EL0);
          v10 = *(unsigned int *)(v20 + 1800);
          v11 = *(unsigned int *)(v20 + 1804);
          v12 = &unk_8E37B;
          v13 = "warn";
          goto LABEL_42;
        }
        if ( HIDWORD(v24[0]) )
        {
          v3 = -19;
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            v22 = _ReadStatusReg(SP_EL0);
            printk(&unk_8C13F, *(unsigned int *)(v22 + 1800), *(unsigned int *)(v22 + 1804), &unk_8E7CE);
          }
          goto LABEL_47;
        }
      }
      else if ( (msm_cvp_debug & 0x800) != 0 && !msm_cvp_debug_out )
      {
        printk(&unk_84834, "dsp", "__reinit_dsp", v4);
      }
      mutex_unlock(&gfa_cv);
      v3 = 0;
      goto LABEL_26;
    }
  }
  else
  {
    v3 = -22;
  }
LABEL_19:
  mutex_lock(&gfa_cv);
  dword_6C668 = 0;
  v24[0] = 1073741832;
  v26[0] = 0x700000003LL;
  if ( byte_6C670 == 1 )
  {
    if ( (unsigned int)qcom_scm_assign_mem(qword_6C678, (unsigned int)dword_6C680, v24, v26, 1) )
    {
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v14 = _ReadStatusReg(SP_EL0);
        printk(&unk_8D550, *(unsigned int *)(v14 + 1800), *(unsigned int *)(v14 + 1804), &unk_8E7CE);
      }
    }
    else
    {
      qword_6C678 = 0;
      dword_6C680 = 0;
      byte_6C670 = 0;
    }
  }
  mutex_unlock(&gfa_cv);
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return v3;
}
