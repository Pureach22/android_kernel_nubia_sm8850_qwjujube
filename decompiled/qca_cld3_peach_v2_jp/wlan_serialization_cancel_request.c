__int64 __fastcall wlan_serialization_cancel_request(
        unsigned int *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  const char *v10; // x2
  __int64 result; // x0
  unsigned int v12; // w5
  int v13; // w7
  __int64 v14; // x8
  __int64 pdev_from_cmd; // x0
  __int64 pdev_obj; // x0
  _DWORD v17[2]; // [xsp+18h] [xbp-38h] BYREF
  __int64 v18; // [xsp+20h] [xbp-30h]
  __int64 v19; // [xsp+28h] [xbp-28h]
  __int64 v20; // [xsp+30h] [xbp-20h]
  __int64 v21; // [xsp+38h] [xbp-18h]
  __int64 v22; // [xsp+40h] [xbp-10h]
  __int64 v23; // [xsp+48h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  v18 = 0;
  if ( a1 )
  {
    if ( (unsigned int)wlan_serialization_validate_cmd(*a1, a1[1]) )
    {
      v10 = "%s: req is not valid";
    }
    else
    {
      v12 = a1[2];
      v13 = *a1;
      v14 = *((_QWORD *)a1 + 2);
      v17[0] = a1[1];
      v17[1] = v12;
      LODWORD(v19) = v13;
      v21 = v14;
      qdf_trace_msg(
        0x4Cu,
        8u,
        "%s: Type %d id %d vdev %d source %d req type %d queue type %d",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "wlan_serialization_cancel_request",
        a1[3],
        *((unsigned __int8 *)a1 + 24));
      pdev_from_cmd = wlan_serialization_get_pdev_from_cmd(v17);
      if ( pdev_from_cmd )
      {
        pdev_obj = wlan_serialization_get_pdev_obj(pdev_from_cmd);
        if ( wlan_serialization_get_pdev_queue_obj(pdev_obj, v17[0]) )
        {
          result = wlan_serialization_find_and_cancel_cmd(v17, a1[3], *((unsigned __int8 *)a1 + 24));
          goto LABEL_6;
        }
        v10 = "%s: pdev_queue is invalid";
      }
      else
      {
        v10 = "%s: pdev is invalid";
      }
    }
  }
  else
  {
    v10 = "%s: given request is empty";
  }
  qdf_trace_msg(0x4Cu, 2u, v10, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_serialization_cancel_request");
  result = 4;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
