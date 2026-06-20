__int64 __fastcall dp_tx_ext_desc_pool_init(__int64 a1, unsigned __int8 a2, unsigned __int16 a3)
{
  __int64 v3; // x29
  __int64 v4; // x30
  unsigned __int8 v8; // w19
  unsigned int v9; // w0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v19; // x4
  unsigned int v20; // w19
  __int64 v21; // [xsp+8h] [xbp-28h]

  if ( !a2 )
    return 0;
  v21 = v4;
  v8 = 0;
  while ( 1 )
  {
    v9 = dp_tx_ext_desc_pool_init_by_id(a1, a3, v8);
    if ( v9 )
      break;
    if ( ++v8 >= (unsigned int)a2 )
      return 0;
  }
  v19 = v8;
  v20 = v9;
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: failed to init ext desc pool %d",
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    "dp_tx_ext_desc_pool_init",
    v19,
    v3,
    v21);
  return v20;
}
