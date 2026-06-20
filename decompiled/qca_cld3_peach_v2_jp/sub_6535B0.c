__int64 sub_6535B0()
{
  __asm { PRFM            #0x1E, [X19,#0x4E]! }
  return ucfg_twt_set_osif_cb();
}
