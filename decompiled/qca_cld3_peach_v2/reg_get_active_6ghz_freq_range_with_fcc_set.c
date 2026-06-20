__int64 __fastcall reg_get_active_6ghz_freq_range_with_fcc_set(__int64 a1, _WORD *a2)
{
  unsigned int v2; // w22
  unsigned int v3; // w23
  __int64 v6; // x20
  __int64 result; // x0
  __int64 v8; // x21
  unsigned int v9; // w24
  __int64 connected_chan_for_mode; // x0
  __int64 v11; // x0
  unsigned __int16 *v12; // x8

  v2 = *(_DWORD *)(a1 + 1512);
  v3 = *(_DWORD *)(a1 + 3636);
  v6 = ((__int64 (*)(void))reg_get_connected_chan_for_mode)();
  result = reg_get_connected_chan_for_mode(a1, 2, v2, v3);
  v8 = result;
  if ( !v6 || !result )
  {
    if ( v6 )
    {
      v9 = *(_DWORD *)(v6 + 24);
      if ( v9 > 7 )
        return result;
    }
    else
    {
      if ( !result )
        return result;
      v9 = *(_DWORD *)(result + 24);
      if ( v9 > 7 )
        return result;
    }
LABEL_13:
    connected_chan_for_mode = reg_get_connected_chan_for_mode(a1, 1, v2, v3);
    if ( connected_chan_for_mode && v9 <= *(_DWORD *)(connected_chan_for_mode + 24) )
      v9 = *(_DWORD *)(connected_chan_for_mode + 24);
    v11 = reg_get_connected_chan_for_mode(a1, 3, v2, v3);
    if ( v11 && v9 <= *(_DWORD *)(v11 + 24) )
      v9 = *(_DWORD *)(v11 + 24);
    if ( v6 | v8 )
    {
      if ( v6 )
        v12 = (unsigned __int16 *)v6;
      else
        v12 = (unsigned __int16 *)v8;
      result = *v12;
      if ( v9 )
        goto LABEL_24;
    }
    else
    {
      result = 0;
      if ( v9 )
      {
LABEL_24:
        result = reg_get_bonded_chan_entry(result, v9, 0);
        if ( result )
          return (__int64)qdf_mem_copy(a2, (const void *)result, 4u);
        return result;
      }
    }
    *a2 = result;
    a2[1] = result;
    return result;
  }
  if ( *(_DWORD *)(v6 + 24) <= *(_DWORD *)(result + 24) )
    v9 = *(_DWORD *)(result + 24);
  else
    v9 = *(_DWORD *)(v6 + 24);
  if ( v9 <= 7 )
    goto LABEL_13;
  return result;
}
