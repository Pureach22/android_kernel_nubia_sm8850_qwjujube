__int64 __fastcall dp_rx_page_pool_alloc(__int64 a1, unsigned int a2, int a3)
{
  __int64 v4; // x0
  __int64 v5; // x21
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned __int64 v22; // x8
  __int64 v23; // x27
  signed int v24; // w24
  __int64 v25; // x0
  unsigned __int64 v26; // x22
  __int64 v27; // x26
  unsigned int v28; // w23
  __int64 v29; // x24
  __int64 v30; // x28
  __int64 v31; // x19
  __int64 v33; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  _QWORD *v42; // x8
  __int64 v43; // x6
  char v44; // w9
  __int64 v45; // x0
  char v46; // w10
  __int64 result; // x0
  _BYTE v49[4]; // [xsp+14h] [xbp-2Ch] BYREF
  __int64 v50; // [xsp+18h] [xbp-28h] BYREF
  __int64 v51; // [xsp+20h] [xbp-20h] BYREF
  __int64 v52; // [xsp+28h] [xbp-18h] BYREF
  _QWORD v53[2]; // [xsp+30h] [xbp-10h] BYREF

  v53[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 >= 5 )
    goto LABEL_31;
  v4 = *(_QWORD *)(a1 + 40);
  LODWORD(v5) = a3;
  v52 = 0;
  v53[0] = 0;
  v50 = 0;
  v51 = 0;
  v49[0] = 0;
  if ( (wlan_cfg_get_dp_rx_buffer_recycle(v4) & 1) == 0 )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: RX buffer recycle disabled from INI",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "dp_rx_page_pool_alloc");
LABEL_29:
    result = 16;
    goto LABEL_30;
  }
  ((void (__fastcall *)(__int64, _QWORD *, __int64 *))dp_rx_get_num_buff_descs_info)(a1, v53, &v52);
  v22 = *(_QWORD *)(a1 + 544LL * a2 + 20504);
  if ( !v22 )
  {
    v22 = v53[0];
    if ( v53[0] )
    {
      *(_QWORD *)(a1 + 544LL * a2 + 20504) = v53[0];
      LODWORD(v5) = v22;
    }
    else
    {
      v22 = 4096;
      *(_QWORD *)(a1 + 544LL * a2 + 20504) = 4096;
    }
  }
  v23 = (unsigned int)v5;
  if ( v22 >= (unsigned int)v5 )
  {
    v24 = 1;
  }
  else
  {
    v23 = (unsigned int)v5 % (unsigned int)v22;
    if ( (_DWORD)v23 )
      v24 = (unsigned int)v5 / (unsigned int)v22 + 1;
    else
      v24 = (unsigned int)v5 / (unsigned int)v22;
    if ( v24 >= 5 )
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: Failed to allocate page pools, invalid pool count %d",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "dp_rx_page_pool_alloc",
        (unsigned int)v24);
      goto LABEL_29;
    }
  }
  v25 = *(_QWORD *)(a1 + 40);
  *(_DWORD *)(a1 + 544LL * a2 + 20480) = 0;
  *(_QWORD *)(a1 + 544LL * a2 + 20488) = 0;
  *(_BYTE *)(a1 + 544LL * a2 + 20664) = 0;
  *(_QWORD *)(a1 + 544LL * a2 + 20464) = a1;
  v26 = ((int)wlan_cfg_rx_buffer_size(v25) + 447LL) & 0xFFFFFFFFFFFFFFC0LL;
  if ( v24 >= 1 )
  {
    v27 = 48LL * (unsigned int)(v24 - 1);
    v28 = 0;
    v29 = 48LL * (unsigned int)v24;
    v30 = 0;
    v31 = a1 + 544LL * a2;
    while ( v30 != 240 )
    {
      if ( v27 != v30 || v23 == 0 )
        v5 = 4096;
      else
        v5 = (unsigned int)v23;
      v33 = _dp_rx_page_pool_create(a1, (unsigned int)v5, v26, &v51, &v50, v49);
      if ( !v33 )
        goto LABEL_28;
      v42 = (_QWORD *)(v31 + v30);
      v43 = v50;
      v44 = v49[0];
      v42[2530] = v33;
      v42[2531] = v5;
      v42[2532] = v43;
      *(_BYTE *)(v31 + 20264 + v30) = v44;
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: Page pool idx %d pool_size %d pp_size %zu",
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        "dp_rx_page_pool_alloc",
        v28,
        (unsigned int)v5);
      v30 += 48;
      ++v28;
      if ( v29 == v30 )
        goto LABEL_26;
    }
LABEL_31:
    __break(0x5512u);
  }
LABEL_26:
  *(_QWORD *)(a1 + 544LL * a2 + 20440) = 2048;
  v49[0] = 0;
  v45 = _dp_rx_page_pool_create(a1, 2048, v26, &v51, &v50, v49);
  *(_QWORD *)(a1 + 544LL * a2 + 20432) = v45;
  if ( !v45
    || (v46 = v49[0],
        *(_QWORD *)(a1 + 544LL * a2 + 20448) = v50,
        *(_QWORD *)(a1 + 544LL * a2 + 20496) = (unsigned int)v5,
        *(_BYTE *)(a1 + 544LL * a2 + 20456) = v46,
        *(_QWORD *)(a1 + 544LL * a2 + 20752) = v26 - 384,
        *(_DWORD *)(a1 + 544LL * a2 + 20760) = 0,
        result = dp_rx_page_pool_init(a1, a2),
        (_DWORD)result) )
  {
LABEL_28:
    ((void (__fastcall *)(__int64, _QWORD))dp_rx_page_pool_free)(a1, a2);
    goto LABEL_29;
  }
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
