__int64 __fastcall lim_send_sme_addts_rsp(__int64 result, char a2, int a3, __int64 a4, __int64 *a5, char a6)
{
  __int64 v7; // x19
  __int64 v11; // x9
  __int64 v12; // x10
  __int64 v13; // x11
  __int64 v14; // x12
  __int64 v15; // x10
  __int64 v16; // x12
  __int64 v17; // x11
  __int16 v18; // w2
  __int64 v19; // [xsp+8h] [xbp-38h] BYREF
  __int64 v20; // [xsp+10h] [xbp-30h]
  __int64 v21; // [xsp+18h] [xbp-28h]
  __int64 v22; // [xsp+20h] [xbp-20h]
  __int64 v23; // [xsp+28h] [xbp-18h]
  __int64 v24; // [xsp+30h] [xbp-10h]
  __int64 v25; // [xsp+38h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  if ( a2 )
  {
    v7 = result;
    result = _qdf_mem_malloc(0xC8u, "lim_send_sme_addts_rsp", 1484);
    if ( result )
    {
      *(_DWORD *)(result + 8) = a3;
      *(_WORD *)result = 5149;
      *(_DWORD *)(result + 16) = a3;
      v12 = a5[2];
      v11 = a5[3];
      LOWORD(v19) = 5149;
      v13 = *a5;
      v14 = a5[1];
      *(_QWORD *)(result + 50) = v11;
      *(_QWORD *)(result + 42) = v12;
      *(_QWORD *)(result + 34) = v14;
      *(_QWORD *)(result + 26) = v13;
      v16 = a5[5];
      v15 = a5[6];
      LOWORD(v11) = *((_WORD *)a5 + 28);
      v17 = a5[4];
      *(_BYTE *)(result + 4) = a6;
      *(_WORD *)(result + 82) = v11;
      *(_QWORD *)(result + 74) = v15;
      *(_QWORD *)(result + 66) = v16;
      *(_QWORD *)(result + 58) = v17;
      v20 = result;
      HIDWORD(v19) = 0;
      if ( a4 )
        v18 = *(_WORD *)(a4 + 8);
      else
        v18 = 255;
      qdf_trace(53, 6u, v18, 5149);
      lim_diag_event_report(v7, 30, a4, 0);
      result = sys_process_mmh_msg(v7, &v19);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
