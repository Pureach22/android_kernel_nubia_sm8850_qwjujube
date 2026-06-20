__int64 __fastcall setting_nolp_work_handler(__int64 a1, __int64 a2)
{
  __int64 v2; // x19

  v2 = a1 - 2560;
  if ( a1 == 2560 )
    return printk(&unk_214703, a2);
  dsi_panel_set_nolp((const char **)(a1 - 2560));
  return zte_aod_handler(v2, 4);
}
