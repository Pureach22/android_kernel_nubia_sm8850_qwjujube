char *__fastcall hdd_filter_ft_info(unsigned __int8 *a1, __int16 a2, _DWORD *a3)
{
  unsigned __int16 v4; // w25
  unsigned __int8 *ie_ptr_from_eid; // x0
  unsigned __int8 *v7; // x19
  unsigned int v8; // w20
  unsigned __int8 *v9; // x0
  unsigned __int8 *v10; // x22
  unsigned int v11; // w23
  unsigned __int8 *v12; // x0
  unsigned __int8 *v13; // x24
  unsigned int v14; // w25
  size_t v15; // x0
  char *v16; // x0
  char *v17; // x21

  v4 = a2 - 30;
  ie_ptr_from_eid = wlan_get_ie_ptr_from_eid(0x30u, a1, a2 - 30);
  v7 = ie_ptr_from_eid;
  if ( ie_ptr_from_eid )
  {
    v8 = ie_ptr_from_eid[1] + 2;
    ((void (__fastcall *)(__int64, __int64, unsigned __int8 *, _QWORD))qdf_trace_hex_dump)(51, 8, ie_ptr_from_eid, v8);
  }
  else
  {
    v8 = 0;
  }
  v9 = wlan_get_ie_ptr_from_eid(0x36u, a1, v4);
  v10 = v9;
  if ( v9 )
  {
    v11 = v9[1] + 2;
    ((void (__fastcall *)(__int64, __int64, unsigned __int8 *, _QWORD))qdf_trace_hex_dump)(51, 8, v9, v11);
  }
  else
  {
    v11 = 0;
  }
  v12 = wlan_get_ie_ptr_from_eid(0x37u, a1, v4);
  v13 = v12;
  if ( v12 )
    v14 = v12[1] + 2;
  else
    v14 = 0;
  v15 = v11 + v8 + v14;
  *a3 = v15;
  v16 = (char *)_qdf_mem_malloc(v15, "hdd_filter_ft_info", 3245);
  v17 = v16;
  if ( v16 )
  {
    if ( v8 )
      qdf_mem_copy(v16, v7, v8);
    if ( v11 )
      qdf_mem_copy(&v17[v8], v10, v11);
    if ( v14 )
      qdf_mem_copy(&v17[v8 + v11], v13, v14);
  }
  return v17;
}
