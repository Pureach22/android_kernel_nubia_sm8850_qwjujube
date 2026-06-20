__int64 __fastcall sde_cp_crtc_res_change(_QWORD *a1)
{
  int v2; // w6
  int v3; // w7
  _QWORD *v4; // x9
  _QWORD *v5; // x20
  unsigned int v7; // w8
  _QWORD *v8; // x27
  bool v9; // cc
  __int64 v10; // x8
  _QWORD *v12; // x8
  _QWORD *v13; // x0
  _QWORD *v14; // x1
  char v15; // [xsp+0h] [xbp+0h]

  if ( !a1 )
    return _drm_err("invalid crtc handle");
  mutex_lock(a1 + 583);
  v4 = (_QWORD *)a1[567];
  if ( v4 != a1 + 567 )
  {
    v5 = a1 + 569;
    do
    {
      v7 = *((_DWORD *)v4 - 12);
      v8 = (_QWORD *)*v4;
      v9 = v7 > 0x22;
      v10 = (1LL << v7) & 0x501000000LL;
      if ( !v9 && v10 != 0 )
      {
        v12 = (_QWORD *)v4[1];
        if ( (_QWORD *)*v12 == v4 && (_QWORD *)v8[1] == v4 )
        {
          v8[1] = v12;
          *v12 = v8;
        }
        else
        {
          _list_del_entry_valid_or_report(v4);
        }
        *v4 = v4;
        v13 = v4 + 2;
        v4[1] = v4;
        v14 = (_QWORD *)a1[570];
        if ( v4 + 2 == v5 || v13 == v14 || (_QWORD *)*v14 != v5 )
        {
          _list_add_valid_or_report(v13, v14);
        }
        else
        {
          a1[570] = v13;
          v4[2] = v5;
          v4[3] = v14;
          *v14 = v13;
        }
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "sde_cp_crtc_res_change",
          5034,
          -1,
          *((_DWORD *)v4 - 12),
          -1059143953,
          v2,
          v3,
          v15);
      }
      v4 = v8;
    }
    while ( v8 != a1 + 567 );
  }
  return mutex_unlock(a1 + 583);
}
