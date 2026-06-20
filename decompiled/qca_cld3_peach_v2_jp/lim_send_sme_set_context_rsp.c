__int64 __fastcall lim_send_sme_set_context_rsp(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        __int64 a5,
        char a6)
{
  __int64 result; // x0
  __int16 v12; // w2
  __int64 (__fastcall *v13)(__int64, __int64 *); // x8
  __int64 v14; // [xsp+8h] [xbp-38h] BYREF
  __int64 v15; // [xsp+10h] [xbp-30h]
  __int64 v16; // [xsp+18h] [xbp-28h]
  __int64 v17; // [xsp+20h] [xbp-20h]
  __int64 v18; // [xsp+28h] [xbp-18h]
  __int64 v19; // [xsp+30h] [xbp-10h]
  __int64 v20; // [xsp+38h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  v19 = 0;
  v16 = 0;
  v17 = 0;
  v14 = 0;
  v15 = 0;
  result = _qdf_mem_malloc(0x14u, "lim_send_sme_set_context_rsp", 1441);
  if ( result )
  {
    *(_DWORD *)(result + 8) = a4;
    *(_DWORD *)(result + 12) = a2;
    *(_BYTE *)(result + 4) = a6;
    *(_DWORD *)result = 1315845;
    HIDWORD(v14) = 0;
    *(_WORD *)(result + 16) = WORD2(a2);
    LOWORD(v14) = 5125;
    v15 = result;
    if ( a5 )
      v12 = *(_WORD *)(a5 + 8);
    else
      v12 = 255;
    qdf_trace(53, 6u, v12, 5125);
    lim_diag_event_report(a1, 6, a5, a4);
    v13 = *(__int64 (__fastcall **)(__int64, __int64 *))(a1 + 12416);
    if ( *((_DWORD *)v13 - 1) != -1829016265 )
      __break(0x8228u);
    result = v13(a1, &v14);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
