char **__fastcall cvp_get_drv_data(__int64 a1)
{
  __int64 matched; // x0
  char **v2; // x19
  __int64 node_opts_by_path; // x0
  __int64 v4; // x2
  __int64 *v5; // x8
  __int64 v6; // x8
  __int64 v7; // x3
  char *v9; // x9
  unsigned __int64 StatusReg; // x8
  unsigned int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_QWORD *)(a1 + 744) )
  {
    matched = of_match_node(&_mod_of__msm_cvp_dt_match_device_table);
    if ( matched )
    {
      v2 = *(char ***)(matched + 192);
      if ( !strcmp((const char *)(matched + 64), "qcom,waipio-cvp") )
      {
        v11 = 0;
        node_opts_by_path = of_find_node_opts_by_path("/memory", 0);
        if ( !node_opts_by_path
          || (of_property_read_variable_u32_array(node_opts_by_path, "ddr_device_type", &v11, 1, 0) & 0x80000000) != 0
          || (v4 = v11, v11 == -2) )
        {
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            StatusReg = _ReadStatusReg(SP_EL0);
            printk(&unk_93F8D, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
          }
          v5 = (__int64 *)(v2 + 3);
          v4 = 4294967294LL;
        }
        else
        {
          v5 = (__int64 *)(v2 + 3);
          v9 = v2[3];
          if ( (v11 & 0xFFFFFFFE) == 6 && v9 )
            *((_DWORD *)v9 + 3) = 15;
        }
        if ( (msm_cvp_debug & 0x100) != 0 && !msm_cvp_debug_out )
        {
          v6 = *v5;
          if ( v6 )
            v7 = *(unsigned int *)(v6 + 12);
          else
            v7 = 0xFFFFFFFFLL;
          printk(&unk_87D80, "core", v4, v7);
        }
      }
    }
    else
    {
      v2 = nullptr;
    }
  }
  else
  {
    v2 = &default_data;
  }
  _ReadStatusReg(SP_EL0);
  return v2;
}
