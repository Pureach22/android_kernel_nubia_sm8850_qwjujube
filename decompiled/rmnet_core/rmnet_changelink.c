__int64 __fastcall rmnet_changelink(__int64 a1, __int64 a2, _QWORD *a3)
{
  __int64 v5; // x8
  __int64 result; // x0
  __int64 v7; // x10
  __int64 v8; // x20
  unsigned __int64 v9; // x9
  __int64 v10; // x8
  __int64 v11; // x10
  unsigned __int8 *v12; // x10
  __int64 *v13; // x11
  __int64 *v14; // x12
  __int64 v15; // x13
  unsigned __int64 *v16; // x12
  unsigned __int64 v17; // x9
  __int64 v18; // x8
  _WORD *v19; // x2
  unsigned int v20; // w19

  v5 = _dev_get_by_index(*(_QWORD *)(a1 + 280), *(unsigned int *)(*(_QWORD *)(a2 + 40) + 4LL));
  result = 4294967277LL;
  if ( !a1 || !v5 || *(__int64 (__fastcall **)())(v5 + 264) != rmnet_rx_handler )
    return result;
  v7 = a3[1];
  v8 = *(_QWORD *)(v5 + 272);
  if ( !v7 )
  {
LABEL_19:
    v18 = a3[2];
    if ( v18 )
      *(_DWORD *)(v8 + 8) = *(_DWORD *)(v8 + 8) & 0x8000000 | *(_DWORD *)(v18 + 8) & *(_DWORD *)(v18 + 4);
    v19 = (_WORD *)a3[3];
    if ( v19 )
    {
      result = qmi_rmnet_change_link(a1, v8, v19 + 2, (unsigned __int16)(*v19 - 4));
      v10 = a3[4];
      if ( !v10 )
        return result;
    }
    else
    {
      result = 0;
      v10 = a3[4];
      if ( !v10 )
        return result;
    }
    v9 = a3[5];
    if ( v9 )
    {
      v9 = *(unsigned __int8 *)(v9 + 4);
      v20 = result;
      if ( v9 <= 2 )
      {
LABEL_29:
        rmnet_map_update_ul_agg_config(
          v8 + 200LL * (unsigned int)v9 + 2072,
          *(unsigned __int16 *)(v10 + 4),
          *(unsigned __int8 *)(v10 + 6),
          *(unsigned __int8 *)(v10 + 7),
          *(unsigned int *)(v10 + 8));
        return v20;
      }
LABEL_27:
      __break(0x5512u);
    }
    v20 = result;
    goto LABEL_29;
  }
  v9 = v8 + 16;
  v10 = *(unsigned __int16 *)(v7 + 4);
  v11 = *(_QWORD *)(v8 + 16 + 8LL * *(unsigned __int8 *)(a1 + 2688));
  if ( v11 )
  {
    do
    {
      v12 = (unsigned __int8 *)(v11 - 16);
      if ( !v12 )
        break;
      v13 = (__int64 *)(v12 + 16);
      if ( *v12 == *(unsigned __int8 *)(a1 + 2688) )
      {
        v14 = *((__int64 **)v12 + 3);
        if ( v14 )
        {
          v15 = *v13;
          *v14 = *v13;
          if ( v15 )
            *(_QWORD *)(v15 + 8) = v14;
          *((_QWORD *)v12 + 3) = 0;
        }
        if ( (unsigned int)v10 < 0x100 )
        {
          v16 = (unsigned __int64 *)(v9 + 8 * v10);
          v17 = *v16;
          *((_QWORD *)v12 + 2) = *v16;
          *((_QWORD *)v12 + 3) = v16;
          atomic_store((unsigned __int64)v13, v16);
          if ( v17 )
            *(_QWORD *)(v17 + 8) = v13;
          *v12 = v10;
          *(_BYTE *)(a1 + 2688) = v10;
          goto LABEL_19;
        }
        goto LABEL_27;
      }
      v11 = *v13;
    }
    while ( *v13 );
  }
  return result;
}
