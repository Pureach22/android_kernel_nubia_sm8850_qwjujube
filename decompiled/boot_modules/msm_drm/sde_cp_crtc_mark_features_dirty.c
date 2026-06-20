__int64 __fastcall sde_cp_crtc_mark_features_dirty(_QWORD *a1)
{
  _QWORD *v2; // x9
  _QWORD *v3; // x12
  _QWORD *v4; // x10
  _QWORD *v5; // x11
  __int64 v6; // x13
  unsigned int v7; // w8
  _QWORD *v8; // x15
  _QWORD *v9; // x0
  _QWORD *v10; // x1
  _QWORD *v11; // x8
  __int64 v12; // x16
  _QWORD *v13; // x9
  _QWORD *v14; // x12
  _QWORD *v15; // x10
  _QWORD *v16; // x11
  __int64 v17; // x13
  unsigned int v18; // w8
  _QWORD *v19; // x15
  _QWORD *v20; // x0
  _QWORD *v21; // x1
  _QWORD *v22; // x8
  __int64 v23; // x16

  if ( !a1 )
    return _drm_err("crtc %pK\n", nullptr);
  mutex_lock(a1 + 583);
  v2 = (_QWORD *)a1[567];
  v3 = a1 + 567;
  if ( v2 != a1 + 567 )
  {
    v4 = a1 + 569;
    v5 = a1 + 571;
    v6 = 1;
    do
    {
      v7 = *((_DWORD *)v2 - 12);
      v8 = (_QWORD *)*v2;
      if ( v7 <= 0x2B && ((v6 << v7) & 0x7F8000) != 0 )
      {
        v9 = v2 + 2;
        v10 = (_QWORD *)a1[572];
        if ( v2 + 2 != v5 && v9 != v10 && (_QWORD *)*v10 == v5 )
        {
          a1[572] = v9;
          v2[2] = v5;
LABEL_14:
          v2[3] = v10;
          *v10 = v9;
          goto LABEL_15;
        }
      }
      else
      {
        v9 = v2 + 2;
        v10 = (_QWORD *)a1[570];
        if ( v2 + 2 != v4 && v9 != v10 && (_QWORD *)*v10 == v4 )
        {
          a1[570] = v9;
          v2[2] = v4;
          goto LABEL_14;
        }
      }
      _list_add_valid_or_report(v9, v10);
LABEL_15:
      v11 = (_QWORD *)v2[1];
      if ( (_QWORD *)*v11 == v2 && (v12 = *v2, *(_QWORD **)(*v2 + 8LL) == v2) )
      {
        *(_QWORD *)(v12 + 8) = v11;
        *v11 = v12;
      }
      else
      {
        _list_del_entry_valid_or_report(v2);
      }
      *v2 = v2;
      v2[1] = v2;
      v2 = v8;
    }
    while ( v8 != v3 );
  }
  v13 = (_QWORD *)a1[573];
  v14 = a1 + 573;
  if ( v13 != a1 + 573 )
  {
    v15 = a1 + 569;
    v16 = a1 + 571;
    v17 = 1;
    while ( 1 )
    {
      v18 = *((_DWORD *)v13 - 12);
      v19 = (_QWORD *)*v13;
      if ( v18 <= 0x2B && ((v17 << v18) & 0x7F8000) != 0 )
      {
        v20 = v13 + 2;
        v21 = (_QWORD *)a1[572];
        if ( v13 + 2 != v16 && v20 != v21 && (_QWORD *)*v21 == v16 )
        {
          a1[572] = v20;
          v13[2] = v16;
LABEL_35:
          v13[3] = v21;
          *v21 = v20;
          goto LABEL_36;
        }
      }
      else
      {
        v20 = v13 + 2;
        v21 = (_QWORD *)a1[570];
        if ( v13 + 2 != v15 && v20 != v21 && (_QWORD *)*v21 == v15 )
        {
          a1[570] = v20;
          v13[2] = v15;
          goto LABEL_35;
        }
      }
      _list_add_valid_or_report(v20, v21);
LABEL_36:
      v22 = (_QWORD *)v13[1];
      if ( (_QWORD *)*v22 == v13 && (v23 = *v13, *(_QWORD **)(*v13 + 8LL) == v13) )
      {
        *(_QWORD *)(v23 + 8) = v22;
        *v22 = v23;
      }
      else
      {
        _list_del_entry_valid_or_report(v13);
      }
      *v13 = v13;
      v13[1] = v13;
      v13 = v19;
      if ( v19 == v14 )
      {
        mutex_unlock(a1 + 583);
        return sde_cp_ad_set_prop((__int64)a1, 4);
      }
    }
  }
  return mutex_unlock(a1 + 583);
}
