__int64 __fastcall wlan_crypto_save_ml_sta_key(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        unsigned __int8 *a4,
        unsigned int a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  unsigned int v18; // w23
  __int64 v19; // x6
  __int64 v20; // x7
  int v21; // w8
  int v22; // w9
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 comp_private_obj; // x0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 result; // x0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  unsigned int v49; // w19

  v18 = (unsigned __int8)a2;
  if ( a4 )
  {
    v19 = *a4;
    v20 = a4[1];
    v21 = a4[2];
    v22 = a4[5];
  }
  else
  {
    v21 = 0;
    v19 = 0;
    v20 = 0;
    v22 = 0;
  }
  qdf_trace_msg(
    0x1Cu,
    8u,
    "%s: save crypto key index %d link_id %d link addr %02x:%02x:%02x:**:**:%02x",
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    "wlan_crypto_save_ml_sta_key",
    (unsigned __int8)a2,
    (unsigned __int8)a5,
    v19,
    v20,
    v21,
    v22);
  if ( v18 >= 8 )
  {
    qdf_trace_msg(
      0x1Cu,
      2u,
      "%s: Invalid Key index %d",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "wlan_crypto_save_ml_sta_key",
      v18);
    return 16;
  }
  else
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 14);
    if ( comp_private_obj )
    {
      *(_BYTE *)(a3 + 1) = 1;
      result = crypto_add_entry(comp_private_obj, a5, a4, a3, a2);
      if ( (_DWORD)result )
      {
        v49 = result;
        qdf_trace_msg(
          0x1Cu,
          2u,
          "%s: failed to add crypto entry %d",
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          "wlan_crypto_save_ml_sta_key",
          (unsigned int)result);
        return v49;
      }
      else
      {
        *(_BYTE *)(a3 + 1) = 1;
      }
    }
    else
    {
      qdf_trace_msg(
        0x1Cu,
        2u,
        "%s: crypto_psoc_obj NULL",
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        "wlan_crypto_save_ml_sta_key");
      return 16;
    }
  }
  return result;
}
