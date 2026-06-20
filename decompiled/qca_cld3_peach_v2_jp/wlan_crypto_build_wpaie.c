_BYTE *__fastcall wlan_crypto_build_wpaie(__int64 a1, __int64 a2)
{
  __int64 comp_private_obj; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x20
  _WORD *v13; // x22
  int v14; // w8
  _BYTE *result; // x0
  _BYTE *v16; // x21
  int v17; // w8
  char v18; // w8
  int v19; // w8
  unsigned int v20; // w8
  int v21; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
  {
    result = nullptr;
    goto LABEL_25;
  }
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 14);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0x1Cu,
      2u,
      "%s: crypto_priv NULL",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "wlan_crypto_vdev_get_comp_params");
    result = nullptr;
    goto LABEL_25;
  }
  v12 = comp_private_obj;
  *(_WORD *)a2 = 221;
  v21 = 32657408;
  qdf_mem_copy((void *)(a2 + 2), &v21, 4u);
  v13 = (_WORD *)(a2 + 8);
  *(_WORD *)(a2 + 6) = 1;
  v14 = *(_DWORD *)(v12 + 8);
  if ( (v14 & 2) != 0 )
  {
    v21 = 49434624;
    goto LABEL_9;
  }
  if ( (v14 & 8) != 0 )
  {
    v21 = 82989056;
LABEL_9:
    qdf_mem_copy((void *)(a2 + 8), &v21, 4u);
    v13 = (_WORD *)(a2 + 12);
  }
  *v13 = 0;
  v16 = v13 + 1;
  v17 = *(_DWORD *)(v12 + 4);
  if ( (v17 & 8) != 0 )
  {
    *(_BYTE *)v13 = 1;
    v21 = 82989056;
    qdf_mem_copy(v13 + 1, &v21, 4u);
    v17 = *(_DWORD *)(v12 + 4);
    v16 = v13 + 3;
  }
  if ( (v17 & 2) != 0 )
  {
    v18 = *(_BYTE *)v13;
    v21 = 49434624;
    *(_BYTE *)v13 = v18 + 1;
    qdf_mem_copy(v16, &v21, 4u);
    v16 += 4;
  }
  *(_WORD *)v16 = 0;
  v19 = *(_DWORD *)(v12 + 20);
  if ( (v19 & 1) != 0 )
  {
    *v16 = 1;
    v21 = 32657408;
  }
  else if ( (v19 & 2) != 0 )
  {
    *v16 = 1;
    v21 = 49434624;
  }
  else
  {
    *v16 = 1;
    if ( (v19 & 0x4000) != 0 )
      v21 = 9846784;
    else
      v21 = 15880192;
  }
  qdf_mem_copy(v16 + 2, &v21, 4u);
  v20 = *(unsigned __int16 *)(v12 + 152);
  if ( v20 >= 2 )
  {
    v16[6] = v20;
    result = v16 + 8;
    v16[7] = *(_BYTE *)(v12 + 153);
  }
  else
  {
    result = v16 + 6;
  }
  *(_BYTE *)(a2 + 1) = (_BYTE)result - a2 - 2;
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
