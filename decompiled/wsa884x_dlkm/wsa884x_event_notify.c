__int64 __fastcall wsa884x_event_notify(__int64 a1, __int16 a2)
{
  __int64 v2; // x19
  _QWORD *v5; // x19
  unsigned __int64 v12; // x9

  v2 = a1 - 616;
  if ( a1 == 616 )
    return 4294967274LL;
  switch ( a2 )
  {
    case 5:
      if ( (*(_QWORD *)(a1 + 64) & 1) != 0 )
      {
        v5 = (_QWORD *)(a1 - 592);
        snd_soc_component_update_bits(*(_QWORD *)(a1 - 592), 13451, 1, 1);
        snd_soc_component_update_bits(*v5, 13360, 1, 1);
      }
      break;
    case 6:
      if ( (*(_QWORD *)(a1 + 64) & 1) != 0 )
      {
        _X8 = (unsigned __int64 *)(a1 + 64);
        __asm { PRFM            #0x11, [X8] }
        do
          v12 = __ldxr(_X8);
        while ( __stxr(v12 | 4, _X8) );
      }
      break;
    case 4:
      wsa884x_swr_down(a1 - 616);
      usleep_range_state(500, 510, 2);
      wsa884x_swr_up(v2);
      usleep_range_state(20000, 20010, 2);
      wsa884x_swr_reset(v2);
      dev_err(*(_QWORD *)(a1 - 608), "%s: BOLERO_SLV_EVT_SSR_UP Called", "wsa884x_event_notify");
      swr_init_port_params(*(_QWORD *)(a1 - 600), 6, a1 - 104);
      break;
  }
  return 0;
}
