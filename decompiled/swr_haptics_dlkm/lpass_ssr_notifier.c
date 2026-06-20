__int64 __fastcall lpass_ssr_notifier(__int64 a1, __int64 a2)
{
  unsigned int v4; // w20
  int v5; // w8
  __int64 v6; // x20
  int v7; // w8
  int v8; // w22
  int logical_dev_num; // w21
  _BYTE v11[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  mutex_lock(a1 + 24);
  if ( a2 == 1 )
  {
    v5 = *(unsigned __int8 *)(a1 + 85);
    v4 = 0;
    *(_BYTE *)(a1 + 92) = 0;
    if ( v5 == 1 )
    {
      v6 = *(_QWORD *)(a1 - 88);
      v11[0] = 0;
      usleep_range_state(500, 510, 2);
      v7 = -29;
      do
      {
        v8 = v7;
        logical_dev_num = swr_get_logical_dev_num(v6, *(_QWORD *)(v6 + 984), v11);
        if ( logical_dev_num < 0 )
          msleep(20);
        if ( !logical_dev_num )
          break;
        v7 = v8 + 1;
      }
      while ( v8 );
      if ( logical_dev_num )
      {
        dev_err(
          *(_QWORD *)(a1 - 96),
          "%s: failed to get devnum for swr-haptics, rc=%d\n",
          "swr_haptics_slave_enumeration",
          logical_dev_num);
        v4 = -517;
        dev_err(
          *(_QWORD *)(a1 - 96),
          "%s: SWR haptics slave enumeration failued after SSR, rc=%d\n",
          "lpass_ssr_notifier",
          4294966779LL);
      }
      else
      {
        *(_BYTE *)(v6 + 64) = v11[0];
        v4 = regmap_write(*(_QWORD *)(a1 - 72), 12417, 4);
        if ( v4 )
          dev_err(*(_QWORD *)(a1 - 96), "%s: Disable SWR_PLAY failed, rc=%d\n", "lpass_ssr_notifier", v4);
      }
    }
  }
  else if ( a2 == 2 )
  {
    v4 = 0;
    *(_BYTE *)(a1 + 92) = 1;
  }
  else
  {
    v4 = 0;
  }
  mutex_unlock(a1 + 24);
  _ReadStatusReg(SP_EL0);
  return v4;
}
