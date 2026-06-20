__int64 __fastcall drm_dp_send_enum_path_resources(_QWORD *a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x19
  unsigned __int8 v7; // w8
  int v8; // w0
  __int64 v9; // x8
  __int64 v10; // x1
  unsigned int v11; // w22
  __int64 v12; // x8
  __int64 v13; // x1
  int v14; // w8
  int v15; // w9
  _QWORD v17[16]; // [xsp+0h] [xbp-80h] BYREF

  v17[15] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = _kmalloc_cache_noprof(_list_del_entry_valid_or_report, 3520, 768);
  if ( v6 )
  {
    v7 = *(_BYTE *)(a3 + 8);
    *(_QWORD *)(v6 + 312) = a2;
    memset(&v17[2], 0, 104);
    v17[0] = 16;
    v17[1] = v7;
    ((void (__fastcall *)(_QWORD *, __int64))drm_dp_encode_sideband_req)(v17, v6);
    *(_BYTE *)(v6 + 344) = 1;
    drm_dp_queue_down_tx(a1, v6);
    v8 = drm_dp_mst_wait_tx_reply(a2, v6);
    if ( v8 < 1 )
    {
      v11 = v8;
    }
    else if ( *(_BYTE *)(v6 + 346) == 1 )
    {
      v9 = a1[13];
      if ( v9 )
        v10 = *(_QWORD *)(v9 + 8);
      else
        v10 = 0;
      _drm_dev_dbg(0, v10, 2, "enum path resources nak received\n");
      v11 = 0;
    }
    else
    {
      if ( *(unsigned __int8 *)(a3 + 8) != *(unsigned __int8 *)(v6 + 348) )
        _drm_err("got incorrect port in response\n");
      v12 = a1[13];
      if ( v12 )
        v13 = *(_QWORD *)(v12 + 8);
      else
        v13 = 0;
      _drm_dev_dbg(
        0,
        v13,
        2,
        "enum path resources %d: %d %d\n",
        *(unsigned __int8 *)(v6 + 348),
        *(unsigned __int16 *)(v6 + 350),
        *(unsigned __int16 *)(v6 + 352));
      v14 = *(unsigned __int16 *)(v6 + 350);
      if ( *(unsigned __int16 *)(a3 + 18) == v14 )
      {
        v15 = *(unsigned __int8 *)(v6 + 349);
        v11 = *(unsigned __int8 *)(a3 + 1648) != v15;
      }
      else
      {
        LOBYTE(v15) = *(_BYTE *)(v6 + 349);
        v11 = 1;
      }
      *(_WORD *)(a3 + 18) = v14;
      *(_BYTE *)(a3 + 1648) = v15;
    }
    kfree(v6);
  }
  else
  {
    v11 = -12;
  }
  _ReadStatusReg(SP_EL0);
  return v11;
}
