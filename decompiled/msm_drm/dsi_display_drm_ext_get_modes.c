__int64 __fastcall dsi_display_drm_ext_get_modes(__int64 a1, __int64 a2)
{
  unsigned int v4; // w20
  __int64 (*v5)(void); // x8
  unsigned int v6; // w0
  __int64 v7; // x8
  _QWORD *v8; // x10
  _QWORD *v9; // x9
  _QWORD *v10; // x8
  _QWORD *v11; // x11
  _QWORD *v12; // x1

  if ( *(_DWORD *)(*(_QWORD *)(a2 + 264) + 1432LL) )
  {
    return (unsigned int)dsi_connector_get_modes(a1, a2);
  }
  else
  {
    v5 = **(__int64 (***)(void))(*(_QWORD *)(a2 + 24) + 2088LL);
    if ( *((_DWORD *)v5 - 1) != -74709386 )
      __break(0x8228u);
    v6 = v5();
    v7 = *(_QWORD *)(a2 + 24);
    v4 = v6;
    v8 = *(_QWORD **)(v7 + 200);
    if ( v8 != (_QWORD *)(v7 + 200) )
    {
      v9 = (_QWORD *)(a1 + 200);
      do
      {
        v11 = (_QWORD *)*v8;
        v10 = (_QWORD *)v8[1];
        if ( (_QWORD *)*v10 == v8 && (_QWORD *)v11[1] == v8 )
        {
          v11[1] = v10;
          *v10 = v11;
        }
        else
        {
          _list_del_entry_valid_or_report(v8);
        }
        v12 = *(_QWORD **)(a1 + 208);
        if ( v8 == v9 || v12 == v8 || (_QWORD *)*v12 != v9 )
        {
          _list_add_valid_or_report(v8, v12);
        }
        else
        {
          *(_QWORD *)(a1 + 208) = v8;
          *v8 = v9;
          v8[1] = v12;
          *v12 = v8;
        }
        v7 = *(_QWORD *)(a2 + 24);
        v8 = v11;
      }
      while ( v11 != (_QWORD *)(v7 + 200) );
    }
    memcpy((void *)(a1 + 216), (const void *)(v7 + 216), 0xC8u);
  }
  return v4;
}
