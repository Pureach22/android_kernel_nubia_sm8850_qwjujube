__int64 __fastcall lim_send_assoc_rsp_mgmt_frame_mlo(__int64 a1, __int64 a2, __int64 a3, unsigned __int8 *a4)
{
  unsigned __int16 *v6; // x23
  __int64 v9; // x1
  __int64 result; // x0
  int v11; // w8

  v6 = (unsigned __int16 *)(a2 + 10872);
  *(_WORD *)(a2 + 10872) = 0;
  qdf_mem_set((void *)(a2 + 10874), 0x92Cu, 0);
  if ( (unsigned int)populate_dot11f_assoc_rsp_mlo_ie(a1, a2, a3, a4) )
    return *v6;
  v11 = v6[12];
  result = v6[1045];
  if ( v6[12] )
  {
    if ( (unsigned int)(v11 - 6) < 0xFFFFFFFB )
    {
      __break(0x5512u);
      return lim_send_bcn_frame_mlo(result, v9);
    }
    result = v6[13] + (unsigned int)result;
    if ( v11 != 1 )
    {
      result = v6[271] + (unsigned int)result;
      if ( v11 != 2 )
      {
        result = v6[529] + (unsigned int)result;
        if ( v11 != 3 )
        {
          result = v6[787] + (unsigned int)result;
          if ( v11 != 4 )
            result = v6[1045] + (unsigned int)result;
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
  *v6 = result;
  return result;
}
