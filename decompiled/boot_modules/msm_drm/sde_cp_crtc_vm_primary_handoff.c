__int64 __fastcall sde_cp_crtc_vm_primary_handoff(_QWORD *a1)
{
  __int64 v2; // x0
  _QWORD *v3; // x12
  _QWORD *v4; // x13
  _QWORD *v5; // x9
  _QWORD *v6; // x14
  _BYTE *v7; // x15
  _QWORD *v8; // x10
  __int64 v9; // x8
  _QWORD *v10; // x11
  _QWORD *v11; // x11
  __int64 *v12; // x1
  __int64 *v13; // x1
  _QWORD *v14; // x8
  _QWORD *v15; // x11
  __int64 v16; // x16

  if ( !a1 )
    return _drm_err("crtc %pK\n", nullptr);
  v2 = mutex_lock(a1 + 583);
  v3 = (_QWORD *)a1[565];
  v4 = a1 + 565;
  if ( v3 == a1 + 565 )
    return mutex_unlock(a1 + 583);
  v5 = a1 + 569;
  v6 = a1 + 567;
  v7 = &feature_handoff_mask;
  v8 = a1 + 571;
  while ( 1 )
  {
    v9 = *((unsigned int *)v3 - 8);
    if ( (unsigned int)v9 >= 0x34 )
      break;
    if ( v7[v9] != 1 )
      goto LABEL_5;
    v10 = v5;
    while ( 1 )
    {
      v10 = (_QWORD *)*v10;
      if ( v10 == v5 )
        break;
      if ( *((_DWORD *)v10 - 16) == (_DWORD)v9 )
        goto LABEL_5;
    }
    v11 = v6;
    do
    {
      v11 = (_QWORD *)*v11;
      if ( v11 == v6 )
      {
        if ( (unsigned int)v9 <= 0x2B && ((1LL << v9) & 0x7F8000) != 0 )
        {
          v2 = (__int64)(v3 + 4);
          v13 = (__int64 *)a1[572];
          if ( v3 + 4 != v8 && (__int64 *)v2 != v13 && (_QWORD *)*v13 == v8 )
          {
            a1[572] = v2;
            v3[4] = v8;
LABEL_4:
            v3[5] = v13;
            *v13 = v2;
            goto LABEL_5;
          }
        }
        else
        {
          v2 = (__int64)(v3 + 4);
          v13 = (__int64 *)a1[570];
          if ( v3 + 4 != v5 && (__int64 *)v2 != v13 && (_QWORD *)*v13 == v5 )
          {
            a1[570] = v2;
            v3[4] = v5;
            goto LABEL_4;
          }
        }
        v2 = _list_add_valid_or_report(v2, v13);
        goto LABEL_5;
      }
    }
    while ( *((_DWORD *)v11 - 12) != (_DWORD)v9 );
    if ( (unsigned int)v9 <= 0x2B && ((1LL << v9) & 0x7F8000) != 0 )
    {
      v2 = (__int64)(v3 + 4);
      v12 = (__int64 *)a1[572];
      if ( v3 + 4 != v8 && (__int64 *)v2 != v12 && (_QWORD *)*v12 == v8 )
      {
        a1[572] = v2;
        v3[4] = v8;
        goto LABEL_35;
      }
LABEL_42:
      v2 = _list_add_valid_or_report(v2, v12);
    }
    else
    {
      v2 = (__int64)(v3 + 4);
      v12 = (__int64 *)a1[570];
      if ( v3 + 4 == v5 || (__int64 *)v2 == v12 || (_QWORD *)*v12 != v5 )
        goto LABEL_42;
      a1[570] = v2;
      v3[4] = v5;
LABEL_35:
      v3[5] = v12;
      *v12 = v2;
    }
    v14 = (_QWORD *)v3[3];
    v15 = v3 + 2;
    if ( (_QWORD *)*v14 == v3 + 2 && (v16 = *v15, *(_QWORD **)(*v15 + 8LL) == v15) )
    {
      *(_QWORD *)(v16 + 8) = v14;
      *v14 = v16;
    }
    else
    {
      v2 = _list_del_entry_valid_or_report(v3 + 2);
    }
    v3[2] = v3 + 2;
    v3[3] = v15;
LABEL_5:
    v3 = (_QWORD *)*v3;
    if ( v3 == v4 )
      return mutex_unlock(a1 + 583);
  }
  __break(0x5512u);
  return sde_cp_crtc_enable(v2);
}
