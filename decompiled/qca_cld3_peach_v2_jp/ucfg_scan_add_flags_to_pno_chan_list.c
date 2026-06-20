__int64 __fastcall ucfg_scan_add_flags_to_pno_chan_list(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        unsigned int a5)
{
  __int64 v5; // x20

  if ( a5 >= 0x10 )
  {
    __break(0x5512u);
    return ucfg_scan_pno_stop();
  }
  else
  {
    v5 = a2 + 116;
    scm_add_channel_flags(a1, a2 + 116 + 1280LL * a5, a3, *(unsigned __int8 *)(a2 + 20688), 1);
    return ((__int64 (__fastcall *)(__int64, _QWORD, __int64))scm_filter_rnr_flag_pno)(a1, a4, v5);
  }
}
