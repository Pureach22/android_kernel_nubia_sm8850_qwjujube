__int64 __fastcall hdd_adapter_link_switch_notification(
        __int64 a1,
        unsigned __int8 a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  __int64 result; // x0
  unsigned __int8 *v13; // x8
  __int64 v14; // x20
  unsigned __int8 v15; // w22
  char v16; // w23
  int v17; // w0
  __int64 v18; // x9
  __int64 v19; // x10
  unsigned int v20; // w20
  __int64 *v21[2]; // [xsp+0h] [xbp-10h] BYREF

  v21[1] = *(__int64 **)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(a1 + 680);
  v21[0] = nullptr;
  if ( v11 )
  {
    if ( (a3 & 1) != 0 && link_switch_vdev_sync )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Previous trans ops not stopped",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "hdd_adapter_link_switch_notification");
      osif_vdev_sync_trans_stop(link_switch_vdev_sync);
      link_switch_vdev_sync = 0;
      result = 4;
    }
    else
    {
      v13 = *(unsigned __int8 **)(v11 + 8);
      v14 = *(_QWORD *)v13;
      if ( v13[8] == *(unsigned __int8 *)(*(_QWORD *)(*(_QWORD *)v13 + 52832LL) + 8LL) )
      {
        if ( (a3 & 1) != 0
          && (v15 = a2,
              v16 = a3,
              v17 = _osif_vdev_sync_op_start(
                      *(_QWORD *)(v14 + 32),
                      v21,
                      (__int64)"hdd_adapter_link_switch_notification"),
              a2 = v15,
              a3 = v16,
              v17) )
        {
          result = 16;
        }
        else
        {
          if ( a2 == 255 )
          {
            result = 0;
          }
          else
          {
            result = 16;
            if ( v14 )
            {
              v18 = v14 + 52840;
              if ( v14 != -52840 )
              {
                v19 = 0;
                while ( 1 )
                {
                  if ( (unsigned __int64)(0x71B3F945A27B1F49LL * (v19 >> 3)) > 2 )
                  {
LABEL_19:
                    result = 16;
                    goto LABEL_21;
                  }
                  if ( *(unsigned __int8 *)(v18 + 8) == a2 )
                    break;
                  v18 += 6088;
                  v19 += 6088;
                  if ( !v18 )
                    goto LABEL_19;
                }
                result = 0;
                *(_QWORD *)(v14 + 52832) = v18;
              }
            }
          }
LABEL_21:
          if ( (a3 & 1) != 0 )
          {
            link_switch_vdev_sync = (__int64)v21[0];
          }
          else if ( link_switch_vdev_sync )
          {
            v20 = result;
            _osif_vdev_sync_op_stop(link_switch_vdev_sync, (__int64)"hdd_adapter_link_switch_notification");
            result = v20;
            link_switch_vdev_sync = 0;
          }
        }
      }
      else
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Deflink VDEV %d not equals current VDEV %d",
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          "hdd_adapter_link_switch_notification");
        result = 4;
      }
    }
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Invalid osif priv",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "hdd_adapter_link_switch_notification");
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
