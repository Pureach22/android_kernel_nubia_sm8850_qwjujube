__int64 __fastcall wifi_pos_move_peers_to_fail_list(__int64 result, __int64 a2, int a3)
{
  __int64 v3; // x19
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x20
  __int64 v16; // x13
  __int64 v17; // x8
  __int64 v18; // x9
  const char *v21; // x2
  __int64 v22; // x21
  int v24; // w11
  int v25; // [xsp+0h] [xbp-10h] BYREF
  __int16 v26; // [xsp+4h] [xbp-Ch]
  __int64 v27; // [xsp+8h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(result + 16) )
    goto LABEL_31;
  v3 = result;
  result = wifi_pos_get_vdev_priv_obj(result);
  if ( !result )
  {
    v21 = "%s: Wifi pos vdev priv obj is null";
    goto LABEL_30;
  }
  v14 = result;
  if ( *(_DWORD *)a2 == -1 && *(__int16 *)(a2 + 4) == -1 )
  {
    if ( a3 == 1 )
    {
      v22 = 16;
      do
      {
        if ( *(_DWORD *)v14 != -1 || *(__int16 *)(v14 + 4) != -1 )
        {
          result = wifi_pos_set_11az_failed_peers(v3, (unsigned __int8 *)v14);
          *(_WORD *)(v14 + 4) = -1;
          *(_DWORD *)v14 = -1;
        }
        --v22;
        v14 += 380;
      }
      while ( v22 );
      goto LABEL_31;
    }
    v21 = "%s: No Valid list exists";
LABEL_30:
    result = qdf_trace_msg(0x25u, 2u, v21, v6, v7, v8, v9, v10, v11, v12, v13, "wifi_pos_move_peers_to_fail_list");
    goto LABEL_31;
  }
  v16 = 16;
  v17 = 6080;
  v18 = result;
  while ( *(_DWORD *)a2 != *(_DWORD *)v18 || *(unsigned __int16 *)(a2 + 4) != *(unsigned __int16 *)(v18 + 4) )
  {
    if ( *(_DWORD *)a2 == *(_DWORD *)(v18 + 6084) && *(unsigned __int16 *)(a2 + 4) == *(unsigned __int16 *)(v18 + 6088) )
    {
      v18 += 6084;
      v17 = 12164;
      break;
    }
    --v16;
    v18 += 380;
    if ( !v16 )
      goto LABEL_31;
  }
  v24 = *(_DWORD *)v18;
  v26 = *(_WORD *)(v18 + 4);
  v25 = v24;
  *(_WORD *)(v18 + 4) = -1;
  *(_DWORD *)v18 = -1;
  --*(_BYTE *)(result + v17);
  result = wifi_pos_set_11az_failed_peers(v3, (unsigned __int8 *)&v25);
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return result;
}
