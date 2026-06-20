__int64 __fastcall wlan_coex_multi_config_send(
        __int64 a1,
        int *a2,
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
  unsigned int v13; // w21
  const char *v14; // x2
  unsigned __int64 v16; // x25
  _DWORD *v17; // x26
  __int64 v18; // x9
  int v19; // w10
  __int64 v20; // x8
  unsigned int v21; // w0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30; // w24
  int v31; // [xsp+8h] [xbp-28h] BYREF
  __int128 v32; // [xsp+Ch] [xbp-24h]
  __int64 v33; // [xsp+1Ch] [xbp-14h]
  int v34; // [xsp+24h] [xbp-Ch]
  __int64 v35; // [xsp+28h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34 = 0;
  v33 = 0;
  v32 = 0u;
  if ( !a1 )
  {
    v14 = "%s: Null vdev";
    goto LABEL_8;
  }
  v10 = *(_QWORD *)(a1 + 152);
  if ( !v10 || !*(_QWORD *)(v10 + 80) )
  {
    v14 = "%s: failed to get coex_obj";
LABEL_8:
    qdf_trace_msg(0x70u, 2u, v14, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_coex_multi_config_send");
    v13 = 4;
    goto LABEL_9;
  }
  if ( (tgt_get_coex_multi_config_support() & 1) != 0 )
  {
    v13 = tgt_send_coex_multi_config(a1, a2);
  }
  else if ( a2[1] )
  {
    v16 = 0;
    v13 = 0;
    v17 = a2 + 4;
    do
    {
      v31 = *a2;
      if ( v16 == 32 )
        __break(0x5512u);
      v18 = *(_QWORD *)(v17 - 1);
      v19 = v17[1];
      LODWORD(v32) = *(v17 - 2);
      v20 = *((_QWORD *)v17 + 1);
      *(_QWORD *)((char *)&v32 + 4) = v18;
      LODWORD(v18) = v17[4];
      HIDWORD(v32) = v19;
      v33 = v20;
      v34 = v18;
      v21 = tgt_send_coex_config(a1, &v31);
      if ( v21 )
      {
        v30 = v21;
        qdf_trace_msg(
          0x70u,
          2u,
          "%s: fail to send one coex config",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "wlan_coex_multi_config_send");
        v13 = v30;
      }
      ++v16;
      v17 += 7;
    }
    while ( v16 < (unsigned int)a2[1] );
  }
  else
  {
    v13 = 0;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return v13;
}
