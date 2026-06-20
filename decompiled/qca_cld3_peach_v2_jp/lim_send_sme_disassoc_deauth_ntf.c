__int64 __fastcall lim_send_sme_disassoc_deauth_ntf(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        unsigned __int16 *a11)
{
  unsigned __int16 *v11; // x21
  __int64 v12; // x4
  unsigned int v14; // w19
  int v16; // w3
  __int64 result; // x0
  const char *v18; // x2
  const char *v19; // x3
  __int64 v20; // [xsp+8h] [xbp-38h] BYREF
  unsigned __int16 *v21; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v22)(__int64); // [xsp+18h] [xbp-28h]
  __int64 v23; // [xsp+20h] [xbp-20h]
  __int64 v24; // [xsp+28h] [xbp-18h]
  __int64 v25; // [xsp+30h] [xbp-10h]
  __int64 v26; // [xsp+38h] [xbp-8h]

  v11 = a11;
  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *a11;
  if ( (unsigned int)(v12 - 5129) > 6 || ((1 << (v12 - 9)) & 0x51) == 0 )
  {
    v18 = "%s: Received invalid disconnect rsp type %d";
    v19 = "lim_send_sme_disassoc_deauth_ntf";
    goto LABEL_11;
  }
  v14 = *((unsigned __int8 *)a11 + 4);
  if ( (wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21560), *((_BYTE *)a11 + 4)) & 0xFFFFFFFD) != 0 )
  {
    v16 = *v11;
    v24 = 0;
    v25 = 0;
    v22 = nullptr;
    v23 = 0;
    v21 = v11;
    v20 = (unsigned __int16)v16;
    qdf_trace(53, 6u, 255, v16);
    result = sys_process_mmh_msg(a1, &v20);
    goto LABEL_12;
  }
  _qdf_mem_free((__int64)v11);
  v24 = 0;
  v25 = 0;
  v22 = nullptr;
  v23 = 0;
  v20 = 0;
  v21 = nullptr;
  result = _qdf_mem_malloc(0x10u, "lim_cm_send_disconnect_rsp", 840);
  if ( result )
  {
    *(_BYTE *)result = v14;
    v11 = (unsigned __int16 *)result;
    *(_QWORD *)(result + 8) = *(_QWORD *)(a1 + 21552);
    v21 = (unsigned __int16 *)result;
    v22 = cm_handle_disconnect_resp;
    result = scheduler_post_message_debug(
               0x35u,
               0x48u,
               72,
               (unsigned __int16 *)&v20,
               0x353u,
               (__int64)"lim_cm_send_disconnect_rsp");
    if ( (_DWORD)result )
    {
      v18 = "%s: Failed to post disconnect rsp to sme vdev_id %d";
      v19 = "lim_cm_send_disconnect_rsp";
      v12 = v14;
LABEL_11:
      qdf_trace_msg(0x35u, 2u, v18, a2, a3, a4, a5, a6, a7, a8, a9, v19, v12);
      result = _qdf_mem_free((__int64)v11);
    }
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
