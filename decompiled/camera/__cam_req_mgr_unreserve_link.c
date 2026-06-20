__int64 __fastcall _cam_req_mgr_unreserve_link(__int64 a1, __int64 a2)
{
  __int64 v4; // x9
  __int64 v5; // x10
  __int64 v6; // x10
  __int64 v7; // x9
  __int64 v8; // x10
  __int64 v9; // x9
  __int64 v10; // x9
  __int64 v11; // x10
  __int64 v12; // x10
  __int64 v13; // x9
  __int64 v14; // x10
  __int64 v15; // x9
  __int64 v16; // x9
  __int64 v17; // x10
  __int64 v18; // x10
  __int64 v19; // x9
  __int64 v20; // x10
  __int64 v21; // x9
  __int64 v22; // x9
  __int64 v23; // x10
  __int64 v24; // x10
  __int64 v25; // x9
  __int64 v26; // x10
  __int64 v27; // x9
  int v28; // w6

  mutex_lock(a1 + 56);
  if ( *(_DWORD *)(a1 + 4) )
  {
    v4 = *(_QWORD *)(a1 + 8);
    if ( v4 == a2 )
    {
      v4 = 0;
      *(_QWORD *)(a1 + 8) = 0;
    }
    v5 = *(_QWORD *)(a2 + 33224);
    if ( v5 && v5 == v4 )
      *(_QWORD *)(v4 + 33224) = 0;
    v6 = *(_QWORD *)(a2 + 33232);
    if ( v6 )
    {
      v7 = *(_QWORD *)(a1 + 8);
      if ( v6 == v7 )
        *(_QWORD *)(v7 + 33232) = 0;
    }
    v8 = *(_QWORD *)(a2 + 33240);
    if ( v8 )
    {
      v9 = *(_QWORD *)(a1 + 8);
      if ( v8 == v9 )
        *(_QWORD *)(v9 + 33240) = 0;
    }
    v10 = *(_QWORD *)(a1 + 16);
    if ( v10 == a2 )
    {
      v10 = 0;
      *(_QWORD *)(a1 + 16) = 0;
    }
    v11 = *(_QWORD *)(a2 + 33224);
    if ( v11 && v11 == v10 )
      *(_QWORD *)(v10 + 33224) = 0;
    v12 = *(_QWORD *)(a2 + 33232);
    if ( v12 )
    {
      v13 = *(_QWORD *)(a1 + 16);
      if ( v12 == v13 )
        *(_QWORD *)(v13 + 33232) = 0;
    }
    v14 = *(_QWORD *)(a2 + 33240);
    if ( v14 )
    {
      v15 = *(_QWORD *)(a1 + 16);
      if ( v14 == v15 )
        *(_QWORD *)(v15 + 33240) = 0;
    }
    v16 = *(_QWORD *)(a1 + 24);
    if ( v16 == a2 )
    {
      v16 = 0;
      *(_QWORD *)(a1 + 24) = 0;
    }
    v17 = *(_QWORD *)(a2 + 33224);
    if ( v17 && v17 == v16 )
      *(_QWORD *)(v16 + 33224) = 0;
    v18 = *(_QWORD *)(a2 + 33232);
    if ( v18 )
    {
      v19 = *(_QWORD *)(a1 + 24);
      if ( v18 == v19 )
        *(_QWORD *)(v19 + 33232) = 0;
    }
    v20 = *(_QWORD *)(a2 + 33240);
    if ( v20 )
    {
      v21 = *(_QWORD *)(a1 + 24);
      if ( v20 == v21 )
        *(_QWORD *)(v21 + 33240) = 0;
    }
    v22 = *(_QWORD *)(a1 + 32);
    if ( v22 == a2 )
    {
      v22 = 0;
      *(_QWORD *)(a1 + 32) = 0;
    }
    v23 = *(_QWORD *)(a2 + 33224);
    if ( v23 && v23 == v22 )
      *(_QWORD *)(v22 + 33224) = 0;
    v24 = *(_QWORD *)(a2 + 33232);
    if ( v24 )
    {
      v25 = *(_QWORD *)(a1 + 32);
      if ( v24 == v25 )
        *(_QWORD *)(v25 + 33232) = 0;
    }
    v26 = *(_QWORD *)(a2 + 33240);
    if ( v26 )
    {
      v27 = *(_QWORD *)(a1 + 32);
      if ( v26 == v27 )
        *(_QWORD *)(v27 + 33240) = 0;
    }
    *(_QWORD *)(a2 + 33232) = 0;
    *(_QWORD *)(a2 + 33240) = 0;
    *(_QWORD *)(a2 + 33224) = 0;
    v28 = *(_DWORD *)(a1 + 4) - 1;
    *(_DWORD *)(a1 + 4) = v28;
    if ( (debug_mdl & 0x10) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x10,
        4,
        "__cam_req_mgr_unreserve_link",
        3059,
        "Active session links (%d)",
        v28);
    mutex_unlock(a1 + 56);
    return _cam_req_mgr_free_link(a2);
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      16,
      2,
      "__cam_req_mgr_unreserve_link",
      3040,
      "No active link or invalid state: hdl %x",
      *(_DWORD *)a2);
    return mutex_unlock(a1 + 56);
  }
}
