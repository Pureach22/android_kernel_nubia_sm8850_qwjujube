__int64 __fastcall wlan_mlo_send_vdev_pause(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 (*v10)(void); // x8
  __int64 result; // x0
  const char *v12; // x2

  _ReadStatusReg(SP_EL0);
  v9 = *(_QWORD *)(a1 + 2128);
  if ( v9 == -1984 )
  {
    v12 = "%s: tx_ops is null!";
    goto LABEL_9;
  }
  v10 = *(__int64 (**)(void))(v9 + 2040);
  if ( !v10 )
  {
    v12 = "%s: send_vdev_pause is null";
    goto LABEL_9;
  }
  if ( *((_DWORD *)v10 - 1) != -262397735 )
    __break(0x8228u);
  result = v10();
  if ( (_DWORD)result )
  {
    v12 = "%s: Failed to send vdev pause to FW";
LABEL_9:
    result = qdf_trace_msg(0x8Fu, 2u, v12, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_mlo_send_vdev_pause");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
