__int64 __fastcall cm_abort_fw_roam(
        __int64 *a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 result; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w20
  unsigned int v30; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v31; // [xsp+8h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *a1;
  v30 = a2;
  cm_get_first_roam_command(v11, a3, a4, a5, a6, a7, a8, a9, a10);
  mlme_cm_osif_roam_abort_ind();
  result = cm_sm_deliver_event(*a1, 0x1Fu, 4u, (__int64)&v30, v12, v13, v14, v15, v16, v17, v18, v19);
  if ( (_DWORD)result )
  {
    v29 = result;
    cm_remove_cmd(a1, &v30, v21, v22, v23, v24, v25, v26, v27, v28);
    result = v29;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
