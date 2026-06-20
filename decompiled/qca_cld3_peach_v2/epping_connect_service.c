__int64 __fastcall epping_connect_service(__int64 a1)
{
  __int64 *v2; // x0
  unsigned int v3; // w0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned int v12; // w20
  const char *v13; // x2
  __int64 *v14; // x0
  int v16; // w8
  __int64 v17; // [xsp+8h] [xbp-A8h] BYREF
  __int64 v18; // [xsp+10h] [xbp-A0h]
  __int64 v19; // [xsp+18h] [xbp-98h]
  _QWORD v20[3]; // [xsp+20h] [xbp-90h] BYREF
  __int64 v21; // [xsp+38h] [xbp-78h]
  __int64 (__fastcall *v22)(__int64, __int64); // [xsp+40h] [xbp-70h]
  __int64 (__fastcall *v23)(__int64, __int64, double, double, double, double, double, double, double, double); // [xsp+48h] [xbp-68h]
  __int64 v24; // [xsp+50h] [xbp-60h]
  __int64 v25; // [xsp+58h] [xbp-58h]
  __int64 v26; // [xsp+60h] [xbp-50h]
  __int64 v27; // [xsp+68h] [xbp-48h]
  __int64 v28; // [xsp+70h] [xbp-40h]
  __int64 v29; // [xsp+78h] [xbp-38h]
  __int64 v30; // [xsp+80h] [xbp-30h]
  __int64 v31; // [xsp+88h] [xbp-28h]
  __int64 v32; // [xsp+90h] [xbp-20h]
  __int64 v33; // [xsp+98h] [xbp-18h]
  __int64 v34; // [xsp+A0h] [xbp-10h]
  __int64 v35; // [xsp+A8h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v23 = nullptr;
  v24 = 0;
  v21 = 0;
  v22 = nullptr;
  v19 = 0;
  memset(v20, 0, sizeof(v20));
  v17 = 0;
  v18 = 0;
  qdf_mem_set(v20, 0x88u, 0);
  qdf_mem_set(&v17, 0x18u, 0);
  v2 = *(__int64 **)(a1 + 56);
  v21 = a1;
  v22 = epping_tx_complete;
  LODWORD(v33) = 64;
  v23 = epping_rx;
  v24 = 0;
  v28 = 0;
  WORD1(v20[0]) |= 8u;
  LOWORD(v20[0]) = 257;
  v25 = 0;
  v3 = htc_connect_service(v2, (unsigned __int16 *)v20, (__int64)&v17);
  if ( v3 )
  {
    v12 = v3;
    v13 = "Failed to connect to Endpoint Ping BE service status:%d\n";
  }
  else
  {
    qdf_trace_msg(0x33u, 1u, "eppingtest BE endpoint:%d\n", v4, v5, v6, v7, v8, v9, v10, v11, HIDWORD(v18));
    v14 = *(__int64 **)(a1 + 56);
    LOWORD(v20[0]) = 258;
    *(_DWORD *)(a1 + 64) = HIDWORD(v18);
    v12 = htc_connect_service(v14, (unsigned __int16 *)v20, (__int64)&v17);
    if ( !v12 )
    {
      qdf_trace_msg(0x33u, 1u, "eppingtest BK endpoint:%d\n", v4, v5, v6, v7, v8, v9, v10, v11, HIDWORD(v18));
      v16 = HIDWORD(v18);
      *(_DWORD *)(a1 + 68) = HIDWORD(v18);
      *(_DWORD *)(a1 + 72) = v16;
      *(_DWORD *)(a1 + 76) = v16;
      goto LABEL_6;
    }
    v13 = "Failed to connect to Endpoint Ping BK service status:%d\n";
  }
  qdf_trace_msg(0x33u, 1u, v13, v4, v5, v6, v7, v8, v9, v10, v11, v12);
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return v12;
}
