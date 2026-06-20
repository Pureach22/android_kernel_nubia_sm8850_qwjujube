__int64 __fastcall wlan_regulatory_psoc_obj_created_notification(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x19
  __int64 v4; // x10
  __int64 v5; // x9
  __int64 v6; // x11
  __int64 v7; // x12
  int v8; // w13
  __int64 v9; // x10
  int v10; // w12
  __int64 v11; // x8
  int v12; // w10
  unsigned int v13; // w0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w20
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7

  v2 = _qdf_mem_malloc(0x16F28u, "wlan_regulatory_psoc_obj_created_notification", 107);
  if ( !v2 )
    return 2;
  v3 = v2;
  v4 = 0;
  *(_BYTE *)(v2 + 91140) = 1;
  *(_DWORD *)(v2 + 91144) = 7;
  *(_BYTE *)(v2 + 91148) = 1;
  *(_DWORD *)(v2 + 93084) = 1;
  *(_WORD *)(v2 + 93958) = 1;
  *(_WORD *)(v2 + 91153) = 255;
  *(_WORD *)(v2 + 93233) = 255;
  *(_DWORD *)(v2 + 91160) = -1;
  *(_QWORD *)(v2 + 93248) = 0;
  v5 = v2 + 60744;
  v6 = v2 + 30380;
  *(_BYTE *)(v2 + 91095) = 0;
  *(_QWORD *)(v2 + 91120) = a1;
  *(_BYTE *)(v2 + 91151) = 0;
  *(_BYTE *)(v2 + 93232) = 0;
  *(_BYTE *)(v2 + 91097) = 0;
  *(_BYTE *)(v2 + 93235) = 0;
  *(_BYTE *)(v2 + 93256) = 0;
  *(_BYTE *)(v2 + 93269) = 0;
  *(_BYTE *)(v2 + 93969) = 0;
  *(_DWORD *)(v2 + 93240) = 0;
  *(_BYTE *)(v2 + 91092) = 0;
  do
  {
    v7 = v2 + v4;
    v4 += 36;
    v8 = *(_DWORD *)(v7 + 20);
    *(_BYTE *)(v7 + 33) = 0;
    *(_DWORD *)(v7 + 16) = 0;
    *(_DWORD *)(v7 + 20) = v8 | 1;
  }
  while ( v4 != 3672 );
  v9 = 102;
  *(_BYTE *)(v2 + 91093) = 0;
  do
  {
    v10 = *(_DWORD *)(v6 + 4);
    --v9;
    *(_BYTE *)(v6 + 17) = 0;
    *(_DWORD *)v6 = 0;
    *(_DWORD *)(v6 + 4) = v10 | 1;
    v6 += 36;
  }
  while ( v9 );
  *(_BYTE *)(v2 + 91094) = 0;
  v11 = 102;
  do
  {
    v12 = *(_DWORD *)(v5 + 4);
    --v11;
    *(_BYTE *)(v5 + 17) = 0;
    *(_DWORD *)v5 = 0;
    *(_DWORD *)(v5 + 4) = v12 | 1;
    v5 += 36;
  }
  while ( v11 );
  v13 = wlan_objmgr_psoc_component_obj_attach(a1, 0xDu, v2, 0);
  if ( v13 )
  {
    v22 = v13;
    _qdf_mem_free(v3);
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: Obj attach failed",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "wlan_regulatory_psoc_obj_created_notification");
    return v22;
  }
  else
  {
    qdf_trace_msg(
      0x51u,
      8u,
      "%s: reg psoc obj created with status %d",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "wlan_regulatory_psoc_obj_created_notification",
      0);
    _qdf_minidump_log(v3, 93992, (__int64)"psoc_regulatory");
    return 0;
  }
}
