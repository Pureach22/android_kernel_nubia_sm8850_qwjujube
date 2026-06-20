__int64 __fastcall lim_send_probe_req_frame_mlo(__int64 a1, __int64 a2)
{
  unsigned __int16 *v4; // x21
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x1
  __int64 result; // x0
  int v15; // w8

  v4 = (unsigned __int16 *)(a2 + 10872);
  *(_WORD *)(a2 + 10872) = 0;
  qdf_mem_set((void *)(a2 + 10874), 0x92Cu, 0);
  if ( (unsigned int)populate_dot11f_probe_req_mlo_ie(v5, v6, v7, v8, v9, v10, v11, v12, a1, a2) )
    return *v4;
  v15 = v4[12];
  result = v4[1045];
  if ( v4[12] )
  {
    if ( (unsigned int)(v15 - 6) < 0xFFFFFFFB )
    {
      __break(0x5512u);
      return lim_send_tdls_mgmt_frame_mlo(result, v13);
    }
    result = v4[13] + (unsigned int)result;
    if ( v15 != 1 )
    {
      result = v4[271] + (unsigned int)result;
      if ( v15 != 2 )
      {
        result = v4[529] + (unsigned int)result;
        if ( v15 != 3 )
        {
          result = v4[787] + (unsigned int)result;
          if ( v15 != 4 )
            result = v4[1045] + (unsigned int)result;
        }
      }
    }
  }
  if ( (unsigned __int16)result >= 0x102u )
  {
    if ( (unsigned __int8)((unsigned __int16)(result - 513) >> 8) != 255 )
      LODWORD(result) = result + 2 * ((unsigned __int16)(result - 513) / 0xFFu) + 2;
    result = (unsigned int)(result + 2);
  }
  *v4 = result;
  return result;
}
