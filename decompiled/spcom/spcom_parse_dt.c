__int64 __fastcall spcom_parse_dt(__int64 a1)
{
  unsigned int string_helper; // w19
  unsigned int v3; // w21
  __int64 v4; // x27
  const char *v6[2]; // [xsp+10h] [xbp-10h] BYREF

  v6[1] = *(const char **)(_ReadStatusReg(SP_EL0) + 1808);
  v6[0] = nullptr;
  string_helper = of_property_read_string_helper(a1, "qcom,spcom-ch-names", 0, 0, 0);
  if ( (string_helper & 0x80000000) != 0 )
  {
    printk(&unk_F40A, "spcom_parse_dt", string_helper);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: wrong format of predefined channels definition [%d]\n",
      "spcom_parse_dt",
      (const char *)&unk_F80E,
      string_helper);
  }
  else if ( string_helper >= 0x21 )
  {
    printk(&unk_11638, "spcom_parse_dt", string_helper);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: too many predefined channels [%d]\n",
      "spcom_parse_dt",
      (const char *)&unk_F80E,
      string_helper);
    string_helper = -22;
  }
  else
  {
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: num of predefined channels [%d]\n",
      "spcom_parse_dt",
      (const char *)&unk_F80E,
      string_helper);
    if ( string_helper )
    {
      v3 = 0;
      v4 = 0;
      while ( (of_property_read_string_helper(a1, "qcom,spcom-ch-names", v6, 1, v3) & 0x80000000) == 0 )
      {
        sized_strscpy(spcom_dev + v4, v6[0], 32);
        ipc_log_string(
          spcom_ipc_log_context,
          "%sspcom:%s: found ch [%s]\n",
          "spcom_parse_dt",
          (const char *)&unk_F80E,
          v6[0]);
        v4 += 32;
        ++v3;
        if ( 32LL * string_helper == v4 )
          goto LABEL_7;
      }
      printk(&unk_12148, "spcom_parse_dt", v3);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: failed to read DT ch#%d name\n",
        "spcom_parse_dt",
        (const char *)&unk_F80E,
        v3);
      string_helper = -14;
    }
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return string_helper;
}
