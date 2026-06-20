__int64 __fastcall htt_soc_initialize(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v6; // x20
  __int64 *v7; // x0
  int v8; // w8
  __int64 result; // x0
  int v10; // w1
  __int64 v11; // x0
  __int64 v12; // [xsp+8h] [xbp-D8h] BYREF
  __int64 v13; // [xsp+10h] [xbp-D0h]
  __int64 v14; // [xsp+18h] [xbp-C8h]
  __int64 v15; // [xsp+20h] [xbp-C0h] BYREF
  __int64 v16; // [xsp+28h] [xbp-B8h]
  __int64 v17; // [xsp+30h] [xbp-B0h]
  __int64 v18; // [xsp+38h] [xbp-A8h]
  __int64 (__fastcall *v19)(__int64, __int64); // [xsp+40h] [xbp-A0h]
  __int64 (__fastcall *v20)(__int64, __int64, double, double, double, double, double, double, double, double); // [xsp+48h] [xbp-98h]
  __int64 v21; // [xsp+50h] [xbp-90h]
  __int64 (*v22)(); // [xsp+58h] [xbp-88h]
  __int64 v23; // [xsp+60h] [xbp-80h]
  __int64 v24; // [xsp+68h] [xbp-78h]
  __int64 v25; // [xsp+70h] [xbp-70h]
  __int64 v26; // [xsp+78h] [xbp-68h]
  __int64 v27; // [xsp+80h] [xbp-60h]
  __int64 v28; // [xsp+88h] [xbp-58h]
  __int64 v29; // [xsp+90h] [xbp-50h]
  __int64 v30; // [xsp+98h] [xbp-48h]
  __int64 v31; // [xsp+A0h] [xbp-40h]
  _QWORD v32[7]; // [xsp+A8h] [xbp-38h] BYREF

  v32[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_QWORD *)a1 = a2;
  v6 = *(_QWORD *)(a1 + 8);
  *(_QWORD *)(a1 + 48) = a3;
  *(_QWORD *)(a1 + 56) = a5;
  *(_QWORD *)(a1 + 16) = a4;
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  v22 = nullptr;
  v23 = 0;
  v20 = nullptr;
  v21 = 0;
  v18 = 0;
  v19 = nullptr;
  v16 = 0;
  v17 = 0;
  v14 = 0;
  v15 = 0;
  v12 = 0;
  v13 = 0;
  qdf_mem_set(&v15, 0x88u, 0);
  qdf_mem_set(&v12, 0x18u, 0);
  v18 = a1;
  v19 = dp_htt_h2t_send_complete;
  v21 = 0;
  v22 = dp_htt_h2t_full;
  v7 = *(__int64 **)(a1 + 48);
  HIDWORD(v28) = 1;
  WORD1(v15) |= 8u;
  v16 = 0;
  LOBYTE(v17) = 0;
  v25 = 0;
  LODWORD(v30) = 64;
  LOWORD(v15) = 768;
  v20 = dp_htt_t2h_msg_handler;
  v8 = htc_connect_service(v7, (unsigned __int16 *)&v15, (__int64)&v12);
  result = 0;
  if ( !v8 )
  {
    v10 = HIDWORD(v13);
    *(_DWORD *)(a1 + 64) = HIDWORD(v13);
    hif_save_htc_htt_config_endpoint(*(_QWORD *)(v6 + 64), v10);
    v11 = *(_QWORD *)(*(_QWORD *)(a1 + 8) + 64LL);
    v32[2] = dp_htt_hif_t2h_hp_callback;
    memset(&v32[3], 0, 24);
    v32[0] = a1;
    v32[1] = 0;
    hif_update_pipe_callback(v11, 5u, (int)v32);
    result = a1;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
