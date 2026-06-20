__int64 __fastcall sde_crtc_clear_cached_mixer_cfg(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  char v8; // w29
  int v9; // w4

  if ( !*(_DWORD *)(a1 + 2192) )
    goto LABEL_10;
  *(_QWORD *)(*(_QWORD *)(a1 + 2200) + 376LL) = 0;
  if ( *(_DWORD *)(a1 + 2192) <= 1u )
    goto LABEL_10;
  *(_QWORD *)(*(_QWORD *)(a1 + 2248) + 376LL) = 0;
  if ( *(_DWORD *)(a1 + 2192) >= 3u
    && (*(_QWORD *)(*(_QWORD *)(a1 + 2296) + 376LL) = 0, *(_DWORD *)(a1 + 2192) >= 4u)
    && (*(_QWORD *)(*(_QWORD *)(a1 + 2344) + 376LL) = 0, *(_DWORD *)(a1 + 2192) >= 5u)
    && (*(_QWORD *)(*(_QWORD *)(a1 + 2392) + 376LL) = 0, *(_DWORD *)(a1 + 2192) >= 6u)
    && (*(_QWORD *)(*(_QWORD *)(a1 + 2440) + 376LL) = 0, *(_DWORD *)(a1 + 2192) >= 7u)
    && (*(_QWORD *)(*(_QWORD *)(a1 + 2488) + 376LL) = 0, *(_DWORD *)(a1 + 2192) >= 8u)
    && (*(_QWORD *)(*(_QWORD *)(a1 + 2536) + 376LL) = 0, *(_DWORD *)(a1 + 2192) > 8u) )
  {
    __break(0x5512u);
    return sde_crtc_transition_handle_events();
  }
  else
  {
LABEL_10:
    if ( a1 )
      v9 = *(_DWORD *)(a1 + 112);
    else
      v9 = -1;
    return sde_evtlog_log(sde_dbg_base_evtlog, "sde_crtc_clear_cached_mixer_cfg", 6020, -1, v9, -1059143953, a7, a8, v8);
  }
}
