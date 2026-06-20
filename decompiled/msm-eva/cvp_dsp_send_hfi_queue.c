void __fastcall cvp_dsp_send_hfi_queue(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  __int64 *v5; // x8
  __int64 v6; // x19
  __int64 v7; // x3
  __int64 v8; // x20
  __int64 v9; // x21
  int v10; // w8
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x8
  unsigned __int64 StatusReg; // x8
  __int64 v14; // x3
  unsigned __int64 v15; // x8
  __int64 v16; // x1
  __int64 v17; // x2
  void *v18; // x0
  unsigned __int64 v19; // x8
  unsigned __int64 v20; // x8
  unsigned __int64 v21; // x8
  unsigned __int64 v22; // x8
  unsigned __int64 v23; // x8
  unsigned __int64 v24; // x8
  __int64 v25; // [xsp+0h] [xbp-40h] BYREF
  _QWORD v26[3]; // [xsp+8h] [xbp-38h] BYREF
  int v27; // [xsp+20h] [xbp-20h]
  _QWORD v28[3]; // [xsp+28h] [xbp-18h] BYREF

  v28[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27 = 0;
  v4 = *(_QWORD *)(cvp_driver + 48);
  memset(v26, 0, sizeof(v26));
  if ( v4 )
  {
    v5 = *(__int64 **)(v4 + 256);
    if ( v5 )
    {
      v6 = *v5;
      if ( *v5 )
      {
        if ( (msm_cvp_debug & 0x800) != 0 && !msm_cvp_debug_out )
          printk(&unk_881DF, "dsp", "cvp_dsp_send_hfi_queue", a4);
        mutex_lock(v6 + 80);
        mutex_lock(&gfa_cv);
        if ( !*(_QWORD *)(v6 + 320) )
        {
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            StatusReg = _ReadStatusReg(SP_EL0);
            printk(&unk_8A304, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
          }
          goto LABEL_68;
        }
        v8 = *(_QWORD *)(v6 + 408);
        if ( !v8 || (v9 = *(unsigned int *)(v6 + 416), !(_DWORD)v9) )
        {
          if ( (msm_cvp_debug & 0x800) != 0 && !msm_cvp_debug_out )
            printk(&unk_84834, "dsp", "cvp_dsp_send_hfi_queue", v7);
          goto LABEL_68;
        }
        if ( dword_6C668 != 2 && dword_6C668 != 5 )
        {
          if ( (msm_cvp_debug & 0x800) != 0 && !msm_cvp_debug_out )
            printk(&unk_8C081, "dsp", "cvp_dsp_send_hfi_queue", (unsigned int)dword_6C668);
          goto LABEL_68;
        }
        if ( (msm_cvp_debug & 0x800) != 0 && !msm_cvp_debug_out )
          printk(&unk_865F0, "dsp", (unsigned int)dword_6C668, (unsigned int)dword_6C668);
        v25 = 8;
        v28[0] = 0x700000003LL;
        v28[1] = 0x70000001ELL;
        if ( (byte_6C670 & 1) == 0 )
        {
          if ( (unsigned int)qcom_scm_assign_mem(v8, v9, &v25, v28, 2) )
          {
            v10 = msm_cvp_debug_out;
            if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
            {
              v22 = _ReadStatusReg(SP_EL0);
              printk(&unk_8D550, *(unsigned int *)(v22 + 1800), *(unsigned int *)(v22 + 1804), &unk_8E7CE);
              v10 = msm_cvp_debug_out;
              if ( (msm_cvp_debug & 1) != 0 )
              {
LABEL_20:
                if ( !v10 )
                {
                  v11 = _ReadStatusReg(SP_EL0);
                  printk(&unk_8AD34, *(unsigned int *)(v11 + 1800), *(unsigned int *)(v11 + 1804), &unk_8E7CE);
                }
              }
            }
            else if ( (msm_cvp_debug & 1) != 0 )
            {
              goto LABEL_20;
            }
LABEL_68:
            mutex_unlock(&gfa_cv);
LABEL_69:
            mutex_unlock(v6 + 80);
            goto LABEL_70;
          }
          qword_6C678 = v8;
          dword_6C680 = v9;
          byte_6C670 = 1;
        }
        if ( dword_6C668 == 2 )
        {
          cvp_dsp_init_hfi_queue_hdr(v6);
          if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
          {
            v21 = _ReadStatusReg(SP_EL0);
            printk(&unk_8CB0A, *(unsigned int *)(v21 + 1800), *(unsigned int *)(v21 + 1804), "warn");
          }
        }
        if ( (unsigned int)cvp_dsp_send_cmd_hfi_queue(v8, (unsigned int)v9, v26) )
        {
          if ( (msm_cvp_debug & 2) == 0 || msm_cvp_debug_out )
            goto LABEL_68;
          v15 = _ReadStatusReg(SP_EL0);
          v16 = *(unsigned int *)(v15 + 1800);
          v17 = *(unsigned int *)(v15 + 1804);
          v18 = &unk_8E37B;
        }
        else
        {
          if ( HIDWORD(v26[0]) != 5 )
          {
            if ( (HIDWORD(v26[0]) & 0xFFFFFFFE) == 2 )
            {
              if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
              {
                v23 = _ReadStatusReg(SP_EL0);
                printk(&unk_84860, *(unsigned int *)(v23 + 1800), *(unsigned int *)(v23 + 1804), &unk_8E7CE);
              }
              dword_6C668 = 0;
              cvp_hyp_assign_from_dsp();
            }
            else
            {
              if ( HIDWORD(v26[0]) == 4 )
              {
                if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
                {
                  v24 = _ReadStatusReg(SP_EL0);
                  printk(&unk_87B12, *(unsigned int *)(v24 + 1800), *(unsigned int *)(v24 + 1804), &unk_8E7CE);
                }
                mutex_unlock(&gfa_cv);
                if ( (unsigned int)cvp_reinit_dsp() )
                {
                  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
                  {
                    v20 = _ReadStatusReg(SP_EL0);
                    printk(&unk_90631, *(unsigned int *)(v20 + 1800), *(unsigned int *)(v20 + 1804), &unk_8E7CE);
                  }
                  goto LABEL_69;
                }
                mutex_lock(&gfa_cv);
              }
              if ( (msm_cvp_debug & 0x800) != 0 && !msm_cvp_debug_out )
                printk(&unk_88640, "dsp", "cvp_dsp_send_hfi_queue", v14);
              dword_6C668 = 3;
            }
            goto LABEL_68;
          }
          if ( (msm_cvp_debug & 2) == 0 || msm_cvp_debug_out )
            goto LABEL_68;
          v19 = _ReadStatusReg(SP_EL0);
          v16 = *(unsigned int *)(v19 + 1800);
          v17 = *(unsigned int *)(v19 + 1804);
          v18 = &unk_8D4D5;
        }
        printk(v18, v16, v17, "warn");
        goto LABEL_68;
      }
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v12 = _ReadStatusReg(SP_EL0);
        printk(&unk_89BB3, *(unsigned int *)(v12 + 1800), *(unsigned int *)(v12 + 1804), &unk_8E7CE);
      }
    }
  }
LABEL_70:
  _ReadStatusReg(SP_EL0);
}
