__int64 __fastcall sde_rm_hw_destroy(int a1, __int64 a2)
{
  if ( a1 > 7 )
  {
    if ( a1 > 10 )
    {
      switch ( a1 )
      {
        case 11:
          return sde_hw_vdc_destroy(a2);
        case 13:
          return sde_hw_qdss_destroy(a2);
        case 14:
          return sde_hw_dnsc_blur_destroy(a2);
      }
      return printk(&unk_246378, "_sde_rm_hw_destroy");
    }
    if ( a1 == 8 )
    {
      return sde_hw_intf_destroy(a2);
    }
    else if ( a1 == 9 )
    {
      return sde_hw_wb_destroy(a2);
    }
    else
    {
      return sde_hw_dsc_destroy(a2);
    }
  }
  else
  {
    if ( a1 <= 4 )
    {
      switch ( a1 )
      {
        case 2:
          return sde_hw_lm_destroy(a2);
        case 3:
          return sde_hw_dspp_destroy(a2);
        case 4:
          return sde_hw_ds_destroy(a2);
      }
      return printk(&unk_246378, "_sde_rm_hw_destroy");
    }
    if ( a1 == 5 )
    {
      return sde_hw_ctl_destroy(a2);
    }
    else if ( a1 == 6 )
    {
      return sde_hw_cdm_destroy(a2);
    }
    else
    {
      return sde_hw_pingpong_destroy(a2);
    }
  }
}
