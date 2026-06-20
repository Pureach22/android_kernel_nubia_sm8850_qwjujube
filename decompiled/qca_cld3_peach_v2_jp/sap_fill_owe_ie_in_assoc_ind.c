void *__fastcall sap_fill_owe_ie_in_assoc_ind(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w8
  const char *v11; // x2
  __int16 v12; // w9
  __int64 v13; // x22
  __int64 v14; // x23
  unsigned __int16 v15; // w21
  unsigned __int8 *ie_ptr_from_eid; // x0
  unsigned __int64 v18; // x8
  unsigned __int64 v19; // x19
  unsigned __int8 *v20; // x20
  unsigned __int8 *ext_ie_ptr_from_ext_id; // x0
  unsigned __int8 *v22; // x21
  unsigned int v23; // w22
  void *result; // x0

  v10 = *(_DWORD *)(a1 + 8);
  if ( (a2 & 1) != 0 )
  {
    if ( v10 <= 9 )
    {
      v11 = "%s: Invalid reassoc req";
LABEL_16:
      qdf_trace_msg(0x39u, 2u, v11, a3, a4, a5, a6, a7, a8, a9, a10, "sap_fill_owe_ie_in_assoc_ind");
      return nullptr;
    }
    v12 = -10;
    v13 = 10;
  }
  else
  {
    if ( v10 <= 3 )
    {
      v11 = "%s: Invalid assoc req";
      goto LABEL_16;
    }
    v12 = -4;
    v13 = 4;
  }
  v14 = *(_QWORD *)(a1 + 16);
  v15 = v12 + v10;
  ie_ptr_from_eid = wlan_get_ie_ptr_from_eid(0x30u, (unsigned __int8 *)(v14 + v13), v12 + (unsigned __int16)v10);
  if ( !ie_ptr_from_eid )
  {
    v11 = "%s: RSN IE is not present";
    goto LABEL_16;
  }
  v18 = ie_ptr_from_eid[1];
  v19 = v18 + 2;
  if ( v18 >= 0x89 )
  {
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: Invalid RSN IE len %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "sap_fill_owe_ie_in_assoc_ind",
      (unsigned int)v19);
    return nullptr;
  }
  v20 = ie_ptr_from_eid;
  ext_ie_ptr_from_ext_id = wlan_get_ext_ie_ptr_from_ext_id(" ", 1u, (unsigned __int8 *)(v14 + v13), v15);
  if ( !ext_ie_ptr_from_ext_id )
  {
    v11 = "%s: DH IE is not present";
    goto LABEL_16;
  }
  v22 = ext_ie_ptr_from_ext_id;
  v23 = ext_ie_ptr_from_ext_id[1] + 2;
  qdf_trace_msg(
    0x39u,
    8u,
    "%s: rsn_ie_len = %d, dh_ie_len = %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "sap_fill_owe_ie_in_assoc_ind",
    (unsigned int)v19,
    v23);
  result = (void *)_qdf_mem_malloc(v23 + (unsigned int)v19, "sap_fill_owe_ie_in_assoc_ind", 2203);
  *(_QWORD *)(a1 + 32) = result;
  if ( result )
  {
    qdf_mem_copy(result, v20, (unsigned int)v19);
    qdf_mem_copy((void *)(*(_QWORD *)(a1 + 32) + v19), v22, v23);
    *(_DWORD *)(a1 + 28) = v23 + v19;
    return &off_0 + 1;
  }
  return result;
}
