__int64 __fastcall aw9620x_awrw_get(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x21
  __int64 v5; // x23
  __int64 v6; // x22
  int v7; // w0
  int v8; // w19

  v3 = *(_QWORD *)(a1 + 152);
  if ( *(_QWORD *)(v3 + 576) )
  {
    if ( *(unsigned __int8 *)(v3 + 571) * *(unsigned __int8 *)(v3 + 570) )
    {
      v5 = 0;
      v6 = 0;
      do
      {
        v7 = snprintf(
               (char *)(a3 + v6),
               4096 - v6,
               "0x%02x,",
               *(unsigned __int8 *)(*(_QWORD *)(v3 + 576) + *(unsigned __int8 *)(v3 + 569) + v5++));
        v6 += v7;
      }
      while ( (unsigned int)v5 < *(unsigned __int8 *)(v3 + 571) * (unsigned int)*(unsigned __int8 *)(v3 + 570) );
    }
    else
    {
      v6 = 0;
    }
    v8 = snprintf((char *)(a3 + v6 - 1), 4096 - v6, "\n");
    devm_kfree(*(_QWORD *)(v3 - 8), *(_QWORD *)(v3 + 576));
    *(_QWORD *)(v3 + 576) = 0;
    return v6 + v8 - 1;
  }
  else
  {
    dev_printk(&unk_134C0, *(_QWORD *)(v3 - 8), "[%s:%d] p_i2c_tranfar_data is NULL\n", "aw9620x_awrw_get", 2857);
    return 0;
  }
}
