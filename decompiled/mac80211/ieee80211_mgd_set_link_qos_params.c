unsigned int *__fastcall ieee80211_mgd_set_link_qos_params(unsigned int *result)
{
  _BYTE *v1; // x21
  unsigned int *v2; // x19
  __int64 v3; // x20
  __int64 v4; // x3
  __int64 v5; // x3
  __int64 v6; // x3
  __int64 v7; // x3
  __int64 v8; // x8
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 v11; // x8

  v1 = *(_BYTE **)result;
  v2 = result;
  v3 = *(_QWORD *)(*(_QWORD *)result + 1616LL);
  if ( (*(_BYTE *)(*(_QWORD *)result + 2768LL) & 1) == 0 )
  {
    result = (unsigned int *)drv_conf_tx(*(_QWORD *)(*(_QWORD *)result + 1616LL), result, 0, (__int64)(result + 222));
    if ( (_DWORD)result )
    {
      v8 = *(_QWORD *)v2;
      if ( *(_WORD *)(*(_QWORD *)v2 + 5800LL) )
        result = (unsigned int *)printk(&unk_B8922, v8 + 1640, v2[2], 0);
      else
        result = (unsigned int *)printk(&unk_BC576, v8 + 1640, 0, v4);
    }
  }
  if ( (v1[2800] & 1) == 0 )
  {
    result = (unsigned int *)drv_conf_tx(v3, v2, 1, (__int64)v2 + 902);
    if ( (_DWORD)result )
    {
      v9 = *(_QWORD *)v2;
      if ( *(_WORD *)(*(_QWORD *)v2 + 5800LL) )
        result = (unsigned int *)printk(&unk_B8922, v9 + 1640, v2[2], 1);
      else
        result = (unsigned int *)printk(&unk_BC576, v9 + 1640, 1, v5);
    }
  }
  if ( (v1[2832] & 1) == 0 )
  {
    result = (unsigned int *)drv_conf_tx(v3, v2, 2, (__int64)(v2 + 229));
    if ( (_DWORD)result )
    {
      v10 = *(_QWORD *)v2;
      if ( *(_WORD *)(*(_QWORD *)v2 + 5800LL) )
        result = (unsigned int *)printk(&unk_B8922, v10 + 1640, v2[2], 2);
      else
        result = (unsigned int *)printk(&unk_BC576, v10 + 1640, 2, v6);
    }
  }
  if ( (v1[2864] & 1) == 0 )
  {
    result = (unsigned int *)drv_conf_tx(v3, v2, 3, (__int64)v2 + 930);
    if ( (_DWORD)result )
    {
      v11 = *(_QWORD *)v2;
      if ( *(_WORD *)(*(_QWORD *)v2 + 5800LL) )
        return (unsigned int *)printk(&unk_B8922, v11 + 1640, v2[2], 3);
      else
        return (unsigned int *)printk(&unk_BC576, v11 + 1640, 3, v7);
    }
  }
  return result;
}
