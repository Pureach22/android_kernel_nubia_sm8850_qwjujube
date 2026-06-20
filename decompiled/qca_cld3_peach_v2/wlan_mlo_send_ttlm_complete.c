__int64 __fastcall wlan_mlo_send_ttlm_complete(
        __int64 result,
        __int64 a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  __int64 v12; // x8
  __int64 v13; // x9
  __int64 (__fastcall *v14)(__int64, char *); // x9
  __int64 v15; // x10
  int v16; // w12
  char v17; // w11
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  const char *v26; // x2
  char v27; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v28[7]; // [xsp+9h] [xbp-17h]
  _BOOL4 v29; // [xsp+10h] [xbp-10h]
  _BOOL4 v30; // [xsp+14h] [xbp-Ch]
  __int64 v31; // [xsp+18h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(result + 216);
  *(_DWORD *)&v28[3] = 0;
  if ( !v11 || (v12 = *(_QWORD *)(v11 + 80)) == 0 )
  {
    v26 = "%s: psoc is null";
LABEL_11:
    result = qdf_trace_msg(0x99u, 2u, v26, a4, a5, a6, a7, a8, a9, a10, a11, "wlan_mlo_send_ttlm_complete");
    goto LABEL_12;
  }
  v13 = *(_QWORD *)(v12 + 2128);
  if ( !v13 )
  {
    qdf_trace_msg(0x49u, 2u, "%s: tx_ops is NULL", a4, a5, a6, a7, a8, a9, a10, a11, "target_if_mlo_get_tx_ops");
    v26 = "%s: tx_ops is null!";
    goto LABEL_11;
  }
  v14 = *(__int64 (__fastcall **)(__int64, char *))(v13 + 2072);
  if ( !v14 )
  {
    v26 = "%s: send_mlo_ttlm_complete_cmd is null!";
    goto LABEL_11;
  }
  if ( *(_BYTE *)(a2 + 548) == 1 )
  {
    v15 = *(_QWORD *)(result + 1360);
    v16 = *(_DWORD *)(v15 + 17);
    v29 = (a3 & 1) == 0;
    v30 = v29;
    LOWORD(v15) = *(_WORD *)(v15 + 21);
    v17 = *(_BYTE *)(result + 168);
    *(_DWORD *)v28 = v16;
    *(_WORD *)&v28[4] = v15;
    v27 = v17;
    if ( *((_DWORD *)v14 - 1) != 1254708662 )
      __break(0x8229u);
    result = v14(v12, &v27);
    if ( (_DWORD)result )
      result = qdf_trace_msg(
                 0x8Fu,
                 2u,
                 "%s: send_mlo_link_ttlm_complete_cmd failed %d",
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 "wlan_mlo_send_ttlm_complete",
                 (unsigned int)result);
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
