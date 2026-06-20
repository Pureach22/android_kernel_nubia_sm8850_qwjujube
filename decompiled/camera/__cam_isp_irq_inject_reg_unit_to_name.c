const char *__fastcall _cam_isp_irq_inject_reg_unit_to_name(int a1, unsigned int a2)
{
  const char *v2; // x3
  char *v3; // x19
  __int64 v4; // x3
  const char *v5; // x2

  if ( a1 == 7 )
  {
    if ( a2 == 500 )
    {
      v3 = reg_str;
      v5 = "CAM_SFE_IRQ_BUS_RD_REG_STATUS%u";
    }
    else
    {
      if ( a2 != 400 )
        return "Invalid reg_unit";
      v3 = reg_str;
      v5 = "CAM_SFE_IRQ_BUS_WR_REG_STATUS%u";
    }
    v4 = 0;
    goto LABEL_16;
  }
  if ( a1 == 2 )
  {
    v4 = a2 - 200;
    if ( (unsigned int)v4 <= 1 )
    {
      v3 = reg_str;
      if ( dword_3A8694 == 65555 )
      {
        scnprintf(reg_str, 64, "CAM_MC_TFE_IRQ_BUS_REG_STATUS%u", v4);
        return v3;
      }
      v5 = "CAM_IFE_IRQ_BUS_VER3_REG_STATUS%u";
LABEL_16:
      scnprintf(reg_str, 64, v5, v4);
      return v3;
    }
    return "Invalid reg_unit";
  }
  if ( a1 || a2 > 0xF )
    return "Invalid reg_unit";
  v2 = cam_ife_csid_get_irq_reg_tag_ptr()[a2];
  v3 = reg_str;
  scnprintf(reg_str, 64, "CAM_IFE_CSID_IRQ_REG_%s", v2);
  return v3;
}
