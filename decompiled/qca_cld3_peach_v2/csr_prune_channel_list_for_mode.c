void *__fastcall csr_prune_channel_list_for_mode(void *result, _BYTE *a2)
{
  __int64 v2; // x8
  int v3; // w9
  int v4; // w8
  unsigned int v6; // w20
  unsigned __int64 v7; // x22
  unsigned __int64 v8; // x8
  bool v9; // cf
  unsigned __int64 v10; // x22

  v2 = *((_QWORD *)result + 1);
  v3 = *(_DWORD *)(v2 + 1032);
  v4 = *(_DWORD *)(v2 + 1036);
  if ( !(v3 | v4) )
    return result;
  if ( v4 == 2 )
  {
    if ( !*a2 )
      goto LABEL_19;
    v6 = 0;
    v10 = 1;
    while ( v10 != 101 )
    {
      result = (void *)wlan_reg_is_5ghz_ch_freq(*(_DWORD *)&a2[4 * v10]);
      if ( ((unsigned __int8)result & 1) != 0 )
      {
        if ( v6 > 0x63 )
          break;
        *(_DWORD *)&a2[4 * v6++ + 4] = *(_DWORD *)&a2[4 * v10];
      }
      v8 = (unsigned __int8)*a2;
      v9 = v10++ >= v8;
      if ( v9 )
      {
        if ( (unsigned int)v8 > v6 )
LABEL_21:
          result = qdf_mem_set(&a2[4 * v6 + 4], 4 * ((unsigned int)v8 - v6), 0);
        goto LABEL_22;
      }
    }
  }
  else
  {
    if ( v4 != 1 )
      return result;
    if ( !*a2 )
      goto LABEL_19;
    v6 = 0;
    v7 = 1;
    while ( v7 != 101 )
    {
      result = (void *)wlan_reg_is_24ghz_ch_freq(*(_DWORD *)&a2[4 * v7]);
      if ( ((unsigned __int8)result & 1) != 0 )
      {
        if ( v6 > 0x63 )
          break;
        *(_DWORD *)&a2[4 * v6++ + 4] = *(_DWORD *)&a2[4 * v7];
      }
      v8 = (unsigned __int8)*a2;
      v9 = v7++ >= v8;
      if ( v9 )
      {
        if ( (unsigned int)v8 <= v6 )
          goto LABEL_22;
        goto LABEL_21;
      }
    }
  }
  __break(0x5512u);
LABEL_19:
  LOBYTE(v6) = 0;
LABEL_22:
  *a2 = v6;
  return result;
}
