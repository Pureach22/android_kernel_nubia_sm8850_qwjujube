__int64 __fastcall ll_lt_sap_switch_to_non_wlan_from_wlan(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int *v9; // x19
  unsigned __int8 *v10; // x20
  const char *v11; // x2
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x8
  __int64 v21; // x0

  if ( !*(_DWORD *)(result + 244) )
    return result;
  v9 = (unsigned int *)result;
  if ( *(_QWORD *)(result + 272) && !*(_DWORD *)(result + 264) )
  {
    v10 = (unsigned __int8 *)(result + 256);
    if ( result != -256 )
      goto LABEL_19;
    goto LABEL_25;
  }
  if ( *(_QWORD *)(result + 312) && !*(_DWORD *)(result + 304) )
  {
    v10 = (unsigned __int8 *)(result + 296);
    if ( result != -296 )
      goto LABEL_19;
    goto LABEL_25;
  }
  if ( *(_QWORD *)(result + 352) && !*(_DWORD *)(result + 344) )
  {
    v10 = (unsigned __int8 *)(result + 336);
    if ( result != -336 )
      goto LABEL_19;
    goto LABEL_25;
  }
  if ( *(_QWORD *)(result + 392) && !*(_DWORD *)(result + 384) )
  {
    v10 = (unsigned __int8 *)(result + 376);
    if ( result != -376 )
      goto LABEL_19;
LABEL_25:
    qdf_trace_msg(
      0xA1u,
      2u,
      "BS_SM request is null (via %s)",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "ll_lt_sap_switch_to_non_wlan_from_wlan");
    v10 = nullptr;
    goto LABEL_26;
  }
  if ( !*(_QWORD *)(result + 432) )
    goto LABEL_25;
  if ( *(_DWORD *)(result + 424) )
    goto LABEL_25;
  v10 = (unsigned __int8 *)(result + 416);
  if ( result == -416 )
    goto LABEL_25;
LABEL_19:
  if ( *v10 >= 6u )
  {
    v11 = "Invalid vdev id %d in BS_SM request";
LABEL_23:
    qdf_trace_msg(0xA1u, 2u, v11, a2, a3, a4, a5, a6, a7, a8, a9);
LABEL_26:
    qdf_trace_msg(
      0xA1u,
      2u,
      "%s: BS_SM vdev %d Invalid total ref count %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "ll_lt_sap_switch_to_non_wlan_from_wlan",
      *(unsigned __int8 *)(*(_QWORD *)v9 + 168LL),
      v9[61]);
    goto LABEL_27;
  }
  if ( *((_DWORD *)v10 + 3) >= 6u )
  {
    v11 = "Invalid source %d in BS_SM request";
    goto LABEL_23;
  }
LABEL_27:
  v20 = *(_QWORD *)(*(_QWORD *)v9 + 216LL);
  if ( v20 )
    v21 = *(_QWORD *)(v20 + 80);
  else
    v21 = 0;
  return bs_sm_deliver_event(v21, 1u, 0x28u, (__int64)v10);
}
