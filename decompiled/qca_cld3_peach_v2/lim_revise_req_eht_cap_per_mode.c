unsigned __int64 __fastcall lim_revise_req_eht_cap_per_mode(
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
  __int64 v10; // x19
  unsigned __int8 v11; // w20
  __int64 v12; // x8
  unsigned __int64 v13; // x12
  bool v14; // zf
  __int64 v15; // x8
  unsigned __int64 v16; // x12
  unsigned __int64 *v17; // x10
  __int64 v18; // x17
  unsigned __int64 result; // x0
  unsigned __int64 v20; // x11
  __int64 v21; // x17
  unsigned __int64 v22; // x11
  unsigned __int64 v23; // x11
  unsigned __int64 v24; // x9
  char v25; // w11

  v10 = a1 + 20480;
  v11 = *(_BYTE *)(a2 + 8635);
  if ( (*(_DWORD *)(a2 + 7036) | 2) == 3 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Disable eht cap for SAP/GO",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "lim_revise_req_eht_cap_per_mode");
    *(_QWORD *)(v10 + 3969) &= 0x9FFFFFFFFFFFFFFFLL;
  }
  v12 = *(_QWORD *)(v10 + 3977);
  v13 = v12 & 0xFFFFF0000FFF1FFFLL;
  v14 = (v12 & 0xF00000000000LL) == 0;
  v15 = v11 & 0xF;
  v16 = v13 & 0xFFFFF0000FFFFFFFLL
      | ((unsigned __int8)(v11 & 0xF) << 28)
      | (v15 << 32) & 0xFFFFF00FFFFFFFFFLL
      | (v15 << 36) & 0xFFFFF0FFFFFFFFFFLL
      | (v15 << 40);
  if ( !v14 )
    v16 = v16 & 0xFFF00FFFFFFF1FFFLL | (v15 << 44) | (v15 << 48);
  if ( (v16 & 0xF0000000000000LL) != 0 )
    v16 = v16 & 0xF00FFFFFFFFFFFFFLL | (v15 << 52) | (v15 << 56);
  v17 = (unsigned __int64 *)(v10 + 3985);
  v18 = *(_QWORD *)(v10 + 3985);
  result = v18 & 0xFFFFFFFFFFFFFFF0LL;
  *(_QWORD *)(v10 + 3977) = ((unsigned __int64)v11 << 60) | v16 & 0xFFFFFFFFFFFFFFFLL;
  v20 = v18 & 0xFFFFFFFFFFFFFFF0LL | v15;
  if ( (v18 & 0xF0) != 0 )
    v20 = v18 & 0xFFFFFFFFFFFFF000LL | v11 & 0xF | (16LL * (v11 & 0xF)) | ((unsigned __int64)(v11 & 0xF) << 8);
  v21 = v15 << 20;
  if ( (v20 & 0xF000) != 0 )
    v20 = v20 & 0xFFFFFFFFFFF00FFFLL | (v15 << 12) | (v15 << 16);
  if ( (v20 & 0xF0000000) != 0 )
    v22 = (v15 << 28) | (v15 << 32) | v20 & 0xFFFFFFF0000FFFFFLL | (v21 | (v15 << 24)) & 0xFFFFFFF00FFFFFFFLL;
  else
    v22 = v20 & 0xFFFFFFFFF00FFFFFLL | v21 | (v15 << 24);
  if ( (v22 & 0xF000000000LL) != 0 )
    v22 = (v15 << 36) | (v15 << 40) | v22 & 0xFFFFF00FFFFFFFFFLL;
  v14 = (v22 & 0xF0000000000000LL) == 0;
  v23 = v22 & 0xFFF00FFFFFFFFFFFLL | ((unsigned __int64)(unsigned __int8)(v15 | (16 * v15)) << 44);
  if ( !v14 )
    v23 = v23 & 0xF00FFFFFFFFFFFFFLL | (v15 << 52) | (v15 << 56);
  *v17 = v23;
  if ( v23 >> 60 )
  {
    v24 = v23 & 0xFFFFFFFFFFFFFFFLL | ((unsigned __int64)v11 << 60);
    v25 = *(_BYTE *)(v10 + 3993) & 0xF0;
    *v17 = v24;
    *(_BYTE *)(v10 + 3993) = v25 | v15;
  }
  return result;
}
