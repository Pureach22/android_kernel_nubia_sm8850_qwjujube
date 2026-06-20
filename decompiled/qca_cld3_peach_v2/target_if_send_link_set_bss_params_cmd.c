__int64 __fastcall target_if_send_link_set_bss_params_cmd(
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
  __int64 v10; // x8
  __int64 v11; // x19
  __int16 *v13; // x9
  __int16 v14; // w10
  __int16 v15; // w8
  int v16; // w10
  int v17; // w8
  int v18; // w8
  __int64 result; // x0
  const char *v20; // x2
  _QWORD v21[3]; // [xsp+0h] [xbp-50h] BYREF
  __int64 v22; // [xsp+18h] [xbp-38h]
  __int64 v23; // [xsp+20h] [xbp-30h]
  __int64 v24; // [xsp+28h] [xbp-28h]
  __int64 v25; // [xsp+30h] [xbp-20h]
  __int64 v26; // [xsp+38h] [xbp-18h]
  __int64 v27; // [xsp+40h] [xbp-10h]
  __int64 v28; // [xsp+48h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  memset(v21, 0, sizeof(v21));
  if ( !a1 )
  {
    v20 = "%s: null pdev";
    goto LABEL_8;
  }
  v10 = *(_QWORD *)(a1 + 2800);
  if ( !v10 || (v11 = *(_QWORD *)(v10 + 16)) == 0 )
  {
    v20 = "%s: null wmi handle";
LABEL_8:
    qdf_trace_msg(
      0x49u,
      2u,
      v20,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_send_link_set_bss_params_cmd",
      v21[0],
      v21[1],
      v21[2],
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28);
    result = 29;
    goto LABEL_9;
  }
  if ( !a2 )
  {
    v20 = "%s: cmd is null";
    goto LABEL_8;
  }
  LOBYTE(v21[0]) = *(_BYTE *)a2;
  qdf_mem_copy((char *)v21 + 1, (const void *)(a2 + 1), 6u);
  v13 = *(__int16 **)(a2 + 24);
  v14 = *(_WORD *)(a2 + 11);
  LOBYTE(v27) = *(_BYTE *)(a2 + 32);
  v15 = *v13;
  *(_WORD *)((char *)&v21[1] + 3) = v14;
  v16 = *(_DWORD *)(a2 + 7);
  LOWORD(v22) = v15;
  v17 = *((_DWORD *)v13 + 4);
  *(_DWORD *)((char *)v21 + 7) = v16;
  LOWORD(v16) = *(_WORD *)(a2 + 17);
  LODWORD(v24) = v17;
  v18 = *((_DWORD *)v13 + 5);
  *(_WORD *)((char *)&v21[2] + 1) = v16;
  HIDWORD(v24) = v18;
  LODWORD(v13) = *((_DWORD *)v13 + 7);
  *(_DWORD *)((char *)&v21[1] + 5) = *(_DWORD *)(a2 + 13);
  HIDWORD(v25) = (_DWORD)v13;
  result = wmi_send_link_set_bss_params_cmd(v11, v21);
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
