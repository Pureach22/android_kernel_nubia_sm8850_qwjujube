__int64 __fastcall lim_set_mlo_caps(__int64 a1, __int64 a2, unsigned __int8 *a3, unsigned __int16 a4)
{
  __int64 result; // x0
  unsigned __int16 *v9; // x20
  unsigned __int8 *ext_ie_ptr_from_ext_id; // x0
  int v11; // w9
  unsigned int v12; // w9
  unsigned int v13; // w9
  unsigned int v14; // w9
  unsigned int v15; // w9
  unsigned int v16; // w9
  unsigned int v17; // w9
  unsigned int v18; // w9

  result = _qdf_mem_malloc(0x92Cu, "lim_set_mlo_caps", 8520);
  if ( result )
  {
    v9 = (unsigned __int16 *)result;
    populate_dot11f_mlo_caps(a1, a2, result);
    ext_ie_ptr_from_ext_id = wlan_get_ext_ie_ptr_from_ext_id("k", 1u, a3, a4);
    if ( ext_ie_ptr_from_ext_id )
    {
      v11 = *(_WORD *)(ext_ie_ptr_from_ext_id + 3) & 0xFFF8 | *v9 & 7;
      *(_WORD *)(ext_ie_ptr_from_ext_id + 3) = *(_WORD *)(ext_ie_ptr_from_ext_id + 3) & 0xFFF8 | *v9 & 7;
      v12 = v11 & 0xFFFFFFF7 | (8 * ((*v9 >> 3) & 1));
      *(_WORD *)(ext_ie_ptr_from_ext_id + 3) = v12;
      v13 = v12 & 0xFFFFFFEF | (16 * ((*v9 >> 4) & 1));
      *(_WORD *)(ext_ie_ptr_from_ext_id + 3) = v13;
      v14 = v13 & 0xFFFFFFDF | (32 * ((*v9 >> 5) & 1));
      *(_WORD *)(ext_ie_ptr_from_ext_id + 3) = v14;
      v15 = v14 & 0xFFFFFFBF | (((*v9 >> 6) & 1) << 6);
      *(_WORD *)(ext_ie_ptr_from_ext_id + 3) = v15;
      v16 = v15 & 0xFFFFFF7F | (((*v9 >> 7) & 1) << 7);
      *(_WORD *)(ext_ie_ptr_from_ext_id + 3) = v16;
      v17 = v16 & 0xFFFFFEFF | ((HIBYTE(*v9) & 1) << 8);
      *(_WORD *)(ext_ie_ptr_from_ext_id + 3) = v17;
      v18 = v17 & 0xFFFFFDFF | (((*v9 >> 9) & 1) << 9);
      *(_WORD *)(ext_ie_ptr_from_ext_id + 3) = v18;
      LOWORD(v18) = v18 & 0xFBFF | (((*v9 >> 10) & 1) << 10);
      *(_WORD *)(ext_ie_ptr_from_ext_id + 3) = v18;
      *(_WORD *)(ext_ie_ptr_from_ext_id + 3) = v18 & 0x7FF | (*v9 >> 12 << 11);
      ext_ie_ptr_from_ext_id[5] = *((_BYTE *)v9 + 2);
      qdf_mem_copy(ext_ie_ptr_from_ext_id + 6, (char *)v9 + 3, 6u);
      a3[1] += 6;
    }
    return _qdf_mem_free((__int64)v9);
  }
  return result;
}
