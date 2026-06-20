__int64 __fastcall lim_add_sta_self(__int64 a1, char a2, __int64 a3)
{
  __int16 v6; // w8
  __int64 v7; // x9
  int v8; // w8
  int v9; // w23
  __int64 v10; // x0
  __int64 v11; // x21
  __int64 v12; // x3
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int16 v21; // w8
  __int64 v22; // x8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  int v31; // w8
  char v32; // w8
  unsigned int v33; // w19
  int v34; // w8
  int v35; // w10
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v45; // [xsp+18h] [xbp-48h]
  __int64 v46; // [xsp+20h] [xbp-40h] BYREF
  __int64 v47; // [xsp+28h] [xbp-38h]
  __int64 v48; // [xsp+30h] [xbp-30h]
  __int64 v49; // [xsp+38h] [xbp-28h]
  __int64 v50; // [xsp+40h] [xbp-20h]
  __int64 v51; // [xsp+48h] [xbp-18h]
  __int64 v52; // [xsp+50h] [xbp-10h] BYREF
  __int64 v53; // [xsp+58h] [xbp-8h]

  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_WORD *)(a3 + 30);
  v7 = *(_QWORD *)(a1 + 8);
  v50 = 0;
  v51 = 0;
  LOWORD(v52) = v6;
  v8 = *(_DWORD *)(a3 + 32);
  v9 = *(_DWORD *)(v7 + 5748);
  v48 = 0;
  v49 = 0;
  v46 = 0;
  v47 = 0;
  *(_DWORD *)((char *)&v52 + 2) = v8;
  v10 = _qdf_mem_malloc(0x110u, "lim_add_sta_self", 2922);
  if ( v10 )
  {
    v11 = v10;
    qdf_mem_copy((void *)(v10 + 9), &v52, 6u);
    qdf_mem_copy((void *)v11, (const void *)(a3 + 24), 6u);
    v21 = *(_WORD *)(a3 + 180);
    *(_BYTE *)(v11 + 8) = 0;
    *(_DWORD *)(v11 + 100) = 0;
    *(_WORD *)(v11 + 6) = v21;
    *(_BYTE *)(v11 + 112) = *(_BYTE *)(a3 + 8);
    *(_BYTE *)(v11 + 131) = *(_BYTE *)(a3 + 10);
    LOBYTE(v21) = *(_BYTE *)(a3 + 7032);
    *(_BYTE *)(v11 + 104) = a2;
    *(_BYTE *)(v11 + 148) = v21;
    v22 = *(_QWORD *)(a3 + 112);
    if ( v22 || (v22 = *(_QWORD *)(a3 + 120)) != 0 )
      mlme_set_mbssid_info(
        *(_QWORD *)(a3 + 16),
        (unsigned __int8 *)(v22 + 4413),
        *(_DWORD *)(a3 + 284),
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20);
    lim_populate_own_rate_set(a1, (_BYTE *)(v11 + 36), nullptr, v13, v14, v15, v16, v17, v18, v19, v20, v12, a3, 0, 0);
    if ( (unsigned int)(v9 - 7) < 7 || v9 == 5 || !v9 )
    {
      *(_BYTE *)(v11 + 21) = 1;
      *(_DWORD *)(v11 + 24) = *(_DWORD *)(a1 + 17124);
      *(_DWORD *)(v11 + 28) = (unsigned __int8)lim_get_ht_capability(a1, 11, a3);
      *(_BYTE *)(v11 + 33) = lim_get_ht_capability(a1, 15, a3);
      *(_BYTE *)(v11 + 32) = lim_get_ht_capability(a1, 14, a3);
      *(_BYTE *)(v11 + 35) = (*(_BYTE *)(a3 + 7266) & 0x20) != 0;
      *(_BYTE *)(v11 + 34) = (*(_BYTE *)(a3 + 7266) & 0x40) != 0;
    }
    v31 = *(unsigned __int8 *)(a3 + 7170);
    *(_BYTE *)(v11 + 115) = v31;
    if ( v31 )
      *(_DWORD *)(v11 + 24) = *(_DWORD *)(a3 + 7176);
    *(_BYTE *)(v11 + 120) = (*(_DWORD *)(a3 + 7268) & 0x1000) != 0;
    *(_BYTE *)(v11 + 121) = (*(_DWORD *)(a3 + 7268) & 0x800) != 0;
    if ( *(_BYTE *)(a3 + 7170) )
      *(_BYTE *)(v11 + 32) = *(_BYTE *)(*(_QWORD *)(a1 + 8) + 2673LL);
    *(_BYTE *)(v11 + 122) = (*(_DWORD *)(a3 + 7268) & 0x100000) != 0;
    *(_BYTE *)(v11 + 123) = *(_BYTE *)(a3 + 7185);
    *(_BYTE *)(v11 + 124) = *(_BYTE *)(a3 + 7190);
    if ( *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1280LL) == 1 )
      v32 = *(_BYTE *)(a3 + 8653) ^ 1;
    else
      v32 = 0;
    *(_BYTE *)(v11 + 125) = v32 & 1;
    *(_BYTE *)(v11 + 126) = *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1281LL);
    *(_BYTE *)(v11 + 127) = *(_BYTE *)(a3 + 7191);
    *(_BYTE *)(v11 + 128) = *(_BYTE *)(a3 + 7236) & 1;
    *(_BYTE *)(v11 + 129) = (*(_BYTE *)(a3 + 7236) & 2) != 0;
    *(_WORD *)(v11 + 16) = *(_WORD *)(*(_QWORD *)(a1 + 8) + 3204LL);
    if ( *(_DWORD *)(a3 + 7036) == 2 )
      *(_BYTE *)(v11 + 113) = 1;
    if ( *(_BYTE *)(a3 + 7864) == 1 )
    {
      *(_BYTE *)(v11 + 149) = 1;
      *(_BYTE *)(a3 + 7864) = 0;
    }
    if ( (unsigned int)(v9 - 10) < 4 || !v9 )
      lim_add_self_he_cap(v11, a3);
    if ( (**(_BYTE **)(a3 + 9976) & 1) != 0 )
    {
      v34 = 1;
      *(_BYTE *)(v11 + 243) = 1;
    }
    else
    {
      v34 = *(unsigned __int8 *)(v11 + 243);
    }
    v35 = *(unsigned __int16 *)(v11 + 16);
    v46 = 4129;
    v47 = v11;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: %02x:%02x:%02x:**:**:%02x: vdev %d Sending WMA_ADD_STA_REQ LI %d no_ptk:%d",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "lim_add_sta_self",
      *(unsigned __int8 *)(v11 + 9),
      *(unsigned __int8 *)(v11 + 10),
      *(unsigned __int8 *)(v11 + 11),
      *(unsigned __int8 *)(v11 + 14),
      *(unsigned __int8 *)(a3 + 10),
      v35,
      v34,
      v45,
      4129,
      v11,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53);
    mac_trace_msg_tx(a1, *(unsigned __int8 *)(a3 + 8), 4129);
    v33 = wma_post_ctrl_msg(a1, &v46);
    if ( v33 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Posting WMA_ADD_STA_REQ to HAL failed, reason=%X",
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        "lim_add_sta_self",
        v33);
      _qdf_mem_free(v11);
    }
  }
  else
  {
    v33 = 2;
  }
  _ReadStatusReg(SP_EL0);
  return v33;
}
