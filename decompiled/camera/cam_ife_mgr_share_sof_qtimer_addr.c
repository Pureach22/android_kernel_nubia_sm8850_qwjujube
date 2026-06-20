__int64 __fastcall cam_ife_mgr_share_sof_qtimer_addr(__int64 a1)
{
  __int64 v1; // x19
  char v2; // w8
  unsigned int v3; // w9
  unsigned int i; // w11
  __int64 v5; // x8
  int ife_csid_rdi_res_type; // w8
  __int64 v7; // x20
  __int64 *v8; // x9
  __int64 *v9; // x10
  int v10; // w12
  __int64 v11; // x19
  __int64 v12; // x20
  _DWORD *v13; // x9
  __int64 v14; // x0
  unsigned int v15; // w0
  unsigned int v16; // w19
  __int64 v17; // x8
  __int64 v18; // x20
  _DWORD *v19; // x8
  __int64 v20; // x0
  __int64 result; // x0
  int v22; // w7
  _QWORD v23[2]; // [xsp+0h] [xbp-20h] BYREF
  __int64 v24; // [xsp+10h] [xbp-10h]
  __int64 v25; // [xsp+18h] [xbp-8h]

  v1 = a1 + 0x2000;
  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_BYTE *)(a1 + 9385);
  v23[1] = 0;
  v24 = 0;
  v23[0] = 0;
  if ( ((v2 & 1) != 0 || *(_BYTE *)(a1 + 9399) == 1) && (v3 = *(_DWORD *)(a1 + 8512)) != 0 )
  {
    for ( i = 1; ; ++i )
    {
      v5 = *(_QWORD *)(a1 + 272) + ((__int64)(int)(i - 1) << 7);
      if ( (unsigned int)(*(_DWORD *)(v5 + 20) - 12294) < 4 )
        break;
      ife_csid_rdi_res_type = 12;
      if ( i >= v3 )
        goto LABEL_10;
    }
    v7 = a1;
    *(_BYTE *)(*(_QWORD *)(v5 + 32) + 144LL) = 1;
    ife_csid_rdi_res_type = cam_ife_hw_mgr_get_ife_csid_rdi_res_type(*(unsigned int *)(v5 + 20));
    a1 = v7;
  }
  else
  {
    ife_csid_rdi_res_type = 12;
  }
LABEL_10:
  v8 = *(__int64 **)(a1 + 208);
  if ( v8 == (__int64 *)(a1 + 208) )
  {
LABEL_19:
    v10 = *((_DWORD *)v8 + 5);
    goto LABEL_21;
  }
  v9 = *(__int64 **)(a1 + 208);
  while ( 1 )
  {
    if ( !*((_DWORD *)v9 + 4) )
      goto LABEL_12;
    v10 = *((_DWORD *)v9 + 5);
    if ( v10 == 5 || v10 == ife_csid_rdi_res_type )
      break;
    if ( !v10 && (*(_BYTE *)(v1 + 1186) & 1) != 0 )
    {
      v10 = 0;
      v8 = v9;
      goto LABEL_21;
    }
LABEL_12:
    v9 = (__int64 *)*v9;
    if ( v9 == (__int64 *)(a1 + 208) )
      goto LABEL_19;
  }
  v8 = v9;
LABEL_21:
  v11 = *(_QWORD *)(a1 + 224);
  v12 = *(_QWORD *)(v8[4] + 16);
  LODWORD(v24) = v10;
  BYTE4(v24) = 1;
  v13 = *(_DWORD **)(v12 + 88);
  v14 = *(_QWORD *)(v12 + 112);
  if ( *(v13 - 1) != -1055839300 )
    __break(0x8229u);
  v15 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64))v13)(v14, 79, v23, 24);
  if ( v15 )
  {
    v16 = v15;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_mgr_share_sof_qtimer_addr",
      2821,
      "Get CSID[%u] SOF ts addr failed",
      *(_DWORD *)(v12 + 4));
    goto LABEL_29;
  }
  v17 = *(_QWORD *)(v11 + 32);
  BYTE4(v24) = 0;
  v18 = *(_QWORD *)(v17 + 16);
  v19 = *(_DWORD **)(v18 + 88);
  v20 = *(_QWORD *)(v18 + 112);
  if ( *(v19 - 1) != -1055839300 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64))v19)(v20, 79, v23, 24);
  if ( (_DWORD)result )
  {
    v22 = *(_DWORD *)(v11 + 20);
    v16 = result;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_mgr_share_sof_qtimer_addr",
      2833,
      "Share SOF ts addr with IFE[%u] res id %u failed",
      *(_DWORD *)(v18 + 4),
      v22);
LABEL_29:
    result = v16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
