__int64 __fastcall cam_isp_sfe_send_scratch_buf_upd(int a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, _DWORD *a6)
{
  int v8; // w19
  __int64 v9; // x9
  int v10; // w8
  int v11; // w8
  int v12; // w10
  __int64 v13; // x8
  __int64 (__fastcall *v14)(__int64, __int64, __int64 *, __int64); // x9
  __int64 v15; // x8
  unsigned int v16; // w22
  __int64 v18; // [xsp+8h] [xbp-98h] BYREF
  __int64 v19; // [xsp+10h] [xbp-90h]
  __int64 v20; // [xsp+18h] [xbp-88h]
  __int64 v21; // [xsp+20h] [xbp-80h]
  __int64 v22; // [xsp+28h] [xbp-78h]
  _QWORD *v23; // [xsp+30h] [xbp-70h]
  __int64 v24; // [xsp+38h] [xbp-68h]
  _QWORD v25[3]; // [xsp+40h] [xbp-60h] BYREF
  _QWORD v26[5]; // [xsp+58h] [xbp-48h] BYREF
  int v27; // [xsp+80h] [xbp-20h]
  int v28; // [xsp+84h] [xbp-1Ch]
  int v29; // [xsp+88h] [xbp-18h]
  int v30; // [xsp+8Ch] [xbp-14h]
  __int64 v31; // [xsp+90h] [xbp-10h]
  __int64 v32; // [xsp+98h] [xbp-8h]

  v8 = a2;
  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a4 + 16);
  v22 = 1;
  v23 = nullptr;
  v26[1] = 0;
  v26[2] = 0x100000000LL;
  v25[0] = v9;
  v25[1] = v9;
  v25[2] = v9;
  v26[0] = v25;
  LODWORD(v9) = *(_DWORD *)a4;
  v10 = *(_DWORD *)(a4 + 4);
  v20 = 0;
  v21 = 0;
  v18 = a3;
  v19 = 0;
  v27 = v9;
  v28 = v10;
  v12 = *(_DWORD *)(a4 + 8);
  v11 = *(_DWORD *)(a4 + 12);
  v23 = v26;
  v24 = 0;
  LODWORD(v21) = a1;
  v29 = v12;
  v30 = v11;
  v13 = *(_QWORD *)(a3 + 16);
  v26[3] = 0;
  v26[4] = 0;
  v14 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v13 + 88);
  v15 = *(_QWORD *)(v13 + 112);
  LODWORD(v19) = a2;
  v20 = a5;
  v31 = 0;
  if ( *((_DWORD *)v14 - 1) != -1055839300 )
    __break(0x8229u);
  v16 = v14(v15, a2, &v18, 56);
  if ( v16 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_sfe_send_scratch_buf_upd",
      14580,
      "Failed to send cmd: %u res: %u rc: %d",
      v8,
      *(_DWORD *)(a3 + 4),
      v16);
  }
  else
  {
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_isp_sfe_send_scratch_buf_upd",
        14585,
        "Scratch buf configured for res: 0x%x",
        *(_DWORD *)(a3 + 4));
    if ( (unsigned int)(v8 - 1) <= 1 )
      *a6 = HIDWORD(v21);
  }
  _ReadStatusReg(SP_EL0);
  return v16;
}
