__int64 __fastcall wlan_hdd_get_mlo_link_id(__int64 a1, _BYTE *a2, _BYTE *a3)
{
  unsigned __int8 *ext_ie_ptr_from_ext_id; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned __int8 *v14; // x21
  __int64 result; // x0
  __int64 v16; // x10
  unsigned __int8 *v17; // x21
  unsigned int v18; // t1
  int v19; // w8
  int v20; // w9
  unsigned __int8 *v21; // x10
  __int64 v22; // x11

  ext_ie_ptr_from_ext_id = wlan_get_ext_ie_ptr_from_ext_id("k", 1u, *(unsigned __int8 **)(a1 + 8), *(_DWORD *)(a1 + 36));
  if ( ext_ie_ptr_from_ext_id )
  {
    v14 = ext_ie_ptr_from_ext_id;
    result = qdf_trace_msg(
               0x33u,
               8u,
               "%s: ML IE found in beacon data",
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               "wlan_hdd_get_mlo_link_id");
    *a3 = 1;
    v18 = v14[5];
    v17 = v14 + 5;
    v16 = v18;
    v19 = *(v17 - 4) - v18 - 3;
    *a2 = v17[7];
    if ( (_BYTE)v19 )
    {
      v20 = (unsigned __int8)*a3;
      v21 = &v17[v16];
      do
      {
        v22 = v21[1];
        *a3 = ++v20;
        v19 = v19 - v22 - 2;
        v21 += v22 + 2;
      }
      while ( (_BYTE)v19 );
    }
  }
  else
  {
    *a3 = 0;
    return qdf_trace_msg(
             0x33u,
             8u,
             "%s: ML IE not found in beacon data",
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             "wlan_hdd_get_mlo_link_id");
  }
  return result;
}
