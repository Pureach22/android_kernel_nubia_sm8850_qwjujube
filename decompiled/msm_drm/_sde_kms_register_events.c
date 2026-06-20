__int64 __fastcall sde_kms_register_events(_QWORD *a1, __int64 a2, unsigned int a3, char a4)
{
  __int64 v6; // x0
  __int64 v9; // x8
  __int64 (__fastcall *v10)(_QWORD); // x8
  int v11; // w8
  __int64 result; // x0
  __int64 v13; // x8
  unsigned int v14; // w19
  __int64 v15; // x0

  if ( !a1 || !a2 )
  {
    printk(&unk_27A5CC, "_sde_kms_register_events");
    return 4294967274LL;
  }
  v6 = a1[798];
  if ( !v6 )
    goto LABEL_9;
  mutex_lock(v6);
  v9 = a1[798];
  if ( !v9 )
    goto LABEL_9;
  v10 = *(__int64 (__fastcall **)(_QWORD))(v9 + 88);
  if ( !v10 )
    goto LABEL_9;
  if ( *((_DWORD *)v10 - 1) != 1370937740 )
    __break(0x8228u);
  if ( (v10(a1) & 1) == 0 )
  {
    v15 = a1[798];
    if ( v15 )
      mutex_unlock(v15);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "HW is owned by other VM\n");
    return 4294967283LL;
  }
  else
  {
LABEL_9:
    v11 = *(_DWORD *)(a2 + 4);
    if ( v11 == -1061109568 )
    {
      result = sde_connector_register_custom_event(a1, a2 - 64, a3, a4 & 1);
      v13 = a1[798];
      if ( !v13 )
        return result;
    }
    else if ( v11 == -858993460 )
    {
      result = sde_crtc_register_custom_event(a1, a2 - 112, a3, a4 & 1);
      v13 = a1[798];
      if ( !v13 )
        return result;
    }
    else
    {
      result = 0;
      v13 = a1[798];
      if ( !v13 )
        return result;
    }
    v14 = result;
    mutex_unlock(v13);
    return v14;
  }
}
