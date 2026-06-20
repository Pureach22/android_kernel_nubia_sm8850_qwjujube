__int64 __fastcall wlan_vdev_set_dot11mode(
        __int64 a1,
        int a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v11; // w8
  char v12; // w9
  char v13; // w9
  __int64 v14; // x5
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  v11 = *(_DWORD *)(a1 + 5968);
  if ( a2 <= 10 )
  {
    if ( a2 == 2 || a2 == 7 )
    {
      v11 >>= 4;
    }
    else if ( a2 == 8 )
    {
      v12 = 12;
LABEL_14:
      v11 >>= v12;
      goto LABEL_15;
    }
    goto LABEL_15;
  }
  switch ( a2 )
  {
    case 11:
      v13 = 20;
      goto LABEL_12;
    case 15:
      v12 = 16;
      goto LABEL_14;
    case 16:
      v13 = 8;
LABEL_12:
      v14 = (v11 >> v13) & 0xF;
      goto LABEL_18;
  }
LABEL_15:
  v14 = v11 & 0xF;
  if ( (v11 & 0xB) == 0
    && !(*(_DWORD *)(*(_QWORD *)(a3 + 520) + 80LL) | *(unsigned __int16 *)(*(_QWORD *)(a3 + 520) + 84LL)) )
  {
    v14 = 3;
    *(_DWORD *)a3 = 3;
  }
LABEL_18:
  result = qdf_trace_msg(
             0x68u,
             8u,
             "%s: vdev%d: dot11_mode %d",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "wlan_vdev_set_dot11mode",
             *(unsigned __int8 *)(*(_QWORD *)(a3 + 520) + 168LL),
             v14);
  _ReadStatusReg(SP_EL0);
  return result;
}
