__int64 __fastcall reg_send_11d_msg_cbk(__int64 a1)
{
  __int64 v1; // x20
  __int64 v2; // x19
  __int64 psoc_tx_ops; // x0
  __int64 v4; // x21
  __int64 psoc_obj; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  void (__fastcall *v14)(__int64, __int64 *); // x8
  __int64 result; // x0
  const char *v16; // x2
  _DWORD *v17; // x8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  _BYTE v26[4]; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v27; // [xsp+8h] [xbp-18h] BYREF
  int v28; // [xsp+10h] [xbp-10h]
  __int64 v29; // [xsp+18h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 8);
  v26[0] = 0;
  v2 = *(_QWORD *)v1;
  v28 = 0;
  v27 = 0;
  psoc_tx_ops = reg_get_psoc_tx_ops(v2);
  if ( psoc_tx_ops )
  {
    v4 = psoc_tx_ops;
    psoc_obj = reg_get_psoc_obj(v2);
    if ( psoc_obj )
    {
      if ( *(unsigned __int8 *)(psoc_obj + 91153) != 255 )
      {
        if ( *(_BYTE *)(v1 + 8) == 1 )
        {
          LOBYTE(v27) = *(_BYTE *)(psoc_obj + 91153);
          HIDWORD(v27) = *(_DWORD *)(psoc_obj + 91156);
          v28 = 0;
          qdf_trace_msg(0x51u, 8u, "%s: sending start msg", v6, v7, v8, v9, v10, v11, v12, v13, "reg_send_11d_msg_cbk");
          v14 = *(void (__fastcall **)(__int64, __int64 *))(v4 + 72);
          if ( *((_DWORD *)v14 - 1) != -291554120 )
            __break(0x8228u);
          v14(v2, &v27);
        }
        else
        {
          v26[0] = *(_BYTE *)(psoc_obj + 91153);
          qdf_trace_msg(0x51u, 8u, "%s: sending stop msg", v6, v7, v8, v9, v10, v11, v12, v13, "reg_send_11d_msg_cbk");
          v17 = *(_DWORD **)(v4 + 80);
          if ( *(v17 - 1) != 979720446 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _BYTE *))v17)(v2, v26);
        }
        goto LABEL_15;
      }
      *(_BYTE *)(psoc_obj + 91151) = 0;
      v16 = "%s: Invalid vdev";
    }
    else
    {
      v16 = "%s: Null psoc priv obj";
    }
    qdf_trace_msg(0x51u, 2u, v16, v6, v7, v8, v9, v10, v11, v12, v13, "reg_send_11d_msg_cbk");
LABEL_15:
    _qdf_mem_free(v1);
    wlan_objmgr_psoc_release_ref(v2, 0x15u, v18, v19, v20, v21, v22, v23, v24, v25);
    result = 0;
    goto LABEL_16;
  }
  result = 16;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
