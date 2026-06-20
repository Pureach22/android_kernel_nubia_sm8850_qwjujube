_WORD *__fastcall wlan_crypto_build_wapiie(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 comp_private_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x21
  _WORD *v22; // x22
  int v23; // w8
  char v24; // w8
  _WORD *v25; // x23
  _WORD *result; // x0
  const char *v27; // x2
  int v28; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v29; // [xsp+8h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
  {
    v27 = "%s: ie buffer NULL";
LABEL_13:
    qdf_trace_msg(0x1Cu, 2u, v27, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_crypto_build_wapiie");
    result = nullptr;
    goto LABEL_16;
  }
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 14);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0x1Cu,
      2u,
      "%s: crypto_priv NULL",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wlan_crypto_vdev_get_comp_params");
    v27 = "%s: crypto_params NULL";
    goto LABEL_13;
  }
  *(_WORD *)(a2 + 4) = 0;
  v21 = comp_private_obj;
  v22 = (_WORD *)(a2 + 6);
  *(_DWORD *)a2 = 65604;
  v23 = *(_DWORD *)(comp_private_obj + 20);
  if ( (v23 & 0x1000) != 0 )
  {
    *(_BYTE *)(a2 + 4) = 1;
    v28 = 41030656;
    qdf_mem_copy((void *)(a2 + 6), &v28, 4u);
    v23 = *(_DWORD *)(v21 + 20);
    v22 = (_WORD *)(a2 + 10);
  }
  if ( (v23 & 0x2000) != 0 )
  {
    v24 = *(_BYTE *)(a2 + 4);
    v28 = 24253440;
    *(_BYTE *)(a2 + 4) = v24 + 1;
    qdf_mem_copy(v22, &v28, 4u);
    v22 += 2;
  }
  *v22 = 0;
  v25 = v22 + 1;
  if ( (*(_BYTE *)(v21 + 4) & 0x10) != 0 )
  {
    *(_BYTE *)v22 = 1;
    v28 = 24253440;
    qdf_mem_copy(v22 + 1, &v28, 4u);
    v25 = v22 + 3;
  }
  v28 = 24253440;
  qdf_mem_copy(v25, &v28, 4u);
  *((_BYTE *)v25 + 4) = *(_BYTE *)(v21 + 152);
  *((_BYTE *)v25 + 5) = *(_BYTE *)(v21 + 153);
  if ( (*(_DWORD *)(a1 + 16) | 2) == 2 )
  {
    result = v25 + 4;
    v25[3] = 0;
  }
  else
  {
    result = v25 + 3;
  }
  *(_BYTE *)(a2 + 1) = (_BYTE)result - a2 - 2;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
