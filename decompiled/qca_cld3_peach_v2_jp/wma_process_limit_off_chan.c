__int64 __fastcall wma_process_limit_off_chan(
        __int64 *a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w4
  unsigned int v11; // w8
  char is_vdev_up; // w0
  int v15; // w4
  __int64 v16; // x0
  int v17; // w9
  int v18; // w10
  unsigned __int8 v19; // w8
  __int64 result; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  const char *v29; // x2
  unsigned int v30; // w1
  int v31; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v32; // [xsp+8h] [xbp-18h]
  __int64 v33; // [xsp+10h] [xbp-10h]
  __int64 v34; // [xsp+18h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *a2;
  v11 = *((unsigned __int16 *)a1 + 81);
  v32 = 0;
  v33 = 0;
  if ( v11 <= v10 )
  {
    v29 = "%s: Invalid vdev_id: %d";
    v30 = 2;
LABEL_7:
    result = qdf_trace_msg(0x36u, v30, v29, a3, a4, a5, a6, a7, a8, a9, a10, "wma_process_limit_off_chan");
    goto LABEL_8;
  }
  is_vdev_up = wma_is_vdev_up(v10);
  v15 = *a2;
  if ( (is_vdev_up & 1) == 0 )
  {
    v29 = "%s: vdev %d is not up skipping limit_off_chan_param";
    v30 = 8;
    goto LABEL_7;
  }
  v16 = *a1;
  v17 = *((_DWORD *)a2 + 1);
  v18 = *((_DWORD *)a2 + 2);
  LOBYTE(v32) = a2[1];
  v19 = a2[12];
  v31 = v15;
  HIDWORD(v32) = v17;
  LODWORD(v33) = v18;
  BYTE4(v33) = v19;
  result = wmi_unified_send_limit_off_chan_cmd(v16, &v31);
  if ( (_DWORD)result )
    result = qdf_trace_msg(
               0x36u,
               2u,
               "%s: failed to set limit off chan cmd",
               v21,
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               v28,
               "wma_process_limit_off_chan");
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
