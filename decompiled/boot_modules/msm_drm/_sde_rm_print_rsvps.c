__int64 __fastcall sde_rm_print_rsvps(__int64 result, int a2)
{
  __int64 v3; // x20
  __int64 *i; // x26
  const char *v5; // x5
  __int64 v6; // x22
  __int64 **v7; // x27
  __int64 *j; // x28
  int v9; // w0
  int v10; // w5
  int v11; // w6
  __int64 v12; // x8
  int v13; // w7
  __int64 v14; // x8
  __int64 v15; // x9
  int v16; // w6
  int v17; // w5
  int v18; // w7
  int v19; // w8

  v3 = result;
  if ( (_drm_debug & 4) != 0 )
    result = _drm_dev_dbg(0, 0, 0, "%d\n", a2);
  for ( i = *(__int64 **)(v3 + 8); i != (__int64 *)(v3 + 8); i = (__int64 *)*i )
  {
    if ( (_drm_debug & 4) != 0 )
    {
      if ( *((_BYTE *)i + 28) )
        v5 = "_nxt";
      else
        v5 = (const char *)&unk_229BD3;
      _drm_dev_dbg(
        0,
        0,
        0,
        "%d rsvp%s[s%ue%u] topology %d\n",
        a2,
        v5,
        *((_DWORD *)i + 4),
        *((_DWORD *)i + 5),
        *((_DWORD *)i + 6));
    }
    result = sde_evtlog_log(
               sde_dbg_base_evtlog,
               "_sde_rm_print_rsvps",
               398,
               -1,
               a2,
               *((_DWORD *)i + 4),
               *((_DWORD *)i + 5),
               *((_DWORD *)i + 6),
               *((_BYTE *)i + 28));
  }
  v6 = 0;
  while ( 2 )
  {
    v7 = (__int64 **)(v3 + 24 + 16 * v6);
    for ( j = *v7; j != (__int64 *)v7; j = (__int64 *)*j )
    {
      v14 = j[2];
      if ( v14 )
      {
        if ( (_drm_debug & 4) != 0 )
        {
          v17 = *(_DWORD *)(v14 + 16);
          v16 = *(_DWORD *)(v14 + 20);
          v15 = j[3];
          if ( v15 )
          {
LABEL_27:
            v18 = *(_DWORD *)(v15 + 16);
            v19 = *(_DWORD *)(v15 + 20);
          }
          else
          {
            v18 = 0;
            v19 = 0;
          }
          _drm_dev_dbg(
            0,
            0,
            0,
            "%d rsvp[s%ue%u->s%ue%u] %d %d\n",
            a2,
            v17,
            v16,
            v18,
            v19,
            *((_DWORD *)j + 8),
            *((_DWORD *)j + 9));
          v14 = j[2];
          v9 = sde_dbg_base_evtlog;
          if ( !v14 )
            goto LABEL_15;
        }
        else
        {
          v9 = sde_dbg_base_evtlog;
        }
        v10 = *(_DWORD *)(v14 + 16);
        v11 = *(_DWORD *)(v14 + 20);
        v12 = j[3];
        if ( !v12 )
          goto LABEL_31;
LABEL_16:
        v13 = *(_DWORD *)(v12 + 16);
        LODWORD(v12) = *(_DWORD *)(v12 + 20);
        goto LABEL_17;
      }
      v15 = j[3];
      if ( v15 )
      {
        if ( (_drm_debug & 4) != 0 )
        {
          v16 = 0;
          v17 = 0;
          goto LABEL_27;
        }
        v9 = sde_dbg_base_evtlog;
LABEL_15:
        v10 = 0;
        v11 = 0;
        v12 = j[3];
        if ( v12 )
          goto LABEL_16;
LABEL_31:
        v13 = 0;
LABEL_17:
        result = sde_evtlog_log(v9, "_sde_rm_print_rsvps", 418, -1, a2, v10, v11, v13, v12);
        continue;
      }
    }
    if ( ++v6 != 15 )
      continue;
    return result;
  }
}
