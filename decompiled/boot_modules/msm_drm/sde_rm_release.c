__int64 __fastcall sde_rm_release(__int64 a1, int *a2, char a3)
{
  __int64 v4; // x23
  __int64 *v7; // x21
  _BYTE *v8; // x8
  __int64 v9; // x4
  const char *v10; // x3
  __int64 result; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x23
  __int64 v15; // x9
  __int64 v16; // x8
  __int64 v17; // x23
  char v18; // [xsp+0h] [xbp-30h]
  _QWORD v19[3]; // [xsp+18h] [xbp-18h] BYREF

  v19[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 )
  {
    result = printk(&unk_223EAA, "sde_rm_release");
    goto LABEL_17;
  }
  v4 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)a2 + 56LL) + 8LL);
  if ( !v4 )
  {
    result = printk(&unk_234896, "sde_rm_release");
    goto LABEL_17;
  }
  mutex_lock(a1 + 280);
  v7 = *(__int64 **)(a1 + 8);
  if ( v7 == (__int64 *)(a1 + 8) )
    goto LABEL_13;
  while ( *((_BYTE *)v7 + 28) != (a3 & 1) || *((_DWORD *)v7 + 5) != a2[6] )
  {
    v7 = (__int64 *)*v7;
    if ( v7 == (__int64 *)(a1 + 8) )
      goto LABEL_13;
  }
  if ( !v7 )
  {
LABEL_13:
    if ( (_drm_debug & 4) != 0 )
    {
      v9 = (unsigned int)a2[6];
      v10 = "failed to find rsvp for enc %d, nxt %d";
LABEL_15:
      _drm_dev_dbg(0, 0, 0, v10, v9, a3 & 1);
    }
    goto LABEL_16;
  }
  if ( *(int **)(v4 + 2720) == a2 )
  {
    v8 = (_BYTE *)(v4 + 2712);
  }
  else
  {
    if ( *(int **)(v4 + 2800) != a2 )
      goto LABEL_22;
    v8 = (_BYTE *)(v4 + 2792);
  }
  if ( *v8 != 1 )
  {
LABEL_22:
    v12 = *(_QWORD *)a2;
    v19[0] = 0;
    v19[1] = 0;
    drm_connector_list_iter_begin(v12, v19);
    do
    {
      v13 = drm_connector_list_iter_next(v19);
      if ( !v13 )
      {
        drm_connector_list_iter_end(v19);
        sde_evtlog_log(sde_dbg_base_evtlog, "sde_rm_release", 2927, -1, a2[6], 0, -1, -1059143953, v18);
        sde_rm_release_rsvp(a1, v7);
        if ( (_drm_debug & 4) == 0 )
          goto LABEL_16;
        v9 = (unsigned int)a2[6];
        v10 = "failed to get conn for enc %d nxt %d\n";
        goto LABEL_15;
      }
    }
    while ( *(int **)(v13 + 2744) != a2 );
    v14 = v13;
    drm_connector_list_iter_end(v19);
    v15 = *(_QWORD *)(v14 + 2512);
    v16 = v14;
    if ( v15 )
      v17 = *(_QWORD *)(v15 + 1408);
    else
      LODWORD(v17) = 0;
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "sde_rm_release",
      2937,
      -1,
      a2[6],
      *(_DWORD *)(v16 + 64),
      *((_DWORD *)v7 + 4),
      v17,
      a3 & 1);
    if ( (v17 & 1) == 0 )
    {
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "release rsvp[s%de%d]\n", *((_DWORD *)v7 + 4), *((_DWORD *)v7 + 5));
      goto LABEL_33;
    }
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "rsvp[s%de%d] not releasing locked resources\n",
        *((unsigned int *)v7 + 4),
        *((unsigned int *)v7 + 5));
    goto LABEL_16;
  }
LABEL_33:
  sde_rm_release_rsvp(a1, v7);
LABEL_16:
  result = mutex_unlock(a1 + 280);
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
