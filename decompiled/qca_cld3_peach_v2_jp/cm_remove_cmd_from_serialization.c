__int64 __fastcall cm_remove_cmd_from_serialization(__int64 *a1, unsigned int a2)
{
  unsigned int v4; // w21
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  int v13; // w6
  int v14; // w8
  int v15; // w9
  __int64 v16; // x4
  __int64 v17; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 result; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // [xsp+8h] [xbp-28h] BYREF
  __int64 v44; // [xsp+10h] [xbp-20h]
  __int64 v45; // [xsp+18h] [xbp-18h]
  __int64 v46; // [xsp+20h] [xbp-10h]
  __int64 v47; // [xsp+28h] [xbp-8h]

  v4 = a2 & 0xF000000;
  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  qdf_mem_set(&v43, 0x20u, 0);
  v44 = a2 | 0x800000000LL;
  switch ( v4 )
  {
    case 0xF000000u:
      v14 = *((unsigned __int8 *)a1 + 92);
      *((_BYTE *)a1 + 92) = 0;
      if ( v14 )
        v13 = 4;
      else
        v13 = 28;
      break;
    case 0xD000000u:
      v13 = 24;
      break;
    case 0xC000000u:
      v13 = 23;
      break;
    default:
      result = qdf_trace_msg(
                 0x68u,
                 2u,
                 "%s: vdev %d cm_id 0x%x: Invalid prefix %x",
                 v5,
                 v6,
                 v7,
                 v8,
                 v9,
                 v10,
                 v11,
                 v12,
                 "cm_remove_cmd_from_serialization",
                 *(unsigned __int8 *)(*a1 + 104),
                 a2,
                 v4);
      goto LABEL_13;
  }
  HIDWORD(v43) = v13;
  v15 = *((_DWORD *)a1 + 22);
  v16 = *(unsigned __int8 *)(*a1 + 104);
  v45 = *a1;
  if ( v15 == a2 )
  {
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: vdev %d cm_id 0x%x: Remove cmd type %d from active",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "cm_remove_cmd_from_serialization",
      v16,
      a2);
    v17 = *a1;
    LOBYTE(v46) = 1;
    cm_reset_active_cm_id(v17, a2, v18, v19, v20, v21, v22, v23, v24, v25);
    result = wlan_serialization_remove_cmd((unsigned int *)&v43, v26, v27, v28, v29, v30, v31, v32, v33);
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: vdev %d cm_id 0x%x: Remove cmd type %d from pending",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "cm_remove_cmd_from_serialization",
      v16,
      a2);
    LOBYTE(v46) = 2;
    result = wlan_serialization_cancel_request((unsigned int *)&v43, v35, v36, v37, v38, v39, v40, v41, v42);
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
