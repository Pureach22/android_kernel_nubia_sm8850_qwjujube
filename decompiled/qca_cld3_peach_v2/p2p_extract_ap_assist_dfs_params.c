__int64 __fastcall p2p_extract_ap_assist_dfs_params(__int64 a1, int a2, int a3, char a4, unsigned int a5, char a6)
{
  __int64 comp_private_obj; // x0
  __int64 v13; // x23
  __int64 v14; // x22
  unsigned int v15; // w20
  __int64 result; // x0
  __int64 v17; // x24
  int v18; // w1
  int v19; // w2
  int v20; // w3
  __int64 v21; // x8
  unsigned __int64 v22; // x9
  bool v23; // zf
  _QWORD v24[15]; // [xsp+8h] [xbp-78h] BYREF

  v24[14] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v24, 0, 107);
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 5u);
  if ( !comp_private_obj || (v13 = *(_QWORD *)(a1 + 216)) == 0 )
  {
    result = 4;
    goto LABEL_6;
  }
  if ( (a6 & 1) != 0 )
  {
    v14 = comp_private_obj;
    v15 = p2p_parse_p2p2_ie(a2, a3, 1, (int)comp_private_obj + 958);
    p2p_validate_ap_assist_params(v13, v14 + 958, a5);
    result = v15;
LABEL_6:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v17 = comp_private_obj;
  p2p_parse_p2p2_ie(a2, a3, a4 & 1, (int)v24);
  p2p_validate_ap_assist_params(v13, v24, a5);
  if ( BYTE5(v24[0]) != 1 || !BYTE6(v24[0]) )
  {
    result = 16;
    goto LABEL_6;
  }
  v21 = 0;
  v22 = 0;
  result = 16;
  while ( v22 != 10 )
  {
    if ( v21 == 100 )
    {
      __break(1u);
      break;
    }
    if ( (*((_BYTE *)v24 + v21 + 7) & 1) != 0
      || (*(_DWORD *)((char *)&v24[1] + v21 + 1) == *(_DWORD *)(v17 + 967)
        ? (v23 = *(unsigned __int16 *)((char *)&v24[1] + v21 + 5) == *(unsigned __int16 *)(v17 + 971))
        : (v23 = 0),
          v23) )
    {
      result = 0;
      goto LABEL_6;
    }
    ++v22;
    v21 += 10;
    if ( v22 >= BYTE6(v24[0]) )
      goto LABEL_6;
  }
  __break(0x5512u);
  return p2p_parse_p2p2_ie(16, v18, v19, v20);
}
