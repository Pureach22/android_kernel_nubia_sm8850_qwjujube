__int64 __fastcall sme_unpack_assoc_rsp(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 result; // x0
  int v11; // w4
  __int64 v12; // x9
  __int64 v13; // x10
  __int64 v14; // x9
  __int64 v15; // x8
  __int64 v16; // x11
  __int64 v17; // x9
  _QWORD v18[7]; // [xsp+8h] [xbp-48h] BYREF
  int v19; // [xsp+40h] [xbp-10h]
  __int64 v20; // [xsp+48h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = dot11f_parse_assoc_response(a1, *(_QWORD *)(a2 + 128), *(unsigned int *)(a2 + 120), a3, 0, a6, a7, a8);
  if ( !(_DWORD)result )
  {
    v11 = *(_DWORD *)(a2 + 48);
    v12 = *(_QWORD *)(a3 + 1372);
    v13 = *(_QWORD *)(a3 + 1380);
    v18[6] = *(_QWORD *)(a3 + 1388);
    v18[4] = v12;
    v18[5] = v13;
    v19 = *(_DWORD *)(a3 + 1396);
    v14 = *(_QWORD *)(a3 + 1348);
    v16 = *(_QWORD *)(a3 + 1356);
    v15 = *(_QWORD *)(a3 + 1364);
    v18[0] = *(_QWORD *)(a3 + 1340);
    v18[1] = v14;
    LOWORD(v13) = *(_WORD *)(a2 + 120);
    v17 = *(_QWORD *)(a2 + 128);
    v18[2] = v16;
    v18[3] = v15;
    lim_strip_and_decode_eht_cap((unsigned __int8 *)(v17 + 6), v13 - 6, (_BYTE *)(a3 + 3264), (__int64)v18, v11, 0);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
