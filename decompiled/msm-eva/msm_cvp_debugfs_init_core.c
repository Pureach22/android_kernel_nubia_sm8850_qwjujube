unsigned __int64 __fastcall msm_cvp_debugfs_init_core(__int64 a1, __int64 a2)
{
  unsigned __int64 dir; // x0
  unsigned __int64 v5; // x19
  unsigned __int64 v6; // x8
  unsigned __int64 v7; // x8
  unsigned __int64 StatusReg; // x8
  __int64 v9; // x1
  __int64 v10; // x2
  void *v11; // x0
  unsigned __int64 v12; // x8
  unsigned __int64 v13; // x8
  unsigned __int64 v14; // x8
  unsigned __int64 v16; // x8
  _QWORD v17[6]; // [xsp+0h] [xbp-40h] BYREF
  __int16 v18; // [xsp+30h] [xbp-10h]
  __int64 v19; // [xsp+38h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  memset(v17, 0, sizeof(v17));
  if ( a1 )
  {
    snprintf((char *)v17, 0x32u, "core%d", 0);
    dir = debugfs_create_dir(v17, a2);
    if ( dir && (v5 = dir, dir < 0xFFFFFFFFFFFFF001LL) )
    {
      if ( debugfs_create_file("info", 292, dir, a1, &core_info_fops) )
      {
        if ( debugfs_create_file("trigger_ssr", 128, v5, a1, &ssr_fops) )
        {
          if ( debugfs_create_file("clock_rate", 420, v5, 0, &clk_rate_fops) )
          {
            if ( debugfs_create_file("dsp_debug_level", 420, v5, 0, &dsp_debug_fops) )
            {
              if ( debugfs_create_file("max_ssr_allowed", 420, v5, 0, &max_ssr_fops) )
              {
                if ( debugfs_create_file("ssr_stall", 420, v5, 0, &ssr_stall_fops) )
                {
                  debugfs_create_u32("hw_wd_recovery", 420, v5, &msm_cvp_hw_wd_recovery);
                  debugfs_create_u32("smmu_fault_recovery", 420, v5, &msm_cvp_smmu_fault_recovery);
                  debugfs_create_u32("sw_dbg_buf_dump", 420, v5, &msm_cvp_sw_dbg_buf_dump);
                  debugfs_create_u32("session_error_recovery", 420, v5, &msm_cvp_session_error_recovery);
                  debugfs_create_u32("hw_hang_recovery", 420, v5, &msm_cvp_hw_hang_recovery);
                  if ( !debugfs_create_file("session_info", 292, v5, a1, &session_info_fops)
                    && (msm_cvp_debug & 1) != 0
                    && !msm_cvp_debug_out )
                  {
LABEL_25:
                    StatusReg = _ReadStatusReg(SP_EL0);
                    v9 = *(unsigned int *)(StatusReg + 1800);
                    v10 = *(unsigned int *)(StatusReg + 1804);
                    v11 = &unk_83E44;
LABEL_26:
                    printk(v11, v9, v10, &unk_8E7CE);
                  }
                }
                else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
                {
                  v16 = _ReadStatusReg(SP_EL0);
                  v9 = *(unsigned int *)(v16 + 1800);
                  v10 = *(unsigned int *)(v16 + 1804);
                  v11 = &unk_8C01F;
                  goto LABEL_26;
                }
              }
              else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
              {
                v14 = _ReadStatusReg(SP_EL0);
                v9 = *(unsigned int *)(v14 + 1800);
                v10 = *(unsigned int *)(v14 + 1804);
                v11 = &unk_8E2C4;
                goto LABEL_26;
              }
            }
            else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
            {
              v13 = _ReadStatusReg(SP_EL0);
              v9 = *(unsigned int *)(v13 + 1800);
              v10 = *(unsigned int *)(v13 + 1804);
              v11 = &unk_972EA;
              goto LABEL_26;
            }
          }
          else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            v12 = _ReadStatusReg(SP_EL0);
            v9 = *(unsigned int *)(v12 + 1800);
            v10 = *(unsigned int *)(v12 + 1804);
            v11 = &unk_8A278;
            goto LABEL_26;
          }
        }
        else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          goto LABEL_25;
        }
      }
      else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        goto LABEL_25;
      }
    }
    else
    {
      v5 = 0;
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v7 = _ReadStatusReg(SP_EL0);
        printk(&unk_8698D, *(unsigned int *)(v7 + 1800), *(unsigned int *)(v7 + 1804), &unk_8E7CE);
        v5 = 0;
      }
    }
  }
  else
  {
    v5 = 0;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v6 = _ReadStatusReg(SP_EL0);
      printk(&unk_8E291, *(unsigned int *)(v6 + 1800), *(unsigned int *)(v6 + 1804), &unk_8E7CE);
      v5 = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return v5;
}
