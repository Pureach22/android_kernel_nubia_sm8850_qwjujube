__int64 __fastcall sde_cp_check_mdnie_art_done(__int64 a1)
{
  int v2; // w22
  unsigned int disp_op; // w0
  __int64 v4; // x1
  int v5; // w8
  unsigned int v6; // w20
  __int64 v7; // x0
  void (*v8)(void); // x8
  __int64 v9; // x0
  void (*v10)(void); // x8
  __int64 v11; // x0
  void (*v12)(void); // x8
  __int64 v13; // x0
  void (*v14)(void); // x8
  __int64 v15; // x0
  void (*v16)(void); // x8

  mutex_lock(a1 + 4664);
  if ( !*(_DWORD *)(a1 + 8024) )
    return mutex_unlock(a1 + 4664);
  v2 = *(_DWORD *)(a1 + 2192);
  if ( !v2 )
  {
    _drm_err("no mixers for this crtc\n");
    return mutex_unlock(a1 + 4664);
  }
  disp_op = sde_crtc_get_disp_op(a1);
  v5 = *(_DWORD *)(a1 + 8024);
  if ( v5 != 1 )
  {
LABEL_38:
    *(_DWORD *)(a1 + 8024) = v5 - 1;
    return mutex_unlock(a1 + 4664);
  }
  v6 = disp_op;
  if ( *(_BYTE *)(a1 + 7946) == 1 )
    sde_crtc_mdnie_art_event_notify((__int64 *)a1);
  v7 = *(_QWORD *)(a1 + 2216);
  if ( !v7 )
    return mutex_unlock(a1 + 4664);
  if ( v6 <= 2 )
  {
    v8 = *(void (**)(void))(v7 + 8LL * v6 + 1360);
    if ( v8 )
    {
      if ( *((_DWORD *)v8 - 1) != 206991498 )
        __break(0x8228u);
      v8();
      aiqe_deregister_client(2);
    }
    if ( v2 != 1 )
    {
      v9 = *(_QWORD *)(a1 + 2264);
      if ( !v9 )
        return mutex_unlock(a1 + 4664);
      v10 = *(void (**)(void))(v9 + 8LL * v6 + 1360);
      if ( v10 )
      {
        if ( *((_DWORD *)v10 - 1) != 206991498 )
          __break(0x8228u);
        v10();
        aiqe_deregister_client(2);
      }
      if ( v2 != 2 )
      {
        v11 = *(_QWORD *)(a1 + 2312);
        if ( !v11 )
          return mutex_unlock(a1 + 4664);
        v12 = *(void (**)(void))(v11 + 8LL * v6 + 1360);
        if ( v12 )
        {
          if ( *((_DWORD *)v12 - 1) != 206991498 )
            __break(0x8228u);
          v12();
          aiqe_deregister_client(2);
        }
        if ( v2 != 3 )
        {
          v13 = *(_QWORD *)(a1 + 2360);
          if ( !v13 )
            return mutex_unlock(a1 + 4664);
          v14 = *(void (**)(void))(v13 + 8LL * v6 + 1360);
          if ( v14 )
          {
            if ( *((_DWORD *)v14 - 1) != 206991498 )
              __break(0x8228u);
            v14();
            aiqe_deregister_client(2);
          }
          if ( v2 != 4 )
          {
            v15 = *(_QWORD *)(a1 + 2408);
            if ( !v15 )
              return mutex_unlock(a1 + 4664);
            v16 = *(void (**)(void))(v15 + 8LL * v6 + 1360);
            if ( v16 )
            {
              if ( *((_DWORD *)v16 - 1) != 206991498 )
                __break(0x8228u);
              v16();
              aiqe_deregister_client(2);
            }
            if ( v2 != 5 )
              return mutex_unlock(a1 + 4664);
          }
        }
      }
    }
    v5 = *(_DWORD *)(a1 + 8024);
    goto LABEL_38;
  }
  __break(0x5512u);
  return sde_cp_crtc_commit_feature(v7, v4);
}
