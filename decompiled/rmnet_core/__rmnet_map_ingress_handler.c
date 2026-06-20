__int64 __fastcall _rmnet_map_ingress_handler(__int64 a1, __int64 a2)
{
  int v4; // w8
  char *v5; // x21
  __int64 v6; // x8
  __int64 v7; // x9
  int v8; // w22
  int v9; // w1
  unsigned int v10; // w23
  unsigned __int8 *endpoint; // x0
  __int64 v12; // x1
  char v13; // w8
  unsigned int v14; // w21
  int v15; // w8
  __int64 result; // x0
  int v17; // w8
  unsigned int v18; // w9
  __int64 v19; // x8
  _BYTE *v20; // x10
  __int64 v21; // x8
  __int64 v22; // x9
  unsigned int v23; // w22
  __int64 v24; // x0
  int v25; // w8
  __int16 v26; // w9
  __int16 v27; // w8
  int v28; // w8
  int v29; // w9
  _QWORD *v30; // x8
  _QWORD *v31; // x2
  __int64 v32; // x8
  _QWORD *v33; // x9
  int v34; // w8
  _BYTE *v35; // x10
  __int64 v36; // x8
  __int64 v37; // x9
  int v38; // w8
  __int16 v39; // w9
  __int16 v40; // w8
  _QWORD *v41; // [xsp+0h] [xbp-20h] BYREF
  _QWORD **v42; // [xsp+8h] [xbp-18h]
  __int64 v43; // [xsp+10h] [xbp-10h]
  __int64 v44; // [xsp+18h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD *)(a1 + 116);
  v41 = &v41;
  v42 = &v41;
  v43 = 0;
  if ( !v4 || *(_DWORD *)(a1 + 112) != v4 )
  {
    v5 = *(char **)(a1 + 224);
    v8 = *v5;
    if ( (v8 & 0x80000000) == 0 )
      goto LABEL_7;
LABEL_14:
    qmi_rmnet_set_dl_msg_active(a2);
    v15 = *(_DWORD *)(a2 + 8);
    if ( (v15 & 0x60000000) != 0 )
    {
      result = rmnet_map_flow_command(a1, a2, 0);
      if ( !(_DWORD)result )
        goto LABEL_67;
      v15 = *(_DWORD *)(a2 + 8);
    }
    if ( (v15 & 2) != 0 )
    {
      result = rmnet_map_command(a1, a2);
      goto LABEL_67;
    }
LABEL_18:
    result = sk_skb_reason_drop(0, a1, 2);
    goto LABEL_67;
  }
  v5 = nullptr;
  v6 = *(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212);
  v7 = *(_QWORD *)(v6 + 88);
  if ( v7 && (v7 & 1) == 0 )
    v5 = (char *)((((v7 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
                + *(unsigned int *)(v6 + 100));
  v8 = *v5;
  if ( v8 < 0 )
    goto LABEL_14;
LABEL_7:
  v9 = (unsigned __int8)v5[1];
  if ( v9 == 255 )
    goto LABEL_18;
  v10 = *((unsigned __int16 *)v5 + 1);
  endpoint = rmnet_get_endpoint(a2, v9);
  if ( !endpoint )
    goto LABEL_18;
  v12 = bswap32(v10) >> 16;
  *(_QWORD *)(a1 + 16) = *((_QWORD *)endpoint + 1);
  v13 = *v5;
  v14 = v12 - (v8 & 0x3F);
  if ( (v13 & 0x40) == 0 || (*(_BYTE *)(a2 + 8) & 0x30) == 0 )
  {
    v18 = *(_DWORD *)(a1 + 112);
    v17 = *(_DWORD *)(a1 + 116);
    if ( v18 - v17 <= 3 )
    {
      v23 = v12;
      if ( v18 < 4 )
      {
        v12 = (unsigned int)v12;
        if ( !v17 )
          goto LABEL_31;
LABEL_22:
        if ( *(_DWORD *)(a1 + 112) == v17 )
        {
          v20 = nullptr;
          v21 = *(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212);
          v22 = *(_QWORD *)(v21 + 88);
          if ( v22 && (v22 & 1) == 0 )
            v20 = (_BYTE *)((((v22 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
                          + *(unsigned int *)(v21 + 100));
          goto LABEL_32;
        }
LABEL_31:
        v20 = *(_BYTE **)(a1 + 224);
LABEL_32:
        v25 = *v20 & 0xF0;
        if ( v25 == 96 )
          v26 = -8826;
        else
          v26 = -1792;
        if ( v25 == 64 )
          v27 = 8;
        else
          v27 = v26;
        *(_WORD *)(a1 + 180) = v27;
        if ( (*(_BYTE *)(a2 + 8) & 4) != 0 && !(unsigned int)rmnet_map_checksum_downlink_packet(a1, v12) )
          *(_BYTE *)(a1 + 128) = *(_BYTE *)(a1 + 128) & 0x9F | 0x20;
        if ( *(_DWORD *)(a1 + 112) > (unsigned int)(unsigned __int16)v14 )
        {
          if ( *(_DWORD *)(a1 + 116) )
          {
            __pskb_trim(a1);
          }
          else
          {
            v28 = *(_DWORD *)(a1 + 224);
            v29 = *(_DWORD *)(a1 + 216);
            *(_DWORD *)(a1 + 112) = (unsigned __int16)v14;
            *(_DWORD *)(a1 + 208) = v28 - v29 + (unsigned __int16)v14;
          }
        }
        v30 = v42;
        *(_QWORD *)a1 = &v41;
        *(_QWORD *)(a1 + 8) = v30;
        v42 = (_QWORD **)a1;
        *v30 = a1;
        LODWORD(v43) = v43 + 1;
        goto LABEL_46;
      }
      v24 = _pskb_pull_tail(a1, 4 - (v18 - v17));
      v12 = v23;
      if ( !v24 )
      {
LABEL_21:
        v17 = *(_DWORD *)(a1 + 116);
        if ( !v17 )
          goto LABEL_31;
        goto LABEL_22;
      }
      v18 = *(_DWORD *)(a1 + 112);
    }
    v19 = *(_QWORD *)(a1 + 224);
    *(_DWORD *)(a1 + 112) = v18 - 4;
    *(_QWORD *)(a1 + 224) = v19 + 4;
    goto LABEL_21;
  }
  if ( (unsigned int)rmnet_map_process_next_hdr_packet(a1, &v41, v14) )
    goto LABEL_18;
LABEL_46:
  if ( (*(_BYTE *)(a2 + 11) & 8) != 0 )
  {
    if ( v41 == &v41 )
      v31 = nullptr;
    else
      v31 = v41;
    qmi_rmnet_work_maybe_restart(a2, 0, v31);
  }
  for ( result = (__int64)v41; v41 != &v41 && v41; result = (__int64)v41 )
  {
    LODWORD(v43) = v43 - 1;
    v32 = *(_QWORD *)result;
    v33 = *(_QWORD **)(result + 8);
    *(_QWORD *)result = 0;
    *(_QWORD *)(result + 8) = 0;
    *(_QWORD *)(v32 + 8) = v33;
    *v33 = v32;
    v34 = *(_DWORD *)(result + 116);
    if ( v34 && *(_DWORD *)(result + 112) == v34 )
    {
      v35 = nullptr;
      v36 = *(_QWORD *)(result + 216) + *(unsigned int *)(result + 212);
      v37 = *(_QWORD *)(v36 + 88);
      if ( v37 && (v37 & 1) == 0 )
        v35 = (_BYTE *)((((v37 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
                      + *(unsigned int *)(v36 + 100));
    }
    else
    {
      v35 = *(_BYTE **)(result + 224);
    }
    v38 = *v35 & 0xF0;
    if ( v38 == 96 )
      v39 = -8826;
    else
      v39 = -1792;
    if ( v38 == 64 )
      v40 = 8;
    else
      v40 = v39;
    *(_WORD *)(result + 180) = v40;
    rmnet_deliver_skb(result, a2);
  }
LABEL_67:
  _ReadStatusReg(SP_EL0);
  return result;
}
