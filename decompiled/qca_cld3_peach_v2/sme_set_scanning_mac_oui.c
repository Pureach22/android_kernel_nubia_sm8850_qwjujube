__int64 __fastcall sme_set_scanning_mac_oui(__int64 a1, __int64 *a2)
{
  __int64 v4; // x0
  __int64 v5; // x8
  __int64 v6; // x10
  __int64 v7; // x20
  __int64 v8; // x8
  __int64 v9; // x10
  __int64 v10; // x11
  __int64 v11; // x8
  __int64 v12; // x10
  __int64 v13; // x11
  __int64 v14; // x9
  __int64 v15; // x11
  __int64 v16; // x10
  unsigned int v17; // w21
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v27; // [xsp+8h] [xbp-38h] BYREF
  __int64 v28; // [xsp+10h] [xbp-30h]
  __int64 v29; // [xsp+18h] [xbp-28h]
  __int64 v30; // [xsp+20h] [xbp-20h]
  __int64 v31; // [xsp+28h] [xbp-18h]
  __int64 v32; // [xsp+30h] [xbp-10h]
  __int64 v33; // [xsp+38h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v4 = _qdf_mem_malloc(0x74u, "sme_set_scanning_mac_oui", 10644);
  if ( v4 )
  {
    v5 = a2[2];
    v6 = *a2;
    v7 = v4;
    *(_QWORD *)(v4 + 8) = a2[1];
    *(_QWORD *)(v4 + 16) = v5;
    *(_QWORD *)v4 = v6;
    v8 = a2[6];
    v9 = a2[3];
    v10 = a2[4];
    *(_QWORD *)(v4 + 40) = a2[5];
    *(_QWORD *)(v4 + 48) = v8;
    *(_QWORD *)(v4 + 24) = v9;
    *(_QWORD *)(v4 + 32) = v10;
    v11 = a2[10];
    v12 = a2[7];
    v13 = a2[8];
    *(_QWORD *)(v4 + 72) = a2[9];
    *(_QWORD *)(v4 + 80) = v11;
    *(_QWORD *)(v4 + 56) = v12;
    *(_QWORD *)(v4 + 64) = v13;
    v15 = a2[12];
    v14 = a2[13];
    v16 = a2[11];
    *(_DWORD *)(v4 + 112) = *((_DWORD *)a2 + 28);
    *(_QWORD *)(v4 + 96) = v15;
    *(_QWORD *)(v4 + 104) = v14;
    *(_QWORD *)(v4 + 88) = v16;
    v17 = qdf_mutex_acquire(a1 + 12848);
    if ( v17
      || (v28 = v7,
          LOWORD(v27) = 4349,
          v17 = scheduler_post_message_debug(
                  0x34u,
                  0x36u,
                  54,
                  (unsigned __int16 *)&v27,
                  0x29A1u,
                  (__int64)"sme_set_scanning_mac_oui"),
          qdf_mutex_release(a1 + 12848),
          v17) )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: failure: %d",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "sme_set_scanning_mac_oui",
        v17);
      _qdf_mem_free(v7);
    }
  }
  else
  {
    v17 = 2;
  }
  _ReadStatusReg(SP_EL0);
  return v17;
}
