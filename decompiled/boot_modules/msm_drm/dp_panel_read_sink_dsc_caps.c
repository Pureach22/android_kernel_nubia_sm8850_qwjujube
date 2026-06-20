unsigned __int8 *__fastcall dp_panel_read_sink_dsc_caps(unsigned __int8 *result)
{
  _BYTE *v2; // x19
  int v3; // w20
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x19
  char v6; // w8
  int v7; // w9
  unsigned int v8; // w10
  bool v9; // zf
  char v10; // w9
  char v11; // w11

  if ( *(_BYTE *)(*((_QWORD *)result + 151) + 726LL) != 1 || *result < 0x14u )
    return result;
  v2 = result;
  result = (unsigned __int8 *)drm_dp_dpcd_read(*(_QWORD *)(*((_QWORD *)result + 149) + 24LL), 96, result + 44, 16);
  v3 = (int)result;
  if ( (int)result <= 15 )
  {
    ipc_log_context = get_ipc_log_context(result);
    StatusReg = _ReadStatusReg(SP_EL0);
    result = (unsigned __int8 *)ipc_log_string(
                                  ipc_log_context,
                                  "[d][%-4d]dsc dpcd read failed, rlen=%d\n",
                                  *(_DWORD *)(StatusReg + 1800),
                                  v3);
    if ( (_drm_debug & 4) != 0 )
      return (unsigned __int8 *)_drm_dev_dbg(
                                  0,
                                  0,
                                  0,
                                  "[msm-dp-debug][%-4d]dsc dpcd read failed, rlen=%d\n",
                                  *(_DWORD *)(StatusReg + 1800),
                                  v3);
    return result;
  }
  v6 = v2[44];
  if ( !v6 )
  {
    v2[961] = 0;
LABEL_16:
    v2[967] = v6;
    return result;
  }
  v7 = (unsigned __int8)v2[50];
  v8 = (unsigned __int8)v2[45];
  v6 = 1;
  v2[961] = 1;
  v9 = v7 == 0;
  v10 = v2[54];
  v2[962] = v8;
  v11 = !v9;
  v2[963] = v11;
  v2[964] = v10;
  if ( v8 > 0x10 )
    goto LABEL_16;
  return result;
}
