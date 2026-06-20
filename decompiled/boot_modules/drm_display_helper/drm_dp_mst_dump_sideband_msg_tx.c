__int64 __fastcall drm_dp_mst_dump_sideband_msg_tx(__int64 a1, __int64 a2)
{
  __int64 v4; // x9
  __int64 v5; // x3
  unsigned __int64 v6; // x8
  __int64 v7; // x9
  int v8; // w11
  __int64 v9; // x8
  const char *v10; // x5
  int v11; // w0
  __int64 result; // x0
  __int64 v13; // x0
  _QWORD v14[8]; // [xsp+0h] [xbp-D0h] BYREF
  __int64 v15; // [xsp+40h] [xbp-90h] BYREF
  __int64 v16; // [xsp+48h] [xbp-88h]
  __int64 v17; // [xsp+50h] [xbp-80h]
  __int64 v18; // [xsp+58h] [xbp-78h]
  __int64 v19; // [xsp+60h] [xbp-70h]
  __int64 v20; // [xsp+68h] [xbp-68h]
  __int64 v21; // [xsp+70h] [xbp-60h]
  __int64 v22; // [xsp+78h] [xbp-58h]
  __int64 v23; // [xsp+80h] [xbp-50h]
  __int64 v24; // [xsp+88h] [xbp-48h]
  __int64 v25; // [xsp+90h] [xbp-40h]
  __int64 v26; // [xsp+98h] [xbp-38h]
  __int64 v27; // [xsp+A0h] [xbp-30h]
  __int64 v28; // [xsp+A8h] [xbp-28h]
  __int64 v29; // [xsp+B0h] [xbp-20h]
  _QWORD v30[3]; // [xsp+B8h] [xbp-18h] BYREF

  v30[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a2 + 312);
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  v20 = 0;
  v21 = 0;
  v18 = 0;
  v19 = 0;
  v15 = 0;
  v5 = *(unsigned __int8 *)(v4 + 32);
  v16 = 0;
  v17 = 0;
  memset(v14, 0, sizeof(v14));
  v30[0] = 0;
  v30[1] = 0;
  if ( v5 )
  {
    v6 = 0;
    v7 = v4 + 24;
    do
    {
      if ( (v6 & 1) != 0 )
      {
        if ( v6 >= 0x10 )
          goto LABEL_22;
        v8 = *(unsigned __int8 *)(v7 + (v6 >> 1)) >> 4;
      }
      else
      {
        if ( v6 > 0xF )
          goto LABEL_22;
        LOBYTE(v8) = *(_BYTE *)(v7 + (v6 >> 1)) & 0x10;
      }
      *((_BYTE *)v30 + v6++) = v8;
    }
    while ( v5 != v6 );
  }
  snprintf((char *)v14, 0x40u, "%*phC", v5, v30);
  v9 = *(unsigned int *)(a2 + 340);
  if ( (unsigned int)v9 <= 4 )
    v10 = drm_dp_mst_sideband_tx_state_str_sideband_reason_str[v9];
  else
    v10 = "unknown";
  drm_printf(
    a1,
    "txmsg cur_offset=%x cur_len=%x seqno=%x state=%s path_msg=%d dst=%s\n",
    *(unsigned __int8 *)(a2 + 304),
    *(unsigned __int8 *)(a2 + 305),
    *(_DWORD *)(a2 + 336),
    v10,
    *(unsigned __int8 *)(a2 + 344),
    (const char *)v14);
  v11 = drm_dp_decode_sideband_req((_BYTE *)a2, (__int64)&v15);
  if ( v11 )
  {
    result = drm_printf(a1, "<failed to decode sideband req: %d>\n", v11);
    goto LABEL_26;
  }
  result = drm_dp_dump_sideband_msg_req_body((unsigned __int8 *)&v15, 1, a1);
  switch ( (unsigned __int8)v15 )
  {
    case '!':
      v13 = v18;
      goto LABEL_25;
    case '#':
LABEL_23:
      v13 = v17;
LABEL_25:
      result = kfree(v13);
      break;
    case '"':
      if ( (_BYTE)v16 )
      {
        result = kfree(v18);
        if ( (unsigned __int8)v16 > 1u )
        {
          result = kfree(v21);
          if ( (unsigned __int8)v16 >= 3u )
          {
            result = kfree(v24);
            if ( (unsigned __int8)v16 >= 4u )
            {
              result = kfree(v27);
              if ( (unsigned __int8)v16 > 4u )
              {
LABEL_22:
                __break(0x5512u);
                goto LABEL_23;
              }
            }
          }
        }
      }
      break;
  }
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
