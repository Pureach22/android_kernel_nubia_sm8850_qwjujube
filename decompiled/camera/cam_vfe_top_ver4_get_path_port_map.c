__int64 __fastcall cam_vfe_top_ver4_get_path_port_map(__int64 result, unsigned int *a2)
{
  _DWORD *v2; // x8
  unsigned int v3; // w9

  v2 = *(_DWORD **)(result + 16);
  v3 = v2[27];
  if ( !v3 )
    goto LABEL_5;
  a2[1] = v2[35];
  a2[2] = v2[36];
  v3 = v2[27];
  if ( v3 <= 1 )
    goto LABEL_5;
  a2[3] = v2[37];
  a2[4] = v2[38];
  v3 = v2[27];
  if ( v3 >= 3 && (a2[5] = v2[39], a2[6] = v2[40], v3 = v2[27], v3 > 3) )
  {
    __break(0x5512u);
    return cam_vfe_init_config_update(result, a2);
  }
  else
  {
LABEL_5:
    *a2 = v3;
  }
  return result;
}
