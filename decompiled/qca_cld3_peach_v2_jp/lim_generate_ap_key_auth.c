__int64 __fastcall lim_generate_ap_key_auth(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _BYTE *v9; // x19
  int v10; // w8
  __int64 v12; // x10
  __int64 v13; // x21
  const void *v14; // x1
  const char *v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  const char *v24; // x9
  __int64 v25; // x8
  __int64 v26; // x9
  bool v29; // w8
  char v30; // w8
  __int64 result; // x0
  unsigned int v32; // [xsp+Ch] [xbp-44h] BYREF
  _QWORD v33[2]; // [xsp+10h] [xbp-40h] BYREF
  _QWORD v34[2]; // [xsp+20h] [xbp-30h] BYREF
  __int64 v35; // [xsp+30h] [xbp-20h] BYREF
  int v36; // [xsp+38h] [xbp-18h]
  _QWORD v37[2]; // [xsp+40h] [xbp-10h] BYREF

  v37[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_BYTE **)(a1 + 9976);
  v36 = 0;
  v34[1] = 0;
  v35 = 0;
  v33[1] = 0;
  v34[0] = 0;
  v33[0] = 0;
  if ( v9 )
  {
    v10 = *(_DWORD *)(a1 + 88);
    v32 = 44;
    if ( v10 == 1 )
      v12 = 78;
    else
      v12 = 758;
    v37[0] = v33;
    if ( v10 == 1 )
      v13 = 758;
    else
      v13 = 78;
    qdf_mem_copy(v33, &v9[v12], 0x10u);
    qdf_mem_copy(v34, &v9[v13], 0x10u);
    qdf_mem_copy(&v35, (const void *)(a1 + 24), 6u);
    if ( *(_DWORD *)(a1 + 88) == 1 )
      v14 = nullptr;
    else
      v14 = (const void *)(a1 + 30);
    qdf_mem_copy((char *)&v35 + 6, v14, 6u);
    if ( ((v9[17] - 19) & 0xFD) != 0 )
      v15 = "hmac(sha256)";
    else
      v15 = "hmac(sha384)";
    if ( (qdf_get_hmac_hash((__int64)v15, (__int64)(v9 + 776), (unsigned __int8)v9[824], 1u, (__int64)v37, &v32)
        & 0x80000000) != 0 )
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: failed to generate PMK id",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "lim_generate_ap_key_auth");
    if ( ((v9[17] - 19) & 0xFD) != 0 )
      v24 = "hmac(sha256)";
    else
      v24 = "hmac(sha384)";
    v25 = *(_QWORD *)v24;
    v26 = *(_QWORD *)(v24 + 5);
    if ( v25 == 0x6168732863616D68LL && v26 == 0x29343833616873LL )
    {
      v30 = 48;
    }
    else
    {
      v29 = v25 == 0x6168732863616D68LL && v26 == 0x29363532616873LL;
      v30 = 32 * v29;
    }
    result = 0;
    v9[1069] = v30;
  }
  else
  {
    qdf_trace_msg(0x35u, 2u, "%s: Failed to get fils_info", a2, a3, a4, a5, a6, a7, a8, a9, "lim_generate_ap_key_auth");
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
