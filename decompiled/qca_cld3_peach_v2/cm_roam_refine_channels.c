__int64 __fastcall cm_roam_refine_channels(__int64 a1, __int64 a2, unsigned __int8 *a3)
{
  __int64 v6; // x22
  int *v7; // x19
  __int64 v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 i; // x8
  __int64 v18; // x8
  __int64 v19; // x0
  unsigned int updated; // w21
  __int64 v21; // x10
  __int64 v22; // x9
  __int64 v23; // x10
  __int64 v24; // x8
  __int64 v26; // [xsp+8h] [xbp-18h] BYREF
  __int64 v27; // [xsp+10h] [xbp-10h]
  __int64 v28; // [xsp+18h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *a3;
  v27 = 0;
  v26 = (unsigned __int8)v6;
  v7 = (int *)_qdf_mem_malloc(4 * v6, "cm_roam_refine_channels", 2727);
  if ( !v7 || (v8 = _qdf_mem_malloc(4 * v6, "cm_roam_refine_channels", 2731), (v27 = v8) == 0) )
  {
LABEL_14:
    updated = 0;
    goto LABEL_15;
  }
  if ( (_DWORD)v6 )
  {
    for ( i = 0; i != v6; ++i )
    {
      v7[i] = *(_DWORD *)(*((_QWORD *)a3 + 1) + i * 4);
      *(_DWORD *)(v8 + i * 4) = *(_DWORD *)(*((_QWORD *)a3 + 1) + i * 4);
    }
  }
  v18 = *(_QWORD *)(a1 + 216);
  if ( v18 )
    v19 = *(_QWORD *)(v18 + 80);
  else
    v19 = 0;
  updated = cm_update_roam_scan_channel_list(
              v19,
              a1,
              *(unsigned __int8 *)(a1 + 168),
              (unsigned __int8 *)&v26,
              v7,
              v6,
              0,
              v9,
              v10,
              v11,
              v12,
              v13,
              v14,
              v15,
              v16);
  if ( !updated )
  {
    v21 = (unsigned __int8)v26;
    *(_BYTE *)(a2 + 4) = v26;
    if ( v21 )
    {
      v22 = v27;
      v23 = 4 * v21;
      v24 = 0;
      do
      {
        if ( v24 == 400 )
          __break(0x5512u);
        *(_DWORD *)(a2 + 8 + v24) = *(_DWORD *)(v22 + v24);
        v24 += 4;
      }
      while ( v23 != v24 );
    }
    goto LABEL_14;
  }
LABEL_15:
  _qdf_mem_free((__int64)v7);
  _qdf_mem_free(v27);
  _ReadStatusReg(SP_EL0);
  return updated;
}
