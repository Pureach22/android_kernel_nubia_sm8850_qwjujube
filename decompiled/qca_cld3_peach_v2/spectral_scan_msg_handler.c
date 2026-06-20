__int64 __fastcall spectral_scan_msg_handler(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  _QWORD *context; // x19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  const char *v31; // x2
  __int64 v32; // x20
  __int64 v33; // [xsp+8h] [xbp-48h] BYREF
  _QWORD v34[2]; // [xsp+10h] [xbp-40h] BYREF
  unsigned __int16 *v35; // [xsp+20h] [xbp-30h]
  __int64 v36; // [xsp+28h] [xbp-28h]
  __int64 v37; // [xsp+30h] [xbp-20h]
  __int64 v38; // [xsp+38h] [xbp-18h]
  __int64 v39; // [xsp+40h] [xbp-10h]
  __int64 v40; // [xsp+48h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33 = 0;
  result = _osif_psoc_sync_op_start(a3, &v33, (__int64)"spectral_scan_msg_handler");
  if ( !(_DWORD)result )
  {
    v38 = 0;
    v39 = 0;
    v36 = 0;
    v37 = 0;
    v34[1] = 0;
    v35 = nullptr;
    v34[0] = 0;
    context = _cds_get_context(51, (__int64)"__spectral_scan_msg_handler", v6, v7, v8, v9, v10, v11, v12, v13);
    if ( !(unsigned int)_wlan_hdd_validate_context(
                          (__int64)context,
                          (__int64)"__spectral_scan_msg_handler",
                          v15,
                          v16,
                          v17,
                          v18,
                          v19,
                          v20,
                          v21,
                          v22) )
    {
      if ( (unsigned int)_nla_parse(v34, 6, a1, a2, 0, 31, 0) )
      {
        v31 = "%s: nla parse fails";
      }
      else if ( v35 )
      {
        if ( (unsigned int)*v35 - 4 <= 7 )
        {
          v32 = jiffies;
          if ( _spectral_scan_msg_handler___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Invalid length for ATTR_DATA",
              v23,
              v24,
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              "__spectral_scan_msg_handler");
            _spectral_scan_msg_handler___last_ticks = v32;
          }
          goto LABEL_6;
        }
        if ( v35 != (unsigned __int16 *)-4LL )
        {
          if ( *((_DWORD *)v35 + 1) )
          {
            qdf_trace_msg(
              0x33u,
              3u,
              "%s: invalid message type %d",
              v23,
              v24,
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              "__spectral_scan_msg_handler");
          }
          else
          {
            *((_DWORD *)context + 873) = *((_DWORD *)v35 + 2);
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: spectral scan application registered, pid=%d",
              v23,
              v24,
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              "__spectral_scan_msg_handler");
            send_spectral_scan_reg_rsp_msg(context);
            ucfg_spectral_scan_set_ppid(context[1], *((unsigned int *)context + 873));
          }
          goto LABEL_6;
        }
        v31 = "%s: data NULL";
      }
      else
      {
        v31 = "%s: attr VENDOR_DATA fails";
      }
      qdf_trace_msg(0x33u, 2u, v31, v23, v24, v25, v26, v27, v28, v29, v30, "__spectral_scan_msg_handler");
    }
LABEL_6:
    result = _osif_psoc_sync_op_stop(v33, (__int64)"spectral_scan_msg_handler");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
