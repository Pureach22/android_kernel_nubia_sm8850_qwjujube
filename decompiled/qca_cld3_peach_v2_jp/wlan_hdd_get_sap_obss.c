unsigned __int8 *__fastcall wlan_hdd_get_sap_obss(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 v11; // x19
  unsigned __int8 *result; // x0
  size_t v13; // x2
  unsigned __int8 *v14; // x20
  unsigned int v15; // w0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  _QWORD v24[7]; // [xsp+8h] [xbp-88h] BYREF
  int v25; // [xsp+40h] [xbp-50h]
  _QWORD v26[7]; // [xsp+48h] [xbp-48h] BYREF
  __int16 v27; // [xsp+80h] [xbp-10h]
  __int64 v28; // [xsp+88h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *a1;
  v27 = 0;
  memset(v26, 0, sizeof(v26));
  v25 = 0;
  memset(v24, 0, sizeof(v24));
  if ( !v9 || (v10 = *(_QWORD *)(v9 + 24)) == 0 || (v11 = *(_QWORD *)(v10 + 16)) == 0 )
  {
    qdf_trace_msg(0x33u, 8u, "%s: NULL MAC context", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_hdd_get_sap_obss");
    goto LABEL_9;
  }
  result = wlan_get_ie_ptr_from_eid(0x2Du, *(unsigned __int8 **)(a1[270] + 8), *(_DWORD *)(a1[270] + 36));
  if ( result )
  {
    v13 = result[1];
    if ( (unsigned int)(v13 - 1) <= 0x39 )
    {
      v14 = result;
      qdf_mem_copy(v26, result + 2, v13);
      v15 = dot11f_unpack_ie_ht_caps(v11, v26, v14[1], v24, 0);
      if ( (v15 & 0x10000000) == 0 )
      {
        result = (unsigned __int8 *)((*(unsigned __int16 *)((char *)v24 + 1) >> 1) & 1);
        goto LABEL_10;
      }
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: unpack failed, ret: 0x%x",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "wlan_hdd_get_sap_obss",
        v15);
    }
LABEL_9:
    result = nullptr;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
