__int64 __fastcall target_if_cfr_update_global_cfg(__int64 a1)
{
  __int64 result; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x19
  char v11; // w20
  __int64 v12; // x21
  unsigned int *v13; // x22
  unsigned int v14; // w8

  result = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x1Eu);
  if ( result )
  {
    v10 = result;
    v11 = 0;
    v12 = -560;
    while ( 1 )
    {
      if ( ((*(_QWORD *)(v10 + 744) >> v11) & 1) == 0 )
        goto LABEL_3;
      v13 = (unsigned int *)(v10 + v12 + 739);
      v14 = *v13;
      if ( (*v13 & 0x10000) != 0 )
      {
        result = (__int64)qdf_mem_copy((void *)(v10 + v12 + 1331), (const void *)(v10 + v12 + 749), 6u);
        v14 = *v13;
        if ( (*v13 & 0x40000) == 0 )
        {
LABEL_7:
          if ( (v14 & 0x20000) == 0 )
            goto LABEL_8;
          goto LABEL_17;
        }
      }
      else if ( (v14 & 0x40000) == 0 )
      {
        goto LABEL_7;
      }
      result = (__int64)qdf_mem_copy((void *)(v10 + v12 + 1337), (const void *)(v10 + v12 + 755), 6u);
      v14 = *v13;
      if ( (*v13 & 0x20000) == 0 )
      {
LABEL_8:
        if ( (v14 & 0x80000) == 0 )
          goto LABEL_9;
        goto LABEL_18;
      }
LABEL_17:
      result = (__int64)qdf_mem_copy((void *)(v10 + v12 + 1343), (const void *)(v10 + v12 + 761), 6u);
      v14 = *v13;
      if ( (*v13 & 0x80000) == 0 )
      {
LABEL_9:
        if ( (v14 & 0x100000) == 0 )
          goto LABEL_10;
        goto LABEL_19;
      }
LABEL_18:
      result = (__int64)qdf_mem_copy((void *)(v10 + v12 + 1349), (const void *)(v10 + v12 + 767), 6u);
      v14 = *v13;
      if ( (*v13 & 0x100000) == 0 )
      {
LABEL_10:
        if ( (v14 & 0x200000) == 0 )
          goto LABEL_11;
        goto LABEL_20;
      }
LABEL_19:
      *(_DWORD *)(v10 + v12 + 1321) = *(_DWORD *)(v10 + v12 + 1321) & 0xFFFFFFC0 | v14 & 0x3F;
      if ( (v14 & 0x200000) == 0 )
      {
LABEL_11:
        if ( (v14 & 0x400000) == 0 )
          goto LABEL_12;
        goto LABEL_21;
      }
LABEL_20:
      *(_DWORD *)(v10 + v12 + 1321) = *(_DWORD *)(v10 + v12 + 1321) & 0xFFFFC03F | ((unsigned __int8)(v14 >> 6) << 6);
      if ( (v14 & 0x400000) == 0 )
      {
LABEL_12:
        if ( (v14 & 0x800000) == 0 )
          goto LABEL_13;
        goto LABEL_22;
      }
LABEL_21:
      *(_WORD *)(v10 + v12 + 1325) = *(_WORD *)(v10 + v12 + 743);
      if ( (v14 & 0x800000) == 0 )
      {
LABEL_13:
        if ( (v14 & 0x1000000) != 0 )
          goto LABEL_23;
        goto LABEL_3;
      }
LABEL_22:
      *(_WORD *)(v10 + v12 + 1327) = *(_WORD *)(v10 + v12 + 745);
      if ( (v14 & 0x1000000) != 0 )
LABEL_23:
        *(_WORD *)(v10 + v12 + 1329) = *(_WORD *)(v10 + v12 + 747);
LABEL_3:
      v12 += 35;
      ++v11;
      if ( !v12 )
        return result;
    }
  }
  return qdf_trace_msg(0x49u, 2u, "%s: pcfr is null", v2, v3, v4, v5, v6, v7, v8, v9, "target_if_cfr_update_global_cfg");
}
