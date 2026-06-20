__int64 __fastcall cam_ife_csid_ver2_stop_csi2_in_err(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x20
  unsigned int v3; // w8
  __int64 v4; // x1

  v1 = result;
  v2 = **(_QWORD **)(result + 31136);
  if ( (debug_mdl & 8) == 0 || debug_priority )
  {
    if ( !*(_DWORD *)(result + 2100) )
      goto LABEL_5;
    goto LABEL_4;
  }
  result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             debug_mdl & 8,
             4,
             "cam_ife_csid_ver2_stop_csi2_in_err",
             1322,
             "CSID:%u Stop csi2 rx",
             *(_DWORD *)(*(_QWORD *)(result + 31120) + 4LL));
  if ( *(_DWORD *)(v1 + 2100) )
LABEL_4:
    result = ((__int64 (__fastcall *)(_QWORD))cam_irq_controller_disable_irq)(*(_QWORD *)(v1 + 30984));
LABEL_5:
  v3 = *(_DWORD *)(v2 + 660);
  if ( v3 < 2 )
    goto LABEL_8;
  if ( *(_DWORD *)(v1 + 2104) )
  {
    result = ((__int64 (__fastcall *)(_QWORD))cam_irq_controller_disable_irq)(*(_QWORD *)(v1 + 31000));
    v3 = *(_DWORD *)(v2 + 660);
LABEL_8:
    if ( !v3 )
      return result;
  }
  if ( *(_DWORD *)(v1 + 2116) )
  {
    result = ((__int64 (__fastcall *)(_QWORD))cam_irq_controller_disable_irq)(*(_QWORD *)(v1 + 31000));
    v3 = *(_DWORD *)(v2 + 660);
  }
  if ( v3 >= 2 )
  {
    v4 = *(unsigned int *)(v1 + 2120);
    if ( (_DWORD)v4 )
    {
      result = ((__int64 (__fastcall *)(_QWORD))cam_irq_controller_disable_irq)(*(_QWORD *)(v1 + 31008));
      v3 = *(_DWORD *)(v2 + 660);
    }
    if ( v3 > 2 )
      goto LABEL_25;
  }
  if ( v3 )
  {
    if ( *(_DWORD *)(v1 + 2108) )
    {
      result = ((__int64 (__fastcall *)(_QWORD))cam_irq_controller_disable_irq)(*(_QWORD *)(v1 + 31000));
      v3 = *(_DWORD *)(v2 + 660);
    }
    if ( v3 >= 2 )
    {
      v4 = *(unsigned int *)(v1 + 2112);
      if ( (_DWORD)v4 )
      {
        result = ((__int64 (__fastcall *)(_QWORD))cam_irq_controller_disable_irq)(*(_QWORD *)(v1 + 31008));
        v3 = *(_DWORD *)(v2 + 660);
      }
      if ( v3 > 2 )
      {
LABEL_25:
        __break(0x5512u);
        return cam_ife_csid_ver2_rx_err_process_bottom_half(result, v4);
      }
    }
  }
  return result;
}
