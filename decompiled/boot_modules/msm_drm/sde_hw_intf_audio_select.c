__int64 __fastcall sde_hw_intf_audio_select(__int64 result, unsigned int a2)
{
  if ( result )
    return sde_reg_write(result, 0x408u, a2, "HDMI_DP_CORE_SELECT");
  return result;
}
