_QWORD *__fastcall dsi_display_setup_ops(_QWORD *result)
{
  result[217] = dsi_display_hfi_prepare;
  result[220] = dsi_display_hfi_enable;
  result[223] = dsi_display_hfi_post_enable;
  result[226] = dsi_display_hfi_pre_disable;
  result[229] = dsi_display_hfi_disable;
  result[232] = dsi_display_hfi_unprepare;
  result[235] = dsi_hfi_misr_setup;
  result[238] = dsi_hfi_misr_read;
  result[216] = dsi_display_prepare;
  result[219] = dsi_display_enable;
  result[222] = dsi_display_post_enable;
  result[225] = dsi_display_pre_disable;
  result[228] = &dsi_display_disable;
  result[231] = dsi_display_unprepare;
  return result;
}
