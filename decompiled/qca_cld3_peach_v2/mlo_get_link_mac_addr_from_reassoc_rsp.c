__int64 __fastcall mlo_get_link_mac_addr_from_reassoc_rsp(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x4
  __int64 v12; // x8
  __int64 v13; // x8
  _BYTE *v14; // x9
  int v16; // w21
  _BYTE *v17; // x9
  int v18; // w10
  __int16 v19; // w9
  __int64 result; // x0
  const char *v21; // x2
  unsigned int v22; // w1
  const char *v23; // x2
  _BYTE dest[176]; // [xsp+8h] [xbp-B8h] BYREF
  __int64 v25; // [xsp+B8h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
    goto LABEL_14;
  v10 = *(_QWORD *)(a1 + 1360);
  v11 = *(unsigned __int8 *)(a1 + 168);
  if ( !v10 )
  {
    v21 = "%s: mlo dev ctx is null, vdev id %d";
    v22 = 2;
    goto LABEL_13;
  }
  v12 = *(_QWORD *)(v10 + 2224);
  if ( !v12 || (v13 = *(_QWORD *)(v12 + 288)) == 0 || (v14 = *(_BYTE **)(v13 + 144)) == nullptr )
  {
    v21 = "%s: sta ctx or copied reassoc rsp is null for vdev id %d";
    v22 = 8;
LABEL_13:
    qdf_trace_msg(0x8Fu, v22, v21, a3, a4, a5, a6, a7, a8, a9, a10, "mlo_get_link_mac_addr_from_reassoc_rsp", v11);
LABEL_14:
    result = 29;
    goto LABEL_15;
  }
  if ( *v14 != 1 )
  {
    v23 = "%s: Roam auth status is not connected";
LABEL_19:
    qdf_trace_msg(0x8Fu, 8u, v23, a3, a4, a5, a6, a7, a8, a9, a10, "mlo_get_link_mac_addr_from_reassoc_rsp", v11);
    result = 16;
    goto LABEL_15;
  }
  v16 = *(unsigned __int8 *)(a1 + 168);
  memcpy(dest, (const void *)(v13 + 160), sizeof(dest));
  if ( !dest[0] )
  {
LABEL_18:
    v23 = "%s: Link mac addr not found";
    goto LABEL_19;
  }
  if ( dest[20] != v16 )
  {
    if ( dest[0] != 1 )
    {
      if ( dest[68] == v16 )
      {
        v17 = &dest[56];
        goto LABEL_10;
      }
      if ( dest[0] != 2 )
      {
        if ( dest[116] == v16 )
        {
          v17 = &dest[104];
          goto LABEL_10;
        }
        if ( dest[0] != 3 )
          __break(0x5512u);
      }
    }
    goto LABEL_18;
  }
  v17 = &dest[8];
LABEL_10:
  v18 = *(_DWORD *)v17;
  v19 = *((_WORD *)v17 + 2);
  result = 0;
  *(_DWORD *)a2 = v18;
  *(_WORD *)(a2 + 4) = v19;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
