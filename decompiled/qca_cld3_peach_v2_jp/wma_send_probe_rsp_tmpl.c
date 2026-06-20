__int64 __fastcall wma_send_probe_rsp_tmpl(
        __int64 *a1,
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
  const char *v12; // x2
  __int64 result; // x0
  __int64 v14; // x10
  __int64 v15; // x8
  __int64 v16; // x0
  unsigned __int8 v17[4]; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-18h]
  __int64 v19; // [xsp+10h] [xbp-10h]
  __int64 v20; // [xsp+18h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17[0] = 0;
  if ( !a2 )
  {
    v12 = "%s: probe_rsp_info is NULL";
    goto LABEL_5;
  }
  if ( (unsigned int)wma_find_vdev_id_by_addr((__int64)a1, a2 + 16, v17) )
  {
    v12 = "%s: failed to get vdev id";
LABEL_5:
    result = qdf_trace_msg(0x36u, 2u, v12, a3, a4, a5, a6, a7, a8, a9, a10, "wma_send_probe_rsp_tmpl");
    goto LABEL_6;
  }
  result = wmi_service_enabled(*a1, 0, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( (result & 1) != 0 )
  {
    v14 = a1[65];
    v19 = 0;
    v15 = *(_QWORD *)(v14 + 488LL * v17[0] + 192);
    LODWORD(v19) = *(_DWORD *)(a2 + 520);
    BYTE4(v19) = *(_BYTE *)(a2 + 556);
    *(_QWORD *)(a2 + 30) = -v15;
    v16 = *a1;
    v18 = a2 + 6;
    result = wmi_unified_probe_rsp_tmpl_send_cmd(v16);
    if ( (result & 0x80000000) != 0 )
    {
      v12 = "%s: wmi_unified_probe_rsp_tmpl_send Failed";
      goto LABEL_5;
    }
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
