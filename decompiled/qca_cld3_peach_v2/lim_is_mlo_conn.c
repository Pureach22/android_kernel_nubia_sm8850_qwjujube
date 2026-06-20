bool __fastcall lim_is_mlo_conn(
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
  _BOOL8 result; // x0
  const char *v12; // x2

  _ReadStatusReg(SP_EL0);
  if ( !a2 )
  {
    v12 = "%s: sta ds is null";
LABEL_7:
    qdf_trace_msg(0x35u, 2u, v12, a3, a4, a5, a6, a7, a8, a9, a10, "lim_is_mlo_conn");
    goto LABEL_8;
  }
  if ( !a1 )
  {
    v12 = "%s: session is null";
    goto LABEL_7;
  }
  if ( (wlan_vdev_mlme_is_mlo_vdev(*(_QWORD *)(a1 + 16), a3, a4, a5, a6, a7, a8, a9, a10) & 1) == 0 )
  {
LABEL_8:
    result = 0;
    goto LABEL_9;
  }
  result = (*(_DWORD *)(a2 + 1080) | *(unsigned __int16 *)(a2 + 1084)) != 0;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
