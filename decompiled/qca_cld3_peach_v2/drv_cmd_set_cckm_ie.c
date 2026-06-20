__int64 __fastcall drv_cmd_set_cckm_ie(__int64 a1, __int64 *a2, char *s)
{
  size_t v6; // x0
  unsigned __int8 *v7; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  int v16; // w8
  unsigned __int8 *v17; // x23
  char v18; // t1
  unsigned __int8 v19; // w8
  __int64 v20; // x9
  int v21; // w10
  unsigned __int8 v22; // w22
  __int64 v23; // x0
  _BYTE *v24; // x21
  __int64 v25; // x24
  unsigned __int64 v26; // x25
  char v27; // w0
  unsigned int v28; // t1
  char v29; // w22
  char v30; // w0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  bool v39; // zf
  unsigned int v40; // w19

  v6 = strlen(s);
  v7 = (unsigned __int8 *)strnchr(s, v6, 32);
  if ( !v7 )
    goto LABEL_16;
  v16 = *v7;
  if ( v16 != 32 )
    goto LABEL_16;
  v17 = v7 + 1;
  while ( (unsigned __int8)v16 == 32 )
  {
    v18 = *++v7;
    LOBYTE(v16) = v18;
    ++v17;
  }
  if ( !(_BYTE)v16 )
    goto LABEL_16;
  v19 = 0;
  v20 = 1;
  do
  {
    v21 = v7[v20];
    v22 = v20;
    ++v19;
    ++v20;
  }
  while ( v21 );
  if ( !v19 )
  {
LABEL_16:
    v40 = -22;
LABEL_17:
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to parse cckm ie data",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "drv_cmd_set_cckm_ie");
    return v40;
  }
  v23 = _qdf_mem_malloc(((unsigned __int64)v19 + 1) >> 1, "hdd_parse_get_cckm_ie", 2534);
  if ( !v23 )
  {
    v40 = -12;
    goto LABEL_17;
  }
  v24 = (_BYTE *)v23;
  v25 = 0;
  v26 = ((unsigned __int64)v22 - 1) >> 1;
  do
  {
    v27 = hex_to_bin(*(v17 - 1));
    v28 = *v17;
    v17 += 2;
    v29 = v27;
    v30 = hex_to_bin(v28);
    v39 = v26 + 1 == v25 + 1;
    v24[v25++] = v30 | (16 * v29);
  }
  while ( !v39 );
  if ( (unsigned __int8)(v26 + 1) < 0x8Bu )
  {
    ucfg_cm_set_cckm_ie(*a2, *(unsigned __int8 *)(a1 + 8), v24, v26 + 1);
    _qdf_mem_free((__int64)v24);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: CCKM Ie input length is more than max[%d]",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "drv_cmd_set_cckm_ie",
      138);
    _qdf_mem_free((__int64)v24);
    return (unsigned int)-22;
  }
}
