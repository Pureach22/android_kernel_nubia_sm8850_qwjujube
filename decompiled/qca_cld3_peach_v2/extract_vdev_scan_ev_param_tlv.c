__int64 __fastcall extract_vdev_scan_ev_param_tlv(__int64 a1, _QWORD *a2, _DWORD *a3)
{
  _DWORD *v4; // x21
  int v6; // w9
  int v7; // w8
  int v8; // w8
  int v9; // w8

  v4 = (_DWORD *)*a2;
  qdf_mem_set(a3, 0x30u, 0);
  v6 = v4[1];
  if ( v6 <= 15 )
  {
    if ( v6 > 3 )
    {
      if ( v6 == 4 )
      {
        v7 = 2;
        goto LABEL_22;
      }
      if ( v6 == 8 )
      {
        v7 = 3;
        goto LABEL_22;
      }
    }
    else
    {
      v7 = 0;
      if ( v6 == 1 )
        goto LABEL_22;
      if ( v6 == 2 )
      {
        v7 = 1;
        goto LABEL_22;
      }
    }
  }
  else if ( v6 <= 63 )
  {
    if ( v6 == 16 )
    {
      v7 = 4;
      goto LABEL_22;
    }
    if ( v6 == 32 )
    {
      v7 = 5;
      goto LABEL_22;
    }
  }
  else
  {
    switch ( v6 )
    {
      case 64:
        v7 = 6;
        goto LABEL_22;
      case 128:
        v7 = 7;
        goto LABEL_22;
      case 256:
        v7 = 8;
        goto LABEL_22;
    }
  }
  v7 = 19;
LABEL_22:
  a3[1] = v7;
  v8 = v4[2];
  if ( v8 <= 3 )
  {
    if ( v8 > 1 )
    {
      if ( v8 == 2 )
        v9 = 3;
      else
        v9 = 4;
    }
    else
    {
      if ( v8 )
      {
        if ( v8 == 1 )
        {
          v9 = 2;
          goto LABEL_40;
        }
        goto LABEL_35;
      }
      v9 = 1;
    }
  }
  else if ( v8 <= 5 )
  {
    if ( v8 == 4 )
      v9 = 5;
    else
      v9 = 6;
  }
  else
  {
    if ( v8 != 6 )
    {
      if ( v8 == 255 )
      {
        v9 = 0;
        goto LABEL_40;
      }
LABEL_35:
      v9 = 11;
      goto LABEL_40;
    }
    v9 = 10;
  }
LABEL_40:
  a3[2] = v9;
  a3[3] = v4[3];
  a3[4] = v4[4];
  a3[5] = v4[5];
  *a3 = v4[6];
  a3[6] = v4[7];
  if ( (wlan_p2p_is_sta_vdev_usage_allowed_for_p2p_dev(**(_QWORD **)(a1 + 760)) & 1) != 0 )
    a3[10] = v4[8];
  return 0;
}
